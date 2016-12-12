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
#ifndef _UIX_UPDOWNCTRL_INL__
#define _UIX_UPDOWNCTRL_INL__
//----------------------------------------------------------------------------//
namespace UIX
{
//----------------------------------------------------------------------------//
UIXINLINE UINT uixUpDownCtrl::GetAccel(UDACCEL accels[], UINT count) const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (UINT)SendMessage(UDM_GETACCEL, (WPARAM)count, (LPARAM)accels);
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixUpDownCtrl::GetRadixBase() const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (INT)SendMessage(UDM_GETBASE, 0, 0);
}
//----------------------------------------------------------------------------//
UIXINLINE HWND uixUpDownCtrl::GetBuddy() const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (HWND)SendMessage(UDM_GETBUDDY, 0, 0);
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixUpDownCtrl::GetValue() const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (INT)SendMessage(UDM_GETPOS32, 0, 0);
}
//----------------------------------------------------------------------------//
UIXINLINE void uixUpDownCtrl::GetRange(INT& low, INT& high) const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    SendMessage(UDM_GETRANGE32, (WPARAM)&low, (LPARAM)&high);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixUpDownCtrl::GetUnicodeFormat() const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (BOOL)SendMessage(UDM_GETUNICODEFORMAT, 0, 0);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixUpDownCtrl::SetAccel(const UDACCEL accels[], UINT count)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (BOOL)SendMessage(UDM_SETACCEL, count, (LPARAM)accels);
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixUpDownCtrl::SetRadixBase(INT base)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (INT)SendMessage(UDM_SETBASE, base, 0);
}
//----------------------------------------------------------------------------//
UIXINLINE HWND uixUpDownCtrl::SetBuddy(HWND handle)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (HWND)SendMessage(UDM_SETBUDDY, (WPARAM)handle, 0);
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixUpDownCtrl::SetValue(INT position)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (INT)SendMessage(UDM_SETPOS32, 0, position);
}
//----------------------------------------------------------------------------//
UIXINLINE void uixUpDownCtrl::SetRange(INT low, INT high)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    SendMessage(UDM_SETRANGE32, low, high);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixUpDownCtrl::SetUnicodeFormat(BOOL unicode)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (BOOL)SendMessage(UDM_SETUNICODEFORMAT, unicode, 0);
}
//----------------------------------------------------------------------------//
}
//----------------------------------------------------------------------------//
#endif /* _UIX_UPDOWNCTRL_INL__ */