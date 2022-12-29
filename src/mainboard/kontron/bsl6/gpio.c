/* SPDX-License-Identifier: GPL-2.0-only */

#include <mainboard/gpio.h>
#include <soc/gpe.h>
#include <soc/gpio.h>

static const struct pad_config gpio_table[] = {
	PAD_CFG_NF(GPP_A0, NONE, PLTRST, NF1),
	PAD_CFG_NF(GPP_A1, UP_20K, PLTRST, NF1),
	PAD_CFG_NF(GPP_A2, UP_20K, PLTRST, NF1),
	PAD_CFG_NF(GPP_A3, UP_20K, PLTRST, NF1),
	PAD_CFG_NF(GPP_A4, UP_20K, PLTRST, NF1),
	PAD_CFG_NF(GPP_A5, NONE, PLTRST, NF1),
	PAD_CFG_NF(GPP_A6, NONE, PLTRST, NF1),
	PAD_CFG_GPI_INT(GPP_A7, NONE, PLTRST, OFF),
	PAD_CFG_NF(GPP_A8, NONE, PLTRST, NF1),
	PAD_CFG_NF(GPP_A9, DN_20K, PLTRST, NF1),
	PAD_CFG_NF(GPP_A10, DN_20K, PLTRST, NF1),
	PAD_CFG_GPI_INT(GPP_A11, NONE, PLTRST, OFF),
	PAD_CFG_GPO(GPP_A12, 1, PLTRST),
	PAD_CFG_NF(GPP_A13, NONE, DEEP, NF1),
	PAD_CFG_NF(GPP_A14, NONE, DEEP, NF1),
	PAD_CFG_NF(GPP_A15, UP_20K, DEEP, NF1),
	PAD_CFG_GPI_INT(GPP_A16, NONE, PLTRST, OFF),
	PAD_CFG_GPI_INT(GPP_A17, NONE, PLTRST, OFF),
	PAD_CFG_GPI_INT(GPP_A18, NONE, PLTRST, OFF),
	PAD_CFG_GPI_INT(GPP_A19, NONE, PLTRST, OFF),
	PAD_CFG_GPO(GPP_A20, 1, DEEP),
	PAD_CFG_GPO(GPP_A21, 1, DEEP),
	PAD_CFG_GPO(GPP_A22, 1, DEEP),
	PAD_CFG_GPI_INT(GPP_A23, NONE, PLTRST, OFF),

	PAD_CFG_GPI_INT(GPP_B0, NONE, PLTRST, OFF),
	PAD_CFG_GPI_INT(GPP_B1, NONE, PLTRST, OFF),
	PAD_CFG_GPI_INT(GPP_B2, NONE, PLTRST, OFF),
	PAD_CFG_GPO(GPP_B3, 1, DEEP),
	PAD_CFG_NF(GPP_B4, NONE, PLTRST, NF1),
	PAD_CFG_NF(GPP_B5, NONE, DEEP, NF1),
	PAD_CFG_GPO(GPP_B6, 1, DEEP),
	PAD_CFG_GPO(GPP_B7, 1, DEEP),
	PAD_CFG_GPO(GPP_B8, 1, DEEP),
	PAD_CFG_GPO(GPP_B9, 1, DEEP),
	PAD_CFG_GPO(GPP_B10, 1, DEEP),
	PAD_CFG_GPI_INT(GPP_B11, NONE, PLTRST, OFF),
	PAD_CFG_NF(GPP_B12, NONE, DEEP, NF1),
	PAD_CFG_NF(GPP_B13, NONE, DEEP, NF1),
	PAD_CFG_NF(GPP_B14, DN_20K, PLTRST, NF1),
	PAD_CFG_GPI_INT(GPP_B15, NONE, PLTRST, OFF),
	PAD_CFG_GPI_INT(GPP_B16, NONE, PLTRST, OFF),
	PAD_CFG_GPO(GPP_B17, 1, DEEP),
	PAD_CFG_GPI_INT(GPP_B18, NONE, PLTRST, OFF),
	PAD_CFG_GPI_INT(GPP_B19, NONE, PLTRST, OFF),
	PAD_CFG_GPI_INT(GPP_B20, NONE, PLTRST, OFF),
	PAD_CFG_GPI_INT(GPP_B21, NONE, PLTRST, OFF),
	PAD_CFG_GPI_INT(GPP_B22, NONE, PLTRST, OFF),
	PAD_CFG_TERM_GPO(GPP_B23, 1, UP_20K, DEEP),

	PAD_CFG_NF(GPP_C0, NONE, DEEP, NF1),
	PAD_CFG_NF(GPP_C1, NONE, DEEP, NF1),
	PAD_CFG_GPI_SCI(GPP_C2, NONE, DEEP, EDGE_SINGLE, INVERT),
	PAD_CFG_NF(GPP_C3, NONE, DEEP, NF1),
	PAD_CFG_NF(GPP_C4, NONE, DEEP, NF1),
	PAD_CFG_GPI_INT(GPP_C5, NONE, PLTRST, OFF),
	/* XXX: C6 not readable */
	/* XXX: C7 not readable */
	PAD_CFG_NF(GPP_C8, NONE, PLTRST, NF1),
	PAD_CFG_NF(GPP_C9, NONE, PLTRST, NF1),
	PAD_CFG_NF(GPP_C10, NONE, PLTRST, NF1),
	PAD_CFG_NF(GPP_C11, NONE, PLTRST, NF1),
	PAD_CFG_NF(GPP_C12, NONE, PLTRST, NF1),
	PAD_CFG_NF(GPP_C13, NONE, PLTRST, NF1),
	PAD_CFG_NF(GPP_C14, NONE, PLTRST, NF1),
	PAD_CFG_NF(GPP_C15, NONE, PLTRST, NF1),
	PAD_CFG_GPI_INT(GPP_C16, NONE, PLTRST, OFF),
	PAD_CFG_GPI_INT(GPP_C17, NONE, PLTRST, OFF),
	PAD_CFG_GPI_INT(GPP_C18, NONE, PLTRST, OFF),
	PAD_CFG_GPI_INT(GPP_C19, NONE, PLTRST, OFF),
	PAD_CFG_NF(GPP_C20, NONE, PLTRST, NF1),
	PAD_CFG_NF(GPP_C21, NONE, PLTRST, NF1),
	PAD_CFG_NF(GPP_C22, NONE, PLTRST, NF1),
	PAD_CFG_NF(GPP_C23, NONE, PLTRST, NF1),

	PAD_CFG_GPO(GPP_D0, 1, DEEP),
	PAD_CFG_GPI_INT(GPP_D1, NONE, DEEP, OFF),
	PAD_CFG_GPI_INT(GPP_D2, NONE, DEEP, OFF),
	PAD_CFG_GPO(GPP_D3, 1, DEEP),
	PAD_CFG_GPI_INT(GPP_D4, NONE, PLTRST, OFF),
	PAD_CFG_NF(GPP_D5, NONE, PLTRST, NF1),
	PAD_CFG_NF(GPP_D6, NONE, PLTRST, NF1),
	PAD_CFG_NF(GPP_D7, NONE, PLTRST, NF1),
	PAD_CFG_NF(GPP_D8, NONE, PLTRST, NF1),
	PAD_CFG_GPO(GPP_D9, 0, DEEP),
	PAD_CFG_GPO(GPP_D10, 0, DEEP),
	PAD_CFG_GPI_SCI_HIGH(GPP_D11, NONE, DEEP, LEVEL),
	PAD_CFG_GPI_SCI_HIGH(GPP_D12, NONE, DEEP, LEVEL),
	PAD_CFG_GPI_INT(GPP_D13, NONE, PLTRST, OFF),
	PAD_CFG_GPI_INT(GPP_D14, NONE, PLTRST, OFF),
	PAD_CFG_GPI_INT(GPP_D15, NONE, PLTRST, OFF),
	PAD_CFG_GPI_INT(GPP_D16, NONE, PLTRST, OFF),
	PAD_CFG_GPO(GPP_D17, 0, DEEP),
	PAD_CFG_GPI_INT(GPP_D18, NONE, DEEP, OFF),
	PAD_CFG_GPO(GPP_D19, 0, DEEP),
	PAD_CFG_GPO(GPP_D20, 0, DEEP),
	PAD_CFG_GPO(GPP_D21, 1, DEEP),
	PAD_CFG_GPO(GPP_D22, 0, DEEP),
	PAD_CFG_GPI_INT(GPP_D23, NONE, PLTRST, OFF),

	PAD_CFG_NF(GPP_E0, UP_20K, PLTRST, NF1),
	PAD_CFG_NF(GPP_E1, UP_20K, PLTRST, NF1),
	PAD_CFG_GPI_INT(GPP_E2, NONE, PLTRST, OFF),
	PAD_CFG_GPI_SCI_HIGH(GPP_E3, NONE, DEEP, LEVEL),
	PAD_CFG_NF(GPP_E4, NONE, PWROK, NF1),
	PAD_CFG_GPI_INT(GPP_E5, NONE, PLTRST, OFF),
	PAD_CFG_GPI_INT(GPP_E6, NONE, PLTRST, OFF),
	PAD_CFG_GPI_SCI(GPP_E7, NONE, DEEP, EDGE_SINGLE, INVERT),
	PAD_CFG_NF(GPP_E8, NONE, PLTRST, NF1),
	PAD_CFG_NF(GPP_E9, NONE, DEEP, NF1),
	PAD_CFG_NF(GPP_E10, NONE, DEEP, NF1),
	PAD_CFG_NF(GPP_E11, NONE, DEEP, NF1),
	PAD_CFG_NF(GPP_E12, NONE, DEEP, NF1),

	PAD_CFG_GPI_INT(GPP_F0, NONE, PLTRST, OFF),
	PAD_CFG_NF(GPP_F1, UP_20K, PLTRST, NF1),
	PAD_CFG_NF(GPP_F2, NONE, PLTRST, NF1),
	PAD_CFG_NF(GPP_F3, NONE, PLTRST, NF1),
	PAD_CFG_NF(GPP_F4, NONE, PLTRST, NF1),
	PAD_CFG_GPI_SCI(GPP_F5, NONE, DEEP, EDGE_SINGLE, NONE),
	PAD_CFG_NF(GPP_F6, NONE, PWROK, NF1),
	PAD_CFG_GPI_INT(GPP_F7, NONE, PLTRST, OFF),
	PAD_CFG_GPI_INT(GPP_F8, NONE, PLTRST, OFF),
	PAD_CFG_GPI_INT(GPP_F9, NONE, PLTRST, OFF),
	PAD_CFG_GPI_APIC_HIGH(GPP_F10, NONE, PLTRST),
	PAD_CFG_GPI_INT(GPP_F11, NONE, PLTRST, OFF),
	PAD_CFG_GPI_APIC_LOW(GPP_F12, NONE, PLTRST),
	PAD_CFG_GPI_APIC_HIGH(GPP_F13, NONE, PLTRST),
	PAD_CFG_GPI_APIC_LOW(GPP_F14, NONE, DEEP),
	PAD_CFG_NF(GPP_F15, NONE, DEEP, NF1),
	PAD_CFG_NF(GPP_F16, NONE, DEEP, NF1),
	PAD_CFG_NF(GPP_F17, NONE, DEEP, NF1),
	PAD_CFG_GPO(GPP_F18, 1, PLTRST),
	PAD_CFG_NF(GPP_F19, NONE, DEEP, NF1),
	PAD_CFG_NF(GPP_F20, NONE, DEEP, NF1),
	PAD_CFG_NF(GPP_F21, NONE, DEEP, NF1),
	PAD_CFG_GPO(GPP_F22, 1, PLTRST),
	PAD_CFG_GPO(GPP_F23, 1, DEEP),

	PAD_CFG_GPO(GPP_G0, 1, PLTRST),
	PAD_CFG_GPO(GPP_G1, 1, PLTRST),
	PAD_CFG_GPI_SCI_LOW(GPP_G2, NONE, PLTRST, LEVEL),
	PAD_CFG_GPI_SCI_LOW(GPP_G3, NONE, PLTRST, LEVEL),
	PAD_CFG_GPO(GPP_G4, 1, DEEP),
	PAD_CFG_GPI_APIC_HIGH(GPP_G5, NONE, PLTRST),
	PAD_CFG_GPI_SCI(GPP_G6, NONE, PLTRST, EDGE_SINGLE, INVERT),
	PAD_CFG_GPO(GPP_G7, 1, DEEP),
	PAD_CFG_GPI_INT(GPP_G8, NONE, PLTRST, OFF),
	PAD_CFG_GPI_INT(GPP_G9, NONE, PLTRST, OFF),
	PAD_CFG_GPI_INT(GPP_G10, NONE, PLTRST, OFF),
	PAD_CFG_GPI_INT(GPP_G11, NONE, PLTRST, OFF),
	PAD_CFG_GPI_SCI(GPP_G12, DN_20K, PLTRST, EDGE_SINGLE, INVERT),
	PAD_CFG_GPO(GPP_G13, 1, PLTRST),
	PAD_CFG_GPI_SCI(GPP_G14, NONE, PLTRST, EDGE_SINGLE, INVERT),
	PAD_CFG_GPO(GPP_G15, 0, PLTRST),
	PAD_CFG_TERM_GPO(GPP_G16, 1, DN_20K, PLTRST),
	PAD_CFG_GPI_INT(GPP_G17, NONE, PLTRST, OFF),
	PAD_CFG_GPI_APIC_HIGH(GPP_G18, NONE, PLTRST),
	PAD_CFG_NF(GPP_G19, NONE, PLTRST, NF1),
	PAD_CFG_GPI_APIC_HIGH(GPP_G20, NONE, PLTRST),
	PAD_CFG_GPI_SCI(GPP_G21, NONE, DEEP, EDGE_SINGLE, INVERT),
	PAD_CFG_GPO(GPP_G22, 1, PLTRST),
	PAD_CFG_GPO(GPP_G23, 1, PLTRST),

	PAD_CFG_GPO(GPP_H0, 1, DEEP),
	PAD_CFG_GPO(GPP_H1, 1, DEEP),
	PAD_CFG_GPO(GPP_H2, 1, DEEP),
	PAD_CFG_GPO(GPP_H3, 1, DEEP),
	PAD_CFG_GPO(GPP_H4, 1, DEEP),
	PAD_CFG_GPO(GPP_H5, 1, DEEP),
	PAD_CFG_GPO(GPP_H6, 1, DEEP),
	PAD_CFG_GPO(GPP_H7, 1, DEEP),
	PAD_CFG_GPO(GPP_H8, 1, DEEP),
	PAD_CFG_GPO(GPP_H9, 1, DEEP),
	PAD_CFG_GPI_INT(GPP_H10, NONE, PLTRST, OFF),
	PAD_CFG_GPI_INT(GPP_H11, NONE, PLTRST, OFF),
	PAD_CFG_GPI_INT(GPP_H12, NONE, PLTRST, OFF),
	PAD_CFG_GPI_APIC_HIGH(GPP_H13, NONE, PLTRST),
	PAD_CFG_GPI_APIC_HIGH(GPP_H14, NONE, PLTRST),
	PAD_CFG_GPI_APIC_HIGH(GPP_H15, NONE, PLTRST),
	PAD_CFG_GPI_INT(GPP_H16, NONE, PLTRST, OFF),
	PAD_CFG_GPO(GPP_H17, 1, PLTRST),
	PAD_CFG_GPI_INT(GPP_H18, NONE, PLTRST, OFF),
	PAD_CFG_GPI_INT(GPP_H19, NONE, PLTRST, OFF),
	PAD_CFG_GPI_INT(GPP_H20, NONE, PLTRST, OFF),
	PAD_CFG_GPI_INT(GPP_H21, NONE, PLTRST, OFF),
	PAD_CFG_GPI_INT(GPP_H22, NONE, PLTRST, OFF),
	PAD_CFG_GPO(GPP_H23, 0, DEEP),

	PAD_CFG_GPI_INT(GPD0, NONE, PLTRST, OFF),
	PAD_CFG_GPO(GPD1, 0, PWROK),
	PAD_CFG_NF(GPD2, NONE, PWROK, NF1),
	PAD_CFG_NF(GPD3, UP_20K, PWROK, NF1),
	PAD_CFG_NF(GPD4, NONE, PWROK, NF1),
	PAD_CFG_NF(GPD5, NONE, PWROK, NF1),
	PAD_CFG_NF(GPD6, NONE, PWROK, NF1),
	PAD_CFG_GPO(GPD7, 1, PWROK),
	PAD_CFG_NF(GPD8, NONE, PWROK, NF1),
	PAD_CFG_GPO(GPD9, 0, PWROK),
	PAD_CFG_NF(GPD10, NONE, PWROK, NF1),
	PAD_CFG_NF(GPD11, NONE, PWROK, NF1),

	PAD_CFG_NF(GPP_I0, NONE, PLTRST, NF1),
	PAD_CFG_NF(GPP_I1, NONE, PLTRST, NF1),
	PAD_CFG_NF(GPP_I2, NONE, PLTRST, NF1),
	PAD_CFG_NF(GPP_I3, NONE, PLTRST, NF1),
	PAD_CFG_NF(GPP_I4, NONE, PLTRST, NF1),
	PAD_CFG_NF(GPP_I5, NONE, PLTRST, NF1),
	PAD_CFG_NF(GPP_I6, NONE, PLTRST, NF1),
	PAD_CFG_NF(GPP_I7, NONE, PLTRST, NF1),
	PAD_CFG_NF(GPP_I8, NONE, PLTRST, NF1),
	PAD_CFG_NF(GPP_I9, NONE, PLTRST, NF1),
	PAD_CFG_NF(GPP_I10, NONE, PLTRST, NF1),
};

void mainboard_configure_gpios(void)
{
	gpio_configure_pads(gpio_table, ARRAY_SIZE(gpio_table));
}
