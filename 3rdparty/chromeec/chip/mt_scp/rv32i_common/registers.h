/* Copyright 2020 The Chromium OS Authors. All rights reserved.
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

/* Register map */

#ifndef __CROS_EC_REGISTERS_H
#define __CROS_EC_REGISTERS_H

#include "common.h"
#include "compile_time_macros.h"
#include "intc.h"

#define UNIMPLEMENTED_GPIO_BANK 0

#define SCP_REG_BASE			0x70000000

/* clock control */
#define SCP_CLK_CTRL_BASE		(SCP_REG_BASE + 0x21000)
/* system clock counter value */
#define SCP_CLK_SYS_VAL			REG32(SCP_CLK_CTRL_BASE + 0x0014)
#define   CLK_SYS_VAL_MASK		(0x3ff << 0)
#define   CLK_SYS_VAL_VAL(v)		((v) & CLK_SYS_VAL_MASK)
/* ULPOSC clock counter value */
#define SCP_CLK_HIGH_VAL		REG32(SCP_CLK_CTRL_BASE + 0x0018)
#define   CLK_HIGH_VAL_MASK             (0x1f << 0)
#define   CLK_HIGH_VAL_VAL(v)		((v) & CLK_HIGH_VAL_MASK)
/* sleep mode control */
#define SCP_SLEEP_CTRL                  REG32(SCP_CLK_CTRL_BASE + 0x0020)
#define   SLP_CTRL_EN			BIT(0)
#define   VREQ_COUNT_MASK		(0x7F << 1)
#define   VREQ_COUNT_VAL(v)		(((v) << 1) & VREQ_COUNT_MASK)
#define   SPM_SLP_MODE			BIT(8)
/* clock divider select */
#define SCP_CLK_DIV_SEL			REG32(SCP_CLK_CTRL_BASE + 0x0024)
#define   CLK_DIV_SEL1			0
#define   CLK_DIV_SEL2			1
#define   CLK_DIV_SEL4			2
#define   CLK_DIV_SEL3			3
/* clock gate */
#define SCP_SET_CLK_CG			REG32(SCP_CLK_CTRL_BASE + 0x0030)
#define   CG_TIMER_MCLK			BIT(0)
#define   CG_TIMER_BCLK			BIT(1)
#define   CG_MAD_MCLK			BIT(2)
#define   CG_I2C_MCLK			BIT(3)
#define   CG_I2C_BCLK			BIT(4)
#define   CG_GPIO_MCLK			BIT(5)
#define   CG_AP2P_MCLK			BIT(6)
#define   CG_UART0_MCLK			BIT(7)
#define   CG_UART0_BCLK			BIT(8)
#define   CG_UART0_RST			BIT(9)
#define   CG_UART1_MCLK			BIT(10)
#define   CG_UART1_BCLK			BIT(11)
#define   CG_UART1_RST			BIT(12)
#define   CG_SPI0			BIT(13)
#define   CG_SPI1			BIT(14)
#define   CG_SPI2			BIT(15)
#define   CG_DMA_CH0			BIT(16)
#define   CG_DMA_CH1			BIT(17)
#define   CG_DMA_CH2			BIT(18)
#define   CG_DMA_CH3			BIT(19)
#define   CG_I3C0			BIT(21)
#define   CG_I3C1			BIT(22)
#define   CG_DMA2_CH0			BIT(23)
#define   CG_DMA2_CH1			BIT(24)
#define   CG_DMA2_CH2			BIT(25)
#define   CG_DMA2_CH3			BIT(26)
/* UART clock select */
#define SCP_UART_CK_SEL			REG32(SCP_CLK_CTRL_BASE + 0x0044)
#define   UART0_CK_SEL_SHIFT		0
#define   UART0_CK_SEL_MASK		(0x3 << UART0_CK_SEL_SHIFT)
#define   UART0_CK_SEL_VAL(v)		((v) & UART0_CK_SEL_MASK)
#define   UART0_CK_SW_STATUS_MASK	(0xf << 8)
#define   UART0_CK_SW_STATUS_VAL(v)	((v) & UART0_CK_SW_STATUS_MASK)
#define   UART1_CK_SEL_SHIFT		16
#define   UART1_CK_SEL_MASK		(0x3 << UART1_CK_SEL_SHIFT)
#define   UART1_CK_SEL_VAL(v)		((v) & UART1_CK_SEL_MASK)
#define   UART1_CK_SW_STATUS_MASK	(0xf << 24)
#define   UART1_CK_SW_STATUS_VAL(v)	((v) & UART1_CK_SW_STATUS_MASK)
#define     UART_CK_SEL_26M		0
#define     UART_CK_SEL_32K		1
#define     UART_CK_SEL_ULPOSC		2
#define     UART_CK_SW_STATUS_26M	BIT(0)
#define     UART_CK_SW_STATUS_32K	BIT(1)
#define     UART_CK_SW_STATUS_ULPOS	BIT(2)
/* BCLK clock select */
#define SCP_BCLK_CK_SEL			REG32(SCP_CLK_CTRL_BASE + 0x0048)
#define   BCLK_CK_SEL_SYS_DIV8		0
#define   BCLK_CK_SEL_32K		1
#define   BCLK_CK_SEL_ULPOSC_DIV8	2
/* VREQ control */
#define SCP_CPU_VREQ_CTRL		REG32(SCP_CLK_CTRL_BASE + 0x0054)
#define   VREQ_SEL			BIT(0)
#define   VREQ_VALUE			BIT(4)
#define   VREQ_EXT_SEL			BIT(8)
#define   VREQ_DVFS_SEL			BIT(16)
#define   VREQ_DVFS_VALUE		BIT(20)
#define   VREQ_DVFS_EXT_SEL		BIT(24)
#define   VREQ_SRCLKEN_SEL		BIT(27)
#define   VREQ_SRCLKEN_VALUE		BIT(28)
/* clock on control */
#define SCP_CLK_HIGH_CORE_CG		REG32(SCP_CLK_CTRL_BASE + 0x005C)
#define   HIGH_CORE_CG			BIT(1)
#define SCP_CLK_ON_CTRL			REG32(SCP_CLK_CTRL_BASE + 0x006C)
#define   HIGH_AO			BIT(0)
#define   HIGH_DIS_SUB			BIT(1)
#define   HIGH_CG_AO			BIT(2)
#define   HIGH_CORE_AO			BIT(4)
#define   HIGH_CORE_DIS_SUB		BIT(5)
#define   HIGH_CORE_CG_AO		BIT(6)

/* system control */
#define SCP_SYS_CTRL			REG32(SCP_REG_BASE + 0x24000)
#define   AUTO_DDREN			BIT(9)

/* IPC */
#define SCP_SCP2APMCU_IPC_SET		REG32(SCP_REG_BASE + 0x24080)
#define SCP_SCP2SPM_IPC_SET		REG32(SCP_REG_BASE + 0x24090)
#define   IPC_SCP2HOST			BIT(0)
#define SCP_GIPC_IN_SET			REG32(SCP_REG_BASE + 0x24098)
#define SCP_GIPC_IN_CLR			REG32(SCP_REG_BASE + 0x2409C)
#define   GIPC_IN(n)			BIT(n)

/* UART */
#define SCP_UART_COUNT			2
#define UART_TX_IRQ(n)			CONCAT3(SCP_IRQ_UART, n, _TX)
#define UART_RX_IRQ(n)			CONCAT3(SCP_IRQ_UART, n, _RX)
#define SCP_UART0_BASE			(SCP_REG_BASE + 0x26000)
#define SCP_UART1_BASE			(SCP_REG_BASE + 0x27000)
#define SCP_UART_BASE(n)		CONCAT3(SCP_UART, n, _BASE)
#define UART_REG(n, offset)		REG32_ADDR(SCP_UART_BASE(n))[offset]

/* WDT */
#define SCP_CORE0_WDT_IRQ		REG32(SCP_REG_BASE + 0x30030)
#define SCP_CORE0_WDT_CFG		REG32(SCP_REG_BASE + 0x30034)
#define   WDT_FREQ			33825 /* 0xFFFFF / 31 */
#define   WDT_MAX_PERIOD		0xFFFFF /* 31 seconds */
#define   WDT_PERIOD(ms)		(WDT_FREQ * (ms) / 1000)
#define   WDT_EN			BIT(31)
#define SCP_CORE0_WDT_KICK		REG32(SCP_REG_BASE + 0x30038)
#define SCP_CORE0_WDT_CUR_VAL		REG32(SCP_REG_BASE + 0x3003C)
#define SCP_CORE0_MON_PC_LATCH		REG32(SCP_REG_BASE + 0x300D0)
#define SCP_CORE0_MON_LR_LATCH		REG32(SCP_REG_BASE + 0x300D4)
#define SCP_CORE0_MON_SP_LATCH		REG32(SCP_REG_BASE + 0x300D8)

/* INTC */
#define SCP_INTC_WORD(irq)		((irq) >> 5) /* word length = 2^5 */
#define SCP_INTC_BIT(irq)		((irq) & 0x1F) /* bit shift =LSB[0:4] */
#define SCP_INTC_GRP_COUNT		15
#define SCP_INTC_GRP_GAP		4

#define SCP_CORE0_INTC_IRQ_BASE		(SCP_REG_BASE + 0x32000)
#define SCP_CORE0_INTC_IRQ_STA(w) \
		REG32_ADDR(SCP_CORE0_INTC_IRQ_BASE + 0x0010)[(w)]
#define SCP_CORE0_INTC_IRQ_EN(w) \
		REG32_ADDR(SCP_CORE0_INTC_IRQ_BASE + 0x0020)[(w)]
#define SCP_CORE0_INTC_IRQ_POL(w) \
		REG32_ADDR(SCP_CORE0_INTC_IRQ_BASE + 0x0040)[(w)]
#define SCP_CORE0_INTC_IRQ_GRP(g, w) \
		REG32_ADDR(SCP_CORE0_INTC_IRQ_BASE + 0x0050 + \
			   ((g) << SCP_INTC_GRP_GAP))[(w)]
#define SCP_CORE0_INTC_IRQ_GRP_STA(g, w) \
		REG32_ADDR(SCP_CORE0_INTC_IRQ_BASE + 0x0150 + \
			   ((g) << SCP_INTC_GRP_GAP))[(w)]
#define SCP_CORE0_INTC_SLP_WAKE_EN(w) \
		REG32_ADDR(SCP_CORE0_INTC_IRQ_BASE + 0x0240)[(w)]
#define SCP_CORE0_INTC_IRQ_OUT		REG32(SCP_CORE0_INTC_IRQ_BASE + 0x0250)
/* UART */
#define SCP_CORE0_INTC_UART0_RX_IRQ	REG32(SCP_CORE0_INTC_IRQ_BASE + 0x0258)
#define SCP_CORE0_INTC_UART1_RX_IRQ	REG32(SCP_CORE0_INTC_IRQ_BASE + 0x025C)
#define SCP_CORE0_INTC_UART_RX_IRQ(n)	CONCAT3(SCP_CORE0_INTC_UART, n, _RX_IRQ)

/* XGPT (general purpose timer) */
#define NUM_TIMERS			6
#define SCP_CORE0_TIMER_BASE(n)		(SCP_REG_BASE + 0x33000 + (0x10 * (n)))
#define SCP_CORE0_TIMER_EN(n)		REG32(SCP_CORE0_TIMER_BASE(n) + 0x0000)
#define   TIMER_EN			BIT(0)
#define   TIMER_CLK_SRC_32K		(0 << 4)
#define   TIMER_CLK_SRC_26M		(1 << 4)
#define   TIMER_CLK_SRC_BCLK		(2 << 4)
#define   TIMER_CLK_SRC_MCLK		(3 << 4)
#define   TIMER_CLK_SRC_MASK		(3 << 4)
#define SCP_CORE0_TIMER_RST_VAL(n)	REG32(SCP_CORE0_TIMER_BASE(n) + 0x0004)
#define SCP_CORE0_TIMER_CUR_VAL(n)	REG32(SCP_CORE0_TIMER_BASE(n) + 0x0008)
#define SCP_CORE0_TIMER_IRQ_CTRL(n)	REG32(SCP_CORE0_TIMER_BASE(n) + 0x000C)
#define   TIMER_IRQ_EN			BIT(0)
#define   TIMER_IRQ_STATUS		BIT(4)
#define   TIMER_IRQ_CLR			BIT(5)
#define SCP_IRQ_TIMER(n)		CONCAT2(SCP_IRQ_TIMER, n)

/* secure control */
#define SCP_SEC_CTRL			REG32(SCP_REG_BASE + 0xA5000)
#define   VREQ_SECURE_DIS		BIT(4)
/* memory remap */
#define SCP_R_REMAP_0X0123		REG32(SCP_REG_BASE + 0xA5060)
#define SCP_R_REMAP_0X4567		REG32(SCP_REG_BASE + 0xA5064)
#define SCP_R_REMAP_0X89AB		REG32(SCP_REG_BASE + 0xA5068)
#define SCP_R_REMAP_0XCDEF		REG32(SCP_REG_BASE + 0xA506C)

/* external address: AP */
#define AP_REG_BASE			0x60000000 /* 0x10000000 remap to 0x6 */
/* AP GPIO */
#define AP_GPIO_BASE			(AP_REG_BASE + 0x5000)
#define AP_GPIO_MODE11_SET		REG32(AP_GPIO_BASE + 0x03B4)
#define AP_GPIO_MODE11_CLR		REG32(AP_GPIO_BASE + 0x03B8)
#define AP_GPIO_MODE12_SET		REG32(AP_GPIO_BASE + 0x03C4)
#define AP_GPIO_MODE12_CLR		REG32(AP_GPIO_BASE + 0x03C8)
#define AP_GPIO_MODE20_SET		REG32(AP_GPIO_BASE + 0x0444)
#define AP_GPIO_MODE20_CLR		REG32(AP_GPIO_BASE + 0x0448)

#include "clock_regs.h"

#endif /* __CROS_EC_REGISTERS_H */
