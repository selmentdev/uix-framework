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
#ifndef _UIX_MENU_H__
#define _UIX_MENU_H__
//----------------------------------------------------------------------------//
#include "uixobject.h"
//----------------------------------------------------------------------------//
namespace UIX
{
//! Menu item type
enum uixMenuItemType_enum
{
    //! Bitmap
    uixMenuItemType_Bitmap = MFT_BITMAP,
    //! Bar break
    uixMenuItemType_MenuBarBreak = MFT_MENUBARBREAK,
    //! Break
    uixMenuItemType_MenuBreak = MFT_MENUBREAK,
    //! Owner draw
    uixMenuItemType_OwnerDraw = MFT_OWNERDRAW,
    //! Radio check
    uixMenuItemType_RadioCheck = MFT_RADIOCHECK,
    //! Right justify
    uixMenuItemType_RightJustify = MFT_RIGHTJUSTIFY,
    //! Right order
    uixMenuItemType_RightOrder = MFT_RIGHTORDER,
    //! Separator
    uixMenuItemType_Separator = MFT_SEPARATOR,
    //! String
    uixMenuItemType_String = MFT_STRING,
};
//! Menu item type
typedef DWORD uixMenuItemType;

//! Menu item state
enum uixMenuItemState_enum
{
    //! Checked
    uixMenuItemState_Checked = MFS_CHECKED,
    //! Default
    uixMenuItemState_Default = MFS_DEFAULT,
    //! Disabled
    uixMenuItemState_Disabled = MFS_DISABLED,
    //! Enabled
    uixMenuItemState_Enabled = MFS_ENABLED,
    //! Grayed
    uixMenuItemState_Grayed = MFS_GRAYED,
    //! Highlight
    uixMenuItemState_Highlight = MFS_HILITE,
    //! Unchecked
    uixMenuItemState_Unchecked = MFS_UNCHECKED,
    //! Unhighlighted
    uixMenuItemState_UnHighlight = MFS_UNHILITE,
};
//! Menu item state type
typedef DWORD uixMenuItemState;

//! Menu Item Info
struct uixMenuItemInfo : MENUITEMINFO
{
    //! Constructor
    uixMenuItemInfo();

    //! Gets mask
    //! @return
    //!     Mask flag
    DWORD GetMask() const;

    //! Sets mask flag
    //! @param[in] value
    //!     Mask value
    void SetMask(DWORD value);

    //! Gets item type
    //! @return
    //!     Type
    uixMenuItemType GetType() const;

    //! Sets item type
    //! @param[in] value
    //!     New type
    void SetType(uixMenuItemType value);

    //! Gets item state
    //! @return
    //!     Item state
    uixMenuItemState GetState() const;

    //! Sets item state
    //! @param[in] value
    //!     State
    void SetState(uixMenuItemState value);

    //! Gets item ID
    //! @return
    //!     Item ID
    UINT GetID() const;

    //! Sets item ID
    //! @param[in] value
    //!     New item ID
    void SetID(UINT value);

    //! Gets sub menu handle
    //! @return
    //!     Submenu handle
    HMENU GetSubMenu() const;

    //! Sets sub menu handle
    //! @param[in] value
    //!     Sub menu handle
    void SetSubMenu(HMENU value);

    //! Gets bitmap checked
    //! @return
    //!     Handle to checked bitmap
    HBITMAP GetBitmapChecked() const;

    //! Sets bitmap checked
    //! @param[in] value
    //!     Handle to bitmap with checked image
    void SetBitmapChecked(HBITMAP value);

    //! Gets bitmap unchecked
    //! @return
    //!     Handle to unchecked bitmap
    HBITMAP GetBitmapUnchecked() const;

    //! Sets bitmap unchecked
    //! @param[in] value
    //!     Handle to bitmap with unchecked image
    void SetBitmapUnchecked(HBITMAP value);

    //! Gets item data
    //! @return
    //!     Item data
    void* GetData() const;

    //! Sets item data
    //! @param[in] value
    //!     Item data
    void SetData(const void* value);

    //! Gets Type data
    //! @return
    //!     Data
    void* GetTypeData() const;

    //! Sets type data
    //! @param[in] value
    //!     Type data
    void SetTypeData(const void* value);

    //! Gets text length
    //! @return
    //!     Text length
    UINT GetTextLength() const;

    //! Sets text length
    //! @param[in] value
    //!     Text length
    void SetTextLength(UINT value);

    //! Gets bitmap item
    //! @return
    //!     Handle to item bitmap
    HBITMAP GetBitmapItem() const;

    //! Sets bitmap item handle
    //! @param[in] value
    //!     Handle to item bitmap
    void SetBitmapItem(HBITMAP value);
};

//! Menu info style
enum uixMenuInfoStyle_enum
{
    //! Auto dismiss
    uixMenuInfoStyle_AutoDismiss = MNS_AUTODISMISS,
    //! Check or bmp
    uixMenuInfoStyle_CheckOrBmp = MNS_CHECKORBMP,
    //! Drag drop
    uixMenuInfoStyle_DragDrop = MNS_DRAGDROP,
    //! Modeless
    uixMenuInfoStyle_Modeless = MNS_MODELESS,
    //! No check
    uixMenuInfoStyle_NoCheck = MNS_NOCHECK,
    //! Notify by pos
    uixMenuInfoStyle_NotifyByPos = MNS_NOTIFYBYPOS
};
typedef DWORD uixMenuInfoStyle;

//! Menu Info
struct uixMenuInfo : MENUINFO
{
    //! Constructor
    uixMenuInfo();

    //! Gets mask
    //! @return
    //!     Mask value
    DWORD GetMask() const;

    //! Sets mask
    //! @param[in] value
    //!     Mask value
    void SetMask(DWORD value);

    //! Gets style
    //! @return
    //!     Style
    uixMenuInfoStyle GetStyle() const;

    //! Sets style
    //! @param[in] value
    //!     Style
    void SetStyle(uixMenuInfoStyle value);

    //! Gets max height
    //! @return
    //!     Max Height
    UINT GetMaxHeight() const;

    //! Sets max height
    //! @param[in] value
    //!     Max height
    void SetMaxHeight(UINT value);

    //! Gets background brush
    //! @return
    //!     Background brush
    HBRUSH GetBackgroundBrush() const;

    //! Sets background brush
    //! @param[in] value
    //!     Background brush handle
    void SetBackgroundBrush(HBRUSH value);

    //! Gets context help ID
    //! @return
    //!     Help ID
    DWORD GetContextHelpID() const;

    //! Sets context help ID
    //! @param[in] value
    //!     Help ID
    void SetContextHelpID(DWORD value);

    //! Gets menu data
    //! @return
    //!     Data
    void* GetData() const;

    //! Sets menu data
    //! @param[in] data
    //!     Data
    void SetData(const void* data);
};

//! Menu Handle
//! @brief
//!     This class implements menu manipulation methods
class uixMenu
{
public:
    HMENU   m_Handle;       //!< Handle

    //! Constructor
    //! @param[in] handle
    //!     Menu handle
    uixMenu(HMENU handle = 0);

    //! Destructor
    ~uixMenu();

    //! Attach handle to object
    //! @param[in] handle
    //!     Handle
    void Attach(HMENU handle);

    //! Detach handle from object
    //! @return
    //!     Attached handle
    HMENU Detach();

    //! Assigment operator
    //! @param[in] handle
    //!     Handle
    //! @return
    //!     This object
    uixMenu& operator = (HMENU handle);

    //! Cast operator
    //! @return
    //!     Menu handle
    operator HMENU () const;

    //! Gets handle
    //! @return
    //!     Handle
    HMENU GetHandle() const;

    //! Gets safe handle
    //! @return
    //!     Safe handle value
    HMENU GetHandleSafe() const;

    //! Check if menu is valid
    //! @return
    //!     True when successful
    BOOL IsValid() const;

    //! Create menu
    //! @return
    //!     True when successful
    BOOL Create();

    //! Create popup menu
    //! @return
    //!     True when successful
    BOOL CreatePopup();

    //! Loads menu from resource
    //! @param[in] resource
    //!     Resource name
    //! @return
    //!     True when successful
    BOOL Load(uixResourceName resource);

    //! Loads menu from resource
    //! @param[in] resourceID
    //!     Resource ID
    //! @return
    //!     True when successful
    BOOL Load(uixResourceID resourceID);

    //! Loads menu from resource
    //! @param[in] instance
    //!     Module handle
    //! @param[in] resource
    //!     Resource Name
    //! @return
    //!     True when successful
    BOOL Load(HINSTANCE instance, uixResourceName resource);

    //! Loads menu from resource
    //! @param[in] instance
    //!     Module handle
    //! @param[in] resource
    //!     Resource ID
    //! @return
    //!     True when successful
    BOOL Load(HINSTANCE instance, uixResourceID resourceID);

    //! Destroy menu
    //! @return
    //!     True when successful
    BOOL Destroy();

    //! Delete menu item
    //! @param[in] position
    //!     Position
    //! @param[in] flags
    //!     Flags
    //! @return
    //!     True when successful
    BOOL Delete(UINT position, UINT flags);

    //! Track popup menu
    //! @param[in] flags
    //!     Flags
    //! @param[in] x
    //!     Left position
    //! @param[in] y
    //!     Top position
    //! @param[in] handle
    //!     Window handle
    //! @param[out] rect
    //!     Rect
    //! @return
    //!     True when successful
    BOOL TrackPopup(UINT flags, int x, int y, HWND handle, RECT* rect = NULLPTR);

    //! Track popup menu
    //! @param[in] flags
    //!     Flags
    //! @param[in] x
    //!     Left position
    //! @param[in] y
    //!     Top position
    //! @param[in] handle
    //!     Window handle
    //! @param[out] params
    //!     Track params
    //! @return
    //!     True when successful
    BOOL TrackPopupEx(UINT flags, int x, int y, HWND handle, TPMPARAMS* params = NULLPTR);

    //! Gets menu item info
    //! @param[in, out] info
    //!     Menu info
    //! @return
    //!     True when successful
    BOOL GetInfo(uixMenuInfo& info) const;

    //! Sets menu info
    //! @param[in] info
    //!     Menu info
    //! @return
    //!     True when successful
    BOOL SetInfo(const uixMenuInfo& info);

    //! Appends menu item
    //! @param[in] flags
    //!     Flags
    //! @param[in] id
    //!     Item ID
    //! @param[in] text
    //!     Item text
    //! @return
    //!     True when successful
    BOOL Append(UINT flags, UINT_PTR id = 0, const uixChar* text = NULLPTR);

    //! Append submenu
    //! @param[in] flags
    //!     flags
    //! @param[in] subMenu
    //!     Handle to submenu
    //! @param[in] text
    //!     Item text
    //! @return
    //!     True when successful
    BOOL Append(UINT flags, HMENU subMenu, const uixChar* text);

    //! Appends bitmap
    //! @param[in] flags
    //!     Flags
    //! @param[in] id
    //!     ID
    //! @param[in] bitmap
    //!     Bitmap handle
    //! @return
    //!     True when successful
    BOOL Append(UINT flags, UINT_PTR id, HBITMAP bitmap);

    //! Appends submenu with bitmap
    //! @param[in] flags
    //!     Flags
    //! @param[in] subMenu
    //!     Handle to submenu
    //! @param[in] bitmap
    //!     Handle to bitmap
    //! @return
    //!     True when successful
    BOOL Append(UINT flags, HMENU subMenu, HBITMAP bitmap);

    //! Checks item
    //! @param[in] id
    //!     Item ID
    //! @param[in] check
    //!     Check flags
    //! @return
    //!     Check flags
    UINT CheckItem(UINT id, UINT check);

    //! Enable item
    //! @param[in] id
    //!     Item to enable
    //! @param[in] enable
    //!     Enable flag
    //! @return
    //!     Flags
    UINT EnableItem(UINT id, UINT enable);

    //! Highlights item
    //! @param[in] handle
    //!     Window handle
    //! @param[in] itemID
    //!     Item to highlight
    //! @param[in] highlight
    //!     Highlight flags
    //! @return
    //!     True when successful
    BOOL HighlightItem(HWND handle, UINT itemID, UINT highlight);

    //! Gets item count
    //! @return
    //!     Items count
    INT GetItemCount() const;

    //! Gets item ID
    //! @param[in] position
    //!     Item positon
    //! @return
    //!     Item ID
    UINT GetItemID(INT position) const;

    //! Gets item state
    //! @param[in] itemID
    //!     Item ID
    //! @param[in] flags
    //!     flags
    //! @return
    //!     Item state
    UINT GetState(UINT itemID, UINT flags) const;

    //! Gets menu item string
    //! @param[in] itemID
    //!     Item ID
    //! @param[out] text
    //!     Text buffer
    //! @param[in] maxCount
    //!     Max count
    //! @param[in] flags
    //!     Flags
    //! @return
    //!     Text length
    INT GetString(UINT itemID, uixChar* text, INT maxCount, UINT flags) const;

    //! Gets string length
    //! @param[in] itemID
    //!     Item ID
    //! @param[in] flags
    //!     Flags
    //! @return
    //!     Text item length
    INT GetStringLength(UINT itemID, UINT flags) const;

    //! Gets sub menu by position
    //! @param[in] position
    //!     Position
    //! @return
    //!     Sub menu
    uixMenu GetSubMenu(INT position) const;

    //! Inserts item
    //! @param[in] position
    //!     Position
    //! @param[in] flags
    //!     Flags
    //! @param[in] itemID
    //!     Item ID
    //! @param[in] text
    //!     Text
    //! @return
    //!     True when successful
    BOOL Insert(UINT position, UINT flags, UINT_PTR itemID = 0, const uixChar* text = NULLPTR);

    //! Inserts item
    //! @param[in] position
    //!     Position
    //! @param[in] flags
    //!     Flags
    //! @param[in] subMenu
    //!     Sub menu handle
    //! @param[in] text
    //!     Text
    //! @return
    //!     True when successful
    BOOL Insert(UINT position, UINT flags, HMENU subMenu, const uixChar* text);

    //! Inserts item
    //! @param[in] position
    //!     Position
    //! @param[in] flags
    //!     Flags
    //! @param[in] itemID
    //!     Item ID
    //! @param[in] bitmap
    //!     Bitmap handle
    //! @return
    //!     True when successful
    BOOL Insert(UINT position, UINT flags, UINT_PTR itemID, HBITMAP bitmap);

    //! Inserts item
    //! @param[in] position
    //!     Position
    //! @param[in] flags
    //!     Flags
    //! @param[in] subMenu
    //!     Sub menu handle
    //! @param[in] bitmap
    //!     Bitmap handle
    //! @return
    //!     True when successful
    BOOL Insert(UINT position, UINT flags, HMENU subMenu, HBITMAP bitmap);

    //! Modify item
    //! @param[in] position
    //!     Position
    //! @param[in] flags
    //!     Flags
    //! @param[in] itemID
    //!     Item ID
    //! @param[in] text
    //!     Text
    //! @return
    //!     True when successful
    BOOL Modify(UINT position, UINT flags, UINT_PTR itemID = 0, const uixChar* text = NULLPTR);

    //! Modify item
    //! @param[in] position
    //!     Position
    //! @param[in] flags
    //!     Flags
    //! @param[in] subMenu
    //!     Sub menu handle
    //! @param[in] text
    //!     Text
    //! @return
    //!     True when successful
    BOOL Modify(UINT position, UINT flags, HMENU subMenu, const uixChar* text);

    //! Modify item
    //! @param[in] position
    //!     Position
    //! @param[in] flags
    //!     Flags
    //! @param[in] itemID
    //!     Item ID
    //! @param[in] bitmap
    //!     Bitmap handle
    //! @return
    //!     True when successful
    BOOL Modify(UINT position, UINT flags, UINT_PTR itemID, HBITMAP bitmap);

    //! Modify item
    //! @param[in] position
    //!     Position
    //! @param[in] flags
    //!     Flags
    //! @param[in] subMenu
    //!     Sub menu handle
    //! @param[in] bitmap
    //!     Bitmap handle
    //! @return
    //!     True when successful
    BOOL Modify(UINT position, UINT flags, HMENU subMenu, HBITMAP bitmap);

    //! Remove item
    //! @param[in] position
    //!     Position
    //! @param[in] flags
    //!     Flags
    //! @return
    //!     True when successful
    BOOL Remove(UINT position, UINT flags);

    //! Sets item bitmaps
    //! @param[in] position
    //!     Position
    //! @param[in] flags
    //!     Flags
    //! @param[in] unchecked
    //!     Unchecked bitmap
    //! @param[in] checked
    //!     Checked bitmap
    //! @return
    //!     True when successful
    BOOL SetItemBitmaps(UINT position, UINT flags, HBITMAP unchecked, HBITMAP checked);

    //! Checks radio item
    //! @param[in] firstID
    //!     First ID
    //! @param[in] lastID
    //!     Last ID
    //! @param[in] itemID
    //!     Item ID
    //! @param[in] flags
    //!     flags
    //! @return
    //!     True when successful
    BOOL CheckRadioItem(UINT firstID, UINT lastID, UINT itemID, UINT flags);

    //! Gets item info
    //! @param[in] item
    //!     Item or position
    //! @param[in] byPosition
    //!     True - position,
    //!     False - ID
    //! @param[out] info
    //!     Item info
    //! @return
    //!     True when successful
    BOOL GetItemInfo(UINT item, BOOL byPosition, uixMenuItemInfo& info) const;

    //! Sets item info
    //! @param[in] item
    //!     Item or position
    //! @param[in] byPosition
    //!     True - position,
    //!     False - ID
    //! @param[in] info
    //!     Item info
    //! @return
    //!     True when successful
    BOOL SetItemInfo(UINT item, BOOL byPosition, uixMenuItemInfo& info);

    //! Inserts item
    //! @param[in] item
    //!     Item
    //! @param[in] byPosition
    //!     True - item = position
    //!     False - item = ID
    //! @param[in] info
    //!     Item info
    //! @return
    //!     True when successful
    BOOL InsertItem(UINT item, BOOL byPosition, uixMenuItemInfo& info);

    //! Gets default item
    //! @param[in] byPosition
    //!     False - by position
    //!     True - by ID
    //! @param[in] flags
    //!     Flags
    //! @return
    //!     Item ID or position
    UINT GetDefaultItem(BOOL byPosition = FALSE, UINT flags = 0) const;

    //! Sets default item
    //! @param[in] item
    //!     Item ID or position
    //! @param[in] byPosition
    //!     False - by position
    //!     True - by ID
    //! @return
    //!     True when successful
    BOOL SetDefaultItem(UINT item = (UINT) - 1, BOOL byPosition = FALSE);

    //! Gets item rect
    //! @param[in] window
    //!     Window handle
    //! @param[in] item
    //!     Item ID
    //! @param[out] rect
    //!     Item rect
    //! @return
    //!     True when successful
    BOOL GetItemRect(HWND window, UINT item, uixRect& rect) const;

    //! Gets item from point
    //! @param[in] window
    //!     Window handle
    //! @param[in] point
    //!     Point
    //! @return
    //!     Item ID
    INT ItemFromPoint(HWND window, const uixPoint& point) const;

    //! Sets context menu help ID
    //! @param[in] helpID
    //!     Help ID
    //! @return
    //!     True when successful
    BOOL SetContextHelpID(DWORD helpID);

    //! Gets menu context help ID
    //! @return
    //!     Context help ID
    DWORD GetContextHelpID() const;
};
}
//----------------------------------------------------------------------------//
#include "uixmenu.inl"
//----------------------------------------------------------------------------//
#endif /* _UIX_MENU_H__ */