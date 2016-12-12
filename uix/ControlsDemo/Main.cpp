#include <uixapplication.h>
#include <uixinit.h>
#include <uixdialog.h>
#include <uixproperty.h>
//----------------------------------------------------------------------------//
#include "Forms/MainForm.h"
//----------------------------------------------------------------------------//
namespace ControlsDemo
{
class Application : public UIX::uixApplication
{
public:
    virtual BOOL InitInstance() override
    {
        if (!UIX::uixApplication::InitInstance())
        {
            return FALSE;
        }

        m_MainWindow = &m_MainForm;
        m_MainForm.CreateFrame();
        m_MainForm.Update();
        m_MainForm.Show();

        return TRUE;
    }

private:
    MainForm    m_MainForm;
};
}
//----------------------------------------------------------------------------//
uixIMPLEMENT_APPLICATION(ControlsDemo::Application);
//----------------------------------------------------------------------------//