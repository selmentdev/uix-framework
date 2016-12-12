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
#ifndef _UIX_EXCEPTIONDLG_H__
#define _UIX_EXCEPTIONDLG_H__
//----------------------------------------------------------------------------//
#include "uixdialog.h"
#include "uixlabel.h"
#include "uixresource.h"
#include "resource.h"
//----------------------------------------------------------------------------//
namespace UIX
{
//! Exception dialog
//! @brief
//!     This dialog window is intend to shows user message with information
//!     about unhandled exception, caught in library
class uixExceptionDlg : public uixDialog
{
    uixDECLARE_DYNAMIC_CLASS(uixExceptionDlg);
    uixDECLARE_EVENT_MAP();
public:
    //! @copydoc uixDialog::OnInitDialog
    void OnInitDialog(uixInitDialogEventArgs& e);

    //! @copydoc uixDialog::OnDestroy
    void OnDestroy(uixDestroyEventArgs& e);

    //! Creates exception dialog
    //! @param[in] parent
    //!     Parent window
    //! @return
    //!     True when successful
    BOOL Create(uixWindow* parent);

    //! Shows exception
    //! @param[in] e
    //!     Exception
    //! @return
    //!     ID of clicked button
    DWORD ShowException(const uixException& e);

private:
    uixLabel        m_Title;        //<! Title label
    uixLabel        m_Exception;    //<! Exception info label
    uixLabel        m_Icon;         //<! Icon
};
}
//----------------------------------------------------------------------------//
#endif /* _UIX_EXCEPTIONDLG_H__ */