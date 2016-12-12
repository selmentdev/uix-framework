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
#ifndef _UIX_COMBOBOX_H__
#define _UIX_COMBOBOX_H__
//----------------------------------------------------------------------------//
#include "uixwindow.h"
//----------------------------------------------------------------------------//
namespace UIX
{
//! Handle Error Space notify code
#define uixEVT_CBN_ERRSPACE(Identifier, Handler) \
    uixEVT_CONTROL(CBN_ERRSPACE, Identifier, Handler)

//! Handle Selection change
#define uixEVT_CBN_SELCHANGE(Identifier, Handler) \
    uixEVT_CONTROL(CBN_SELCHANGE, Identifier, Handler)

//! Handle double click
#define uixEVT_CBN_DOUBLECLICKED(Identifier, Handler) \
    uixEVT_CONTROL(CBN_DBLCLK, Identifier, Handler)

//! Handle set focus
#define uixEVT_CBN_SETFOCUS(Identifier, Handler) \
    uixEVT_CONTROL(CBN_SETFOCUS, Identifier, Handler)

//! Handle kill focus
#define uixEVT_CBN_KILLFOCUS(Identifier, Handler) \
    uixEVT_CONTROL(CBN_KILLFOCUS, Identifier, Handler)

//! Handle edit change
#define uixEVT_CBN_EDITCHANGE(Identifier, Handler) \
    uixEVT_CONTROL(CBN_EDITCHANGE, Identifier, Handler)

//! Handle edit update
#define uixEVT_CBN_EDITUPDATE(Identifier, Handler) \
    uixEVT_CONTROL(CBN_EDITUPDATE, Identifier, Handler)

//! Handle list drop down
#define uixEVT_CBN_DROPDOWN(Identifier, Handler) \
    uixEVT_CONTROL(CBN_DROPDOWN, Identifier, Handler)

//! Handle list close up
#define uixEVT_CBN_CLOSEUP(Identifier, Handler) \
    uixEVT_CONTROL(CBN_CLOSEUP, Identifier, Handler)

//! Handle selection end ok
#define uixEVT_CBN_SELENDOK(Identifier, Handler) \
    uixEVT_CONTROL(CBN_SELENDOK, Identifier, Handler)

//! Handle selection end cancel
#define uixEVT_CBN_SELENDCANCEL(Identifier, Handler) \
    uixEVT_CONTROL(CBN_SELENDCANCEL, Identifier, Handler)


//! Combo Box style
enum uixComboBoxStyle
{
    //! None
    uixComboBoxStyle_None = 0,
    //! Simple
    uixComboBoxStyle_Simple = CBS_SIMPLE,
    //! Drop Down
    uixComboBoxStyle_DropDown = CBS_DROPDOWN,
    //! Drop Down List
    uixComboBoxStyle_DropDownList = CBS_DROPDOWNLIST,
    //! Owner Draw - fixed
    uixComboBoxStyle_OwnerDrawFixed = CBS_OWNERDRAWFIXED,
    //! Owner Draw variable
    uixComboBoxStyle_OwnerDrawVariable = CBS_OWNERDRAWVARIABLE,
    //! Auto Horizontal Scroll
    uixComboBoxStyle_AutoHScroll = CBS_AUTOHSCROLL,
    //! Oem char convert
    uixComboBoxStyle_OemConvert = CBS_OEMCONVERT,
    //! Sorting enabled
    uixComboBoxStyle_Sort = CBS_SORT,
    //! Has strings
    uixComboBoxStyle_HasStrings = CBS_HASSTRINGS,
    //! No integral height
    uixComboBoxStyle_NoIntegralHeight = CBS_NOINTEGRALHEIGHT,
    //! Disable no scroll
    uixComboBoxStyle_DisableNoScroll = CBS_DISABLENOSCROLL,
    //! Upper case
    uixComboBoxStyle_UpperCase = CBS_UPPERCASE,
    //! Lower case
    uixComboBoxStyle_LowerCase = CBS_LOWERCASE,
};

//! Combo box control
//! @brief
//!     Combo box allows you to choose one item from range of items
class UIXAPI uixComboBox : public uixWindow
{
    uixDECLARE_DYNAMIC_CLASS(uixComboBox);
public:
    //! Constructor
    uixComboBox();

    //! Destructor
    virtual ~uixComboBox();

    //! @copydoc uixWindow::BeforeWindowCreate
    virtual BOOL BeforeWindowCreate(CREATESTRUCT& cs) override;

    //! Adds item with data
    //! @param[in] data
    //!     Data pointer
    //! @result
    //!     New Item ID
    INT AddItemData(const void* data);

    //! @copydoc uixComboBox::AddItemData(const void* data)
    template <typename TType>
    INT AddItemData(const TType& data);

    //! Adds string item
    //! @param[in] text
    //!     Text of item
    //! @return
    //!     New Item ID
    INT AddString(const uixChar* text);

    //! Delete item
    //! @param[in] itemID
    //!     ID of item to delete
    //! @return
    //!     Number of remainings items
    INT DeleteString(INT itemID);

    //! Enumerate items from directory
    //! @param[in] attributes
    //!     Attributes flags
    //! @param[in] fileSpec
    //!     Path to directory
    //! @return
    //!     Zero based index of last name added to list
    //! @remarks
    //!     Check return value for CB_ERR
    INT Dir(UINT attributes, const uixChar* fileSpec);

    //! Finds item by data
    //! @param[in] firstID
    //!     First ID to search from
    //! @param[in] data
    //!     Data pointer to search
    //! @return
    //!     Item ID, check for CB_ERR
    INT FindItemData(INT firstID, const void* data) const;

    //! Finds by string
    //! @param[in] firstID
    //!     First ID to search from
    //! @param[in] text
    //!     Text to search
    //! @return
    //!     Item ID, check for CB_ERR value
    INT FindString(INT firstID, const uixChar* text) const;

    //! Finds exact string
    //! @param[in] firstID
    //!     First ID to search from
    //! @param[in] text
    //!     Text to search
    //! @return
    //!     Item ID, check for CB_ERR value
    INT FindStringExact(INT firstID, const uixChar* text) const;

    //! Gets number of items
    //! @return
    //!     Number of items
    INT GetItemCount() const;

    //! Gets cue banner text
    //! @param[out] text
    //!     Text buffer
    //! @param[in] length
    //!     Text length
    //! @return
    //!     True when successful
    BOOL GetCueBanner(uixChar* text, INT length) const;

    //! Gets current selection
    //! @return
    //!     Item ID of currently selected item
    INT GetCurrentSelection() const;

    //! Gets drop down rect area
    //! @param[out] rect
    //!     Rect of drop down area
    void GetDroppedControlRect(RECT& rect) const;

    //! Gets dropped state
    //! @return
    //!     True, when drop down list is dropped down
    BOOL GetDroppedState() const;

    //! Gets extended ui state
    //! @return
    //!     True, when extended UI is enabled
    BOOL GetExtendedUI() const;

    //! Gets item data
    //! @param[in] itemID
    //!     Item ID
    //! @return
    //!     Item Data
    void* GetItemData(INT itemID) const;

    //! Gets item height
    //! @return
    //!     Item height
    INT GetItemHeight() const;

    //! Gets item string
    //! @param[in] itemID
    //!     Item ID
    //! @param[in] text
    //!     Text buffer
    //! @return
    //!     Number of characters in string, CB_ERR otherwise
    INT GetItemString(INT itemID, uixChar* text) const;

    //! Gets items string length
    //! @param[in] itemID
    //!     Item ID
    //! @return
    //!     Text length
    INT GetItemStringLength(INT itemID) const;

    //! Gets min number of visible items
    //! @return
    //!     Min number of visible items
    INT GetMinVisible() const;

    //! Inserts item with data
    //! @param[in] itemID
    //!     Item ID
    //! @param[in] data
    //!     Data of item
    //! @return
    //!     Zero based index of item, CB_ERR otherwise
    INT InsertItemData(INT itemID, const void* data);

    //! Inserts string
    //! @param[in] itemID
    //!     Item ID
    //! @param[in] text
    //!     Text of item
    //! @return
    //!     Zero based index of item, CB_ERR otherwise
    //! @note
    //!     This function API is weird. @see text
    INT InsertString(INT itemID, uixChar* text);

    //! Sets limit for text
    //! @param[in] limit
    //!     Max number of characters
    void LimitText(INT limit);

    //! Resets content
    void ResetContent();
    //! Select item by data
    //! @param[in] startID
    //!     Start index, -1 search from begin
    //! @param[in] data
    //!     Data of item to select
    //! @return
    //!     Index of selected item, CB_ERR otherwise
    INT SelectItemData(INT startID, const void* data);

    //! Select item by string
    //! @param[in] startID
    //!     Start index, -1 search from begin
    //! @param[in] text
    //!     Text to select
    //! @return
    //!     Index of selected item, CB_ERR otherwise
    INT SelectString(INT startID, const uixChar* text);

    //! Sets cue banner text
    //! @param[in] text
    //!     New cue banner text
    //! @return
    //!     True when successful
    BOOL SetCueBanner(const uixChar* text);

    //! Sets currently selected item
    //! @param[in] itemID
    //!     Item to select
    //! @return
    //!     Previous selection
    INT SetCurrentSelection(INT itemID);

    //! Sets extended UI flags
    //! @param[in] enabled
    //!     Extended UI enabled flag
    //! @return
    //!     Previous state
    BOOL SetExtendedUI(BOOL enabled);

    //! Sets item data
    //! @param[in] itemID
    //!     Item ID
    //! @param[in] data
    //!     New data for item
    //! @return
    //!     True when successful
    BOOL SetItemData(INT itemID, const void* data);

    //! Sets new item height
    //! @param[in] itemID
    //!     Item ID
    //! @param[in] height
    //!     New item height
    //! @return
    //!     True when successful
    BOOL SetItemHeight(INT itemID, INT height);

    //! Sets min number visible items
    //! @param[in] minVisible
    //!     Min number of visible items
    //! @return
    //!     True when successful
    BOOL SetMinVisible(INT minVisible);

    //! Shows drop down list
    //! @param[in] show
    //!     Show flag
    //! @return
    //!     True when successful
    BOOL ShowDropdown(BOOL show = TRUE);
};
}
//----------------------------------------------------------------------------//
#include "uixcombobox.inl"
//----------------------------------------------------------------------------//
#endif /* _UIX_COMBOBOX_H__ */