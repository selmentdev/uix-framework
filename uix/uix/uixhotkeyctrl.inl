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
#ifndef _UIX_HOTKEYCTRL_INL__
#define _UIX_HOTKEYCTRL_INL__
//----------------------------------------------------------------------------//
#include "uixhotkeyctrl.h"
//----------------------------------------------------------------------------//
namespace UIX
{
//----------------------------------------------------------------------------//
UIXINLINE DWORD uixHotKeyCtrl::GetHotKey() const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);

    return (DWORD)SendMessage(HKM_GETHOTKEY, 0, 0);
}
//----------------------------------------------------------------------------//
UIXINLINE void uixHotKeyCtrl::SetHotKey(WORD vKey, WORD modifier)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);
    SendMessage(HKM_SETHOTKEY, MAKEWORD(vKey, modifier), 0);
}
//----------------------------------------------------------------------------//
UIXINLINE void uixHotKeyCtrl::SetRules(uixHotKeyCombination invalidCombination, WORD modifier)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);
    SendMessage(HKM_SETRULES, MAKEWORD(invalidCombination, modifier), 0);
}
//----------------------------------------------------------------------------//
}
//----------------------------------------------------------------------------//
#endif /* _UIX_HOTKEYCTRL_INL__ */