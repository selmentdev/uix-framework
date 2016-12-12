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
#ifndef _UIX_TIME_H__
#define _UIX_TIME_H__
//----------------------------------------------------------------------------//
#include "uixrequired.h"
//----------------------------------------------------------------------------//
namespace UIX
{
//----------------------------------------------------------------------------//
enum uixMonthName
{
    uixMonthName_January = 1,
    uixMonthName_February = 2,
    uixMonthName_March = 3,
    uixMonthName_April = 4,
    uixMonthName_May = 5,
    uixMonthName_June = 6,
    uixMonthName_July = 7,
    uixMonthName_August = 8,
    uixMonthName_September = 9,
    uixMonthName_October = 10,
    uixMonthName_November = 11,
    uixMonthName_December = 12,
};
//----------------------------------------------------------------------------//
enum uixWeekdayName
{
    uixWeekdayName_Sunday = 0,
    uixWeekdayName_Monday = 1,
    uixWeekdayName_Tuesday = 2,
    uixWeekdayName_Wednesday = 3,
    uixWeekdayName_Thursday = 4,
    uixWeekdayName_Friday = 5,
    uixWeekdayName_Saturday = 6,
};
//----------------------------------------------------------------------------//
struct uixSystemTime : SYSTEMTIME
{
    static void GetLocalTime(SYSTEMTIME& time);
    static void GetSystemTime(SYSTEMTIME& time);

    uixSystemTime& GetLocalTime();
    uixSystemTime& GetSystemTime();

    WORD GetYear() const;
    uixMonthName GetMonth() const;
    uixWeekdayName GetDayOfWeek() const;
    WORD GetDay() const;
    WORD GetHour() const;
    WORD GetMinute() const;
    WORD GetSecond() const;
    WORD GetMilliseconds() const;

    void SetYear(WORD value);
    void SetMonth(uixMonthName value);
    void SetDayOfWeek(uixWeekdayName value);
    void SetDay(WORD value);
    void SetHour(WORD value);
    void SetMinute(WORD value);
    void SetSecond(WORD value);
    void SetMilliseconds(WORD value);
};
//----------------------------------------------------------------------------//
}
//----------------------------------------------------------------------------//
#endif /* _UIX_TIME_H__ */