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
//----------------------------------------------------------------------------//
#include "uixaboutdlg.h"
//----------------------------------------------------------------------------//
namespace UIX
{
//----------------------------------------------------------------------------//
uixIMPLEMENT_DYNAMIC_CLASS(uixAboutDlg, uixDialog);
//----------------------------------------------------------------------------//
uixBEGIN_EVENT_MAP(uixAboutDlg, uixDialog)
uixEVT_INITDIALOG()
uixEVT_DESTROY()
uixEND_EVENT_MAP()
//----------------------------------------------------------------------------//
void uixAboutDlg::OnInitDialog(uixInitDialogEventArgs& e)
{
    uixWindow::OnInitDialog(e);

    if (e.Result == FALSE)
    {
        return;
    }

    // Attaching auto-created controls to labels
    m_License.Attach(::GetDlgItem(GetHandle(), ID_LBL_LICENSE));
    m_AppName.Attach(::GetDlgItem(GetHandle(), ID_LBL_APPNAME));
    m_Content.Attach(::GetDlgItem(GetHandle(), ID_LBL_CONTENT));
    m_VertBar.Attach(::GetDlgItem(GetHandle(), ID_IMG_VERTBAR));

    m_TechSupport.Attach(::GetDlgItem(GetHandle(), ID_BTN_TECHSUPPORT));
    m_SystemInfo.Attach(::GetDlgItem(GetHandle(), ID_BTN_SYSTEMINFO));

    e.Result = TRUE;
}
//----------------------------------------------------------------------------//
void uixAboutDlg::OnDestroy(uixDestroyEventArgs& e)
{
    // Detaching controls
    m_License.Detach();
    m_AppName.Detach();
    m_Content.Detach();
    m_VertBar.Detach();
    m_TechSupport.Detach();
    m_SystemInfo.Detach();

    uixWindow::OnDestroy(e);
}
//----------------------------------------------------------------------------//
void uixAboutDlg::SetLicense(const uixString& license)
{
    m_License.SetText(license);
}
//----------------------------------------------------------------------------//
void uixAboutDlg::SetAppName(const uixString& appName)
{
    m_AppName.SetText(appName);
    this->SetText(appName + _(" - About"));
}
//----------------------------------------------------------------------------//
void uixAboutDlg::SetContent(const uixString& content)
{
    m_Content.SetText(content);
}
//----------------------------------------------------------------------------//
void uixAboutDlg::SetVerticalBarImage(HBITMAP bitmap)
{
    m_VertBar.SetBitmap(bitmap);
}
//----------------------------------------------------------------------------//
BOOL uixAboutDlg::Create(uixWindow* parent)
{
    return uixDialog::CreateDlgFrame(parent, uixRESID_DIALOG_ABOUT);
}
//----------------------------------------------------------------------------//
DWORD uixAboutDlg::DoModal()
{
    HWND parent = this->GetParent();

    // Try to offset dialog relative to it's parent
    if (parent != 0)
    {
        uixRect rc;
        ::GetClientRect(parent, &rc);
        rc.Offset(50, 50);
        uixPoint pt = rc.TopLeft();
        ::ClientToScreen(parent, &pt);

        this->SetWindowPos(pt, uixSize(), SWP_NOZORDER | SWP_NOSIZE);
    }

    return uixDialog::DoModal();
}
//----------------------------------------------------------------------------//
}
//----------------------------------------------------------------------------//