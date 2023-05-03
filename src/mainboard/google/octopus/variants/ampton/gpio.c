/* SPDX-License-Identifier: GPL-2.0-only */

#include <baseboard/gpio.h>
#include <baseboard/variants.h>
#include <commonlib/helpers.h>

static const struct pad_config variant_override_table[] = {
	/* NORTHWEST COMMUNITY GPIOS */
	PAD_CFG_NF_IOSTANDBY_IGNORE(GPIO_0, NONE, DEEP, NF1), /* TCK */
	PAD_CFG_NF_IOSTANDBY_IGNORE(GPIO_1, DN_20K, DEEP, NF1), /* TRST_B */
	PAD_CFG_NF_IOSTANDBY_IGNORE(GPIO_2, NONE, DEEP, NF1), /* TMS */
	PAD_CFG_NF_IOSTANDBY_IGNORE(GPIO_3, NONE, DEEP, NF1), /* TDI */
	PAD_CFG_NF_IOSTANDBY_IGNORE(GPIO_4, NONE, DEEP, NF1), /* TDO */
	PAD_CFG_NF_IOSTANDBY_IGNORE(GPIO_6, NONE, DEEP, NF1), /* CX_PREQ_B */
	PAD_CFG_NF_IOSTANDBY_IGNORE(GPIO_7, NONE, DEEP, NF1), /* CX_PRDY_B */
	PAD_CFG_NF_IOSSTATE_IOSTERM(GPIO_8, DN_20K, DEEP, NF5, HIZCRx0, DISPUPD), /* TRACE_0_CLK_VNN */
	PAD_CFG_NF_IOSSTATE_IOSTERM(GPIO_9, DN_20K, DEEP, NF5, HIZCRx0, DISPUPD), /* TRACE_0_DATA0_VNN */
	PAD_CFG_NF_IOSSTATE_IOSTERM(GPIO_10, DN_20K, DEEP, NF5, HIZCRx0, DISPUPD), /* TRACE_0_DATA1_VNN */
	PAD_CFG_NF_IOSSTATE_IOSTERM(GPIO_11, DN_20K, DEEP, NF5, HIZCRx0, DISPUPD), /* TRACE_0_DATA2_VNN */
	PAD_CFG_NF_IOSSTATE_IOSTERM(GPIO_12, DN_20K, DEEP, NF5, HIZCRx0, DISPUPD), /* TRACE_0_DATA3_VNN */
	PAD_CFG_NF_IOSSTATE_IOSTERM(GPIO_13, DN_20K, DEEP, NF5, HIZCRx0, DISPUPD), /* TRACE_0_DATA4_VNN */
	PAD_CFG_NF_IOSSTATE_IOSTERM(GPIO_14, DN_20K, DEEP, NF5, HIZCRx0, DISPUPD), /* TRACE_0_DATA5_VNN */
	PAD_CFG_NF_IOSSTATE_IOSTERM(GPIO_15, DN_20K, DEEP, NF5, HIZCRx0, DISPUPD), /* TRACE_0_DATA6_VNN */
	PAD_CFG_NF_IOSSTATE_IOSTERM(GPIO_16, DN_20K, DEEP, NF5, HIZCRx0, DISPUPD), /* TRACE_0_DATA7_VNN */
	PAD_CFG_NF_IOSSTATE_IOSTERM(GPIO_17, DN_20K, DEEP, NF5, HIZCRx0, DISPUPD), /* DBG_PTI_CLK_1 */
	PAD_CFG_NF_IOSSTATE_IOSTERM(GPIO_18, DN_20K, DEEP, NF5, HIZCRx0, DISPUPD), /* DBG_PTI_DATA_8 */
	PAD_CFG_NF_IOSSTATE_IOSTERM(GPIO_19, DN_20K, DEEP, NF5, HIZCRx0, DISPUPD), /* DBG_PTI_DATA_9 */
	PAD_CFG_NF_IOSSTATE_IOSTERM(GPIO_20, DN_20K, DEEP, NF5, HIZCRx0, DISPUPD), /* DBG_PTI_DATA_10 */
	PAD_CFG_NF_IOSSTATE_IOSTERM(GPIO_24, DN_20K, DEEP, NF5, HIZCRx0, DISPUPD), /* TRACE_1_DATA6_VNN */
	PAD_CFG_NF_IOSSTATE_IOSTERM(GPIO_25, DN_20K, DEEP, NF5, HIZCRx0, DISPUPD), /* TRACE_1_DATA7_VNN */
	PAD_CFG_NF_IOSSTATE_IOSTERM(GPIO_26, DN_20K, DEEP, NF5, HIZCRx0, DISPUPD), /* TRACE_2_CLK_VNN */
	PAD_CFG_NF_IOSSTATE_IOSTERM(GPIO_27, DN_20K, DEEP, NF5, HIZCRx0, DISPUPD), /* TRACE_2_DATA0_VNN */
	PAD_CFG_NF_IOSSTATE_IOSTERM(GPIO_28, DN_20K, DEEP, NF5, HIZCRx0, DISPUPD), /* TRACE_2_DATA1_VNN 0*/
	PAD_CFG_NF_IOSSTATE_IOSTERM(GPIO_29, DN_20K, DEEP, NF5, HIZCRx0, DISPUPD), /* TRACE_2_DATA2_VNN */
	PAD_CFG_NF_IOSSTATE_IOSTERM(GPIO_30, DN_20K, DEEP, NF5, HIZCRx0, DISPUPD), /* TRACE_2_DATA3_VNN */
	PAD_CFG_NF_IOSSTATE_IOSTERM(GPIO_31, DN_20K, DEEP, NF5, HIZCRx0, DISPUPD), /* TRACE_2_DATA4_VNN */
	PAD_CFG_NF_IOSSTATE_IOSTERM(GPIO_32, DN_20K, DEEP, NF5, HIZCRx0, DISPUPD), /* TRACE_2_DATA5_VNN */
	PAD_CFG_NF_IOSSTATE_IOSTERM(GPIO_33, DN_20K, DEEP, NF5, HIZCRx0, DISPUPD), /* TRACE_2_DATA6_VNN */
	PAD_CFG_NF_IOSSTATE_IOSTERM(GPIO_34, DN_20K, DEEP, NF5, HIZCRx0, DISPUPD), /* TRACE_2_DATA7_VNN */
	PAD_CFG_NF_IOSSTATE_IOSTERM(GPIO_35, DN_20K, DEEP, NF5, HIZCRx0, DISPUPD), /* TRACE_3_CLK_VNN */
	PAD_CFG_NF_IOSSTATE_IOSTERM(GPIO_36, DN_20K, DEEP, NF5, HIZCRx0, DISPUPD), /* TRACE_3_DATA0_VNN */
	PAD_CFG_NF_IOSSTATE_IOSTERM(GPIO_37, DN_20K, DEEP, NF5, HIZCRx0, DISPUPD), /* TRACE_3_DATA1_VNN */
	PAD_CFG_NF_IOSSTATE_IOSTERM(GPIO_38, DN_20K, DEEP, NF5, HIZCRx0, DISPUPD), /* TRACE_3_DATA2_VNN */
	PAD_CFG_NF_IOSSTATE_IOSTERM(GPIO_43, DN_20K, DEEP, NF1, HIZCRx0, DISPUPD), /* GP_INTD_DSI_TE2 */
	PAD_CFG_NF_IOSSTATE_IOSTERM(GPIO_56, NONE, DEEP, NF1, HIZCRx1, DISPUPD), /* LPSS_I2C3_SDA */
	PAD_CFG_NF_IOSSTATE_IOSTERM(GPIO_57, NONE, DEEP, NF1, HIZCRx1, DISPUPD), /* LPSS_I2C2_SCL */
	PAD_CFG_NF_IOSSTATE_IOSTERM(GPIO_60, UP_20K, DEEP, NF1, HIZCRx1, DISPUPD), /* LPSS_UART0_RXD */
	PAD_CFG_NF_IOSSTATE_IOSTERM(GPIO_61, UP_20K, DEEP, NF1, HIZCRx1, DISPUPD), /* LPSS_UART0_TXD */
	PAD_NC(GPIO_67, UP_20K), /*EN_PP3300_DX_LTE_SOC -- unused */
	PAD_NC(GPIO_213, UP_20K), /* TP_AP_GPIO213 -- unused */
	PAD_NC(GPIO_214, UP_20K), /* P_SENSOR_INT_L -- unused */

	/* LPSS */
	PAD_CFG_GPIO_HI_Z(GPIO_81, UP_20K, DEEP, HIZCRx0, DISPUPD), /* GPIO_81_DEBUG (Boot halt) -- MIPI60 DEBUG */
	PAD_NC(GPIO_84, NONE), /* LPSS_SPI_2_CLK - unused */
	PAD_CFG_GPI_APIC_IOS(GPIO_137, NONE, DEEP, EDGE_BOTH, INVERT, HIZCRx1,
				DISPUPD),/* GPIO_137 -- HP_INT_ODL */
	PAD_CFG_GPO_IOSSTATE_IOSTERM(GPIO_140, 0, DEEP, NONE, Tx1RxDCRx0, DISPUPD),/* GPIO_140 -- PEN_RESET */
	PAD_NC(GPIO_143, UP_20K), /* GPIO_143 - NC */
	PAD_NC(GPIO_144, UP_20K), /* GPIO_144 - PEN_EJECT */
	PAD_NC(GPIO_145, UP_20K), /* GPIO_145 - PEN_EJECT */
	PAD_CFG_GPO_IOSSTATE_IOSTERM(GPIO_146, 0, DEEP, NONE, Tx0RxDCRx0, DISPUPD), /* EN_PP3300_TOUCHSCREEN */

	/* AUDIO COMMUNITY GPIOS*/
	PAD_NC(GPIO_157, DN_20K),/* AVS_I2S0_BCLK -- unused */
	PAD_NC(GPIO_158, DN_20K),/* AVS_I2S0_WS_SYNC -- unused */
	PAD_NC(GPIO_159, DN_20K),/* AVS_I2S0_SDI -- unused */
	PAD_NC(GPIO_161, DN_20K),/* AVS_I2S1_MCLK -- unused */

	/* Disable standby for GPIO_171 and GPIO_173 to support Wake on Voice */
	PAD_CFG_NF_IOSSTATE(GPIO_171, DN_20K, DEEP, NF1, HIZCRx0), /* AVS_M_CLK_A1 */
	PAD_CFG_NF_IOSSTATE(GPIO_173, DN_20K, DEEP, NF1, HIZCRx0), /* AVS_M_DATA_1 */

	/* EN_PP3300_WLAN_L */
	PAD_CFG_GPO_IOSSTATE_IOSTERM(GPIO_178, 1, DEEP, NONE, Tx0RxDCRx0,
				DISPUPD),
};

const struct pad_config *variant_override_gpio_table(size_t *num)
{
	*num = ARRAY_SIZE(variant_override_table);
	return variant_override_table;
}

/* GPIOs needed prior to ramstage. */
static const struct pad_config early_gpio_table[] = {
	PAD_CFG_GPI(GPIO_190, NONE, DEEP), /* PCH_WP_OD */
	/* GSPI0_INT */
	PAD_CFG_GPI_APIC_IOS(GPIO_63, NONE, DEEP, LEVEL, INVERT, TxDRxE,
		DISPUPD), /* H1_PCH_INT_ODL */
	/* GSPI0_CLK */
	PAD_CFG_NF(GPIO_79, NONE, DEEP, NF1), /* H1_SLAVE_SPI_CLK_R */
	/* GSPI0_CS# */
	PAD_CFG_NF(GPIO_80, NONE, DEEP, NF1), /* H1_SLAVE_SPI_CS_L_R */
	/* GSPI0_MISO */
	PAD_CFG_NF(GPIO_82, NONE, DEEP, NF1), /* H1_SLAVE_SPI_MISO */
	/* GSPI0_MOSI */
	PAD_CFG_NF(GPIO_83, NONE, DEEP, NF1), /* H1_SLAVE_SPI_MOSI_R */

	/* Enable power to wifi early in bootblock and de-assert PERST#. */
	PAD_CFG_GPO(GPIO_178, 0, DEEP), /* EN_PP3300_WLAN_L */
	PAD_CFG_GPO(GPIO_164, 0, DEEP), /* WLAN_PE_RST */

	/*
	 * ESPI_IO1 acts as ALERT# (which is open-drain) and requires a weak
	 * pull-up for proper operation. Since there is no external pull present
	 * on this platform, configure an internal weak pull-up.
	 */
	PAD_CFG_NF_IOSSTATE_IOSTERM(GPIO_151, UP_20K, DEEP, NF2, HIZCRx1,
				    ENPU), /* ESPI_IO1 */
};

const struct pad_config *variant_early_gpio_table(size_t *num)
{
	*num = ARRAY_SIZE(early_gpio_table);
	return early_gpio_table;
}
