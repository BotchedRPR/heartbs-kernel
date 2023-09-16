#include <linux/module.h>
#include <soc/samsung/debug-snapshot.h>
#include <soc/samsung/ect_parser.h>
#include <soc/samsung/cal-if.h>
#ifdef CONFIG_EXYNOS9820_BTS
#include <soc/samsung/bts.h>
#endif
#if defined(CONFIG_EXYNOS_BCM_DBG)
#include <soc/samsung/exynos-bcm_dbg.h>
#endif

#include "pwrcal-env.h"
#include "pwrcal-rae.h"
#include "cmucal.h"
#include "ra.h"
#include "acpm_dvfs.h"
#include "fvmap.h"
#include "asv.h"

#include "pmucal_system.h"
#include "pmucal_local.h"
#include "pmucal_cpu.h"
#include "pmucal_dbg.h"
#include "pmucal_cp.h"
#include "pmucal_gnss.h"
#include "pmucal_chub.h"
#include "pmucal_rae.h"
#include "pmucal_powermode.h"

//#if defined(CONFIG_SOC_S5E5515)
//static u32 watch_version;
//#endif

int (*exynos_cal_pd_bcm_sync)(unsigned int id, bool on);
EXPORT_SYMBOL(exynos_cal_pd_bcm_sync);
extern void (*lpd_sram_power_control)(unsigned int enable);
extern void (*lpd_sram_cal_data_init)(void);

static DEFINE_SPINLOCK(pmucal_cpu_lock);

unsigned int cal_clk_is_enabled(unsigned int id)
{
	return 0;
}

unsigned long cal_dfs_get_max_freq(unsigned int id)
{
	return vclk_get_max_freq(id);
}

unsigned long cal_dfs_get_min_freq(unsigned int id)
{
	return vclk_get_min_freq(id);
}

unsigned int cal_dfs_get_lv_num(unsigned int id)
{
	return vclk_get_lv_num(id);
}

int cal_dfs_get_bigturbo_max_freq(unsigned int *table)
{
	return vclk_get_bigturbo_table(table);
}

int cal_dfs_set_rate(unsigned int id, unsigned long rate)
{
	struct vclk *vclk;
	int ret;

	if (IS_ACPM_VCLK(id)) {
		ret = exynos_acpm_set_rate(GET_IDX(id), rate);
		if (!ret) {
			vclk = cmucal_get_node(id);
			if (vclk)
				vclk->vrate = (unsigned int)rate;
		}
	} else {
		ret = vclk_set_rate(id, rate);
	}

	return ret;
}

int cal_dfs_set_rate_switch(unsigned int id, unsigned long switch_rate)
{
	int ret = 0;

	ret = vclk_set_rate_switch(id, switch_rate);

	return ret;
}

int cal_dfs_set_rate_restore(unsigned int id, unsigned long switch_rate)
{
	int ret = 0;

	ret = vclk_set_rate_restore(id, switch_rate);

	return ret;
}

unsigned long cal_dfs_cached_get_rate(unsigned int id)
{
	unsigned long ret;

	ret = vclk_get_rate(id);

	return ret;
}

unsigned long cal_dfs_get_rate(unsigned int id)
{
	unsigned long ret;

	ret = vclk_recalc_rate(id);

	return ret;
}

int cal_dfs_get_rate_table(unsigned int id, unsigned long *table)
{
	int ret;

	ret = vclk_get_rate_table(id, table);

	return ret;
}

int cal_clk_setrate(unsigned int id, unsigned long rate)
{
	int ret = -EINVAL;

	ret = vclk_set_rate(id, rate);

	return ret;
}

unsigned long cal_clk_getrate(unsigned int id)
{
	unsigned long ret = 0;

	ret = vclk_recalc_rate(id);

	return ret;
}

int cal_clk_enable(unsigned int id)
{
	int ret = 0;

	ret = vclk_set_enable(id);

	return ret;
}

int cal_clk_disable(unsigned int id)
{
	int ret = 0;

	ret = vclk_set_disable(id);

	return ret;
}

int cal_qch_init(unsigned int id, unsigned int use_qch)
{
	int ret = 0;

	ret = ra_set_qch(id, use_qch, 0, 0);

	return ret;
}

unsigned int cal_dfs_get_boot_freq(unsigned int id)
{
	return vclk_get_boot_freq(id);
}

unsigned int cal_dfs_get_resume_freq(unsigned int id)
{
	return vclk_get_resume_freq(id);
}

int cal_pd_control(unsigned int id, int on)
{
	unsigned int index;
	int ret;

	if ((id & 0xFFFF0000) != BLKPWR_MAGIC)
		return -1;

	index = id & 0x0000FFFF;

	if (on) {
		ret = pmucal_local_enable(index);
#ifdef CONFIG_EXYNOS9820_BTS
		if (index == 0x7)
			bts_pd_sync(id, on);
#endif
#if defined(CONFIG_EXYNOS_BCM_DBG)
		if (cal_pd_status(id))
			exynos_bcm_dbg_pd_sync(id, true);
#endif
	} else {
#ifdef CONFIG_EXYNOS9820_BTS
		if (index == 0x7)
			bts_pd_sync(id, on);
#endif
#if defined(CONFIG_EXYNOS_BCM_DBG)
		if (cal_pd_status(id))
			exynos_bcm_dbg_pd_sync(id, false);
#endif
		ret = pmucal_local_disable(index);
	}

	return ret;
}

int cal_pd_status(unsigned int id)
{
	unsigned int index;

	if ((id & 0xFFFF0000) != BLKPWR_MAGIC)
		return -1;

	index = id & 0x0000FFFF;

	return pmucal_local_is_enabled(index);
}

int cal_pd_set_smc_id(unsigned int id, int need_smc)
{
	unsigned int index;

	if (need_smc && ((id & 0xFFFF0000) != BLKPWR_MAGIC))
		return -1;

	index = id & 0x0000FFFF;

	pmucal_local_set_smc_id(index, need_smc);

	return 0;
}

int cal_pm_enter(int mode)
{
	return pmucal_system_enter(mode);
}

int cal_pm_exit(int mode)
{
	return pmucal_system_exit(mode);
}

int cal_pm_earlywakeup(int mode)
{
	return pmucal_system_earlywakeup(mode);
}

int cal_cpu_enable(unsigned int cpu)
{
	int ret;

	spin_lock(&pmucal_cpu_lock);
	ret = pmucal_cpu_enable(cpu);
	spin_unlock(&pmucal_cpu_lock);

	return ret;
}

int cal_cpu_disable(unsigned int cpu)
{
	int ret;

	spin_lock(&pmucal_cpu_lock);
	ret = pmucal_cpu_disable(cpu);
	spin_unlock(&pmucal_cpu_lock);

	return ret;
}

int cal_cpu_status(unsigned int cpu)
{
	int ret;

	spin_lock(&pmucal_cpu_lock);
	ret = pmucal_cpu_is_enabled(cpu);
	spin_unlock(&pmucal_cpu_lock);

	return ret;
}

int cal_cluster_enable(unsigned int cluster)
{
	int ret;

	spin_lock(&pmucal_cpu_lock);
	ret = pmucal_cpu_cluster_enable(cluster);
	spin_unlock(&pmucal_cpu_lock);

	return ret;
}

int cal_cluster_disable(unsigned int cluster)
{
	int ret;

	spin_lock(&pmucal_cpu_lock);
	ret = pmucal_cpu_cluster_disable(cluster);
	spin_unlock(&pmucal_cpu_lock);

	return ret;
}

int cal_cluster_status(unsigned int cluster)
{
	int ret;

	spin_lock(&pmucal_cpu_lock);
	ret = pmucal_cpu_cluster_is_enabled(cluster);
	spin_unlock(&pmucal_cpu_lock);

	return ret;
}

int cal_cluster_req_emulation(unsigned int cluster, bool en)
{
	int ret;

	spin_lock(&pmucal_cpu_lock);
	ret = pmucal_cpu_cluster_req_emulation(cluster, en);
	spin_unlock(&pmucal_cpu_lock);

	return ret;
}

void cal_lpd_sram_power_control(unsigned int enable)
{
	if (lpd_sram_power_control)
		lpd_sram_power_control(enable);
}
EXPORT_SYMBOL(cal_lpd_sram_power_control);

extern int cal_is_lastcore_detecting(unsigned int cpu)
{
	return pmucal_is_lastcore_detecting(cpu);
}

int cal_dfs_get_asv_table(unsigned int id, unsigned int *table)
{
	return fvmap_get_voltage_table(id, table);
}

void cal_dfs_set_volt_margin(unsigned int id, int volt)
{
	if (IS_ACPM_VCLK(id))
		exynos_acpm_set_volt_margin(id, volt);
}

int cal_dfs_get_rate_asv_table(unsigned int id,
					struct dvfs_rate_volt *table)
{
	unsigned long rate[48];
	unsigned int volt[48];
	int num_of_entry;
	int idx;

	num_of_entry = cal_dfs_get_rate_table(id, rate);
	if (num_of_entry == 0)
		return 0;

	if (num_of_entry != cal_dfs_get_asv_table(id, volt))
		return 0;

	for (idx = 0; idx < num_of_entry; idx++) {
		table[idx].rate = rate[idx];
		table[idx].volt = volt[idx];
	}

	return num_of_entry;
}

int cal_asv_get_ids_info(unsigned int id)
{
	return asv_get_ids_info(id);
}

int cal_asv_get_grp(unsigned int id)
{
	return asv_get_grp(id);
}

int cal_asv_get_tablever(void)
{
	return asv_get_table_ver();
}

#ifdef CONFIG_CP_PMUCAL
int cal_cp_init(void)
{
	return pmucal_cp_init();
}

int cal_cp_status(void)
{
	return pmucal_cp_status();
}

int cal_cp_reset_assert(void)
{
	return pmucal_cp_reset_assert();
}

int cal_cp_reset_release(void)
{
	return pmucal_cp_reset_release();
}

void cal_cp_active_clear(void)
{
	pmucal_cp_active_clear();
}

void cal_cp_reset_req_clear(void)
{
	pmucal_cp_reset_req_clear();
}

void cal_cp_enable_dump_pc_no_pg(void)
{
	pmucal_cp_enable_dump_pc_no_pg();
}

void cal_cp_disable_dump_pc_no_pg(void)
{
	pmucal_cp_disable_dump_pc_no_pg();
}
#endif

#ifdef CONFIG_GNSS_PMUCAL
void cal_gnss_init(void)
{
	pmucal_gnss_init();
}
int cal_gnss_status(void)
{
	return pmucal_gnss_status();
}
void cal_gnss_reset_assert(void)
{
	pmucal_gnss_reset_assert();
}
void cal_gnss_reset_release(void)
{
	pmucal_gnss_reset_release();
}
void cal_gnss_reset_req_clear(void)
{
	pmucal_gnss_reset_req_clear();
}
void cal_gnss_active_clear(void)
{
	pmucal_gnss_active_clear();
}
#endif

#if IS_ENABLED(CONFIG_CHUB_PMUCAL)
int cal_chub_on(void)
{
	return pmucal_chub_on();
}

int cal_chub_reset_assert(void)
{
	return pmucal_chub_reset_assert();
}

int cal_chub_reset_release_config(void)
{
	return pmucal_chub_reset_release_config();
}

int cal_chub_reset_release(void)
{
	return pmucal_chub_reset_release();
}

int cal_chub_cm55_reset_release(void)
{
	if (IS_ENABLED(CONFIG_SOC_S5E5515))
		return pmucal_chub_cm55_reset_release();
	else
		return 0;
}
#endif

//#if IS_ENABLED(CONFIG_SOC_S5E5515)
//u32 cal_watch_version(void)
//{
//	return watch_version;
//}
//EXPORT_SYMBOL(cal_watch_version);
//#endif

int __init cal_if_init(void *dev)
{
	static int cal_initialized;
#ifdef CONFIG_DEBUG_FS
	struct resource res;
#endif
	int ret;

	if (cal_initialized == 1)
		return 0;

	ect_parse_binary_header();

	vclk_initialize();

	if (cal_data_init)
		cal_data_init();

	ret = pmucal_rae_init();
	if (ret < 0)
		return ret;

	ret = pmucal_system_init();
	if (ret < 0)
		return ret;

	ret = pmucal_local_init();
	if (ret < 0)
		return ret;

	ret = pmucal_cpu_init();
	if (ret < 0)
		return ret;

	ret = pmucal_cpuinform_init();
	if (ret < 0)
		return ret;

	pmucal_dbg_init();

#ifdef CONFIG_CP_PMUCAL
	ret = pmucal_cp_initialize();
	if (ret < 0)
		return ret;
#endif

#ifdef CONFIG_GNSS_PMUCAL
	ret = pmucal_gnss_initialize();
#endif

#ifdef CONFIG_CHUB_PMUCAL
	ret = pmucal_chub_initialize();
	if (ret < 0)
		return ret;
#endif

//#if defined(CONFIG_SOC_S5E5515)
//	ret = of_property_read_u32(dev, "watch-version", &watch_version);
//	if (ret) {
//			pr_err("%s: watch-version is empty\n", __func__);
//			watch_version = 4;
//		} else {
//			pr_info("%s: watch-version is %d\n", __func__, watch_version);
//	}
//#endif
	exynos_acpm_set_device(dev);

	if (lpd_sram_cal_data_init)
		lpd_sram_cal_data_init();

#ifdef CONFIG_DEBUG_FS
	if (of_address_to_resource(dev, 0, &res) == 0)
		cmucal_dbg_set_cmu_top_base(res.start);
#endif
	cal_initialized = 1;

	return 0;
}
