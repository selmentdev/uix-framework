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
#ifndef _UIX_GDIBRUSH_H__
#define _UIX_GDIBRUSH_H__
//----------------------------------------------------------------------------//
#include "uixrequired.h"
//----------------------------------------------------------------------------//
namespace UIX
{
//! Brush hatch style
enum uixBrushHatchStyle
{
    //! Backward diagonal
    uixBrushHatchStyle_BDiagonal = HS_BDIAGONAL,
    //! Cross
    uixBrushHatchStyle_Cross = HS_CROSS,
    //! Diagonal Cross
    uixBrushHatchStyle_DiagonalCross = HS_DIAGCROSS,
    //! Forward Diagonal
    uixBrushHatchStyle_FDiagonal = HS_FDIAGONAL,
    //! Horizontal
    uixBrushHatchStyle_Horizontal = HS_HORIZONTAL,
    //! Vertical
    uixBrushHatchStyle_Vertical = HS_VERTICAL,
};

//! GDI Brush
//! @brief
//!     Brush is an GDI object, which represents color and style used for
//!     Filling background, when painting on DC's
class uixBrush
{
public:
    HBRUSH m_Handle;    //!< Handle
public:
    //! Constructor
    //! @param[in] handle
    //!     Handle
    uixBrush(HBRUSH handle = 0);

    //! Constructor
    //! @param[in] color
    //!     Brush color
    uixBrush(uixColor color);

    //! Destructor
    ~uixBrush();

    //! Gets brush handle
    //! @return
    //!     Brush handle
    HBRUSH GetHandle() const;

    //! Gets safe brush handle
    //! @return
    //!     Safe brush handle
    HBRUSH GetHandleSafe() const;

    //! Casting operator
    //! @return
    //!     Brush handle
    operator HBRUSH () const;

    //! Checks if brush is valid
    //! @return
    //!     True when brush is valid
    BOOL IsValid() const;

    //! Attach brush handle to object
    //! @param[in] handle
    //!     Handle to attach
    //! @return
    //!     This instance
    uixBrush& Attach(HBRUSH handle);

    //! Detach handle from object
    //! @return
    //!     Attached handle
    HBRUSH Detach();

    //! Creates solid brush
    //! @param[in] color
    //!     Brush color
    //! @return
    //!     True when successful
    BOOL CreateSolid(uixColor color);

    //! Creates hatch brush
    //! @param[in] style
    //!     Hatch style
    //! @param[in] color
    //!     Brush color
    //! @return
    //!     True when successful
    BOOL CreateHatch(uixBrushHatchStyle style = uixBrushHatchStyle_Vertical,
                     uixColor color = uixColor(0, 0, 0));

    //! Creates indirect brush
    //! @param[in] logbrush
    //!     Brush description
    //! @return
    //!     True when successful
    BOOL CreateIndirect(const LOGBRUSH& logbrush);

    //! Creates brush using bitmap pattern
    //! @param[in] bitmap
    //!     Handle to bitmap
    //! @return
    //!     True when successful
    BOOL CreatePattern(HBITMAP bitmap);

    //! Creates brush using system color
    //! @param[in] color
    //!     System color index
    //! @return
    //!     True when successful
    BOOL CreateSystemColor(uixSystemColor color);

    //! Deletes object
    //! @return
    //!     True when successful
    BOOL DeleteObject();

    //! Gets log brush data
    //! @param[out] logbrush
    //!     Brush data
    //! @return
    //!     Flags
    INT GetLogBrush(LOGBRUSH& logbrush);
};
}
//----------------------------------------------------------------------------//
#include "uixgdibrush.inl"
//----------------------------------------------------------------------------//
#endif /* _UIX_GDIBRUSH_H__ */