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
#ifndef _UIX_VIEW_H__
#define _UIX_VIEW_H__
//----------------------------------------------------------------------------//
#include "uixwindow.h"
//----------------------------------------------------------------------------//
namespace UIX
{
//! View class
//! @brief
//!     View class is base class for all views.
class UIXAPI uixView : public uixWindow
{
    uixDECLARE_DYNAMIC_CLASS(uixView);
public:
    //! Create view window
    //! @param[in] parent
    //!     Parent window
    //! @param[in] text
    //!     Text
    //! @param[in] position
    //!     Position
    //! @param[in] size
    //!     Size
    //! @param[in[] style
    //!     Style
    //! @return
    //!     True when successful
    virtual BOOL Create(
        uixWindow* parent,
        const uixChar* text,
        const uixPoint& position,
        const uixSize& size,
        DWORD style);

    //! @copydoc uixWindow::BeforeTranslateMessage
    virtual BOOL BeforeTranslateMessage(MSG* m) override;

    //! @copydoc uixWindow::BeforeWindowCreate
    virtual BOOL BeforeWindowCreate(CREATESTRUCT& cs) override;
};
}
//----------------------------------------------------------------------------//
#endif /* _UIX_VIEW_H__ */