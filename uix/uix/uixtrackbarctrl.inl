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
#ifndef _UIX_TRACKBARCTRL_INL__
#define _UIX_TRACKBARCTRL_INL__
//----------------------------------------------------------------------------//
#include "uixtrackbarctrl.inl"
//----------------------------------------------------------------------------//
namespace UIX
{
//----------------------------------------------------------------------------//
UIXINLINE void uixTrackBarCtrl::ClearSelection(BOOL redraw)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    SendMessage(TBM_CLEARSEL, redraw, 0);
}
//----------------------------------------------------------------------------//
UIXINLINE void uixTrackBarCtrl::ClearTics(BOOL redraw)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    SendMessage(TBM_CLEARTICS, redraw, 0);
}
//----------------------------------------------------------------------------//
UIXINLINE HWND uixTrackBarCtrl::GetBuddyWindow(BOOL left) const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (HWND)SendMessage(TBM_GETBUDDY, left, 0);
}
//----------------------------------------------------------------------------//
UIXINLINE void uixTrackBarCtrl::GetChannelRect(RECT& rect) const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    SendMessage(TBM_GETCHANNELRECT, 0, (LPARAM)&rect);
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixTrackBarCtrl::GetLineSize() const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (INT)SendMessage(TBM_GETLINESIZE, 0, 0);
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixTrackBarCtrl::GetNumTics() const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (INT)SendMessage(TBM_GETNUMTICS, 0, 0);
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixTrackBarCtrl::GetPageSize() const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (INT)SendMessage(TBM_GETPAGESIZE, 0, 0);
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixTrackBarCtrl::GetPosition() const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (INT)SendMessage(TBM_GETPOS, 0, 0);
}
//----------------------------------------------------------------------------//
UIXINLINE DWORD* uixTrackBarCtrl::GetTics() const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (DWORD*)SendMessage(TBM_GETPTICS, 0, 0);
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixTrackBarCtrl::GetRangeMax() const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (INT)SendMessage(TBM_GETRANGEMAX, 0, 0);
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixTrackBarCtrl::GetRangeMin() const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (INT)SendMessage(TBM_GETRANGEMIN, 0, 0);
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixTrackBarCtrl::GetSelectionEnd() const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (INT)SendMessage(TBM_GETSELEND, 0, 0);
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixTrackBarCtrl::GetSelectionStart() const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (INT)SendMessage(TBM_GETSELSTART, 0, 0);
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixTrackBarCtrl::GetThumbLength() const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (INT)SendMessage(TBM_GETTHUMBLENGTH, 0, 0);
}
//----------------------------------------------------------------------------//
UIXINLINE void uixTrackBarCtrl::GetThumbRect(RECT& rect) const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    SendMessage(TBM_GETTHUMBRECT, 0, (LPARAM)&rect);
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixTrackBarCtrl::GetTic(INT ticID) const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (INT)SendMessage(TBM_GETTIC, ticID, 0);
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixTrackBarCtrl::GetTicPosition(INT ticID) const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (INT)SendMessage(TBM_GETTICPOS, ticID, 0);
}
//----------------------------------------------------------------------------//
UIXINLINE HWND uixTrackBarCtrl::GetToolTips() const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (HWND)SendMessage(TBM_GETTOOLTIPS, 0, 0);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixTrackBarCtrl::GetUnicodeFormat() const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (BOOL)SendMessage(TBM_GETUNICODEFORMAT, 0, 0);
}
//----------------------------------------------------------------------------//
UIXINLINE HWND uixTrackBarCtrl::SetBuddy(BOOL left, HWND buddy)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (HWND)SendMessage(TBM_SETBUDDY, left, (LPARAM)buddy);
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixTrackBarCtrl::SetLineSize(INT size)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (INT)SendMessage(TBM_SETLINESIZE, 0, size);
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixTrackBarCtrl::SetPageSize(INT size)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (INT)SendMessage(TBM_SETPAGESIZE, 0, size);
}
//----------------------------------------------------------------------------//
UIXINLINE void uixTrackBarCtrl::SetPosition(INT position, BOOL redraw)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    SendMessage(TBM_SETPOS, redraw, position);
}
//----------------------------------------------------------------------------//
UIXINLINE void uixTrackBarCtrl::SetPositionNotify(INT position)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    SendMessage(TBM_SETPOSNOTIFY, 0, position);
}
//----------------------------------------------------------------------------//
UIXINLINE void uixTrackBarCtrl::SetRange(INT low, INT high, BOOL redraw)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    SendMessage(TBM_SETRANGE, redraw, MAKELPARAM(low, high));
}
//----------------------------------------------------------------------------//
UIXINLINE void uixTrackBarCtrl::SetRangeMax(INT max, BOOL redraw)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    SendMessage(TBM_SETRANGEMAX, redraw, max);
}
//----------------------------------------------------------------------------//
UIXINLINE void uixTrackBarCtrl::SetRangeMin(INT min, BOOL redraw)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    SendMessage(TBM_SETRANGEMIN, redraw, min);
}
//----------------------------------------------------------------------------//
UIXINLINE void uixTrackBarCtrl::SetSelection(INT start, INT end, BOOL redraw)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    SendMessage(TBM_SETSEL, redraw, MAKELPARAM(start, end));
}
//----------------------------------------------------------------------------//
UIXINLINE void uixTrackBarCtrl::SetSelectionEnd(INT end, BOOL redraw)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    SendMessage(TBM_SETSELEND, redraw, end);
}
//----------------------------------------------------------------------------//
UIXINLINE void uixTrackBarCtrl::SetSelectionStart(INT start, BOOL redraw)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    SendMessage(TBM_SETSELSTART, redraw, start);
}
//----------------------------------------------------------------------------//
UIXINLINE void uixTrackBarCtrl::SetThumbLength(INT length)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    SendMessage(TBM_SETTHUMBLENGTH, length, 0);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixTrackBarCtrl::SetTic(INT ticPosition)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (BOOL)SendMessage(TBM_SETTIC, 0, ticPosition);
}
//----------------------------------------------------------------------------//
UIXINLINE void uixTrackBarCtrl::SetTicFrequency(INT frequency)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    SendMessage(TBM_SETTICFREQ, frequency, 0);
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixTrackBarCtrl::SetTipSide(INT tipSide)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (INT)SendMessage(TBM_SETTIPSIDE, tipSide, 0);
}
//----------------------------------------------------------------------------//
UIXINLINE void uixTrackBarCtrl::SetToolTips(HWND toolTip)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    SendMessage(TBM_SETTOOLTIPS, (WPARAM)toolTip, 0);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixTrackBarCtrl::SetUnicodeFormat(BOOL unicode)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (BOOL)SendMessage(TBM_SETUNICODEFORMAT, unicode, 0);
}
//----------------------------------------------------------------------------//
}
//----------------------------------------------------------------------------//
#endif /* _UIX_TRACKBARCTRL_INL__ */