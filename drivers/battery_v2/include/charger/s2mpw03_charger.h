/*
 * drivers/battery/s2mpw03_charger.h
 *
 * Header of S2MPW03 Charger Driver
 *
 * Copyright (C) 2015 Samsung Electronics
 * Develope by Nguyen Tien Dat <tiendat.nt@samsung.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */

#ifndef S2MPW03_CHARGER_H
#define S2MPW03_CHARGER_H
#include <linux/mfd/samsung/s2mpw03.h>
#include <linux/mfd/samsung/s2mpw03-regulator.h>

#define MASK(width, shift)      (((0x1 << (width)) - 1) << shift)

#define S2MPW03_CHG_REG_INT1		0x00
#define S2MPW03_CHG_REG_INT2		0x01
#define S2MPW03_CHG_REG_INT3		0x02
#define S2MPW03_CHG_REG_INT4		0x03
#define S2MPW03_CHG_REG_INT1M		0x04
#define S2MPW03_CHG_REG_INT2M		0x05
#define S2MPW03_CHG_REG_INT3M		0x06
#define S2MPW03_CHG_REG_INT4M		0x07
#define S2MPW03_CHG_REG_STATUS1		0x08
#define S2MPW03_CHG_REG_STATUS2		0x09
#define S2MPW03_CHG_REG_STATUS3		0x0A
#define S2MPW03_CHG_REG_STATUS4		0x0B
#define S2MPW03_CHG_REG_CTRL1       0x0C
#define S2MPW03_CHG_REG_CTRL2       0x0D
#define S2MPW03_CHG_REG_CTRL3       0x0E
#define S2MPW03_CHG_REG_CTRL4       0x0F
#define S2MPW03_CHG_REG_CTRL5       0x10
#define S2MPW03_CHG_REG_CTRL6       0x11
#define S2MPW03_CHG_REG_CTRL7       0x12
#define S2MPW03_CHG_REG_CTRL8       0x13
#define S2MPW03_CHG_REG_CTRL9   	0x14
#define S2MPW03_CHG_REG_CTRL11		0x16
#define S2MPW03_CHG_REG_CTRL12		0x17
#define S2MPW03_CHG_REG_CHG_OTP1	0x22
#define S2MPW03_CHG_REG_CHG_OTP4	0x25
#define S2MPW03_CHG_ADD_CURR		0x29
#define S2MPW03_CHG_REG_CHG_OTP12	0x2D
#define S2MPW03_CHG_REG_CHG_OTP14	0x2F
#define S2MPW03_CHG_REG_CHG_SET4	0x43

/* S2MPW03_CHG_STATUS1 */
#define CHG_STATUS1_RE_CHG		0
#define CHG_STATUS1_CHG_DONE 	1
#define CHG_STATUS1_TOP_OFF		2
#define	CHG_STATUS1_PRE_CHG		3
#define CHG_STATUS1_CHG_STS		4
#define CHG_STATUS1_CIN2BAT		5
#define CHG_STATUS1_CHGVINOVP 	6
#define CHG_STATUS1_ACOK		7

#define CHGVINOVP_STATUS_MASK	BIT(CHG_STATUS1_CHGVINOVP)
#define CIN2BAT_STATUS_MASK		BIT(CHG_STATUS1_CIN2BAT)
#define TOP_OFF_STATUS_MASK		BIT(CHG_STATUS1_TOP_OFF)
#define CHGSTS_STATUS_MASK		BIT(CHG_STATUS1_CHG_STS)
#define CHG_DONE_STATUS_MASK	BIT(CHG_STATUS1_CHG_DONE)
#define CHG_ACOK_STATUS_MASK		BIT(CHG_STATUS1_ACOK)

/* S2MPW03_CHG_STATUS2 */
#define DET_BAT_STATUS_SHIFT			7
#define DET_BAT_STATUS_MASK				BIT(DET_BAT_STATUS_SHIFT)
#define A2D_CHGINOK_STATUS_SHIFT		6
#define A2D_CHGINOK_STATUS_MASK			BIT(A2D_CHGINOK_STATUS_SHIFT)
#define TMROUT_STATUS_SHIFT				2
#define TMROUT_STATUS_MASK				BIT(TMROUT_STATUS_SHIFT)

/* S2MPW03_CHG_STATUS3 */
#define CV_OK_STATUS			6
#define CV_OK_STATUS_MASK		BIT(CV_OK_STATUS)

/* S2MPW03_CHG_STATUS4 */
#define CHG_STATUS4_JIGON			0
#define CHG_STATUS4_RID_ATTACH		1
#define CHG_STATUS4_FACT_LEAKAGE	2
#define CHG_STATUS4_UART_BOOT_ON	3
#define CHG_STATUS4_UART_BOOT_OFF	4
#define CHG_STATUS4_USB_BOOT_ON		5
#define CHG_STATUS4_USB_BOOT_OFF	6
#define CHG_STATUS4_UART_CABLE		7

#define CHG_STATUS4_JIGON_STS 0x0

#define JIGON_MASK					BIT(CHG_STATUS4_JIGON)
#define RID_ATTACH_MASK				BIT(CHG_STATUS4_RID_ATTACH)
#define FACT_LEAKAGE_MASK			BIT(CHG_STATUS4_FACT_LEAKAGE)
#define UART_BOOT_ON_MASK			BIT(CHG_STATUS4_UART_BOOT_ON)
#define UART_BOOT_OFF_MASK			BIT(CHG_STATUS4_UART_BOOT_OFF)
#define USB_BOOT_ON_MASK			BIT(CHG_STATUS4_USB_BOOT_ON)
#define USB_BOOT_OFF_MASK			BIT(CHG_STATUS4_USB_BOOT_OFF)
#define UART_CABLE_MASK				BIT(CHG_STATUS4_UART_CABLE)

/* S2MPW03_CHG_CTRL1 */
#define EN_CHG_SHIFT		7
#define EN_CHG_MASK			BIT(EN_CHG_SHIFT)

/* S2MPW03_CHG_CTRL2 */
#define CV_SEL_SHIFT	0
#define CV_SEL_WIDTH	6
#define CV_SEL_MASK	MASK(CV_SEL_WIDTH, CV_SEL_SHIFT)

/* S2MPW03_CHG_CTRL3 */
#define FORCED_ADD_ON_SHIFT		1
#define FORCED_ADD_ON_MASK		BIT(FORCED_ADD_ON_SHIFT)

/* S2MPW03_CHG_CTRL4 */
#define T_ADD_SHIFT		1
#define T_ADD_WIDTH		3
#define T_ADD_MASK		MASK(T_ADD_WIDTH, T_ADD_SHIFT)

/* S2MPW03_CHG_CTRL5 */
#define EOC_I_SEL_SHIFT	4
#define EOC_I_SEL_WIDTH	4
#define EOC_I_SEL_MASK	MASK(EOC_I_SEL_WIDTH, EOC_I_SEL_SHIFT)
#define IVR_V_SEL_SHIFT	2
#define IVR_V_SEL_WIDTH	2
#define IVR_V_SEL_MASK	MASK(IVR_V_SEL_WIDTH, IVR_V_SEL_SHIFT)

/* S2MPW03_CHG_CTRL7 */
#define MRST_EN_SHIFT	3
#define MRST_EN_MASK	BIT(MRST_EN_SHIFT)

/* S2MPW03_CHG_CTRL8 */
#define WDT_EN_MASK		1
#define CC_SEL_SHIFT	4
#define CC_SEL_WIDTH	3
#define CC_SEL_MASK	MASK(CC_SEL_WIDTH, CC_SEL_SHIFT)

/* S2MPW03_RID_CTRL1 */
#define TDB_RID_SHIFT	6
#define TDB_RID_WIDTH	2
#define TDB_RID_MASK	MASK(TDB_RID_WIDTH, TDB_RID_SHIFT)

/* S2MPW03_CHG_CTRL11 */
#define NO_TIMEOUT_30M_TM_SHIFT		6
#define NO_TIMEOUT_30M_TM_MASK		BIT(NO_TIMEOUT_30M_TM_SHIFT)

#define FAKE_BAT_LEVEL                  50

/* S2MPW03_CHG_IN2BAT */
#define CHG_IN2BAT_SHIFT		4
#define CHG_IN2BAT_MASK			BIT(CHG_IN2BAT_SHIFT)

enum {
	CHG_REG = 0,
	CHG_DATA,
	CHG_REGS,
};

struct charger_info {
	int dummy;
};


struct s2mpw03_muic;
#if defined(CONFIG_S2MPW03_RID_DETECT)
extern struct muic_platform_data muic_pdata;
extern struct s2mpw03_muic *s2mpw03_init_muic(struct platform_device *pdev);
extern void s2mpw03_muic_unregister(struct s2mpw03_muic *muic);
#else
inline struct s2mpw03_muic *s2mpw03_init_muic(struct platform_device *pdev) { return NULL; }
inline void s2mpw03_muic_unregister(struct s2mpw03_muic *muic) {}
#endif

#endif /*S2MPW03_CHARGER_H*/