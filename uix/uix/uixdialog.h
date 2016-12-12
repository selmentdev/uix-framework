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
#pragma once
#ifndef _UIX_DIALOG_H__
#define _UIX_DIALOG_H__
//----------------------------------------------------------------------------//
#include "uixwindow.h"
#include "uixstate.h"
#include "uixthreading.h"
//----------------------------------------------------------------------------//
namespace UIX
{
//! Default Dialog window proc
//! @note
//!     This procedure is used only to handle WM_INITDIALOG message, all others
//!     are automagically passed to WindowProc and so on
UINT_PTR CALLBACK UixDlgProc(HWND h, UINT u, WPARAM j, LPARAM a);

//! Dialog
//! @brief
//!     This class implements modal / modeless dialog
//!
//! @par Modal dialog
//!     To run dialog as a modal dialog, you must create uixDialog instance (typically,
//!     as variable on stack) and call DoModal method.
//!
//! @par Modeless dialog
//!     Modeless dialogs are dialogs, which live much longer than modal dialogs, so
//!     instance of uixDialog must be variable on parent window or created dynamically
//!     via new / delete.
//!
//! @par Dialog Application
//!     Because uixDialog uses own message loop (also known as modal loop), when you
//!     want to create application with only a dialog window, you should override
//!     uixApplication::InitInstance, to run modal loop (using uixDialog::DoModal)
//!     and return false to prevent running global application loop
/**@code
BOOL MyApplication::InitInstance()
{
uixApplication::InitInstance();

m_Dialog = new uixDialog();
m_Dialog->Create(&m_MainForm, MAKEINTRESOURCE(IDD_DIALOG1));
m_Dialog->DoModal();

return FALSE;
}
@endcode*/
class UIXAPI uixDialog : public uixWindow
{
    uixDECLARE_DYNAMIC_CLASS(uixDialog);
    uixDECLARE_EVENT_MAP();
protected:
    //! Process message
    //! @note
    //!     This method calls thread's ProcessMessage
    //! @param[in] m
    //!     Message to process
    //! @return
    //!     true when successful
    BOOL ProcessMessage(MSG* m);

    //! Checks if message is an idle message
    //! @note
    //!     This method calls thread's IsIdleMessage
    //! @param[in] m
    //!     Message to check
    //! @return
    //!     True when successful
    BOOL IsIdleMessage(MSG* m);

    //! Enters modal loop
    //! @param[in] flags
    //!     Flags
    //! @return
    //!     Modal result
    INT BeginModalLoop(UINT flags);

    //! Ends modal loop
    //! @param[in] result
    //!     Modal result
    void EndModalLoop(INT result);

    //! Ends dialog modal loop with result value
    //! @brief
    //!     Call to end dialog with modal result
    //! @param[in] result
    //!     Modal result
    void EndDialog(INT result);

    UINT m_Flags;       //!< Modal dialog flags
    INT m_ModalResult;  //!< Modal result
public:
    //! Constructor
    uixDialog();

    //! Destructor
    virtual ~uixDialog();

    //! Create dialog frame
    //! @param[in] parent
    //!     Parent window
    //! @param[in] templateName
    //!     Teplate name
    //! @return
    //!     True when successful
    BOOL CreateDlgFrame(uixWindow* parent, uixResourceName templateName);

    //! Create dialog frame
    //! @param[in] parent
    //!     Parent window
    //! @param[in] instance
    //!     Module handle
    //! @param[in] templateName
    //!     Teplate name
    //! @return
    //!     True when successful
    BOOL CreateDlgFrame(uixWindow* parent, HINSTANCE instance, uixResourceName templateName);

    //! Create dialog frame
    //! @param[in] parent
    //!     Parent window
    //! @param[in] templateID
    //!     Teplate ID
    //! @return
    //!     True when successful
    BOOL CreateDlgFrame(uixWindow* parent, uixResourceID templateID);

    //! Create dialog frame
    //! @param[in] parent
    //!     Parent window
    //! @param[in] instance
    //!     Module handle
    //! @param[in] templateID
    //!     Teplate ID
    //! @return
    //!     True when successful
    BOOL CreateDlgFrame(uixWindow* parent, HINSTANCE instance, uixResourceID templateID);

    //! @copydoc uixWindow::BeforeWindowCreate
    virtual BOOL BeforeWindowCreate(CREATESTRUCT& cs) override;

    //! @copydoc uixWindow::BeforeTranslateMessage
    virtual BOOL BeforeTranslateMessage(MSG* m) override;

    //! Called when dialog begins modal state
    virtual void BeginModalState();

    //! Called when dialog ends modal state
    virtual void EndModalState();

    //! Shows modal dialog
    //! @brief
    //!     Enters modal loop and shows dialog.
    //! @note
    //!     It is possible to handle nested modal dialogs, since processed
    //!     message is preserved.
    //! @return
    //!     ID of button clicked by user
    virtual DWORD DoModal();

    //! Called when dialog is initialized
    //! @return
    //!     False to fail
    virtual BOOL OnInitDialog();

    //! Called when user clicked close button
    void OnClose(uixCloseEventArgs& e);

    //! Called when user clicked OK button
    virtual void OnOK(uixCommandEventArgs& e);

    //! Called when user clicked Cancel button
    virtual void OnCancel(uixCommandEventArgs& e);

    //! Called when system change colors
    void OnControlColor(uixControlColorEventArgs& e);
};
}
//----------------------------------------------------------------------------//
#endif /* _UIX_DIALOG_H__ */