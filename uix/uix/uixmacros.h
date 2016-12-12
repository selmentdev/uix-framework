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
#ifndef _UIX_MACROS_H__
#define _UIX_MACROS_H__
//----------------------------------------------------------------------------//
#if defined UIX_UNICODE
#   define _(_Text) L ## _Text
#else
#   define _(_Text) _Text
#endif

#define uixUNUSED(_Symbol)
#define uixUNREFERENCED(_Symbol) (void)_Symbol

#if defined UIX_UNICODE
#   define __UIX_FILE__ __FILEW__
#   define __UIX_FUNCTION__ __FUNCTIONW__
#else
#   define __UIX_FILE__ __FILE__
#   define __UIX_FUNCTION__ __FUNCTION__
#endif

#if !defined(UIX_DEBUG)
#define UIX_NOVTABLE __declspec(novtable)
#else
#define UIX_NOVTABLE
#endif

#if defined (UIX_DEBUG)
//# define new new(_NORMAL_BLOCK, __FILE__, __LINE__)
#endif

#if _MSC_VER >= 1600
#   define NULLPTR nullptr
#else
#   define NULLPTR 0
#endif
//----------------------------------------------------------------------------//
#endif /* _UIX_MACROS_H__ */