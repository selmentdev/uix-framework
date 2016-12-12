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
#ifndef _UIX_DATETIMECTRL_H__
#define _UIX_DATETIMECTRL_H__
//----------------------------------------------------------------------------//
#include "uixwindow.h"
#include "uixmonthcalendarctrl.h"
//----------------------------------------------------------------------------//
namespace UIX
{
//! Handle moncal dropwodn
#define uixEVT_DTN_DROPDOWN(Identifier, Handler) /* LRESULT (INT code, NMHDR* header) */ \
    uixEVT_NOTIFY(DTN_DROPDOWN)

//! Handle moncal closeup
#define uixEVT_DTN_CLOSEUP(Identifier, Handler) /* LRESULT (INT code, NMHDR* header) */ \
    uixEVT_NOTIFY(DTN_CLOSEUP, Identifier, Handler)

//! Handle date time change
#define uixEVT_DTN_DATETIMECHANGE(Identifier, Handler) /* LRESULT (INT code, NMHDR* header) */ \
    uixEVT_NOTIFY(DTN_DATETIMECHANGE, Identifier, Handler)

//! Handle format
#define uixEVT_DTN_FORMAT(Identifier, Handler) /* LRESULT (INT code, NMHDR* header) */ \
    uixEVT_NOTIFY(DTN_FORMAT, Identifier, Handler)

//! Handle format query
#define uixEVT_DTN_FORMATQUERY(Identifier, Handler) /* LRESULT (INT code, NMHDR* header) */ \
    uixEVT_NOTIFY(DTN_FORMATQUERY, Identifier, Handler)

//! Handle user strings nm
#define uixEVT_DTN_USERSTRING(Identifier, Handler) /* LRESULT (INT code, NMHDR* header) */ \
    uixEVT_NOTIFY(DTN_USERSTRING, Identifier, Handler)

//! Handle DTN_WMKEYDOWN
#define uixEVT_DTN_KEYDOWN(Identifier, Handler) /* LRESULT (INT code, NMHDR* header) */ \
    uixEVT_NOTIFY(DTN_WMKEYDOWN, Identifier, Handler)


//! Date Time control style
enum uixDateTimeCtrlStyle
{
    //! None
    uixDateTimeCtrlStyle_None = 0,
    //! Up Down
    uixDateTimeCtrlStyle_UpDown = DTS_UPDOWN,
    //! No selection
    uixDateTimeCtrlStyle_ShowNone = DTS_SHOWNONE,
    //! Short date format
    uixDateTimeCtrlStyle_ShortDateFormat = DTS_SHORTDATEFORMAT,
    //! Short date format with century
    uixDateTimeCtrlStyle_ShortDateCenturyFormat = DTS_SHORTDATECENTURYFORMAT,
    //! Time format
    uixDateTimeCtrlStyle_TimeFormat = DTS_TIMEFORMAT,
    //! Allow user to enter strings
    uixDateTimeCtrlStyle_AppCanParse = DTS_APPCANPARSE,
    //! Right align popup
    uixDateTimeCtrlStyle_RightAlignPopup = DTS_RIGHTALIGN,
};

//! Date and time picker control
//! @brief
//!     This control allows user enter date and time by using popup calendar
class UIXAPI uixDateTimeCtrl : public uixWindow
{
    uixDECLARE_DYNAMIC_CLASS(uixDateTimeCtrl);
public:
    //! Constructor
    uixDateTimeCtrl();

    //! Destructor
    virtual ~uixDateTimeCtrl();

    //! @copydoc uixWindow::BeforeWindowCreate
    virtual BOOL BeforeWindowCreate(CREATESTRUCT& cs) override;

    //! Sets calendar format
    //! @param[in] format
    //!     New format
    //! @return
    //!     True when successful
    //! @note
    //!     String format may contain those specifiers:
    //!     - "d" - one or two digit day
    //!     - "dd" - two digit day, leading zeros
    //!     - "ddd" - three character weekday abbr
    //!     - "dddd" - full weekday name
    //!     - "h" - one or two digit hour in 12-hour format
    //!     - "hh" - two digit hour in 12-hour format
    //!     - "H" - one or two digit hour in 24-hour format
    //!     - "HH" - two digit hour in 24-hour format
    //!     - "m" - one or two digit minute
    //!     - "mm" - two digit minute, leading zeros
    //!     - "MM" - two digit month number
    //!     - "MMM" - three character month abbr
    //!     - "MMMM" - full month name
    //!     - "t" - one letter AM/PM abbr
    //!     - "tt" - two letter AM/PM abbr
    //!     - "yy" - last two digits of year
    //!     - "yyyy" - full year
    BOOL SetCalendarFormat(const uixChar* format);

    //! Gets calendar window handle
    //! @return
    //!     Handle to calendar window
    HWND GetCalendarHandle() const;

    //! Gets calendar part color
    //! @param[in] colorID
    //!     Color ID
    //! @return
    //!     Color of specified part
    uixColor GetCalendarColor(uixMonthCalendarColor colorID) const;

    //! Sets calendar part color
    //! @param[in] colorID
    //!     Color ID
    //! @param[in] color
    //!     New color of specified part
    //! @return
    //!     Previous color of part
    uixColor SetCalendarColor(uixMonthCalendarColor colorID, uixColor color);

    //! Gets calendar selected time
    //! @param[out] time
    //!     Time
    //! @return
    //!     True when successful
    BOOL GetCalendarTime(SYSTEMTIME& time) const;

    //! Sets calendar time
    //! @param[in] valid
    //!     False to unset time
    //! @param[in] time
    //!     Time to set
    //! @return
    //!     True when successful
    BOOL SetCalendarTime(BOOL valid, SYSTEMTIME& time);

    //! Gets calendar font
    //! @return
    //!     Current font handle
    HFONT GetCalendarFont() const;

    //! Sets calendar font
    //! @param[in] handle
    //!     Handle to new font
    //! @param[in] redraw
    //!     Redraw flag
    void SetCalendarFont(HFONT handle, BOOL redraw = FALSE);

    //! Gets calendar range
    //! @param[in] time
    //!     Time range
    //! @return
    //!     Combination of GDTR_MIN and GDTR_MAX flags
    DWORD GetCalendarRange(SYSTEMTIME time[2]) const;

    //! Sets calendar range
    //! @param[in] flags
    //!     Combination of GDTR_MIN and GDTR_MAX flags
    //! @param[in] time
    //!     Time range
    //! @return
    //!     True when successful
    BOOL SetCalendarRange(DWORD flags, SYSTEMTIME time[2]);

    //! Gets calendar style
    //! @return
    //!     Calendar style
    uixMonthCalendarStyle GetCalendarStyle() const;

    //! Sets calendar style
    //! @param[in] style
    //!     New calendar style
    //! @return
    //!     Previous calendar style
    uixMonthCalendarStyle SetCalendarStyle(uixMonthCalendarStyle style);

    //! Close drop down calendar
    void CloseMonthCal();

    //! @note DATETIMEPICKERINFO not implemented.
    //! @param[in,out] info
    //!     Control info struct
    void GetDateTimePickerInfo(DATETIMEPICKERINFO& info) const;

    //! Gets ideal control size
    //! @param[out] size
    //!     Ideal size
    //! @return
    //!     True when successful
    BOOL GetIdealSize(SIZE& size) const;

    //! Gets month calendar handle
    //! @return
    //!     Handle to month calendar
    HWND GetMonthCal() const;
};
}
//----------------------------------------------------------------------------//
#include "uixdatetimectrl.inl"
//----------------------------------------------------------------------------//
#endif /* _UIX_DATETIMECTRL_H__ */