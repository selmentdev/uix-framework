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
#ifndef _UIX_PAGESCROLLERCTRL_H__
#define _UIX_PAGESCROLLERCTRL_H__
//----------------------------------------------------------------------------//
#include "uixwindow.h"
//----------------------------------------------------------------------------//
namespace UIX
{
//! Handle
#define uixEVT_PGN_CALCSIZE(Identifier, Handler) \
    uixEVT_NOTIFY(PGN_CALCSIZE, Identifier, Handler)

//! Handle
#define uixEVT_PGN_HOTITEMCHANGE(Identifier, Handler) \
    uixEVT_NOTIFY(PGN_HOTITEMCHANGE, Identifier, Handler)

//! Handle
#define uixEVT_PGN_SCROLL(Identifier, Handler) \
    uixEVT_NOTIFY(PGN_SCROLL, Identifier, Handler)

//! Page scroller style
enum uixPageScrollerStyle
{
    //! Auto scroll
    uixPageScrollerStyle_AutoScroll = PGS_AUTOSCROLL,
    //! Drag and drop
    uixPageScrollerStyle_DragNDrop = PGS_DRAGNDROP,
    //! Horizontal
    uixPageScrollerStyle_Horizontal = PGS_HORZ,
    //! Vertical
    uixPageScrollerStyle_Vertical = PGS_VERT,
};

//! Page Scroller
//! @brief
//!     This class implements page scroller control
class UIXAPI uixPageScrollerCtrl : public uixWindow
{
    uixDECLARE_DYNAMIC_CLASS(uixPageScrollerCtrl);
    uixDECLARE_EVENT_MAP();
public:
    //! Constructor
    uixPageScrollerCtrl();

    //! Destructor
    virtual ~uixPageScrollerCtrl();

    //! @copydoc uixWindow::BeforeWindowCreate
    virtual BOOL BeforeWindowCreate(CREATESTRUCT& cs) override;

    //! Sets child window
    //! @param[in] child
    //!     Handle to child window
    void SetChild(HWND child);

    //! Recalcs size
    void RecalcSize();

    //! Forwards mouse
    //! @param[in] forward
    //!     Forward flag
    void ForwardMouse(BOOL forward);

    //! Gets background color
    //! @return
    //!     Background color
    uixColor GetBackgroundColor() const;

    //! Sets background color
    //! @param[in] color
    //!     Background color
    //! @return
    //!     Previous background color
    uixColor SetBackgroundColor(uixColor color);

    //! Gets border width
    //! @return
    //!     Border width
    INT GetBorder() const;

    //! Sets border width
    //! @param[in] border
    //!     New border width
    //! @return
    //!     Border width
    INT SetBorder(INT border);

    //! Gets position
    //! @return
    //!     Position
    INT GetPos() const;

    //! Sets position
    //! @param[in] position
    //!     Position
    //! @return
    //!     Previous position
    INT SetPos(INT position);

    //! Gets button size
    //! @return
    //!     Button size
    INT GetButtonSize() const;

    //! Sets button size
    //! @param[in] size
    //!     Button size
    //! @return
    //!     Previuos button size
    INT SetButtonSize(INT size);

    //! Gets button state
    //! @param[in] buttonID
    //!     Button ID
    //! @return
    //!     Button state flags
    DWORD GetButtonState(INT buttonID) const;
};
}
//----------------------------------------------------------------------------//
#include "uixpagescrollerctrl.inl"
//----------------------------------------------------------------------------//
#endif /* _UIX_PAGESCROLLERCTRL_H__ */