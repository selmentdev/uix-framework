#pragma once
//----------------------------------------------------------------------------//
#include <uixframe.h>
#include <uixrebarctrl.h>
#include <uiximagelistctrl.h>
#include <uixtoolbarctrl.h>
#include <uixstatusbarctrl.h>
#include <uixmenu.h>
//----------------------------------------------------------------------------//
#include "../Resources/resource.h"
//----------------------------------------------------------------------------//
#include <uixextcrspanel.h>
//----------------------------------------------------------------------------//
namespace WorldEditor
{
using namespace UIX;

//----------------------------------------------------------------------------//
class MainForm : public uixFrame
{
    uixDECLARE_EVENT_MAP()
public:

    virtual BOOL BeforeWindowCreate(CREATESTRUCT& cs);

    void OnCreate(uixCreateEventArgs& e);
    void OnSize(uixSizeEventArgs& e);

    void RecalcLayout();

    enum IDs
    {
        ID_REBAR = uixID_LAST,
        ID_PANEL_LEFT,
        ID_RENDERVIEW,

        ID_TOOLBAR_STANDARD = IDR_TOOLBAR_STANDARD,
    };

private:
    uixRebarCtrl        m_Rebar;
    uixToolBarCtrl      m_StandardToolBar;
    uixStatusBarCtrl    m_StatusBar;
    uixMenu             m_MainMenu;
    uixCrsPanel         m_Panel;
    uixCrsPanel         m_PanelInside[2];
};
//----------------------------------------------------------------------------//
}
//----------------------------------------------------------------------------//