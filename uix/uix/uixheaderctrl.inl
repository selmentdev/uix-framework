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
#ifndef _UIX_HEADERCTRL_INL__
#define _UIX_HEADERCTRL_INL__
//----------------------------------------------------------------------------//
#include "uixwindow.h"
//----------------------------------------------------------------------------//
namespace UIX
{
//----------------------------------------------------------------------------//
// uixHeaderItem
//----------------------------------------------------------------------------//
UIXINLINE uixHeaderItem::uixHeaderItem()
{
    mask = 0;
}
//----------------------------------------------------------------------------//
UIXINLINE DWORD uixHeaderItem::GetMask() const
{
    return mask;
}
//----------------------------------------------------------------------------//
UIXINLINE void uixHeaderItem::SetMask(DWORD value)
{
    mask = value;
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixHeaderItem::GetWidth() const
{
    if (mask & HDI_WIDTH)
    {
        return cxy;
    }

    return 0;
}
//----------------------------------------------------------------------------//
UIXINLINE void uixHeaderItem::SetWidth(INT value)
{
    mask |= HDI_WIDTH;
    cxy = value;
}
//----------------------------------------------------------------------------//
UIXINLINE const uixChar* uixHeaderItem::GetText() const
{
    if (mask & HDI_TEXT)
    {
        return pszText;
    }

    return NULLPTR;
}
//----------------------------------------------------------------------------//
UIXINLINE void uixHeaderItem::SetText(const uixChar* value)
{
    mask |= HDI_TEXT;
    pszText = (LPTSTR)value;
    cchTextMax = lstrlen(value);
}
//----------------------------------------------------------------------------//
UIXINLINE void uixHeaderItem::SetText(const uixChar* value, INT length)
{
    mask |= HDI_TEXT;
    pszText = (LPTSTR)value;
    cchTextMax = length;
}
//----------------------------------------------------------------------------//
UIXINLINE void uixHeaderItem::SetTextLength(INT length)
{
    cchTextMax = length;
}
//----------------------------------------------------------------------------//
UIXINLINE HBITMAP uixHeaderItem::GetBitmap() const
{
    if (mask & HDI_BITMAP)
    {
        return hbm;
    }

    return 0;
}
//----------------------------------------------------------------------------//
UIXINLINE void uixHeaderItem::SetBitmap(HBITMAP value)
{
    mask |= HDI_BITMAP;
    hbm = value;
}
//----------------------------------------------------------------------------//
UIXINLINE uixHeaderItemFormat uixHeaderItem::GetFormat() const
{
    if (mask & HDI_FORMAT)
    {
        return (uixHeaderItemFormat)fmt;
    }

    return uixHeaderItemFormat_None;
}
//----------------------------------------------------------------------------//
UIXINLINE void uixHeaderItem::SetFormat(uixHeaderItemFormat value)
{
    mask |= HDI_FORMAT;
    fmt = value;
}
//----------------------------------------------------------------------------//
UIXINLINE void* uixHeaderItem::GetData() const
{
    if (mask & HDI_LPARAM)
    {
        return (void*)lParam;
    }

    return NULLPTR;
}
//----------------------------------------------------------------------------//
UIXINLINE void uixHeaderItem::SetData(const void* value)
{
    mask |= HDI_LPARAM;
    lParam = (LPARAM)value;
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixHeaderItem::GetImage() const
{
    if (mask & HDI_IMAGE)
    {
        return iImage;
    }

    return 0;
}
//----------------------------------------------------------------------------//
UIXINLINE void uixHeaderItem::SetImage(INT value)
{
    mask |= HDI_IMAGE;
    iImage = value;
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixHeaderItem::GetOrder() const
{
    if (mask & HDI_ORDER)
    {
        return iOrder;
    }

    return 0;
}
//----------------------------------------------------------------------------//
UIXINLINE void uixHeaderItem::SetOrder(INT value)
{
    mask |= HDI_ORDER;
    iOrder = value;
}
//----------------------------------------------------------------------------//
UIXINLINE uixHeaderItemType uixHeaderItem::GetType() const
{
    if (mask & HDI_FILTER)
    {
        return (uixHeaderItemType)type;
    }

    return uixHeaderItemType_None;
}
//----------------------------------------------------------------------------//
UIXINLINE void uixHeaderItem::SetType(uixHeaderItemType value)
{
    mask |= HDI_FILTER;
    type = value;
}
//----------------------------------------------------------------------------//
UIXINLINE void* uixHeaderItem::GetFilter() const
{
    if (mask & HDI_FILTER)
    {
        return pvFilter;
    }

    return NULLPTR;
}
//----------------------------------------------------------------------------//
UIXINLINE void uixHeaderItem::SetFilter(const void* value)
{
    mask |= HDI_FILTER;
    pvFilter = (void*)value;
}
//----------------------------------------------------------------------------//
UIXINLINE UINT uixHeaderItem::GetState() const
{
    if (mask & HDI_STATE)
    {
        return state;
    }

    return 0;
}
//----------------------------------------------------------------------------//
UIXINLINE void uixHeaderItem::SetState(UINT value)
{
    mask |= HDI_STATE;
    state = value;
}
//----------------------------------------------------------------------------//
// uixHeaderCtrl
//----------------------------------------------------------------------------//
UIXINLINE INT uixHeaderCtrl::GetItemCount() const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (INT)Header_GetItemCount(m_Handle);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixHeaderCtrl::GetItem(INT itemID, HDITEM& item) const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (BOOL)Header_GetItem(m_Handle, itemID, &item);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixHeaderCtrl::SetItem(INT itemID, const HDITEM& item)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (BOOL)Header_SetItem(m_Handle, itemID, &item);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixHeaderCtrl::GetItemText(INT itemID, uixChar* text, INT textLength) const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    HDITEM item;
    item.mask = HDI_TEXT;
    item.pszText = text;
    item.cchTextMax = textLength;

    return GetItem(itemID, item);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixHeaderCtrl::GetItemFull(INT itemID, HDITEM& item, uixChar* text,
        INT textLength) const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    item.mask = HDI_TEXT | HDI_WIDTH | HDI_HEIGHT | HDI_FORMAT | HDI_LPARAM | HDI_BITMAP | HDI_IMAGE |
                HDI_ORDER;
    item.pszText = text;
    item.cchTextMax = textLength;

    return GetItem(itemID, item);
}
//----------------------------------------------------------------------------//
UIXINLINE HIMAGELIST uixHeaderCtrl::GetImageList() const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    return (HIMAGELIST)Header_GetImageList(m_Handle);
}
//----------------------------------------------------------------------------//
UIXINLINE HIMAGELIST uixHeaderCtrl::SetImageList(HIMAGELIST handle)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    return (HIMAGELIST)Header_SetImageList(m_Handle, handle);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixHeaderCtrl::GetOrderArray(INT indices[], INT count) const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (BOOL)Header_GetOrderArray(m_Handle, count, indices);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixHeaderCtrl::SetOrderArray(INT indices[], INT count)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (BOOL)Header_SetOrderArray(m_Handle, count, indices);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixHeaderCtrl::GetItemRect(INT itemID, RECT& rect) const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (BOOL)Header_GetItemRect(m_Handle, itemID, &rect);
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixHeaderCtrl::SetHotDivider(BOOL position, DWORD inputValue)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (INT)Header_SetHotDivider(m_Handle, position, inputValue);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixHeaderCtrl::GetUnicodeFormat() const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (BOOL)Header_GetUnicodeFormat(m_Handle);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixHeaderCtrl::SetUnicodeFormat(BOOL unicode)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (BOOL)Header_SetUnicodeFormat(m_Handle, unicode);
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixHeaderCtrl::InsertItem(INT itemID, HDITEM& item)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (INT)Header_InsertItem(m_Handle, itemID, &item);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixHeaderCtrl::DeleteItem(INT itemID)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (BOOL)Header_DeleteItem(m_Handle, itemID);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixHeaderCtrl::Layout(HD_LAYOUT& layout)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (BOOL)Header_Layout(m_Handle, &layout);
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixHeaderCtrl::HitTest(HDHITTESTINFO& hti)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (INT)SendMessage(HDM_HITTEST, 0, (LPARAM)&hti);
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixHeaderCtrl::OrderToIndex(INT order)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (INT)Header_OrderToIndex(m_Handle, order);
}
//----------------------------------------------------------------------------//
UIXINLINE HIMAGELIST uixHeaderCtrl::CreateDragImage(INT itemID)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (HIMAGELIST)Header_CreateDragImage(m_Handle, itemID);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixHeaderCtrl::ClearAllFilters()
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (BOOL)Header_ClearAllFilters (m_Handle);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixHeaderCtrl::ClearFilter(INT itemID)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (BOOL)Header_ClearFilter(m_Handle, itemID);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixHeaderCtrl::EditFilter(INT itemID, BOOL discard)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (BOOL)Header_EditFilter(m_Handle, itemID, discard);
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixHeaderCtrl::GetBitmapMargin() const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (INT)Header_GetBitmapMargin(m_Handle);
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixHeaderCtrl::GetFocusedItem() const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (INT)Header_GetFocusedItem(m_Handle);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixHeaderCtrl::GetItemDropDownRect(INT itemID, RECT& rect) const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (BOOL)Header_GetItemDropDownRect(m_Handle, itemID, &rect);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixHeaderCtrl::GetOverflowRect(RECT& rect) const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (BOOL)Header_GetOverflowRect(m_Handle, &rect);
}
//----------------------------------------------------------------------------//
UIXINLINE HIMAGELIST uixHeaderCtrl::GetStateImageList() const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (HIMAGELIST)Header_GetStateImageList(m_Handle);
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixHeaderCtrl::SetBitmapMargin(INT width)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (INT)Header_SetBitmapMargin(m_Handle, width);
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixHeaderCtrl::SetFilterChangeTimeout(INT timeout)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (INT)Header_SetFilterChangeTimeout(m_Handle, timeout);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixHeaderCtrl::SetFocusedItem(INT itemID)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (BOOL)Header_SetFocusedItem(m_Handle, itemID);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixHeaderCtrl::SetStateImageList(HIMAGELIST imageList)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (BOOL)Header_SetStateImageList(m_Handle, imageList);
}
//----------------------------------------------------------------------------//
}
//----------------------------------------------------------------------------//
#endif /* _UIX_HEADERCTRL_INL__ */