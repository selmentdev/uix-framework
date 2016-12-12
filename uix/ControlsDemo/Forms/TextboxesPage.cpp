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
#include "TextboxesPage.h"
//----------------------------------------------------------------------------//
namespace ControlsDemo
{
//----------------------------------------------------------------------------//
uixBEGIN_EVENT_MAP(TextboxesPage, uixTabPage)
uixEVT_COMMAND(IDC_BUTTON11, OnNormalButtonClick)
uixEND_EVENT_MAP();
//----------------------------------------------------------------------------//
BOOL TextboxesPage::CreateDlgFrame(uixWindow* parent)
{
    return uixTabPage::CreateDlgFrame(parent, IDD_TEXTBOXES);
}
//----------------------------------------------------------------------------//
BOOL TextboxesPage::OnInitDialog()
{
    if (!uixTabPage::OnInitDialog())
    {
        return FALSE;
    }

    return TRUE;
}
//----------------------------------------------------------------------------//
void TextboxesPage::OnNormalButtonClick(uixCommandEventArgs& e)
{
    MessageBox(GetHandle(),
               _("You have clicked button!"),
               _("Information"),
               MB_OK | MB_ICONINFORMATION);
}
//----------------------------------------------------------------------------//
}
//----------------------------------------------------------------------------//