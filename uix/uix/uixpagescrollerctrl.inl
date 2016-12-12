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
#ifndef _UIX_PAGESCROLLERCTRL_INL__
#define _UIX_PAGESCROLLERCTRL_INL__
//----------------------------------------------------------------------------//
#include "uixpagescrollerctrl.h"
//----------------------------------------------------------------------------//
namespace UIX
{
//----------------------------------------------------------------------------//
UIXINLINE void uixPageScrollerCtrl::SetChild(HWND child)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    uixASSERT(::IsWindow(child));
    Pager_SetChild(m_Handle, child);
}
//----------------------------------------------------------------------------//
UIXINLINE void uixPageScrollerCtrl::RecalcSize()
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    Pager_RecalcSize(m_Handle);
}
//----------------------------------------------------------------------------//
UIXINLINE void uixPageScrollerCtrl::ForwardMouse(BOOL forward)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    Pager_ForwardMouse(m_Handle, forward);
}
//----------------------------------------------------------------------------//
UIXINLINE uixColor uixPageScrollerCtrl::GetBackgroundColor() const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (uixColor)Pager_GetBkColor(m_Handle);
}
//----------------------------------------------------------------------------//
UIXINLINE uixColor uixPageScrollerCtrl::SetBackgroundColor(uixColor color)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (uixColor)Pager_SetBkColor(m_Handle, color);
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixPageScrollerCtrl::GetBorder() const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (INT)Pager_GetBorder(m_Handle);
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixPageScrollerCtrl::SetBorder(INT border)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (INT)Pager_SetBorder(m_Handle, border);
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixPageScrollerCtrl::GetPos() const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (INT)Pager_GetPos(m_Handle);
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixPageScrollerCtrl::SetPos(INT position)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (INT)Pager_SetPos(m_Handle, position);
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixPageScrollerCtrl::GetButtonSize() const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (INT)Pager_GetButtonSize(m_Handle);
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixPageScrollerCtrl::SetButtonSize(INT size)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (INT)Pager_SetButtonSize(m_Handle, size);
}
//----------------------------------------------------------------------------//
UIXINLINE DWORD uixPageScrollerCtrl::GetButtonState(INT buttonID) const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (DWORD)Pager_GetButtonState(m_Handle, buttonID);
}
//----------------------------------------------------------------------------//
}
//----------------------------------------------------------------------------//
#endif /* _UIX_PAGESCROLLERCTRL_INL__ */