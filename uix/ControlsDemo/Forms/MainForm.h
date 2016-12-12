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
//----------------------------------------------------------------------------//
#include <uixdialog.h>
#include <uixwindowclass.h>
#include <uixframe.h>
#include <uixtabctrl.h>
#include <uixmenu.h>
//----------------------------------------------------------------------------//
#include "TextboxesPage.h"
#include "DrawingPage.h"
#include "ViewsPage.h"
//----------------------------------------------------------------------------//
#include <uixstatusbarctrl.h>
#include <uixrebarctrl.h>
#include <uixtoolbarctrl.h>
//----------------------------------------------------------------------------//
namespace ControlsDemo
{
using namespace UIX;

class MainForm : public uixFrame
{
    uixDECLARE_EVENT_MAP();
public:
    void OnCreate(uixCreateEventArgs& e);
    virtual BOOL BeforeWindowCreate(CREATESTRUCT& cs) override;

    enum IDs
    {
        ID_TABCTRL = uixID_LAST,
    };

    void OnTabChange(uixNotifyEventArgs& e);
    void OnSize(uixSizeEventArgs& e);

    void OnClose(uixCloseEventArgs& e);

    void OnCmdFileExit(uixCommandEventArgs& e);
    void OnCmdHelpAbout(uixCommandEventArgs& e);

private:
    uixTabCtrl          m_TabCtrl;
    uixStatusBarCtrl    m_StatusBar;
    uixToolBarCtrl      m_Toolbar;
    uixToolBarCtrl      m_AdditionalToolbar;
    uixRebarCtrl        m_Rebar;
    TextboxesPage       m_EditBoxesPage;
    DrawingPage         m_DrawingPage;
    ViewsPage           m_ViewsPage;
    uixMenu             m_MainMenu;
};
}
//----------------------------------------------------------------------------//