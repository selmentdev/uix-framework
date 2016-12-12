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
#ifndef _UIX_REQUIRED_H__
#define _UIX_REQUIRED_H__
//----------------------------------------------------------------------------//
// Windows API version
//----------------------------------------------------------------------------//
#ifndef WINVER
#define WINVER 0x0600
#endif

#ifndef _WIN32_WINNT
#define _WIN32_WINNT 0x0600     // Windows Vista at least?
#endif

#ifndef _WIN32_WINDOWS
#define _WIN32_WINDOWS 0x0410
#endif

#ifndef _WIN32_IE
#define _WIN32_IE 0x0700
#endif
//----------------------------------------------------------------------------//
// Windows Includes
//----------------------------------------------------------------------------//
#include <Windows.h>
#include <WindowsX.h>
#include <tchar.h>
#include <OAidl.h>
#include <CommCtrl.h>
#include <Shobjidl.h>
#include <Shlwapi.h>
#include <Richedit.h>
#include <Uxtheme.h>
//----------------------------------------------------------------------------//
// STL includes
//----------------------------------------------------------------------------//
#include <vector>
#include <string>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <list>
//----------------------------------------------------------------------------//
// Additional libraries
//----------------------------------------------------------------------------//
#pragma comment(lib, "comctl32.lib")
#pragma comment(lib, "gdiplus.lib")
#pragma comment(lib, "shlwapi")
#pragma comment(lib, "Msimg32.lib")
//----------------------------------------------------------------------------//
// UIX includes
//----------------------------------------------------------------------------//
#include "uixconfig.h"
#include "uixmacros.h"
#include "uixtrace.h"
#include "uixdiagnostic.h"
//----------------------------------------------------------------------------//
// Common controls manifest
//----------------------------------------------------------------------------//
#if defined _M_IX86
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='x86' publicKeyToken='6595b64144ccf1df' language='*'\"")
#elif defined _M_IA64
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='ia64' publicKeyToken='6595b64144ccf1df' language='*'\"")
#elif defined _M_X64
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='amd64' publicKeyToken='6595b64144ccf1df' language='*'\"")
#else
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")
#endif
//----------------------------------------------------------------------------//
#endif /* _UIX_REQUIRED_H__ */