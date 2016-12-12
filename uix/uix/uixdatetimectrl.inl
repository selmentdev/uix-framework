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
#ifndef _UIX_DATETIMECTRL_INL__
#define _UIX_DATETIMECTRL_INL__
//----------------------------------------------------------------------------//
#include "uixdatetimectrl.h"
//----------------------------------------------------------------------------//
namespace UIX
{
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixDateTimeCtrl::SetCalendarFormat(const uixChar* format)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (BOOL)DateTime_SetFormat(m_Handle, format);
}
//----------------------------------------------------------------------------//
UIXINLINE HWND uixDateTimeCtrl::GetCalendarHandle() const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (HWND)DateTime_GetMonthCal(m_Handle);
}
//----------------------------------------------------------------------------//
UIXINLINE uixColor uixDateTimeCtrl::GetCalendarColor(uixMonthCalendarColor colorID) const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (uixColorRef)DateTime_GetMonthCalColor(m_Handle, colorID);
}
//----------------------------------------------------------------------------//
UIXINLINE uixColor uixDateTimeCtrl::SetCalendarColor(uixMonthCalendarColor colorID, uixColor color)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (uixColorRef)DateTime_SetMonthCalColor(m_Handle, colorID, color);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixDateTimeCtrl::GetCalendarTime(SYSTEMTIME& time) const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (BOOL)DateTime_GetSystemtime(m_Handle, &time) != GDT_VALID;
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixDateTimeCtrl::SetCalendarTime(BOOL valid, SYSTEMTIME& time)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (BOOL)DateTime_SetSystemtime(m_Handle, valid ? GDT_VALID : GDT_NONE, &time);
}
//----------------------------------------------------------------------------//
UIXINLINE HFONT uixDateTimeCtrl::GetCalendarFont() const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (HFONT)DateTime_GetMonthCalFont(m_Handle);
}
//----------------------------------------------------------------------------//
UIXINLINE void uixDateTimeCtrl::SetCalendarFont(HFONT handle, BOOL redraw)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    DateTime_SetMonthCalFont(m_Handle, handle, redraw);
}
//----------------------------------------------------------------------------//
UIXINLINE DWORD uixDateTimeCtrl::GetCalendarRange(SYSTEMTIME time[2]) const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (DWORD)DateTime_GetRange(m_Handle, time);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixDateTimeCtrl::SetCalendarRange(DWORD flags, SYSTEMTIME time[2])
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (BOOL)DateTime_SetRange(m_Handle, flags, time);
}
//----------------------------------------------------------------------------//
UIXINLINE uixMonthCalendarStyle uixDateTimeCtrl::GetCalendarStyle() const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (uixMonthCalendarStyle)DateTime_GetMonthCalStyle(m_Handle);
}
//----------------------------------------------------------------------------//
UIXINLINE uixMonthCalendarStyle uixDateTimeCtrl::SetCalendarStyle(uixMonthCalendarStyle style)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (uixMonthCalendarStyle)DateTime_SetMonthCalStyle(m_Handle, style);
}
//----------------------------------------------------------------------------//
UIXINLINE void uixDateTimeCtrl::CloseMonthCal()
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    DateTime_CloseMonthCal(m_Handle);
}
//----------------------------------------------------------------------------//
UIXINLINE void uixDateTimeCtrl::GetDateTimePickerInfo(DATETIMEPICKERINFO& info) const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    DateTime_GetDateTimePickerInfo(m_Handle, &info);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixDateTimeCtrl::GetIdealSize(SIZE& size) const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (BOOL)DateTime_GetIdealSize(m_Handle, &size);
}
//----------------------------------------------------------------------------//
UIXINLINE HWND uixDateTimeCtrl::GetMonthCal() const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (HWND)DateTime_GetMonthCal(m_Handle);
}
//----------------------------------------------------------------------------//
}
//----------------------------------------------------------------------------//
#endif /* _UIX_DATETIMECTRL_INL__ */