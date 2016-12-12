/*
 * This file is part of User Interface Framework
 *
 * User Interface Framework is free software: you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public License as
 * published by the Free Software Foundation, either version 3 of the License,
 * or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#pragma once
#ifndef _UIX_HOTKEYCTRL_H__
#define _UIX_HOTKEYCTRL_H__
//----------------------------------------------------------------------------//
#include "uixwindow.h"
//----------------------------------------------------------------------------//
namespace UIX
{
//! Hot key modifier
enum uixHotKeyModifier
{
    //! Alt
    uixHotKeyModifier_Alt = HOTKEYF_ALT,
    //! Ctrl
    uixHotKeyModifier_Control = HOTKEYF_CONTROL,
    //! Super
    uixHotKeyModifier_Ext = HOTKEYF_EXT,
    //! Shift
    uixHotKeyModifier_Shift = HOTKEYF_SHIFT,
};

enum uixHotKeyCombination
{
    uixHotKeyCombination_None = HKCOMB_NONE,
    uixHotKeyCombination_Alt = HKCOMB_A,
    uixHotKeyCombination_Ctrl = HKCOMB_C,
    uixHotKeyCombination_Shift = HKCOMB_S,
    uixHotKeyCombination_ShiftAlt = HKCOMB_SA,
    uixHotKeyCombination_CtrlShift = HKCOMB_SC,
    uixHotKeyCombination_CtrlShiftAlt = HKCOMB_SCA,
};

//! Hot Key control
//! @brief
//!     This controls allow user to enter keyboard hot key
class UIXAPI uixHotKeyCtrl : public uixWindow
{
    uixDECLARE_DYNAMIC_CLASS(uixHotKeyCtrl);
public:
    //! Constructor
    uixHotKeyCtrl();

    //! Destructor
    virtual ~uixHotKeyCtrl();

    //! @copydoc uixWindow::BeforeWindowCreate
    virtual BOOL BeforeWindowCreate(CREATESTRUCT& cs) override;

    //! Gets hot key
    //! @return
    //!     Hot key flags
    DWORD GetHotKey() const;

    //! Sets hot key
    //! @param[in] vKey
    //!     Virtual Key
    //! @param[in] modifier
    //!     Key modifiers
    void SetHotKey(WORD vKey, WORD modifier);

    //! Sets rules for hotkeys
    //! @param[in] invalidCombination
    //!     Invalid combination flags
    //! @param[in] modifier
    //!     Modifiers
    void SetRules(uixHotKeyCombination invalidCombination, WORD modifier);
};
}
//----------------------------------------------------------------------------//
#include "uixhotkeyctrl.inl"
//----------------------------------------------------------------------------//
#endif /* _UIX_HOTKEYCTRL_H__ */