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
#ifndef _UIX_TIME_INL__
#define _UIX_TIME_INL__
//----------------------------------------------------------------------------//
namespace UIX
{
//----------------------------------------------------------------------------//
UIXINLINE void uixSystemTime::GetLocalTime(SYSTEMTIME& time)
{
    ::GetLocalTime(&time);
}
//----------------------------------------------------------------------------//
UIXINLINE void uixSystemTime::GetSystemTime(SYSTEMTIME& time)
{
    ::GetSystemTime(&time);
}
//----------------------------------------------------------------------------//
UIXINLINE uixSystemTime& uixSystemTime::GetLocalTime()
{
    ::GetLocalTime(this);
    return (*this);
}
//----------------------------------------------------------------------------//
UIXINLINE uixSystemTime& uixSystemTime::GetSystemTime()
{
    ::GetSystemTime(this);
    return (*this);
}
//----------------------------------------------------------------------------//
UIXINLINE WORD uixSystemTime::GetYear() const
{
    return wYear;
}
//----------------------------------------------------------------------------//
UIXINLINE uixMonthName uixSystemTime::GetMonth() const
{
    return (uixMonthName)wMonth;
}
//----------------------------------------------------------------------------//
UIXINLINE uixWeekdayName uixSystemTime::GetDayOfWeek() const
{
    return (uixWeekdayName)wDayOfWeek;
}
//----------------------------------------------------------------------------//
UIXINLINE WORD uixSystemTime::GetDay() const
{
    return wDay;
}
//----------------------------------------------------------------------------//
UIXINLINE WORD uixSystemTime::GetHour() const
{
    return wHour;
}
//----------------------------------------------------------------------------//
UIXINLINE WORD uixSystemTime::GetMinute() const
{
    return wMinute;
}
//----------------------------------------------------------------------------//
UIXINLINE WORD uixSystemTime::GetSecond() const
{
    return wSecond;
}
//----------------------------------------------------------------------------//
UIXINLINE WORD uixSystemTime::GetMilliseconds() const
{
    return wMilliseconds;
}
//----------------------------------------------------------------------------//
UIXINLINE void uixSystemTime::SetYear(WORD value)
{
    wYear = value;
}
//----------------------------------------------------------------------------//
UIXINLINE void uixSystemTime::SetMonth(uixMonthName value)
{
    wMonth = value;
}
//----------------------------------------------------------------------------//
UIXINLINE void uixSystemTime::SetDayOfWeek(uixWeekdayName value)
{
    wDayOfWeek = value;
}
//----------------------------------------------------------------------------//
UIXINLINE void uixSystemTime::SetDay(WORD value)
{
    wDay = value;
}
//----------------------------------------------------------------------------//
UIXINLINE void uixSystemTime::SetHour(WORD value)
{
    wHour = value;
}
//----------------------------------------------------------------------------//
UIXINLINE void uixSystemTime::SetMinute(WORD value)
{
    wMinute = value;
}
//----------------------------------------------------------------------------//
UIXINLINE void uixSystemTime::SetSecond(WORD value)
{
    wSecond = value;
}
//----------------------------------------------------------------------------//
UIXINLINE void SetMilliseconds(WORD value)
{
    wMilliseconds = value;
}
//----------------------------------------------------------------------------//
}
//----------------------------------------------------------------------------//
#endif /* _UIX_TIME_INL__ */