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
#ifndef _UIX_ABOUTDLG_H__
#define _UIX_ABOUTDLG_H__
//----------------------------------------------------------------------------//
#include "uixdialog.h"
#include "uixlabel.h"
#include "uixbuttonctrl.h"
#include "resource.h"
#include "uixresid.h"
//----------------------------------------------------------------------------//
namespace UIX
{
//! About Dialog
//! @brief
//!     This class create about dialog in application. Any resources needed
//!     by this dialog are stored in uix10.dll library
//! @par How to use
//! \code
//! uixAboutDlg dlg;
//! dlg.Create(this);
//! dlg.SetAppName(_("Example"));
//! dlg.DoModal();
//! \endcode
class UIXAPI uixAboutDlg : public uixDialog
{
    uixDECLARE_DYNAMIC_CLASS(uixAboutDlg);
    uixDECLARE_EVENT_MAP();
public:
    //! @copydoc uixDialog::OnInitDialog
    void OnInitDialog(uixInitDialogEventArgs& e);

    //! @copydoc uixDialog::OnDestroy
    void OnDestroy(uixDestroyEventArgs& e);

    //! Sets license text
    //! @param[in] license
    //!     License text
    void SetLicense(const uixString& license);

    //! Sets application name
    //! @param[in] appName
    //!     Application name
    void SetAppName(const uixString& appName);

    //! Sets content text
    //! @param[in] content
    //!     Content text
    void SetContent(const uixString& content);

    //! Sets vertical bar image handle
    //! @param[in] bitmap
    //!     Bitmap handle
    void SetVerticalBarImage(HBITMAP bitmap);

    //! Creates about dialog
    //! @param[in] parent
    //!     Parent window
    //! @return
    //!     True when successful
    BOOL Create(uixWindow* parent);

    //! @copydoc uixDialog::DoModal
    virtual DWORD DoModal() override;

private:
    uixLabel        m_License;      //<! License label
    uixLabel        m_AppName;      //<! Application name label
    uixLabel        m_Content;      //<! Content text label
    uixLabel        m_VertBar;      //<! Vertical bar image
    uixButton       m_TechSupport;  //<! Additional tech support
    uixButton       m_SystemInfo;   //<! System info button

    enum IDs
    {
        ID_LBL_LICENSE      = 1000,
        ID_LBL_APPNAME      = 1001,
        ID_LBL_CONTENT      = 1002,
        ID_BTN_OK           = uixID_OK,
        ID_BTN_SYSTEMINFO   = 1003,
        ID_BTN_TECHSUPPORT  = 1004,
        ID_IMG_VERTBAR      = 1005,
    };
};
}
//----------------------------------------------------------------------------//
#endif /* _UIX_ABOUTDLG_H__ */