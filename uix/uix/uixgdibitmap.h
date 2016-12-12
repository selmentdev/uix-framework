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
#ifndef _UIX_GDIBITMAP_H__
#define _UIX_GDIBITMAP_H__
//----------------------------------------------------------------------------//
#include "uixrequired.h"
//----------------------------------------------------------------------------//
namespace UIX
{
//! Bitmap class
//! @brief
//!     This class encapsulate all Windows API functions in one object, which
//!     represents single bitmap.
class UIXAPI uixBitmap
{
protected:
    HBITMAP m_Handle;   //!< Handle
public:
    //! Constructor
    //! @param[in] handle
    //!     Bitmap handle
    uixBitmap(HBITMAP handle = 0);

    //! Destructor
    ~uixBitmap();

    //! Checks if bitmap is valid
    //! @return
    //!     True when bitmap is valid
    BOOL IsValid() const;

    //! Gets bitmap handle
    //! @return
    //!     Bitmap handle
    HBITMAP GetHandle() const;

    //! Gets safe bitmap handle
    //! @return
    //!     Safe bitmap handle
    HBITMAP GetHandleSafe() const;

    //! Loads bitmap from resource
    //! @param[in] resourceName
    //!     Resource Name
    //! @return
    //!     True when successful
    BOOL Load(uixResourceName resourceName);

    //! Loads bitmap from resource
    //! @param[in] resourceID
    //!     Resource ID
    //! @return
    //!     True when successful
    BOOL Load(uixResourceID resourceID);

    //! Loads bitmap from resource
    //! @param[in] instance
    //!     Handle to library with resource
    //! @param[in] resourceName
    //!     Resource Name
    //! @return
    //!     True when successful
    BOOL Load(HINSTANCE instance, uixResourceName resourceName);

    //! Loads bitmap from resource
    //! @param[in] instance
    //!     Handle to library with resource
    //! @param[in] resourceID
    //!     Resource ID
    //! @return
    //!     True when successful
    BOOL Load(HINSTANCE instance, uixResourceID resourceID);

    //! Loads bitmal from file
    //! @param[in] filename
    //!     File name
    //! @param[in] transparent
    //!     Specify true to use first bitmap pixel as transparent color
    //! @return
    //!     True when successful
    BOOL LoadFromFile(const uixChar* filename, BOOL transparent = FALSE);

    //! Creates new bitmap
    //! @param[in] width
    //!     Bitmap width
    //! @param[in] height
    //!     Bitmap height
    //! @param[in] planes
    //!     Number of planes
    //! @param[in] bitCount
    //!     Bit count per pixel
    //! @param[in] data
    //!     Bitmap data pointer
    //! @return
    //!     True when successful
    BOOL Create(INT width, INT height, UINT planes, UINT bitCount, const void* data);

    //! Destroy bitmap
    //! @return
    //!     True when successful
    BOOL Destroy();

    //! Gets bitmap data
    //! @param[out] bitmap
    //!     Bitmap data
    //! @return
    //!     Flags
    INT GetBitmap(BITMAP& bitmap) const;

    //! Gets bitmap size
    //! @param[out] size
    //!     Bitmap size
    //! @return
    //!     True when sucecssful
    BOOL GetSize(uixSize& size) const;

    //! Gets bitmap bits
    //! @param[in] count
    //!     Number of bytes to get
    //! @param[out] data
    //!     Buffer for bitmap bits
    //! @return
    //!     Flags
    DWORD GetBits(DWORD count, void* data);

    //! Sets bitmap bits
    //! @param[in] count
    //!     Number of bytes to set
    //! @param[in] data
    //!     Buffer with bitmap bits
    //! @return
    //!     Flags
    DWORD SetBits(DWORD count, const void* data);

    //! Sets dimension
    //! @param[in] width
    //!     Width
    //! @param[in] height
    //!     Height
    //! @param[out] size
    //!     Pointer to previuos bitmap size
    //! @return
    //!     True when successful
    BOOL SetDimension(INT width, INT height, uixSize* size = NULLPTR);

    //! Creates new bitmap using indirect description
    //! @param[in] bitmap
    //!     Bitmap description struct
    //! @return
    //!     True when successful
    BOOL CreateIndirect(const BITMAP& bitmap);

    //! Creates compatible bitmap
    //! @param[in] dc
    //!     Device context
    //! @param[in] width
    //!     Width
    //! @param[in] height
    //!     Height
    //! @return
    //!     True when successful
    BOOL CreateCompatible(HDC dc, INT width, INT height);

    //! Creates discardable bitmap
    //! @param[in] dc
    //!     Device context
    //! @param[in] width
    //!     Width
    //! @param[in] height
    //!     Height
    //! @return
    //!     True when successful
    BOOL CreateDiscardable(HDC dc, INT width, INT height);
};
}
//----------------------------------------------------------------------------//
#include "uixgdibitmap.inl"
//----------------------------------------------------------------------------//
#endif /* _UIX_GDIBITMAP_H__ */