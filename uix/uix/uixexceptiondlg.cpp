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
#include "uixexceptiondlg.h"
//----------------------------------------------------------------------------//
namespace UIX
{
//----------------------------------------------------------------------------//
uixIMPLEMENT_DYNAMIC_CLASS(uixExceptionDlg, uixDialog);
//----------------------------------------------------------------------------//
uixBEGIN_EVENT_MAP(uixExceptionDlg, uixDialog)
uixEVT_INITDIALOG()
uixEVT_DESTROY()
uixEND_EVENT_MAP()
//----------------------------------------------------------------------------//
void uixExceptionDlg::OnInitDialog(uixInitDialogEventArgs& e)
{
    uixWindow::OnInitDialog(e);

    if (e.Result == FALSE)
    {
        return;
    }

    m_Title.Attach(::GetDlgItem(GetHandle(), IDC_EXCEPTIONTITLE));
    m_Exception.Attach(::GetDlgItem(GetHandle(), IDC_EXCEPTIONINFO));
    m_Icon.Attach(::GetDlgItem(GetHandle(), IDC_EXCEPTIONICON));
}
//----------------------------------------------------------------------------//
void uixExceptionDlg::OnDestroy(uixDestroyEventArgs& e)
{
    m_Title.Detach();
    m_Exception.Detach();
    m_Icon.Detach();

    uixWindow::OnDestroy(e);
}
//----------------------------------------------------------------------------//
BOOL uixExceptionDlg::Create(uixWindow* parent)
{
    return uixDialog::CreateDlgFrame(parent, IDD_EXCEPTION);
}
//----------------------------------------------------------------------------//
DWORD uixExceptionDlg::ShowException(const uixException& e)
{
    uixString info;
    e.Report(info);
    m_Exception.SetText(info);
    m_Icon.SetIcon(UixLoadIcon(0, IDI_WARNING));

    // Center to desktop
    CenterWindow(uixWindowRelativePos_Desktop);
    return uixDialog::DoModal();
}
//----------------------------------------------------------------------------//
}
//----------------------------------------------------------------------------//