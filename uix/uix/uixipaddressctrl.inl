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
#ifndef _UIX_IPADDRESSCTRL_INL__
#define _UIX_IPADDRESSCTRL_INL__
//----------------------------------------------------------------------------//
#include "uixipaddressctrl.h"
//----------------------------------------------------------------------------//
namespace UIX
{
//----------------------------------------------------------------------------//
UIXINLINE void uixIPAddressCtrl::Clear()
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    SendMessage(IPM_CLEARADDRESS, 0, 0);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixIPAddressCtrl::IsBlank() const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (BOOL)SendMessage(IPM_ISBLANK, 0, 0);
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixIPAddressCtrl::GetAddress(uixIPAddress& address) const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (INT)SendMessage(IPM_GETADDRESS, 0, (LPARAM)&address);
}
//----------------------------------------------------------------------------//
UIXINLINE void uixIPAddressCtrl::SetAddress(uixIPAddress address)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    SendMessage(IPM_SETADDRESS, 0, (LPARAM)address);
}
//----------------------------------------------------------------------------//
UIXINLINE void uixIPAddressCtrl::SetFocus(UINT fieldID)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    SendMessage(IPM_SETFOCUS, fieldID, 0);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixIPAddressCtrl::SetRange(UINT fieldID, BYTE low, BYTE high)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (BOOL)SendMessage(IPM_SETRANGE, fieldID, MAKEIPRANGE(low, high));
}
//----------------------------------------------------------------------------//
}
//----------------------------------------------------------------------------//
#endif /* _UIX_IPADDRESSCTRL_INL__ */