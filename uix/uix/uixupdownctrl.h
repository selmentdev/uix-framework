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
#ifndef _UIX_UPDOWNCTRL_H__
#define _UIX_UPDOWNCTRL_H__
//----------------------------------------------------------------------------//
#include "uixwindow.h"
//----------------------------------------------------------------------------//
namespace UIX
{
//! Handle
#define uixEVT_UDN_DELTAPOS(Identifier, Handler) \
    uixEVT_NOTIFY(UDN_DELTAPOS, Identifier, Handler)

enum uixUpDownStyle
{
    uixUpDownStyle_AlignLeft = UDS_ALIGNLEFT,
    uixUpDownStyle_AlignRight = UDS_ALIGNRIGHT,
    uixUpDownStyle_ArrowKeys = UDS_ARROWKEYS,
    uixUpDownStyle_AutoBuddy = UDS_AUTOBUDDY,
    uixUpDownStyle_Horizontal = UDS_HORZ,
    uixUpDownStyle_HotTrack = UDS_HOTTRACK,
    uixUpDownStyle_NoThousands = UDS_NOTHOUSANDS,
    uixUpDownStyle_SetBuddyInt = UDS_SETBUDDYINT,
    uixUpDownStyle_Wrap = UDS_WRAP,
};

//! @todo Document
struct uixUpDownAccel : UDACCEL
{
};

//! UpDown control
//! @brief
//!     This class implements up down control, which allows to change numerical
//!     values in attached controls, just like uixTextBoxCtrl - a buddy control
class UIXAPI uixUpDownCtrl : public uixWindow
{
    uixDECLARE_DYNAMIC_CLASS(uixUpDownCtrl);
public:
    //! Constructor
    uixUpDownCtrl();

    //! Destructor
    virtual ~uixUpDownCtrl();

    //! @copydoc uixWindow::BeforeWindowCreate
    virtual BOOL BeforeWindowCreate(CREATESTRUCT& cs) override;

    //! Gets accelerator table
    //! @param[out] accels
    //!     Accelerator table
    //! @param[in] count
    //!     Number of elements in accels
    //! @return
    //!     Number of elements set in control
    UINT GetAccel(UDACCEL accels[], UINT count) const;

    //! Gets radix base
    //! @return
    //!     Radix base
    INT GetRadixBase() const;

    //! Gets buddy window
    //! @return
    //!     Handle to buddy window
    HWND GetBuddy() const;

    //! Gets value
    //! @return
    //!     Value
    INT GetValue() const;

    //! Gets range
    //! @param[out] low
    //!     Low range value
    //! @param[out] high
    //!     High range value
    void GetRange(INT& low, INT& high) const;

    //! Gets unicode format
    //! @return
    //!     True when unicode is enabled
    BOOL GetUnicodeFormat() const;

    //! Sets accelerator table
    //! @param[in] accels
    //!     Accelerator table
    //! @param[in] count
    //!     Number of element in accels
    //! @return
    //!     True when successful
    BOOL SetAccel(const UDACCEL accels[], UINT count);

    //! Sets radix base
    //! @param[in] base
    //!     Radix base
    //! @return
    //!     Previous radix base
    INT SetRadixBase(INT base);

    //! Sets buddy window
    //! @param[in] handle
    //!     New buddy window handle
    //! @return
    //!     Previous buddy window handle
    HWND SetBuddy(HWND handle);

    //! Sets value
    //! @param[in] value
    //!     Value
    //! @return
    //!     Previous value
    INT SetValue(INT value);

    //! Sets range values
    //! @param[in] low
    //!     Lower bound
    //! @param[in] high
    //!     Higher bound
    void SetRange(INT low, INT high);

    //! Sets unicode format
    //! @param[in] unicode
    //!     Unicode format flag
    //! @return
    //!     Previuos unicode format flag
    BOOL SetUnicodeFormat(BOOL unicode);
};
}
//----------------------------------------------------------------------------//
#include "uixupdownctrl.inl"
//----------------------------------------------------------------------------//
#endif /* _UIX_UPDOWNCTRL_H__ */