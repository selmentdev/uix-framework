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
#ifndef _UIX_ANIMATECTRL_H__
#define _UIX_ANIMATECTRL_H__
//----------------------------------------------------------------------------//
#include "uixwindow.h"
//----------------------------------------------------------------------------//
namespace UIX
{
//! Notify messages
enum uixAnimateNotifyMessage
{
    //! Start animation
    uixAnimateNotifyMessage_Start = ACN_START,
    //! Stop animation
    uixAnimateNotifyMessage_Stop = ACN_STOP,
};

//! uixAnimateCtrl style
enum uixAnimateCtrlStyle
{
    //! No style specified
    uixAnimateCtrlStyle_None = 0,
    //! Centers animation in control area
    uixAnimateCtrlStyle_Center = ACS_CENTER,
    //! Transparent animations
    uixAnimateCtrlStyle_Transparent = ACS_TRANSPARENT,
    //! Animation auto play
    uixAnimateCtrlStyle_AutoPlay = ACS_AUTOPLAY,
    //! Uses timer instead thread
    uixAnimateCtrlStyle_Timer = ACS_TIMER,
    //! Default style
    uixAnimateCtrlStyle_Default =
        uixAnimateCtrlStyle_AutoPlay |
        uixAnimateCtrlStyle_Center |
        uixAnimateCtrlStyle_Transparent,
};

//! Animate Control
//! @brief
//!     This class implements GUI control which is able to show any AVI
//!     animations on frame
class UIXAPI uixAnimateCtrl : public uixWindow
{
    uixDECLARE_DYNAMIC_CLASS(uixAnimateCtrl);
public:
    //! Constructor
    uixAnimateCtrl();

    //! Destructor
    virtual ~uixAnimateCtrl();

    //! @copydoc uixWindow::BeforeWindowCreate
    virtual BOOL BeforeWindowCreate(CREATESTRUCT& cs) override;

    //! Open from resource name (current instance)
    //! @param[in] resource
    //!     Resource name
    //! @return
    //!     True when successful
    BOOL OpenFile(const uixChar* fileName);

    //! Load from resource ID, specified instance
    //! @param[in] resource
    //!     Resource name
    //! @return
    //!     True when successful
    BOOL Load(uixResourceName resource);

    //! Load from resource ID, specified instance
    //! @param[in] resourceID
    //!     Resource ID
    //! @return
    //!     True when successful
    BOOL Load(uixResourceID resourceID);

    //! Load from resource ID, specified instance
    //! @param[in] instance
    //!     Handle to library with resource
    //! @param[in] resource
    //!     Resource name
    //! @return
    //!     True when successful
    BOOL Load(HINSTANCE instance, uixResourceName resource);

    //! Load from resource ID, specified instance
    //! @param[in] instance
    //!     Handle to library with resource
    //! @param[in] resourceID
    //!     Resource ID
    //! @return
    //!     True when successful
    BOOL Load(HINSTANCE instance, uixResourceID resourceID);

    //! Play frames
    //! @param[in] from
    //!     Number of first frame, -1 to first frame of animation
    //! @param[in] to
    //!     Number of last frame, -1 to last frame of animation
    //! @param[in] repeat
    //!     Number of repeats, -1 to infinity
    //! @return
    //!     True when successful
    BOOL Play(INT from, INT to, INT repeat);

    //! Stop
    //! @return
    //!     True when successful
    BOOL Stop();

    //! Checks if control is playing animation
    //! @return
    //!     True when successful
    BOOL IsPlaying();

    //! Close animation
    //! @return
    //!     True when successful
    BOOL Close();

    //! Sets current frame
    //! @param[in] frame
    //!     Frame to set
    //! @return
    //!     True when successful
    BOOL Seek(INT frame);
};
}
//----------------------------------------------------------------------------//
#include "uixanimatectrl.inl"
//----------------------------------------------------------------------------//
#endif /* _UIX_ANIMATECTRL_H__ */