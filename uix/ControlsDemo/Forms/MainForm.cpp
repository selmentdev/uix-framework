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
#include "MainForm.h"
//----------------------------------------------------------------------------//
namespace ControlsDemo
{
//----------------------------------------------------------------------------//
uixBEGIN_EVENT_MAP(MainForm, uixFrame)
uixEVT_CREATE()
uixEVT_SIZE()
uixEVT_COMMAND(IDC_HELP_ABOUT, OnCmdHelpAbout)
uixEVT_COMMAND(IDC_FILE_EXIT, OnCmdFileExit)
uixEVT_CLOSE()
uixEND_EVENT_MAP()
//----------------------------------------------------------------------------//
BOOL MainForm::BeforeWindowCreate(CREATESTRUCT& cs)
{
    if (!uixFrame::BeforeWindowCreate(cs))
    {
        return FALSE;
    }

    m_MainMenu.Load(IDR_MAINMENU);
    cs.hMenu = m_MainMenu;

    cs.style = uixWindowStyle_OverlappedWindow;
    cs.style &= ~(uixWindowStyle_MaximizeBox | uixWindowStyle_ThickFrame);

    cs.cx = 583;
    cs.cy = 561;

    cs.lpszName = _("Controls Demo");

    return TRUE;
}
//----------------------------------------------------------------------------//
void MainForm::OnCreate(uixCreateEventArgs& e)
{
    uixFrame::OnCreate(e);

    if (e.Result == -1)
    {
        return;
    }

    m_StatusBar.Create(this);
    m_StatusBar.SetText(_("Ready"));

    m_Rebar.Create(this);

    m_Toolbar.Create(this);
    m_Toolbar.Load(IDR_STDTOOLBAR);
    m_Rebar.AddBar(&m_Toolbar, uixID_ANY);

    m_AdditionalToolbar.Create(this);
    m_AdditionalToolbar.Load(IDR_STDTOOLBAR);
    m_Rebar.AddBar(&m_AdditionalToolbar, uixID_ANY);

    m_TabCtrl.Create(this, uixPoint(0, 0), uixSize(400, 300), ID_TABCTRL);
    m_EditBoxesPage.CreateDlgFrame(&m_TabCtrl);
    m_DrawingPage.CreateDlgFrame(&m_TabCtrl);
    m_ViewsPage.CreateDlgFrame(&m_TabCtrl);

    m_TabCtrl.AddPage(&m_EditBoxesPage, _("Controls"));
    m_TabCtrl.AddPage(&m_DrawingPage, _("Drawing"));
    m_TabCtrl.AddPage(&m_ViewsPage, _("Views"));

}
//----------------------------------------------------------------------------//
void MainForm::OnSize(uixSizeEventArgs& e)
{
    uixFrame::OnSize(e);

    uixRect rc;

    uixRect aux;
    m_StatusBar.RecalcLayout();
    m_StatusBar.GetWindowRect(aux);


    GetClientRect(rc);
    rc.Deflate(7, 7);
    rc.bottom -= aux.Height();

    m_Rebar.RecalcLayout();
    m_Rebar.GetWindowRect(aux);

    rc.top += aux.Height();

    m_TabCtrl.SetWindowPos(rc);
}
//----------------------------------------------------------------------------//
void MainForm::OnClose(uixCloseEventArgs& e)
{
    if (::MessageBox(GetHandleSafe(),
                     _("Do you really want to quit?"),
                     _("Question"),
                     MB_YESNO | MB_ICONQUESTION) == uixID_YES)
    {
        uixFrame::OnClose(e);
    }
}
//----------------------------------------------------------------------------//
void MainForm::OnCmdFileExit(uixCommandEventArgs& e)
{
    Close();
}
//----------------------------------------------------------------------------//
void MainForm::OnCmdHelpAbout(uixCommandEventArgs& e)
{
    ::MessageBox(
        GetHandleSafe(),
        _("This is Controls Demo application for UIX User Interface Framework.\nAuthor: Karol Grzybowski"),
        _("About Controls Demo"),
        MB_OK | MB_ICONINFORMATION);
}
//----------------------------------------------------------------------------//
}
//----------------------------------------------------------------------------//