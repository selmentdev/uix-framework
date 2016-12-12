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
#include "uixtoolbarctrl.h"
//----------------------------------------------------------------------------//
namespace UIX
{
//----------------------------------------------------------------------------//
uixIMPLEMENT_DYNAMIC_CLASS(uixToolBarCtrl, uixWindow);

uixBEGIN_EVENT_MAP(uixToolBarCtrl, uixWindow)
uixEVT_CREATE()
uixEND_EVENT_MAP()
//----------------------------------------------------------------------------//
uixToolBarCtrl::uixToolBarCtrl()
{
}
//----------------------------------------------------------------------------//
uixToolBarCtrl::~uixToolBarCtrl()
{
    m_ImageList.Destroy();
    DestroyWindow();
}
//----------------------------------------------------------------------------//
BOOL uixToolBarCtrl::BeforeWindowCreate(CREATESTRUCT& cs)
{
    if (!uixWindow::BeforeWindowCreate(cs))
    {
        return FALSE;
    }

    cs.lpszClass = TOOLBARCLASSNAME;

    cs.style |= WS_CHILD | WS_VISIBLE | WS_TABSTOP | WS_CLIPCHILDREN | WS_CLIPSIBLINGS;
    cs.style |= CCS_NODIVIDER | CCS_NORESIZE | CCS_NOPARENTALIGN | TBSTYLE_TOOLTIPS | TBSTYLE_FLAT;

    return TRUE;
}
//----------------------------------------------------------------------------//
void uixToolBarCtrl::OnCreate(uixCreateEventArgs& e)
{
    uixWindow::OnCreate(e);

    if (e.Result == -1)
    {
        return;
    }

    SendMessage( TB_BUTTONSTRUCTSIZE, sizeof(TBBUTTON), 0L);

    e.Result = 0;
}
//----------------------------------------------------------------------------//
BOOL uixToolBarCtrl::Load(uixResourceID resourceID)
{
#define RT_TOOLBAR  MAKEINTRESOURCE(241)

    // 1. Search for toolbar resource.
    HINSTANCE inst = UixFindResourceHandle(resourceID, RT_TOOLBAR);

    if (inst == 0)
    {
        return FALSE;
    }

    // 1.1 Load toolbar
    HRSRC toolbar = UixFindResource(inst, MAKEINTRESOURCE(resourceID), RT_TOOLBAR);
    HGLOBAL res = UixLoadResource(inst, toolbar);

    uixToolBarResourceData* items = (uixToolBarResourceData*)UixLockResource(res);

    uixToolBarButton button;

    INT bitmap = 0;

    for (INT i = 0; i < items->ItemCount; ++i)
    {
        if (items->Items[i] != 0)
        {
            button.iBitmap = bitmap++;
            button.idCommand = items->Items[i];
            button.fsState = uixToolBarButtonState_Enabled;
            button.fsStyle = uixToolBarButtonStyle_Button;
            button.dwData = 0;
            // 1.1.1 Loading string
            button.iString = 0; //!@todo add loading strings
        }
        else
        {
            button.iBitmap = 8;
            button.idCommand = 0;
            button.fsState = 0;
            button.fsStyle = uixToolBarButtonStyle_Separator;
            button.dwData = 0;
            button.iString = 0;
        }

        AddButtons(&button, 1);
    }

    SetBitmapSize(items->Width, items->Height);
    SetButtonSize(items->Width, items->Height);

    m_ImageList.Destroy();
    m_ImageList.CreateColor(
        inst,
        resourceID,
        uixSize(items->Width, items->Height));

    this->SetImageList(m_ImageList);

    UixUnlockResource(res);

    return TRUE;
}
//----------------------------------------------------------------------------//
INT uixToolBarCtrl::LoadImages(uixResourceID resourceID)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    return LoadImages(
               UixFindResourceHandle(resourceID, RT_BITMAP),
               resourceID);
}
//----------------------------------------------------------------------------//
INT uixToolBarCtrl::LoadImages(uixResourceName resource)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    return LoadImages(
               UixFindResourceHandle(resource, RT_BITMAP),
               resource);
}
//----------------------------------------------------------------------------//
INT uixToolBarCtrl::LoadImages(HINSTANCE instance, uixResourceID resourceID)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    return (INT)SendMessage(TB_LOADIMAGES, (WPARAM)resourceID, (LPARAM)instance);
}
//----------------------------------------------------------------------------//
INT uixToolBarCtrl::LoadImages(HINSTANCE instance, uixResourceName resource)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    return (INT)SendMessage(TB_LOADIMAGES, (WPARAM)resource, (LPARAM)instance);
}
//----------------------------------------------------------------------------//
}
//----------------------------------------------------------------------------//