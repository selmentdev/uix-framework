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
#ifndef _UIX_MONTHCALENDAR_INL__
#define _UIX_MONTHCALENDAR_INL__
//----------------------------------------------------------------------------//
#include "uixmonthcalendarctrl.h"
//----------------------------------------------------------------------------//
namespace UIX
{
//----------------------------------------------------------------------------//
UIXINLINE DWORD uixMonthCalendarCtrl::GetCalendarBorder() const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return MonthCal_GetCalendarBorder(m_Handle);
}
//----------------------------------------------------------------------------//
UIXINLINE DWORD uixMonthCalendarCtrl::GetCalendarCount() const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return MonthCal_GetCalendarCount(m_Handle);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixMonthCalendarCtrl::GetCalendarGridInfo(MCGRIDINFO& grid) const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return MonthCal_GetCalendarGridInfo(m_Handle, &grid);
}
//----------------------------------------------------------------------------//
UIXINLINE CALID uixMonthCalendarCtrl::GetCALID() const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return MonthCal_GetCALID(m_Handle);
}
//----------------------------------------------------------------------------//
UIXINLINE uixColor uixMonthCalendarCtrl::GetColor(uixMonthCalendarColor color) const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (uixColorRef)MonthCal_GetColor(m_Handle, color);
}
//----------------------------------------------------------------------------//
UIXINLINE uixMonthCalendarView uixMonthCalendarCtrl::GetCurrentView() const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (uixMonthCalendarView)MonthCal_GetCurrentView(m_Handle);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixMonthCalendarCtrl::GetCurrentSelection(SYSTEMTIME& time) const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return MonthCal_GetCurSel(m_Handle, &time);
}
//----------------------------------------------------------------------------//
UIXINLINE DWORD uixMonthCalendarCtrl::GetFirstDayOfWeek() const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return MonthCal_GetFirstDayOfWeek(m_Handle);
}
//----------------------------------------------------------------------------//
UIXINLINE DWORD uixMonthCalendarCtrl::GetMaxSelectionCount() const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return MonthCal_GetMaxSelCount(m_Handle);
}
//----------------------------------------------------------------------------//
UIXINLINE DWORD uixMonthCalendarCtrl::GetMaxTodayWidth() const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return MonthCal_GetMaxTodayWidth(m_Handle);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixMonthCalendarCtrl::GetMinRequiredRect(RECT& rect) const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (BOOL)MonthCal_GetMinReqRect(m_Handle, &rect);
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixMonthCalendarCtrl::GetMonthDelta() const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return MonthCal_GetMonthDelta(m_Handle);
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixMonthCalendarCtrl::GetMonthRange(DWORD flag, SYSTEMTIME time[2]) const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return MonthCal_GetMonthRange(m_Handle, flag, time);
}
//----------------------------------------------------------------------------//
UIXINLINE DWORD uixMonthCalendarCtrl::GetRange(SYSTEMTIME time[2]) const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return MonthCal_GetRange(m_Handle, time);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixMonthCalendarCtrl::GetSelectionRange(SYSTEMTIME time[2]) const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (BOOL)MonthCal_GetSelRange(m_Handle, time);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixMonthCalendarCtrl::GetToday(SYSTEMTIME& time) const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return MonthCal_GetToday(m_Handle, &time);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixMonthCalendarCtrl::GetUnicodeFormat() const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return MonthCal_GetUnicodeFormat(m_Handle);
}
//----------------------------------------------------------------------------//
UIXINLINE DWORD uixMonthCalendarCtrl::HitTest(MCHITTESTINFO& hitTest) const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (DWORD)MonthCal_HitTest(m_Handle, &hitTest);
}
//----------------------------------------------------------------------------//
UIXINLINE void uixMonthCalendarCtrl::SetCalendarBorder(INT border, BOOL set)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    MonthCal_SetCalendarBorder(m_Handle, set, border);
}
//----------------------------------------------------------------------------//
UIXINLINE void uixMonthCalendarCtrl::SetCALID(CALID calid)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    MonthCal_SetCALID(m_Handle, calid);
}
//----------------------------------------------------------------------------//
UIXINLINE uixColor uixMonthCalendarCtrl::SetColor(uixMonthCalendarColor index, uixColor color)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (uixColorRef)MonthCal_SetColor(m_Handle, index, color);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixMonthCalendarCtrl::SetCurrentView(uixMonthCalendarView view)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return MonthCal_SetCurrentView(m_Handle, view);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixMonthCalendarCtrl::SetCurrentSelection(const SYSTEMTIME& time)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return MonthCal_SetCurSel(m_Handle, &time);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixMonthCalendarCtrl::SetDayState(MONTHDAYSTATE dayStateElements[], INT months)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (BOOL)MonthCal_SetDayState(m_Handle, months, dayStateElements);
}
//----------------------------------------------------------------------------//
UIXINLINE DWORD uixMonthCalendarCtrl::SetFirstDayOfWeek(INT dayID)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (DWORD)MonthCal_SetFirstDayOfWeek(m_Handle, dayID);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixMonthCalendarCtrl::SetMaxSelectionCount(UINT max)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return MonthCal_SetMaxSelCount(m_Handle, max);
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixMonthCalendarCtrl::SetMonthDelta(INT delta)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return MonthCal_SetMonthDelta(m_Handle, delta);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixMonthCalendarCtrl::SetRange(const SYSTEMTIME time[2])
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return MonthCal_SetRange(m_Handle, GDTR_MAX | GDTR_MIN, time);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixMonthCalendarCtrl::SetSelectionRange(const SYSTEMTIME time[2])
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (BOOL)MonthCal_SetSelRange(m_Handle, time);
}
//----------------------------------------------------------------------------//
UIXINLINE void uixMonthCalendarCtrl::SetToday(const SYSTEMTIME* time)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    MonthCal_SetToday(m_Handle, time);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixMonthCalendarCtrl::SetUnicodeFormat(BOOL unicode)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return MonthCal_SetUnicodeFormat(m_Handle, unicode);
}
//----------------------------------------------------------------------------//
UIXINLINE LRESULT uixMonthCalendarCtrl::SizeRectToMin(RECT& rect) const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return MonthCal_SizeRectToMin(m_Handle, &rect);
}
//----------------------------------------------------------------------------//
}
//----------------------------------------------------------------------------//
#endif /* _UIX_MONTHCALENDAR_INL__ */