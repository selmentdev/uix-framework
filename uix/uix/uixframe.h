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
#ifndef _UIX_FRAME_H__
#define _UIX_FRAME_H__
//----------------------------------------------------------------------------//
#include "uixwindow.h"
#include "uixview.h"
//----------------------------------------------------------------------------//
namespace UIX
{
//! Frame window
//! @brief
//!     Frame window is main application window
class UIXAPI uixFrame : public uixWindow
{
    uixDECLARE_DYNAMIC_CLASS(uixFrame);
    uixDECLARE_EVENT_MAP();
public:
    //! Constructor
    uixFrame();
    //! Destructor
    virtual ~uixFrame();

    //! Creates frame
    //! @return
    //!     True when successful
    BOOL CreateFrame();

    //! Creates frame
    //! @return
    //!     True when successful
    BOOL CreateFrame(const uixChar* caption);

    //! Loads accelerator table
    //! @param[in] accelID
    //!     ID of resource to load
    //! @return
    //!     true when successful
    BOOL LoadAccelTable(uixResourceID accelID);

    //! Loads accelerator table
    //! @param[in] accelName
    //!     Name of resource to load
    //! @return
    //!     true when successful
    BOOL LoadAccelTable(uixResourceName accelName);

    //! Loads accelerator table
    //! @param[in] instance
    //!     Handle to instance of module with resource
    //! @param[in] accelID
    //!     ID of resource to load
    //! @return
    //!     true when successful
    BOOL LoadAccelTable(HINSTANCE instance, uixResourceID accelID);

    //! Loads accelerator table
    //! @param[in] instance
    //!     Handle to instance of module with resource
    //! @param[in] accelName
    //!     Name of resource to load
    //! @return
    //!     true when successful
    BOOL LoadAccelTable(HINSTANCE instance, uixResourceName accelName);

    //! @copydoc uixWindow::BeforeTranslateMessage
    virtual BOOL BeforeTranslateMessage(MSG* m) override;

    //! @copydoc uixWindow::BeforeWindowCreate
    virtual BOOL BeforeWindowCreate(CREATESTRUCT& cs) override;

    //! Sets new view
    //! @param[in] view
    //!     New view
    //! @param[in] deleteView
    //!     True to delete previous view
    virtual void SetView(uixView* view, BOOL deleteView = FALSE);

    //! Gets current view
    //! @return
    //!     Pointer to view
    virtual uixView* GetView() const;

    //! Close frame
    //! @return
    //!     True when successful
    BOOL Close();

    //! @copydoc uixWindow::OnClose
    void OnClose(uixCloseEventArgs& e);
private:
    HACCEL      m_AccelTable;   //!< Accelerator table for this window
    uixView*    m_View;         //!< View
};
}
//----------------------------------------------------------------------------//
#include "uixframe.inl"
//----------------------------------------------------------------------------//
#endif /* _UIX_FRAME_H__ */