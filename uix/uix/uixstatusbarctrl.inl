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
#ifndef _UIX_STATUSBARCTRL_INL__
#define _UIX_STATUSBARCTRL_INL__
//----------------------------------------------------------------------------//
#include "uixstatusbarctrl.h"
//----------------------------------------------------------------------------//
namespace UIX
{
//----------------------------------------------------------------------------//
UIXINLINE HICON uixStatusBarCtrl::GetIcon(INT paneID) const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    if (paneID < 256)
    {
        return (HICON)SendMessage(SB_GETICON, paneID, 0);
    }

    return 0;
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixStatusBarCtrl::SetIcon(INT paneID, HICON icon)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    if (paneID < 256)
    {
        return (BOOL)SendMessage(SB_SETICON, paneID, (LPARAM)icon);
    }

    return FALSE;
}
//----------------------------------------------------------------------------//
UIXINLINE uixColor uixStatusBarCtrl::SetBackgroundColor(uixColor color)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    return (uixColorRef)SendMessage(SB_SETBKCOLOR, 0, (LPARAM)color);
}
//----------------------------------------------------------------------------//
UIXINLINE void uixStatusBarCtrl::GetTipText(INT paneID, uixChar* text, INT size) const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    if (paneID < 256)
    {
        SendMessage(SB_GETTIPTEXT, MAKEWPARAM(paneID, size), (LPARAM)text);
    }
}
//----------------------------------------------------------------------------//
UIXINLINE void uixStatusBarCtrl::SetTipText(INT paneID, const uixChar* text)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    if (paneID < 256)
    {
        SendMessage(SB_SETTIPTEXT, (WPARAM)paneID, (LPARAM)text);
    }
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixStatusBarCtrl::GetPanes(INT panes[], INT count) const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (INT)SendMessage(SB_GETPARTS, count, (LPARAM)panes);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixStatusBarCtrl::SetPanes(INT panes[], INT count)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (BOOL)SendMessage(SB_SETPARTS, count, (LPARAM)panes);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixStatusBarCtrl::GetBorders(INT borders[]) const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (BOOL)SendMessage(SB_GETBORDERS, 0, (LPARAM)borders);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixStatusBarCtrl::GetPaneRect(INT paneID, uixRect& rect) const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (BOOL)SendMessage(SB_GETRECT, paneID, (LPARAM)&rect);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixStatusBarCtrl::IsSimple() const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (BOOL)SendMessage(SB_ISSIMPLE, 0, 0);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixStatusBarCtrl::SetSimple(BOOL value)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (BOOL)SendMessage(SB_SIMPLE, value, 0);
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixStatusBarCtrl::GetPaneText(INT paneID, uixChar* text) const
{
    return LOWORD(SendMessage(SB_GETTEXT, paneID, (LPARAM)text));
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixStatusBarCtrl::GetPaneTextLength(INT paneID) const
{
    return LOWORD(SendMessage(SB_GETTEXTLENGTH, paneID, 0));
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixStatusBarCtrl::SetPaneText(INT paneID, const uixChar* text)
{
    return (BOOL)SendMessage(SB_SETTEXT, MAKEWPARAM(paneID, 0), (LPARAM)text);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixStatusBarCtrl::GetUnicodeFormat() const
{
    return (BOOL)SendMessage(SB_GETUNICODEFORMAT, 0, 0);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixStatusBarCtrl::SetUnicodeFormat(BOOL unicode)
{
    return (BOOL)SendMessage(SB_SETUNICODEFORMAT, unicode, 0);
}
//----------------------------------------------------------------------------//
UIXINLINE void uixStatusBarCtrl::SetMinHeight(INT height)
{
    SendMessage(SB_SETMINHEIGHT, height, 0);
}
//----------------------------------------------------------------------------//
UIXINLINE void uixStatusBarCtrl::RecalcLayout()
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    SendMessage(WM_SIZE, 0, 0);
}
//----------------------------------------------------------------------------//
}
//----------------------------------------------------------------------------//
#endif /* _UIX_STATUSBARCTRL_INL__ */