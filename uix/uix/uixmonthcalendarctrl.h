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
#ifndef _UIX_MONTHCALCTRL_H__
#define _UIX_MONTHCALCTRL_H__
//----------------------------------------------------------------------------//
#include "uixwindow.h"
//----------------------------------------------------------------------------//
namespace UIX
{
//! Handle
#define uixEVT_MCN_GETDAYSTATE(Identifier, Handler) \
    uixEVT_NOTIFY(MCN_GETDAYSTATE, Identifier, Handler)

//! Handle
#define uixEVT_MCN_SELCHANGE(Identifier, Handler) \
    uixEVT_NOTIFY(MCN_SELCHANGE, Identifier, Handler)

//! Handle
#define uixEVT_MCN_SELECT(Identifier, Handler) \
    uixEVT_NOTIFY(MCN_SELECT, Identifier, Handler)

//! Handle
#define uixEVT_MCN_VIEWCHANGE(Identifier, Handler) \
    uixEVT_NOTIFY(MCN_VIEWCHANGE, Identifier, Handler)

//! Month calendar color
enum uixMonthCalendarColor
{
    //! Background color
    uixMonthCalendarColor_Background = MCSC_BACKGROUND,
    //! Month background color
    uixMonthCalendarColor_MonthBackground =  MCSC_MONTHBK,
    //! Text color
    uixMonthCalendarColor_Text = MCSC_TEXT,
    //! Title background color
    uixMonthCalendarColor_TitleBackground = MCSC_TITLEBK,
    //! Title text color
    uixMonthCalendarColor_TitleText = MCSC_TITLETEXT,
    //! Trailing text color
    uixMonthCalendarColor_TrailingText = MCSC_TRAILINGTEXT,
};

//! Calendar style
enum uixMonthCalendarStyle
{
    uixMonthCalendarStyle_None = 0,
    uixMonthCalendarStyle_DayState = MCS_DAYSTATE,
    uixMonthCalendarStyle_MultiSelect = MCS_MULTISELECT,
    uixMonthCalendarStyle_WeekNumbers = MCS_WEEKNUMBERS,
    uixMonthCalendarStyle_NoTodayCircle = MCS_NOTODAYCIRCLE,
    uixMonthCalendarStyle_NoToday = MCS_NOTODAY,
    uixMonthCalendarStyle_NoTrailingDates = MCS_NOTRAILINGDATES,
    uixMonthCalendarStyle_ShortDaysOfWeek = MCS_SHORTDAYSOFWEEK,
    uixMonthCalendarStyle_NoSelectionChangeOnNavigate = MCS_NOSELCHANGEONNAV,
};

struct uixMonthCalendarGridInfo : MCGRIDINFO
{
};

//! Month calendar view
enum uixMonthCalendarView
{
    uixMonthCalendarView_Month = MCMV_MONTH,
    uixMonthCalendarView_Year = MCMV_YEAR,
    uixMonthCalendarView_Decade = MCMV_DECADE,
    uixMonthCalendarView_Century = MCMV_CENTURY,
};

//! Month Calendar control
//! @brief
//!     This class implements month calendar GUI control
class UIXAPI uixMonthCalendarCtrl : public uixWindow
{
    uixDECLARE_DYNAMIC_CLASS(uixMonthCalendarCtrl)
public:
    //! Constructor
    uixMonthCalendarCtrl();

    //! Destructor
    virtual ~uixMonthCalendarCtrl();

    //! @copydoc uixWindow::BeforeWindowCreate
    virtual BOOL BeforeWindowCreate(CREATESTRUCT& cs) override;

    //! Gets calendar border
    //! @return
    //!     Border
    DWORD GetCalendarBorder() const;

    //! Gets calendar count
    //! @return
    //!     Number of calendars
    DWORD GetCalendarCount() const;

    //! Gets calendar grid info
    //! @param[out] grid
    //!     Grid info
    //! @return
    //!     True when successful
    BOOL GetCalendarGridInfo(MCGRIDINFO& grid) const;

    //! Gets CALID
    //! @return
    //!     CALID
    CALID GetCALID() const;

    //! Gets color
    //! @param[in] color
    //!     Item
    //! @return
    //!     Color of specified item
    uixColor GetColor(uixMonthCalendarColor color) const;

    //! Gets current view
    //! @return
    //!     View
    uixMonthCalendarView GetCurrentView() const;

    //! Gets current selection
    //! @param[out] time
    //!     Selected time
    //! @return
    //!     True when successful
    BOOL GetCurrentSelection(SYSTEMTIME& time) const;

    //! Get first day of week
    //! @return
    //!     Index of first day of week
    DWORD GetFirstDayOfWeek() const;

    //! Gets  max selection count
    //! @return
    //!     Max selection count
    DWORD GetMaxSelectionCount() const;

    //! Get max today width
    //! @return
    //!     Width
    DWORD GetMaxTodayWidth() const;

    //! Gets min required rect
    //! @param[out] rect
    //!     Rect
    //! @return
    //!     True when successful
    BOOL GetMinRequiredRect(RECT& rect) const;

    //! Gets month delta
    //! @return
    //!     Delta
    INT GetMonthDelta() const;

    //! Gets month range
    //! @param[in] flags
    //!     Flags
    //! @param[out] time
    //!     Min and max time
    //! @return
    //!     Flags
    INT GetMonthRange(DWORD flag, SYSTEMTIME time[2]) const;

    //! Gets range
    //! @param[out] time
    //!     Min and max time
    //! @return
    //!     Flags
    DWORD GetRange(SYSTEMTIME time[2]) const;

    //! Gets selection range
    //! @param[out] time
    //!     Selection range
    //! @return
    //!     True when successful
    BOOL GetSelectionRange(SYSTEMTIME time[2]) const;

    //! Gets today
    //! @param[out] time
    //!     Today time
    //! @return
    //!     True when successful
    BOOL GetToday(SYSTEMTIME& time) const;

    //! Gets unicode format support
    //! @return
    //!     True when unicode supported
    BOOL GetUnicodeFormat() const;

    //! Perform hit test
    //! @param[in] hitTest
    //!     Hit test data
    //! @return
    //!     Flags
    DWORD HitTest(MCHITTESTINFO& hitTest) const;

    //! Sets calendar border
    //! @param[in] border
    //!     Border value
    //! @param[in] set
    //!     Set or reset?
    void SetCalendarBorder(INT border, BOOL set = TRUE);

    //! Sets CALID
    //! @param[in] calid
    //!     CALID
    void SetCALID(CALID calid);

    //! Sets color
    //! @param[in] index
    //!     Color index
    //! @param[in] color
    //!     New color
    //! @return
    //!     Previous color
    uixColor SetColor(uixMonthCalendarColor index, uixColor color);

    //! Sets current view
    //! @param[in] view
    //!     New view
    //! @return
    //!     True when successful
    BOOL SetCurrentView(uixMonthCalendarView view);

    //! Sets current selection
    //! @param[in] time
    //!     Current time
    //! @return
    //!     True when successful
    BOOL SetCurrentSelection(const SYSTEMTIME& time);

    //! Sets day state
    //! @param[in] dayStateElements
    //!     Array
    //! @param[in] months
    //!     Number of months
    //! @return
    //!     True when successful
    BOOL SetDayState(MONTHDAYSTATE dayStateElements[], INT months);

    //! Sets first day of week
    //! @param[in] dayID
    //!     Index of first day
    //! @return
    //!     Flags
    DWORD SetFirstDayOfWeek(INT dayID);

    //! Sets max selection count
    //! @param[in] value
    //!     Max selection count
    //! @return
    //!     True when successful
    BOOL SetMaxSelectionCount(UINT max);

    //! Sets month delta
    //! @param[in] delta
    //!     Delta
    //! @return
    //!     Previous delta
    INT SetMonthDelta(INT delta);

    //! Sets range
    //! @param[in] time
    //!     Ranges
    //! @return
    //!     True when successful
    BOOL SetRange(const SYSTEMTIME time[2]);

    //! Sets selection range
    //! @param[in] time
    //!     Range
    //! @return
    //!     True when successful
    BOOL SetSelectionRange(const SYSTEMTIME time[2]);

    //! Sets today
    //! @param[in] time
    //!     Today
    void SetToday(const SYSTEMTIME* time = NULLPTR);

    //! Sets unicode format support
    //! @param[in] unicode
    //!     Unicode flag
    //! @return
    //!     Previous value
    BOOL SetUnicodeFormat(BOOL unicode);

    //! Size rect to min
    //! @param[out] rect
    //!     Rect to minimize
    //! @return
    //!     Result value
    LRESULT SizeRectToMin(RECT& rect) const;
};
}
//----------------------------------------------------------------------------//
#include "uixmonthcalendarctrl.inl"
//----------------------------------------------------------------------------//
#endif /* _UIX_MONTHCALCTRL_H__ */