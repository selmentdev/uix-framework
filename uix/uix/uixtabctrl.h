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
#ifndef _UIX_TABCTRL_H__
#define _UIX_TABCTRL_H__
//----------------------------------------------------------------------------//
#include "uixwindow.h"
#include "uixdialog.h"
//----------------------------------------------------------------------------//
namespace UIX
{

//! Handle
#define uixEVT_TCN_FOCUSCHANGE(Identifier, Handler) \
    uixEVT_NOTIFY(TCN_FOCUSCHANGE, Identifier, Handler)

//! Handle
#define uixEVT_TCN_GETOBJECT(Identifier, Handler) \
    uixEVT_NOTIFY(TCN_GETOBJECT, Identifier, Handler)

//! Handle
#define uixEVT_TCN_KEYDOWN(Identifier, Handler) \
    uixEVT_NOTIFY(TCN_KEYDOWN, Identifier, Handler)

//! Handle
#define uixEVT_TCN_SELCHANGE(Identifier, Handler) \
    uixEVT_NOTIFY(TCN_SELCHANGE, Identifier, Handler)

//! Handle
#define uixEVT_TCN_SELCHANGING(Identifier, Handler) \
    uixEVT_NOTIFY(TCN_SELCHANGING, Identifier, Handler)

//! Tab Control Item
//! @brief
//!     This struct represents single Tab Control item.
//! @remarks
//!     Don't use fields of inherited TCITEM struct directly, instead please
//!     use methods written in this wrapper struct.
struct uixTabCtrlItem : TCITEM
{
    //! Constructor
    uixTabCtrlItem();

    //! Checks if item has state
    //! @return
    //!     True when successful
    BOOL HasState() const;

    //! Checks if item has image
    //! @return
    //!     True when successful
    BOOL HasImage() const;

    //! Checks if item has data
    //! @return
    //!     True when successful
    BOOL HasData() const;

    //! Checks if item has text
    //! @return
    //!     True when successful
    BOOL HasText() const;

    //! Gets item state
    //! @return
    //!     State flags
    DWORD GetState() const;

    //! Sets item state
    //! @param[in] state
    //!     State flags
    void SetState(DWORD state);

    //! Gets state mask
    //! @return
    //!     State mask
    DWORD GetStateMask() const;

    //! Sets state mask
    //! @param[in] mask
    //!     State mask
    void SetStateMask(DWORD mask);

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

    //! Gets text
    //! @return
    //!     Text
    uixChar* GetText() const;

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
    INT GetImageIndex() const;

    //! Sets image index
    //! @param[in] index
    //!     Image index
    void SetImageIndex(INT index);

    //! Gets item data
    //! @return
    //!     Item data
    void* GetData() const;

    //! Sets item data
    //! @param[in] data
    //!     Item data
    void SetData(const void* data);
};

//! Tab Control Hit Test
struct uixTabCtrlHitTest : TC_HITTESTINFO
{
};

enum uixTabCtrlStyle
{
    uixTabCtrlStyle_Bottom = TCS_BOTTOM,
    uixTabCtrlStyle_Buttons = TCS_BUTTONS,
    uixTabCtrlStyle_FixedWidth = TCS_FIXEDWIDTH,
    uixTabCtrlStyle_FlatButtons = TCS_FLATBUTTONS,
    uixTabCtrlStyle_FocusNever = TCS_FOCUSNEVER,
    uixTabCtrlStyle_FocusOnButtonDown = TCS_FOCUSONBUTTONDOWN,
    uixTabCtrlStyle_ForceIconLeft = TCS_FORCEICONLEFT,
    uixTabCtrlStyle_ForceLabelLeft = TCS_FORCELABELLEFT,
    uixTabCtrlStyle_HotTrack = TCS_HOTTRACK,
    uixTabCtrlStyle_Multiline = TCS_MULTILINE,
    uixTabCtrlStyle_Multiselect = TCS_MULTISELECT,
    uixTabCtrlStyle_OwnerDrawFixed = TCS_OWNERDRAWFIXED,
    uixTabCtrlStyle_RaggedRight = TCS_RAGGEDRIGHT,
    uixTabCtrlStyle_Right = TCS_RIGHT,
    uixTabCtrlStyle_RightJustify = TCS_RIGHTJUSTIFY,
    uixTabCtrlStyle_ScrollOpposite = TCS_SCROLLOPPOSITE,
    uixTabCtrlStyle_SingleLine = TCS_SINGLELINE,
    uixTabCtrlStyle_Tabs = TCS_TABS,
    uixTabCtrlStyle_ToolTips = TCS_TOOLTIPS,
    uixTabCtrlStyle_Vertical = TCS_VERTICAL,
};

enum uixTabCtrlStyleEx
{
    uixTabCtrlStyleEx_FlatSeparators = TCS_EX_FLATSEPARATORS,
    uixTabCtrlStyleEx_RegisterDrop = TCS_EX_REGISTERDROP,
};

//! Tab Control
//! @brief
//!     This class implements tab control
class UIXAPI uixTabCtrl : public uixWindow
{
    uixDECLARE_DYNAMIC_CLASS(uixTabCtrl);
    uixDECLARE_EVENT_MAP();
public:
    //! Constructor
    uixTabCtrl();

    //! Destructor
    virtual ~uixTabCtrl();

    //! @copydoc uixWindow::BeforeWindowCreate
    virtual BOOL BeforeWindowCreate(CREATESTRUCT& cs) override;

    //! Gets item count
    //! @return
    //!     Item count
    INT GetItemCount() const;

    //! Gets item
    //! @param[in] itemID
    //!     Item ID
    //! @param[out] item
    //!     Item data
    //! @return
    //!     True when successful
    BOOL GetItem(INT itemID, TCITEM& item) const;

    //! Sets item
    //! @param[in] itemID
    //!     Item ID
    //! @param[in] item
    //!     Item data
    //! @return
    //!     True when successful
    BOOL SetItem(INT itemID, const TCITEM& item);

    //! Gets item rect
    //! @param[in] itemID
    //!     Item ID
    //! @param[out] rect
    //!     Item rect
    //! @return
    //!     True when successful
    BOOL GetItemRect(INT itemID, RECT& rect) const;

    //! Gets current selection
    //! @return
    //!     Currently selected index
    INT GetCurrentSelection() const;

    //! Sets current selection
    //! @param[in] itemID
    //!     Selected ID
    //! @return
    //!     Previous selected ID
    INT SetCurrentSelection(INT itemID);

    //! Sets item size
    //! @param[in] width
    //!     Width
    //! @param[in] height
    //!     Height
    void SetItemSize(INT width, INT height);

    //! Sets item size
    //! @param[in] size
    //!     Item size
    void SetItemSize(SIZE size);

    //! Sets padding
    //! @param[in] width
    //!     Width
    //! @param[in] height
    //!     Height
    void SetPadding(INT width, INT height);

    //! Sets padding
    //! @param[in] size
    //!     Size
    void SetPadding(SIZE size);

    //! Gets row count
    //! @return
    //!     Row count
    INT GetRowCount() const;

    //! Gets tooltip control handle
    //! @return
    //!     Tooltip control handle
    HWND GetToolTipCtrl() const;

    //! Sets tooltip control handle
    //! @param[in] handle
    //!     Tool tip control handle
    void SetToolTipCtrl(HWND handle);

    //! Gets currently focused item ID
    //! @return
    //!     Item ID
    INT GetCurrentFocus() const;

    //! Sets currently focused item
    //! @param[in] itemID
    //!     Item ID
    void SetCurrentFocus(INT itemID);

    //! Sets item extra
    //! @param[in] count
    //!     Count
    //! @return
    //!     True when successful
    BOOL SetItemExtra(INT count);

    //! Sets min tab width
    //! @param[in] width
    //!     Width
    //! @return
    //!     Previous min tab width
    INT SetMinTabWidth(INT width);

    //! Gets control style
    //! @return
    //!     Control style
    DWORD GetControlStyle() const;

    //! Sets control style
    //! @param[in] style
    //!     New style
    //! @return
    //!     Previous style
    DWORD SetControlStyle(DWORD style);

    //! Gets unicode format support
    //! @return
    //!     True when successful
    BOOL GetUnicodeFormat() const;

    //! Sets unicode support
    //! @param[in] unicode
    //!     Flag
    //! @return
    //!     Previous value
    BOOL SetUnicodeFormat(BOOL unicode);

    //! Inserts item
    //! @param[in] itemID
    //!     Item ID
    //! @param[in] item
    //!     Item to insert
    //! @return
    //!     True when successful
    BOOL InsertItem(INT itemID, TCITEM& item);

    //! Delete item
    //! @param[in] itemID
    //!     ID of item to delete
    //! @return
    //!     True when successful
    BOOL DeleteItem(INT itemID);

    //! Deletes all items
    //! @return
    //!     True when successful
    BOOL DeleteAllItems();

    //! Adjusts rect
    //! @param[in] larger
    //!     Larger flag
    //! @param[out] rect
    //!     Adjusted rect
    void AdjustRect(BOOL larger, RECT& rect);

    //! Removes image
    //! @param[in] itemID
    //!     Item ID
    void RemoveImage(INT itemID);

    //! Perform hit test
    //! @param[in] hti
    //!     Hit test info
    //! @return
    //!     Result flags
    INT HitTest(TC_HITTESTINFO& hti);

    //! Deselects all items
    //! @param[in] excludeFocus
    //!     Exclude focus
    void DeselectAll(BOOL excludeFocus = TRUE);

    //! Gets image list
    //! @return
    //!     Handle to image list
    HIMAGELIST GetImageList() const;

    //! Sets image list
    //! @param[in] handle
    //!     Handle to image list
    //! @return
    //!     Previous image list handle
    HIMAGELIST SetImageList(HIMAGELIST handle);

    //! Highlights item
    //! @param[in] itemID
    //!     Item ID
    //! @param[in] highlight
    //!     Highlight flag
    //! @return
    //!     True when successful
    BOOL HighlightItem(INT itemID, BOOL highlight);

public: // new interface

    //! Pages list
    typedef std::vector<uixWindow*> PagesList;

    //! Adds page
    //! @param[in] control
    //!     Control page
    //! @param[in] text
    //!     Caption
    //! @return
    //!     True when successful
    BOOL AddPage(uixWindow* control, const uixString& text);

    //! Remove page by index
    //! @param[in] index
    //!     Index of page to remove
    //! @return
    //!     True when successful
    BOOL RemovePage(INT index);

    //! Gets page control
    //! @param[in] index
    //!     Page index
    //! @return
    //!     Page control
    uixWindow* GetPageControl(INT index);

    //! Gets page caption
    //! @param[in] index
    //!     Page index
    //! @return
    //!     Page caption
    uixString GetPageCaption(INT index);

    //! Gets page count
    //! @return
    //!     Page count
    INT GetPageCount() const;

    //! Gets index of selected page
    //! @return
    //!     Selected page index
    INT GetSelectedPage() const;

    //! Gets focused page index
    //! @return
    //!     Focused page index
    INT GetFocusedPage() const;

    //! Selects page
    //! @param[in] index
    //!     Index of page to select
    //! @return
    //!     True when successful
    BOOL SelectPage(INT index);

    //! Called when selection changed
    void OnSelectionChange(uixNotifyEventArgs& e);

    //! Called when size changed
    void OnSize(uixSizeEventArgs& e);

private:
    PagesList   m_Pages;

    //! Hides page
    //! @param[in] index
    //!     Page index to hide
    //! @return
    //!     True when successful
    BOOL HidePage(INT index);
};

//! Tab page control
//! @brief
//!     Base class for all tab control pages
class UIXAPI uixTabPage : public uixDialog
{
public:
    uixDECLARE_EVENT_MAP()
public:
    //! @copydoc uixDialog::BeforeWindowCreate
    virtual BOOL BeforeWindowCreate(CREATESTRUCT& cs) override;

    //! Called when background erase
    void OnEraseBackground(uixEraseBackgroundEventArgs& e);

    //! Called when enters size move
    void OnEnterSizeMove(uixEventArgs& e);

    //! Called when exits size move
    void OnExitSizeMove(uixEventArgs& e);

    //! Called when control is redrawn
    void OnControlColor(uixControlColorEventArgs& e);
};
}
//----------------------------------------------------------------------------//
#include "uixtabctrl.inl"
//----------------------------------------------------------------------------//
#endif /* _UIX_TABCTRL_H__ */