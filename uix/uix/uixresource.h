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
#ifndef _UIX_RESOURCE_H__
#define _UIX_RESOURCE_H__
//----------------------------------------------------------------------------//
#include "uixstate.h"
//----------------------------------------------------------------------------//
namespace UIX
{
//! @remarks
//!     Naming convention
//!     _CURSOR_ - cursor
//!     _BITMAP_ - bitmap
//!     _ICON_ - icon
//!     _MENU_ - menu
//!     _DIALOG_ - dialog
//!     _STRING_ - string, localizable
//!     _FONTDIR_ - font directory
//!     _FONT_ - font
//!     _ACCELERATOR_ - accelerator
//!     _RCDATA_ - resource data
//!     _MSGTABLE_ - message table
//!     _GRPCURSOR_ - group cursor
//!     _GRPICON_ - group icon
//!     _VERSION_ - version
//!     _DLGINC_ - dialog include
//!     _PLUGPLAY_ - plug and play
//!     _ANICURSOR_ - animated cursor
//!     _ANIICON_ - animated icon
//!     _HTML_ - html
//!     _MANIFEST_ - manifest
//!     _TOOLBAR_ - toolbar

//! Finds resource module handle
//! @remarks
//!     Finds module with (probably) newest version of resource
//! @param[in] id
//!     Resource ID
//! @param[in] type
//!     Resource type
//! @return
//!     Instance handle
HINSTANCE UIXAPI UixFindResourceHandle(uixResourceID id, UINT type);

//! Finds resource module handle
//! @remarks
//!     Finds module with (probably) newest version of resource
//! @param[in] name
//!     Resource name
//! @param[in] type
//!     Resource type
//! @return
//!     Instance handle
HINSTANCE UIXAPI UixFindResourceHandle(uixResourceName name, UINT type);

//! Finds resource module handle
//! @remarks
//!     Finds module with (probably) newest version of resource
//! @param[in] id
//!     Resource ID
//! @param[in] type
//!     Resource type
//! @return
//!     Instance handle
HINSTANCE UIXAPI UixFindResourceHandle(uixResourceID id, const uixChar* type);

//! Finds resource module handle
//! @remarks
//!     Finds module with (probably) newest version of resource
//! @param[in] name
//!     Resource name
//! @param[in] type
//!     Resource type
//! @return
//!     Instance handle
HINSTANCE UIXAPI UixFindResourceHandle(uixResourceName name, const uixChar* type);

//! Locks resource
//! @param[in] resourceData
//!     Resource data
//! @return
//!     Pointer to locked resource
UIXAPI void* UixLockResource(HGLOBAL resourceData);

//! Unlocks resource
//! @param[in] resourceData
//!     Resource data
void UIXAPI UixUnlockResource(HGLOBAL resourceData);

//! Finds resource
//! @param[in] instance
//!     Module instance handle
//! @param[in] resource
//!     Resource name
//! @param[in] type
//!     Resource type
//! @return
//!     Resource handle
HRSRC UIXAPI UixFindResource(HINSTANCE instance, uixResourceName resource, const uixChar* type);

//! Finds resource
//! @param[in] instance
//!     Module instance handle
//! @param[in] resource
//!     Resource ID
//! @param[in] type
//!     Resource type
//! @return
//!     Resource handle
HRSRC UIXAPI UixFindResource(HINSTANCE instance, uixResourceID resource, UINT typeID);

//! Loads resource
//! @param[in] instance
//!     Module instance
//! @param[in] resource
//!     Resource handle
//! @return
//!     Resource data
HGLOBAL UIXAPI UixLoadResource(HINSTANCE instance, HRSRC resource);

//! Loads icon
//! @param[in] instance
//!     Module instance
//! @param[in] iconID
//!     Icon ID
//! @return
//!     Icon handle
HICON UIXAPI UixLoadIcon(HINSTANCE instance, uixResourceID iconID);

//! Loads icon
//! @param[in] instance
//!     Module instance
//! @param[in] iconName
//!     Icon name
//! @return
//!     Icon handle
HICON UIXAPI UixLoadIcon(HINSTANCE instance, uixResourceName iconName);

//! Loads icon
//! @param[in] iconID
//!     Icon ID
//! @return
//!     Icon handle
HICON UIXAPI UixLoadIcon(uixResourceID iconID);

//! Loads icon
//! @param[in] iconName
//!     Icon name
//! @return
//!     Icon handle
HICON UIXAPI UixLoadIcon(uixResourceName iconName);

//! Loads image
//! @param[in] instance
//!     Module instance
//! @param[in] imageID
//!     Image ID
//! @return
//!     Image handle
HBITMAP UIXAPI UixLoadImage(HINSTANCE instance, uixResourceID imageID);

//! Loads image
//! @param[in] instance
//!     Module instance
//! @param[in] imageName
//!     Image name
//! @return
//!     Image handle
HBITMAP UIXAPI UixLoadImage(HINSTANCE instance, uixResourceName imageName);

//! Loads image
//! @param[in] imageID
//!     Image ID
//! @return
//!     Image handle
HBITMAP UIXAPI UixLoadImage(uixResourceID imageID);

//! Loads image
//! @param[in] imageName
//!     Image name
//! @return
//!     Image handle
HBITMAP UIXAPI UixLoadImage(uixResourceName imageName);

//! Loads library
//! @param[in] libFileName
//!     Library file name
//! @return
//!     Instance handle to loaded library
HINSTANCE UIXAPI UixLoadLibrary(const uixChar* libFileName);

//! Frees loaded library
//! @param[in] instance
//!     Handle of loaded library
//! @return
//!     True when successful
BOOL UIXAPI UixFreeLibrary(HINSTANCE instance);

//! Loads string from resources
//! @param[in] resourceID
//!     Resource ID
//! @return
//!     Loaded string
uixString UIXAPI UixLoadString(uixResourceID resourceID);
}
//----------------------------------------------------------------------------//
#endif /* _UIX_RESOURCE_H__ */