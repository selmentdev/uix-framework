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
#ifndef _UIX_GDIFONT_H__
#define _UIX_GDIFONT_H__
//----------------------------------------------------------------------------//
#include "uixrequired.h"
//----------------------------------------------------------------------------//
namespace UIX
{
//! GDI Font object
//! @brief
//!     This object represents GDI font
class uixFont
{
public:
    HFONT   m_Handle;   //!< Font handle
public:
    //! Constructor
    //! @param[in] handle
    //!     Font handle
    uixFont(HFONT handle = 0);

    //! Destructor
    ~uixFont();

    //! Handle cast operator
    //! @return
    //!     Font handle
    operator HFONT();

    //! Gets handle
    //! @return
    //!     Font handle
    HFONT GetHandle();

    //! Gets safe font handle
    //! @return
    //!     Safe font handle
    HFONT GetHandleSafe() const;

    //! Attachs font handle
    //! @param[in] handle
    //!     Font handle
    //! @return
    //!     This object
    uixFont& Attach(HFONT handle);

    //! Detachs font handle
    //! @return
    //!     Attached font handle
    HFONT Detach();

    //! Deletes font object
    //! @return
    //!     True when successful
    BOOL DeleteObject();

    //! Creates indirect font
    //! @param[in] params
    //!     Creation params
    //! @return
    //!     True when successful
    BOOL CreateIndirect(const LOGFONT* params);

    //! Creates font
    //! @param[in] height
    //!     Font height
    //! @param[in] width
    //!     Font width
    //! @param[in] escapement
    //!     Escapement
    //! @param[in] orientation
    //!     Orientation
    //! @param[in] weight
    //!     Weight
    //! @param[in] italic
    //!     Italic
    //! @param[in] underline
    //!     Underline
    //! @param[in] strikeOut
    //!     Strike out
    //! @param[in] charSet
    //!     Charset
    //! @param[in] outPrecision
    //!     Out precision
    //! @param[in] clipPrecision
    //!     Clip precision
    //! @param[in] quality
    //!     Quality
    //! @param[in] pitchAndFamily
    //!     Pitch and family
    //! @param[in] facename
    //!     Face name
    //! @return
    //!     True when successful
    BOOL Create(INT height, INT width, INT escapement, INT orientation, INT weight,
                BYTE italic, BYTE underline, BYTE strikeOut, BYTE charSet, BYTE outPrecision,
                BYTE clipPrecision, BYTE quality, BYTE pitchAndFamily, const uixChar* facename);

    //! Gets font from stock
    //! @param[in] index
    //!     Stock font index
    //! @return
    //!     True when successful
    BOOL GetStock(INT index);

    //! Gets log font
    //! @param[in] params
    //!     Pointer to logfont
    //! @return
    //!     Flags
    INT GetLogFont(LOGFONT* params);

    //! Gets log font
    //! @param[in] params
    //!     Logfont
    //! @return
    //!     True when successful
    BOOL GetLogFont(LOGFONT& params);
};
}
//----------------------------------------------------------------------------//
#include "uixgdifont.inl"
//----------------------------------------------------------------------------//
#endif /* _UIX_GDIFONT_H__ */