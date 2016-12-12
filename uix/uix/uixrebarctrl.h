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
#ifndef _UIX_REBARCTRL_H__
#define _UIX_REBARCTRL_H__
//----------------------------------------------------------------------------//
#include "uixwindow.h"
#include "uixtoolbarctrl.h"
//----------------------------------------------------------------------------//
namespace UIX
{
//! Handle
#define uixEVT_RBN_AUTOBREAK(Identifier, Handler) \
    uixEVT_NOTIFY(RBN_AUTOBREAK, Identifier, Handler)

//! Handle
#define uixEVT_RBN_AUTOSIZE(Identifier, Handler) \
    uixEVT_NOTIFY(RBN_AUTOSIZE, Identifier, Handler)

//! Handle
#define uixEVT_RBN_BEGINDRAG(Identifier, Handler) \
    uixEVT_NOTIFY(RBN_BEGINDRAG, Identifier, Handler)

//! Handle
#define uixEVT_RBN_CHEVRONPUSHED(Identifier, Handler) \
    uixEVT_NOTIFY(RBN_CHEVRONPUSHED, Identifier, Handler)

//! Handle
#define uixEVT_RBN_CHILDSIZE(Identifier, Handler) \
    uixEVT_NOTIFY(RBN_CHILDSIZE, Identifier, Handler)

//! Handle
#define uixEVT_RBN_DELETEDBAND(Identifier, Handler) \
    uixEVT_NOTIFY(RBN_DELETEDBAND, Identifier, Handler)

//! Handle
#define uixEVT_RBN_DELETINGBAND(Identifier, Handler) \
    uixEVT_NOTIFY(RBN_DELETINGBAND, Identifier, Handler)

//! Handle
#define uixEVT_RBN_ENDDRAG(Identifier, Handler) \
    uixEVT_NOTIFY(RBN_ENDDRAG, Identifier, Handler)

//! Handle
#define uixEVT_RBN_GETOBJECT(Identifier, Handler) \
    uixEVT_NOTIFY(RBN_GETOBJECT, Identifier, Handler)

//! Handle
#define uixEVT_RBN_HEIGHTCHANGE(Identifier, Handler) \
    uixEVT_NOTIFY(RBN_HEIGHTCHANGE, Identifier, Handler)

//! Handle
#define uixEVT_RBN_LAYOUTCHANGED(Identifier, Handler) \
    uixEVT_NOTIFY(RBN_LAYOUTCHANGED, Identifier, Handler)

//! Handle
#define uixEVT_RBN_MINMAX(Identifier, Handler) \
    uixEVT_NOTIFY(RBN_MINMAX, Identifier, Handler)

//! Handle
#define uixEVT_RBN_SPLITTERDRAG(Identifier, Handler) \
    uixEVT_NOTIFY(RBN_SPLITTERDRAG, Identifier, Handler)

enum enumUixRebarBandStyle
{
    uixRebarBandStyle_Break = RBBS_BREAK,
    uixRebarBandStyle_ChildEdge = RBBS_CHILDEDGE,
    uixRebarBandStyle_FixedBmp = RBBS_FIXEDBMP,
    uixRebarBandStyle_FixedSize = RBBS_FIXEDSIZE,
    uixRebarBandStyle_GripperAlways = RBBS_GRIPPERALWAYS,
    uixRebarBandStyle_Hidden = RBBS_HIDDEN,
    uixRebarBandStyle_NoGripper = RBBS_NOGRIPPER,
    uixRebarBandStyle_UseChevron = RBBS_USECHEVRON,
    uixRebarBandStyle_VariableHeight = RBBS_VARIABLEHEIGHT,
    uixRebarBandStyle_NoVertical = RBBS_NOVERT,
    uixRebarBandStyle_HideTitle = RBBS_HIDETITLE,
    uixRebarBandStyle_TopAlign = RBBS_TOPALIGN,
};
typedef UINT uixRebarBandStyle;

//! Rebar Band Info
struct uixRebarBandInfo : REBARBANDINFO
{
    //! Constructor
    uixRebarBandInfo();

    //! Gets rebar band style
    //! @return
    //!     Style
    uixRebarBandStyle GetStyle() const;

    //! Sets rebar band style
    //! @param[in] style
    //!     Style
    void SetStyle(uixRebarBandStyle value);

    //! Gets foreground color
    //! @return
    //!     Foreground color
    uixColor GetForegroundColor() const;

    //! Sets foreground color
    //! @param[in] value
    //!     Foreground color
    void SetForegroundColor(uixColor value);

    //! Gets background color
    //! @return
    //!     Background color
    uixColor GetBackgroundColor() const;

    //! Sets background color
    //! @param[in] value
    //!     Background color
    void SetBackgroundColor(uixColor value);

    //! Gets text
    //! @return
    //!     Text
    const uixChar* GetText() const;

    //! Sets text
    //! @param[in] value
    //!     Text
    void SetText(const uixChar* value);

    //! Sets text
    //! @param[in] value
    //!     Text
    //! @param[in] length
    //!     Text length
    void SetText(const uixChar* value, INT length);

    //! Gets text length
    //! @return
    //!     Text length
    INT GetTextLength() const;

    //! Sets text length
    //! @param[in] length
    //!     Text length
    void SetTextLength(INT length);

    //! Gets image index
    //! @return
    //!     Image index
    INT GetImage() const;

    //! Sets image index
    //! @param[in] image
    //!     Image index
    void SetImage(INT image);

    //! Gets child window
    //! @return
    //!     Handle to child window
    HWND GetChildWindow() const;

    //! Sets child window
    //! @param[in] handle
    //!     Child window handle
    void SetChildWindow(HWND handle);

    //! Gets min child size
    //! @param[out] size
    //!     Size
    void GetMinChildSize(SIZE& size) const;

    //! Sets min child size
    //! @param[in] size
    //!     Child size
    void SetMinChildSize(const SIZE& size);

    //! Gets child height
    //! @return
    //!     Child height
    UINT GetChildHeight() const;

    //! Sets child height
    //! @param[in] height
    //!     Child height
    void SetChildHeight(UINT height);

    //! Gets child max height
    //! @return
    //!     Max height
    UINT GetChildMaxHeight() const;

    //! Sets max child height
    //! @param[in] height
    //!     Max height
    void SetChildMaxHeight(UINT height);

    //! Gets width
    //! @return
    //!     Width
    UINT GetWidth() const;

    //! Sets width
    //! @param[in] width
    //!     Width
    void SetWidth(UINT width);

    //! Gets background bitmap handle
    //! @return
    //!     Handle to background bitmap
    HBITMAP GetBackgroundBitmap() const;

    //! Sets background bitmap handle
    //! @param[in] handle
    //!     Background bitmap handle
    void SetBackgroundBitmap(HBITMAP handle);

    //! Gets band ID
    //! @return
    //!     ID
    UINT GetID() const;

    //! Sets band ID
    //! @param[in] value
    //!     Band ID
    void SetID(UINT value);

    //! Gets ideal size
    //! @return
    //!     Ideal size
    UINT GetIdealSize() const;

    //! Sets ideal size
    //! @param[in] size
    //!     Ideal size
    void SetIdealSize(UINT size);

    //! Gets integral step
    //! @return
    //!     Integral steop
    UINT GetIntegralStep() const;

    //! Sets integral step
    //! @param[in] value
    //!     Integral step value
    void SetIntegralStep(UINT value);

    //! Gets data
    //! @return
    //!     Data
    void* GetData() const;

    //! Sets data
    //! @param[in] value
    //!     Data
    void SetData(const void* value);

    //! Gets header size
    //! @return
    //!     Header size
    UINT GetHeaderSize() const;

    //! Sets header size
    //! @param[in] value
    //!     Header size
    void SetHeaderSize(UINT value);

    //! Gets chevron location
    //! @param[out] rect
    //!     Chevron location
    BOOL GetChevronLocation(RECT& rect) const;

    //! Sets chevron location
    //! @param[in] rect
    //!     New chevron location
    void SetChevronLocation(const RECT& rect);

    //! Gets chevron state
    //! @return
    //!     Chevron state
    UINT GetChevronState() const;

    //! Sets chevron state
    //! @param[in] state
    //!     Chevron state
    void SetChevronState(UINT state);
};

//! Rebar Info
struct uixRebarInfo : REBARINFO
{
    //! Constructor
    uixRebarInfo();

    //! Gets image list handle
    //! @return
    //!     Image list handle
    HIMAGELIST GetImageList() const;

    //! Sets image list handle
    //! @param[in] handle
    //!     Image list handle
    void SetImageList(HIMAGELIST handle);
};

//! Color Sheme
struct uixColorSheme : COLORSCHEME
{
    //! Constructor
    uixColorSheme();

    //! Gets hightlight color
    //! @return
    //!     Highlight color
    uixColor GetHighlight() const;

    //! Sets highlight color
    //! @param[in] color
    //!     Highlight color
    void SetHighlight(uixColor color);

    //! Gets shadow color
    //! @return
    //!     Shadow color
    uixColor GetShadow() const;

    //! Sets shadow color
    //! @param[in] color
    //!     Shadow color
    void SetShadow(uixColor color);
};

//! Rebar Hit Test
struct uixRebarHitTest : RBHITTESTINFO
{
};

//! Rebar sty;e
enum uixRebarStyle
{
    //! Auto size
    uixRebarStyle_AutoSize = RBS_AUTOSIZE,
    //! Band borders
    uixRebarStyle_BandBorders = RBS_BANDBORDERS,
    //! Double click toggle
    uixRebarStyle_DoubleClickToggle = RBS_DBLCLKTOGGLE,
    //! Fixed order
    uixRebarStyle_FixedOrder = RBS_FIXEDORDER,
    //! Register drop
    uixRebarStyle_RegisterDrop = RBS_REGISTERDROP,
    //! Tool tips
    uixRebarStyle_ToolTips = RBS_TOOLTIPS,
    //! Variable height
    uixRebarStyle_VarHeight = RBS_VARHEIGHT,
    //! Vertical gripper
    uixRebarStyle_VerticalGripper = RBS_VERTICALGRIPPER,
};

//! Rebar Control
//! @brief
//!     This class implements rebar control, which allow to store another
//!     controls in movable bars
class UIXAPI uixRebarCtrl : public uixWindow
{
    uixDECLARE_DYNAMIC_CLASS(uixRebarCtrl);
    uixDECLARE_EVENT_MAP();
public:
    //! Constructor
    uixRebarCtrl();

    //! Destructor
    virtual ~uixRebarCtrl();

    //! @copydoc uixWindow::BeforeWindowCreate
    virtual BOOL BeforeWindowCreate(CREATESTRUCT& cs) override;

    //! @copydoc uixWindow::OnCreate
    void OnCreate(uixCreateEventArgs& e);

    //! Adds bar
    //! @param[in] toolBar
    //!     Tool bar control
    //! @param[in] id
    //!     ID
    //! @param[in] title
    //!     Bar title
    //! @param[in] newRow
    //!     Move to new row
    //! @param[in] style
    //!     Style
    //! @return
    //!     True when successful
    BOOL AddBar(
        uixToolBarCtrl* toolBar,
        uixWindowID id,
        const uixChar* title = NULLPTR,
        BOOL newRow = FALSE,
        uixRebarBandStyle style =
            uixRebarBandStyle_GripperAlways
            | uixRebarBandStyle_UseChevron);

    //! Gets bands count
    //! @return
    //!     Number of bands
    UINT GetBandCount() const;

    //! Gets band info
    //! @param[in] bandID
    //!     Band ID
    //! @param[out] band
    //!     Band info
    //! @return
    //!     True when successful
    BOOL GetBandInfo(UINT bandID, REBARBANDINFO& band) const;

    //! Sets band info
    //! @param[in] bandID
    //!     Band ID
    //! @param[in] band
    //!     Band info
    //! @return
    //!     True when successful
    BOOL SetBandInfo(UINT bandID, const REBARBANDINFO& band);

    //! Gets bar info
    //! @param[out] info
    //!     Bar info
    //! @return
    //!     True when successful
    BOOL GetBarInfo(REBARINFO& info) const;

    //! Sets bar info
    //! @param[in] info
    //!     Bar info
    //! @return
    //!     True when successful
    BOOL SetBarInfo(const REBARINFO& info);

    //! Gets row count
    //! @return
    //!     Number of rows
    UINT GetRowCount() const;

    //! Gets row height
    //! @param[in] bandID
    //!     Band ID
    //! @return
    //!     Row height
    UINT GetRowHeight(UINT bandID) const;

    //! Gets text color
    //! @return
    //!     Text color
    uixColor GetTextColor() const;

    //! Sets text color
    //! @param[in] color
    //!     New text color
    //! @return
    //!     Previous text color
    uixColor SetTextColor(uixColor color);

    //! Gets background color
    //! @return
    //!     Background color
    uixColor GetBackgroundColor() const;

    //! Sets background color
    //! @param[in] color
    //!     Background color
    //! @return
    //!     Previous background color
    uixColor SetBackgroundColor(uixColor color);

    //! Gets bar height
    //! @return
    //!     Bar hegiht
    UINT GetBarHeight() const;

    //! Gets band rect
    //! @param[in] bandID
    //!     Band ID
    //! @return[out] rect
    //!     Rect
    //! @return
    //!     True when successful
    BOOL GetRect(UINT bandID, RECT& rect) const;

    //! Gets tooltips window
    //! @return
    //!     Handle to tooltips window
    HWND GetToolTips() const;

    //! Sets tooltips window handle
    //! @param[in] handle
    //!     Handle to tooltips window
    void SetToolTips(HWND handle);

    //! Gets band borders
    //! @param[in] bandID
    //!     Band ID
    //! @param[out] rect
    //!     Rect
    void GetBandBorders(UINT bandID, RECT& rect) const;

    //! Gets color scheme
    //! @param[out] scheme
    //!     Color scheme
    //! @return
    //!     True when successful
    BOOL GetColorScheme(COLORSCHEME& scheme) const;

    //! Sets color scheme
    //! @param[in] scheme
    //!     Color scheme
    void SetColorScheme(const COLORSCHEME& scheme);

    //! Gets palette
    //! @return
    //!     Current palette
    HPALETTE GetPalette() const;

    //! Sets palette
    //! @param[in] palette
    //!     New palette
    //! @return
    //!     Previuos palette
    HPALETTE SetPalette(HPALETTE palette);

    //! Gets unicode format support
    //! @return
    //!     True when unicode supported
    BOOL GetUnicodeFormat() const;

    //! Sets unicode support
    //! @param[in] unicode
    //!     Flag
    //! @return
    //!     Previous unicode state
    BOOL SetUnicodeFormat(BOOL unicode = TRUE);

    //! Inserts band
    //! @param[in] rbbi
    //!     Band info
    //! @param[in] bandID
    //!     Band ID
    //! @return
    //!     True when successful
    BOOL InsertBand(REBARBANDINFO& rbbi, INT bandID = -1);

    //! Deletes band
    //! @param[in] bandID
    //!     Band ID
    //! @return
    //!     True when successful
    BOOL DeleteBand(INT bandID);

    //! Sets notify window
    //! @param[in] window
    //!     New notify window
    //! @return
    //!     Previous notify window
    HWND SetNotifyWindow(HWND window);

    //! Begin drag band
    //! @param[in] bandID
    //!     Band ID
    //! @param[in] position
    //!     Position
    void BeginDrag(INT bandID, DWORD position);

    //! Begin drag band
    //! @param[in] bandID
    //!     Band ID
    //! @param[in] x
    //!     Left position
    //! @param[in] y
    //!     Top position
    void BeginDrag(INT bandID, INT x, INT y);

    //! Begin drag band
    //! @param[in] bandID
    //!     Band ID
    //! @param[in] pt
    //!     Position
    void BeginDrag(INT bandID, POINT pt);

    //! Ends drag
    void EndDrag();

    //! Drag move
    //! @param[in] position
    //!     Position
    void DragMove(DWORD position);

    //! Drag move
    //! @param[in] x
    //!     Left position
    //! @param[in] x
    //!     Left position
    void DragMove(INT x, INT y);

    //! Drag move
    //! @param[in] pt
    //!     Position
    void DragMove(POINT pt);

    //! Maximize band
    //! @param[in] bandID
    //!     Band to maximize
    void MaximizeBand(INT bandID);

    //! Minimize band
    //! @param[in] bandID
    //!     Band to minimize
    void MinimizeBand(INT bandID);

    //! Size to rect
    //! @param[out] rect
    //!     Rect to size
    //! @return
    //!     True when successful
    BOOL SizeToRect(RECT& rect);

    //! Band ID to index
    //! @param[in] bandID
    //!     Band ID
    //! @return
    //!     Index
    INT BandIdToIndex(INT bandID);

    //! Perform hit test
    //! @param[in] info
    //!     Hit test data
    //! @return
    //!     Hit test flags
    INT HitTest(RBHITTESTINFO& info);

    //! Shows band
    //! @param[in] bandID
    //!     Band ID
    //! @param[in] show
    //!     Show or hide
    //! @return
    //!     True when successful
    BOOL ShowBand(INT bandID, BOOL show);

    //! Moves band
    //! @param[in] bandID
    //!     Band ID
    //! @param[in] newPos
    //!     New position
    //! @return
    //!     True when successful
    BOOL MoveBand(INT bandID, INT newPos);

    //! Handle to index
    //! @param[in] handle
    //!     Handle to band window
    //! @return
    //!     Index
    INT HandleToIndex(HWND handle);

    //! Auto size rebar
    void RecalcLayout();

    //! Gets band margins
    //! @param[out] margins
    //!     Margins
    void GetBandMargins(MARGINS& margins) const;

    //! Gets drop target
    //! @param[out] target
    //!     Drop target
    void GetDropTarget(IDropTarget** target) const;

    //! Sets band width
    //! @param[in] bandID
    //!     Band ID
    //! @param[in] width
    //!     Width
    //! @return
    //!     True when successful
    BOOL SetBandWidth(INT bandID, INT width);

    //! Sets window theme
    //! @param[in] theme
    //!     Theme name
    void SetWindowTheme(const wchar_t* theme);
};
}
//----------------------------------------------------------------------------//
#include "uixrebarctrl.inl"
//----------------------------------------------------------------------------//
#endif /* _UIX_REBARCTRL_H__ */