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
#include "uixdialog.h"
#include "uixuithread.h"
#include "uixresource.h"
#include "uixgdidc.h"
//----------------------------------------------------------------------------//
namespace UIX
{
//----------------------------------------------------------------------------//
UINT_PTR CALLBACK UixDlgProc(HWND h, UINT u, WPARAM j, LPARAM a)
{
    if (u == WM_INITDIALOG)
    {
        uixDialog* dlg = uixDYNAMIC_CAST(uixDialog, uixWindow::FromHandle(h));

        if (dlg != NULLPTR)
        {
            return dlg->OnInitDialog();
        }

        return 1;
    }

    return 0;
}
//----------------------------------------------------------------------------//
uixIMPLEMENT_DYNAMIC_CLASS(uixDialog, uixWindow);
//----------------------------------------------------------------------------//
uixBEGIN_EVENT_MAP(uixDialog, uixWindow)
uixEVT_COMMAND(IDOK, OnOK)
uixEVT_COMMAND(IDCANCEL, OnCancel)
uixEVT_CLOSE()
uixEND_EVENT_MAP()
//----------------------------------------------------------------------------//
uixDialog::uixDialog()
    : uixWindow()
    , m_Flags(0)
    , m_ModalResult(0)
{
}
//----------------------------------------------------------------------------//
uixDialog::~uixDialog()
{
    EndDialog(0);
    DestroyWindow();
}
//----------------------------------------------------------------------------//
BOOL uixDialog::CreateDlgFrame(uixWindow* parent, uixResourceName templateName)
{
    return uixDialog::CreateDlgFrame(
               parent,
               UixFindResourceHandle(templateName, RT_DIALOG),
               templateName);
}
//----------------------------------------------------------------------------//
BOOL uixDialog::CreateDlgFrame(uixWindow* parent, HINSTANCE instance, uixResourceName templateName)
{
    // Find this resouce
    HRSRC hRes = UixFindResource(instance, templateName, RT_DIALOG);
    // Load it
    HGLOBAL hResource = UixLoadResource(instance, hRes);

    uixENSURE(hResource != NULLPTR);

    // Setup create window hook
    uixCreateWindowHook::Begin(this);

    // Try to create dialog indirect
    HWND handle = CreateDialogIndirect(
                      instance,
                      (LPCDLGTEMPLATE)UixLockResource(hResource),
                      parent->GetHandleSafe(),
                      (DLGPROC)&UixDlgProc);

#if defined UIX_DEBUG
    DWORD errorCode = ::GetLastError();
#endif

    if (!uixCreateWindowHook::End())
    {
        // Post NcDestroy event
        ::PostMessage(uixThreadState::Get().m_LastSentMsg.hwnd, WM_NCDESTROY, 0, 0);
    }

#if defined UIX_DEBUG

    if (errorCode != 0)
    {
        // Notify debugger about error while creating dialog control
        uixTRACE(_("%s(%p, %p, %d) = [Error].%d"), __UIX_FUNCTION__, parent, instance, templateName,
                 errorCode);
        uixTRACE(_("%s"), UixErrorString(errorCode).c_str());
    }

#endif
    return (handle == m_Handle);
}
//----------------------------------------------------------------------------//
BOOL uixDialog::CreateDlgFrame(uixWindow* parent, uixResourceID templateID)
{
    return uixDialog::CreateDlgFrame(parent, MAKEINTRESOURCE(templateID));
}
//----------------------------------------------------------------------------//
BOOL uixDialog::CreateDlgFrame(uixWindow* parent, HINSTANCE instance, uixResourceID templateID)
{
    return uixDialog::CreateDlgFrame(parent, instance, MAKEINTRESOURCE(templateID));
}
//----------------------------------------------------------------------------//
void uixDialog::EndDialog(INT result)
{
    EndModalLoop(result);
    ::EndDialog(m_Handle, result);
}
//----------------------------------------------------------------------------//
BOOL uixDialog::BeforeWindowCreate(CREATESTRUCT& cs)
{
    if (!uixWindow::BeforeWindowCreate(cs))
    {
        return FALSE;
    }

    // Note: this is generic dialog class name
    cs.lpszClass = _("#32770");
    cs.style |= uixWindowStyle_DialogFrame | uixWindowStyle_Visible;

    return TRUE;
}
//----------------------------------------------------------------------------//
BOOL uixDialog::BeforeTranslateMessage(MSG* m)
{
    if ((WM_KEYFIRST <= m->message) && (m->message <= WM_KEYLAST))
    {
        // Checking dialog messages
        return ::IsDialogMessage(m_Handle, m);
    }

    return uixWindow::BeforeTranslateMessage(m);
}
//----------------------------------------------------------------------------//
INT uixDialog::BeginModalLoop(UINT flags)
{
    m_Flags = flags;

    BOOL isIdle = TRUE;

    // Current message
    MSG* msg = &uixThreadState::Get().m_CurrentMsg;

    for (;;)
    {
        while (isIdle && PeekMessage(msg, 0, 0, 0, PM_NOREMOVE))
        {
            isIdle = FALSE;
        }

        do
        {
            if (!ProcessMessage(msg))
            {
                PostQuitMessage(-1);
                return -1;
            }

            if (!(m_Flags & 1))
            {
                goto ExitModal;
            }

            if (IsIdleMessage(msg))
            {
                isIdle = TRUE;
                //idleCount = 0;
            }
        }
        while (PeekMessage(msg, 0, 0, 0, PM_NOREMOVE));
    }

ExitModal:
    return m_ModalResult;
}
//----------------------------------------------------------------------------//
void uixDialog::EndModalLoop(INT result)
{
    m_ModalResult = result;

    if (m_Flags & 1)
    {
        m_Flags &= ~1;
        PostMessage(WM_NULL, 0, 0);
    }
}
//----------------------------------------------------------------------------//
BOOL uixDialog::ProcessMessage(MSG* m)
{
    uixUiThread* thread = uixThreadState::Get().m_CurrentThread;

    if (thread)
    {
        return thread->ProcessMessage(m);
    }

    return FALSE;
}
//----------------------------------------------------------------------------//
BOOL uixDialog::IsIdleMessage(MSG* m)
{
    uixUiThread* thread = uixThreadState::Get().m_CurrentThread;

    if (thread)
    {
        return thread->IsIdleMessage(m);
    }

    return FALSE;
}
//----------------------------------------------------------------------------//
void uixDialog::BeginModalState()
{
}
//----------------------------------------------------------------------------//
void uixDialog::EndModalState()
{
}
//----------------------------------------------------------------------------//
DWORD uixDialog::DoModal()
{
    HWND parent = ::GetParent(m_Handle);
    BOOL wasEnabled = ::IsWindowEnabled(parent);

    if (wasEnabled)
    {
        ::EnableWindow(parent, FALSE);
    }

    // Make sure that dialog is visible
    Show(SW_SHOWNORMAL);

    //!@todo name it somehow.. 1 flag? wtf?
    //!@note Generally this flag should be named ContinueFlag..
    DWORD result = BeginModalLoop(1);

    if (wasEnabled)
    {
        ::EnableWindow(parent, TRUE);
    }

    if (parent != NULLPTR && ::GetActiveWindow() == m_Handle)
    {
        ::SetActiveWindow(parent);
    }

    return result;
}
//----------------------------------------------------------------------------//
BOOL uixDialog::OnInitDialog()
{
    return TRUE;
}
//----------------------------------------------------------------------------//
void uixDialog::OnClose(uixCloseEventArgs& e)
{
    EndDialog(IDCLOSE);
    DestroyWindow();
}
//----------------------------------------------------------------------------//
void uixDialog::OnOK(uixCommandEventArgs& e)
{
    EndDialog(IDOK);
    DestroyWindow();
}
//----------------------------------------------------------------------------//
void uixDialog::OnCancel(uixCommandEventArgs& e)
{
    EndDialog(IDCANCEL);
    DestroyWindow();
}
//----------------------------------------------------------------------------//
void uixDialog::OnControlColor(uixControlColorEventArgs& e)
{
}
//----------------------------------------------------------------------------//
}
//----------------------------------------------------------------------------//