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
#ifndef _UIX_LISTVIEWCTRL_INL__
#define _UIX_LISTVIEWCTRL_INL__
//----------------------------------------------------------------------------//
#include "uixlistviewctrl.h"
//----------------------------------------------------------------------------//
namespace UIX
{
//----------------------------------------------------------------------------//
// uixListViewItem
//----------------------------------------------------------------------------//
UIXINLINE uixListViewItem::uixListViewItem()
{
    ZeroMemory(this, sizeof(uixListViewItem));
}
//----------------------------------------------------------------------------//
UIXINLINE DWORD uixListViewItem::GetMask() const
{
    return mask;
}
//----------------------------------------------------------------------------//
UIXINLINE void uixListViewItem::SetMask(DWORD value)
{
    mask = value;
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixListViewItem::GetItem() const
{
    return iItem;
}
//----------------------------------------------------------------------------//
UIXINLINE void uixListViewItem::SetItem(INT value)
{
    iItem = value;
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixListViewItem::GetSubItem() const
{
    return iSubItem;
}
//----------------------------------------------------------------------------//
UIXINLINE void uixListViewItem::SetSubItem(INT value)
{
    iSubItem = value;
}
//----------------------------------------------------------------------------//
UIXINLINE UINT uixListViewItem::GetState() const
{
    if (mask & LVIF_STATE)
    {
        return state;
    }

    return 0;
}
//----------------------------------------------------------------------------//
UIXINLINE void uixListViewItem::SetState(UINT value)
{
    mask |= LVIF_STATE;
    state = value;
}
//----------------------------------------------------------------------------//
UIXINLINE UINT uixListViewItem::GetStateMask() const
{
    return stateMask;
}
//----------------------------------------------------------------------------//
UIXINLINE void uixListViewItem::SetStateMask(UINT value)
{
    mask |= LVIF_STATE;
    stateMask = value;
}
//----------------------------------------------------------------------------//
UIXINLINE const uixChar* uixListViewItem::GetText() const
{
    if (mask & LVIF_TEXT)
    {
        return (const uixChar*)pszText;
    }

    return NULLPTR;
}
//----------------------------------------------------------------------------//
UIXINLINE void uixListViewItem::SetText(const uixChar* text)
{
    mask |= LVIF_TEXT;
    pszText = (LPTSTR)text;
    cchTextMax = lstrlen(text);
}
//----------------------------------------------------------------------------//
UIXINLINE void uixListViewItem::SetText(const uixChar* text, INT length)
{
    mask |= LVIF_TEXT;
    pszText = (LPTSTR)text;
    cchTextMax = length;
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixListViewItem::GetTextLength() const
{
    if (mask & LVIF_TEXT)
    {
        return cchTextMax;
    }

    return 0;
}
//----------------------------------------------------------------------------//
UIXINLINE void uixListViewItem::SetTextLength(INT length)
{
    cchTextMax = length;
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixListViewItem::GetImage() const
{
    if (mask & LVIF_IMAGE)
    {
        return iImage;
    }

    return 0;
}
//----------------------------------------------------------------------------//
UIXINLINE void uixListViewItem::SetImage(INT value)
{
    mask |= LVIF_IMAGE;
    iImage = value;
}
//----------------------------------------------------------------------------//
UIXINLINE const void* uixListViewItem::GetData() const
{
    if (mask & LVIF_PARAM)
    {
        return (const void*)lParam;
    }

    return NULLPTR;
}
//----------------------------------------------------------------------------//
UIXINLINE void uixListViewItem::SetData(const void* value)
{
    mask |= LVIF_PARAM;
    lParam = (LPARAM)value;
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixListViewItem::GetIndent() const
{
    if (mask & LVIF_INDENT)
    {
        return iIndent;
    }

    return 0;
}
//----------------------------------------------------------------------------//
UIXINLINE void uixListViewItem::SetIndent(INT value)
{
    mask |= LVIF_INDENT;
    iIndent = value;
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixListViewItem::GetGroupID() const
{
    if (mask & LVIF_GROUPID)
    {
        return iGroupId;
    }

    return I_GROUPIDNONE;
}
//----------------------------------------------------------------------------//
UIXINLINE void uixListViewItem::SetGroupID(INT value)
{
    mask |= LVIF_GROUPID;
    iGroupId = value;
}
//----------------------------------------------------------------------------//
// uixListViewColumn
//----------------------------------------------------------------------------//
UIXINLINE uixListViewColumn::uixListViewColumn()
{
    ZeroMemory(this, sizeof(uixListViewColumn));
}
//----------------------------------------------------------------------------//
UIXINLINE DWORD uixListViewColumn::GetMask() const
{
    return mask;
}
//----------------------------------------------------------------------------//
UIXINLINE void uixListViewColumn::SetMask(DWORD value)
{
    mask = value;
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixListViewColumn::GetFormat() const
{
    if (mask & LVCF_FMT)
    {
        return fmt;
    }

    return 0;
}
//----------------------------------------------------------------------------//
UIXINLINE void uixListViewColumn::SetFormat(INT value)
{
    mask |= LVCF_FMT;
    fmt = value;
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixListViewColumn::GetWidth() const
{
    if (mask & LVCF_WIDTH)
    {
        return cx;
    }

    return 0;
}
//----------------------------------------------------------------------------//
UIXINLINE const uixChar* uixListViewColumn::GetText() const
{
    if (mask & LVCF_TEXT)
    {
        return (const uixChar*)pszText;
    }

    return NULLPTR;
}
//----------------------------------------------------------------------------//
UIXINLINE void uixListViewColumn::SetText(const uixChar* text)
{
    mask |= LVCF_TEXT;
    pszText = (LPTSTR)text;
    cchTextMax = lstrlen(text);
}
//----------------------------------------------------------------------------//
UIXINLINE void uixListViewColumn::SetText(const uixChar* text, INT length)
{
    mask |= LVCF_TEXT;
    pszText = (LPTSTR)text;
    cchTextMax = length;
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixListViewColumn::GetTextLength() const
{
    if (mask & LVCF_TEXT)
    {
        return cchTextMax;
    }

    return 0;
}
//----------------------------------------------------------------------------//
UIXINLINE void uixListViewColumn::SetTextLenght(INT length)
{
    cchTextMax = length;
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixListViewColumn::GetSubItem() const
{
    if (mask & LVCF_SUBITEM)
    {
        return iSubItem;
    }

    return 0;
}
//----------------------------------------------------------------------------//
UIXINLINE void uixListViewColumn::SetSubItem(INT value)
{
    mask |= LVCF_SUBITEM;
    iSubItem = value;
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixListViewColumn::GetImage() const
{
    if (mask & LVCF_IMAGE)
    {
        return iImage;
    }

    return 0;
}
//----------------------------------------------------------------------------//
UIXINLINE void uixListViewColumn::SetImage(INT value)
{
    mask |= LVCF_IMAGE;
    iImage = value;
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixListViewColumn::GetOrder() const
{
    if (mask & LVCF_ORDER)
    {
        return iOrder;
    }

    return 0;
}
//----------------------------------------------------------------------------//
UIXINLINE void uixListViewColumn::SetOrder(INT value)
{
    mask |= LVCF_ORDER;
    iOrder = value;
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixListViewColumn::GetMinWidth() const
{
    if (mask & LVCF_MINWIDTH)
    {
        return cxMin;
    }

    return 0;
}
//----------------------------------------------------------------------------//
UIXINLINE void uixListViewColumn::SetMinWidth(INT value)
{
    mask |= LVCF_WIDTH;
    cxMin = value;
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixListViewColumn::GetDefaultWidth() const
{
    if (mask & LVCF_DEFAULTWIDTH)
    {
        return cxDefault;
    }

    return 0;
}
//----------------------------------------------------------------------------//
UIXINLINE void uixListViewColumn::SetDefaultWidth(INT value)
{
    mask |= LVCF_DEFAULTWIDTH;
    cxDefault = value;
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixListViewColumn::GetIdealWidth() const
{
    if (mask & LVCF_IDEALWIDTH)
    {
        return cxIdeal;
    }

    return 0;
}
//----------------------------------------------------------------------------//
UIXINLINE void uixListViewColumn::SetIdealWidth(INT value)
{
    mask |= LVCF_IDEALWIDTH;
    cxIdeal = value;
}
//----------------------------------------------------------------------------//
// uixListViewBackgroundImage
//----------------------------------------------------------------------------//
UIXINLINE uixListViewBackgroundImage::uixListViewBackgroundImage()
{
    ZeroMemory(this, sizeof(uixListViewBackgroundImage));
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixListViewBackgroundImage::GetXOffset() const
{
    if (ulFlags & LVBKIF_FLAG_TILEOFFSET)
    {
        return xOffsetPercent;
    }

    return 0;
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixListViewBackgroundImage::GetYOffset() const
{
    if (ulFlags & LVBKIF_FLAG_TILEOFFSET)
    {
        return yOffsetPercent;
    }

    return 0;
}
//----------------------------------------------------------------------------//
UIXINLINE void uixListViewBackgroundImage::SetOffset(INT x, INT y)
{
    ulFlags |= LVBKIF_FLAG_TILEOFFSET;
    xOffsetPercent = x;
    yOffsetPercent = y;
}
//----------------------------------------------------------------------------//
UIXINLINE void uixListViewBackgroundImage::FromHandle(HBITMAP handle)
{
    ulFlags &= ~LVBKIF_SOURCE_MASK;
    ulFlags |= LVBKIF_SOURCE_HBITMAP;
    hbm = handle;
}
//----------------------------------------------------------------------------//
UIXINLINE void uixListViewBackgroundImage::FromUrl(const uixChar* url)
{
    ulFlags &= ~LVBKIF_SOURCE_MASK;
    ulFlags |= LVBKIF_SOURCE_URL;
    pszImage = (LPTSTR)url;
}
//----------------------------------------------------------------------------//
UIXINLINE void uixListViewBackgroundImage::FromEmpty()
{
    ulFlags &= ~LVBKIF_SOURCE_MASK;
    ulFlags |= LVBKIF_SOURCE_NONE;
}
//----------------------------------------------------------------------------//
UIXINLINE void uixListViewBackgroundImage::SetStyle(BOOL tile)
{
    ulFlags &= ~LVBKIF_STYLE_MASK;

    if (tile)
    {
        ulFlags |= LVBKIF_STYLE_TILE;
    }
    else
    {
        ulFlags |= LVBKIF_STYLE_NORMAL;
    }
}
//----------------------------------------------------------------------------//
UIXINLINE void uixListViewBackgroundImage::SetWatermark(BOOL value)
{
    if (value)
    {
        ulFlags |= LVBKIF_TYPE_WATERMARK;
    }
    else
    {
        ulFlags &= ~LVBKIF_TYPE_WATERMARK;
    }
}
//----------------------------------------------------------------------------//
UIXINLINE void uixListViewBackgroundImage::SetAlphaBlend(BOOL value)
{
    if (ulFlags & LVBKIF_TYPE_WATERMARK)
    {
        if (value)
        {
            ulFlags |= LVBKIF_FLAG_ALPHABLEND;
        }
        else
        {
            ulFlags &= ~LVBKIF_FLAG_ALPHABLEND;
        }
    }
}
//----------------------------------------------------------------------------//
// uixListViewCtrl
UIXINLINE DWORD uixListViewCtrl::ApproximateViewRect(INT width, INT height, INT itemCount)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return ListView_ApproximateViewRect(m_Handle, width, height, itemCount);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixListViewCtrl::Arrange(UINT code)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return ListView_Arrange(m_Handle, code);
}
//----------------------------------------------------------------------------//
UIXINLINE void uixListViewCtrl::CancelEditLabel()
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    ListView_CancelEditLabel(m_Handle);
}
//----------------------------------------------------------------------------//
UIXINLINE HIMAGELIST uixListViewCtrl::CreateDragImage(INT itemID, POINT* upperLeft) const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return ListView_CreateDragImage(m_Handle, itemID, upperLeft);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixListViewCtrl::DeleteAllItems()
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return ListView_DeleteAllItems(m_Handle);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixListViewCtrl::DeleteColumn(INT columnID)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return ListView_DeleteColumn(m_Handle, columnID);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixListViewCtrl::DeleteItem(INT itemID)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return ListView_DeleteItem(m_Handle, itemID);
}
//----------------------------------------------------------------------------//
UIXINLINE HWND uixListViewCtrl::EditLabel(INT itemID)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return ListView_EditLabel(m_Handle, itemID);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixListViewCtrl::EnableGroupView(BOOL enable)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return ListView_EnableGroupView(m_Handle, enable) != -1;
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixListViewCtrl::EnsureVisible(INT itemID, BOOL partial)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return ListView_EnsureVisible(m_Handle, itemID, partial);
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixListViewCtrl::FindItem(INT startID, const LVFINDINFO& findInfo) const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return ListView_FindItem(m_Handle, startID, &findInfo);
}
//----------------------------------------------------------------------------//
UIXINLINE uixColor uixListViewCtrl::GetBackgroundColor() const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return ListView_GetBkColor(m_Handle);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixListViewCtrl::GetBackgroundImage(LVBKIMAGE& image) const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return ListView_GetBkImage(m_Handle, &image);
}
//----------------------------------------------------------------------------//
UIXINLINE UINT uixListViewCtrl::GetCallbackMask() const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return ListView_GetCallbackMask(m_Handle);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixListViewCtrl::GetCheckState(UINT itemID) const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return ListView_GetCheckState(m_Handle, itemID);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixListViewCtrl::GetColumn(INT columnID, LVCOLUMN& column) const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return ListView_GetColumn(m_Handle, columnID, &column);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixListViewCtrl::GetColumnOrderArray(INT columns[], INT count) const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return ListView_GetColumnOrderArray(m_Handle, count, columns);
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixListViewCtrl::GetColumnWidth(INT columnID) const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return ListView_GetColumnWidth(m_Handle, columnID);
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixListViewCtrl::GetCountPerPage() const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return ListView_GetCountPerPage(m_Handle);
}
//----------------------------------------------------------------------------//
UIXINLINE HWND uixListViewCtrl::GetEditControl() const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return ListView_GetEditControl(m_Handle);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixListViewCtrl::GetEmptyText(WCHAR* text, UINT length) const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return ListView_GetEmptyText(m_Handle, text, length);
}
//----------------------------------------------------------------------------//
UIXINLINE DWORD uixListViewCtrl::GetControlStyle() const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return ListView_GetExtendedListViewStyle(m_Handle);
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixListViewCtrl::GetFocusedGroup() const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (INT)ListView_GetFocusedGroup(m_Handle);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixListViewCtrl::GetFooterInfo(LVFOOTERINFO& footer) const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return ListView_GetFooterInfo(m_Handle, &footer);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixListViewCtrl::GetFooterItem(UINT footerID, LVFOOTERITEM& item) const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return ListView_GetFooterItem(m_Handle, footerID, &item);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixListViewCtrl::GetFooterItemRect(UINT footerID, RECT& rect) const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return ListView_GetFooterItemRect(m_Handle, footerID, &rect);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixListViewCtrl::GetFooterRect(RECT& rect) const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return ListView_GetFooterRect(m_Handle, &rect);
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixListViewCtrl::GetGroupCount() const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (INT)ListView_GetGroupCount(m_Handle);
}
//----------------------------------------------------------------------------//
UIXINLINE HIMAGELIST uixListViewCtrl::GetGroupHeaderImageList() const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return ListView_GetGroupHeaderImageList(m_Handle);
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixListViewCtrl::GetGroupInfo(INT groupID, LVGROUP& group) const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (INT)ListView_GetGroupInfo(m_Handle, groupID, &group);
}
//----------------------------------------------------------------------------//
UIXINLINE LRESULT uixListViewCtrl::GetGroupInfoByIndex(INT index, LVGROUP& group)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return ListView_GetGroupInfoByIndex(m_Handle, index, &group);
}
//----------------------------------------------------------------------------//
UIXINLINE void uixListViewCtrl::GetGroupMetrics(LVGROUPMETRICS& metrics) const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    ListView_GetGroupMetrics(m_Handle, &metrics);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixListViewCtrl::GetGroupRect(UINT groupID, LONG type, RECT& rect) const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (BOOL)ListView_GetGroupRect(m_Handle, groupID, type, &rect);
}
//----------------------------------------------------------------------------//
UIXINLINE UINT uixListViewCtrl::GetGroupState(UINT groupID, UINT mask) const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return ListView_GetGroupState(m_Handle, groupID, mask);
}
//----------------------------------------------------------------------------//
UIXINLINE HWND uixListViewCtrl::GetHeader() const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return ListView_GetHeader(m_Handle);
}
//----------------------------------------------------------------------------//
UIXINLINE HCURSOR uixListViewCtrl::GetHotCursor() const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return ListView_GetHotCursor(m_Handle);
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixListViewCtrl::GetHotItem() const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return ListView_GetHotItem(m_Handle);
}
//----------------------------------------------------------------------------//
UIXINLINE DWORD uixListViewCtrl::GetHoverTime() const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return ListView_GetHoverTime(m_Handle);
}
//----------------------------------------------------------------------------//
UIXINLINE HIMAGELIST uixListViewCtrl::GetImageList(uixListViewImageList type) const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return ListView_GetImageList(m_Handle, type);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixListViewCtrl::GetInsertMark(LVINSERTMARK& mark) const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return ListView_GetInsertMark(m_Handle, &mark);
}
//----------------------------------------------------------------------------//
UIXINLINE uixColor uixListViewCtrl::GetInsertMarkColor() const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return ListView_GetInsertMarkColor(m_Handle);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixListViewCtrl::GetInsertMarkRect(RECT& rect) const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return ListView_GetInsertMarkRect(m_Handle, &rect) != 0;
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixListViewCtrl::GetISearchString(uixChar* text) const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return ListView_GetISearchString(m_Handle, text) != 0;
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixListViewCtrl::GetISearchStringLength() const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return ListView_GetISearchString(m_Handle, NULLPTR);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixListViewCtrl::GetItem(LVITEM& item) const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return ListView_GetItem(m_Handle, &item);
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixListViewCtrl::GetItemCount() const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return ListView_GetItemCount(m_Handle);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixListViewCtrl::GetItemIndexRect(LVITEMINDEX& index, LONG subItem, LONG code,
        RECT& rect) const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return ListView_GetItemIndexRect(m_Handle, &index, subItem, code, &rect);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixListViewCtrl::GetItemPosition(INT itemID, POINT& position) const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return ListView_GetItemPosition(m_Handle, itemID, &position);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixListViewCtrl::GetItemRect(INT itemID, INT code, RECT& rect) const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return ListView_GetItemRect(m_Handle, itemID, &rect, code);
}
//----------------------------------------------------------------------------//
UIXINLINE DWORD uixListViewCtrl::GetItemSpacing(BOOL isSmall) const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return ListView_GetItemSpacing(m_Handle, isSmall);
}
//----------------------------------------------------------------------------//
UIXINLINE UINT uixListViewCtrl::GetItemState(INT itemID, UINT mask) const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return ListView_GetItemState(m_Handle, itemID, mask);
}
//----------------------------------------------------------------------------//
UIXINLINE void uixListViewCtrl::GetItemText(INT itemID, INT subItemID, uixChar* text,
        INT length) const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    ListView_GetItemText(m_Handle, itemID, subItemID, text, length);
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixListViewCtrl::GetNextItem(INT startID, UINT flags) const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return ListView_GetNextItem(m_Handle, startID, flags);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixListViewCtrl::GetNextItemIndex(LVITEMINDEX& index, LPARAM flags) const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return ListView_GetNextItemIndex(m_Handle, &index, flags);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixListViewCtrl::GetNumberOfWorkAreas(UINT& workAreas) const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return ListView_GetNumberOfWorkAreas(m_Handle, &workAreas);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixListViewCtrl::GetOrigin(POINT& point) const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return ListView_GetOrigin(m_Handle, &point);
}
//----------------------------------------------------------------------------//
UIXINLINE uixColor uixListViewCtrl::GetOutlineColor() const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return ListView_GetOutlineColor(m_Handle);
}
//----------------------------------------------------------------------------//
UIXINLINE UINT uixListViewCtrl::GetSelectedColumn() const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return ListView_GetSelectedColumn(m_Handle);
}
//----------------------------------------------------------------------------//
UIXINLINE UINT uixListViewCtrl::GetSelectedCount() const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return ListView_GetSelectedCount(m_Handle);
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixListViewCtrl::GetSelectionMark() const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return ListView_GetSelectionMark(m_Handle);
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixListViewCtrl::GetStringWidth(const uixChar* text) const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return ListView_GetStringWidth(m_Handle, text);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixListViewCtrl::GetSubItemRect(INT itemID, INT subItemID, INT code,
        RECT& rect) const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return ListView_GetSubItemRect(m_Handle, itemID, subItemID, code, &rect);
}
//----------------------------------------------------------------------------//
UIXINLINE uixColor uixListViewCtrl::GetTextBackgroundColor() const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return ListView_GetTextBkColor(m_Handle);
}
//----------------------------------------------------------------------------//
UIXINLINE uixColor uixListViewCtrl::GetTextColor() const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return ListView_GetTextColor(m_Handle);
}
//----------------------------------------------------------------------------//
UIXINLINE void uixListViewCtrl::GetTileInfo(LVTILEINFO& info) const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    ListView_GetTileInfo(m_Handle, &info);
}
//----------------------------------------------------------------------------//
UIXINLINE void uixListViewCtrl::GetTileViewInfo(LVTILEVIEWINFO& info) const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    ListView_GetTileViewInfo(m_Handle, &info);
}
//----------------------------------------------------------------------------//
UIXINLINE HWND uixListViewCtrl::GetToolTips() const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return ListView_GetToolTips(m_Handle);
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixListViewCtrl::GetTopIndex() const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return ListView_GetTopIndex(m_Handle);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixListViewCtrl::GetUnicodeFormat() const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return ListView_GetUnicodeFormat(m_Handle);
}
//----------------------------------------------------------------------------//
UIXINLINE uixListViewViewMode uixListViewCtrl::GetViewMode() const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (uixListViewViewMode)ListView_GetView(m_Handle);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixListViewCtrl::GetViewRect(RECT& rect) const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return ListView_GetViewRect(m_Handle, &rect);
}
//----------------------------------------------------------------------------//
UIXINLINE void uixListViewCtrl::GetWorkAreas(RECT areas[], INT count) const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    ListView_GetWorkAreas(m_Handle, count, areas);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixListViewCtrl::HasGroup(INT groupID) const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (BOOL)ListView_HasGroup(m_Handle, groupID);
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixListViewCtrl::HitTest(LVHITTESTINFO& info) const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return ListView_HitTest(m_Handle, &info);
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixListViewCtrl::HitTestEx(LVHITTESTINFO& info) const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return ListView_HitTestEx(m_Handle, &info);
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixListViewCtrl::InsertColumn(INT columnID, const LVCOLUMN& column)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return ListView_InsertColumn(m_Handle, columnID, &column);
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixListViewCtrl::InsertGroup(INT groupID, LVGROUP& group)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (INT)ListView_InsertGroup(m_Handle, groupID, &group);
}
//----------------------------------------------------------------------------//
UIXINLINE void uixListViewCtrl::InsertGroupSorted(LVINSERTGROUPSORTED& insert)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    ListView_InsertGroupSorted(m_Handle, &insert);
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixListViewCtrl::InsertItem(const LVITEM& item)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return ListView_InsertItem(m_Handle, &item);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixListViewCtrl::InsertMarkHitTest(POINT& point, LVINSERTMARK& mark)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return ListView_InsertMarkHitTest(m_Handle, &point, &mark);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixListViewCtrl::IsGroupViewEnabled() const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return ListView_IsGroupViewEnabled(m_Handle);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixListViewCtrl::IsItemVisible(UINT itemID) const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return ListView_IsItemVisible(m_Handle, itemID);
}
//----------------------------------------------------------------------------//
UIXINLINE UINT uixListViewCtrl::IDToIndex(UINT itemID) const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return ListView_MapIDToIndex(m_Handle, itemID);
}
//----------------------------------------------------------------------------//
UIXINLINE UINT uixListViewCtrl::IndexToID(UINT index) const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return ListView_MapIndexToID(m_Handle, index);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixListViewCtrl::RedrawItems(INT firstIndex, INT lastIndex)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return ListView_RedrawItems(m_Handle, firstIndex, lastIndex);
}
//----------------------------------------------------------------------------//
UIXINLINE void uixListViewCtrl::RemoveAllGroups()
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    ListView_RemoveAllGroups(m_Handle);
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixListViewCtrl::RemoveGroup(INT groupID)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (INT)ListView_RemoveGroup(m_Handle, groupID);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixListViewCtrl::ScrollView(INT dx, INT dy)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return ListView_Scroll(m_Handle, dx, dy);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixListViewCtrl::SetBackgroundColor(uixColor color)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return ListView_SetBkColor(m_Handle, color);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixListViewCtrl::SetBackgroundImage(LVBKIMAGE& image)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return ListView_SetBkImage(m_Handle, &image);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixListViewCtrl::SetCallbackMask(UINT mask)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return ListView_SetCallbackMask(m_Handle, mask);
}
//----------------------------------------------------------------------------//
UIXINLINE void uixListViewCtrl::SetCheckState(UINT itemIndex, BOOL check)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    ListView_SetCheckState(m_Handle, itemIndex, check);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixListViewCtrl::SetColumn(INT columnIndex, LVCOLUMN& column)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return ListView_SetColumn(m_Handle, columnIndex, &column);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixListViewCtrl::SetColumnOrderArray(INT order[], INT count)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return ListView_SetColumnOrderArray(m_Handle, count, order);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixListViewCtrl::SetColumnWidth(INT columnIndex, INT width)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return ListView_SetColumnWidth(m_Handle, columnIndex, width);
}
//----------------------------------------------------------------------------//
UIXINLINE void uixListViewCtrl::SetControlStyle(DWORD style)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    ListView_SetExtendedListViewStyle(m_Handle, style);
}
//----------------------------------------------------------------------------//
UIXINLINE void uixListViewCtrl::SetControlStyle(DWORD style, DWORD mask)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    ListView_SetExtendedListViewStyleEx(m_Handle, mask, style);
}
//----------------------------------------------------------------------------//
UIXINLINE HIMAGELIST uixListViewCtrl::SetGroupHeaderImageList(HIMAGELIST images)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return ListView_SetGroupHeaderImageList(m_Handle, images);
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixListViewCtrl::SetGroupInfo(INT groupID, LVGROUP& group)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (INT)ListView_SetGroupInfo(m_Handle, groupID, &group);
}
//----------------------------------------------------------------------------//
UIXINLINE void uixListViewCtrl::SetGroupMetrics(LVGROUPMETRICS& metrics)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    ListView_SetGroupMetrics(m_Handle, &metrics);
}
//----------------------------------------------------------------------------//
UIXINLINE void uixListViewCtrl::SetGroupState(UINT groupID, UINT mask, UINT state)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    ListView_SetGroupState(m_Handle, groupID, mask, state);
}
//----------------------------------------------------------------------------//
UIXINLINE HCURSOR uixListViewCtrl::SetHotCursor(HCURSOR cursor)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return ListView_SetHotCursor(m_Handle, cursor);
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixListViewCtrl::SetHotItem(INT itemIndex)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return ListView_SetHotItem(m_Handle, itemIndex);
}
//----------------------------------------------------------------------------//
UIXINLINE void uixListViewCtrl::SetHoverTime(DWORD time)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    ListView_SetHoverTime(m_Handle, time);
}
//----------------------------------------------------------------------------//
UIXINLINE DWORD uixListViewCtrl::SetIconSpacing(INT width, INT height)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return ListView_SetIconSpacing(m_Handle, width, height);
}
//----------------------------------------------------------------------------//
UIXINLINE HIMAGELIST uixListViewCtrl::SetImageList(HIMAGELIST handle, uixListViewImageList type)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return ListView_SetImageList(m_Handle, handle, type);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixListViewCtrl::SetInfoTip(LVSETINFOTIP& info)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return ListView_SetInfoTip(m_Handle, &info);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixListViewCtrl::SetInsertMark(LVINSERTMARK& mark)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return ListView_SetInsertMark(m_Handle, &mark);
}
//----------------------------------------------------------------------------//
UIXINLINE uixColor uixListViewCtrl::SetInsertMarkColor(uixColor color)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return ListView_SetInsertMarkColor(m_Handle, color);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixListViewCtrl::SetItem(const LVITEM& item)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return ListView_SetItem(m_Handle, &item);
}
//----------------------------------------------------------------------------//
UIXINLINE void uixListViewCtrl::SetItemCount(INT count)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    ListView_SetItemCount(m_Handle, count);
}
//----------------------------------------------------------------------------//
UIXINLINE void uixListViewCtrl::SetItemCount(INT count, DWORD flags)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    ListView_SetItemCountEx(m_Handle, count, flags);
}
//----------------------------------------------------------------------------//
UIXINLINE void uixListViewCtrl::SetItemIndexState(LVITEMINDEX& index, UINT data, UINT mask)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    ListView_SetItemIndexState(m_Handle, &index, data, mask);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixListViewCtrl::SetItemPosition(INT itemIndex, INT left, INT top)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return ListView_SetItemPosition(m_Handle, itemIndex, left, top);
}
//----------------------------------------------------------------------------//
UIXINLINE void uixListViewCtrl::SetItemPosition32(INT itemIndex, INT left, INT top)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    ListView_SetItemPosition32(m_Handle, itemIndex, left, top);
}
//----------------------------------------------------------------------------//
UIXINLINE void uixListViewCtrl::SetItemState(INT itemIndex, UINT state, UINT mask)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    ListView_SetItemState(m_Handle, itemIndex, state, mask);
}
//----------------------------------------------------------------------------//
UIXINLINE void uixListViewCtrl::SetItemText(INT itemIndex, INT subItemIndex, const uixChar* text)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    ListView_SetItemText(m_Handle, itemIndex, subItemIndex, (LPTSTR)text);
}
//----------------------------------------------------------------------------//
UIXINLINE uixColor uixListViewCtrl::SetOutlineColor(uixColor color)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return ListView_SetOutlineColor(m_Handle, color);
}
//----------------------------------------------------------------------------//
UIXINLINE void uixListViewCtrl::SetSelectedColumn(INT columnIndex)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    ListView_SetSelectedColumn(m_Handle, columnIndex);
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixListViewCtrl::SetSelectionMark(INT itemIndex)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return ListView_SetSelectionMark(m_Handle, itemIndex);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixListViewCtrl::SetTextBackgroundColor(uixColor color)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return ListView_SetTextBkColor(m_Handle, color);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixListViewCtrl::SetTextColor(uixColor color)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return ListView_SetTextColor(m_Handle, color);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixListViewCtrl::SetTileInfo(LVTILEINFO& info)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (BOOL)ListView_SetTileInfo(m_Handle, &info);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixListViewCtrl::SetTileViewInfo(LVTILEVIEWINFO& info)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (BOOL)ListView_SetTileViewInfo(m_Handle, &info);
}
//----------------------------------------------------------------------------//
UIXINLINE HWND uixListViewCtrl::SetToolTips(HWND toolTips)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return ListView_SetToolTips(m_Handle, toolTips);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixListViewCtrl::SetUnicodeFormat(BOOL unicode)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return ListView_SetUnicodeFormat(m_Handle, unicode);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixListViewCtrl::SetViewMode(uixListViewViewMode view)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return ListView_SetView(m_Handle, view) != 0;
}
//----------------------------------------------------------------------------//
UIXINLINE void uixListViewCtrl::SetWorkAreas(RECT areas[], INT count)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    ListView_SetWorkAreas(m_Handle, count, areas);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixListViewCtrl::SortGroups(PFNLVGROUPCOMPARE compare, void* data)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return ListView_SortGroups(m_Handle, compare, data) != 0;
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixListViewCtrl::SortItems(PFNLVCOMPARE compare, LPARAM data)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return ListView_SortItems(m_Handle, compare, data);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixListViewCtrl::SortItemsEx(PFNLVCOMPARE compare, LPARAM data)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return ListView_SortItemsEx(m_Handle, compare, data);
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixListViewCtrl::SubItemHitTest(LVHITTESTINFO& info)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return ListView_SubItemHitTest(m_Handle, &info);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixListViewCtrl::UpdateItem(INT itemIndex)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return ListView_Update(m_Handle, itemIndex);
}
//----------------------------------------------------------------------------//
}
//----------------------------------------------------------------------------//
#endif /* _UIX_LISTVIEWCTRL_INL__ */
