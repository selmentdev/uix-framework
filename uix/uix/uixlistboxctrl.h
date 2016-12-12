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
#ifndef _UIX_LISTBOXCTRL_H__
#define _UIX_LISTBOXCTRL_H__
//----------------------------------------------------------------------------//
#include "uixwindow.h"
//----------------------------------------------------------------------------//
namespace UIX
{
//! Handle list box double click
#define uixEVT_LBN_DBLCLICK(Identifier, Handler) \
    uixEVT_CONTROL(LBN_DBLCLK, Identifier, Handler)

//! Handle list box error space
#define uixEVT_LBN_ERRSPACE(Identifier, Handler) \
    uixEVT_CONTROL(LBN_ERRSPACE, Identifier, Handler)

//! Handle list box kill focus
#define uixEVT_LBN_KILLFOCUS(Identifier, Handler) \
    uixEVT_CONTROL(LBN_KILLFOCUS, Identifier, Handler)

//! Handle list box selection change
#define uixEVT_LBN_SELCHANGE(Identifier, Handler) \
    uixEVT_CONTROL(LBN_SELCHANGE, Identifier, Handler)

//! Handle list box selection cancel
#define uixEVT_LBN_SELCANCEL(Identifier, Handler) \
    uixEVT_CONTROL(LBN_SELCANCEL, Identifier, Handler)

//! Handle list box set focus
#define uixEVT_LBN_SETFOCUS(Identifier, Handler) \
    uixEVT_CONTROL(LBN_SETFOCUS, Identifier, Handler)



//! List box control styles
enum uixListBoxStyle
{
    //! Combo Box
    uixListBoxStyle_ComboBox = LBS_COMBOBOX,
    //! Disable no scroll
    uixListBoxStyle_DisableNoScroll = LBS_DISABLENOSCROLL,
    //! Extended selection
    uixListBoxStyle_ExtendedSelection = LBS_EXTENDEDSEL,
    //! Has strings
    uixListBoxStyle_HasStrings = LBS_HASSTRINGS,
    //! Multi column
    uixListBoxStyle_MultiColumn = LBS_MULTICOLUMN,
    //! Multiple selection
    uixListBoxStyle_MultipleSelection = LBS_MULTIPLESEL,
    //! No data
    uixListBoxStyle_NoData = LBS_NODATA,
    //! No integral height
    uixListBoxStyle_NoIntegralHeight = LBS_NOINTEGRALHEIGHT,
    //! No redraw
    uixListBoxStyle_NoRedraw = LBS_NOREDRAW,
    //! No selection
    uixListBoxStyle_NoSelection = LBS_NOSEL,
    //! Notify
    uixListBoxStyle_Notify = LBS_NOTIFY,
    //! Owner draw - fixed
    uixListBoxStyle_OwnerDrawFixed = LBS_OWNERDRAWFIXED,
    //! Owner draw - variable
    uixListBoxStyle_OwnerDrawVariable = LBS_OWNERDRAWVARIABLE,
    //! Sort
    uixListBoxStyle_Sort = LBS_SORT,
    //! Standard
    uixListBoxStyle_Standard = LBS_STANDARD,
    //! Use tab stops
    uixListBoxStyle_UseTabStops = LBS_USETABSTOPS,
    //! Wants keyboard input
    uixListBoxStyle_WantKeyboardInput = LBS_WANTKEYBOARDINPUT,
};

//! List Box control
//! @brief
//!     This class implements list box GUI control
//! @note
//!     Notify message entries are starting with uixEVT_LBN_
class UIXAPI uixListBoxCtrl : public uixWindow
{
    uixDECLARE_DYNAMIC_CLASS(uixListBoxCtrl);
public:
    //! Constructor
    uixListBoxCtrl();

    //! Destructor
    virtual ~uixListBoxCtrl();

    //! @copydoc uixWindow::BeforeWindowCreate
    virtual BOOL BeforeWindowCreate(CREATESTRUCT& cs) override;

    //! Gets list box flags
    DWORD GetListBoxInfo() const;

    //! Gets item ID from point
    //! @param[in] pt
    //!     Point
    //! @param[in] autoScroll
    //!     Use auto scroll?
    //! @return
    //!     Item ID
    INT ItemFromPoint(POINT pt, BOOL autoScroll) const;

    //! Makes drag list
    //! @return
    //!     True when successful
    BOOL MakeDragList();

    //! Adds string item
    //! @param[in] text
    //!     Text
    //! @return
    //!     Item ID
    INT AddString(const uixChar* text);

    //! Adds data item
    //! @param[in] data
    //!     Data item
    //! @return
    //!     Item ID
    INT AddItemData(const void* data);

    //! Deletes item
    //! @param[in] itemID
    //!     Item ID to delete
    //! @return
    //!     Number of items left
    INT DeleteString(INT itemID);

    //! Enumerate directory content
    //! @param[in] attributes
    //!     Attributes
    //! @param[in] fileSpec
    //!     File specifier
    //! @return
    //!     Number of items
    INT Dir(UINT attributes, const uixChar* fileSpec);

    //! Finds item by data
    //! @param[in] startID
    //!     Start ID, -1 from begin
    //! @param[in] data
    //!     Data to find
    //! @return
    //!     Item ID
    INT FindItemData(INT startID, const void* data) const;

    //! Finds item by string
    //! @param[in] startID
    //!     Start ID, -1 from begin
    //! @param[in] text
    //!     Text to find
    //! @return
    //!     Item ID
    INT FindString(INT startID, const uixChar* text) const;

    //! Finds exact string
    //! @param[in] startID
    //!     Start ID, -1 from begin
    //! @param[in] text
    //!     Text
    //! @return
    //!     Item ID
    INT FindStringExact(INT startID, const uixChar* text) const;

    //! Gets caret index
    //! @return
    //!     Caret index
    INT GetCaretIndex() const;

    //! Gets item count
    //! @return
    //!     Item count
    INT GetCount() const;

    //! Gets current selection
    //! @return
    //!     Selected item ID
    INT GetCurrentSelection() const;

    //! Gets horizontal extent
    //! @return
    //!     Extent value
    INT GetHorizontalExtent() const;

    //! Gets item data by ID
    //! @param[in] itemID
    //!     Item ID
    //! @return
    //!     Item data
    void* GetItemData(INT itemID) const;

    //! Gets item height
    //! @param[in] itemID
    //!     Item ID
    //! @return
    //!     Item height
    INT GetItemHeight(INT itemID) const;

    //! Gets item rect
    //! @param[in] itemID
    //!     Item ID
    //! @param[out] rect
    //!     Rect
    //! @return
    //!     True when successful
    BOOL GetItemRect(INT itemID, RECT& rect) const;

    //! Get selected
    //! @param[in] itemID
    //!     Item ID
    //! @return
    //!     Flags
    DWORD GetSelected(INT itemID) const;

    //! Gets selected count
    //! @return
    //!     Number of selected items
    INT GetSelectedCount() const;

    //! Gets selected items
    //! @param[out] items
    //!     Array of item IDs
    //! @param[in] itemCount
    //!     Number of elements in items array
    //! @return
    //!     Number of readed items
    INT GetSelectedItems(INT items[], INT itemCount) const;

    //! Gets item text
    //! @param[in] itemID
    //!     Item ID
    //! @param[out] text
    //!     Text buffer
    //! @return
    //!     Number of readed chars
    INT GetString(INT itemID, uixChar* text) const;

    //! Gets text length
    //! @param[in] itemID
    //!     Item ID
    //! @return
    //!     Text length
    INT GetStringLength(INT itemID) const;

    //! Gets top index
    //! @return
    //!     Index of top item
    INT GetTopIndex() const;

    //! Insert item with data
    //! @param[in] itemID
    //!     Target ID
    //! @param[in] data
    //!     Data
    //! @return
    //!     Index of new item
    INT InsertItemData(INT itemID, const void* data);

    //! Inserts string
    //! @param[in] itemID
    //!     Item ID
    //! @param[in] text
    //!     Text
    //! @return
    //!     Index of new item
    INT InsertString(INT itemID, const uixChar* text);

    //! Resets control content
    //! @return
    //!     True when successful
    BOOL ResetContent();

    //! Selects item data
    //! @param[in] startID
    //!     Start ID, -1 from begin
    //! @param[in] data
    //!     Item data
    //! @return
    //!     Item ID of selected item
    INT SelectItemData(INT startID, const void* data);

    //! Selects item by text
    //! @param[in] startID
    //!     Start ID, -1 from begin
    //! @param[in] text
    //!     Item text
    //! @return
    //!     Item ID of selected item
    INT SelectString(INT startID, const uixChar* text);

    //! Selects item range
    //! @param[in] firstID
    //!     Start ID, -1 from begin
    //! @param[in] lastID
    //!     Last ID, -1 to end
    //! @param[in] select
    //!     True to select, false otherwise
    //! @return
    //!     Number of selected items
    INT SelectItemRange(INT firstID, INT lastID, BOOL select = FALSE);

    //! Sets caret index
    //! @param[in] itemID
    //!     Item ID
    //! @return
    //!     Previous caret index
    INT SetCaretIndex(INT itemID);

    //! Sets column width
    //! @param[in] width
    //!     Width
    void SetColumnWidth(INT width);

    //! Sets current selection
    //! @param[in] itemID
    //!     Item ID
    //! @return
    //!     Previous selected item ID
    INT SetCurrentSelection(INT itemID);

    //! Sets horizontal extent
    //! @param[in] extent
    //!     Extent
    void SetHorizontalExtent(INT extent);

    //! Sets item data
    //! @param[in] itemID
    //!     Item ID
    //! @param[in] data
    //!     Data
    //! @return
    //!     ID
    INT SetItemData(INT itemID, const void* data);

    //! Sets item height
    //! @param[in] itemID
    //!     Item ID
    //! @param[in] height
    //!     Item height
    //! @return
    //!     Previous height
    INT SetItemHeight(INT itemID, INT height);

    //! Sets selection
    //! @param[in] itemID
    //!     Item ID to select
    //! @param[in] select
    //!     True to select, false otherwise
    //! @return
    //!     ID
    INT SetSelection(INT itemID, BOOL select);

    //! Sets tab stops
    //! @param[in] tabs
    //!     Array of tab stops elements
    //! @param[in] count
    //!     Number of elements in tabs array
    //! @return
    //!     True when successful
    BOOL SetTabStops(INT tabs[], INT count);

    //! Sets top index
    //! @param[in] itemID
    //!     Item ID
    //! @return
    //!     Previous top item ID
    INT SetTopIndex(INT itemID);
};
}
//----------------------------------------------------------------------------//
#include "uixlistboxctrl.inl"
//----------------------------------------------------------------------------//
#endif /* _UIX_LISTBOXCTRL_H__ */