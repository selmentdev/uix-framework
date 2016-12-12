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
#include "uixfiledialog.h"
//----------------------------------------------------------------------------//
namespace UIX
{
//! File Dialog Event handler
class uixFileDialogEventHandler
    : public IFileDialogEvents
    , public IFileDialogControlEvents
{
public:
    //! Constructor
    //! @param[in] parent
    //!     Parent dialog
    uixFileDialogEventHandler(uixFileDialog* parent)
        : m_Parent(parent)
        , m_Reference(1)
    {
        uixASSERT(parent != NULLPTR);

        uixTRACE(_("[%s]"), __UIX_FUNCTION__);
    }

    //! Called when user clicks OK button
    IFACEMETHODIMP OnFileOk(IFileDialog* dialog) override
    {
        uixTRACE(_("[%s]"), __UIX_FUNCTION__);

        m_Parent->OnFileOk();

        return S_OK; // or E_FAIL
    }

    //! Called when user change folder
    IFACEMETHODIMP OnFolderChange(IFileDialog* dialog) override
    {
        uixTRACE(_("[%s]"), __UIX_FUNCTION__);

        m_Parent->OnFolderChange();

        return S_OK; // or E_FAIL
    }

    //! Called when user is changing folder
    IFACEMETHODIMP OnFolderChanging(IFileDialog* dialog, IShellItem* item) override
    {
        uixTRACE(_("[%s]"), __UIX_FUNCTION__);

        m_Parent->OnFolderChanging();

        return S_OK; // or E_FAIL
    }

    //! Called when user clicked help
    IFACEMETHODIMP OnHelp(IFileDialog*)
    {
        return S_OK;
    }

    //! Called when user changed selection
    IFACEMETHODIMP OnSelectionChange(IFileDialog*) override
    {
        return S_OK;
    }

    //! Called when user violate share
    IFACEMETHODIMP OnShareViolation(IFileDialog*, IShellItem*, FDE_SHAREVIOLATION_RESPONSE*) override
    {
        return S_OK;
    }

    //! Called when user change type
    IFACEMETHODIMP OnTypeChange(IFileDialog* pfd) override
    {
        return S_OK;
    }

    //! Called when user overwrite item
    IFACEMETHODIMP OnOverwrite(IFileDialog*, IShellItem*, FDE_OVERWRITE_RESPONSE*) override
    {
        return S_OK;
    }

    // IFileDialogControlEvents methods

    //! Called when user selects item
    IFACEMETHODIMP OnItemSelected(IFileDialogCustomize* pfdc, DWORD dwIDCtl, DWORD dwIDItem) override
    {
        return S_OK;
    }

    //! Called when user clicks button
    IFACEMETHODIMP OnButtonClicked(IFileDialogCustomize*, DWORD) override
    {
        return S_OK;
    }

    //! Called when user checks button
    IFACEMETHODIMP OnCheckButtonToggled(IFileDialogCustomize*, DWORD, BOOL) override
    {
        return S_OK;
    }

    //! Called when user activate control
    IFACEMETHODIMP OnControlActivating(IFileDialogCustomize*, DWORD) override
    {
        return S_OK;
    }

    //! Query interface
    IFACEMETHODIMP QueryInterface(REFIID riid, void** ppv) override
    {
        static const QITAB qit[] =
        {
            QITABENT(uixFileDialogEventHandler, IFileDialogEvents),
            QITABENT(uixFileDialogEventHandler, IFileDialogControlEvents),
            {0},
        };

        return QISearch(this, qit, riid, ppv);
    }

    IFACEMETHODIMP_(ULONG) AddRef() override
    {
        return ::InterlockedIncrement(&m_Reference);
    }

    IFACEMETHODIMP_(ULONG) Release() override
    {
        long cRef = InterlockedDecrement(&m_Reference);

        if (!cRef)
        {
            delete this;
        }

        return cRef;
    }

    static HRESULT CreateInstance(REFIID riid, void** ppv, uixFileDialog* parent)
    {
        *ppv = NULLPTR;
        uixFileDialogEventHandler* impl = new /*(std::nothrow) */uixFileDialogEventHandler(parent);
        HRESULT hr = impl ? S_OK : E_OUTOFMEMORY;

        if (SUCCEEDED(hr))
        {
            hr = impl->QueryInterface(riid, ppv);
            impl->Release();
        }

        return hr;
    }

private:
    //! Destructor
    virtual ~uixFileDialogEventHandler() {}

private:
    uixFileDialog*      m_Parent;           //!< Parent dialog
    long                m_Reference;        //!< Reference counter
};
//----------------------------------------------------------------------------//
uixFileDialog::uixFileDialog(BOOL openDialog)
    : m_Cookie(0)
    , m_EventHandler(NULLPTR)
    , m_FileDialog(NULLPTR)
    , m_ShowResult(E_FAIL)
{
    uixTRACE(_("[%s]"), __UIX_FUNCTION__);

    HRESULT hr = 0;

    if (openDialog)
    {
        // Try to CoCreate instance of open dialog
        hr = CoCreateInstance(
                 CLSID_FileOpenDialog,
                 NULLPTR,
                 CLSCTX_INPROC_SERVER,
                 IID_PPV_ARGS(&m_FileDialog));
    }
    else
    {
        // Try to CoCreate instance of save dialog
        hr = CoCreateInstance(
                 CLSID_FileSaveDialog,
                 NULLPTR,
                 CLSCTX_INPROC_SERVER,
                 IID_PPV_ARGS(&m_FileDialog));
    }

    if (FAILED(hr))
    {
        m_FileDialog = NULLPTR;
        m_EventHandler = NULLPTR;
        m_Cookie = 0;
        return;
    }

    hr = uixFileDialogEventHandler::CreateInstance(IID_PPV_ARGS(&m_EventHandler), this);

    if (FAILED(hr))
    {
        m_FileDialog->Release();

        m_FileDialog = NULLPTR;
        m_EventHandler = NULLPTR;
        m_Cookie = 0;
        return;
    }

    hr = m_FileDialog->Advise(m_EventHandler, &m_Cookie);

    if (FAILED(hr))
    {
        m_EventHandler->Release();
        m_FileDialog->Release();

        m_FileDialog = NULLPTR;
        m_EventHandler = NULLPTR;
        m_Cookie = 0;
        return;
    }
}
//----------------------------------------------------------------------------//
uixFileDialog::~uixFileDialog()
{
    if (m_Cookie)
    {
        m_FileDialog->Unadvise(m_Cookie);
    }

    if (m_EventHandler)
    {
        m_EventHandler->Release();
    }

    if (m_FileDialog)
    {
        m_FileDialog->Release();
    }

    uixTRACE(_("[%s]"), __UIX_FUNCTION__);
}
//----------------------------------------------------------------------------//
#pragma region Properties
//----------------------------------------------------------------------------//
uixFileDialogFlag uixFileDialog::GetOptions() const
{
    if (!m_FileDialog || !m_Cookie || !m_EventHandler)
    {
        return uixFileDialogFlag_None;
    }

    DWORD flags;

    if (SUCCEEDED(m_FileDialog->GetOptions(&flags)))
    {
        return (uixFileDialogFlag)flags;
    }

    return (uixFileDialogFlag)uixFileDialogFlag_None;
}
//----------------------------------------------------------------------------//
BOOL uixFileDialog::SetOptions(uixFileDialogFlag flags)
{
    if (!m_FileDialog || !m_Cookie || !m_EventHandler)
    {
        return FALSE;
    }

    if (SUCCEEDED(m_FileDialog->SetOptions(flags)))
    {
        return TRUE;
    }

    return FALSE;
}
//----------------------------------------------------------------------------//
BOOL uixFileDialog::SetFileName(const wchar_t* fileName)
{
    if (!m_FileDialog || !m_Cookie || !m_EventHandler)
    {
        return FALSE;
    }

    if (SUCCEEDED(m_FileDialog->SetFileName(fileName)))
    {
        return TRUE;
    }

    return FALSE;
}
//----------------------------------------------------------------------------//
void uixFileDialog::AddPlace(const wchar_t* folder, BOOL onTop)
{
    if (!m_FileDialog || !m_Cookie || !m_EventHandler)
    {
        return;
    }

    IShellItem* item = NULLPTR;
    HRESULT hr = SHCreateItemFromParsingName(folder, NULLPTR, IID_PPV_ARGS(&item));

    if (SUCCEEDED(hr))
    {
        m_FileDialog->AddPlace(item, onTop ? FDAP_TOP : FDAP_BOTTOM);
        item->Release();
    }
}
//----------------------------------------------------------------------------//
void uixFileDialog::SetFolder(const wchar_t* folder)
{
    if (!m_FileDialog || !m_Cookie || !m_EventHandler)
    {
        return;
    }

    IShellItem* item = NULLPTR;
    HRESULT hr = SHCreateItemFromParsingName(folder, NULLPTR, IID_PPV_ARGS(&item));

    if (SUCCEEDED(hr))
    {
        m_FileDialog->SetFolder(item);
        item->Release();
    }
}
//----------------------------------------------------------------------------//
void uixFileDialog::SetDefaultFolder(const wchar_t* folder)
{
    if (!m_FileDialog || !m_Cookie || !m_EventHandler)
    {
        return;
    }

    IShellItem* item = NULLPTR;
    HRESULT hr = SHCreateItemFromParsingName(folder, NULLPTR, IID_PPV_ARGS(&item));

    if (SUCCEEDED(hr))
    {
        m_FileDialog->SetDefaultFolder(item);
        item->Release();
    }
}
//----------------------------------------------------------------------------//
void uixFileDialog::Close()
{
    if (!m_FileDialog || !m_Cookie || !m_EventHandler)
    {
        return;
    }

    m_FileDialog->Close(m_ShowResult);
}
//----------------------------------------------------------------------------//
void uixFileDialog::GetCurrentSelection(uixWString& selection)
{
    if (!m_FileDialog || !m_Cookie || !m_EventHandler)
    {
        return;
    }

    IShellItem* item = NULLPTR;

    if (SUCCEEDED(m_FileDialog->GetCurrentSelection(&item)))
    {
        uixChar* file = NULLPTR;

        if (SUCCEEDED(item->GetDisplayName(SIGDN_FILESYSPATH, &file)))
        {
            selection = file;
            CoTaskMemFree(file);
        }

        item->Release();
    }
}
//----------------------------------------------------------------------------//
void uixFileDialog::GetFileName(uixWString& selection)
{
    if (!m_FileDialog || !m_Cookie || !m_EventHandler)
    {
        return;
    }

    uixChar* file = NULLPTR;

    if (SUCCEEDED(m_FileDialog->GetFileName(&file)))
    {
        selection = file;
        CoTaskMemFree(file);
    }
}
//----------------------------------------------------------------------------//
void uixFileDialog::GetResult(uixWString& fileName)
{
    if (!m_FileDialog || !m_Cookie || !m_EventHandler)
    {
        return;
    }

    IShellItem* item = NULLPTR;

    if (SUCCEEDED(m_FileDialog->GetResult(&item)))
    {
        uixChar* file = NULLPTR;

        if (SUCCEEDED(item->GetDisplayName(SIGDN_FILESYSPATH, &file)))
        {
            fileName = file;
            CoTaskMemFree(file);
        }

        item->Release();
    }
}
//----------------------------------------------------------------------------//
void uixFileDialog::GetFolder(uixWString& folder)
{
    if (!m_FileDialog || !m_Cookie || !m_EventHandler)
    {
        return;
    }

    IShellItem* item = NULLPTR;

    if (SUCCEEDED(m_FileDialog->GetFolder(&item)))
    {
        uixChar* file = NULLPTR;

        if (SUCCEEDED(item->GetDisplayName(SIGDN_FILESYSPATH, &file)))
        {
            folder = file;
            CoTaskMemFree(file);
        }

        item->Release();
    }
}
//----------------------------------------------------------------------------//
void uixFileDialog::SetTitle(const wchar_t* title)
{
    if (!m_FileDialog || !m_Cookie || !m_EventHandler)
    {
        return;
    }

    m_FileDialog->SetTitle(title);
}
//----------------------------------------------------------------------------//
void uixFileDialog::SetOkButtonLabel(const wchar_t* title)
{
    if (!m_FileDialog || !m_Cookie || !m_EventHandler)
    {
        return;
    }

    m_FileDialog->SetOkButtonLabel(title);
}
//----------------------------------------------------------------------------//
void uixFileDialog::SetDefaultExtension(const wchar_t* extension)
{
    if (!m_FileDialog || !m_Cookie || !m_EventHandler)
    {
        return;
    }

    m_FileDialog->SetDefaultExtension(extension);
}
//----------------------------------------------------------------------------//
void uixFileDialog::SetFileNameLabel(const wchar_t* title)
{
    if (!m_FileDialog || !m_Cookie || !m_EventHandler)
    {
        return;
    }

    m_FileDialog->SetFileNameLabel(title);
}
//----------------------------------------------------------------------------//
void uixFileDialog::SetFileTypeIndex(UINT index)
{
    if (!m_FileDialog || !m_Cookie || !m_EventHandler)
    {
        return;
    }

    m_FileDialog->SetFileTypeIndex(index);
}
//----------------------------------------------------------------------------//
UINT uixFileDialog::GetFileTypeIndex() const
{
    if (!m_FileDialog || !m_Cookie || !m_EventHandler)
    {
        return 0;
    }

    UINT index = 0;
    m_FileDialog->GetFileTypeIndex(&index);
    return index;
}
//----------------------------------------------------------------------------//
void uixFileDialog::SetFileTypes(const uixFileDialogFilter filters[], UINT count)
{
    uixASSERT(filters);

    if (!m_FileDialog || !m_Cookie || !m_EventHandler)
    {
        return;
    }

    m_FileDialog->SetFileTypes(count, filters);
}
//----------------------------------------------------------------------------//
UINT_PTR uixFileDialog::DoModal(uixWindow* parent)
{
    if (!m_FileDialog || !m_Cookie || !m_EventHandler)
    {
        return FALSE;
    }

    m_ShowResult = m_FileDialog->Show(parent->GetHandleSafe());

    if (m_ShowResult == S_OK)
    {
        return IDOK;
    }

    return IDCANCEL;
}
//----------------------------------------------------------------------------//
#pragma endregion
//----------------------------------------------------------------------------//
#pragma region Message Handlers
//----------------------------------------------------------------------------//
BOOL uixFileDialog::OnFileOk()
{
    uixTRACE(_("[%s]"), __UIX_FUNCTION__);
    return TRUE;
}
//----------------------------------------------------------------------------//
BOOL uixFileDialog::OnFolderChange()
{
    uixTRACE(_("[%s]"), __UIX_FUNCTION__);
    return TRUE;
}
//----------------------------------------------------------------------------//
BOOL uixFileDialog::OnFolderChanging()
{
    uixTRACE(_("[%s]"), __UIX_FUNCTION__);
    return TRUE;
}
//----------------------------------------------------------------------------//
#pragma endregion
//----------------------------------------------------------------------------//
}
//----------------------------------------------------------------------------//