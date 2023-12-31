/* linux/drivers/iommu/exynos_iommu-reg.h
 *
 * Copyright (c) 2017 Samsung Electronics Co., Ltd.
 *		http://www.samsung.com
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */
#include "exynos-iommu.h"
#include <dt-bindings/sysmmu/sysmmu.h>
#include <linux/sec_debug.h>

#define is_secure_info_fail(x)	((((x) >> 16) & 0xffff) == 0xdead)
#ifdef CONFIG_EXYNOS_CONTENT_PATH_PROTECTION
static inline u32 __secure_info_read(unsigned int addr)
{
	u32 ret;

	ret = exynos_smc(SMC_DRM_SEC_SMMU_INFO, (unsigned long)addr,
			0, SEC_SMMU_SFR_READ);
	if (is_secure_info_fail(ret))
		pr_err("Invalid value returned, %#x\n", ret);

	return ret;
}
#else
static inline u32 __secure_info_read(unsigned int addr)
{
	return 0;
}
#endif

static inline void __sysmmu_tlb_invalidate_all(struct sysmmu_drvdata *drvdata)
{
	writel(0x1, MMU_REG(drvdata, IDX_ALL_INV));
}

static inline void __sysmmu_tlb_invalidate(struct sysmmu_drvdata *drvdata,
				dma_addr_t iova, size_t size)
{
	writel_relaxed(iova, MMU_REG(drvdata, IDX_RANGE_INV_START));
	writel_relaxed(size - 1 + iova, MMU_REG(drvdata, IDX_RANGE_INV_END));
	writel(0x1, MMU_REG(drvdata, IDX_RANGE_INV));
	SYSMMU_EVENT_LOG_TLB_INV_RANGE(SYSMMU_DRVDATA_TO_LOG(drvdata),
					iova, iova + size);
}

static inline void __sysmmu_set_ptbase(struct sysmmu_drvdata *drvdata,
					phys_addr_t pfn_pgtable)
{
	writel_relaxed(pfn_pgtable, MMU_REG(drvdata, IDX_FLPT_BASE));
	__sysmmu_tlb_invalidate_all(drvdata);

	SYSMMU_EVENT_LOG_TLB_INV_ALL(
			SYSMMU_DRVDATA_TO_LOG(drvdata));
}

static inline unsigned int dump_tlb_entry_way_type(void __iomem *sfrbase,
						int idx_way, int idx_set)
{
	if (MMU_TLB_ENTRY_VALID(readl_relaxed(sfrbase + REG_TLB_ATTR))) {
		pr_crit("[%02d][%02d] VPN: %#010x, PPN: %#010x, ATTR: %#010x\n",
			idx_way, idx_set,
			readl_relaxed(sfrbase + REG_TLB_VPN),
			readl_relaxed(sfrbase + REG_TLB_PPN),
			readl_relaxed(sfrbase + REG_TLB_ATTR));
		return 1;
	}
	return 0;
}

static inline void sysmmu_tlb_compare(phys_addr_t pgtable,
				int idx_sub, u32 vpn, u32 ppn)
{
	sysmmu_pte_t *entry;
	unsigned long vaddr = MMU_VADDR_FROM_TLB((unsigned long)vpn, idx_sub);
	unsigned long paddr = MMU_PADDR_FROM_TLB((unsigned long)ppn);
	unsigned long phys = 0;

	if (!pgtable)
		return;

	entry = section_entry(phys_to_virt(pgtable), vaddr);

	if (lv1ent_section(entry)) {
		phys = section_phys(entry);
	} else if (lv1ent_page(entry)) {
		entry = page_entry(entry, vaddr);

		if (lv2ent_large(entry))
			phys = lpage_phys(entry);
		else if (lv2ent_small(entry))
			phys = spage_phys(entry);
	} else {
		pr_crit(">> Invalid address detected! entry: %#lx",
						(unsigned long)*entry);
		return;
	}

	if (paddr != phys) {
		pr_crit(">> TLB mismatch detected!\n");
		pr_crit("   TLB: %#010lx, PT entry: %#010lx\n", paddr, phys);
	}
}

static inline unsigned int dump_tlb_entry_port_type(
			struct sysmmu_drvdata *drvdata,	phys_addr_t pgtable,
			int idx_way, int idx_set, int idx_sub)
{
	if (MMU_TLB_ENTRY_VALID(
			readl_relaxed(MMU_REG(drvdata, IDX_TLB_ATTR)))) {
		u32 vpn, ppn, attr;

		vpn = readl_relaxed(MMU_REG(drvdata, IDX_TLB_VPN));
		ppn = readl_relaxed(MMU_REG(drvdata, IDX_TLB_PPN));
		attr = readl_relaxed(MMU_REG(drvdata, IDX_TLB_ATTR));

		pr_crit("[%02d][%02d] VPN: %#010x, PPN: %#010x, ATTR: %#010x\n",
			idx_way, idx_set, vpn, ppn, attr);
		sysmmu_tlb_compare(pgtable, idx_sub, vpn, ppn);
		return 1;
	}
	return 0;
}

#define MMU_NUM_TLB_SUBLINE		4
static inline void dump_sysmmu_tlb_way(struct sysmmu_drvdata *drvdata)
{
	int i, j, k;
	u32 capa;
	unsigned int cnt;
	void __iomem *sfrbase = drvdata->sfrbase;

	capa = readl_relaxed(sfrbase + REG_MMU_CAPA0_V7);

	pr_auto(ASL4, "TLB has %d way, %d set. SBB has %d entries.\n",
			MMU_CAPA_NUM_TLB_WAY(capa),
			(1 << MMU_CAPA_NUM_TLB_SET(capa)),
			(1 << MMU_CAPA_NUM_SBB_ENTRY(capa)));
	pr_auto(ASL4, "------------- TLB[WAY][SET][ENTRY] -------------\n");
	for (i = 0, cnt = 0; i < MMU_CAPA_NUM_TLB_WAY(capa); i++) {
		for (j = 0; j < (1 << MMU_CAPA_NUM_TLB_SET(capa)); j++) {
			for (k = 0; k < MMU_NUM_TLB_SUBLINE; k++) {
				writel_relaxed(MMU_SET_TLB_READ_ENTRY(j, i, k),
					sfrbase + REG_TLB_READ);
				cnt += dump_tlb_entry_way_type(sfrbase, i, j);
			}
		}
	}
	if (!cnt)
		pr_auto(ASL4, ">> No Valid TLB Entries\n");

	pr_auto(ASL4, "--- SBB(Second-Level Page Table Base Address Buffer ---\n");
	for (i = 0, cnt = 0; i < (1 << MMU_CAPA_NUM_SBB_ENTRY(capa)); i++) {
		writel_relaxed(i, sfrbase + REG_SBB_READ);
		if (MMU_SBB_ENTRY_VALID(readl_relaxed(sfrbase + REG_SBB_VPN))) {
			pr_auto(ASL4, "[%02d] VPN: %#010x, PPN: %#010x, ATTR: %#010x\n",
				i, readl_relaxed(sfrbase + REG_SBB_VPN),
				readl_relaxed(sfrbase + REG_SBB_LINK),
				readl_relaxed(sfrbase + REG_SBB_ATTR));
			cnt++;
		}
	}
	if (!cnt)
		pr_auto(ASL4, ">> No Valid SBB Entries\n");
}

static inline void sysmmu_sbb_compare(u32 sbb_vpn, u32 sbb_link,
						phys_addr_t pgtable)
{
	sysmmu_pte_t *entry;
	unsigned long vaddr = MMU_VADDR_FROM_SBB((unsigned long)sbb_vpn);
	unsigned long paddr = MMU_PADDR_FROM_SBB((unsigned long)sbb_link);
	unsigned long phys = 0;

	if (!pgtable)
		return;

	entry = section_entry(phys_to_virt(pgtable), vaddr);

	if (lv1ent_page(entry)) {
		phys = lv2table_base(entry);

		if (paddr != phys) {
			pr_crit(">> SBB mismatch detected!\n");
			pr_crit("   entry addr: %lx / SBB addr %lx\n",
							paddr, phys);
		}
	} else {
		pr_crit(">> Invalid address detected! entry: %#lx",
						(unsigned long)*entry);
	}
}

static unsigned int dump_tlb_entry_port(struct sysmmu_drvdata *drvdata,
					phys_addr_t pgtable,
					int tlb, int way, int num_set)
{
	int cnt = 0;
	int set, sline;

	for (set = 0; set < num_set; set++) {
		for (sline = 0; sline < MMU_NUM_TLB_SUBLINE; sline++) {
			writel_relaxed(MMU_CAPA1_SET_TLB_READ_ENTRY(tlb, set,
								    way, sline),
				       MMU_REG(drvdata, IDX_TLB_READ));
			cnt += dump_tlb_entry_port_type(drvdata, pgtable,
							way, set, sline);
		}
	}

	return cnt;
}

static inline void dump_sysmmu_tlb_port(struct sysmmu_drvdata *drvdata,
							phys_addr_t pgtable)
{
	int t, i;
	u32 capa0, capa1, info;
	u32 sbb_vpn, sbb_link;
	unsigned int cnt;
	int num_tlb, num_port, num_sbb;
	void __iomem *sfrbase = drvdata->sfrbase;

	capa0 = readl_relaxed(sfrbase + REG_MMU_CAPA0_V7);
	capa1 = readl_relaxed(sfrbase + REG_MMU_CAPA1_V7);

	num_tlb = MMU_CAPA1_NUM_TLB(capa1);
	num_port = MMU_CAPA1_NUM_PORT(capa1);
	num_sbb = 1 << MMU_CAPA_NUM_SBB_ENTRY(capa0);

	pr_crit("SysMMU has %d TLBs, %d ports, %d sbb entries\n",
					num_tlb, num_port, num_sbb);

	for (t = 0; t < num_tlb; t++) {
		int num_set, num_way;

		info = readl_relaxed(sfrbase + MMU_TLB_INFO(t));
		num_way = MMU_CAPA1_NUM_TLB_WAY(info);
		num_set = MMU_CAPA1_NUM_TLB_SET(info);

		pr_crit("TLB.%d has %d way, %d set.\n", t, num_way, num_set);
		pr_crit("------------- TLB[WAY][SET][ENTRY] -------------\n");
		for (i = 0, cnt = 0; i < num_way; i++)
			cnt += dump_tlb_entry_port(drvdata, pgtable,
						   t, i, num_set);
	}
	if (!cnt)
		pr_auto(ASL4, ">> No Valid TLB Entries\n");

	pr_crit("--- SBB(Second-Level Page Table Base Address Buffer) ---\n");
	for (i = 0, cnt = 0; i < num_sbb; i++) {
		writel_relaxed(i, MMU_REG(drvdata, IDX_SBB_READ));
		if (MMU_SBB_ENTRY_VALID(readl_relaxed(
					MMU_REG(drvdata, IDX_SBB_VPN)))) {
			sbb_vpn = readl_relaxed(MMU_REG(drvdata, IDX_SBB_VPN));
			sbb_link = readl_relaxed(
					MMU_REG(drvdata, IDX_SBB_LINK));

			pr_crit("[%02d] VPN: %#010x, PPN: %#010x, ATTR: %#010x",
				i, sbb_vpn, sbb_link,
				readl_relaxed(MMU_REG(drvdata, IDX_SBB_ATTR)));
			sysmmu_sbb_compare(sbb_vpn, sbb_link, pgtable);
			cnt++;
		}
	}
	if (!cnt)
		pr_auto(ASL4, ">> No Valid SBB Entries\n");
}

static char *sysmmu_fault_name[SYSMMU_FAULTS_NUM] = {
	"PTW ACCESS FAULT",
	"PAGE FAULT",
	"L1TLB MULTI-HIT FAULT",
	"ACCESS FAULT",
	"SECURITY FAULT",
	"UNKNOWN FAULT"
};

static inline void dump_sysmmu_status(struct sysmmu_drvdata *drvdata,
							phys_addr_t pgtable)
{
	int info;
	pgd_t *pgd;
	pud_t *pud;
	pmd_t *pmd;
	pte_t *pte;
	phys_addr_t phys;
	void __iomem *sfrbase = drvdata->sfrbase;

	pgd = pgd_offset_k((unsigned long)sfrbase);
	if (!pgd) {
		pr_crit("Invalid virtual address %p\n", sfrbase);
		return;
	}

	pud = pud_offset(pgd, (unsigned long)sfrbase);
	if (!pud) {
		pr_crit("Invalid virtual address %p\n", sfrbase);
		return;
	}

	pmd = pmd_offset(pud, (unsigned long)sfrbase);
	if (!pmd) {
		pr_crit("Invalid virtual address %p\n", sfrbase);
		return;
	}

	pte = pte_offset_kernel(pmd, (unsigned long)sfrbase);
	if (!pte) {
		pr_crit("Invalid virtual address %p\n", sfrbase);
		return;
	}

	info = MMU_RAW_VER(readl_relaxed(sfrbase + REG_MMU_VERSION));

	phys = pte_pfn(*pte) << PAGE_SHIFT;
	pr_crit("ADDR: %pa(VA: %p), MMU_CTRL: %#010x, PT_BASE: %#010x\n",
		&phys, sfrbase,
		readl_relaxed(sfrbase + REG_MMU_CTRL),
		readl_relaxed(MMU_REG(drvdata, IDX_FLPT_BASE)));
	pr_crit("VERSION %d.%d.%d, MMU_CFG: %#010x, MMU_STATUS: %#010x\n",
		MMU_MAJ_VER(info), MMU_MIN_VER(info), MMU_REV_VER(info),
		readl_relaxed(sfrbase + REG_MMU_CFG),
		readl_relaxed(sfrbase + REG_MMU_STATUS));

	if (drvdata->has_vcr)
		pr_crit("MMU_CTRL_VM: %#010x, MMU_CFG_VM: %#010x\n",
				readl_relaxed(sfrbase + REG_MMU_CTRL_VM),
				readl_relaxed(sfrbase + REG_MMU_CFG_VM));

	if (IS_TLB_WAY_TYPE(drvdata))
		dump_sysmmu_tlb_way(drvdata);
	else if(IS_TLB_PORT_TYPE(drvdata))
		dump_sysmmu_tlb_port(drvdata, pgtable);
}

static inline void show_secure_fault_information(struct sysmmu_drvdata *drvdata,
				   int flags, unsigned long fault_addr)
{
	unsigned int info;
	phys_addr_t pgtable;
	int fault_id = SYSMMU_FAULT_ID(flags);
	unsigned int sfrbase = drvdata->securebase;
	const char *port_name = NULL;
#ifdef CONFIG_SEC_DEBUG_EXTRA_INFO
	char temp_buf[SZ_128];
#endif

	pgtable = __secure_info_read(MMU_SEC_REG(drvdata, IDX_SEC_FLPT_BASE));
	pgtable <<= PAGE_SHIFT;

	info = __secure_info_read(MMU_SEC_REG(drvdata, IDX_FAULT_TRANS_INFO));

	of_property_read_string(drvdata->sysmmu->of_node,
					"port-name", &port_name);

	pr_auto_once(4);
	pr_auto(ASL4, "----------------------------------------------------------\n");
	pr_auto(ASL4, "From [%s], SysMMU %s %s at %#010lx (page table @ %pa)\n",
		port_name ? port_name : dev_name(drvdata->sysmmu),
		(flags & IOMMU_FAULT_WRITE) ? "WRITE" : "READ",
		sysmmu_fault_name[fault_id], fault_addr, &pgtable);

#ifdef CONFIG_SEC_DEBUG_EXTRA_INFO
	snprintf(temp_buf, SZ_128, "%s %s %s at %#010lx (%pa)",
		port_name ? port_name : dev_name(drvdata->sysmmu),
		(flags & IOMMU_FAULT_WRITE) ? "WRITE" : "READ",
		sysmmu_fault_name[fault_id], fault_addr, &pgtable);
	secdbg_exin_set_sysmmu(temp_buf);
#endif

	if (fault_id == SYSMMU_FAULT_UNKNOWN) {
		pr_auto(ASL4, "The fault is not caused by this System MMU.\n");
		pr_auto(ASL4, "Please check IRQ and SFR base address.\n");
		goto finish;
	}

	pr_auto(ASL4, "AxID: %#x, AxLEN: %#x\n", info & 0xFFFF, (info >> 16) & 0xF);

	if (fault_id == SYSMMU_FAULT_PTW_ACCESS)
		pr_auto(ASL4, "System MMU has failed to access page table\n");

	if (!pfn_valid(pgtable >> PAGE_SHIFT)) {
		pr_auto(ASL4, "Page table base is not in a valid memory region\n");
	} else {
		sysmmu_pte_t *ent;
		ent = section_entry(phys_to_virt(pgtable), fault_addr);
		pr_auto(ASL4, "Lv1 entry: %#010x\n", *ent);

		if (lv1ent_page(ent)) {
			ent = page_entry(ent, fault_addr);
			pr_auto(ASL4, "Lv2 entry: %#010x\n", *ent);
		}
	}

	info = MMU_RAW_VER(__secure_info_read(sfrbase + REG_MMU_VERSION));

	pr_auto(ASL4, "ADDR: %#x, MMU_CTRL: %#010x, PT_BASE: %#010x\n",
		sfrbase,
		__secure_info_read(sfrbase + REG_MMU_CTRL),
		__secure_info_read(MMU_SEC_REG(drvdata, IDX_SEC_FLPT_BASE)));
	pr_auto(ASL4, "VERSION %d.%d.%d, MMU_CFG: %#010x, MMU_STATUS: %#010x\n",
		MMU_MAJ_VER(info), MMU_MIN_VER(info), MMU_REV_VER(info),
		__secure_info_read(sfrbase + REG_MMU_CFG),
		__secure_info_read(sfrbase + REG_MMU_STATUS));

finish:
	pr_auto(ASL4, "----------------------------------------------------------\n");
	pr_auto_disable(4);
}

static inline int show_fault_information(struct sysmmu_drvdata *drvdata,
				int flags, unsigned long fault_addr, char *panic_str)
{
	unsigned int info;
	phys_addr_t pgtable;
	int fault_id = SYSMMU_FAULT_ID(flags);
	const char *port_name = NULL;
	static int ptw_count = 0;
#ifdef CONFIG_SEC_DEBUG_EXTRA_INFO
	char temp_buf[SZ_128];
#endif

	pgtable = readl_relaxed(MMU_REG(drvdata, IDX_FLPT_BASE));
	pgtable <<= PAGE_SHIFT;

	info = readl_relaxed(MMU_REG(drvdata, IDX_FAULT_TRANS_INFO));

	of_property_read_string(drvdata->sysmmu->of_node,
					"port-name", &port_name);

	snprintf(panic_str, MAX_PANIC_LEN, "From [%s], SysMMU %s %s at %#010lx",
		 port_name ? port_name : dev_name(drvdata->sysmmu),
		 (flags & IOMMU_FAULT_WRITE) ? "WRITE" : "READ",
		 sysmmu_fault_name[fault_id], fault_addr);

	pr_auto_once(4);
	pr_auto(ASL4, "----------------------------------------------------------\n");
	pr_auto(ASL4, "%s (page table @ %pa)\n", panic_str, &pgtable);

#ifdef CONFIG_SEC_DEBUG_EXTRA_INFO
	snprintf(temp_buf, SZ_128, "%s %s %s at %#010lx (%pa)",
		port_name ? port_name : dev_name(drvdata->sysmmu),
		(flags & IOMMU_FAULT_WRITE) ? "WRITE" : "READ",
		sysmmu_fault_name[fault_id], fault_addr, &pgtable);
	secdbg_exin_set_sysmmu(temp_buf);
#endif

	if (fault_id == SYSMMU_FAULT_UNKNOWN) {
		pr_auto(ASL4, "The fault is not caused by this System MMU.\n");
		pr_auto(ASL4, "Please check IRQ and SFR base address.\n");
		goto finish;
	}

	pr_auto(ASL4, "AxID: %#x, AxLEN: %#x\n", info & 0xFFFF, (info >> 16) & 0xF);

	if (pgtable != drvdata->pgtable)
		pr_auto(ASL4, "Page table base of driver: %pa\n",
			&drvdata->pgtable);

	if (!pfn_valid(pgtable >> PAGE_SHIFT)) {
		pr_auto(ASL4, "Page table base is not in a valid memory region\n");
		pgtable = 0;
	} else {
		sysmmu_pte_t *ent;
		ent = section_entry(phys_to_virt(pgtable), fault_addr);
		pr_auto(ASL4, "Lv1 entry: %#010x\n", *ent);

		if (lv1ent_page(ent)) {
			ent = page_entry(ent, fault_addr);
			pr_auto(ASL4, "Lv2 entry: %#010x\n", *ent);
		}
	}

	if (fault_id == SYSMMU_FAULT_PTW_ACCESS) {
		ptw_count++;
		pr_auto(ASL4, "System MMU has failed to access page table, %d\n", ptw_count);
		pgtable = 0;

		if (ptw_count > 3)
			panic("Unrecoverable System MMU PTW fault");

		writel(0x1, drvdata->sfrbase + REG_INT_CLEAR);

		return -EAGAIN;
	}

	dump_sysmmu_status(drvdata, pgtable);

finish:
	pr_auto(ASL4, "----------------------------------------------------------\n");
	pr_auto_disable(4);

	return 0;
}

static inline void __sysmmu_disable_nocount(struct sysmmu_drvdata *drvdata)
{
	if (drvdata->no_block_mode) {
		if (drvdata->set_disable) {
			writel_relaxed(0, drvdata->sfrbase + REG_MMU_CFG);
			writel_relaxed(CTRL_DISABLE,
				       drvdata->sfrbase + REG_MMU_CTRL);
		}
		writel_relaxed(0, MMU_REG(drvdata, IDX_FLPT_BASE));
		__sysmmu_tlb_invalidate_all(drvdata);
	} else {
		if (drvdata->has_vcr) {
			writel_relaxed(0, drvdata->sfrbase + REG_MMU_CFG_VM);
			writel_relaxed(CTRL_BLOCK_DISABLE,
				       drvdata->sfrbase + REG_MMU_CTRL_VM);
		}

		writel_relaxed(0, drvdata->sfrbase + REG_MMU_CFG);
		writel_relaxed(CTRL_BLOCK_DISABLE,
			       drvdata->sfrbase + REG_MMU_CTRL);
	}

	SYSMMU_EVENT_LOG_DISABLE(SYSMMU_DRVDATA_TO_LOG(drvdata));
}

static inline void __sysmmu_set_public_way(struct sysmmu_drvdata *drvdata,
						unsigned int public_cfg)
{
	u32 cfg = readl_relaxed(drvdata->sfrbase + REG_PUBLIC_WAY_CFG);
	cfg &= ~MMU_PUBLIC_WAY_MASK;
	cfg |= public_cfg;

	writel_relaxed(cfg, drvdata->sfrbase + REG_PUBLIC_WAY_CFG);

	dev_dbg(drvdata->sysmmu, "public_cfg : %#x\n", cfg);
}

static inline void __sysmmu_set_private_way_id(struct sysmmu_drvdata *drvdata,
						unsigned int way_idx)
{
	struct tlb_priv_id *priv_cfg = drvdata->tlb_props.way_props.priv_id_cfg;
	u32 cfg = readl_relaxed(
			drvdata->sfrbase + REG_PRIVATE_WAY_CFG(way_idx));

	cfg &= ~MMU_PRIVATE_WAY_MASK;
	cfg |= MMU_WAY_CFG_ID_MATCHING | MMU_WAY_CFG_PRIVATE_ENABLE |
						priv_cfg[way_idx].cfg;

	writel_relaxed(cfg, drvdata->sfrbase + REG_PRIVATE_WAY_CFG(way_idx));
	writel_relaxed(priv_cfg[way_idx].id,
			drvdata->sfrbase + REG_PRIVATE_ID(way_idx));

	dev_dbg(drvdata->sysmmu, "priv ID way[%d] cfg : %#x, id : %#x\n",
					way_idx, cfg, priv_cfg[way_idx].id);
}

static inline void __sysmmu_set_private_way_addr(struct sysmmu_drvdata *drvdata,
						unsigned int priv_addr_idx)
{
	struct tlb_priv_addr *priv_cfg =
		drvdata->tlb_props.way_props.priv_addr_cfg;
	unsigned int way_idx =
		drvdata->tlb_props.way_props.priv_id_cnt + priv_addr_idx;
	u32 cfg =
		readl_relaxed(drvdata->sfrbase + REG_PRIVATE_WAY_CFG(way_idx));

	cfg &= ~MMU_PRIVATE_WAY_MASK;
	cfg |= MMU_WAY_CFG_ADDR_MATCHING | MMU_WAY_CFG_PRIVATE_ENABLE |
						priv_cfg[priv_addr_idx].cfg;

	writel_relaxed(cfg, drvdata->sfrbase + REG_PRIVATE_WAY_CFG(way_idx));

	dev_dbg(drvdata->sysmmu, "priv ADDR way[%d] cfg : %#x\n", way_idx, cfg);
}

static inline void __sysmmu_set_tlb_way_type(struct sysmmu_drvdata *drvdata)
{
	u32 cfg = readl_relaxed(drvdata->sfrbase + REG_MMU_CAPA0_V7);
	u32 tlb_way_num = MMU_CAPA_NUM_TLB_WAY(cfg);
	u32 set_cnt = 0;
	struct tlb_props *tlb_props = &drvdata->tlb_props;
	unsigned int i;
	int priv_id_cnt = tlb_props->way_props.priv_id_cnt;
	int priv_addr_cnt = tlb_props->way_props.priv_addr_cnt;

	if (tlb_props->flags & TLB_WAY_PUBLIC)
		__sysmmu_set_public_way(drvdata,
				tlb_props->way_props.public_cfg);

	if (tlb_props->flags & TLB_WAY_PRIVATE_ID) {
		for (i = 0; i < priv_id_cnt &&
				set_cnt < tlb_way_num; i++, set_cnt++)
			__sysmmu_set_private_way_id(drvdata, i);
	}

	if (tlb_props->flags & TLB_WAY_PRIVATE_ADDR) {
		for (i = 0; i < priv_addr_cnt &&
				set_cnt < tlb_way_num; i++, set_cnt++)
			__sysmmu_set_private_way_addr(drvdata, i);
	}

	if (priv_id_cnt + priv_addr_cnt > tlb_way_num) {
		dev_warn(drvdata->sysmmu,
				"Too many values than TLB way count %d,"
				" so ignored!\n", tlb_way_num);
		dev_warn(drvdata->sysmmu,
				"Number of private way id/addr = %d/%d\n",
				priv_id_cnt, priv_addr_cnt);
	}
}

static inline void __sysmmu_set_tlb_port(struct sysmmu_drvdata *drvdata,
						unsigned int port_idx)
{
	struct tlb_port_cfg *port_cfg = drvdata->tlb_props.port_props.port_cfg;

	writel_relaxed(MMU_TLB_CFG_MASK(port_cfg[port_idx].cfg),
			drvdata->sfrbase + REG_MMU_TLB_CFG(port_idx));

	/* port_idx 0 is default port. */
	if (port_idx == 0) {
		dev_dbg(drvdata->sysmmu, "port[%d] cfg : %#x for common\n",
				port_idx,
				MMU_TLB_CFG_MASK(port_cfg[port_idx].cfg));
		return;
	}

	writel_relaxed(MMU_TLB_MATCH_CFG_MASK(port_cfg[port_idx].cfg),
			drvdata->sfrbase + REG_MMU_TLB_MATCH_CFG(port_idx));
	writel_relaxed(port_cfg[port_idx].id,
			drvdata->sfrbase + REG_MMU_TLB_MATCH_ID(port_idx));

	dev_dbg(drvdata->sysmmu, "port[%d] cfg : %#x, match : %#x, id : %#x\n",
				port_idx,
				MMU_TLB_CFG_MASK(port_cfg[port_idx].cfg),
				MMU_TLB_MATCH_CFG_MASK(port_cfg[port_idx].cfg),
				port_cfg[port_idx].id);
}

static inline void __sysmmu_set_tlb_port_type(struct sysmmu_drvdata *drvdata)
{
	u32 cfg = readl_relaxed(drvdata->sfrbase + REG_MMU_CAPA1_V7);
	u32 tlb_num = MMU_CAPA1_NUM_TLB(cfg);
	struct tlb_props *tlb_props = &drvdata->tlb_props;
	unsigned int i;
	int port_id_cnt = tlb_props->port_props.port_id_cnt;
	int slot_cnt = tlb_props->port_props.slot_cnt;

	if (port_id_cnt > tlb_num) {
		dev_warn(drvdata->sysmmu,
				"Too many values %d than TLB count %d,"
				" so ignored!\n", port_id_cnt, tlb_num);
		port_id_cnt = tlb_num;
	}

	for (i = 0; i < port_id_cnt; i++)
		__sysmmu_set_tlb_port(drvdata, i);

	for (i = 0; i < slot_cnt; i++)
		writel_relaxed(tlb_props->port_props.slot_cfg[i],
				drvdata->sfrbase + REG_SLOT_RSV(i));
}

static inline void __sysmmu_init_config(struct sysmmu_drvdata *drvdata)
{
	unsigned long cfg = 0, cfg_vm = 0;

	if (!drvdata->no_block_mode)
		writel_relaxed(CTRL_BLOCK, drvdata->sfrbase + REG_MMU_CTRL);

	if (IS_TLB_WAY_TYPE(drvdata))
		__sysmmu_set_tlb_way_type(drvdata);
	else if (IS_TLB_PORT_TYPE(drvdata))
		__sysmmu_set_tlb_port_type(drvdata);

	if (drvdata->qos != DEFAULT_QOS_VALUE)
		cfg |= CFG_QOS_OVRRIDE | CFG_QOS(drvdata->qos);

	if (drvdata->has_vcr) {
		cfg_vm = cfg & ~CFG_MASK_VM;
		cfg &= ~CFG_MASK_GLOBAL;
		writel_relaxed(cfg, drvdata->sfrbase + REG_MMU_CFG);
		writel_relaxed(cfg_vm, drvdata->sfrbase + REG_MMU_CFG_VM);
	} else {
		writel_relaxed(cfg, drvdata->sfrbase + REG_MMU_CFG);
	}
}

static inline void __sysmmu_enable_nocount(struct sysmmu_drvdata *drvdata)
{
	__sysmmu_init_config(drvdata);

	__sysmmu_set_ptbase(drvdata, drvdata->pgtable / PAGE_SIZE);

	writel(CTRL_ENABLE, drvdata->sfrbase + REG_MMU_CTRL);
	if (drvdata->has_vcr)
		writel(CTRL_ENABLE | CTRL_FAULT_STALL_MODE,
				drvdata->sfrbase + REG_MMU_CTRL_VM);

	SYSMMU_EVENT_LOG_ENABLE(SYSMMU_DRVDATA_TO_LOG(drvdata));
}

static inline u32 __sysmmu_get_intr_status(struct sysmmu_drvdata *drvdata,
					bool is_secure)
{
	if (is_secure)
		return __secure_info_read(drvdata->securebase + REG_INT_STATUS);
	else
		return readl_relaxed(drvdata->sfrbase + REG_INT_STATUS);
}

static inline u32 __sysmmu_get_fault_address(struct sysmmu_drvdata *drvdata,
					bool is_secure, unsigned long vmid)
{
	if (is_secure)
		return __secure_info_read(
				MMU_SEC_VM_REG(drvdata, IDX_FAULT_VA, vmid));
	else
		return readl_relaxed(MMU_VM_REG(drvdata, IDX_FAULT_VA, vmid));
}

static inline u32 __sysmmu_get_fault_trans_info(struct sysmmu_drvdata *drvdata,
					bool is_secure, unsigned long vmid)
{
	if (is_secure)
		return __secure_info_read(
			MMU_SEC_VM_REG(drvdata, IDX_FAULT_TRANS_INFO, vmid));
	else
		return readl_relaxed(
			MMU_VM_REG(drvdata, IDX_FAULT_TRANS_INFO, vmid));
}

static inline u32 __sysmmu_get_hw_version(struct sysmmu_drvdata *data)
{
	return MMU_RAW_VER(readl_relaxed(data->sfrbase + REG_MMU_VERSION));
}

static inline bool __sysmmu_has_capa1(struct sysmmu_drvdata *data)
{
	return MMU_CAPA1_EXIST(readl_relaxed(data->sfrbase + REG_MMU_CAPA0_V7));
}

static inline u32 __sysmmu_get_capa_type(struct sysmmu_drvdata *data)
{
	return MMU_CAPA1_TYPE(readl_relaxed(data->sfrbase + REG_MMU_CAPA1_V7));
}

static inline bool __sysmmu_get_capa_no_block_mode(
					struct sysmmu_drvdata *data)
{
	return MMU_CAPA1_BLOCK_MODE_DISABLED(
			readl_relaxed(data->sfrbase + REG_MMU_CAPA1_V7));
}
static inline bool __sysmmu_get_capa_vcr_enabled(struct sysmmu_drvdata *data)
{
	return MMU_CAPA1_VCR_ENABLED(
			readl_relaxed(data->sfrbase + REG_MMU_CAPA1_V7));
}
