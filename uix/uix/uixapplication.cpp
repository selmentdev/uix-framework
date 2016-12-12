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
#include "uixapplication.h"
#include "uixstate.h"
#include "uixwindow.h"
#include "uixinit.h"
//----------------------------------------------------------------------------//
namespace UIX
{
//----------------------------------------------------------------------------//
uixIMPLEMENT_DYNAMIC_CLASS(uixApplication, uixUiThread);
//----------------------------------------------------------------------------//
uixApplication::uixApplication()
    : uixUiThread()
    , m_Instance(0)
    , m_RichEditModule(0)
{
    // Gets current thread data
    m_ThreadHandle = ::GetCurrentThread();
    m_ThreadID = ::GetCurrentThreadId();

    // Gets ThreadState
    uixThreadState& ts = uixThreadState::Get();
    ts.m_CurrentThread = this;

    // Set current application
    uixASSERT(UixGetCurrentApp() == NULLPTR);
    UixGetProcessState().m_Application = this;
    uixASSERT(UixGetCurrentApp() == this);
}
//----------------------------------------------------------------------------//
uixApplication::~uixApplication()
{
    // Clear current application
    uixASSERT(uixThreadState::Get().m_CurrentThread == this);
}
//----------------------------------------------------------------------------//
BOOL uixApplication::InitInstance()
{
    uixASSERT(this != NULLPTR);

    // Initialize all common controls
    INITCOMMONCONTROLSEX iccs;
    iccs.dwSize = sizeof(iccs);
    iccs.dwICC = 0xffff;
    InitCommonControlsEx(&iccs);

    // And network address control
    InitNetworkAddressControl();

    // And Rich Edit control
    m_RichEditModule = ::LoadLibrary(_("msftedit.dll"));

    return uixUiThread::InitInstance();
}
//----------------------------------------------------------------------------//
LRESULT uixApplication::ExitInstance()
{
    uixASSERT(this != NULLPTR);

    if (m_ActiveWindow != NULLPTR)
    {
        m_ActiveWindow = NULLPTR;
    }

    if (m_MainWindow != NULLPTR)
    {
        m_MainWindow = NULLPTR;
    }

    // Free RichEdit module library if loaded
    if (m_RichEditModule)
    {
        ::FreeLibrary(m_RichEditModule);
        m_RichEditModule = 0;
    }

    return uixUiThread::ExitInstance();
}
//----------------------------------------------------------------------------//
LRESULT uixApplication::Run()
{
    uixASSERT(this != NULLPTR);

    // Ensure that we have main window
    uixENSURE(m_MainWindow != NULLPTR);

    if (m_MainWindow == NULLPTR)
    {
        // Otherwise exit
        uixTRACE(_("[%s] no main window set"), __UIX_FUNCTION__);
        PostQuitMessage(0);
    }

    return uixUiThread::Run();
}
//----------------------------------------------------------------------------//
void uixApplication::OnException(const uixException& e)
{
    uixASSERT(this != NULLPTR);

    // Rely on UiThread implementation
    uixUiThread::OnException(e);
}
//----------------------------------------------------------------------------//
void uixApplication::InitializeHandles(HINSTANCE instance, const uixChar* cmdLine, UINT showCmd)
{
    // (1) It should be current application at beginning
    uixASSERT(UixGetProcessState().m_Application == this);

    // Set handles
    m_Instance = instance;
    m_CommandLine = cmdLine;
    m_ShowCommand = showCmd;

    // And module name
    uixChar buffer[1024];
    {
        ::GetModuleFileName(m_Instance, buffer, 1024);
        m_FileName = buffer;
    }

    // (1) And at ending
    uixASSERT(UixGetProcessState().m_Application == this);
}
//----------------------------------------------------------------------------//
}
//----------------------------------------------------------------------------//