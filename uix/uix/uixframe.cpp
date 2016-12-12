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
#include "uixframe.h"
#include "uixwindowclass.h"
#include "uixresource.h"
//----------------------------------------------------------------------------//
namespace UIX
{
//----------------------------------------------------------------------------//
uixBEGIN_EVENT_MAP(uixFrame, uixWindow)
uixEVT_CLOSE()
uixEND_EVENT_MAP()
//----------------------------------------------------------------------------//
uixIMPLEMENT_DYNAMIC_CLASS(uixFrame, uixWindow)
//----------------------------------------------------------------------------//
uixFrame::uixFrame()
    : m_AccelTable(NULLPTR)
    , m_View(NULLPTR)
{
}
//----------------------------------------------------------------------------//
uixFrame::~uixFrame()
{
    DestroyWindow();
}
//----------------------------------------------------------------------------//
BOOL uixFrame::CreateFrame()
{
    uixASSERT(this != NULLPTR);

    return uixWindow::CreateEx(
               0,
               NULLPTR,
               NULLPTR,
               0,
               CW_USEDEFAULT,
               CW_USEDEFAULT,
               CW_USEDEFAULT,
               CW_USEDEFAULT,
               0,
               0);
}
//----------------------------------------------------------------------------//
BOOL uixFrame::CreateFrame(const uixChar* caption)
{
    uixASSERT(this != NULLPTR);

    return uixWindow::CreateEx(
               0,
               NULLPTR,
               caption,
               0,
               CW_USEDEFAULT,
               CW_USEDEFAULT,
               CW_USEDEFAULT,
               CW_USEDEFAULT,
               0,
               0);
}
//----------------------------------------------------------------------------//
BOOL uixFrame::LoadAccelTable(uixResourceID accelID)
{
    uixASSERT(this != NULLPTR);

    return LoadAccelTable(
               UixFindResourceHandle(accelID, RT_ACCELERATOR),
               MAKEINTRESOURCE(accelID));
}
//----------------------------------------------------------------------------//
BOOL uixFrame::LoadAccelTable(uixResourceName accelName)
{
    uixASSERT(this != NULLPTR);

    return LoadAccelTable(
               UixFindResourceHandle(accelName, RT_ACCELERATOR),
               accelName);
}
//----------------------------------------------------------------------------//
BOOL uixFrame::LoadAccelTable(HINSTANCE instance, uixResourceID accelID)
{
    uixASSERT(this != NULLPTR);

    return LoadAccelTable(instance, MAKEINTRESOURCE(accelID));
}
//----------------------------------------------------------------------------//
BOOL uixFrame::LoadAccelTable(HINSTANCE instance, uixResourceName accelName)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(accelName != NULLPTR);
    uixASSERT(m_AccelTable == NULLPTR);

    m_AccelTable = ::LoadAccelerators(instance, accelName);
    return m_AccelTable != NULLPTR;
}
//----------------------------------------------------------------------------//
BOOL uixFrame::BeforeTranslateMessage(MSG* m)
{
    uixASSERT(this != NULLPTR);

    if (uixWindow::BeforeTranslateMessage(m))
    {
        return TRUE;
    }

    //!@bug Possible bug in this code - some keystrokes may be unhandled
    if ((m->message >= WM_KEYFIRST) && (m->message <= WM_KEYLAST))
    {
        if (::IsDialogMessage(m_Handle, m))
        {
            HACCEL accel = m_AccelTable;

            if (accel != NULLPTR)
            {
                // But maybe it is an accelerator?
                return !::TranslateAccelerator(m_Handle, accel, m);
            }

            // Dialog msg anyway..
            return TRUE;
        }
    }

    return FALSE;
}
//----------------------------------------------------------------------------//
BOOL uixFrame::BeforeWindowCreate(CREATESTRUCT& cs)
{
    uixASSERT(this != NULLPTR);

    if (!uixWindow::BeforeWindowCreate(cs))
    {
        return FALSE;
    }

    cs.lpszClass = _("uixFrame");
    BOOL ok = uixWindowClass::TryRegister(
                  cs.lpszClass,
                  ::GetSysColorBrush(COLOR_BTNFACE));

    cs.style |= WS_SYSMENU | WS_MAXIMIZEBOX | WS_MINIMIZEBOX | WS_OVERLAPPEDWINDOW;

    return ok;
}
//----------------------------------------------------------------------------//
void uixFrame::OnClose(uixCloseEventArgs& e)
{
    uixASSERT(this != NULLPTR);

    PostQuitMessage(0);
    uixWindow::OnClose(e);
}
//----------------------------------------------------------------------------//
}
//----------------------------------------------------------------------------//