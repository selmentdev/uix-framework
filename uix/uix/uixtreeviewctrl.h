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
#ifndef _UIX_TREEVIEWCTRL_H__
#define _UIX_TREEVIEWCTRL_H__
//----------------------------------------------------------------------------//
#include "uixwindow.h"
//----------------------------------------------------------------------------//
namespace UIX
{
//! Handle
#define uixEVT_TVN_ASYNCDRAW(Identifier, Handler) \
    uixEVT_NOTIFY(TVN_ASYNCDRAW, Identifier, Handler)

//! Handle
#define uixEVT_TVN_BEGINDRAG(Identifier, Handler) \
    uixEVT_NOTIFY(TVN_BEGINDRAG, Identifier, Handler)

//! Handle
#define uixEVT_TVN_BEGINLABELEDIT(Identifier, Handler) \
    uixEVT_NOTIFY(TVN_BEGINLABELEDIT, Identifier, Handler)

//! Handle
#define uixEVT_TVN_BEGINRDRAG(Identifier, Handler) \
    uixEVT_NOTIFY(TVN_BEGINRDRAG, Identifier, Handler)

//! Handle
#define uixEVT_TVN_DELETEITEM(Identifier, Handler) \
    uixEVT_NOTIFY(TVN_DELETEITEM, Identifier, Handler)

//! Handle
#define uixEVT_TVN_ENDLABELEDIT(Identifier, Handler) \
    uixEVT_NOTIFY(TVN_ENDLABELEDIT, Identifier, Handler)

//! Handle
#define uixEVT_TVN_GETDISPINFO(Identifier, Handler) \
    uixEVT_NOTIFY(TVN_GETDISPINFO, Identifier, Handler)

//! Handle
#define uixEVT_TVN_GETINFOTIP(Identifier, Handler) \
    uixEVT_NOTIFY(TVN_GETINFOTIP, Identifier, Handler)

//! Handle
#define uixEVT_TVN_ITEMCHANGED(Identifier, Handler) \
    uixEVT_NOTIFY(TVN_ITEMCHANGED, Identifier, Handler)

//! Handle
#define uixEVT_TVN_ITEMCHANGING(Identifier, Handler) \
    uixEVT_NOTIFY(TVN_ITEMCHANGING, Identifier, Handler)

//! Handle
#define uixEVT_TVN_ITEMEXPANDED(Identifier, Handler) \
    uixEVT_NOTIFY(TVN_ITEMEXPANDED, Identifier, Handler)

//! Handle
#define uixEVT_TVN_ITEMEXPANDING(Identifier, Handler) \
    uixEVT_NOTIFY(TVN_ITEMEXPANDING, Identifier, Handler)

//! Handle
#define uixEVT_TVN_KEYDOWN(Identifier, Handler) \
    uixEVT_NOTIFY(TVN_KEYDOWN, Identifier, Handler)

//! Handle
#define uixEVT_TVN_SELCHANGED(Identifier, Handler) \
    uixEVT_NOTIFY(TVN_SELCHANGED, Identifier, Handler)

//! Handle
#define uixEVT_TVN_SELCHANGING(Identifier, Handler) \
    uixEVT_NOTIFY(TVN_SELCHANGING, Identifier, Handler)

//! Handle
#define uixEVT_TVN_SETDISPINFO(Identifier, Handler) \
    uixEVT_NOTIFY(TVN_SETDISPINFO, Identifier, Handler)

//! Handle
#define uixEVT_TVN_SINGLEEXPAND(Identifier, Handler) \
    uixEVT_NOTIFY(TVN_SINGLEEXPAND, Identifier, Handler)

//! Tree View Item
struct uixTreeViewItem : TVITEMEX
{
    //! Constructor
    uixTreeViewItem();

    //! Gets mask
    //! @return
    //!     Mask
    DWORD GetMask() const;

    //! Sets mask
    //! @param[in] value
    //!     Mask
    void SetMask(DWORD value);

    //! Gets item handle
    //! @return
    //!     Item handle
    HTREEITEM GetItem() const;

    //! Sets item handle
    //! @param[in] handle
    //!     Item handle
    void SetItem(HTREEITEM handle);

    //! Gets state
    //! @return
    //!     State
    DWORD GetState() const;

    //! Sets state
    //! @param[in] value
    void SetState(DWORD value);

    //! Gets state mask
    //! @return
    //!     State mask
    DWORD GetStateMask() const;

    //! Sets state mask
    //! @param[in] value
    //!     State mask
    void SetStateMask(DWORD value);

    //! Gets text
    //! @return
    //!     Item text
    const uixChar* GetText() const;

    //! Gets text length
    //! @return
    //!     Text length
    INT GetTextLength() const;

    //! Sets text
    //! @param[in] text
    //!     Text
    void SetText(const uixChar* text);

    //! Sets text
    //! @param[in] text
    //!     Text
    //! @param[in] length
    //!     Text length
    void SetText(const uixChar* text, INT length);

    //! Sets text length
    //! @param[in] length
    //!     Text length
    void SetTextLength(INT length);

    //! Gets image index
    //! @return
    //!     Image index
    INT GetImage() const;

    //! Sets image index
    //! @param[in] value
    //!     Image index
    void SetImage(INT value);

    //! Gets selected image index
    //! @return
    //!     Image index
    INT GetSelectedImage() const;

    //! Sets selected image index
    //! @param[in] value
    //!     Image index
    void SetSelectedImage(INT value);

    //! Gets children count
    //! @return
    //!     Children count
    INT GetChildren() const;

    //! Sets children count
    //! @param[in] value
    //!     Children count
    void SetChildren(INT value);

    //! Gets data
    //! @return
    //!     Data pointer
    const void* GetData() const;

    //! Sets data
    //! @param[in] data
    //!     Data pointer
    void SetData(const void* data);

    //! Gets intergral height
    //! @return
    //!     Integral value
    INT GetIntegral() const;

    //! Sets integral height
    //! @param[in] value
    //!     Integral height
    void SetIntegral(INT value);

    //! Gets extended state
    //! @return
    //!     Flags
    DWORD GetStateEx() const;

    //! Sets extended state
    //! @param[in] value
    //!     Extended state flags
    void SetStateEx(DWORD value);

    //! Gets expaned image index
    //! @return
    //!     Image index
    INT GetExpanededImage() const;

    //! Sets expanded image
    //! @param[in] value
    //!     Expanded image index
    void SetExpandedImage(INT value);
};

//! Tree View hit test
//! @todo Implement
struct uixTreeViewHitTest : TVHITTESTINFO
{
};

//! Tree View insert

struct uixTreeViewInsert : TVINSERTSTRUCT
{
    //! Sets parent item handle
    //! @param[in] handle
    //!     Parent item handle
    void SetParent(HTREEITEM handle);

    //! Gets parent item handle
    //! @return
    //!     Parent item handle
    HTREEITEM GetParent() const;

    //! Sets item as relative to first item
    void SetRelativeAsFirst();

    //! Sets item as relative to last item
    void SetRelativeAsLast();

    //! Sets item as root item
    void SetRelativeAsRoot();

    //! Sets item as sorted
    void SetRelativeAsSorted();

    //! Gets relative item handle
    HTREEITEM GetRelative() const;

    //! Sets item
    //! @param[in] item
    //!     Item data
    void SetItem(const TVITEMEX& item);

    //! Gets item
    //! @param[out] item
    //!     Item data
    void GetItem(TVITEMEX& item) const;
};

//! Tree View sort callback
//! @todo Implement
struct uixTreeViewSortCallback : TVSORTCB
{
};

//! Tree view style
enum uixTreeViewStyle
{
    //! Check boxes
    uixTreeViewStyle_CheckBoxes = TVS_CHECKBOXES,
    //! Disable drag and drop
    uixTreeViewStyle_DisableDragDrop = TVS_DISABLEDRAGDROP,
    //! Edit labels
    uixTreeViewStyle_EditLabels = TVS_EDITLABELS,
    //! Full row select
    uixTreeViewStyle_FullRowSelect = TVS_FULLROWSELECT,
    //! Has buttons
    uixTreeViewStyle_HasButtons = TVS_HASBUTTONS,
    //! Has lines
    uixTreeViewStyle_HasLines = TVS_HASLINES,
    //! Has info tip
    uixTreeViewStyle_InfoTip = TVS_INFOTIP,
    //! Lines at root
    uixTreeViewStyle_LinesAtRoot = TVS_LINESATROOT,
    //! No horizontal scroll
    uixTreeViewStyle_NoHScroll = TVS_NOHSCROLL,
    //! Non even height
    uixTreeViewStyle_NonEvenHeight = TVS_NONEVENHEIGHT,
    //! No scroll
    uixTreeViewStyle_NoScroll = TVS_NOSCROLL,
    //! No tool tips
    uixTreeViewStyle_NoTooltips = TVS_NOTOOLTIPS,
    //! Rtl reading
    uixTreeViewStyle_RtlReading = TVS_RTLREADING,
    //! Always show selection
    uixTreeViewStyle_ShowSelectionAlways = TVS_SHOWSELALWAYS,
    //! Single expand mode
    uixTreeViewStyle_SingleExpand = TVS_SINGLEEXPAND,
    //! Track selected item
    uixTreeViewStyle_TrackSelect = TVS_TRACKSELECT,
};

//! Tree view extended style
enum uixTreeViewExStyle
{
    //! Multiselect
    uixTreeViewExStyle_Multiselect = TVS_EX_MULTISELECT,
    //! Double buffer
    uixTreeViewExStyle_DoubleBuffer = TVS_EX_DOUBLEBUFFER,
    //! No indent state
    uixTreeViewExStyle_NoIndentState = TVS_EX_NOINDENTSTATE,
    //! Rich tool tips
    uixTreeViewExStyle_RichToolTip = TVS_EX_RICHTOOLTIP,
    //! Auto horizontal scroll
    uixTreeViewExStyle_AutoHScroll = TVS_EX_AUTOHSCROLL,
    //! Fade in/out expands
    uixTreeViewExStyle_FadeInOutExpands = TVS_EX_FADEINOUTEXPANDOS,
    //! Partial checkboxes
    uixTreeViewExStyle_PartialCheckBoxes = TVS_EX_PARTIALCHECKBOXES,
    //! Exclusion checkboxes
    uixTreeViewExStyle_ExclusionCheckBoxes = TVS_EX_EXCLUSIONCHECKBOXES,
    //! Draw image async
    uixTreeViewExStyle_DrawImageAsync = TVS_EX_DRAWIMAGEASYNC,
    //! Dimmed checkboxes
    uixTreeViewExStyle_DimmedCheckBoxes = TVS_EX_DIMMEDCHECKBOXES,
};

//! Tree View control
//! @brief
//!     This class implements tree view control, which allows to represents
//!     various sets of data in tree structure
class UIXAPI uixTreeViewCtrl : public uixWindow
{
    uixDECLARE_DYNAMIC_CLASS(uixTreeViewCtrl);
public:
    //! Constructor
    uixTreeViewCtrl();

    //! Destructor
    virtual ~uixTreeViewCtrl();

    //! @copydoc uixWindow::BeforeWindowCreate
    virtual BOOL BeforeWindowCreate(CREATESTRUCT& cs) override;

    //! Creates drag image
    //! @param[in] item
    //!     Item handle
    //! @return
    //!     Image list with drag image
    HIMAGELIST CreateDragImage(HTREEITEM item) const;

    //! Deletes all items
    //! @return
    //!     True when successful
    BOOL DeleteAllItems();

    //! Deletes item
    //! @param[in] item
    //!     Item handle to delete
    //! @return
    //!     True when successful
    BOOL DeleteItem(HTREEITEM item);

    //! Edit item label
    //! @param[in] item
    //!     Item handle
    //! @return
    //!     Handle to text box
    HWND EditLabel(HTREEITEM item);

    //! Ends edit label now
    //! @param[in] cancel
    //!     True to discard user input
    //! @return
    //!     True when successful
    BOOL EndEditLabelNow(BOOL cancel);

    //! Ensures that item will be visible
    //! @param[in] item
    //!     Item handle
    //! @return
    //!     True when succecssful
    BOOL EnsureVisible(HTREEITEM item);

    //! Expands item
    //! @param[in] item
    //!     Item handle
    //! @param[in] flag
    //!     TVE_COLLAPSE
    //!     TVE_COLLAPSERESET
    //!     TVE_EXPAND
    //!     TVE_EXPANDPARTIAL
    //!     TVE_TOGGLE
    //! @return
    //!     True when successful
    BOOL Expand(HTREEITEM item, UINT flag);

    //! Gets background color
    //! @return
    //!     Background color
    uixColor GetBackgroundColor() const;

    //! Gets check state
    //! @param[in] item
    //!     Item handle
    //! @return
    //!     State flags
    UINT GetCheckState(HTREEITEM item) const;

    //! Gets item child
    //! @param[in] item
    //!     Item handle
    //! @return
    //!     Handle to first child item
    HTREEITEM GetChild(HTREEITEM item) const;

    //! Gets items count
    //! @return
    //!     Number of items in control
    UINT GetCount() const;

    //! Gets drop highlight
    //! @return
    //!     Handle to highlighted item in drop mode
    HTREEITEM GetDropHighlight() const;

    //! Gets handle to edit control
    //! @return
    //!     Handle to edit control
    HWND GetEditControl() const;

    //! Gets control style
    //! @return
    //!     Control style
    DWORD GetControlExStyle() const;

    //! Gets first visible item
    //! @return
    //!     First visible item handle
    HTREEITEM GetFirstVisible() const;

    //! Gets image list
    //! @param[in] type
    //!     TVSIL_NORMAL
    //!     TVSIL_STATE
    //! @return
    //!     Image list
    HIMAGELIST GetImageList(INT type) const;

    //! Gets indent value
    //! @return
    //!     Indent
    UINT GetIndent() const;

    //! Gets insert mark color
    //! @return
    //!     Insert mark color
    uixColor GetInsertMarkColor() const;

    //! Incremental search for text
    //! @param[in] text
    //!     Text to search
    //! @return
    //!     True when successful
    BOOL GetISearchString(uixChar* text) const;

    //! Gets item
    //! @param[out] item
    //!     Item data
    //! @return
    //!     True when successful
    BOOL GetItem(TVITEMEX& item) const;

    //! Gets item height
    //! @return
    //!     Item height
    INT GetItemHeight() const;

    //! Gets item part rect
    //! @param[in] item
    //!     Item handle
    //! @param[out] rect
    //!     Item part rect
    //! @return
    //!     True when successful
    BOOL GetItemPartRect(HTREEITEM item, RECT& rect) const;

    //! Gets item rect
    //! @param[in] item
    //!     Item handle
    //! @param[out] rect
    //!     Item rect
    //! @param[in] itemRect
    //!     True to get item rect
    //! @return
    //!     True when successful
    BOOL GetItemRect(HTREEITEM item, RECT& rect, BOOL itemRect) const;

    //! Gets item state
    //! @param[in] item
    //!     Item handle
    //! @param[in] stateMask
    //!     State mask
    //! @return
    //!     Masked state
    UINT GetItemState(HTREEITEM item, UINT stateMask) const;

    //! Gets last visible item
    //! @return
    //!     Handle of last visible item
    HTREEITEM GetLastVisible() const;

    //! Gets line color
    //! @return
    //!     Line color
    uixColor GetLineColor() const;

    //! Gets next item
    //! @param[in] item
    //!     Item handle
    //! @param[in] flag
    //!     TVGN_CARET
    //!     TVGN_CHILD
    //!     TVGN_DROPHILITE
    //!     TVGN_FIRSTVISIBLE
    //!     TVGN_NEXT
    //!     TVGN_NEXTSELECTED
    //!     TVGN_NEXTVISIBLE
    //!     TVGN_PARENT
    //!     TVGN_PREVIOUS,
    //!     TVGN_PREVIUOSVISIBLE,
    //!     TVGN_ROOT
    //! @return
    //!     Item handle
    HTREEITEM GetNext_Item(HTREEITEM item, UINT flag) const;

    //! Gets next selected
    //! @param[in] item
    //!     Item handle
    //! @return
    //!     Item handle
    HTREEITEM GetNext_Selected(HTREEITEM item) const;

    //! Gets next sibling
    //! @param[in] item
    //!     Item handle
    //! @return
    //!     Item handle
    HTREEITEM GetNext_Sibling(HTREEITEM item) const;

    //! Gets next visible
    //! @param[in] item
    //!     Item handle
    //! @return
    //!     Item handle
    HTREEITEM GetNext_Visible(HTREEITEM item) const;

    //! Gets parent
    //! @param[in] item
    //!     Item handle
    //! @return
    //!     Item handle
    HTREEITEM GetParent(HTREEITEM item) const;

    //! Gets previous sibling
    //! @param[in] item
    //!     Item handle
    //! @return
    //!     Item handle
    HTREEITEM GetPrev_Sibling(HTREEITEM item) const;

    //! Gets previous visible
    //! @param[in] item
    //!     Item handle
    //! @return
    //!     Item handle
    HTREEITEM GetPrev_Visible(HTREEITEM item) const;

    //! Gets root item
    //! @return
    //!     Root item handle
    HTREEITEM GetRoot() const;

    //! Gets scroll time
    //! @return
    //!     Scroll time
    UINT GetScrollTime() const;

    //! Gets selection
    //! @return
    //!     Selected item handle
    HTREEITEM GetSelection() const;

    //! Gets text color
    //! @return
    //!     Text color
    uixColor GetTextColor() const;

    //! Gets tool tips window
    //! @return
    //!     Tool tip window handle
    HWND GetToolTips() const;

    //! Gets unicode format
    //! @return
    //!     True when control supports unicode
    BOOL GetUnicodeFormat() const;

    //! Gets visible item count
    //! @return
    //!     Number of visible items
    UINT GetVisibleCount() const;

    //! Perform hit test
    //! @param[out] info
    //!     Test params
    //! @return
    //!     Item handle
    HTREEITEM HitTest(TVHITTESTINFO& info) const;

    //! Inserts item
    //! @param[in] item
    //!     Item data
    //! @return
    //!     Inserted item handle
    HTREEITEM InsertItem(TVINSERTSTRUCT& item);

    //! Maps accid to item handle
    //! @param[in] id
    //!     Accessibility ID
    //! @return
    //!     Item handle
    HTREEITEM MapAccIDToHTREEITEM(UINT id) const;

    //! Maps item handle to accid
    //! @param[in] item
    //!     Item handle
    //! @return
    //!     Accessibility ID
    UINT MapHTREEITEMtoAccID(HTREEITEM item) const;

    //! Selects item
    //! @param[in] item
    //!     Item handle to select
    //! @param[in] flag
    //!     TVGN_CARET
    //!     TVGN_DROPHILITE
    //!     TVGN_FIRSTVISIBLE
    //! @return
    //!     True when successful
    BOOL Select(HTREEITEM item, UINT flag);

    //! Selects drop target
    //! @param[in] item
    //!     Item handle
    //! @return
    //!     True when successful
    BOOL SelectDropTarget(HTREEITEM item);

    //! Selects item
    //! @param[in] item
    //!     Item handle
    //! @return
    //!     True when successful
    BOOL SelectItem(HTREEITEM item);

    //! Sets auto scroll info
    //! @param[in] pixPerSecond
    //!     Number of pixels per second
    //! @param[in] updateTime
    //!     Update time
    //! @return
    //!     Result value
    LRESULT SetAutoScrollInfo(UINT pixPerSecond, UINT updateTime);

    //! Sets background color
    //! @param[in] color
    //!     New background color
    //! @return
    //!     Previuos background color
    uixColor SetBackgroundColor(uixColor color);

    //! Sets check state
    //! @param[in] item
    //!     Item handle
    //! @param[in] check
    //!     Check state
    //! @return
    //!     Flags
    UINT SetCheckState(HTREEITEM item, BOOL check);

    //! Sets control
    //! @param[in] style
    //!     Member of uixTreeViewExStyle
    //! @return
    //!     Result value
    HRESULT SetControlExStyle(DWORD style, UINT mask);

    //! Sets image list
    //! @param[in] imageList
    //!     Image list
    //! @param[in] type
    //!     TVSIL_NORMAL
    //!     TVSIL_STATE
    //! @return
    //!     Previuos image list
    HIMAGELIST SetImageList(HIMAGELIST imageList, INT type);

    //! Sets indent
    //! @param[in] indent
    //!     Indent
    //! @return
    //!     True when successful
    BOOL SetIndent(INT indent);

    //! Sets insert mark
    //! @param[in] item
    //!     Item handle
    //! @param[in] after
    //!     True to insert after
    //! @return
    //!     True when successful
    BOOL SetInsertMark(HTREEITEM item, BOOL after);

    //! Sets insert mark color
    //! @param[in] color
    //!     New color
    //! @return
    //!     Previous color
    uixColor SetInsertMarkColor(uixColor color);

    //! Sets item
    //! @param[in] item
    //!     Item data
    //! @return
    //!     True when successful
    BOOL SetItem(const TVITEMEX& item);

    //! Sets item height
    //! @param[in] itemHeight
    //!     Item height
    //! @return
    //!     Previuos item height
    INT SetItemHeight(SHORT itemHeight);

    //! Sets item state
    //! @param[in] item
    //!     Item handle
    //! @param[in] state
    //!     Item state
    //! @param[in] stateMask
    //!     State mask
    //! @return
    //!     Previuos item state
    UINT SetItemState(HTREEITEM item, UINT state, UINT stateMask);

    //! Sets line color
    //! @param[in] color
    //!     New line color
    //! @return
    //!     Previous line color
    uixColor SetLineColor(uixColor color);

    //! Sets scroll time
    //! @param[in] maxScrollTime
    //!     Max scroll time
    //! @return
    //!     Previous max scroll time
    UINT SetScrollTime(UINT maxScrollTime);

    //! Sets text color
    //! @param[in] color
    //!     New text color
    //! @return
    //!     Previous text color
    uixColor SetTextColor(uixColor color);

    //! Sets tool tip window
    //! @param[in] toolTip
    //!     New tool tip window handle
    //! @return
    //!     Previous tool tip window handle
    HWND SetToolTips(HWND toolTip);

    //! Sets unicode format
    //! @param[in] unicode
    //!     True to enable unicode support
    //! @return
    //!     Previous unicode format flag
    BOOL SetUnicodeFormat(BOOL unicode);

    //! Shows info tip
    //! @param[in] item
    //!     Item handle
    //! @return
    //!     Result flags
    DWORD ShowInfoTip(HTREEITEM item);

    //! Sorts children
    //! @param[in] item
    //!     Item handle
    //! @param[in] recursive
    //!     True to perform recursive children sort
    //! @return
    //!     True when successful
    BOOL SortChildren(HTREEITEM item, BOOL recurse);

    //! Sets children callback
    //! @param[in] sort
    //!     Sort callback data
    //! @param[in] recurse
    //!     Callback is recursive
    //! @return
    //!     True when successful
    BOOL SortChildrenCallback(TVSORTCB& sort, BOOL recurse);
};
}
//----------------------------------------------------------------------------//
#include "uixtreeviewctrl.inl"
//----------------------------------------------------------------------------//
#endif /* _UIX_TREEVIEWCTRL_H__ */