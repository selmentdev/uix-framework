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
#ifndef _UIX_DUMP_H__
#define _UIX_DUMP_H__
//----------------------------------------------------------------------------//
#include "uixrequired.h"
//----------------------------------------------------------------------------//
#include "uixfilestream.h"
//----------------------------------------------------------------------------//
namespace UIX
{
//! Dump context
//! @brief
//!     This class is used to dump objects structure into stream
class UIXAPI uixDumpContext
{
public:
    //! Constructor
    //! @param[in] stream
    //!     Stream
    uixDumpContext(uixStreamPtr stream);

    //! Destructor
    ~uixDumpContext();

    //! Writes message
    //! @param[in] name
    //!     Field name
    //! @param[in] format
    //!     Format string
    void Write(const wchar_t* name, const wchar_t* format, ...);

    //! Writes message
    //! @param[in] name
    //!     Field name
    //! @param[in] format
    //!     Format string
    void Write(const char* name, const char* format, ...);

private:
    //!  Stream object
    uixStreamPtr m_Stream;
};
}
//----------------------------------------------------------------------------//
#endif /* _UIX_DUMP_H__ */