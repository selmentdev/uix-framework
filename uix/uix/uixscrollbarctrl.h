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
#ifndef _UIX_SCROLLBARCTRL_H__
#define _UIX_SCROLLBARCTRL_H__
//----------------------------------------------------------------------------//
#include "uixwindow.h"
//----------------------------------------------------------------------------//
namespace UIX
{
//! Scroll bar style
enum uixScrollBarStyle
{
    //! Left align
    uixScrollBarStyle_LeftAlign = SBS_LEFTALIGN,
    //! Top align
    uixScrollBarStyle_TopAlign = SBS_TOPALIGN,
    //! Right align
    uixScrollBarStyle_RightAlign = SBS_RIGHTALIGN,
    //! Bottom align
    uixScrollBarStyle_BottomAlign = SBS_BOTTOMALIGN,
    //! Horizontal
    uixScrollBarStyle_Horizontal = SBS_HORZ,
    //! Vertical
    uixScrollBarStyle_Vertical = SBS_VERT,
    //! Size grip
    uixScrollBarStyle_SizeGrip = SBS_SIZEGRIP,
    //! Size box
    uixScrollBarStyle_SizeBox = SBS_SIZEBOX,
    //! Size box bottom right align
    uixScrollBarStyle_SizeBoxBottomRightAlign = SBS_SIZEBOXBOTTOMRIGHTALIGN,
    //! Size box top left align
    uixScrollBarStyle_SizeBoxTopLeftAlign = SBS_SIZEBOXTOPLEFTALIGN,
};

//! Scroll Bar Control
//! @brief
//!     This class implements scrollbar control
class UIXAPI uixScrollBarCtrl : public uixWindow
{
    uixDECLARE_DYNAMIC_CLASS(uixScrollBarCtrl);
public:
    //! Constructor
    uixScrollBarCtrl();

    //! Destructor
    virtual ~uixScrollBarCtrl();

    //! @copydoc uixWindow::BeforeWindowCreate
    virtual BOOL BeforeWindowCreate(CREATESTRUCT& cs) override;

    //! Enable scroll
    //! @param[in] flags
    //!     Flags
    //! @return
    //!     True when successful
    BOOL EnableScroll(UINT flags);

    //! Gets position
    //! @return
    //!     Position
    INT GetPosition() const;

    //! Gets range
    //! @param[out] min
    //!     Min range
    //! @param[out] max
    //!     Max range
    //! @return
    //!     True when successful
    BOOL GetRange(INT& min, INT& max) const;

    //! Sets range
    //! @param[in] min
    //!     Min range
    //! @param[in] max
    //!     Max range
    //! @param[in] redraw
    //!     Redraw
    //! @return
    //!     True when successful
    BOOL SetRange(INT min, INT max, BOOL redraw = TRUE);

    //! Shows scroll bar
    //! @param[in] show
    //!     Show flag
    //! @return
    //!     True when successful
    BOOL ShowScrollBar(BOOL show = TRUE);
};
}
//----------------------------------------------------------------------------//
#endif /* _UIX_SCROLLBARCTRL_H__ */