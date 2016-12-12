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
#include "uixuithread.h"
#include "uixstate.h"
#include "uixwindow.h"
#include "uixexceptiondlg.h"
//----------------------------------------------------------------------------//
namespace UIX
{
//----------------------------------------------------------------------------//
uixIMPLEMENT_DYNAMIC_CLASS(uixUiThread, uixThread);
//----------------------------------------------------------------------------//
uixUiThread::uixUiThread()
    : m_MainWindow(NULLPTR)
    , m_ActiveWindow(NULLPTR)
{
}
//----------------------------------------------------------------------------//
uixUiThread::~uixUiThread()
{
}
//----------------------------------------------------------------------------//
BOOL uixUiThread::PostThreadMessage(UINT message, WPARAM wParam, LPARAM lParam)
{
    return ::PostThreadMessage(m_ThreadID, message, wParam, lParam);
}
//----------------------------------------------------------------------------//
BOOL uixUiThread::InitInstance()
{
    return TRUE;
}
//----------------------------------------------------------------------------//
LRESULT uixUiThread::ExitInstance()
{
    uixThreadState& ts = uixThreadState::Get();
    return (LRESULT)ts.m_CurrentMsg.wParam;
}
//----------------------------------------------------------------------------//
LRESULT uixUiThread::Run()
{
    uixASSERT(m_MainWindow != NULLPTR);

    BOOL isIdle = TRUE;
    LONG idleCount = 0;

    uixThreadState& ts = uixThreadState::Get();
    MSG* m = &ts.m_CurrentMsg;

    for (;;)
    {
        while (isIdle && PeekMessage(m, 0, 0, 0, PM_NOREMOVE))
        {
            if (!OnIdle(idleCount++))
            {
                isIdle = FALSE;
            }
        }

        do
        {
            if (!ProcessMessage(m))
            {
                return ExitInstance();
            }

            if (IsIdleMessage(m))
            {
                isIdle = TRUE;
                idleCount = 0;
            }
        }
        while (PeekMessage(m, 0, 0, 0, PM_NOREMOVE));
    }
}
//----------------------------------------------------------------------------//
BOOL uixUiThread::BeforeTranslateMessage(MSG* m)
{
    BOOL mainCalled = FALSE;

    //!@todo Modify when uixWindow::GetParent SetParent, GetOwner SetOwner would be implemented
    for (HWND handle = m->hwnd;
         handle != 0;
         handle = ::GetParent(handle))
    {
        if ((m_MainWindow != NULLPTR) && (handle == m_MainWindow->GetHandleSafe()))
        {
            mainCalled = TRUE;
        }

        uixWindow* window = uixWindow::FromHandle(handle);
#if defined UIX_DEBUG

        if (window && (window->GetMetaClass() == &uixObject::metaClass))
        {
            OutputDebugStringA(window->GetMetaClass()->GetName());
            OutputDebugStringA("\n");
            DebugBreak();
        }

#endif

        if (window && window->BeforeTranslateMessage(m))
        {
            return TRUE;
        }
    }

    if (m_MainWindow && !mainCalled)
    {
        if (m_MainWindow->BeforeTranslateMessage(m))
        {
            return TRUE;
        }
    }

    return FALSE;
}
//----------------------------------------------------------------------------//
BOOL uixUiThread::ProcessMessage(MSG* m)
{
    if (IsWindowUnicode(m->hwnd))
    {
        if (!GetMessageW(m, 0, 0, 0))
        {
            return FALSE;
        }

        if (!BeforeTranslateMessage(m))
        {
            TranslateMessage(m);
            DispatchMessageW(m);
        }
    }
    else
    {
        if (!GetMessageA(m, 0, 0, 0))
        {
            return FALSE;
        }

        if (!BeforeTranslateMessage(m))
        {
            TranslateMessage(m);
            DispatchMessageA(m);
        }
    }

    return TRUE;
}
//----------------------------------------------------------------------------//
BOOL uixUiThread::OnIdle(LONG idleCount)
{
    uixUNREFERENCED(idleCount);
    return FALSE;
}
//----------------------------------------------------------------------------//
BOOL uixUiThread::IsIdleMessage(MSG* m)
{
    if ((m->message == WM_MOUSEMOVE) || (m->message == WM_NCMOUSEMOVE))
    {
        uixThreadState& ts = uixThreadState::Get();

        if (
            (ts.m_LastCursorPos == m->pt) &&
            (m->message == ts.m_LastMsg))
        {
            return FALSE;
        }

        ts.m_LastCursorPos = m->pt;
        ts.m_LastMsg = m->message;
        return TRUE;
    }

    return (m->message == WM_PAINT) || (m->message == 0x0118);
}
//----------------------------------------------------------------------------//
LRESULT uixUiThread::ProcessWindowProcException(uixException& e, const MSG* m)
{
    uixUNREFERENCED(e);
    uixUNREFERENCED(m);

    OnException(e);
    return 0;
}
//----------------------------------------------------------------------------//
void uixUiThread::OnException(const uixException& e)
{
    uixUNREFERENCED(e);
    uixTRACE(_("[%s]"), __UIX_FUNCTION__);

    uixExceptionDlg dlg;
    dlg.Create(m_MainWindow);
    dlg.ShowException(e);
}
//----------------------------------------------------------------------------//
}
//----------------------------------------------------------------------------//