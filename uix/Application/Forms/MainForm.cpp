#include "MainForm.h"
//----------------------------------------------------------------------------//
namespace WorldEditor
{
//----------------------------------------------------------------------------//
uixBEGIN_EVENT_MAP(MainForm, uixFrame)
uixEVT_CREATE()
uixEVT_SIZE()
uixEND_EVENT_MAP()
//----------------------------------------------------------------------------//
BOOL MainForm::BeforeWindowCreate(CREATESTRUCT& cs)
{
    if (!uixFrame::BeforeWindowCreate(cs))
    {
        return FALSE;
    }

    cs.lpszName = _("Fancy Panel");

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

    m_Panel.Create(this, _("Example of using panel"), uixPoint(0, 0), uixSize(200, 200), ID_PANEL_LEFT);
    m_PanelInside[0].Create(&m_Panel, _("Hello"), uixPoint(7, 7), uixSize(200, 100));
    m_PanelInside[1].Create(&m_Panel, _("World"), uixPoint(7, 114), uixSize(200, 100));
}
//----------------------------------------------------------------------------//
void MainForm::OnSize(uixSizeEventArgs& e)
{
    RecalcLayout();
}
//----------------------------------------------------------------------------//
void MainForm::RecalcLayout()
{
    uixRect rc;
    GetClientRect(rc);
    rc.Deflate(50, 50);

    m_Panel.SetWindowPos(rc);
}
//----------------------------------------------------------------------------//
}
//----------------------------------------------------------------------------//