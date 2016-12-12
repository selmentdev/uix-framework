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
#ifndef _UIX_IMAGELISTCTRL_INL__
#define _UIX_IMAGELISTCTRL_INL__
//----------------------------------------------------------------------------//
#include "uiximagelistctrl.h"
#include "uixresource.h"
//----------------------------------------------------------------------------//
namespace UIX
{
//----------------------------------------------------------------------------//
UIXINLINE uixImageListCtrl::uixImageListCtrl(HIMAGELIST handle)
    : m_Handle(handle)
{
}
//----------------------------------------------------------------------------//
UIXINLINE uixImageListCtrl::~uixImageListCtrl()
{
    Destroy();
}
//----------------------------------------------------------------------------//
UIXINLINE uixImageListCtrl::operator HIMAGELIST()
{
    return m_Handle;
}
//----------------------------------------------------------------------------//
UIXINLINE HIMAGELIST uixImageListCtrl::GetHandle() const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);

    return m_Handle;
}
//----------------------------------------------------------------------------//
UIXINLINE HIMAGELIST uixImageListCtrl::GetHandleSafe() const
{
    if (this != NULLPTR)
    {
        return m_Handle;
    }

    return 0;
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixImageListCtrl::Create(INT cx, INT cy, UINT flags, INT initialCount, INT growCount)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle == 0);

    m_Handle = ImageList_Create(cx, cy, flags, initialCount, growCount);

    return m_Handle != 0;
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixImageListCtrl::Create(uixResourceName bitmap, INT cx, INT growCount,
                                        uixColor mask)
{
    return Create(
               UixFindResourceHandle(bitmap, RT_BITMAP),
               bitmap,
               cx,
               growCount,
               mask);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixImageListCtrl::Create(uixResourceID bitmapID, INT cx, INT growCount,
                                        uixColor mask)
{
    return Create(
               UixFindResourceHandle(bitmapID, RT_BITMAP),
               bitmapID,
               cx,
               growCount,
               mask);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixImageListCtrl::Create(HINSTANCE instance, uixResourceID bitmapID, INT cx,
                                        INT growCount, uixColor mask)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle == 0);

    return Create(instance, MAKEINTRESOURCE(bitmapID), cx, growCount, mask);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixImageListCtrl::Create(HINSTANCE instance, uixResourceName resource, INT cx,
                                        INT growCount, uixColor mask)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle == 0);

    m_Handle = ImageList_LoadBitmap(instance, resource, cx, growCount, mask);

    return m_Handle != 0;
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixImageListCtrl::CreateColor(uixResourceID resourceID, SIZE buttonSize, INT btnini)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle == 0);

    return CreateColor(
               UixFindResourceHandle(resourceID, RT_BITMAP),
               resourceID,
               buttonSize,
               btnini);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixImageListCtrl::CreateColor(uixResourceName resource, SIZE buttonSize, INT btnini)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle == 0);

    return CreateColor(
               UixFindResourceHandle(resource, RT_BITMAP),
               resource,
               buttonSize,
               btnini);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixImageListCtrl::CreateColor(HINSTANCE instance, uixResourceID resourceID,
        SIZE buttonSize, INT btnini)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle == 0);

    return CreateColor(
               instance,
               MAKEINTRESOURCE(resourceID),
               buttonSize,
               btnini);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixImageListCtrl::CreateColor(HINSTANCE instance, uixResourceName resource,
        SIZE buttonSize, INT btnini)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle == 0);

    BITMAP bmp = {0};
    HGDIOBJ handle = ::LoadImage(instance, resource, IMAGE_BITMAP, 0, 0,
                                 LR_DEFAULTSIZE | LR_CREATEDIBSECTION);
    ::GetObject(handle, sizeof(BITMAP), &bmp);
    RGBTRIPLE* rgb = (RGBTRIPLE*)bmp.bmBits;

    if (btnini == -1)
    {
        btnini = bmp.bmWidth / bmp.bmBitsPixel;
    }

    WORD colorBits = (WORD)(bmp.bmPlanes * bmp.bmBitsPixel);

    if (colorBits == 1)
    {
        colorBits = 1;
    }
    else if (colorBits <= 4)
    {
        colorBits = ILC_COLOR4;
    }
    else if (colorBits <= 8)
    {
        colorBits = ILC_COLOR8;
    }
    else if (colorBits <= 16)
    {
        colorBits = ILC_COLOR16;
    }
    else if (colorBits <= 24)
    {
        colorBits = ILC_COLOR24;
    }
    else
    {
        colorBits = ILC_COLOR32;
    }

    if (!Create(buttonSize.cx, buttonSize.cy, colorBits | ILC_MASK, btnini, 0))
    {
        return FALSE;
    }

    if (AddMasked((HBITMAP)handle, uixColor(rgb[0].rgbtRed, rgb[0].rgbtGreen, rgb[0].rgbtBlue)) == -1)
    {
        return FALSE;
    }

    return TRUE;
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixImageListCtrl::Destroy()
{
    uixASSERT(this != NULLPTR);

    if (m_Handle != 0)
    {
        BOOL result = ImageList_Destroy(m_Handle);

        if (result)
        {
            m_Handle = 0;
        }

        return result;
    }

    return FALSE;
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixImageListCtrl::Attach(HIMAGELIST handle)
{
    uixASSERT(this != NULLPTR);

    if (m_Handle == 0)
    {
        m_Handle = handle;
    }

    return m_Handle == handle;
}
//----------------------------------------------------------------------------//
UIXINLINE HIMAGELIST uixImageListCtrl::Detach()
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);

    HIMAGELIST handle = m_Handle;
    m_Handle = 0;
    return handle;
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixImageListCtrl::GetImageCount() const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);

    return ImageList_GetImageCount(m_Handle);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixImageListCtrl::GetImageInfo(INT imageID, IMAGEINFO& ii)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);
    return ImageList_GetImageInfo(m_Handle, imageID, &ii);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixImageListCtrl::SetImageCount(UINT newCount)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);

    return (BOOL)ImageList_SetImageCount(m_Handle, newCount) != 0;
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixImageListCtrl::Add(HBITMAP image, HBITMAP mask)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);

    return ImageList_Add(m_Handle, image, mask);
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixImageListCtrl::AddMasked(HBITMAP image, uixColor mask)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);

    return ImageList_AddMasked(m_Handle, image, mask);
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixImageListCtrl::ReplaceIcon(INT imageID, HICON icon)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);

    return ImageList_ReplaceIcon(m_Handle, imageID, icon);
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixImageListCtrl::AddIcon(HICON icon)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);

    return ImageList_AddIcon(m_Handle, icon);
}
//----------------------------------------------------------------------------//
UIXINLINE uixColor uixImageListCtrl::SetBackgroundColor(uixColor color)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);

    return ImageList_SetBkColor(m_Handle, color);
}
//----------------------------------------------------------------------------//
UIXINLINE uixColor uixImageListCtrl::GetBackgroundColor() const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);

    return ImageList_GetBkColor(m_Handle);
}
//----------------------------------------------------------------------------//
UIXINLINE uixColor uixImageListCtrl::SetOverlayImage(INT imageID, INT overlayID)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);

    return ImageList_SetOverlayImage(m_Handle, imageID, overlayID);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixImageListCtrl::Draw(INT imageID, HDC dc, INT x, INT y,
                                      uixImageListDrawStyle style)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);

    return ImageList_Draw(m_Handle, imageID, dc, x, y, style);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixImageListCtrl::Draw(INT imageID, HDC dc, POINT pt, uixImageListDrawStyle style)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);

    return ImageList_Draw(m_Handle, imageID, dc, pt.x, pt.y, style);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixImageListCtrl::Replace(INT indexID, HBITMAP image, HBITMAP mask)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);

    return ImageList_Replace(m_Handle, indexID, image, mask);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixImageListCtrl::DrawEx(INT imageID, HDC dc, INT x, INT y, INT dx, INT dy,
                                        uixColor background, uixColor foreground, uixImageListDrawStyle style)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);

    return ImageList_DrawEx(m_Handle, imageID, dc, x, y, dx, dy, background, foreground, style);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixImageListCtrl::DrawIndirect(IMAGELISTDRAWPARAMS& imldp)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);

    return ImageList_DrawIndirect(&imldp);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixImageListCtrl::Remove(INT imageID)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);

    return ImageList_Remove(m_Handle, imageID);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixImageListCtrl::Clear()
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);

    return ImageList_RemoveAll(m_Handle);
}
//----------------------------------------------------------------------------//
UIXINLINE HICON uixImageListCtrl::GetIcon(INT imageID, uixImageListDrawStyle flags)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);

    return ImageList_GetIcon(m_Handle, imageID, flags);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixImageListCtrl::Copy(INT targetID, HIMAGELIST iml, INT sourceID, UINT flags)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);
    uixASSERT(iml != 0);

    return ImageList_Copy(m_Handle, targetID, iml, sourceID, flags);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixImageListCtrl::Copy(INT targetID, INT sourceID, UINT flags)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);

    return ImageList_Copy(m_Handle, targetID, m_Handle, sourceID, flags);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixImageListCtrl::BeginDrag(INT trackImageID, INT dxHotspot, INT dyHotspot)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);

    return ImageList_BeginDrag(m_Handle, trackImageID, dxHotspot, dyHotspot);
}
//----------------------------------------------------------------------------//
UIXINLINE void uixImageListCtrl::EndDrag()
{
    ImageList_EndDrag();
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixImageListCtrl::DragEnter(HWND window, INT x, INT y)
{
    uixASSERT(::IsWindow(window));
    return ImageList_DragEnter(window, x, y);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixImageListCtrl::DragLeave(HWND window)
{
    uixASSERT(::IsWindow(window));
    return ImageList_DragLeave(window);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixImageListCtrl::DragMove(INT x, INT y)
{
    return ImageList_DragMove(x, y);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixImageListCtrl::SetDragCursorImage(INT dragImageID, INT dxHotspot, INT dyHotspot)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);

    return ImageList_SetDragCursorImage(m_Handle, dragImageID, dxHotspot, dyHotspot);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixImageListCtrl::DragShowNolock(BOOL show)
{
    return ImageList_DragShowNolock(show);
}
//----------------------------------------------------------------------------//
UIXINLINE HIMAGELIST uixImageListCtrl::GetDragImage(POINT* ppt, POINT* hotspot)
{
    return ImageList_GetDragImage(ppt, hotspot);
}
//----------------------------------------------------------------------------//
UIXINLINE HIMAGELIST uixImageListCtrl::GetDragImage(POINT& ppt, POINT& hotspot)
{
    return ImageList_GetDragImage(&ppt, &hotspot);
}
//----------------------------------------------------------------------------//
UIXINLINE HICON uixImageListCtrl::ExtractIcon(INT imageID)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);

    return GetIcon(imageID, 0);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixImageListCtrl::Load(uixResourceID resourceID, INT cx, INT growCount,
                                      uixColor mask)
{
    uixASSERT(this != NULLPTR);

    return Load(
               UixFindResourceHandle(resourceID, RT_BITMAP),
               resourceID,
               cx,
               growCount,
               mask);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixImageListCtrl::Load(uixResourceName resource, INT cx, INT growCount,
                                      uixColor mask)
{
    uixASSERT(this != NULLPTR);

    return Load(
               UixFindResourceHandle(resource, RT_BITMAP),
               resource,
               cx,
               growCount,
               mask);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixImageListCtrl::Load(HINSTANCE instance, uixResourceID resourceID, INT cx,
                                      INT growCount, uixColor mask)
{
    uixASSERT(this != NULLPTR);

    return Attach(ImageList_LoadBitmap(instance, MAKEINTRESOURCE(resourceID), cx, growCount, mask));
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixImageListCtrl::Load(HINSTANCE instance, uixResourceName resource, INT cx,
                                      INT growCount, uixColor mask)
{
    uixASSERT(this != NULLPTR);

    return Attach(ImageList_LoadBitmap(instance, resource, cx, growCount, mask));
}
//----------------------------------------------------------------------------//
#ifdef __IStream_INTERFACE_DEFINED__
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixImageListCtrl::Read(LPSTREAM stream)
{
    return Attach(ImageList_Read(stream));
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixImageListCtrl::Write(LPSTREAM stream)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);

    return ImageList_Write(m_Handle, stream);
}
//----------------------------------------------------------------------------//
#endif
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixImageListCtrl::GetIconSize(INT& cx, INT& cy)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);

    return ImageList_GetIconSize(m_Handle, &cx, &cy);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixImageListCtrl::SetIconSize(INT cx, INT cy)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);

    return ImageList_SetIconSize(m_Handle, cx, cy);
}
//----------------------------------------------------------------------------//
UIXINLINE HIMAGELIST uixImageListCtrl::Merge(INT targetID, HIMAGELIST imageList, INT sourceID,
        INT dx, INT dy)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);
    uixASSERT(imageList != 0);

    return ImageList_Merge(m_Handle, targetID, imageList, sourceID, dx, dy);
}
//----------------------------------------------------------------------------//
UIXINLINE HIMAGELIST uixImageListCtrl::Duplicate(HIMAGELIST handle)
{
    if (handle != 0)
    {
        return ImageList_Duplicate(handle);
    }

    return 0;
}
//----------------------------------------------------------------------------//
UIXINLINE HIMAGELIST uixImageListCtrl::Duplicate() const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);

    return Duplicate(m_Handle);
}
//----------------------------------------------------------------------------//
}
//----------------------------------------------------------------------------//
#endif /* _UIX_IMAGELISTCTRL_INL__ */