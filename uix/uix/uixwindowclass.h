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
#ifndef _UIX_WINDOWCLASS_H__
#define _UIX_WINDOWCLASS_H__
//----------------------------------------------------------------------------//
#include "uixrequired.h"
//----------------------------------------------------------------------------//
namespace UIX
{
//! Window class
//! @brief
//!     This class supports window class registering and checking
class UIXAPI uixWindowClass
{
public:
    //! Tries to register window class
    //! @param[in] className
    //!     Class name
    //! @param[in] brush
    //!     Handle to brush
    //! @param[in] style
    //!     Class style
    //! @return
    //!     True when successful
    static BOOL TryRegister(
        const uixChar* className,
        HBRUSH brush,
        UINT style = 0);

    //! Checks if class is already registered in system
    //! @param[in] className
    //!     Class name
    //! @return
    //!     True when successful
    static BOOL IsRegistered(const uixChar* className);
};
}
//----------------------------------------------------------------------------//
#endif /* _UIX_WINDOWCLASS_H__ */