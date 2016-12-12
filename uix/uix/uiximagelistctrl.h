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
#ifndef _UIX_IMAGELISTCTRL_H__
#define _UIX_IMAGELISTCTRL_H__
//----------------------------------------------------------------------------//
#include "uixobject.h"
//----------------------------------------------------------------------------//
namespace UIX
{
//! Image List draw style
enum enumUixImageListDrawStyle
{
    //! Blend 25%
    uixImageListDrawStyle_Blend25 = ILD_BLEND25,
    //! Focus
    uixImageListDrawStyle_Focus = ILD_FOCUS,
    //! Blend 50%
    uixImageListDrawStyle_Blend50 = ILD_BLEND50,
    //! Selected
    uixImageListDrawStyle_Selected = ILD_SELECTED,
    //! Blend
    uixImageListDrawStyle_Blend = ILD_BLEND,
    //! Mask
    uixImageListDrawStyle_Mask = ILD_MASK,
    //! Normal
    uixImageListDrawStyle_Normal = ILD_NORMAL,
    //! Transparent
    uixImageListDrawStyle_Transparent = ILD_TRANSPARENT,
};
typedef UINT uixImageListDrawStyle;

//! Image List control
//! @brief
//!     This class implements image list control
class UIXAPI uixImageListCtrl : public uixObject
{
    uixDECLARE_DYNAMIC_CLASS(uixImageListCtrl);
private:
    HIMAGELIST m_Handle;    //!< Handle
public:
    //! Constructor
    //! @param[in] handle
    //!     Handle
    uixImageListCtrl(HIMAGELIST handle = 0);

    //! Destructor
    virtual ~uixImageListCtrl();

    //! Handle cast operator
    operator HIMAGELIST();

    //! Gets handle
    //! @return
    //!     Handle
    HIMAGELIST GetHandle() const;
    //! Gets safe handle
    //! @return
    //!     Safe handle
    HIMAGELIST GetHandleSafe() const;

    //! Create image list
    //! @param[in] cx
    //!     Item width
    //! @param[in] cy
    //!     Item height
    //! @param[in] flags
    //!     Flags
    //! @param[in] initialCount
    //!     Initial count
    //! @param[in] growCount
    //!     Grow count
    //! @return
    //!     True when successful
    BOOL Create(INT cx, INT cy, UINT flags, INT initialCount, INT growCount);

    //! Create image list
    //! @param[in] bitmap
    //!     Bitmap resource name
    //! @param[in] cx
    //!     Image width
    //! @param[in] growCount
    //!     Amount of items when grow
    //! @param[in] mask
    //!     Color mask
    BOOL Create(uixResourceName bitmap, INT cx, INT growCount, uixColor mask);

    //! Create image list
    //! @param[in] bitmapID
    //!     Bitmap resource id
    //! @param[in] cx
    //!     Image width
    //! @param[in] growCount
    //!     Amount of items when grow
    //! @param[in] mask
    //!     Color mask
    BOOL Create(uixResourceID bitmapID, INT cx, INT growCount, uixColor mask);

    //! Create image list
    //! @param[in] instance
    //!     Module instance
    //! @param[in] bitmapID
    //!     Resource ID
    //! @param[in] cx
    //!     Item width
    //! @param[in] growCount
    //!     Grow count
    //! @param[in] mask
    //!     Mask color
    //! @return
    //!     True when successful
    BOOL Create(HINSTANCE instance, uixResourceID bitmapID, INT cx, INT growCount, uixColor mask);

    //! Create image list
    //! @param[in] instance
    //!     Module instance
    //! @param[in] resource
    //!     Resource name
    //! @param[in] cx
    //!     Item width
    //! @param[in] growCount
    //!     Grow count
    //! @param[in] mask
    //!     Mask color
    //! @return
    //!     True when successful
    BOOL Create(HINSTANCE instance, uixResourceName resource, INT cx, INT growCount, uixColor mask);

    //! Create image list
    //! @param[in] resource
    //!     Resource name
    //! @param[in] buttonSize
    //!     Button size
    //! @param[in] btnini
    //!     Buttons initial count
    //! @return
    //!     True when successful
    BOOL CreateColor(uixResourceName resource, SIZE buttonSize, INT buttonCount = -1);

    //! Create image list
    //! @param[in] resource
    //!     Resource name
    //! @param[in] buttonSize
    //!     Button size
    //! @param[in] btnini
    //!     Buttons initial count
    //! @return
    //!     True when successful
    BOOL CreateColor(uixResourceID resourceID, SIZE buttonSize, INT buttonCount = -1);

    //! Create image list
    //! @param[in] instance
    //!     Instance to module handle
    //! @param[in] resource
    //!     Resource name
    //! @param[in] buttonSize
    //!     Button size
    //! @param[in] btnini
    //!     Buttons initial count
    //! @return
    //!     True when successful
    BOOL CreateColor(HINSTANCE instance, uixResourceName resource, SIZE buttonSize,
                     INT buttonCount = -1);

    //! Create image list using color
    //! @param[in] instance
    //!     Module instance
    //! @param[in] resourceID
    //!     Resource ID
    //! @param[in] buttonSize
    //!     Button size
    //! @param[in] btnini
    //!     Initial button count
    //! @return
    //!     True when successful
    BOOL CreateColor(HINSTANCE instance, uixResourceID resourceID, SIZE buttonSize, INT btnini = -1);

    //! Destroy image list
    //! @return
    //!     True when successful
    BOOL Destroy();

    //! Attach image list handle to object
    //! @param[in] handle
    //!     Handle to attach
    //! @return
    //!     True when successful
    BOOL Attach(HIMAGELIST handle);

    //! Detach handle from object
    //! @return
    //!     Handle attached to object
    HIMAGELIST Detach();

    //! Gets image count
    //! @return
    //!     Image count
    INT GetImageCount() const;

    //! Gets image info
    //! @param[in] imageID
    //!     Image ID
    //! @param[in] ii
    //!     Image info
    //! @return
    //!     True when successful
    BOOL GetImageInfo(INT imageID, IMAGEINFO& ii);

    //! Sets image count
    //! @param[in] newCount
    //!     New images count
    //! @return
    //!     True when successful
    BOOL SetImageCount(UINT newCount);

    //! Adds bitmap to image list
    //! @param[in] image
    //!     Image to add
    //! @param[in] mask
    //!     Image mask
    //! @return
    //!     Index of new image
    INT Add(HBITMAP image, HBITMAP mask);

    //! Adds masked bitmap to image list
    //! @param[in] image
    //!     Image to add
    //! @param[in] mask
    //!     Color mask
    //! @return
    //!     Index of new image
    INT AddMasked(HBITMAP image, uixColor mask);

    //! Replaces icon
    //! @param[in] imageID
    //!     Image ID
    //! @param[in] icon
    //!     Handle to icon
    //! @return
    //!     Image ID
    INT ReplaceIcon(INT imageID, HICON icon);

    //! Adds icon to image list
    //! @param[in] icon
    //!     Icon to add
    //! @return
    //!     Index of new image
    INT AddIcon(HICON icon);

    //! Sets background color
    //! @param[in] color
    //!     Background color
    //! @return
    //!     Previous background color
    uixColor SetBackgroundColor(uixColor color);

    //! Gets background color
    //! @return
    //!     Background color
    uixColor GetBackgroundColor() const;

    //! Sets overlay image
    //! @param[in] imageID
    //!     Image ID
    //! @param[in] overlayID
    //!     Overlay ID
    //! @return
    //!     Color
    uixColor SetOverlayImage(INT imageID, INT overlayID);

    //! Draws image on dc
    //! @param[in] imageID
    //!     Image to draw
    //! @param[in] dc
    //!     On DC
    //! @param[in] x
    //!     Left position
    //! @param[in] y
    //!     Top position
    //! @param[in] style
    //!     Draw style
    //! @return
    //!     True when successful
    BOOL Draw(INT imageID, HDC dc, INT x, INT y, uixImageListDrawStyle style);

    //! Draws image on dc
    //! @param[in] imageID
    //!     Image to draw
    //! @param[in] dc
    //!     On DC
    //! @param[in] pt
    //!     Position
    //! @param[in] style
    //!     Draw style
    //! @return
    //!     True when successful
    BOOL Draw(INT imageID, HDC dc, POINT pt, uixImageListDrawStyle style);

    //! Replace image
    //! @param[in] indexID
    //!     Index of image to replace
    //! @param[in] image
    //!     Handle to replacement bitmap
    //! @param[in] mask
    //!     Handle to mask bitmap
    //! @return
    //!     True when successful
    BOOL Replace(INT indexID, HBITMAP image, HBITMAP mask);

    //! Draws image on dc
    //! @param[in] imageID
    //!     Image to draw
    //! @param[in] dc
    //!     On DC
    //! @param[in] x
    //!     Left position
    //! @param[in] y
    //!     Top position
    //! @param[in] dx
    //!
    //! @param[in] dy
    //!
    //! @param[in] background
    //!     Background color
    //! @param[in] foreground
    //!     Foreground color
    //! @param[in] style
    //!     Draw style
    //! @return
    //!     True when successful
    BOOL DrawEx(INT imageID, HDC dc, INT x, INT y, INT dx, INT dy, uixColor background,
                uixColor foreground, uixImageListDrawStyle style);

    //! Draws indirect
    //! @param[in] params
    //!     Draw indirect params
    //! @return
    //!     True when successful
    BOOL DrawIndirect(IMAGELISTDRAWPARAMS& params);

    //! Removes image from list
    //! @param[in] imageID
    //!     Index of image to remove
    //! @return
    //!     True when successful
    BOOL Remove(INT imageID);

    //! Clears image list
    //! @return
    //!     True when successful
    BOOL Clear();

    //! Gets icon handle
    //! @param[in] imageID
    //!     Image ID
    //! @param[in] flags
    //!     Flags
    //! @return
    //!     Icon handle
    HICON GetIcon(INT imageID, uixImageListDrawStyle flags);

    //! Copy image
    //! @param[in] targetID
    //!     Target ID
    //! @param[in] iml
    //!     Image List
    //! @param[in] sourceID
    //!     Source ID
    //! @param[in] flags
    //!     Flags
    //! @return
    //!     True when successful
    BOOL Copy(INT targetID, HIMAGELIST iml, INT sourceID, UINT flags);

    //! Copy image
    //! @param[in] targetID
    //!     Target ID
    //! @param[in] sourceID
    //!     Source ID
    //! @param[in] flags
    //!     Flags
    //! @return
    //!     True when successful
    BOOL Copy(INT targetID, INT sourceID, UINT flags);

    //! Begin Drag
    //! @param[in] trackImageID
    //!     Track Image ID
    //! @param[in] dxHotspot
    //!     dx of hotspot point
    //! @param[in] dyHotspot
    //!     dx of hotspot point
    //! @return
    //!     True when successful
    BOOL BeginDrag(INT trackImageID, INT dxHotspot, INT dyHotspot);

    //! Ends dragging
    static void EndDrag();

    //! Enters dragging
    //! @param[in] window
    //!     Window handle
    //! @param[in] x
    //!     Left position
    //! @param[in] y
    //!     Top position
    //! @return
    //!     True when successful
    static BOOL DragEnter(HWND window, INT x, INT y);

    //! Leave dragging
    //! @param[in] window
    //!     Window handle
    //! @return
    //!     True when successful
    static BOOL DragLeave(HWND window);

    //! Move drag
    //! @param[in] x
    //!     Left position
    //! @param[in] y
    //!     Top position
    //! @return
    //!     True when successful
    static BOOL DragMove(INT x, INT y);

    //! Sets drag cursor image
    //! @param[in] dragImageID
    //!     Image ID which will be used to as drag cursor
    //! @param[in] dxHotspot
    //!     dx Hotspot value
    //! @param[in] dyHotspot
    //!     dy Hotspot value
    //! @return
    //!     True when successful
    BOOL SetDragCursorImage(INT dragImageID, INT dxHotspot, INT dyHotspot);

    //! Sets show no lock value
    //! @param[in] show
    //!     Show enabled
    //! @return
    //!     True when successful
    static BOOL DragShowNolock(BOOL show);

    //! Gets drag image list
    //! @param[in, out] ppt
    //!     Point
    //! @param[in, out] hotspot
    //!     Hot spot
    //! @return
    //!     Image List
    static HIMAGELIST GetDragImage(POINT* ppt, POINT* hotspot);

    //! Gets drag image list
    //! @param[in, out] ppt
    //!     Point
    //! @param[in, out] hotspot
    //!     Hot spot
    //! @return
    //!     Image List
    static HIMAGELIST GetDragImage(POINT& ppt, POINT& hotspot);

    //! Extracts icon
    //! @param[in] imageID
    //!     Image ID
    //! @return
    //!     Icon handle
    HICON ExtractIcon(INT imageID);

    //! Loads image list from resource
    //! @param[in] resourceID
    //!     Resource ID
    //! @param[in] cx
    //!     Image width
    //! @param[in] growCount
    //!     Amount of images when grow
    //! @param[in] mask
    //!     Color mask
    BOOL Load(uixResourceID resourceID, INT cx, INT growCount, uixColor mask);

    //! Loads image list from resource
    //! @param[in] resource
    //!     Resource name
    //! @param[in] cx
    //!     Image width
    //! @param[in] growCount
    //!     Amount of images when grow
    //! @param[in] mask
    //!     Color mask
    BOOL Load(uixResourceName resource, INT cx, INT growCount, uixColor mask);

    //! Loads image list from resource
    //! @param[in] instance
    //!     Instance handle
    //! @param[in] resourceID
    //!     Resource ID
    //! @param[in] cx
    //!     Image width
    //! @param[in] growCount
    //!     Amount of images when grow
    //! @param[in] mask
    //!     Color mask
    BOOL Load(HINSTANCE instance, uixResourceID resourceID, INT cx, INT growCount, uixColor mask);

    //! Load image list from resource
    //! @param[in] instance
    //!     Module instance
    //! @param[in] resource
    //!     Resource Name
    //! @param[in] cx
    //!     Width
    //! @param[in] growCount
    //!     Grow count
    //! @param[in] mask
    //!     Mask color
    //! @return
    //!     True when successful
    BOOL Load(HINSTANCE instance, uixResourceName resource, INT cx, INT growCount, uixColor mask);

#ifdef __IStream_INTERFACE_DEFINED__

    //! Read data from stream
    //! @param[in] stream
    //!     Stream
    //! @return
    //!     True when successful
    BOOL Read(LPSTREAM stream);

    //! Write data from stream
    //! @param[in] stream
    //!     Stream
    //! @return
    //!     True when successful
    BOOL Write(LPSTREAM stream);
#endif
    //! Gets icon size
    //! @param[out] cx
    //!     Width
    //! @param[out] cy
    //!     Height
    //! @return
    //!     True when successful
    BOOL GetIconSize(INT& cx, INT& cy);

    //! Gets icon size
    //! @param[out] cx
    //!     Width
    //! @param[out] cy
    //!     Height
    //! @return
    //!     True when successful
    BOOL SetIconSize(INT cx, INT cy);

    //! Merge two image lists
    //! @param[in] targetID
    //!     Target Image ID
    //! @param[in] imageList
    //!     Image list
    //! @param[in] sourceID
    //!     Source Image ID
    //! @param[in] dx
    //!     Delta X
    //! @param[in] dy
    //!     Delta y
    //! @return
    //!     New image list
    HIMAGELIST Merge(INT targetID, HIMAGELIST imageList, INT sourceID, INT dx, INT dy);

    //! Duplicate Image list
    //! @param[in] handle
    //!     Image List
    //! @return
    //!     Copy of image list
    static HIMAGELIST Duplicate(HIMAGELIST handle);

    //! Duplicate Image List
    //! @return
    //!     Copy of this image list
    HIMAGELIST Duplicate() const;
};
}
//----------------------------------------------------------------------------//
#include "uiximagelistctrl.inl"
//----------------------------------------------------------------------------//
#endif /* _UIX_IMAGELISTCTRL_H__ */