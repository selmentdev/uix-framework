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
#ifndef _UIX_TOOLTIPCTRL_H__
#define _UIX_TOOLTIPCTRL_H__
//----------------------------------------------------------------------------//
#include "uixwindow.h"
#include "uixstate.h"
//----------------------------------------------------------------------------//
namespace UIX
{
//! Handle
#define uixEVT_TTN_GETDISPINFO(Identifier, Handler) \
    uixEVT_NOTIFY(TTN_GETDISPINFO, Identifier, Handler)

//! Handle
#define uixEVT_TTN_LINKCLICK(Identifier, Handler) \
    uixEVT_NOTIFY(TTN_LINKCLICK, Identifier, Handler)

//! Handle
#define uixEVT_TTN_NEEDTEXT(Identifier, Handler) \
    uixEVT_NOTIFY(TTN_NEEDTEXT, Identifier, Handler)

//! Handle
#define uixEVT_TTN_POP(Identifier, Handler) \
    uixEVT_NOTIFY(TTN_POP, Identifier, Handler)

//! Handle
#define uixEVT_TTN_SHOW(Identifier, Handler) \
    uixEVT_NOTIFY(TTN_SHOW, Identifier, Handler)

//! Tool Tip Tool Info
//! @todo Implement
struct uixToolTipToolInfo : TOOLINFO
{
    //! Create tool tip info data from window
    //! @param[in] window
    //!     Window pointer
    //! @param[in] text
    //!     Tool tip text
    //! @return
    //!     Tool tip info data
    static uixToolTipToolInfo ForWindow(uixWindow* window, const uixChar* text);

    //! Create tool tip info data from rect
    //! @param[in] window
    //!     Parent window
    //! @param[in] rc
    //!     Rectangle
    //! @param[in] text
    //!     Tool tip text
    //! @return
    //!     Tool tip info data
    static uixToolTipToolInfo ForRect(uixWindow* parent, const RECT& rc, const uixChar* text = NULLPTR);
};

//! Tool Tip Get Title
//! @todo Implement
struct uixToolTipGetTitle : TTGETTITLE
{
};

enum uixToolTipStyle
{
    uixToolTipStyle_AlwaysTip = TTS_ALWAYSTIP,
    uixToolTipStyle_Balloon = TTS_BALLOON,
    uixToolTipStyle_Close = TTS_CLOSE,
    uixToolTipStyle_NoAnimate = TTS_NOANIMATE,
    uixToolTipStyle_NoFade = TTS_NOFADE,
    uixToolTipStyle_NoPrefix = TTS_NOPREFIX,
    uixToolTipStyle_UseVisualStyle = TTS_USEVISUALSTYLE,
};

//! Tool tip control
//! @brief
//!     This control allows to auto create hint boxes above specified
//!     controls or areas of attached control
class UIXAPI uixToolTipCtrl : public uixWindow
{
    uixDECLARE_DYNAMIC_CLASS(uixToolTipCtrl);
public:
    //! Constructor
    //! @param[in] handle
    //!     Handle
    uixToolTipCtrl(HWND handle = 0);

    //! Destructor
    virtual ~uixToolTipCtrl();

    //! @copydoc uixWindow::BeforeWindowCreate
    virtual BOOL BeforeWindowCreate(CREATESTRUCT& cs) override;

    //! Sets text
    //! @param[in] info
    //!     Tool info
    void SetText(TOOLINFO& info);

    //! Gets tool info
    //! @param[out] info
    //!     Tool info
    //! @return
    //!     True when successful
    BOOL GetToolInfo(TOOLINFO& info);

    //! Sets tool info
    //! @param[in] info
    //!     Tool info
    void SetToolInfo(TOOLINFO& info);

    //! Sets tool rect
    //! @param[in] info
    //!     Tool info
    void SetToolRect(TOOLINFO& info);

    //! Sets tool rect
    //! @param[in] handle
    //!     Window handle
    //! @param[in] rect
    //!     Rectangle
    //! @param[in] id
    //!     Tool ID
    //! @return
    //!     True when successful
    BOOL SetToolRect(HWND handle, RECT& rect, UINT id);

    //! Gets tools count
    //! @return
    //!     Tools count
    INT GetToolCount();

    //! Gets delay time
    //! @param[in] type
    //!     Delay type
    //! @return
    //!     Delay time
    INT GetDelayTime(DWORD type);

    //! Sets delay time
    //! @param[in] type
    //!     Delay type
    //! @param[in] time
    //!     Delay time
    void SetDelayTime(DWORD type, INT time);

    //! Gets margins
    //! @param[out] rect
    //!     Margins
    void GetMargin(RECT& rect);

    //! Sets margin
    //! @param[in] rect
    //!     Margins
    void SetMargin(const RECT& rect);

    //! Gets max tip width
    //! @return
    //!     Max tip width
    INT GetMaxTipWidth() const;

    //! Sets max tip width
    //! @param[in] width
    //!     New max tip width
    //! @return
    //!     Previous max tip width
    INT SetMaxTipWidth(INT width) const;

    //! Gets tip background color
    //! @return
    //!     Background color
    uixColor GetTipBackgroundColor() const;

    //! Sets tip background color
    //! @param[in] color
    //!     New background color
    void SetTipBackgroundColor(uixColor color);

    //! Gets tip text color
    //! @return
    //!     Tip text color
    uixColor GetTipTextColor() const;

    //! Sets tip text color
    //! @param[in] color
    //!     New text color
    void SetTipTextColor(uixColor color);

    //! Gets current tool
    //! @param[out]toolInfo
    //!     Tool info
    //! @return
    //!     True when successful
    BOOL GetCurrentTool(TOOLINFO* toolInfo);

    //! Activate tooltip
    //! @param[in] active
    //!     Active status
    void Activate(BOOL active);

    //! Adds tool info
    //! @param[in] info
    //!     Tool info
    void AddToolInfo(TOOLINFO& info);

    //! Updates tip text
    //! @param[in] window
    //!     Window
    //! @param[in] text
    //!     New text
    //! @param[out] rect
    //!     Rectangle
    //! @param[in] id
    //!     Tool ID
    //! @return
    //!     True when successful
    BOOL UpdateTipText(HWND window, uixChar* text = LPSTR_TEXTCALLBACK, RECT* rect = NULLPTR,
                       UINT id = 0);

    //! Adds tool
    //! @param[in] window
    //!     Window
    //! @param[in] text
    //!     Tool text
    //! @param[in] rect
    //!     Rectangle
    //! @param[in] id
    //!     ID
    BOOL AddTool(HWND window, uixChar* text = LPSTR_TEXTCALLBACK, const RECT* rect = NULLPTR,
                 UINT id = 0);

    //! Delete tool
    //! @param[in] ti
    //!     Tool info to delete
    void DeleteTool(TOOLINFO& ti);

    //! Performs hit test
    //! @param[int] hti
    //!     Hit test data
    //! @return
    //!     True when successful
    BOOL HitTest(TTHITTESTINFO& hti);

    //! Relay event
    //! @param[in] msg
    //!     Message
    void RelayEvent(MSG* msg);

    //! Updates tip text
    //! @param[in] ti
    //!     Tool info
    void UpdateTipText(TOOLINFO& ti);

    //! Enumerate tools
    //! @param[in] index
    //!     Tool index
    //! @param[out] ti
    //!     Tool info
    //! @return
    //!     True when available
    BOOL EnumTools(UINT index, TOOLINFO& ti);

    //! Pops tool tip
    void Pop();

    //! Tracks activate control
    //! @param[out] ti
    //!     Tool info
    //! @param[in] activate
    //!     Activate
    void TrackActivate(TOOLINFO& ti, BOOL activate);

    //! Tracks position
    //! @param[in] x
    //!     Left coord
    //! @param[in] y
    //!     Top coord
    void TrackPosition(INT x, INT y);

    //! Updates control
    void Update();

    //! Adjusts rectangle
    //! @param[out] rect
    //!     Rectangle to adjust
    //! @param[in] larger
    //!     True to larger, smaller otherwise
    //! @return
    //!     True when successful
    BOOL AdjustRect(RECT& rect, BOOL larger = TRUE);

    //! Gets bubble size
    //! @param[in] ti
    //!     Tool info
    //! @return
    //!     Bubble size
    DWORD GetBubbleSize(TOOLINFO& ti);

    //! Sets title
    //! @param[in] icon
    //!     Icon ID
    //! @param[in] title
    //!     Title text
    //! @return
    //!     True when successful
    BOOL SetTitle(UINT icon, const uixChar* title);

    //! Popups tool tip
    void Popup();

    //! Gets title info
    //! @param[out] ttgt
    //!     Title info
    void GetTitle(TTGETTITLE& ttgt);

    //! Sets window theme
    //! @param[in] theme
    //!     Window theme name
    void SetWindowTheme(const uixChar* theme);
};
}
//----------------------------------------------------------------------------//
#include "uixtooltipctrl.inl"
//----------------------------------------------------------------------------//
#endif /* _UIX_TOOLTIPCTRL_H__ */