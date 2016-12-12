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
#ifndef _UIX_CONFIG_H__
#define _UIX_CONFIG_H__
//----------------------------------------------------------------------------//
#if defined(DEBUG) || !defined(NDEBUG)
#   define UIX_DEBUG
#endif

#if defined(UIX_DLL)
#   if defined(UIX_EXPORTS)
#       define UIXAPI __declspec(dllexport)
#   else
#       define UIXAPI __declspec(dllimport)
#   endif
#else
#   define UIXAPI
#endif

#define UIXEXC extern "C"

#if defined(UNICODE)
#   define UIX_UNICODE
#endif

#if !defined(_MSC_VER) || (_MSC_VER < 1500)
#   define override
#endif

#define UIXINLINE inline

#pragma warning (disable: 4100)
#pragma warning (disable: 4201)
#pragma warning (disable: 4355)
//warning C4251: 'X' : class 'Y' needs to have dll-interface to be used by clients of class 'Z'
#pragma warning (disable: 4251)
#pragma warning (disable: 4481)
//----------------------------------------------------------------------------//
#endif /* _UIX_CONFIG_H__ */