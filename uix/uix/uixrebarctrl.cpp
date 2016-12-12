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
#include "uixrebarctrl.h"
//----------------------------------------------------------------------------//
namespace UIX
{
//----------------------------------------------------------------------------//
uixIMPLEMENT_DYNAMIC_CLASS(uixRebarCtrl, uixWindow);
//----------------------------------------------------------------------------//
uixBEGIN_EVENT_MAP(uixRebarCtrl, uixWindow)
uixEVT_CREATE()
uixEND_EVENT_MAP()
//----------------------------------------------------------------------------//
uixRebarCtrl::uixRebarCtrl()
{
}
//----------------------------------------------------------------------------//
uixRebarCtrl::~uixRebarCtrl()
{
    DestroyWindow();
}
//----------------------------------------------------------------------------//
BOOL uixRebarCtrl::BeforeWindowCreate(CREATESTRUCT& cs)
{
    if (!uixWindow::BeforeWindowCreate(cs))
    {
        return FALSE;
    }

    cs.lpszClass = REBARCLASSNAME;
    cs.style = uixWindowStyle_Child |
               uixWindowStyle_Visible |
               uixWindowStyle_ClipChildren;

    cs.style |=
        uixRebarStyle_VarHeight |
        uixRebarStyle_BandBorders |
        uixRebarStyle_AutoSize;

    cs.style |=
        uixControlStyle_NoDivider;

    return TRUE;
}
//----------------------------------------------------------------------------//
void uixRebarCtrl::OnCreate(uixCreateEventArgs& e)
{
    uixWindow::OnCreate(e);

    if (e.Result == -1)
    {
        return;
    }

    if (!this->SetBarInfo(uixRebarInfo()))
    {
        uixASSERT(false);
    }
}
//----------------------------------------------------------------------------//
BOOL uixRebarCtrl::AddBar(
    uixToolBarCtrl* toolBar,
    uixWindowID id,
    const uixChar* title,
    BOOL newRow,
    uixRebarBandStyle style)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    uixASSERT(::IsWindow(toolBar->GetHandleSafe()));

    INT buttonCount = toolBar->GetButtonCount();

    toolBar->UpdateLayout();

    REBARBANDINFO band;
    band.cbSize = sizeof(band);
    band.fStyle = style | RBBS_VARIABLEHEIGHT;
    band.fStyle |= RBBS_CHILDEDGE | RBBS_GRIPPERALWAYS;

    SIZE size;
    BOOL result = toolBar->GetMaxSize(size);

    band.fMask = RBBIM_CHILD | RBBIM_IDEALSIZE | RBBIM_CHILDSIZE | RBBIM_STYLE | RBBIM_ID;

    if (title != NULLPTR)
    {
        band.fMask |= RBBIM_TEXT;
    }

    if (newRow)
    {
        band.fStyle |= RBBS_BREAK;
    }

    band.lpText = const_cast<LPWSTR>(title);
    band.hwndChild = toolBar->GetHandleSafe();
    band.wID = id;
    band.cxMinChild = (UINT)(size.cx * 0.40);
    band.cxHeader = 0;

    uixRect rc;

    if (buttonCount > 0)
    {
        result = toolBar->GetItemRect(buttonCount - 1, rc);

        //!@bug Possible bug - check when can't get
        uixASSERT(result != FALSE);

        band.cx = rc.right;
        band.cyMinChild = rc.Height();
        band.cyMaxChild = rc.Height();
    }
    else
    {
        result = toolBar->GetWindowRect(rc);

        if (result)
        {
            band.cx = rc.Width();
            band.cyMinChild = rc.Height();
            band.cyMaxChild = rc.Width();
        }
        else
        {
            band.cx = 100;
        }
    }

    band.cxIdeal = band.cx;

    return InsertBand(band);
}
//----------------------------------------------------------------------------//
}
//----------------------------------------------------------------------------//