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
#ifndef _UIX_STATUSBARCTRL_H__
#define _UIX_STATUSBARCTRL_H__
//----------------------------------------------------------------------------//
#include "uixwindow.h"
//----------------------------------------------------------------------------//
namespace UIX
{
//! Handle
#define uixEVT_SBN_SIMPLEMODECHANGE(Identifier, Handler) \
    uixEVT_NOTIFY(SBN_SIMPLEMODECHANGE, Identifier, Handler)


enum uixStatusBarStyle
{
    uixStatusBarStyle_SizeGrip = SBARS_SIZEGRIP,
    uixStatusBarStyle_ToolTips = SBARS_TOOLTIPS,
};

//! Status Bar Control
//! @brief
//!     This class implements status bar control
class UIXAPI uixStatusBarCtrl : public uixWindow
{
    uixDECLARE_DYNAMIC_CLASS(uixStatusBarCtrl);
    uixDECLARE_EVENT_MAP();
public:
    //! Destructor
    virtual ~uixStatusBarCtrl();

    //! @copydoc uixWindow::BeforeWindowCreate
    virtual BOOL BeforeWindowCreate(CREATESTRUCT& cs) override;

    //! Updates layout
    //! @return
    //!     True when successful
    BOOL UpdateLayout() override;

    //! Gets icon handle
    //! @param[in] paneID
    //!     Pane ID
    //! @return
    //!     Icon handle
    HICON GetIcon(INT paneID) const;

    //! Sets icon handle
    //! @param[in] paneID
    //!     Pane ID
    //! @param[in] icon
    //!     Icon handle
    //! @return
    //!     True when successful
    BOOL SetIcon(INT paneID, HICON icon);

    //! Sets background color
    //! @param[in] color
    //!     Background color
    //! @return
    //!     Previous background color
    uixColor SetBackgroundColor(uixColor color);

    //! Gets tip text
    //! @param[in] paneID
    //!     Pane ID
    //! @param[out] text
    //!     Text buffer
    //! @param[in] length
    //!     Size of text buffer
    void GetTipText(INT paneID, uixChar* text, INT length) const;

    //! Sets tip text
    //! @param[in] paneID
    //!     Pane ID
    //! @param[in] text
    //!     Text to set
    void SetTipText(INT paneID, const uixChar* text);

    //! Gets panes
    //! @param[in] panes
    //!     Array of panes
    //! @param[in] count
    //!     Number of elements in panes array
    //! @return
    //!     Number of parts
    INT GetPanes(INT panes[], INT count) const;

    //! Sets panes
    //! @param[in] panes
    //!     Panes array
    //! @param[in] count
    //!     Number of elements in panes array
    //! @return
    //!     True when successful
    BOOL SetPanes(INT panes[], INT count);

    //! Gets borders
    //! @param[in] borders
    //!     Borders array
    //! @return
    //!     True when sucessful
    BOOL GetBorders(INT borders[3]) const;

    //! Gets pane rect
    //! @param[in] paneID
    //!     Pane ID
    //! @param[out] rect
    //!     Pane rect area
    //! @return
    //!     True when successful
    BOOL GetPaneRect(INT paneID, uixRect& rect) const;

    //! Checks if status bar is simple
    //! @return
    //!     True when successful
    BOOL IsSimple() const;

    //! Sets simple status
    //! @param[in] simple
    //!     Simple status
    //! @return
    //!     Previuos status
    BOOL SetSimple(BOOL simple);

    //! Gets pane text
    //! @param[in] paneID
    //!     Pane ID
    //! @param[out] text
    //!     Pane text
    //! @return
    //!     Text length of pane
    INT GetPaneText(INT paneID, uixChar* text) const;

    //! Gets pane text length
    //! @param[in] paneID
    //!     Pane ID
    //! @return
    //!     Text length
    INT GetPaneTextLength(INT paneID) const;

    //! Sets pane text
    //! @param[in] paneID
    //!     Pane ID
    //! @param[in] text
    //!     Pane text
    //! @return
    //!     True when successful
    BOOL SetPaneText(INT paneID, const uixChar* text);

    //! Gets unicode format support
    //! @return
    //!     True when supported
    BOOL GetUnicodeFormat() const;

    //! Sets unicode format support
    //! @param[in] unicode
    //!     Unicode format support
    //! @return
    //!     Previous support flag
    BOOL SetUnicodeFormat(BOOL unicode);

    //! Sets min height value
    //! @param[in] height
    //!     Height
    void SetMinHeight(INT height);

    //! Perform autosize
    void RecalcLayout();
};
}
//----------------------------------------------------------------------------//
#include "uixstatusbarctrl.inl"
//----------------------------------------------------------------------------//
#endif /* _UIX_STATUSBARCTRL_H__ */