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
#ifndef _UIX_DIAGNOSTIC_H__
#define _UIX_DIAGNOSTIC_H__
//----------------------------------------------------------------------------//
namespace UIX
{
//! Assertion method
//! @brief
//!     This method will show dialog box with information about assertion,
//!     and return user's choice about what to do
//! @return
//!     True when user want to fail execution
BOOL UIXAPI UixAssertFailed(const char* FileName, int Line);


#if defined(UIX_DEBUG)
#   define uixASSERT(_Expression) \
    ( \
      (_Expression) || \
      !UIX::UixAssertFailed(__FILE__, __LINE__) || \
      (DebugBreak(), false) \
    )

#   define uixENSURE(_Expression) \
    ( \
      (_Expression) || \
      !UIX::UixAssertFailed(__FILE__, __LINE__) || \
      ((throw UIX::uixInvalidArgumentException()), false) \
    )

#else
#   define uixASSERT(_Expression)
#   define uixENSURE(_Expression) \
    ( \
      (_Expression) || \
      ((throw UIX::uixInvalidArgumentException()), false) \
    )
#endif
}
//----------------------------------------------------------------------------//
#endif /* _UIX_DIAGNOSTIC_H__ */