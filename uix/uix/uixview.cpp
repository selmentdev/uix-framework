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
#include "uixview.h"
#include "uixwindowclass.h"
//----------------------------------------------------------------------------//
namespace UIX
{
//----------------------------------------------------------------------------//
uixIMPLEMENT_DYNAMIC_CLASS(uixView, uixWindow);
//----------------------------------------------------------------------------//
BOOL uixView::Create(
    uixWindow* parent,
    const uixChar* text,
    const uixPoint& position,
    const uixSize& size,
    DWORD style)
{
    return uixWindow::CreateEx(
               0,
               _("UixViewClass"),
               text,
               style,
               position.x,
               position.y,
               size.cx,
               size.cy,
               parent->GetHandle(),
               (HMENU)0);
}
//----------------------------------------------------------------------------//
BOOL uixView::BeforeTranslateMessage(MSG* m)
{
    if (uixWindow::BeforeTranslateMessage(m))
    {
        return TRUE;
    }

    //!@bug Possible bug in this code - some keystrokes may be unhandled
    if ((m->message >= WM_KEYFIRST) && (m->message <= WM_KEYLAST))
    {
        if (::IsDialogMessage(m_Handle, m))
        {
            return TRUE;
        }
    }

    return FALSE;
}
//----------------------------------------------------------------------------//
BOOL uixView::BeforeWindowCreate(CREATESTRUCT& cs)
{
    if (!uixWindow::BeforeWindowCreate(cs))
    {
        return FALSE;
    }

    cs.lpszClass = _("uixView");
    cs.style |= WS_CHILD;

    if (!uixWindowClass::TryRegister(cs.lpszClass, ::GetSysColorBrush(COLOR_BTNFACE)))
    {
        return FALSE;
    }

    return TRUE;
}
//----------------------------------------------------------------------------//
}
//----------------------------------------------------------------------------//