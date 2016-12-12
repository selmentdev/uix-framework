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
#ifndef _UIX_HEADERCTRL_H__
#define _UIX_HEADERCTRL_H__
//----------------------------------------------------------------------------//
#include "uixwindow.h"
//----------------------------------------------------------------------------//
namespace UIX
{
//! Handle begin drag nm
#define uixEVT_HDN_BEGINDRAG(Identifier, Handler) \
    uixEVT_NOTIFY(HDN_BEGINDRAG, Identifier, Handler)

//! Handle begin filter edit
#define uixEVT_HDN_BEGINFILTEREDIT(Identifier, Handler) \
    uixEVT_NOTIFY(HDN_BEGINFILTEREDIT, Identifier, Handler)

//! Handle begin track
#define uixEVT_HDN_BEGINTRACK(Identifier, Handler) \
    uixEVT_NOTIFY(HDN_BEGINTRACK, Identifier, Handler)

//! Handle divider double click
#define uixEVT_HDN_DIVIDERDBLCLICK(Identifier, Handler) \
    uixEVT_NOTIFY(HDN_DIVIDERDBLCLICK, Identifier, Handler)

//! Handle drop down
#define uixEVT_HDN_DROPDOWN(Identifier, Handler) \
    uixEVT_NOTIFY(HDN_DROPDOWN, Identifier, Handler)

//! Handle end drag
#define uixEVT_HDN_ENDDRAG(Identifier, Handler) \
    uixEVT_NOTIFY(HDN_ENDDRAG, Identifier, Handler)

//! Handle end filter edit
#define uixEVT_HDN_ENDFILTEREDIT(Identifier, Handler) \
    uixEVT_NOTIFY(HDN_ENDFILTEREDIT, Identifier, Handler)

//! Handle filter btn click
#define uixEVT_HDN_FILTERBTNCLICK(Identifier, Handler) \
    uixEVT_NOTIFY(HDN_FILTERBTNCLICK, Identifier, Handler)

//! Handle filter change
#define uixEVT_HDN_FILTERCHANGE(Identifier, Handler) \
    uixEVT_NOTIFY(HDN_FILTERCHANGE, Identifier, Handler)

//! Handle get display info
#define uixEVT_HDN_GETDISPINFO(Identifier, Handler) \
    uixEVT_NOTIFY(HDN_GETDISPINFO, Identifier, Handler)

//! Handle item changed
#define uixEVT_HDN_ITEMCHANGED(Identifier, Handler) \
    uixEVT_NOTIFY(HDN_ITEMCHANGED, Identifier, Handler)

//! Handle item changing
#define uixEVT_HDN_ITEMCHANGING(Identifier, Handler) \
    uixEVT_NOTIFY(HDN_ITEMCHANGING, Identifier, Handler)

//! Handle item click
#define uixEVT_HDN_ITEMCLICK(Identifier, Handler) \
    uixEVT_NOTIFY(HDN_ITEMCLICK, Identifier, Handler)

//! Handle item double click
#define uixEVT_HDN_ITEMDBLCLICK(Identifier, Handler) \
    uixEVT_NOTIFY(HDN_ITEMDBLCLICK, Identifier, Handler)

//! Handle item key down
#define uixEVT_HDN_ITEMKEYDOWN(Identifier, Handler) \
    uixEVT_NOTIFY(HDN_ITEMKEYDOWN, Identifier, Handler)

//! Handle state icon click
#define uixEVT_HDN_ITEMSTATEICONCLICK(Identifier, Handler) \
    uixEVT_NOTIFY(HDN_ITEMSTATEICONCLICK, Identifier, Handler)

//! Handle overflow click
#define uixEVT_HDN_OVERFLOWCLICK(Identifier, Handler) \
    uixEVT_NOTIFY(HDN_OVERFLOWCLICK, Identifier, Handler)

//! Handle track
#define uixEVT_HDN_TRACK(Identifier, Handler) \
    uixEVT_NOTIFY(HDN_TRACK, Identifier, Handler)

//! Header item format
enum uixHeaderItemFormat
{
    //! None
    uixHeaderItemFormat_None = 0,
    //! Text aligned to center
    uixHeaderItemFormat_TextCenter = HDF_CENTER,
    //! Text aligned to left
    uixHeaderItemFormat_TextLeft = HDF_LEFT,
    //! Text aligned to right
    uixHeaderItemFormat_TextRight = HDF_RIGHT,
    //! Display bitmap
    uixHeaderItemFormat_DisplayBitmap = HDF_BITMAP,
    //! Display bitmap on right
    uixHeaderItemFormat_DisplayBitmapOnRight = HDF_BITMAP_ON_RIGHT,
    //! Owner draw
    uixHeaderItemFormat_DisplayOwnerDraw = HDF_OWNERDRAW,
    //! Display string
    uixHeaderItemFormat_DisplayString = HDF_STRING,
    //! Display image
    uixHeaderItemFormat_Image = HDF_IMAGE,
    //! RTL reading
    uixHeaderItemFormat_RtlReading = HDF_RTLREADING,
    //! Sort down
    uixHeaderItemFormat_SortDown = HDF_SORTDOWN,
    //! Sort up
    uixHeaderItemFormat_SortUp = HDF_SORTUP,
    //! Checkbox
    uixHeaderItemFormat_Checkbox = HDF_CHECKBOX,
    //! Checked
    uixHeaderItemFormat_Checked = HDF_CHECKED,
    //! Fixed width
    uixHeaderItemFormat_FixedWidth = HDF_FIXEDWIDTH,
    //! Split button
    uixHeaderItemFormat_SplitButton = HDF_SPLITBUTTON,
};

//! Header item type
enum uixHeaderItemType
{
    //! None
    uixHeaderItemType_None = 0,
    //! String
    uixHeaderItemType_String = HDFT_ISSTRING,
    //! Number
    uixHeaderItemType_Number = HDFT_ISNUMBER,
    //! No value
    uixHeaderItemType_NoValue = HDFT_HASNOVALUE,
    //! Date
    uixHeaderItemType_IsDate = HDFT_ISDATE,
};

//! Header control item
struct uixHeaderItem : HDITEM
{
    //! Constructor
    uixHeaderItem();

    //! Gets mask
    //! @return
    //!     Struct fields mask
    DWORD GetMask() const;

    //! Sets fields mask
    //! @param[in] value
    //!     Fields mask
    void SetMask(DWORD value);

    //! Gets item width
    //! @return
    //!     Item width
    INT GetWidth() const;

    //! Sets item width
    //! @param[in] value
    //!     Width
    void SetWidth(INT value);

    //! Gets item text
    //! @return
    //!     Item text
    const uixChar* GetText() const;

    //! Sets item text
    //! @param[in] value
    //!     Item text
    void SetText(const uixChar* value);

    //! Sets item text
    //! @param[in] value
    //!     Text
    //! @param[in] length
    //!     Text length
    void SetText(const uixChar* value, INT length);

    //! Sets text length
    //! @param[in] length
    //!     Text length
    void SetTextLength(INT length);

    //! Gets bitmap handle
    //! @return
    //!     Bitmap handle
    HBITMAP GetBitmap() const;

    //! Sets bitmap handle
    //! @param[in] value
    //!     Bitmap handle
    void SetBitmap(HBITMAP value);

    //! Gets format
    //! @return
    //!     Format
    uixHeaderItemFormat GetFormat() const;

    //! Sets format
    //! @param[in] value
    //!     Format
    void SetFormat(uixHeaderItemFormat value);

    //! Gets item data
    //! @return
    //!     Data
    void* GetData() const;

    //! Sets item data
    //! @param[in] value
    //!     Item data
    void SetData(const void* value);

    //! Gets image index
    //! @return
    //!     Image index
    INT GetImage() const;

    //! Sets image index
    //! @param[in] value
    //!     Image index
    void SetImage(INT value);

    //! Gets order id
    //! @return
    //!     Order id
    INT GetOrder() const;

    //! Sets order id
    //! @param[in] value
    //!     Order ID
    void SetOrder(INT value);

    //! Gets type
    //! @return
    //!     Type
    uixHeaderItemType GetType() const;

    //! Sets type
    //! @param[in] value
    //!     Type
    void SetType(uixHeaderItemType value);

    //! Gets filter value
    //! @return
    //!     Filter value
    void* GetFilter() const;

    //! Sets filter value
    //! @param[in] value
    //!     Filter value
    void SetFilter(const void* value);

    //! Gets state
    //! @return
    //!     Item state
    UINT GetState() const;

    //! Sets item state
    //! @param[in] value
    //!     Item state
    void SetState(UINT value);

    //! Is Item focused
    //! @return
    //!     True when successful
    BOOL IsFocused() const
    {
        return GetState() == HDIS_FOCUSED;
    }

    //! Set item focused
    //! @param[in] focused
    //!     True when item is focused
    void SetFocused(BOOL focused)
    {
        SetState(focused ? HDIS_FOCUSED : 0);
    }
};

struct uixHeaderHitTest : HDHITTESTINFO
{
};


//! Header Control style
enum uixHeaderStyle
{
    //! None
    uixHeaderStyle_None = 0,
    //! Horizontal
    uixHeaderStyle_Horizontal = HDS_HORZ,
    //! Buttons
    uixHeaderStyle_Buttons = HDS_BUTTONS,
    //! Hot item tracking
    uixHeaderStyle_HotTrack = HDS_HOTTRACK,
    //! Hidden
    uixHeaderStyle_Hidden = HDS_HIDDEN,
    //! Drag and drop support
    uixHeaderStyle_DragDrop = HDS_DRAGDROP,
    //! Full drag
    uixHeaderStyle_FullDrag = HDS_FULLDRAG,
    //! Filter bar
    uixHeaderStyle_FilterBar = HDS_FILTERBAR,
    //! Flat
    uixHeaderStyle_Flat = HDS_FLAT,
    //! Checkboxes
    uixHeaderStyle_Checkboxes = HDS_CHECKBOXES,
    //! No sizing enabled
    uixHeaderStyle_Nosizing = HDS_NOSIZING,
    //! Overflow
    uixHeaderStyle_Overflow = HDS_OVERFLOW,
    //! Default
    uixHeaderStyle_Default = uixHeaderStyle_None,
};

//! Header control
//! @brief
//!     Header control allows you to create columns.
//! @note
//!     Notify message entries are starting with uixEVT_HDN_
class UIXAPI uixHeaderCtrl : public uixWindow
{
    uixDECLARE_DYNAMIC_CLASS(uixHeaderCtrl);
public:
    //! Constructor
    uixHeaderCtrl();

    //! Destructor
    virtual ~uixHeaderCtrl();

    //! @copydoc uixWindow::BeforeWindowCreate
    virtual BOOL BeforeWindowCreate(CREATESTRUCT& cs) override;

    //! Gets item count
    //! @return
    //!     Items count
    INT GetItemCount() const;

    //! Gets item with itemID
    //! @param[in] itemID
    //!     Item ID
    //! @param[out] item
    //!     Item data
    //! @return
    //!     True when successful
    BOOL GetItem(INT itemID, HDITEM& item) const;

    //! Sets item with itemID to item variable
    //! @param[in] itemID
    //!     ItemID
    //! @param[in] item
    //!     Item Data
    //! @return
    //!     True when successful
    BOOL SetItem(INT itemID, const HDITEM& item);

    //! Gets text with itemID
    //! @param[in] itemID
    //!     Item ID
    //! @param[out] text
    //!     Text buffer
    //! @param[in] textLength
    //!     Text buffer length
    //! @return
    //!     True when successful
    BOOL GetItemText(INT itemID, uixChar* text, INT textLength) const;

    //! Gets full info about item
    //! @param[in] itemID
    //!     Item ID
    //! @param[out] item
    //!     Item
    //! @param[out] text
    //!     Text buffer
    //! @param[in] textLength
    //!     Text buffer length
    //! @return
    //!     True when successful
    BOOL GetItemFull(INT itemID, HDITEM& item, uixChar* text, INT textLength) const;

    //! Gets image list
    //! @return
    //!     Image List
    HIMAGELIST GetImageList() const;

    //! Sets image list
    //! @param[in] handle
    //!     Image list handle
    //! @return
    //!     Previuos image list handle
    HIMAGELIST SetImageList(HIMAGELIST handle);

    //! Get order array
    //! @param[out] indices
    //!     Indices array
    //! @param[in] count
    //!     Number of element in indices array
    //! @return
    //!     True when successful
    BOOL GetOrderArray(INT indices[], INT count) const;

    //! Set order array
    //! @param[in] indices
    //!     Indices array
    //! @param[in] count
    //!     Number of elements in indices array
    //! @return
    //!     True when successful
    BOOL SetOrderArray(INT indices[], INT count);

    //! Gets item rect with itemID
    //! @param[in] itemID
    //!     Item ID
    //! @param[out] rect
    //!     Rect
    //! @return
    //!     True when successful
    BOOL GetItemRect(INT itemID, RECT& rect) const;

    //! Sets hot divider
    //! @param[in] position
    //!     Position
    //! @param[in] inputValue
    //!     Input Value
    //! @return
    //!     Int
    INT SetHotDivider(BOOL position, DWORD inputValue);

    //! Gets Unicode format
    //! @return
    //!     True when unicode is supported
    BOOL GetUnicodeFormat() const;

    //! Sets Unicode format
    //! @param[in] unicode
    //!     Unicode support flag
    //! @return
    //!     Previous unicode support flag
    BOOL SetUnicodeFormat(BOOL unicode);

    //! Insert item at itemID
    //! @param[in] itemID
    //!     Item ID
    //! @param[in] item
    //!     Item data
    //! @return
    //!     New Item ID
    INT InsertItem(INT itemID, HDITEM& item);

    //! Delete item with itemID
    //! @param[in] itemID
    //!     Item ID
    //! @return
    //!     True when successful
    BOOL DeleteItem(INT itemID);

    //! Sets control layout
    //! @param[in] layout
    //!     Layout
    //! @return
    //!     True when successful
    BOOL Layout(HD_LAYOUT& layout);

    //! Perform hit test
    //! @param[in] hti
    //!     Hit test data
    //! @return
    //!     Hit test result
    INT HitTest(HDHITTESTINFO& hti);

    //! Translate order to itemID
    //! @param[in] order
    //!     Order ID
    //! @result
    //!     Item ID
    INT OrderToIndex(INT order);

    //! Create drag image of item at index
    //! @param[in] index
    //!     Item ID
    //! @return
    //!     Drag image list handle
    HIMAGELIST CreateDragImage(INT index);

    //! Clears all filters
    //! @return
    //!     True when successful
    BOOL ClearAllFilters();

    //! Clears filter for itemID
    //! @param[in] itemID
    //!     Item ID
    //! @return
    //!     True when successful
    BOOL ClearFilter(INT itemID);

    //! Edit filter for itemID
    //! @param[in] itemID
    //!     Item ID
    //! @param[in] discard
    //!     Discard flag
    //! @return
    //!     True when successful
    BOOL EditFilter(INT itemID, BOOL discard);

    //! Gets bitmap margin
    //! @return
    //!     Bitmap margin
    INT GetBitmapMargin() const;

    //! Gets focused item
    //! @return
    //!     ItemID of focused item
    INT GetFocusedItem() const;

    //! Gets drop down rect for item with itemID
    //! @param[in] itemID
    //!     Item ID
    //! @param[out] rect
    //!     Drop down rect for item
    //! @return
    //!     True when successful
    BOOL GetItemDropDownRect(INT itemID, RECT& rect) const;

    //! Gets overflow rect
    //! @param[out] rect
    //!     Overflow rect
    //! @return
    //!     True when successful
    BOOL GetOverflowRect(RECT& rect) const;

    //! Gets state image list
    //! @return
    //!     State image list
    HIMAGELIST GetStateImageList() const;

    //! Sets bitmap width
    //! @param[in] width
    //!     Bitmap width
    //! @return
    //!     Previous bitmap margin
    INT SetBitmapMargin(INT width);

    //! Sets filter change timeout
    //! @param[in] timeout
    //!     Timeout in ms
    //! @return
    //!     Previous timeout value
    INT SetFilterChangeTimeout(INT timeout);

    //! Sets focused item
    //! @param[in] itemID
    //!     ID of item to focus
    //! @return
    //!     True when successful
    BOOL SetFocusedItem(INT itemID);

    //! Sets state image list
    //! @param[in] imageList
    //!     Handle to image list
    //! @return
    //!     True when successful
    BOOL SetStateImageList(HIMAGELIST imageList);
};
}
//----------------------------------------------------------------------------//
#include "uixheaderctrl.inl"
//----------------------------------------------------------------------------//
#endif /* _UIX_HEADERCTRL_H__ */