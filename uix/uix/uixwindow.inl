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
#ifndef _UIX_WINDOW_INL__
#define _UIX_WINDOW_INL__
//----------------------------------------------------------------------------//
#include "uixwindow.h"
//----------------------------------------------------------------------------//
namespace UIX
{
//----------------------------------------------------------------------------//
#pragma region Window Tree
//----------------------------------------------------------------------------//
UIXINLINE HWND uixWindow::GetHandle() const
{
    uixASSERT(this != NULLPTR);

    return m_Handle;
}
//----------------------------------------------------------------------------//
UIXINLINE HWND uixWindow::GetHandleSafe() const
{
    if (this != NULLPTR)
    {
        return m_Handle;
    }

    return 0;
}
//----------------------------------------------------------------------------//
UIXINLINE HWND uixWindow::SetParent(HWND newParent)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    return ::SetParent(m_Handle, newParent);
}
//----------------------------------------------------------------------------//
UIXINLINE HWND uixWindow::GetParent() const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    return ::GetParent(m_Handle);
}
//----------------------------------------------------------------------------//
UIXINLINE uixWindowID uixWindow::GetID() const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    return (uixWindowID)::GetWindowLongPtr(m_Handle, GWLP_ID);
}
//----------------------------------------------------------------------------//
UIXINLINE uixWindowID uixWindow::SetID(uixWindowID id)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    return (uixWindowID)::SetWindowLongPtr(m_Handle, GWLP_ID, id);
}
//----------------------------------------------------------------------------//
UIXINLINE HWND uixWindow::GetAncestor(UINT flags) const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    return (HWND)::GetAncestor(m_Handle, flags);
}
//----------------------------------------------------------------------------//
UIXINLINE HWND uixWindow::GetActiveWindow()
{
    return ::GetActiveWindow();
}

//----------------------------------------------------------------------------//
UIXINLINE HWND uixWindow::SetActiveWindow(HWND handle)
{
    return ::SetActiveWindow(handle);
}
//----------------------------------------------------------------------------//
UIXINLINE HWND uixWindow::SetActiveWindow()
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    return ::SetActiveWindow(m_Handle);
}
//----------------------------------------------------------------------------//
UIXINLINE HWND uixWindow::GetForegroundWindow()
{
    return ::GetForegroundWindow();
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixWindow::SetForegroundWindow(HWND handle)
{
    return ::SetForegroundWindow(handle);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixWindow::SetForegroundWindow()
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    return ::SetForegroundWindow(m_Handle);
}
//----------------------------------------------------------------------------//
UIXINLINE HWND uixWindow::GetCapture()
{
    return ::GetCapture();
}
//----------------------------------------------------------------------------//
UIXINLINE HWND uixWindow::SetCapture(HWND handle)
{
    return ::SetCapture(handle);
}
//----------------------------------------------------------------------------//
UIXINLINE HWND uixWindow::SetCapture()
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    return ::SetCapture(m_Handle);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixWindow::ReleaseCapture()
{
    return ::ReleaseCapture();
}
//----------------------------------------------------------------------------//
UIXINLINE HWND uixWindow::GetFocus()
{
    return ::GetFocus();
}
//----------------------------------------------------------------------------//
UIXINLINE HWND uixWindow::SetFocus(HWND handle)
{
    return ::SetFocus(handle);
}
//----------------------------------------------------------------------------//
UIXINLINE HWND uixWindow::SetFocus()
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    return ::SetFocus(m_Handle);
}
//----------------------------------------------------------------------------//
UIXINLINE HWND uixWindow::GetDesktopWindow()
{
    return ::GetDesktopWindow();
}
//----------------------------------------------------------------------------//
UIXINLINE HWND uixWindow::ChildWindowFromPoint(POINT point) const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    return ::ChildWindowFromPoint(m_Handle, point);
}
//----------------------------------------------------------------------------//
UIXINLINE HWND uixWindow::ChildWindowFromPoint(POINT point, UINT flags) const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    return ::ChildWindowFromPointEx(m_Handle, point, flags);
}
//----------------------------------------------------------------------------//
UIXINLINE HWND uixWindow::FindWindow(const uixChar* className, const uixChar* windowName)
{
    return ::FindWindow(className, windowName);
}
//----------------------------------------------------------------------------//
UIXINLINE HWND uixWindow::FindWindow(HWND parent, HWND after, const uixChar* className,
                                     const uixChar* windowName)
{
    return ::FindWindowEx(parent, after, className, windowName);
}
//----------------------------------------------------------------------------//
UIXINLINE HWND uixWindow::GetNext() const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    return ::GetWindow(m_Handle, GW_HWNDNEXT);
}
//----------------------------------------------------------------------------//
UIXINLINE HWND uixWindow::GetPrev() const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    return ::GetWindow(m_Handle, GW_HWNDPREV);
}
//----------------------------------------------------------------------------//
UIXINLINE HWND uixWindow::GetFirst() const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    return ::GetWindow(m_Handle, GW_HWNDFIRST);
}
//----------------------------------------------------------------------------//
UIXINLINE HWND uixWindow::GetLast() const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    return ::GetWindow(m_Handle, GW_HWNDLAST);
}
//----------------------------------------------------------------------------//
UIXINLINE HWND uixWindow::GetOwner() const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    return ::GetWindow(m_Handle, GW_OWNER);
}
//----------------------------------------------------------------------------//
UIXINLINE HWND uixWindow::GetChild() const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    return ::GetWindow(m_Handle, GW_CHILD);
}
//----------------------------------------------------------------------------//
UIXINLINE HWND uixWindow::GetEnabledPopup() const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    return ::GetWindow(m_Handle, GW_ENABLEDPOPUP);
}
//----------------------------------------------------------------------------//
UIXINLINE HWND uixWindow::GetTopWindow() const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    return ::GetTopWindow(m_Handle);
}
//----------------------------------------------------------------------------//
UIXINLINE HWND uixWindow::GetWindow(UINT cmd) const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    return ::GetWindow(m_Handle, cmd);
}
//----------------------------------------------------------------------------//
UIXINLINE HWND uixWindow::GetLastActivePopup() const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    return ::GetLastActivePopup(m_Handle);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixWindow::IsChild(HWND child) const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    return ::IsChild(m_Handle, child);
}
//----------------------------------------------------------------------------//
UIXINLINE HWND uixWindow::WindowFromPoint(POINT point)
{
    return ::WindowFromPoint(point);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixWindow::FlashWindow(BOOL invert)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    return ::FlashWindow(m_Handle, invert);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixWindow::FlashWindow(DWORD flags, UINT count, DWORD timeout)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    FLASHWINFO fwi;
    fwi.cbSize = sizeof(fwi);
    fwi.dwFlags = flags;
    fwi.dwTimeout = timeout;
    fwi.hwnd = m_Handle;
    fwi.uCount = count;
    return ::FlashWindowEx(&fwi);
}
//----------------------------------------------------------------------------//
#pragma region Scrolling
//----------------------------------------------------------------------------//
UIXINLINE INT uixWindow::GetScrollPosition(uixScrollBarID barID) const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    return (INT)::GetScrollPos(m_Handle, barID);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixWindow::GetScrollRange(uixScrollBarID barID, INT& min, INT& max) const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    return ::GetScrollRange(m_Handle, barID, &min, &max);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixWindow::ScrollWindow(INT dx, INT dy, const RECT* rect, const RECT* clip)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    return ::ScrollWindow(m_Handle, dx, dy, rect, clip);
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixWindow::SetScrollPosition(uixScrollBarID barID, INT position, BOOL redraw)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    return ::SetScrollPos(m_Handle, barID, position, redraw);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixWindow::SetScrollRange(uixScrollBarID barID, INT min, INT max, BOOL redraw)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    return ::SetScrollRange(m_Handle, barID, min, max, redraw);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixWindow::SetScrollInfo(uixScrollBarID barID, const SCROLLINFO& info, BOOL redraw)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    return ::SetScrollInfo(m_Handle, barID, &info, redraw);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixWindow::GetScrollInfo(uixScrollBarID barID, SCROLLINFO& info) const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    return ::GetScrollInfo(m_Handle, barID, &info);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixWindow::GetScrollBarInfo(LONG objectID, SCROLLBARINFO& info) const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    return ::GetScrollBarInfo(m_Handle, objectID, &info);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixWindow::EnableScrollBar(UINT flags, UINT arrows)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    return ::EnableScrollBar(m_Handle, flags, arrows);
}
//----------------------------------------------------------------------------//
#pragma endregion
//----------------------------------------------------------------------------//
#pragma region Style manipulation
//----------------------------------------------------------------------------//
UIXINLINE DWORD uixWindow::GetStyle() const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    return (DWORD)::GetWindowLongPtr(m_Handle, GWL_STYLE);
}
//----------------------------------------------------------------------------//
UIXINLINE DWORD uixWindow::GetStyleEx() const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    return (DWORD)::GetWindowLongPtr(m_Handle, GWL_EXSTYLE);
}
//----------------------------------------------------------------------------//
UIXINLINE DWORD uixWindow::SetStyle(DWORD style)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    return (DWORD)::SetWindowLongPtr(m_Handle, GWL_STYLE, style);
}
//----------------------------------------------------------------------------//
UIXINLINE DWORD uixWindow::SetStyleEx(DWORD style)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    return (DWORD)::SetWindowLongPtr(m_Handle, GWL_EXSTYLE, style);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixWindow::UpdateStyle(DWORD remove, DWORD add, UINT flags)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    DWORD current = GetStyle();
    DWORD style = current;
    style &= ~remove;
    style |= add;

    if (style == current)
    {
        return FALSE;
    }

    SetStyle(style);

    if (flags != 0)
    {

    }

    return TRUE;
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixWindow::UpdateStyleEx(DWORD remove, DWORD add, UINT flags)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    DWORD current = GetStyleEx();
    DWORD style = current;
    style &= ~remove;
    style |= add;

    if (style == current)
    {
        return FALSE;
    }

    SetStyleEx(style);

    return TRUE;
}
//----------------------------------------------------------------------------//
#pragma endregion
//----------------------------------------------------------------------------//
#pragma region Window State
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixWindow::IsWindowEnabled() const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    return ::IsWindowEnabled(m_Handle);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixWindow::EnableWindow(BOOL value)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    return ::EnableWindow(m_Handle, value);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixWindow::Show(UINT command)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    return ::ShowWindow(m_Handle, command);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixWindow::Update()
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    return ::UpdateWindow(m_Handle);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixWindow::IsVisible() const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    return ::IsWindowVisible(m_Handle);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixWindow::GetWindowInfo(WINDOWINFO& info) const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    return ::GetWindowInfo(m_Handle, &info);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixWindow::GetTitleBarInfo(TITLEBARINFO& info) const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    return ::GetTitleBarInfo(m_Handle, &info);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixWindow::Close()
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    return ::CloseWindow(m_Handle);
}
//----------------------------------------------------------------------------//
UIXINLINE HMENU uixWindow::GetMenu() const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    return ::GetMenu(m_Handle);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixWindow::SetMenu(HMENU menu)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    return ::SetMenu(m_Handle, menu);
}
//----------------------------------------------------------------------------//
UIXINLINE HMENU uixWindow::GetSystemMenu(BOOL revert) const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    return ::GetSystemMenu(m_Handle, revert);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixWindow::IsIconic() const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    return ::IsIconic(m_Handle);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixWindow::IsZoomed() const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    return ::IsZoomed(m_Handle);
}
//----------------------------------------------------------------------------//
UIXINLINE UINT uixWindow::ArrangeIconicWindows()
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    return ::ArrangeIconicWindows(m_Handle);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixWindow::BringToTop()
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    return ::BringWindowToTop(m_Handle);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixWindow::LockWindowUpdate()
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    return ::LockWindowUpdate(m_Handle);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixWindow::UnlockWindowUpdate()
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    return ::LockWindowUpdate(0);
}
//----------------------------------------------------------------------------//
UIXINLINE UINT_PTR uixWindow::SetTimer(UINT_PTR eventID, UINT interval, TIMERPROC proc)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    return ::SetTimer(m_Handle, eventID, interval, proc);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixWindow::KillTimer(UINT_PTR eventID)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    return ::KillTimer(m_Handle, eventID);
}
//----------------------------------------------------------------------------//
UIXINLINE HICON uixWindow::SetIcon(HICON icon, BOOL bigIcon)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    return (HICON)SendMessage(WM_SETICON, (WPARAM)(bigIcon != FALSE ? 1 : 0), (LPARAM)icon);
}
//----------------------------------------------------------------------------//
UIXINLINE HICON uixWindow::GetIcon(BOOL bigIcon) const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    return (HICON)SendMessage(WM_GETICON, (WPARAM)(bigIcon != FALSE ? 1 : 0), 0);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixWindow::SetWindowContextHelpId(DWORD helpID)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    return ::SetWindowContextHelpId(m_Handle, helpID);
}
//----------------------------------------------------------------------------//
UIXINLINE DWORD uixWindow::GetWindowContextHelpId() const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    return ::GetWindowContextHelpId(m_Handle);
}
//----------------------------------------------------------------------------//
#pragma endregion
//----------------------------------------------------------------------------//
#pragma region Object Comparison
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixWindow::Equals(const uixWindow& window) const
{
    return m_Handle == window.m_Handle;
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixWindow::operator == (const uixWindow& window) const
{
    return Equals(window);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixWindow::operator != (const uixWindow& window) const
{
    return !Equals(window);
}
//----------------------------------------------------------------------------//
#pragma endregion
//----------------------------------------------------------------------------//
#pragma region Painting
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixWindow::InvalidateRect(const uixRect& rect, BOOL erase)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    return ::InvalidateRect(m_Handle, &rect, erase);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixWindow::Invalidate(BOOL erase)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    return ::InvalidateRect(m_Handle, NULLPTR, erase);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixWindow::InvalidateRgn(HRGN region, BOOL erase)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    return ::InvalidateRgn(m_Handle, region, erase);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixWindow::ValidateRect(const RECT& rect)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    return ::ValidateRect(m_Handle, &rect);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixWindow::ValidateRgn(HRGN region)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    return ::ValidateRgn(m_Handle, region);
}
//----------------------------------------------------------------------------//
UIXINLINE HDC uixWindow::BeginPaint(PAINTSTRUCT& ps)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    return ::BeginPaint(m_Handle, &ps);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixWindow::EndPaint(const PAINTSTRUCT& ps)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    return ::EndPaint(m_Handle, &ps);
}
//----------------------------------------------------------------------------//
UIXINLINE HDC uixWindow::GetDC() const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    return ::GetDC(m_Handle);
}
//----------------------------------------------------------------------------//
UIXINLINE HDC uixWindow::GetWindowDC() const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    return ::GetWindowDC(m_Handle);
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixWindow::ReleaseDC(HDC dc)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    return ::ReleaseDC(m_Handle, dc);
}
//----------------------------------------------------------------------------//
UIXINLINE void uixWindow::SetRedraw(BOOL redraw)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    SendMessage(WM_SETREDRAW, (LPARAM)redraw, 0);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixWindow::GetUpdateRect(RECT& rect, BOOL erase) const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    return ::GetUpdateRect(m_Handle, &rect, erase);
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixWindow::GetUpdateRgn(HRGN region, BOOL erase) const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    return ::GetUpdateRgn(m_Handle, region, erase);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixWindow::RedrawWindow(const RECT* update, HRGN region, UINT flags)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    return ::RedrawWindow(m_Handle, update, region, flags);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixWindow::DrawAnimatedRects(INT animation, const RECT& from, const RECT& to)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    return ::DrawAnimatedRects(m_Handle, animation, &from, &to);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixWindow::DrawCaption(HDC dc, const RECT& rect, UINT flags)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    return ::DrawCaption(m_Handle, dc, &rect, flags);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixWindow::AnimateWindow(DWORD time, DWORD flags)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    return ::AnimateWindow(m_Handle, time, flags);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixWindow::PrintWindow(HDC dc, UINT flags)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    return ::PrintWindow(m_Handle, dc, flags);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixWindow::SetLayeredAttributes(uixColor colorkey, BYTE alpha,
        uixLayeredWindowAttribute flags)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    return ::SetLayeredWindowAttributes(m_Handle, colorkey, alpha, flags);
}
//----------------------------------------------------------------------------//
#pragma endregion
//----------------------------------------------------------------------------//
#pragma region Message Manipulation
//----------------------------------------------------------------------------//
UIXINLINE LRESULT uixWindow::SendMessage(UINT message, WPARAM wParam, LPARAM lParam) const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    return ::SendMessage(m_Handle, message, wParam, lParam);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixWindow::PostMessage(UINT message, WPARAM wParam, LPARAM lParam) const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    return ::PostMessage(m_Handle, message, wParam, lParam);
}
//----------------------------------------------------------------------------//
#pragma endregion
//----------------------------------------------------------------------------//
#pragma region Window Text
//----------------------------------------------------------------------------//
UIXINLINE void uixWindow::SetText(const uixChar* text)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(IsWindow(m_Handle));

    ::SetWindowText(m_Handle, text);
}
//----------------------------------------------------------------------------//
UIXINLINE void uixWindow::SetText(const uixString& text)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    ::SetWindowText(m_Handle, text.c_str());
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixWindow::GetText(uixChar* text, INT maxLength) const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    return (INT)::GetWindowText(m_Handle, text, maxLength);
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixWindow::GetText(uixString& text, INT maxLength) const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    uixChar* pointer = const_cast<uixChar*>(text.c_str());
    return (INT)::GetWindowText(m_Handle, pointer, maxLength);
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixWindow::GetText(uixString& text) const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    text.resize(GetTextLength() + 1);
    uixChar* pointer = const_cast<uixChar*>(text.c_str());
    return (INT)::GetWindowText(m_Handle, pointer, (INT)text.length());
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixWindow::GetTextLength() const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    return (INT)::GetWindowTextLength(m_Handle);
}
//----------------------------------------------------------------------------//
#pragma endregion
//----------------------------------------------------------------------------//
#pragma region Size and position management
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixWindow::GetWindowRect(RECT& rect) const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    return ::GetWindowRect(m_Handle, &rect);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixWindow::GetClientRect(RECT& rect) const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    return ::GetClientRect(m_Handle, &rect);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixWindow::SetWindowRect(const RECT& rect)
{
    return SetWindowPos(rect);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixWindow::SetClientSize(const SIZE& size)
{
    return SetClientSize(size.cx, size.cy);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixWindow::SetClientSize(UINT width, UINT height)
{
    uixRect rc;
    GetWindowRect(rc);
    rc.Set(
        rc.left,
        rc.top,
        rc.left + width,
        rc.top + height);

    ::AdjustWindowRectEx(
        &rc,
        uixWindow::GetStyle(),
        GetMenu() != 0,
        uixWindow::GetStyleEx());

    return SetWindowRect(rc);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixWindow::SetWindowPos(INT x, INT y, INT width, INT height, UINT flags)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    return ::SetWindowPos(m_Handle, 0, x, y, width, height, flags);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixWindow::SetWindowPos(const uixPoint& position, const uixSize& size, UINT flags)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    return ::SetWindowPos(m_Handle, 0, position.x, position.y, size.cx, size.cy, flags);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixWindow::SetWindowPos(const uixRect& rect, UINT flags)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    return ::SetWindowPos(m_Handle, 0, rect.left, rect.top, rect.Width(), rect.Height(), flags);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixWindow::SetWindowPosZ(HWND insertAfter, INT x, INT y, INT width, INT height,
                                        UINT flags)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    return ::SetWindowPos(m_Handle, insertAfter, x, y, width, height, flags);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixWindow::SetWindowPosZ(HWND insertAfter, const uixPoint& position,
                                        const uixSize& size, UINT flags)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    return ::SetWindowPos(m_Handle, insertAfter, position.x, position.y, size.cx, size.cy, flags);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixWindow::SetWindowPosZ(HWND insertAfter, const uixRect& rect, UINT flags)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    return ::SetWindowPos(m_Handle, insertAfter, rect.left, rect.top, rect.Width(), rect.Height(),
                          flags);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixWindow::ScreenToClient(POINT& point) const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    return ::ScreenToClient(m_Handle, &point);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixWindow::ScreenToClient(RECT& rect) const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    BOOL result = ::ScreenToClient(m_Handle, ((POINT*)&rect) + 0);
    result &= ::ScreenToClient(m_Handle, ((POINT*)&rect) + 1);
    return result;
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixWindow::ClientToScreen(POINT& point) const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    return ::ClientToScreen(m_Handle, &point);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixWindow::ClientToScreen(RECT& rect) const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    BOOL result = ::ClientToScreen(m_Handle, ((POINT*)&rect) + 0);
    result &= ::ClientToScreen(m_Handle, ((POINT*)&rect) + 1);
    return result;
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixWindow::MapPoints(HWND target, POINT points[], UINT count) const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    return ::MapWindowPoints(m_Handle, target, points, count);
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixWindow::MapPoints(HWND target, uixPoint points[], UINT count) const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    return ::MapWindowPoints(m_Handle, target, points, count);
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixWindow::MapPoints(HWND target, RECT points[], UINT count) const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    return ::MapWindowPoints(m_Handle, target, (POINT*)points, 2 * count);
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixWindow::MapPoints(HWND target, uixRect points[], UINT count) const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    return ::MapWindowPoints(m_Handle, target, (POINT*)points, 2 * count);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixWindow::MoveWindow(INT left, INT top, INT width, INT height, BOOL repaint)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    return ::MoveWindow(m_Handle, left, top, width, height, repaint);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixWindow::MoveWindow(const POINT& position, const SIZE& size, BOOL repaint)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    return ::MoveWindow(m_Handle, position.x, position.y, size.cx, size.cy, repaint);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixWindow::MoveWindow(const RECT& rect, BOOL repaint)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    return ::MoveWindow(m_Handle, rect.left, rect.top, rect.right - rect.left, rect.bottom - rect.top,
                        repaint);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixWindow::GetWindowPlacement(WINDOWPLACEMENT& params) const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    return ::GetWindowPlacement(m_Handle, &params);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixWindow::SetWindowPlacement(const WINDOWPLACEMENT& params)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    return ::SetWindowPlacement(m_Handle, &params);
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixWindow::SetWindowRgn(HRGN region, BOOL redraw)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    return ::SetWindowRgn(m_Handle, region, redraw);
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixWindow::GetWindowRgn(HRGN region) const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    return ::GetWindowRgn(m_Handle, region);
}
//----------------------------------------------------------------------------//
#pragma endregion
#pragma region Event Handler methods
//----------------------------------------------------------------------------//
UIXINLINE void uixWindow::OnActivate(uixActivateEventArgs& e)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    CallDefaultProc();
}
//----------------------------------------------------------------------------//
UIXINLINE void uixWindow::OnActivateApp(uixActivateAppEventArgs& e)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    CallDefaultProc();
}
//----------------------------------------------------------------------------//
UIXINLINE void uixWindow::OnAppCommand(uixAppCommandEventArgs& e)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    CallDefaultProc();
}
//----------------------------------------------------------------------------//
UIXINLINE void uixWindow::OnAskClipboardFormatName(uixClipboardFormatNameEventArgs& e)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    CallDefaultProc();
}
//----------------------------------------------------------------------------//
UIXINLINE void uixWindow::OnCancelJournal(uixEventArgs& e)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    CallDefaultProc();
}
//----------------------------------------------------------------------------//
UIXINLINE void uixWindow::OnCancelMode(uixEventArgs& e)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    CallDefaultProc();
}
//----------------------------------------------------------------------------//
UIXINLINE void uixWindow::OnCaptureChanged(uixCaptureChangedEventArgs& e)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    CallDefaultProc();
}
//----------------------------------------------------------------------------//
UIXINLINE void uixWindow::OnChangeClipboardChain(uixChangeClipboardChainEventArgs& e)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    CallDefaultProc();
}
//----------------------------------------------------------------------------//
UIXINLINE void uixWindow::OnChangeUIState(uixChangeUiStateEventArgs& e)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    CallDefaultProc();
}
//----------------------------------------------------------------------------//
UIXINLINE void uixWindow::OnChar(uixKeyEventArgs& e)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    CallDefaultProc();
}
//----------------------------------------------------------------------------//
UIXINLINE void uixWindow::OnCharToItem(uixCharToItemEventArgs& e)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    e.Result = (INT)CallDefaultProc();
}
//----------------------------------------------------------------------------//
UIXINLINE void uixWindow::OnChildActivate(uixEventArgs& e)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    CallDefaultProc();
}
//----------------------------------------------------------------------------//
UIXINLINE void uixWindow::OnClear(uixEventArgs& e)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    CallDefaultProc();
}
//----------------------------------------------------------------------------//
UIXINLINE void uixWindow::OnClipboardUpdate(uixEventArgs& e)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    CallDefaultProc();
}
//----------------------------------------------------------------------------//
UIXINLINE void uixWindow::OnClose(uixCloseEventArgs& e)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    CallDefaultProc();
}
//----------------------------------------------------------------------------//
UIXINLINE void uixWindow::OnCompacting(uixCompactingEventArgs& e)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    CallDefaultProc();
}
//----------------------------------------------------------------------------//
UIXINLINE void uixWindow::OnCompareItem(uixCompareItemEventArgs& e)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    e.Result = (INT)CallDefaultProc();
}
//----------------------------------------------------------------------------//
UIXINLINE void uixWindow::OnContextMenu(uixContextMenuEventArgs& e)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    CallDefaultProc();
}
//----------------------------------------------------------------------------//
UIXINLINE void uixWindow::OnCopy(uixEventArgs& e)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    CallDefaultProc();
}
//----------------------------------------------------------------------------//
UIXINLINE void uixWindow::OnCopyData(uixCopyDataEventArgs& e)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    e.Result = (BOOL)CallDefaultProc();
}
//----------------------------------------------------------------------------//
UIXINLINE void uixWindow::OnCreate(uixCreateEventArgs& e)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    e.Result = (INT)CallDefaultProc();
}
//----------------------------------------------------------------------------//
UIXINLINE void uixWindow::OnCut(uixEventArgs& e)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    CallDefaultProc();
}
//----------------------------------------------------------------------------//
UIXINLINE void uixWindow::OnDeadChar(uixKeyEventArgs& e)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    CallDefaultProc();
}
//----------------------------------------------------------------------------//
UIXINLINE void uixWindow::OnDeleteItem(uixDeleteItemEventArgs& e)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    e.Result = (BOOL)CallDefaultProc();
}
//----------------------------------------------------------------------------//
UIXINLINE void uixWindow::OnDestroy(uixDestroyEventArgs& e)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    CallDefaultProc();
}
//----------------------------------------------------------------------------//
UIXINLINE void uixWindow::OnDestroyClipboard(uixEventArgs& e)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    CallDefaultProc();
}
//----------------------------------------------------------------------------//
UIXINLINE void uixWindow::OnDeviceChange(uixDeviceChangeEventArgs& e)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    CallDefaultProc();
}
//----------------------------------------------------------------------------//
UIXINLINE void uixWindow::OnDevModeChange(uixDevModeChangeEventArgs& e)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    CallDefaultProc();
}
//----------------------------------------------------------------------------//
UIXINLINE void uixWindow::OnDisplayChange(uixDisplayChangeEventArgs& e)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    CallDefaultProc();
}
//----------------------------------------------------------------------------//
UIXINLINE void uixWindow::OnDrawClipboard(uixEventArgs& e)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    CallDefaultProc();
}
//----------------------------------------------------------------------------//
UIXINLINE void uixWindow::OnDrawItem(uixDrawItemEventArgs& e)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    e.Result = (BOOL)CallDefaultProc();
}
//----------------------------------------------------------------------------//
UIXINLINE void uixWindow::OnDropFiles(uixDropFilesEventArgs& e)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    CallDefaultProc();
}
//----------------------------------------------------------------------------//
//----------------------------------------------------------------------------//
//----------------------------------------------------------------------------//
//----------------------------------------------------------------------------//
UIXINLINE void uixWindow::OnEnable(uixEnableEventArgs& e)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    CallDefaultProc();
}
//----------------------------------------------------------------------------//
UIXINLINE void uixWindow::OnEndSession(uixEndSessionEventArgs& e)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    CallDefaultProc();
}
//----------------------------------------------------------------------------//
UIXINLINE void uixWindow::OnEnterIdle(uixEnterIdleEventArgs& e)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    CallDefaultProc();
}
//----------------------------------------------------------------------------//
UIXINLINE void uixWindow::OnEnterMenuLoop(uixMenuLoopEventArgs& e)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    CallDefaultProc();
}
//----------------------------------------------------------------------------//
UIXINLINE void uixWindow::OnEnterSizeMove(uixEventArgs& e)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    CallDefaultProc();
}
//----------------------------------------------------------------------------//
UIXINLINE void uixWindow::OnEraseBackground(uixEraseBackgroundEventArgs& e)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    e.Result = (BOOL)CallDefaultProc();
}
//----------------------------------------------------------------------------//
UIXINLINE void uixWindow::OnExitMenuLoop(uixMenuLoopEventArgs& e)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    CallDefaultProc();
}
//----------------------------------------------------------------------------//
UIXINLINE void uixWindow::OnExitSizeMove(uixEventArgs& e)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    CallDefaultProc();
}
//----------------------------------------------------------------------------//
UIXINLINE void uixWindow::OnFontChange(uixEventArgs& e)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    CallDefaultProc();
}
//----------------------------------------------------------------------------//
UIXINLINE void uixWindow::OnHelp(uixHelpEventArgs& e)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    e.Result = (BOOL)CallDefaultProc();
}
//----------------------------------------------------------------------------//
UIXINLINE void uixWindow::OnHScroll(uixScrollEventArgs& e)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    CallDefaultProc();
}
//----------------------------------------------------------------------------//
UIXINLINE void uixWindow::OnInitDialog(uixInitDialogEventArgs& e)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    e.Result = (BOOL)CallDefaultProc();
}
//----------------------------------------------------------------------------//
UIXINLINE void uixWindow::OnKeyDown(uixKeyEventArgs& e)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    CallDefaultProc();
}
//----------------------------------------------------------------------------//
UIXINLINE void uixWindow::OnKeyUp(uixKeyEventArgs& e)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    CallDefaultProc();
}
//----------------------------------------------------------------------------//

//----------------------------------------------------------------------------//
UIXINLINE void uixWindow::OnMouseActivate(uixMouseActivateEventArgs& e)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    CallDefaultProc();
}
//----------------------------------------------------------------------------//
UIXINLINE void uixWindow::OnMouseDoubleClick(uixMouseEventArgs& e)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    CallDefaultProc();
}
//----------------------------------------------------------------------------//
UIXINLINE void uixWindow::OnMouseDown(uixMouseEventArgs& e)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    CallDefaultProc();
}
//----------------------------------------------------------------------------//
UIXINLINE void uixWindow::OnMouseUp(uixMouseEventArgs& e)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    CallDefaultProc();
}
//----------------------------------------------------------------------------//
UIXINLINE void uixWindow::OnMouseHover(uixMouseEventArgs& e)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    CallDefaultProc();
}
//----------------------------------------------------------------------------//
UIXINLINE void uixWindow::OnMouseMove(uixMouseEventArgs& e)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    CallDefaultProc();
}
//----------------------------------------------------------------------------//
UIXINLINE void uixWindow::OnMouseLeave(uixEventArgs& e)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    CallDefaultProc();
}
//----------------------------------------------------------------------------//
UIXINLINE void uixWindow::OnMouseWheel(uixMouseEventArgs& e)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    CallDefaultProc();
}
//----------------------------------------------------------------------------//
UIXINLINE void uixWindow::OnMouseHWheel(uixMouseEventArgs& e)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    CallDefaultProc();
}
//----------------------------------------------------------------------------//

//----------------------------------------------------------------------------//
UIXINLINE void uixWindow::OnMove(uixMoveEventArgs& e)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    CallDefaultProc();
}
//----------------------------------------------------------------------------//
UIXINLINE void uixWindow::OnMoving(uixBorderChangeEventArgs& e)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    e.Result = (BOOL)CallDefaultProc();
}
//----------------------------------------------------------------------------//

//----------------------------------------------------------------------------//
UIXINLINE void uixWindow::OnNcMouseLeave(uixEventArgs& e)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    CallDefaultProc();
}
//----------------------------------------------------------------------------//
/*UIXINLINE void uixWindow::OnNcMouseActivate(uixEventArgs& e)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    CallDefaultProc();
}*/
//----------------------------------------------------------------------------//
UIXINLINE void uixWindow::OnNcMouseHover(uixNcMouseEventArgs& e)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    CallDefaultProc();
}
//----------------------------------------------------------------------------//
UIXINLINE void uixWindow::OnNcMouseMove(uixNcMouseEventArgs& e)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    CallDefaultProc();
}
//----------------------------------------------------------------------------//
UIXINLINE void uixWindow::OnNcMouseDoubleClick(uixNcMouseEventArgs& e)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    CallDefaultProc();
}
//----------------------------------------------------------------------------//
UIXINLINE void uixWindow::OnNcMouseDown(uixNcMouseEventArgs& e)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    CallDefaultProc();
}
//----------------------------------------------------------------------------//
UIXINLINE void uixWindow::OnNcMouseUp(uixNcMouseEventArgs& e)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    CallDefaultProc();
}
//----------------------------------------------------------------------------//



//----------------------------------------------------------------------------//
UIXINLINE void uixWindow::OnPaint(uixPaintEventArgs& e)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    CallDefaultProc();
}
//----------------------------------------------------------------------------//
UIXINLINE void uixWindow::OnShowWindow(uixShowWindowEventArgs& e)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    CallDefaultProc();
}
//----------------------------------------------------------------------------//
UIXINLINE void uixWindow::OnSize(uixSizeEventArgs& e)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    CallDefaultProc();
}
//----------------------------------------------------------------------------//
UIXINLINE void uixWindow::OnSizeConstraints(uixSizeConstraintsEventArgs& e)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    CallDefaultProc();
}
//----------------------------------------------------------------------------//
UIXINLINE void uixWindow::OnSizing(uixBorderChangeEventArgs& e)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    e.Result = (BOOL)CallDefaultProc();
}
//----------------------------------------------------------------------------//
UIXINLINE void uixWindow::OnSysChar(uixKeyEventArgs& e)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    CallDefaultProc();
}
//----------------------------------------------------------------------------//
UIXINLINE void uixWindow::OnSysDeadChar(uixKeyEventArgs& e)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    CallDefaultProc();
}
//----------------------------------------------------------------------------//
UIXINLINE void uixWindow::OnSysKeyDown(uixKeyEventArgs& e)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    CallDefaultProc();
}
//----------------------------------------------------------------------------//
UIXINLINE void uixWindow::OnSysKeyUp(uixKeyEventArgs& e)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    CallDefaultProc();
}
//----------------------------------------------------------------------------//
UIXINLINE void uixWindow::OnTimer(uixTimerEventArgs& e)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    CallDefaultProc();
}
//----------------------------------------------------------------------------//
UIXINLINE void uixWindow::OnUniChar(uixKeyEventArgs& e)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    CallDefaultProc();
}
//----------------------------------------------------------------------------//
UIXINLINE void uixWindow::OnVScroll(uixScrollEventArgs& e)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    CallDefaultProc();
}
//----------------------------------------------------------------------------//
//----------------------------------------------------------------------------//
#pragma endregion
//----------------------------------------------------------------------------//
#pragma region Message Handler methods
#if 0
//----------------------------------------------------------------------------//
UIXINLINE void uixWindow::OnClipboardUpdate()
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    CallDefaultProc();
}
//----------------------------------------------------------------------------//
UIXINLINE void uixWindow::OnClose()
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    CallDefaultProc();
}
//----------------------------------------------------------------------------//
UIXINLINE void uixWindow::OnCompacting(UINT cpuTime)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    CallDefaultProc();
}
//----------------------------------------------------------------------------//
UIXINLINE int uixWindow::OnCompareItem(INT ctrlID, COMPAREITEMSTRUCT* params)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (int)CallDefaultProc();
}
//----------------------------------------------------------------------------//
UIXINLINE void uixWindow::OnContextMenu(HWND handle, uixPoint position)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    CallDefaultProc();
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixWindow::OnCopyData(HWND handle, COPYDATASTRUCT* params)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (BOOL)CallDefaultProc();
}
//----------------------------------------------------------------------------//
UIXINLINE int uixWindow::OnCreate(CREATESTRUCT* params)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (int)CallDefaultProc();
}
//----------------------------------------------------------------------------//
UIXINLINE HBRUSH uixWindow::OnCtlColor(HWND handle, HDC dc, UINT color)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (HBRUSH)CallDefaultProc();
}

//----------------------------------------------------------------------------//
UIXINLINE void uixWindow::OnDeleteItem(INT ctrlID, DELETEITEMSTRUCT* params)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    CallDefaultProc();
}
//----------------------------------------------------------------------------//
UIXINLINE void uixWindow::OnDestroy()
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    CallDefaultProc();
}
//----------------------------------------------------------------------------//
UIXINLINE void uixWindow::OnDestroyClipboard()
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    CallDefaultProc();
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixWindow::OnDeviceChange(UINT eventType, DWORD_PTR data)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (BOOL)CallDefaultProc();
}
//----------------------------------------------------------------------------//
UIXINLINE void uixWindow::OnDevModeChange(uixChar* deviceName)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    CallDefaultProc();
}
//----------------------------------------------------------------------------//
UIXINLINE void uixWindow::OnDrawClipboard()
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    CallDefaultProc();
}
//----------------------------------------------------------------------------//
UIXINLINE void uixWindow::OnDrawItem(INT ctrlID, DRAWITEMSTRUCT* params)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    CallDefaultProc();
}
//----------------------------------------------------------------------------//
UIXINLINE void uixWindow::OnDropFiles(HDROP handle)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    CallDefaultProc();
}
//----------------------------------------------------------------------------//
UIXINLINE void uixWindow::OnColorizationColorChanged(DWORD color, BOOL opacity)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    CallDefaultProc();
}
//----------------------------------------------------------------------------//
UIXINLINE void uixWindow::OnCompositionChanged()
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    CallDefaultProc();
}
//----------------------------------------------------------------------------//
UIXINLINE void uixWindow::OnNcRenderingChanged(BOOL isRendering)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    CallDefaultProc();
}
//----------------------------------------------------------------------------//
UIXINLINE void uixWindow::OnWindowMaximizedChanged(BOOL isMaximized)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    CallDefaultProc();
}
//----------------------------------------------------------------------------//
UIXINLINE void uixWindow::OnEnable(BOOL enable)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    CallDefaultProc();
}
//----------------------------------------------------------------------------//
UIXINLINE void uixWindow::OnEndSession(BOOL ending, UINT reason)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    CallDefaultProc();
}
//----------------------------------------------------------------------------//
UIXINLINE void uixWindow::OnEnterIdle(UINT reason, HWND handle)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    CallDefaultProc();
}
//----------------------------------------------------------------------------//
UIXINLINE void uixWindow::OnEnterSizeMove()
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    CallDefaultProc();
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixWindow::OnEraseBackground(HDC dc)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (BOOL)CallDefaultProc();
}
//----------------------------------------------------------------------------//
UIXINLINE void uixWindow::OnExitSizeMove()
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    CallDefaultProc();
}
//----------------------------------------------------------------------------//
UIXINLINE void uixWindow::OnFontChange()
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    CallDefaultProc();
}
//----------------------------------------------------------------------------//
UIXINLINE UINT uixWindow::OnGetDlgCode()
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (UINT)CallDefaultProc();
}
//----------------------------------------------------------------------------//
UIXINLINE void uixWindow::OnGetMinMaxInfo(MINMAXINFO* params)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    CallDefaultProc();
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixWindow::OnHelpInfo(HELPINFO* params)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (BOOL)CallDefaultProc();
}
//----------------------------------------------------------------------------//
UIXINLINE void uixWindow::OnHotKey(UINT hotKeyID, UINT key1, UINT key2)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    CallDefaultProc();
}
//----------------------------------------------------------------------------//
UIXINLINE void uixWindow::OnHScroll(HWND scrollBar, UINT code, UINT pos)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    CallDefaultProc();
}
//----------------------------------------------------------------------------//
UIXINLINE void uixWindow::OnHScrollClipboard(HWND handle, UINT code, UINT pos)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    CallDefaultProc();
}
//----------------------------------------------------------------------------//
UIXINLINE void uixWindow::OnIconEraseBackground(HDC dc)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    CallDefaultProc();
}
//----------------------------------------------------------------------------//
UIXINLINE void uixWindow::OnInitMenu(HMENU menu)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    CallDefaultProc();
}
//----------------------------------------------------------------------------//
UIXINLINE void uixWindow::OnInitMenuPopup(HMENU popupMenu, UINT index, BOOL systemMenu)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    CallDefaultProc();
}
//----------------------------------------------------------------------------//
UIXINLINE void uixWindow::OnInputDeviceChange(USHORT flags)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    CallDefaultProc();
}
//----------------------------------------------------------------------------//
UIXINLINE void uixWindow::OnInputLangChange(UINT charset, UINT localeID)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    CallDefaultProc();
}
//----------------------------------------------------------------------------//
UIXINLINE void uixWindow::OnInputLangChangeRequest(UINT flags, UINT localeID)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    CallDefaultProc();
}
//----------------------------------------------------------------------------//
UIXINLINE void uixWindow::OnKillFocus(HWND newWindow)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    CallDefaultProc();
}
//----------------------------------------------------------------------------//
UIXINLINE void uixWindow::OnLButtonDblClk(UINT flags, uixPoint point)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    CallDefaultProc();
}
//----------------------------------------------------------------------------//
UIXINLINE void uixWindow::OnLButtonDown(UINT flags, uixPoint point)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    CallDefaultProc();
}
//----------------------------------------------------------------------------//
UIXINLINE void uixWindow::OnLButtonUp(UINT flags, uixPoint point)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    CallDefaultProc();
}
//----------------------------------------------------------------------------//
UIXINLINE void uixWindow::OnMButtonDblClk(UINT flags, uixPoint point)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    CallDefaultProc();
}
//----------------------------------------------------------------------------//
UIXINLINE void uixWindow::OnMButtonDown(UINT flags, uixPoint point)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    CallDefaultProc();
}
//----------------------------------------------------------------------------//
UIXINLINE void uixWindow::OnMButtonUp(UINT flags, uixPoint point)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    CallDefaultProc();
}
//----------------------------------------------------------------------------//
UIXINLINE void uixWindow::OnRButtonDblClk(UINT flags, uixPoint point)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    CallDefaultProc();
}
//----------------------------------------------------------------------------//
UIXINLINE void uixWindow::OnRButtonDown(UINT flags, uixPoint point)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    CallDefaultProc();
}
//----------------------------------------------------------------------------//
UIXINLINE void uixWindow::OnRButtonUp(UINT flags, uixPoint point)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    CallDefaultProc();
}
//----------------------------------------------------------------------------//
UIXINLINE void uixWindow::OnXButtonDblClk(UINT flags, uixPoint point)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    CallDefaultProc();
}
//----------------------------------------------------------------------------//
UIXINLINE void uixWindow::OnXButtonDown(UINT flags, uixPoint point)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    CallDefaultProc();
}
//----------------------------------------------------------------------------//
UIXINLINE void uixWindow::OnXButtonUp(UINT flags, uixPoint point)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    CallDefaultProc();
}
//----------------------------------------------------------------------------//
UIXINLINE void uixWindow::OnRawInput(UINT code, HRAWINPUT hri)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    CallDefaultProc();
}
//----------------------------------------------------------------------------//
UIXINLINE void uixWindow::OnMeasureItem(INT ctrlID, MEASUREITEMSTRUCT* params)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    CallDefaultProc();
}
//----------------------------------------------------------------------------//
UIXINLINE void uixWindow::OnMenuChar(UINT uChar, UINT flags, UINT menu)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    CallDefaultProc();
}
//----------------------------------------------------------------------------//
UIXINLINE UINT uixWindow::OnMenuDrag(UINT pos, HMENU menu)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (UINT)CallDefaultProc();
}
//----------------------------------------------------------------------------//
UIXINLINE UINT uixWindow::OnMenuGetObject(MENUGETOBJECTINFO* params)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (UINT)CallDefaultProc();
}
//----------------------------------------------------------------------------//
UIXINLINE void uixWindow::OnMenuSelect(UINT itemID, UINT flags, HMENU systemMenu)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    CallDefaultProc();
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixWindow::OnMouseActivate(HWND desktop, UINT hitTest, UINT message)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (INT)CallDefaultProc();
}
//----------------------------------------------------------------------------//
UIXINLINE void uixWindow::OnMouseHover(UINT flags, uixPoint point)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    CallDefaultProc();
}
//----------------------------------------------------------------------------//
UIXINLINE void uixWindow::OnMouseHWheel(UINT flags, SHORT delta, uixPoint point)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    CallDefaultProc();
}
//----------------------------------------------------------------------------//
UIXINLINE void uixWindow::OnMouseLeave()
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    CallDefaultProc();
}
//----------------------------------------------------------------------------//
UIXINLINE void uixWindow::OnMouseMove(UINT flags, uixPoint point)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    CallDefaultProc();
}
//----------------------------------------------------------------------------//
UIXINLINE void uixWindow::OnMouseWheel(UINT flags, SHORT delta, uixPoint point)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    CallDefaultProc();
}
//----------------------------------------------------------------------------//
UIXINLINE void uixWindow::OnMove(INT x, INT y)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    CallDefaultProc();
}
//----------------------------------------------------------------------------//
UIXINLINE void uixWindow::OnMoving(UINT side, uixRect* rect)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    CallDefaultProc();
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixWindow::OnNcActivate(BOOL active)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (BOOL)CallDefaultProc();
}
//----------------------------------------------------------------------------//
UIXINLINE void uixWindow::OnNcCalcSize(BOOL calcValidRects, NCCALCSIZE_PARAMS* params)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    CallDefaultProc();
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixWindow::OnNcCreate(CREATESTRUCT* params)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (BOOL)CallDefaultProc();
}
//----------------------------------------------------------------------------//
UIXINLINE void uixWindow::OnNcDestroy()
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    CallDefaultProc();
}
//----------------------------------------------------------------------------//
UIXINLINE LRESULT uixWindow::OnNcHitTest(uixPoint point)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (LRESULT)CallDefaultProc();
}
//----------------------------------------------------------------------------//
UIXINLINE void uixWindow::OnNcLButtonDblClk(UINT hitTest, uixPoint point)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    CallDefaultProc();
}
//----------------------------------------------------------------------------//
UIXINLINE void uixWindow::OnNcLButtonDown(UINT hitTest, uixPoint point)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    CallDefaultProc();
}
//----------------------------------------------------------------------------//
UIXINLINE void uixWindow::OnNcLButtonUp(UINT hitTest, uixPoint point)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    CallDefaultProc();
}
//----------------------------------------------------------------------------//
UIXINLINE void uixWindow::OnNcMButtonDblClk(UINT hitTest, uixPoint point)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    CallDefaultProc();
}
//----------------------------------------------------------------------------//
UIXINLINE void uixWindow::OnNcMButtonDown(UINT hitTest, uixPoint point)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    CallDefaultProc();
}
//----------------------------------------------------------------------------//
UIXINLINE void uixWindow::OnNcMButtonUp(UINT hitTest, uixPoint point)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    CallDefaultProc();
}
//----------------------------------------------------------------------------//
UIXINLINE void uixWindow::OnNcRButtonDblClk(UINT hitTest, uixPoint point)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    CallDefaultProc();
}
//----------------------------------------------------------------------------//
UIXINLINE void uixWindow::OnNcRButtonDown(UINT hitTest, uixPoint point)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    CallDefaultProc();
}
//----------------------------------------------------------------------------//
UIXINLINE void uixWindow::OnNcRButtonUp(UINT hitTest, uixPoint point)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    CallDefaultProc();
}
//----------------------------------------------------------------------------//
UIXINLINE void uixWindow::OnNcXButtonDblClk(UINT hitTest, uixPoint point)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    CallDefaultProc();
}
//----------------------------------------------------------------------------//
UIXINLINE void uixWindow::OnNcXButtonDown(UINT hitTest, uixPoint point)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    CallDefaultProc();
}
//----------------------------------------------------------------------------//
UIXINLINE void uixWindow::OnNcXButtonUp(UINT hitTest, uixPoint point)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    CallDefaultProc();
}
//----------------------------------------------------------------------------//
UIXINLINE void uixWindow::OnNcMouseHover(UINT hitTest, uixPoint point)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    CallDefaultProc();
}
//----------------------------------------------------------------------------//
UIXINLINE void uixWindow::OnNcMouseLeave()
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    CallDefaultProc();
}
//----------------------------------------------------------------------------//
UIXINLINE void uixWindow::OnNcMouseMove(UINT hitTest, uixPoint point)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    CallDefaultProc();
}
//----------------------------------------------------------------------------//
UIXINLINE void uixWindow::OnNcPaint()
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    CallDefaultProc();
}
//----------------------------------------------------------------------------//
UIXINLINE void uixWindow::OnNextMenu(UINT key, MDINEXTMENU* params)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    CallDefaultProc();
}
//----------------------------------------------------------------------------//
UIXINLINE UINT uixWindow::OnNotifyFormat(HWND window, UINT command)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (UINT)CallDefaultProc();
}
//----------------------------------------------------------------------------//
UIXINLINE void uixWindow::OnPaint()
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    CallDefaultProc();
}
//----------------------------------------------------------------------------//
UIXINLINE void uixWindow::OnPaintClipboard(HWND appWindow, HGLOBAL paintStruct)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    CallDefaultProc();
}
//----------------------------------------------------------------------------//
UIXINLINE void uixWindow::OnPaletteChanged(HWND focusWindow)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    CallDefaultProc();
}
//----------------------------------------------------------------------------//
UIXINLINE void uixWindow::OnPaletteChanging(HWND realizeWindow)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    CallDefaultProc();
}
//----------------------------------------------------------------------------//
UIXINLINE void uixWindow::OnParentNotify(UINT message, LPARAM lParam)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    CallDefaultProc();
}
//----------------------------------------------------------------------------//
UIXINLINE void uixWindow::OnPowerBroadcast(UINT eventID, UINT eventData)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    CallDefaultProc();
}
//----------------------------------------------------------------------------//
UIXINLINE HCURSOR uixWindow::OnQueryDragIcon()
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (HCURSOR)CallDefaultProc();
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixWindow::OnQueryEndSession(UINT reason)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (BOOL)CallDefaultProc();
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixWindow::OnQueryNewPalette()
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (BOOL)CallDefaultProc();
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixWindow::OnQueryOpen()
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (BOOL)CallDefaultProc();
}
//----------------------------------------------------------------------------//
UIXINLINE void uixWindow::OnRenderAllFormats()
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    CallDefaultProc();
}
//----------------------------------------------------------------------------//
UIXINLINE void uixWindow::OnRenderFormat(UINT format)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    CallDefaultProc();
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixWindow::OnSetCursor(HWND window, UINT hitTest, UINT message)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (BOOL)CallDefaultProc();
}
//----------------------------------------------------------------------------//
UIXINLINE void uixWindow::OnSetFocus(HWND previous)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    CallDefaultProc();
}
//----------------------------------------------------------------------------//
UIXINLINE void uixWindow::OnSettingChange(UINT flags, const uixChar* section)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    CallDefaultProc();
}
//----------------------------------------------------------------------------//
UIXINLINE void uixWindow::OnShowWindow(BOOL show, UINT status)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    CallDefaultProc();
}
//----------------------------------------------------------------------------//
UIXINLINE void uixWindow::OnSizeClipboard(HWND clipboardAppWindow, HGLOBAL rect)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    CallDefaultProc();
}
//----------------------------------------------------------------------------//
UIXINLINE void uixWindow::OnSizing(UINT side, uixRect* rect)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    CallDefaultProc();
}
//----------------------------------------------------------------------------//
UIXINLINE void uixWindow::OnSpoolerStatus(UINT status, UINT jobs)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    CallDefaultProc();
}
//----------------------------------------------------------------------------//
UIXINLINE void uixWindow::OnStyleChanged(INT styleType, STYLESTRUCT* params)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    CallDefaultProc();
}
//----------------------------------------------------------------------------//
UIXINLINE void uixWindow::OnStyleChanging(INT styleType, STYLESTRUCT* params)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    CallDefaultProc();
}
//----------------------------------------------------------------------------//
UIXINLINE void uixWindow::OnSysColorChange()
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    CallDefaultProc();
}
//----------------------------------------------------------------------------//
UIXINLINE void uixWindow::OnSysCommand(UINT id, LPARAM lParam)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    CallDefaultProc();
}
//----------------------------------------------------------------------------//
UIXINLINE void uixWindow::OnTCard(UINT action, DWORD data)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    CallDefaultProc();
}
//----------------------------------------------------------------------------//
UIXINLINE void uixWindow::OnTimeChange()
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    CallDefaultProc();
}
//----------------------------------------------------------------------------//
UIXINLINE void uixWindow::OnTimer(UINT_PTR eventID)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    CallDefaultProc();
}
//----------------------------------------------------------------------------//
UIXINLINE void uixWindow::OnUnInitMenuPopup(HMENU menu, UINT flags)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    CallDefaultProc();
}
//----------------------------------------------------------------------------//
UIXINLINE void uixWindow::OnUserChanged()
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    CallDefaultProc();
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixWindow::OnVKeyToItem(UINT key, HWND listBox, UINT index)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (INT)CallDefaultProc();
}
//----------------------------------------------------------------------------//
UIXINLINE void uixWindow::OnVScroll(HWND scrollBar, UINT code, UINT pos)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    CallDefaultProc();
}
//----------------------------------------------------------------------------//
UIXINLINE void uixWindow::OnVScrollClipboard(HWND clipboardAppWindow, UINT code, UINT pos)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    CallDefaultProc();
}
//----------------------------------------------------------------------------//
UIXINLINE void uixWindow::OnWindowPosChanged(WINDOWPOS* params)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    CallDefaultProc();
}
//----------------------------------------------------------------------------//
UIXINLINE void uixWindow::OnWindowPosChanging(WINDOWPOS* params)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    CallDefaultProc();
}
//----------------------------------------------------------------------------//
UIXINLINE void uixWindow::OnWinIniChange(const uixChar* section)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    CallDefaultProc();
}
//----------------------------------------------------------------------------//
UIXINLINE void uixWindow::OnSessionChange(UINT sessionState, UINT id)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    CallDefaultProc();
}
#endif
//----------------------------------------------------------------------------//
#pragma endregion
//----------------------------------------------------------------------------//
}
//----------------------------------------------------------------------------//
#endif /* _UIX_WINDOW_INL__ */