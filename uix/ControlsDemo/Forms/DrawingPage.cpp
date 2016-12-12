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
#include "DrawingPage.h"
#include <uixmenu.h>
//----------------------------------------------------------------------------//
namespace ControlsDemo
{
//----------------------------------------------------------------------------//
uixBEGIN_EVENT_MAP(DrawingPage, uixTabPage)
uixEVT_CONTEXTMENU()
uixEND_EVENT_MAP();
//----------------------------------------------------------------------------//
BOOL DrawingPage::CreateDlgFrame(uixWindow* parent)
{
    return uixTabPage::CreateDlgFrame(parent, IDD_DRAWINGS);
}
//----------------------------------------------------------------------------//
BOOL DrawingPage::OnInitDialog()
{
    if (!uixTabPage::OnInitDialog())
    {
        return FALSE;
    }

    return TRUE;
}
//----------------------------------------------------------------------------//
void DrawingPage::OnContextMenu(uixContextMenuEventArgs& e)
{

    uixMenu contextMenu;
    contextMenu.Load(IDR_CONTEXTMENU);
    uixMenu submenu = contextMenu.GetSubMenu(0);

    uixRect testSite;
    uixGroupPane pane;
    pane.Attach(GetChildByID(IDC_CTXTESTSITE));
    {
        pane.GetWindowRect(testSite);
    }
    pane.Detach();

    if (contextMenu)
    {
        if (testSite.PtInRect(e.Position))
        {
            submenu.TrackPopupEx(TPM_LEFTALIGN | TPM_RIGHTBUTTON,
                                 e.Position.x,
                                 e.Position.y,
                                 GetHandle());
        }
    }
}
//----------------------------------------------------------------------------//
}
//----------------------------------------------------------------------------//