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
#include "uixwindowclass.h"
#include "uixstate.h"
//----------------------------------------------------------------------------//
namespace UIX
{
//----------------------------------------------------------------------------//
BOOL uixWindowClass::TryRegister(
    const uixChar* className,
    HBRUSH brush,
    UINT style
)
{
    HINSTANCE app = uixProcessState::Get().m_Handle;

    // Class data
    WNDCLASSEX wcex;

    if (::GetClassInfoEx(app, className, &wcex))
    {
        // class already registered
        return TRUE;
    }

    // Fill data
    wcex.cbSize         = sizeof(wcex);
    wcex.style          = style;
    wcex.lpfnWndProc    = DefWindowProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = app;
    wcex.hIcon          = ::LoadIcon(0, MAKEINTRESOURCE(IDI_APPLICATION));
    wcex.hCursor        = ::LoadCursor(0, MAKEINTRESOURCE(IDC_ARROW));
    wcex.hbrBackground  = brush;
    wcex.lpszMenuName   = 0;
    wcex.lpszClassName  = className;
    wcex.hIconSm        = wcex.hIcon;

    // and register class
    if (!::RegisterClassEx(&wcex))
    {
        return FALSE;
    }

    return TRUE;
}
//----------------------------------------------------------------------------//
BOOL uixWindowClass::IsRegistered(const uixChar* className)
{
    WNDCLASSEX wcex;
    return ::GetClassInfoEx(
               uixProcessState::Get().m_Handle,
               className,
               &wcex);
}
//----------------------------------------------------------------------------//
}
//----------------------------------------------------------------------------//