#include <uixapplication.h>
#include <uixframe.h>
#include <uixbuttonctrl.h>
#include <uixaboutdlg.h>

namespace Example
{
using namespace UIX;

class CMainFrame : public uixFrame
{
    uixDECLARE_EVENT_MAP()
public:
    enum Command
    {
        Command_Default = uixID_LAST,
        Command_About,
    };

    void OnCreate(uixCreateEventArgs& e)
    {
        uixFrame::OnCreate(e);

        if (e.Result == -1)
        {
            return;
        }

        this->SetText(_("Example application"));
        m_Button.Create(this, _("&Click Me"), uixPoint(7, 7), uixSize(75, 23), Command_Default);
        m_About.Create(this, _("&About"), uixPoint(7, 37), uixSize(75, 23), Command_About);
    }

    void OnButtonClick(uixCommandEventArgs& e)
    {
        MessageBox(GetHandle(), _("You clicked Button"), _("Information"), MB_OK | MB_ICONINFORMATION);
    }

    void OnAboutClick(uixCommandEventArgs& e)
    {
        uixAboutDlg d;
        d.Create(this);
        d.SetAppName(_("Example application"));
        d.DoModal();
    }
private:
    uixButton   m_Button;
    uixButton   m_About;
};

uixBEGIN_EVENT_MAP(CMainFrame, uixFrame)
uixEVT_CREATE()
uixEVT_COMMAND(CMainFrame::Command_Default, OnButtonClick)
uixEVT_COMMAND(CMainFrame::Command_About, OnAboutClick)
uixEND_EVENT_MAP()


class CApplication : public uixApplication
{
public:
    virtual BOOL InitInstance() override
    {
        if (!uixApplication::InitInstance())
        {
            return FALSE;
        }

        SetMainWindow(&m_MainFrame);
        m_MainFrame.CreateFrame();
        m_MainFrame.Show();
        m_MainFrame.Update();

        return TRUE;
    }
private:
    CMainFrame  m_MainFrame;
};
}
uixIMPLEMENT_APPLICATION(Example::CApplication)