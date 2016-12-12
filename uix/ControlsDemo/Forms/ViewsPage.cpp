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
#include "ViewsPage.h"
//----------------------------------------------------------------------------//
#include <uixtreeviewctrl.h>
#include <uixcombobox.h>
#include <uixtabctrl.h>
#include <uixlistboxctrl.h>
#include <uixlistviewctrl.h>
#include <uixprogressbarctrl.h>
//----------------------------------------------------------------------------//
namespace ControlsDemo
{
//----------------------------------------------------------------------------//
uixBEGIN_EVENT_MAP(ViewsPage, uixTabPage)
uixEND_EVENT_MAP();
//----------------------------------------------------------------------------//
BOOL ViewsPage::CreateDlgFrame(uixWindow* parent)
{
    return uixTabPage::CreateDlgFrame(parent, IDD_VIEWS);
}
//----------------------------------------------------------------------------//
BOOL ViewsPage::OnInitDialog()
{
    if (!uixTabPage::OnInitDialog())
    {
        return FALSE;
    }

    uixTreeViewCtrl tree;
    tree.Subclass(GetChildByID(IDC_TREE1));
    {
        uixTreeViewItem item;
        item.SetText(_("Root"));

        uixTreeViewInsert tvi;
        tvi.SetParent(0);
        tvi.SetRelativeAsRoot();
        tvi.SetItem(item);
        HTREEITEM root =  tree.InsertItem(tvi);

        for (size_t i = 0; i < 10; ++i)
        {
            uixString msg;
            UixFormatString(msg, _("Node: %d"), i);
            item.SetText(msg.c_str());

            tvi.SetParent(root);
            tvi.SetRelativeAsLast();
            tvi.SetItem(item);
            HTREEITEM node = tree.InsertItem(tvi);

            for (size_t i = 0; i < 10; ++i)
            {
                uixString msg;
                UixFormatString(msg, _("Leaf: %d"), i);
                item.SetText(msg.c_str());

                tvi.SetParent(node);
                tvi.SetRelativeAsLast();
                tvi.SetItem(item);
                HTREEITEM leaf = tree.InsertItem(tvi);
                (void)leaf;
            }
        }
    }
    tree.Unsubclass();

    // Combo fields
    uixComboBox combo;
    combo.Attach(GetChildByID(IDC_COMBO1));
    {
        combo.AddString(_("One"));
        combo.AddString(_("Two"));
        combo.AddString(_("Three"));
        combo.AddString(_("Four"));
        combo.AddString(_("Five"));
    }
    combo.Detach();

    combo.Attach(GetChildByID(IDC_COMBO2));
    {
        combo.AddString(_("One"));
        combo.AddString(_("Two"));
        combo.AddString(_("Three"));
        combo.AddString(_("Four"));
        combo.AddString(_("Five"));
    }
    combo.Detach();

    combo.Attach(GetChildByID(IDC_COMBO3));
    {
        combo.AddString(_("One"));
        combo.AddString(_("Two"));
        combo.AddString(_("Three"));
        combo.AddString(_("Four"));
        combo.AddString(_("Five"));
    }
    combo.Detach();

    // List box
    uixListBoxCtrl listBox;
    listBox.Attach(GetChildByID(IDC_LIST1));
    {
        uixString msg;

        for (size_t i = 0; i < 25; ++i)
        {
            UixFormatString(msg, _("Item: %d"), i);
            listBox.AddString(msg.c_str());
        }
    }
    listBox.Detach();

    uixListViewCtrl listView;
    listView.Attach(GetChildByID(IDC_LIST2));
    listView.Detach();

    uixProgressBarCtrl bar;

    // Modify PB1
    bar.Attach(GetChildByID(IDC_PROGRESS1));
    bar.SetRange(0, 100);
    bar.SetPosition(66);
    bar.SetState(uixProgressBarState_Paused);
    bar.Detach();

    // Modify PB2
    bar.Attach(GetChildByID(IDC_PROGRESS2));
    bar.SetRange(0, 100);
    bar.SetPosition(66);
    bar.SetMarquee(TRUE, 30);
    bar.Detach();

    return TRUE;
}
//----------------------------------------------------------------------------//
}
//----------------------------------------------------------------------------//