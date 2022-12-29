/* SPDX-License-Identifier: GPL-2.0-only */

Device (HKEY)
{
	/* Generated by ssdt.c */
	External (\HBDC, IntObj)
	External (\HWAN, IntObj)
	External (\HKBL, IntObj)
	External (\HUWB, IntObj)

	Name (_HID, EisaId (CONFIG_THINKPADEC_HKEY_EISAID))

	Name (BTN, 0)

	Name (BTAB, 0)

	/* MASK */
	Name (DHKN, 0x080C)

	/* Effective Mask */
	Name (EMSK, 0)

	/* Effective Mask for tablet */
	Name (ETAB, 0)

	/* Device enabled. */
	Name (EN, 0)

	Method (_STA, 0, NotSerialized)
	{
		Return (0x0F)
	}

	/* Retrieve event. */
	Method (MHKP, 0, NotSerialized)
	{
		Store (BTN, Local0)
		If (Local0 != 0) {
			Store (Zero, BTN)
			Local0 += 0x1000
			Return (Local0)
		}
		Store (BTAB, Local0)
		If (Local0 != 0) {
			Store (Zero, BTAB)
			Local0 += 0x5000
			Return (Local0)
		}
		Return (Zero)
	}

	/* Report event  */
	Method (RHK, 1, NotSerialized) {
		ShiftLeft (One, Arg0 - 1, Local0)
		If (EMSK & Local0) {
			Store (Arg0, BTN)
			Notify (HKEY, 0x80)
		}
	}

	/* Report tablet  */
	Method (RTAB, 1, NotSerialized) {
		ShiftLeft (One, Arg0 - 1, Local0)
		If (ETAB & Local0) {
			Store (Arg0, BTAB)
			Notify (HKEY, 0x80)
		}
	}

	/* Enable/disable all events.  */
	Method (MHKC, 1, NotSerialized) {
		If (Arg0) {
			Store (DHKN, EMSK)
			Store (Ones, ETAB)
		}
		Else
		{
			Store (Zero, EMSK)
			Store (Zero, ETAB)
		}
		Store (Arg0, EN)
	}

	/* Enable/disable event.  */
	Method (MHKM, 2, NotSerialized) {
		If (Arg0 <= 0x20) {
			ShiftLeft (One, Arg0 - 1, Local0)
			If (Arg1)
			{
				Or (DHKN, Local0, DHKN)
			}
			Else
			{
				DHKN = DHKN & !Local0
			}
			If (EN)
			{
				Store (DHKN, EMSK)
			}
		}
	}

	/* Mask hotkey all. */
	Method (MHKA, 0, NotSerialized)
	{
		Return (0x07FFFFFF)
	}

	/* Report tablet mode switch state */
	Method (MHKG, 0, NotSerialized)
	{
		Return (ShiftLeft(TBSW, 3))
	}

	/* Mute audio */
	Method (SSMS, 1, NotSerialized)
	{
		Store(Arg0, ALMT)
	}

	/* Control mute microphone LED */
	Method (MMTS, 1, NotSerialized)
	{
		If (Arg0)
		{
			TLED(0x8E)
		}
		Else
		{
			TLED(0x0E)
		}
	}

	/* Version */
	Method (MHKV, 0, NotSerialized)
	{
		Return (0x0100)
	}

	/* Master wireless switch state */
	Method (WLSW, 0, NotSerialized)
	{
		Return (\_SB.PCI0.LPCB.EC.GSTS)
	}

	/* Set to one on first boot */
	Name (INIT, 0)

	/* Has thinkpad_acpi module loaded */
	Name (HAST, 0)

	/* State after sleep */
	Name (WBDC, 0)
	/*
	 * Returns the current state:
	 *  Bit 0: BT HW present
	 *  Bit 1: BT radio enabled
	 *  Bit 2: BT state at resume
	 */
	Method (GBDC, 0)
	{
		Store (One, HAST)

		If (HBDC) {
			Store(One, Local0)
			If(\_SB.PCI0.LPCB.EC.BTEB)
			{
				Or(Local0, 2, Local0)
			}
			Or(Local0, ShiftLeft(WBDC, 2), Local0)
			Return (Local0)
		} Else {
			Return (0)
		}
	}

	/*
	 * Set the current state:
	 *  Bit 1: BT radio enabled
	 *  Bit 2: BT state at resume
	 */
	Method (SBDC, 1)
	{
		Store (One, HAST)

		If (HBDC) {
			ShiftRight (Arg0 & 2, 1, Local0)
			Store (Local0, \_SB.PCI0.LPCB.EC.BTEB)
			ShiftRight (Arg0 & 4, 2, Local0)
			Store (Local0, WBDC)
		}
	}

	/* State after sleep */
	Name (WWAN, 0)
	/*
	 * Returns the current state:
	 *  Bit 0: WWAN HW present
	 *  Bit 1: WWAN radio enabled
	 *  Bit 2: WWAN state at resume
	 */
	Method (GWAN, 0)
	{
		Store (One, HAST)

		If (HWAN) {
			Store(One, Local0)
			If(\_SB.PCI0.LPCB.EC.WWEB)
			{
				Or(Local0, 2, Local0)
			}
			Or(Local0, ShiftLeft(WWAN, 2), Local0)
			Return (Local0)
		} Else {
			Return (0)
		}
	}

	/*
	 * Set the current state:
	 *  Bit 1: WWAN radio enabled
	 *  Bit 2: WWAN state at resume
	 */
	Method (SWAN, 1)
	{
		Store (One, HAST)

		If (HWAN) {
			ShiftRight (Arg0 & 2, 1, Local0)
			Store (Local0, \_SB.PCI0.LPCB.EC.WWEB)
			ShiftRight (Arg0 & 4, 2, WWAN)
		}
	}

	/*
	 * Argument is unused.
	 * Returns the current state:
	 *  Bit 9: Backlight HW present
	 *  Bit 0-1: Brightness level
	 */
	Method (MLCG, 1)
	{
		If (HKBL) {
			Store (0x200, Local0)
			/* FIXME: Support 2bit brightness control */
			Or (Local0, \_SB.PCI0.LPCB.EC.KBLT, Local0)
			Return (Local0)
		} Else {
			Return (0)
		}
	}

	/*
	 * Set the current state:
	 * Bit 0-1: Brightness level
	 */
	Method (MLCS, 1)
	{
		If (HKBL) {
			/* FIXME: Support 2bit brightness control */
			Store (Arg0 & 1, \_SB.PCI0.LPCB.EC.WWEB)
		}
	}

	/*
	 * Returns the current state:
	 *  Bit 0: UWB HW present
	 *  Bit 1: UWB radio enabled
	 */
	Method (GUWB, 0)
	{
		If (HUWB) {
			Store (One, Local0)
			If(\_SB.PCI0.LPCB.EC.UWBE)
			{
				Or(Local0, 2, Local0)
			}
			Return (Local0)
		} Else {
			Return (0)
		}
	}

	/*
	 * Set the current state:
	 *  Bit 1: UWB radio enabled
	 */
	Method (SUWB, 1)
	{
		If (HUWB) {
			ShiftRight (Arg0 & 2, 1, Local0)
			Store (Local0, \_SB.PCI0.LPCB.EC.UWBE)
		}
	}

	/*
	 * Called from _WAK
	 */
	Method (WAKE, 1)
	{
		If (HAST) {
			Store (WBDC, \_SB.PCI0.LPCB.EC.BTEB)
			Store (WWAN, \_SB.PCI0.LPCB.EC.WWEB)
		}
	}

	#if CONFIG(H8_HAS_BAT_THRESHOLDS_IMPL)
	#include "thinkpad_bat_thresholds.asl"
	#endif
}
