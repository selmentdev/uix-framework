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
#include "uixtabctrl.h"
#include "uixgdidc.h"
//----------------------------------------------------------------------------//
namespace UIX
{
//----------------------------------------------------------------------------//
uixIMPLEMENT_DYNAMIC_CLASS(uixTabCtrl, uixWindow);
//----------------------------------------------------------------------------//
uixBEGIN_EVENT_MAP(uixTabCtrl, uixWindow)
uixEVT_REFLECT_NOTIFY(TCN_SELCHANGE, OnSelectionChange)
uixEVT_SIZE()
uixEND_EVENT_MAP()
//----------------------------------------------------------------------------//
uixTabCtrl::uixTabCtrl()
{
}
//----------------------------------------------------------------------------//
uixTabCtrl::~uixTabCtrl()
{
    DestroyWindow();
}
//----------------------------------------------------------------------------//
BOOL uixTabCtrl::BeforeWindowCreate(CREATESTRUCT& cs)
{
    if (!uixWindow::BeforeWindowCreate(cs))
    {
        return FALSE;
    }

    cs.lpszClass = WC_TABCONTROL;
    cs.style |= WS_CHILD
                | WS_VISIBLE
                | WS_CLIPCHILDREN
                | WS_CLIPSIBLINGS
                | WS_TABSTOP
                | WS_GROUP
                | TCS_HOTTRACK
                | TCS_MULTILINE
                | TCS_TABS
                | TCS_RIGHTJUSTIFY;
    cs.dwExStyle |= 0
                    | WS_EX_TRANSPARENT
                    ;

    return TRUE;
}
//----------------------------------------------------------------------------//
BOOL uixTabCtrl::AddPage(uixWindow* control, const uixString& text)
{
    if (control == NULLPTR)
    {
        return FALSE;
    }

    PagesList::const_iterator it = std::find(m_Pages.begin(), m_Pages.end(), control);

    if (it == m_Pages.end())
    {
        m_Pages.push_back(control);

        uixTabCtrlItem item;
        item.SetText(text.c_str());
        InsertItem(GetItemCount(), item);

        SelectPage(0);

        return TRUE;
    }

    return FALSE;
}
//----------------------------------------------------------------------------//
BOOL uixTabCtrl::RemovePage(INT index)
{
    // Valid index
    if ((index >= 0) && (index < (INT)m_Pages.size()))
    {
        PagesList::iterator it = m_Pages.begin() + index;
        m_Pages.erase(it);
        DeleteItem(index);
        return TRUE;
    }

    return FALSE;
}
//----------------------------------------------------------------------------//
uixWindow* uixTabCtrl::GetPageControl(INT index)
{
    if ((index >= 0) && (index < (INT)m_Pages.size()))
    {
        PagesList::iterator it = m_Pages.begin() + index;
        return *it;
    }

    return NULLPTR;
}
//----------------------------------------------------------------------------//
uixString uixTabCtrl::GetPageCaption(INT index)
{
    if ((index >= 0) && (index < (INT)m_Pages.size()))
    {
        uixTabCtrlItem item;
        item.SetText(NULLPTR, 0);

        return item.GetText();
    }

    return _("");
}
//----------------------------------------------------------------------------//
INT uixTabCtrl::GetPageCount() const
{
    return GetItemCount();
}
//----------------------------------------------------------------------------//
INT uixTabCtrl::GetSelectedPage() const
{
    return this->GetCurrentSelection();
}
//----------------------------------------------------------------------------//
INT uixTabCtrl::GetFocusedPage() const
{
    return this->GetCurrentFocus();
}
//----------------------------------------------------------------------------//
BOOL uixTabCtrl::SelectPage(INT index)
{
    uixWindow* page = GetPageControl(index);

    if (page != NULLPTR)
    {
        uixRect rc;
        GetClientRect(rc);
        AdjustRect(FALSE, rc);

        page->SetWindowRect(rc);
        page->Show();
        //page->BringToTop();

        return TRUE;
    }

    return FALSE;
}
//----------------------------------------------------------------------------//
void uixTabCtrl::OnSelectionChange(uixNotifyEventArgs& e)
{
    INT selected = GetSelectedPage();

    if ((selected >= 0) && selected < (INT)m_Pages.size())
    {
        for (INT i = 0; i < (INT)m_Pages.size(); ++i)
        {
            HidePage(i);
        }

        SelectPage(selected);
    }
}
//----------------------------------------------------------------------------//
void uixTabCtrl::OnSize(uixSizeEventArgs& e)
{
    uixWindow::OnSize(e);

    INT selected = GetSelectedPage();

    if ((selected >= 0) && selected < (INT)m_Pages.size())
    {
        uixWindow* page = GetPageControl(selected);

        if (page)
        {
            uixRect rc(uixPoint(0, 0), uixSize(e.Width, e.Height));
            AdjustRect(FALSE, rc);
            page->SetWindowRect(rc);
        }
    }
}
//----------------------------------------------------------------------------//
BOOL uixTabCtrl::HidePage(INT index)
{
    uixWindow* page = GetPageControl(index);

    if (page != NULLPTR)
    {
        page->Show(SW_HIDE);
        return TRUE;
    }

    return FALSE;
}
//----------------------------------------------------------------------------//
uixBEGIN_EVENT_MAP(uixTabPage, uixDialog)
uixEVT_ERASEBACKGROUND()
uixEVT_ENTERSIZEMOVE()
uixEVT_EXITSIZEMOVE()
uixEVT_COLOR(OnControlColor)
uixEND_EVENT_MAP()
//----------------------------------------------------------------------------//
BOOL uixTabPage::BeforeWindowCreate(CREATESTRUCT& cs)
{
    if (!uixDialog::BeforeWindowCreate(cs))
    {
        return FALSE;
    }

    return TRUE;
}
//----------------------------------------------------------------------------//
void uixTabPage::OnEraseBackground(uixEraseBackgroundEventArgs& e)
{
    e.Result = TRUE;
}
//----------------------------------------------------------------------------//
void uixTabPage::OnEnterSizeMove(uixEventArgs& e)
{
    uixDialog::OnEnterSizeMove(e);
    //SetRedraw(FALSE);
}
//----------------------------------------------------------------------------//
void uixTabPage::OnExitSizeMove(uixEventArgs& e)
{
    uixDialog::OnExitSizeMove(e);
    //SetRedraw(TRUE);
}
//----------------------------------------------------------------------------//
void uixTabPage::OnControlColor(uixControlColorEventArgs& e)
{
    if (e.DeviceContext)
    {
        switch (e.Request)
        {
        case uixControlColorEventArgs::uixColorRequest_Dialog:
        case uixControlColorEventArgs::uixColorRequest_Label:
            {
                SetWindowLong(e.Sender, GWL_EXSTYLE, GetWindowLong(e.Sender, GWL_EXSTYLE) | WS_EX_TRANSPARENT);
                ::SetBkMode(e.DeviceContext, uixDCBackgroundMode_Transparent);
                e.Result = (HBRUSH)NULL_BRUSH;
                //e.Processed = TRUE;
                break;
            }
        }
    }
}
//----------------------------------------------------------------------------//
}
//----------------------------------------------------------------------------//