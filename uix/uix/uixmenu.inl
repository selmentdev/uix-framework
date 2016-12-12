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
#ifndef _UIX_MENU_INL__
#define _UIX_MENU_INL__
//----------------------------------------------------------------------------//
#include "uixmenu.h"
#include "uixresource.h"
//----------------------------------------------------------------------------//
namespace UIX
{
//----------------------------------------------------------------------------//
// Menu Item Info
//----------------------------------------------------------------------------//
UIXINLINE uixMenuItemInfo::uixMenuItemInfo()
{
    this->cbSize = sizeof(uixMenuItemInfo);
    this->fMask = 0;
}
//----------------------------------------------------------------------------//
UIXINLINE DWORD uixMenuItemInfo::GetMask() const
{
    return fMask;
}
//----------------------------------------------------------------------------//
UIXINLINE void uixMenuItemInfo::SetMask(DWORD value)
{
    fMask = value;
}
//----------------------------------------------------------------------------//
UIXINLINE uixMenuItemType uixMenuItemInfo::GetType() const
{
    if (fMask & MIIM_FTYPE)
    {
        return fType;
    }

    return (uixMenuItemType)0;
}
//----------------------------------------------------------------------------//
UIXINLINE void uixMenuItemInfo::SetType(uixMenuItemType value)
{
    fMask |= MIIM_FTYPE;
    fType = value;
}
//----------------------------------------------------------------------------//
UIXINLINE uixMenuItemState uixMenuItemInfo::GetState() const
{
    if (fMask & MIIM_STATE)
    {
        return fState;
    }

    return 0;
}
//----------------------------------------------------------------------------//
UIXINLINE void uixMenuItemInfo::SetState(uixMenuItemState value)
{
    fMask |= MIIM_STATE;
    fState = value;
}
//----------------------------------------------------------------------------//
UIXINLINE UINT uixMenuItemInfo::GetID() const
{
    if (fMask & MIIM_ID)
    {
        return wID;
    }

    return 0;
}
//----------------------------------------------------------------------------//
UIXINLINE void uixMenuItemInfo::SetID(UINT value)
{
    fMask |= MIIM_ID;
    wID = value;
}
//----------------------------------------------------------------------------//
UIXINLINE HMENU uixMenuItemInfo::GetSubMenu() const
{
    if (fMask & MIIM_SUBMENU)
    {
        return hSubMenu;
    }

    return 0;
}
//----------------------------------------------------------------------------//
UIXINLINE void uixMenuItemInfo::SetSubMenu(HMENU value)
{
    fMask |= MIIM_SUBMENU;
    hSubMenu = value;
}
//----------------------------------------------------------------------------//
UIXINLINE HBITMAP uixMenuItemInfo::GetBitmapChecked() const
{
    if (fMask & MIIM_CHECKMARKS)
    {
        return hbmpChecked;
    }

    return 0;
}
//----------------------------------------------------------------------------//
UIXINLINE void uixMenuItemInfo::SetBitmapChecked(HBITMAP value)
{
    fMask |= MIIM_CHECKMARKS;
    hbmpChecked = value;
}
//----------------------------------------------------------------------------//
UIXINLINE HBITMAP uixMenuItemInfo::GetBitmapUnchecked() const
{
    if (fMask & MIIM_CHECKMARKS)
    {
        return hbmpUnchecked;
    }

    return 0;
}
//----------------------------------------------------------------------------//
UIXINLINE void uixMenuItemInfo::SetBitmapUnchecked(HBITMAP value)
{
    fMask |= MIIM_CHECKMARKS;
    hbmpUnchecked = value;
}
//----------------------------------------------------------------------------//
UIXINLINE void* uixMenuItemInfo::GetData() const
{
    if (fMask & MIIM_DATA)
    {
        return (void*)dwItemData;
    }

    return NULLPTR;
}
//----------------------------------------------------------------------------//
UIXINLINE void uixMenuItemInfo::SetData(const void* value)
{
    fMask |= MIIM_DATA;
    dwItemData = (ULONG_PTR)value;
}
//----------------------------------------------------------------------------//
UIXINLINE void* uixMenuItemInfo::GetTypeData() const
{
    if (fMask & MIIM_TYPE)
    {
        return (void*)dwTypeData;
    }

    return NULLPTR;
}
//----------------------------------------------------------------------------//
UIXINLINE void uixMenuItemInfo::SetTypeData(const void* value)
{
    fMask |= MIIM_TYPE;
    dwTypeData = (LPTSTR)value;
}
//----------------------------------------------------------------------------//
UIXINLINE UINT uixMenuItemInfo::GetTextLength() const
{
    if (fMask & MIIM_TYPE)
    {
        return cch;
    }

    return 0;
}
//----------------------------------------------------------------------------//
UIXINLINE void uixMenuItemInfo::SetTextLength(UINT value)
{
    cch = value;
}
//----------------------------------------------------------------------------//
UIXINLINE HBITMAP uixMenuItemInfo::GetBitmapItem() const
{
    if (fMask & MIIM_BITMAP)
    {
        return hbmpItem;
    }

    return 0;
}
//----------------------------------------------------------------------------//
UIXINLINE void uixMenuItemInfo::SetBitmapItem(HBITMAP value)
{
    fMask |= MIIM_BITMAP;
    hbmpItem = value;
}
//----------------------------------------------------------------------------//
// Menu Info
//----------------------------------------------------------------------------//
UIXINLINE uixMenuInfo::uixMenuInfo()
{
    this->cbSize = sizeof(uixMenuInfo);
    this->fMask = 0;
}
//----------------------------------------------------------------------------//
UIXINLINE DWORD uixMenuInfo::GetMask() const
{
    return fMask;
}
//----------------------------------------------------------------------------//
UIXINLINE void uixMenuInfo::SetMask(DWORD value)
{
    fMask = value;
}
//----------------------------------------------------------------------------//
UIXINLINE DWORD uixMenuInfo::GetStyle() const
{
    if (fMask & MIM_STYLE)
    {
        return dwStyle;
    }

    return 0;
}
//----------------------------------------------------------------------------//
UIXINLINE void uixMenuInfo::SetStyle(DWORD value)
{
    fMask |= MIM_STYLE;
    dwStyle = value;
}
//----------------------------------------------------------------------------//
UIXINLINE UINT uixMenuInfo::GetMaxHeight() const
{
    if (fMask & MIM_MAXHEIGHT)
    {
        return cyMax;
    }

    return 0;
}
//----------------------------------------------------------------------------//
UIXINLINE void uixMenuInfo::SetMaxHeight(UINT value)
{
    fMask |= MIM_MAXHEIGHT;
    cyMax = value;
}
//----------------------------------------------------------------------------//
UIXINLINE HBRUSH uixMenuInfo::GetBackgroundBrush() const
{
    if (fMask & MIM_BACKGROUND)
    {
        return hbrBack;
    }

    return 0;
}
//----------------------------------------------------------------------------//
UIXINLINE void uixMenuInfo::SetBackgroundBrush(HBRUSH value)
{
    fMask |= MIM_BACKGROUND;
    hbrBack = value;
}
//----------------------------------------------------------------------------//
UIXINLINE DWORD uixMenuInfo::GetContextHelpID() const
{
    if (fMask & MIM_HELPID)
    {
        return dwContextHelpID;
    }

    return 0;
}
//----------------------------------------------------------------------------//
UIXINLINE void uixMenuInfo::SetContextHelpID(DWORD value)
{
    fMask |= MIM_HELPID;
    dwContextHelpID = value;
}
//----------------------------------------------------------------------------//
UIXINLINE void* uixMenuInfo::GetData() const
{
    if (fMask & MIM_MENUDATA)
    {
        return (void*)dwMenuData;
    }

    return NULLPTR;
}
//----------------------------------------------------------------------------//
UIXINLINE void uixMenuInfo::SetData(const void* data)
{
    fMask |= MIM_MENUDATA;
    dwMenuData = (ULONG_PTR)data;
}
//----------------------------------------------------------------------------//
// Menu
//----------------------------------------------------------------------------//
UIXINLINE uixMenu::uixMenu(HMENU handle)
    : m_Handle(handle)
{
}
//----------------------------------------------------------------------------//
UIXINLINE uixMenu::~uixMenu()
{
    if (/*IsHandle && */(m_Handle != 0))
    {
        Destroy();
    }
}
//----------------------------------------------------------------------------//
UIXINLINE void uixMenu::Attach(HMENU handle)
{
    if (/*IsHandle && */(m_Handle != 0) && (m_Handle != handle))
    {
        ::DestroyMenu(m_Handle);
    }

    m_Handle = handle;
}
//----------------------------------------------------------------------------//
UIXINLINE HMENU uixMenu::Detach()
{
    HMENU handle = m_Handle;
    m_Handle = 0;
    return handle;
}
//----------------------------------------------------------------------------//
UIXINLINE uixMenu& uixMenu::operator = (HMENU handle)
{
    Attach(handle);
    return (*this);
}
//----------------------------------------------------------------------------//
UIXINLINE uixMenu::operator HMENU () const
{
    uixASSERT(this != NULLPTR);
    return m_Handle;
}
//----------------------------------------------------------------------------//
UIXINLINE HMENU uixMenu::GetHandle() const
{
    uixASSERT(this != NULLPTR);
    return m_Handle;
}
//----------------------------------------------------------------------------//
UIXINLINE HMENU uixMenu::GetHandleSafe() const
{
    if (this != NULLPTR)
    {
        return m_Handle;
    }

    return 0;
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixMenu::IsValid() const
{
    return m_Handle != 0;
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixMenu::Create()
{
    uixASSERT(m_Handle == 0);
    m_Handle = ::CreateMenu();
    return m_Handle != 0;
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixMenu::CreatePopup()
{
    uixASSERT(m_Handle == 0);
    m_Handle = ::CreatePopupMenu();
    return m_Handle != 0;
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixMenu::Load(uixResourceName resource)
{
    uixASSERT(m_Handle == 0);

    return Load(
               UixFindResourceHandle(resource, RT_MENU),
               resource);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixMenu::Load(uixResourceID resourceID)
{
    uixASSERT(m_Handle == 0);

    return Load(
               UixFindResourceHandle(resourceID, RT_MENU),
               resourceID);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixMenu::Load(HINSTANCE instance, uixResourceName resource)
{
    uixASSERT(m_Handle == 0);

    m_Handle = ::LoadMenu(instance, resource);
    return m_Handle != 0;
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixMenu::Load(HINSTANCE instance, uixResourceID resourceID)
{
    return Load(instance, MAKEINTRESOURCE(resourceID));
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixMenu::Destroy()
{
    if (m_Handle == 0)
    {
        return FALSE;
    }

    BOOL result = ::DestroyMenu(m_Handle);

    if (result)
    {
        m_Handle = 0;
    }

    return result;
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixMenu::Delete(UINT position, UINT flags)
{
    return ::DeleteMenu(m_Handle, position, flags);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixMenu::TrackPopup(UINT flags, int x, int y, HWND handle, RECT* rect)
{
    return ::TrackPopupMenu(m_Handle, flags, x, y, 0, handle, rect);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixMenu::TrackPopupEx(UINT flags, int x, int y, HWND handle, TPMPARAMS* params)
{
    return ::TrackPopupMenuEx(m_Handle, flags, x, y, handle, params);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixMenu::GetInfo(uixMenuInfo& info) const
{
    return ::GetMenuInfo(m_Handle, &info);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixMenu::SetInfo(const uixMenuInfo& info)
{
    return ::SetMenuInfo(m_Handle, &info);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixMenu::Append(UINT flags, UINT_PTR id, const uixChar* text)
{
    return ::AppendMenu(m_Handle, flags, id, text);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixMenu::Append(UINT flags, HMENU subMenu, const uixChar* text)
{
    return ::AppendMenu(m_Handle, flags | MF_POPUP, (UINT_PTR)subMenu, text);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixMenu::Append(UINT flags, UINT_PTR id, HBITMAP bitmap)
{
    return ::AppendMenu(m_Handle, flags | MF_BITMAP, id, (LPCTSTR)bitmap);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixMenu::Append(UINT flags, HMENU subMenu, HBITMAP bitmap)
{
    return ::AppendMenu(m_Handle, flags | MF_BITMAP | MF_POPUP, (UINT_PTR)subMenu, (LPCWSTR)bitmap);
}
//----------------------------------------------------------------------------//
UIXINLINE UINT uixMenu::CheckItem(UINT id, UINT check)
{
    return (UINT)::CheckMenuItem(m_Handle, id, check);
}
//----------------------------------------------------------------------------//
UIXINLINE UINT uixMenu::EnableItem(UINT id, UINT enable)
{
    return (UINT)::EnableMenuItem(m_Handle, id, enable);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixMenu::HighlightItem(HWND handle, UINT itemID, UINT highlight)
{
    return ::HiliteMenuItem(handle, m_Handle, itemID, highlight);
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixMenu::GetItemCount() const
{
    return ::GetMenuItemCount(m_Handle);
}
//----------------------------------------------------------------------------//
UIXINLINE UINT uixMenu::GetItemID(INT position) const
{
    return ::GetMenuItemID(m_Handle, position);
}
//----------------------------------------------------------------------------//
UIXINLINE UINT uixMenu::GetState(UINT itemID, UINT flags) const
{
    return ::GetMenuState(m_Handle, itemID, flags);
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixMenu::GetString(UINT itemID, uixChar* text, INT maxCount, UINT flags) const
{
    return ::GetMenuString(m_Handle, itemID, text, maxCount, flags);
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixMenu::GetStringLength(UINT itemID, UINT flags) const
{
    return ::GetMenuString(m_Handle, itemID, NULLPTR, 0, flags);
}
//----------------------------------------------------------------------------//
UIXINLINE uixMenu uixMenu::GetSubMenu(INT position) const
{
    return uixMenu(::GetSubMenu(m_Handle, position));
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixMenu::Insert(UINT position, UINT flags, UINT_PTR itemID, const uixChar* text)
{
    return ::InsertMenu(m_Handle, position, flags, itemID, text);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixMenu::Insert(UINT position, UINT flags, HMENU subMenu, const uixChar* text)
{
    return ::InsertMenu(m_Handle, position, flags | MF_POPUP, (UINT_PTR)subMenu, text);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixMenu::Insert(UINT position, UINT flags, UINT_PTR itemID, HBITMAP bitmap)
{
    return ::InsertMenu(m_Handle, position, flags | MF_BITMAP, itemID, (LPCTSTR)bitmap);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixMenu::Insert(UINT position, UINT flags, HMENU subMenu, HBITMAP bitmap)
{
    return ::InsertMenu(m_Handle, position, flags | MF_BITMAP | MF_POPUP, (UINT_PTR)subMenu,
                        (LPCTSTR)bitmap);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixMenu::Modify(UINT position, UINT flags, UINT_PTR itemID, const uixChar* text)
{
    return ::ModifyMenu(m_Handle, position, flags, itemID, text);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixMenu::Modify(UINT position, UINT flags, HMENU subMenu, const uixChar* text)
{
    return ::ModifyMenu(m_Handle, position, flags | MF_POPUP, (UINT_PTR)subMenu, text);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixMenu::Modify(UINT position, UINT flags, UINT_PTR itemID, HBITMAP bitmap)
{
    return ::ModifyMenu(m_Handle, position, flags | MF_BITMAP, itemID, (LPCTSTR)bitmap);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixMenu::Modify(UINT position, UINT flags, HMENU subMenu, HBITMAP bitmap)
{
    return ::ModifyMenu(m_Handle, position, flags | MF_BITMAP | MF_POPUP, (UINT_PTR)subMenu,
                        (LPCTSTR)bitmap);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixMenu::Remove(UINT position, UINT flags)
{
    return ::RemoveMenu(m_Handle, position, flags);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixMenu::SetItemBitmaps(UINT position, UINT flags, HBITMAP unchecked,
                                       HBITMAP checked)
{
    return ::SetMenuItemBitmaps(m_Handle, position, flags, unchecked, checked);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixMenu::CheckRadioItem(UINT firstID, UINT lastID, UINT itemID, UINT flags)
{
    return ::CheckMenuRadioItem(m_Handle, firstID, lastID, itemID, flags);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixMenu::GetItemInfo(UINT item, BOOL byPosition, uixMenuItemInfo& info) const
{
    return (BOOL)::GetMenuItemInfo(m_Handle, item, byPosition, &info);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixMenu::SetItemInfo(UINT item, BOOL byPosition, uixMenuItemInfo& info)
{
    return (BOOL)::SetMenuItemInfo(m_Handle, item, byPosition, &info);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixMenu::InsertItem(UINT item, BOOL byPosition, uixMenuItemInfo& info)
{
    return (BOOL)::InsertMenuItem(m_Handle, item, byPosition, &info);
}
//----------------------------------------------------------------------------//
UIXINLINE UINT uixMenu::GetDefaultItem(BOOL byPosition, UINT flags) const
{
    return ::GetMenuDefaultItem(m_Handle, (UINT)byPosition, flags);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixMenu::SetDefaultItem(UINT item, BOOL byPosition)
{
    return ::SetMenuDefaultItem(m_Handle, item, (UINT)byPosition);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixMenu::GetItemRect(HWND window, UINT item, uixRect& rect) const
{
    return ::GetMenuItemRect(window, m_Handle, item, &rect);
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixMenu::ItemFromPoint(HWND window, const uixPoint& point) const
{
    return ::MenuItemFromPoint(window, m_Handle, point);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixMenu::SetContextHelpID(DWORD helpID)
{
    return ::SetMenuContextHelpId(m_Handle, helpID);
}
//----------------------------------------------------------------------------//
UIXINLINE DWORD uixMenu::GetContextHelpID() const
{
    return ::GetMenuContextHelpId(m_Handle);
}
//----------------------------------------------------------------------------//
}
//----------------------------------------------------------------------------//
#endif /* _UIX_MENU_INL__ */