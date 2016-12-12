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
#ifndef _UIX_GDIPEN_H__
#define _UIX_GDIPEN_H__
//----------------------------------------------------------------------------//
#include "uixrequired.h"
//----------------------------------------------------------------------------//
namespace UIX
{
//! Pen style
enum uixPenStyle
{
    uixPenStyle_None = PS_NULL,
    uixPenStyle_Solid = PS_SOLID,
    uixPenStyle_Dash = PS_DASH,
    uixPenStyle_Dot = PS_DOT,
    uixPenStyle_DashDot = PS_DASHDOT,
    uixPenStyle_DashDotDot = PS_DASHDOTDOT,
    uixPenStyle_InsideFrame = PS_INSIDEFRAME,
};

//! GDI Pen
//! @brief
//!     This object represents GDI pen
class uixPen
{
public:
    HPEN m_Handle;  //!< Pen handle
public:
    //! Constructor
    //! @param[in] handle
    //!     Pen handle
    uixPen(HPEN handle = 0);

    //! Destructor
    ~uixPen();

    //! Checks if pen is valid
    //! @return
    //!     True when successful
    BOOL IsValid() const;

    //! Gets pen handle
    //! @return
    //!     Pen handle
    HPEN GetHandle();

    //! Gets safe pen handle
    //! @return
    //!     Safe pen handle
    HPEN GetHandleSafe();

    //! Pen handle cast operator
    //! @return
    //!     Pen handle
    operator HPEN ();

    //! Creates new pen
    //! @param[in] style
    //!     Pen style
    //! @param[in] width
    //!     Pen width
    //! @param[in] color
    //!     Pen color
    //! @return
    //!     True when successful
    BOOL Create(uixPenStyle style = uixPenStyle_Solid, INT width = 1, uixColor color = uixColor(0, 0,
                0));

    //! Creates pen
    //! @param[in] params
    //!     Brush
    //! @param[in] style
    //!     Pen style
    //! @param[in] width
    //!     Pen width
    //! @param[in] styleCount
    //!     Style count
    //! @param[out] styleData
    //!     Style data
    //! @return
    //!     True when successful
    BOOL CreateExt(const LOGBRUSH& params, uixPenStyle style = uixPenStyle_Solid, INT width = 1,
                   INT styleCount = 0, DWORD* styleData = NULLPTR);

    //! Create pen indirect
    //! @param[in] params
    //!     Pen params
    //! @return
    //!     True when successful
    BOOL CreateIndirect(const LOGPEN& params);

    //! Delete pen object
    //! @return
    //!     True when successful
    BOOL DeleteObject();

    //! Gets pen data
    //! @param[out] logpen
    //!     Pen data
    //! @return
    //!     Flags
    INT GetLogPen(LOGPEN& logpen);

    //! Gets extended pen data
    //! @param[out] logpen
    //!     Pen data
    //! @return
    //!     Flags
    INT GetExtLogPen(EXTLOGPEN& logpen);
};
}
//----------------------------------------------------------------------------//
#include "uixgdipen.inl"
//----------------------------------------------------------------------------//
#endif /* _UIX_GDIPEN_H__ */