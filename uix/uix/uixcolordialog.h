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
#ifndef _UIX_COLORDIALOG_H__
#define _UIX_COLORDIALOG_H__
//----------------------------------------------------------------------------//
#include "uixwindow.h"
//----------------------------------------------------------------------------//
namespace UIX
{
//! Color Choose dialog
//! @brief
//!     This class implements color choosing dialog
class UIXAPI uixColorDialog : public uixObject
{
    uixDECLARE_DYNAMIC_CLASS(uixColorDialog);
public:
    //! Constructor
    //! @param[in] parent
    //!     Parent window
    //! @param[in] color
    //!     Selected color
    //! @param[in] flags
    //!     Additional flags
    uixColorDialog(uixWindow* parent = NULLPTR, uixColor color = (uixColor)0, DWORD flags = 0);

    //! Destructor
    virtual ~uixColorDialog();

    //! Shows modal dialog
    //! @param[in] parent
    //!     Parent window
    //! @return
    //!     ID result value
    DWORD DoModal(uixWindow* parent = NULLPTR);

    //! Gets selected color
    //! @return
    //!     Selected color
    uixColor GetColor() const;
private:
    ::CHOOSECOLOR   m_Data;     //!< Color data from Windows
};
}
//----------------------------------------------------------------------------//
#include "uixcolordialog.inl"
//----------------------------------------------------------------------------//
#endif /* _UIX_COLORDIALOG_H__ */