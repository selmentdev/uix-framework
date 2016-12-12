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
#ifndef _UIX_GDIBITMAP_INL__
#define _UIX_GDIBITMAP_INL__
//----------------------------------------------------------------------------//
#include "uixgdibitmap.h"
#include "uixresource.h"
//----------------------------------------------------------------------------//
namespace UIX
{
//----------------------------------------------------------------------------//
UIXINLINE uixBitmap::uixBitmap(HBITMAP handle)
    : m_Handle(handle)
{
}
//----------------------------------------------------------------------------//
UIXINLINE uixBitmap::~uixBitmap()
{
    Destroy();
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixBitmap::IsValid() const
{
    uixASSERT(this != NULLPTR);
    return m_Handle != 0;
}
//----------------------------------------------------------------------------//
UIXINLINE HBITMAP uixBitmap::GetHandle() const
{
    uixASSERT(this != NULLPTR);
    return m_Handle;
}
//----------------------------------------------------------------------------//
UIXINLINE HBITMAP uixBitmap::GetHandleSafe() const
{
    if (this != NULLPTR)
    {
        return m_Handle;
    }

    return NULLPTR;
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixBitmap::Load(uixResourceName resourceName)
{
    uixASSERT(this != NULLPTR);

    return Load(
               UixFindResourceHandle(resourceName, RT_BITMAP),
               resourceName);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixBitmap::Load(uixResourceID resourceID)
{
    uixASSERT(this != NULLPTR);

    return Load(
               UixFindResourceHandle(resourceID, RT_BITMAP),
               resourceID);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixBitmap::Load(HINSTANCE instance, uixResourceName resourceName)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle == 0);

    m_Handle = ::LoadBitmap(instance, resourceName);
    return m_Handle != 0;
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixBitmap::Load(HINSTANCE instance, uixResourceID resourceID)
{
    uixASSERT(this != NULLPTR);

    return Load(instance, MAKEINTRESOURCE(resourceID));
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixBitmap::LoadFromFile(const uixChar* filename, BOOL transparent)
{
    uixASSERT(this != NULLPTR);

    UINT flags = (transparent != FALSE) ? LR_LOADTRANSPARENT : 0;
    m_Handle = (HBITMAP)::LoadImage(0, filename, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | flags);
    return m_Handle != 0;
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixBitmap::Create(INT width, INT height, UINT planes, UINT bitCount,
                                 const void* data)
{
    uixASSERT(this != NULLPTR);

    if (m_Handle != 0)
    {
        m_Handle = ::CreateBitmap(width, height, planes, bitCount, data);
        return m_Handle != 0;
    }

    return FALSE;
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixBitmap::Destroy()
{
    uixASSERT(this != NULLPTR);

    if (m_Handle != 0)
    {
        BOOL result = ::DeleteObject(m_Handle);

        if (result)
        {
            m_Handle = 0;
        }

        return result;
    }

    return TRUE;
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixBitmap::GetBitmap(BITMAP& bitmap) const
{
    uixASSERT(this != NULLPTR);

    if (m_Handle != 0)
    {
        return (INT)::GetObject(m_Handle, sizeof(BITMAP), &bitmap);
    }

    return 0;
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixBitmap::GetSize(uixSize& size) const
{
    uixASSERT(this != NULLPTR);

    if (m_Handle != 0)
    {
        BITMAP bm;

        if (GetBitmap(bm))
        {
            size.cx = bm.bmWidth;
            size.cy = bm.bmHeight;
            return TRUE;
        }
    }

    return FALSE;
}
//----------------------------------------------------------------------------//
UIXINLINE DWORD uixBitmap::GetBits(DWORD count, void* data)
{
    uixASSERT(this != NULLPTR);

    if (m_Handle != 0)
    {
        return ::GetBitmapBits(m_Handle, count, data);
    }

    return 0;
}
//----------------------------------------------------------------------------//
UIXINLINE DWORD uixBitmap::SetBits(DWORD count, const void* data)
{
    uixASSERT(this != NULLPTR);

    if (m_Handle != 0)
    {
        return ::SetBitmapBits(m_Handle, count, data);
    }

    return 0;
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixBitmap::SetDimension(INT width, INT height, uixSize* size)
{
    uixASSERT(this != NULLPTR);

    if (m_Handle != 0)
    {
        return ::SetBitmapDimensionEx(m_Handle, width, height, size);
    }

    return FALSE;
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixBitmap::CreateIndirect(const BITMAP& bitmap)
{
    uixASSERT(this != NULLPTR);

    if (m_Handle == 0)
    {
        m_Handle = ::CreateBitmapIndirect(&bitmap);
    }

    return m_Handle != 0;
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixBitmap::CreateCompatible(HDC dc, INT width, INT height)
{
    uixASSERT(this != NULLPTR);

    if (m_Handle == 0)
    {
        m_Handle = ::CreateCompatibleBitmap(dc, width, height);
    }

    return m_Handle != 0;
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixBitmap::CreateDiscardable(HDC dc, INT width, INT height)
{
    uixASSERT(this != NULLPTR);

    if (m_Handle == 0)
    {
        m_Handle = ::CreateDiscardableBitmap(dc, width, height);
    }

    return m_Handle != 0;
}
//----------------------------------------------------------------------------//
}
//----------------------------------------------------------------------------//
#endif /* _UIX_GDIBITMAP_INL__ */