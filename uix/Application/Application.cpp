#include <uixapplication.h>
//----------------------------------------------------------------------------//
#include "Forms/MainForm.h"
//----------------------------------------------------------------------------//
namespace WorldEditor
{
using namespace UIX;

class Application : public uixApplication
{
public:
    virtual BOOL InitInstance() override
    {
        BOOL result = uixApplication::InitInstance();

        m_MainWindow = m_ActiveWindow = &m_MainForm;

        if (!m_MainForm.CreateFrame())
        {
            return FALSE;
        }

        m_MainForm.Show();
        m_MainForm.Update();

        return result;
    }

    virtual void OnException(const uixException& e) override
    {
        uixString message;
        e.Report(message);

        ::MessageBox(0,
                     message.c_str(),
                     _("Exception"),
                     MB_OK | MB_ICONWARNING);

        uixApplication::OnException(e);
    }
private:
    MainForm    m_MainForm;
};
}
//----------------------------------------------------------------------------//
uixIMPLEMENT_APPLICATION(WorldEditor::Application)
//----------------------------------------------------------------------------//