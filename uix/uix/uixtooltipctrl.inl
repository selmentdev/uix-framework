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
#ifndef _UIX_TOOLTIPCTRL_INL__
#define _UIX_TOOLTIPCTRL_INL__
//----------------------------------------------------------------------------//
#include "uixtooltipctrl.h"
//----------------------------------------------------------------------------//
namespace UIX
{
//----------------------------------------------------------------------------//
UIXINLINE uixToolTipToolInfo uixToolTipToolInfo::ForWindow(uixWindow* window, const uixChar* text)
{
    uixToolTipToolInfo r;
    ZeroMemory(&r, sizeof(r));

    r.cbSize = sizeof(r);
    r.hwnd = window->GetParent();
    r.uFlags = TTF_IDISHWND | TTF_SUBCLASS;
    r.uId = (UINT_PTR)window->GetHandle();
    r.hinst = uixProcessState::Get().m_Handle;
    r.lpszText = (LPTSTR)text;

    return r;
}
//----------------------------------------------------------------------------//
UIXINLINE uixToolTipToolInfo uixToolTipToolInfo::ForRect(uixWindow* parent, const RECT& rc,
        const uixChar* text)
{
    uixToolTipToolInfo r;
    ZeroMemory(&r, sizeof(r));

    r.cbSize = sizeof(r);
    r.hwnd = parent->GetHandle();
    r.rect = rc;
    r.uFlags = TTF_SUBCLASS;
    r.hinst = uixProcessState::Get().m_Handle;
    r.lpszText = (LPTSTR)text;

    return r;
}
//----------------------------------------------------------------------------//
UIXINLINE void uixToolTipCtrl::SetText(TOOLINFO& info)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);

    //!@todo Possible bug
    SendMessage(TTM_GETTEXT, 0, (LPARAM)&info);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixToolTipCtrl::GetToolInfo(TOOLINFO& info)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);

    return (BOOL)SendMessage(TTM_SETTOOLINFO, 0, (LPARAM)&info);
}
//----------------------------------------------------------------------------//
UIXINLINE void uixToolTipCtrl::SetToolInfo(TOOLINFO& info)
{
    SendMessage(TTM_SETTOOLINFO, 0, (LPARAM)&info);
}
//----------------------------------------------------------------------------//
UIXINLINE void uixToolTipCtrl::SetToolRect(TOOLINFO& info)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);
    SendMessage(TTM_NEWTOOLRECT, 0, (LPARAM)&info);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixToolTipCtrl::SetToolRect(HWND handle, RECT& rect, UINT id)
{
    TOOLINFO tti = {0};
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);

    tti.cbSize = sizeof(tti);
    tti.hwnd = handle;
    tti.uFlags = 0;
    tti.uId = id;
    tti.lpszText = NULLPTR;
    tti.rect = rect;

    return (BOOL)SendMessage(TTM_NEWTOOLRECT, 0, (LPARAM)&tti);
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixToolTipCtrl::GetToolCount()
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);

    return (INT)SendMessage(TTM_GETTOOLCOUNT, 0, 0);
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixToolTipCtrl::GetDelayTime(DWORD type)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);

    return (INT)SendMessage(TTM_GETDELAYTIME, type, 0);
}
//----------------------------------------------------------------------------//
UIXINLINE void uixToolTipCtrl::SetDelayTime(DWORD type, INT time)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);

    SendMessage(TTM_SETDELAYTIME, type, MAKELPARAM(time, 0));
}
//----------------------------------------------------------------------------//
UIXINLINE void uixToolTipCtrl::GetMargin(RECT& rect)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);

    SendMessage(TTM_GETMARGIN, 0, (LPARAM)&rect);
}
//----------------------------------------------------------------------------//
UIXINLINE void uixToolTipCtrl::SetMargin(const RECT& rect)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);

    SendMessage(TTM_SETMARGIN, 0, (LPARAM)&rect);
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixToolTipCtrl::GetMaxTipWidth() const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);

    return (INT)SendMessage(TTM_GETMAXTIPWIDTH, 0, 0);
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixToolTipCtrl::SetMaxTipWidth(INT width) const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);

    return (INT)SendMessage(TTM_SETMAXTIPWIDTH, 0, width);
}
//----------------------------------------------------------------------------//
UIXINLINE uixColor uixToolTipCtrl::GetTipBackgroundColor() const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);

    return (uixColorRef)SendMessage(TTM_GETTIPBKCOLOR, 0, 0);
}
//----------------------------------------------------------------------------//
UIXINLINE void uixToolTipCtrl::SetTipBackgroundColor(uixColor color)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);

    SendMessage(TTM_SETTIPBKCOLOR, (WPARAM)color, 0);
}
//----------------------------------------------------------------------------//
UIXINLINE uixColor uixToolTipCtrl::GetTipTextColor() const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);

    return (uixColorRef)SendMessage(TTM_GETTIPTEXTCOLOR, 0, 0);
}
//----------------------------------------------------------------------------//
UIXINLINE void uixToolTipCtrl::SetTipTextColor(uixColor color)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);

    SendMessage(TTM_SETTIPTEXTCOLOR, (WPARAM)color, 0);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixToolTipCtrl::GetCurrentTool(TOOLINFO* toolInfo)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);

    return (BOOL)SendMessage(TTM_GETCURRENTTOOL, 0, (LPARAM)toolInfo);
}
//----------------------------------------------------------------------------//
UIXINLINE void uixToolTipCtrl::Activate(BOOL active)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);

    SendMessage(TTM_ACTIVATE, active, 0);
}
//----------------------------------------------------------------------------//
UIXINLINE void uixToolTipCtrl::AddToolInfo(TOOLINFO& info)
{
    SendMessage(TTM_ADDTOOL, 0, (LPARAM)&info);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixToolTipCtrl::UpdateTipText(HWND window, uixChar* text, RECT* rect, UINT id)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);
    uixASSERT(window != 0);
    uixASSERT(::IsWindow(window));

    TOOLINFO ti = {0};
    ti.cbSize = sizeof(ti);

    if (id == 0)
    {
        ti.hwnd = window;
        ti.uFlags |= TTF_IDISHWND;
        ti.uId = (UINT_PTR)window;  //!@bug Possible booog
    }
    else
    {
        ti.hwnd = window;
        ti.uId = id;
    }

    if (rect)
    {
        ti.rect = *rect;
    }

    ti.lpszText = text;

    return (BOOL)SendMessage(TTM_UPDATETIPTEXT, 0, (LPARAM)&ti);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixToolTipCtrl::AddTool(HWND window, uixChar* text, const RECT* rect, UINT id)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);
    uixASSERT(window != 0);
    uixASSERT(::IsWindow(window));

    TOOLINFO ti = {0};
    ti.cbSize = sizeof(ti);

    if (id == 0)
    {
        ti.hwnd = ::GetParent(window);
        ti.uFlags |= TTF_IDISHWND;
        ti.uId = (UINT_PTR)window;
    }
    else
    {
        ti.hwnd = window;
        ti.uId = id;
    }

    if (rect != NULLPTR)
    {
        ti.rect = *rect;
    }

    //!@todo How to get instance? Need this before continue
    ti.hinst = 0;

    ti.lpszText = text;

    return (BOOL)SendMessage(TTM_ADDTOOL, 0, (LPARAM)&ti);
}
//----------------------------------------------------------------------------//
UIXINLINE void uixToolTipCtrl::DeleteTool(TOOLINFO& ti)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);

    SendMessage(TTM_DELTOOL, 0, (LPARAM)&ti);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixToolTipCtrl::HitTest(TTHITTESTINFO& hti)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);

    return (BOOL)SendMessage(TTM_HITTEST, 0, (LPARAM)&hti);
}
//----------------------------------------------------------------------------//
UIXINLINE void uixToolTipCtrl::RelayEvent(MSG* msg)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);
    SendMessage(TTM_RELAYEVENT, 0, (LPARAM)msg);
}
//----------------------------------------------------------------------------//
UIXINLINE void uixToolTipCtrl::UpdateTipText(TOOLINFO& ti)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);

    SendMessage(TTM_UPDATETIPTEXT, 0, (LPARAM)&ti);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixToolTipCtrl::EnumTools(UINT index, TOOLINFO& ti)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);
    return (BOOL)SendMessage(TTM_ENUMTOOLS, index, (LPARAM)&ti);
}
//----------------------------------------------------------------------------//
UIXINLINE void uixToolTipCtrl::Pop()
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);

    SendMessage(TTM_POP, 0, 0);
}
//----------------------------------------------------------------------------//
UIXINLINE void uixToolTipCtrl::TrackActivate(TOOLINFO& ti, BOOL activate)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);

    SendMessage(TTM_TRACKACTIVATE, activate, (LPARAM)&ti);
}
//----------------------------------------------------------------------------//
UIXINLINE void uixToolTipCtrl::TrackPosition(INT x, INT y)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);

    SendMessage(TTM_TRACKPOSITION, 0, MAKELPARAM(x, y));
}
//----------------------------------------------------------------------------//
UIXINLINE void uixToolTipCtrl::Update()
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);

    SendMessage(TTM_UPDATE, 0, 0);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixToolTipCtrl::AdjustRect(RECT& rect, BOOL larger)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);

    return (BOOL)SendMessage(TTM_ADJUSTRECT, larger, (LPARAM)&rect);
}
//----------------------------------------------------------------------------//
UIXINLINE DWORD uixToolTipCtrl::GetBubbleSize(TOOLINFO& ti)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);

    return (DWORD)SendMessage(TTM_GETBUBBLESIZE, 0, (LPARAM)&ti);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixToolTipCtrl::SetTitle(UINT icon, const uixChar* title)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);

    return (BOOL)SendMessage(TTM_SETTITLE, icon, (LPARAM)title);
}
//----------------------------------------------------------------------------//
UIXINLINE void uixToolTipCtrl::Popup()
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);
    SendMessage(TTM_POPUP, 0, 0);
}
//----------------------------------------------------------------------------//
UIXINLINE void uixToolTipCtrl::GetTitle(TTGETTITLE& ttgt)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);

    SendMessage(TTM_GETTITLE, 0, (LPARAM)&ttgt);
}
//----------------------------------------------------------------------------//
UIXINLINE void uixToolTipCtrl::SetWindowTheme(const uixChar* theme)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);
    SendMessage(TTM_SETWINDOWTHEME, 0, (LPARAM)theme);
}
//----------------------------------------------------------------------------//
}
//----------------------------------------------------------------------------//
#endif /* _UIX_TOOLTIPCTRL_INL__ */