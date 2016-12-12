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
#ifndef _UIX_LABEL_H__
#define _UIX_LABEL_H__
//----------------------------------------------------------------------------//
#include "uixwindow.h"
//----------------------------------------------------------------------------//
namespace UIX
{
//! Handle label clicked
#define uixEVT_LLN_CLICKED(Identifier, Handler) /* void(void) */ \
    uixEVT_CONTROL(STN_CLICKED, Identifier, Handler)

//! Handle label double clicked
#define uixEVT_LLN_DBLCLICKED(Identifier, Handler) /* void(void) */ \
    uixEVT_CONTROL(STN_DBLCLK, Identifier, Handler)

//! Handle label enable
#define uixEVT_LLN_ENABLE(Identifier, Handler) /* void(void) */ \
    uixEVT_CONTROL(STN_ENABLE, Identifier, Handler)

//! Handle label disable
#define uixEVT_LLN_DISABLE(Identifier, Handler) /* void(void) */ \
    uixEVT_CONTROL(STN_DISABLE, Identifier, Handler)

//! Label style
enum uixLabelStyle
{
    //! Bitmap
    uixLabelStyle_Bitmap = SS_BITMAP,
    //! Black frame
    uixLabelStyle_BlackFrame = SS_BLACKFRAME,
    //! Black rect
    uixLabelStyle_BlackRect = SS_BLACKRECT,
    //! Center
    uixLabelStyle_Center = SS_CENTER,
    //! Center image
    uixLabelStyle_CenterImage = SS_CENTERIMAGE,
    //! Edit control
    uixLabelStyle_EditControl = SS_EDITCONTROL,
    //! End ellipsis
    uixLabelStyle_EndEllipsis = SS_ENDELLIPSIS,
    //! Enhanced meta file
    uixLabelStyle_EnhMetaFile = SS_ENHMETAFILE,
    //! Etched frame
    uixLabelStyle_EtchedFrame = SS_ETCHEDFRAME,
    //! Etched horizontal
    uixLabelStyle_EtchedHorizontal = SS_ETCHEDHORZ,
    //! Etched vertical
    uixLabelStyle_EtchedVertical = SS_ETCHEDVERT,
    //! Gray frame
    uixLabelStyle_GrayFrame = SS_GRAYFRAME,
    //! Gray rect
    uixLabelStyle_GrayRect = SS_GRAYRECT,
    //! Icon
    uixLabelStyle_Icon = SS_ICON,
    //! Align left
    uixLabelStyle_Left = SS_LEFT,
    //! Left no word wrap
    uixLabelStyle_LeftNoWordWrap = SS_LEFTNOWORDWRAP,
    //! No prefix
    uixLabelStyle_NoPrefix = SS_NOPREFIX,
    //! Notify
    uixLabelStyle_Notify = SS_NOTIFY,
    //! Owner draw
    uixLabelStyle_OwnerDraw = SS_OWNERDRAW,
    //! Path ellipsis
    uixLabelStyle_PathEllipsis = SS_PATHELLIPSIS,
    //! Real size control
    uixLabelStyle_RealSizeControl = SS_REALSIZECONTROL,
    //! Real size image
    uixLabelStyle_RealSizeImage = SS_REALSIZEIMAGE,
    //! Right text align
    uixLabelStyle_Right = SS_RIGHT,
    //! Right text justify
    uixLabelStyle_RightJustify = SS_RIGHTJUST,
    //! Simple
    uixLabelStyle_Simple = SS_SIMPLE,
    //! Sunken
    uixLabelStyle_Sunken = SS_SUNKEN,
    //! Type mask
    uixLabelStyle_TypeMask = SS_TYPEMASK,
    //! White frame
    uixLabelStyle_WhiteFrame = SS_WHITEFRAME,
    //! White rect
    uixLabelStyle_WhiteRect = SS_WHITERECT,
    //! Word ellipsis
    uixLabelStyle_WordEllipsis = SS_WORDELLIPSIS,
};

//! Label control
//! @brief
//!     This class implements label control
//! @note
//!     Notify message entries are starting with uixEVT_LLN_
class UIXAPI uixLabel : public uixWindow
{
    uixDECLARE_DYNAMIC_CLASS(uixLabel);
    uixDECLARE_EVENT_MAP();
public:
    //! Constructor
    uixLabel();

    //! Destructor
    virtual ~uixLabel();

    //! @copydoc uixWindow::BeforeWindowCreate
    virtual BOOL BeforeWindowCreate(CREATESTRUCT& cs) override;

    //! Gets icon handle
    //! @return
    //!     Icon handle
    HICON GetIcon() const;

    //! Gets bitmap handle
    //! @return
    //!     Bitmap handle
    HBITMAP GetBitmap() const;

    //! Gets cursor handle
    //! @return
    //!     Cursor handle
    HCURSOR GetCursor() const;

    //! Sets icon handle
    //! @param[in] icon
    //!     Icon handle
    //! @return
    //!     Previous icon handle
    HICON SetIcon(HICON icon);

    //! Sets bitmap handle
    //! @param[in] bitmap
    //!     Bitmap handle
    //! @return
    //!     Previous bitmap handle
    HBITMAP SetBitmap(HBITMAP bitmap);

    //! Sets cursor handle
    //! @param[in] cursor
    //!     Cursor handle
    //! @return
    //!     Previous cursor handle
    HCURSOR SetCursor(HCURSOR cursor);
};
}
//----------------------------------------------------------------------------//
#include "uixlabel.inl"
//----------------------------------------------------------------------------//
#endif /* _UIX_LABEL_H__ */