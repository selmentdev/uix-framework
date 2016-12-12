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
#ifndef _UIX_PROGRESSBARCTRL_H__
#define _UIX_PROGRESSBARCTRL_H__
//----------------------------------------------------------------------------//
#include "uixwindow.h"
//----------------------------------------------------------------------------//
namespace UIX
{
//! Progress Bar state
enum uixProgressBarState
{
    //! Normal
    uixProgressBarState_Normal = PBST_NORMAL,
    //! Error
    uixProgressBarState_Error = PBST_ERROR,
    //! Paused
    uixProgressBarState_Paused = PBST_PAUSED,
};

//! Progress Bar Range
struct uixProgressBarRange : public PBRANGE
{
    //! Gets low range
    //! @return
    //!     Low range value
    INT GetLow() const;

    //! Sets low range
    //! @param[in] value
    //!     Low range value
    void SetLow(INT value);

    //! Gets high range
    //! @return
    //!     High range value
    INT GetHigh() const;

    //! Sets high range
    //! @param[in] value
    //!     High range value
    void SetHigh(INT value);
};

//! Progress bar style
enum uixProgressBarStyle
{
    //! Marquee
    uixProgressBarStyle_Marquee = PBS_MARQUEE,
    //! Smooth
    uixProgressBarStyle_Smooth = PBS_SMOOTH,
    //! Smooth reverse
    uixProgressBarStyle_SmoothReverse = PBS_SMOOTHREVERSE,
    //! Horizontal
    uixProgressBarStyle_Horizontal = 0,
    //! Vertical
    uixProgressBarStyle_Vertical = PBS_VERTICAL,
};

//! ProgressBar Control
//! @brief
//!     This class implements progressbar control
class UIXAPI uixProgressBarCtrl : public uixWindow
{
    uixDECLARE_DYNAMIC_CLASS(uixProgressBarCtrl);
public:
    //! Constructor
    uixProgressBarCtrl();

    //! Destructor
    virtual ~uixProgressBarCtrl();

    //! @copydoc uixWindow::BeforeWindowCreate
    virtual BOOL BeforeWindowCreate(CREATESTRUCT& cs) override;

    //! Delta position
    //! @param[in] delta
    //!     Delta value
    //! @return
    //!     Previous delta value
    INT DeltaPos(INT delta);

    //! Gets bar color
    //! @return
    //!     Bar color
    uixColor GetBarColor() const;

    //! Gets background color
    //! @return
    //!     Background color
    uixColor GetBackgroundColor() const;

    //! Gets progress position
    //! @return
    //!     Progress position
    INT GetPosition() const;

    //! Gets range
    //! @param[out] range
    //!     Range
    void GetRange(uixProgressBarRange& range) const;

    //! Gets progress bar state
    //! @return
    //!     State
    uixProgressBarState GetState() const;

    //! Gets step value
    //! @return
    //!     Step value
    INT GetStep() const;

    //! Sets bar color
    //! @param[in] color
    //!     Color
    //! @return
    //!     Previous color
    uixColor SetBarColor(uixColor color);

    //! Sets background color
    //! @param[in] color
    //!     Color
    //! @return
    //!     Previous color
    //! @note
    //!     CLR_DEFAULT
    uixColor SetBackgroundColor(uixColor color);

    //! Sets marquee mode
    //! @param[in] enable
    //!     Enabled flag
    //! @param[in] deltaTime
    //!     Delta time in ms
    void SetMarquee(BOOL enable, UINT deltaTime);

    //! Sets position
    //! @param[in] position
    //!     Position
    //! @return
    //!     Previous position
    INT SetPosition(INT position);

    //! Sets range
    //! @param[in] low
    //!     Low range limit
    //! @param[in] high
    //!     High range limit
    void SetRange(INT low, INT high);

    //! Sets range
    //! @param[in] range
    //!     Range
    void SetRange(const uixProgressBarRange& range);

    //! Sets progress bar state
    //! @param[in] state
    //!     Progress Bar state
    //! @return
    //!     Previous state
    uixProgressBarState SetState(uixProgressBarState state);

    //! Sets step value
    //! @param[in] step
    //!     Step value
    //! @return
    //!     Previous step value
    INT SetStep(INT step);

    //! Moves progress by step value
    //! @return
    //!     New position
    INT StepIt();
};
}
//----------------------------------------------------------------------------//
#include "uixprogressbarctrl.inl"
//----------------------------------------------------------------------------//
#endif /* _UIX_PROGRESSBARCTRL_H__ */