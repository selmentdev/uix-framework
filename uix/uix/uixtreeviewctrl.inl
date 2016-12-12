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
#ifndef _UIX_TREEVIEWCTRL_INL__
#define _UIX_TREEVIEWCTRL_INL__
//----------------------------------------------------------------------------//
#include "uixtreeviewctrl.h"
//----------------------------------------------------------------------------//
namespace UIX
{
//----------------------------------------------------------------------------//
// Tree view item
//----------------------------------------------------------------------------//
UIXINLINE uixTreeViewItem::uixTreeViewItem()
{
    ZeroMemory(this, sizeof(uixTreeViewItem));
}
//----------------------------------------------------------------------------//
UIXINLINE DWORD uixTreeViewItem::GetMask() const
{
    return mask;
}
//----------------------------------------------------------------------------//
UIXINLINE void uixTreeViewItem::SetMask(DWORD value)
{
    mask = value;
}
//----------------------------------------------------------------------------//
UIXINLINE HTREEITEM uixTreeViewItem::GetItem() const
{
    if (mask & TVIF_HANDLE)
    {
        return hItem;
    }

    return 0;
}
//----------------------------------------------------------------------------//
UIXINLINE void uixTreeViewItem::SetItem(HTREEITEM handle)
{
    mask |= TVIF_HANDLE;
    hItem = handle;
}
//----------------------------------------------------------------------------//
UIXINLINE DWORD uixTreeViewItem::GetState() const
{
    if (mask & TVIF_STATE)
    {
        return state;
    }

    return 0;
}
//----------------------------------------------------------------------------//
UIXINLINE void uixTreeViewItem::SetState(DWORD value)
{
    mask |= TVIF_STATE;
    state = value;
}
//----------------------------------------------------------------------------//
UIXINLINE DWORD uixTreeViewItem::GetStateMask() const
{
    return stateMask;
}
//----------------------------------------------------------------------------//
UIXINLINE void uixTreeViewItem::SetStateMask(DWORD value)
{
    stateMask = value;
}
//----------------------------------------------------------------------------//
UIXINLINE const uixChar* uixTreeViewItem::GetText() const
{
    if (mask & TVIF_TEXT)
    {
        return pszText;
    }

    return NULLPTR;
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixTreeViewItem::GetTextLength() const
{
    if (mask & TVIF_TEXT)
    {
        return cchTextMax;
    }

    return 0;
}
//----------------------------------------------------------------------------//
UIXINLINE void uixTreeViewItem::SetText(const uixChar* text)
{
    mask |= TVIF_TEXT;
    pszText = (LPTSTR)text;
    cchTextMax = lstrlen(text);
}
//----------------------------------------------------------------------------//
UIXINLINE void uixTreeViewItem::SetText(const uixChar* text, INT length)
{
    mask |= TVIF_TEXT;
    pszText = (LPTSTR)text;
    cchTextMax = length;
}
//----------------------------------------------------------------------------//
UIXINLINE void uixTreeViewItem::SetTextLength(INT length)
{
    cchTextMax = length;
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixTreeViewItem::GetImage() const
{
    if (mask & TVIF_IMAGE)
    {
        return iImage;
    }

    return 0;
}
//----------------------------------------------------------------------------//
UIXINLINE void uixTreeViewItem::SetImage(INT value)
{
    mask |= TVIF_IMAGE;
    iImage = value;
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixTreeViewItem::GetSelectedImage() const
{
    if (mask & TVIF_SELECTEDIMAGE)
    {
        return iSelectedImage;
    }

    return 0;
}
//----------------------------------------------------------------------------//
UIXINLINE void uixTreeViewItem::SetSelectedImage(INT value)
{
    mask |= TVIF_SELECTEDIMAGE;
    iSelectedImage = value;
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixTreeViewItem::GetChildren() const
{
    if (mask & TVIF_CHILDREN)
    {
        return cChildren;
    }

    return 0;
}
//----------------------------------------------------------------------------//
UIXINLINE void uixTreeViewItem::SetChildren(INT value)
{
    mask |= TVIF_CHILDREN;
    cChildren = value;
}
//----------------------------------------------------------------------------//
UIXINLINE const void* uixTreeViewItem::GetData() const
{
    if (mask & TVIF_PARAM)
    {
        return (const void*)lParam;
    }

    return NULLPTR;
}
//----------------------------------------------------------------------------//
UIXINLINE void uixTreeViewItem::SetData(const void* data)
{
    mask |= TVIF_PARAM;
    lParam = (LPARAM)data;
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixTreeViewItem::GetIntegral() const
{
    if (mask & TVIF_INTEGRAL)
    {
        return iIntegral;
    }

    return 0;
}
//----------------------------------------------------------------------------//
UIXINLINE void uixTreeViewItem::SetIntegral(INT value)
{
    mask |= TVIF_INTEGRAL;
    iIntegral = value;
}
//----------------------------------------------------------------------------//
UIXINLINE DWORD uixTreeViewItem::GetStateEx() const
{
    if (mask & TVIF_STATEEX)
    {
        return uStateEx;
    }

    return 0;
}
//----------------------------------------------------------------------------//
UIXINLINE void uixTreeViewItem::SetStateEx(DWORD value)
{
    mask |= TVIF_STATEEX;
    uStateEx = value;
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixTreeViewItem::GetExpanededImage() const
{
    if (mask & TVIF_EXPANDEDIMAGE)
    {
        return iExpandedImage;
    }

    return 0;
}
//----------------------------------------------------------------------------//
UIXINLINE void uixTreeViewItem::SetExpandedImage(INT value)
{
    mask |= TVIF_EXPANDEDIMAGE;
    iExpandedImage = value;
}
//----------------------------------------------------------------------------//
// Tree view item insert
//----------------------------------------------------------------------------//
UIXINLINE void uixTreeViewInsert::SetParent(HTREEITEM handle)
{
    hParent = handle;
}
//----------------------------------------------------------------------------//
UIXINLINE HTREEITEM uixTreeViewInsert::GetParent() const
{
    return hParent;
}
//----------------------------------------------------------------------------//
UIXINLINE void uixTreeViewInsert::SetRelativeAsFirst()
{
    hInsertAfter = TVI_FIRST;
}
//----------------------------------------------------------------------------//
UIXINLINE void uixTreeViewInsert::SetRelativeAsLast()
{
    hInsertAfter = TVI_LAST;
}
//----------------------------------------------------------------------------//
UIXINLINE void uixTreeViewInsert::SetRelativeAsRoot()
{
    hInsertAfter = TVI_ROOT;
}
//----------------------------------------------------------------------------//
UIXINLINE void uixTreeViewInsert::SetRelativeAsSorted()
{
    hInsertAfter = TVI_SORT;
}
//----------------------------------------------------------------------------//
UIXINLINE HTREEITEM uixTreeViewInsert::GetRelative() const
{
    return hInsertAfter;
}
//----------------------------------------------------------------------------//
UIXINLINE void uixTreeViewInsert::SetItem(const TVITEMEX& item)
{
    itemex = item;
}
//----------------------------------------------------------------------------//
UIXINLINE void uixTreeViewInsert::GetItem(TVITEMEX& item) const
{
    item = itemex;
}
//----------------------------------------------------------------------------//
// Tree View control
//----------------------------------------------------------------------------//
UIXINLINE HIMAGELIST uixTreeViewCtrl::CreateDragImage(HTREEITEM item) const
{
    uixASSERT(this != 0);
    uixASSERT(::IsWindow(m_Handle));
    uixASSERT(item != 0);
    return TreeView_CreateDragImage(m_Handle, item);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixTreeViewCtrl::DeleteAllItems()
{
    uixASSERT(this != 0);
    uixASSERT(::IsWindow(m_Handle));
    return TreeView_DeleteAllItems(m_Handle);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixTreeViewCtrl::DeleteItem(HTREEITEM item)
{
    uixASSERT(this != 0);
    uixASSERT(::IsWindow(m_Handle));
    uixASSERT(item != 0);
    return TreeView_DeleteItem(m_Handle, item);
}
//----------------------------------------------------------------------------//
UIXINLINE HWND uixTreeViewCtrl::EditLabel(HTREEITEM item)
{
    uixASSERT(this != 0);
    uixASSERT(::IsWindow(m_Handle));
    uixASSERT(item != 0);
    return TreeView_EditLabel(m_Handle, item);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixTreeViewCtrl::EndEditLabelNow(BOOL cancel)
{
    uixASSERT(this != 0);
    uixASSERT(::IsWindow(m_Handle));
    return TreeView_EndEditLabelNow(m_Handle, cancel);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixTreeViewCtrl::EnsureVisible(HTREEITEM item)
{
    uixASSERT(this != 0);
    uixASSERT(::IsWindow(m_Handle));
    uixASSERT(item != 0);
    return TreeView_EnsureVisible(m_Handle, item);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixTreeViewCtrl::Expand(HTREEITEM item, UINT flag)
{
    uixASSERT(this != 0);
    uixASSERT(::IsWindow(m_Handle));
    uixASSERT(item != 0);
    return TreeView_Expand(m_Handle, item, flag);
}
//----------------------------------------------------------------------------//
UIXINLINE uixColor uixTreeViewCtrl::GetBackgroundColor() const
{
    uixASSERT(this != 0);
    uixASSERT(::IsWindow(m_Handle));
    return TreeView_GetBkColor(m_Handle);
}
//----------------------------------------------------------------------------//
UIXINLINE UINT uixTreeViewCtrl::GetCheckState(HTREEITEM item) const
{
    uixASSERT(this != 0);
    uixASSERT(::IsWindow(m_Handle));
    uixASSERT(item != 0);
    return TreeView_GetCheckState(m_Handle, item);
}
//----------------------------------------------------------------------------//
UIXINLINE HTREEITEM uixTreeViewCtrl::GetChild(HTREEITEM item) const
{
    uixASSERT(this != 0);
    uixASSERT(::IsWindow(m_Handle));
    uixASSERT(item != 0);
    return TreeView_GetChild(m_Handle, item);
}
//----------------------------------------------------------------------------//
UIXINLINE UINT uixTreeViewCtrl::GetCount() const
{
    uixASSERT(this != 0);
    uixASSERT(::IsWindow(m_Handle));
    return TreeView_GetCount(m_Handle);
}
//----------------------------------------------------------------------------//
UIXINLINE HTREEITEM uixTreeViewCtrl::GetDropHighlight() const
{
    uixASSERT(this != 0);
    uixASSERT(::IsWindow(m_Handle));
    return TreeView_GetDropHilight(m_Handle);
}
//----------------------------------------------------------------------------//
UIXINLINE HWND uixTreeViewCtrl::GetEditControl() const
{
    uixASSERT(this != 0);
    uixASSERT(::IsWindow(m_Handle));
    return TreeView_GetEditControl(m_Handle);
}
//----------------------------------------------------------------------------//
UIXINLINE DWORD uixTreeViewCtrl::GetControlExStyle() const
{
    uixASSERT(this != 0);
    uixASSERT(::IsWindow(m_Handle));
    return TreeView_GetExtendedStyle(m_Handle);
}
//----------------------------------------------------------------------------//
UIXINLINE HTREEITEM uixTreeViewCtrl::GetFirstVisible() const
{
    uixASSERT(this != 0);
    uixASSERT(::IsWindow(m_Handle));
    return TreeView_GetFirstVisible(m_Handle);
}
//----------------------------------------------------------------------------//
UIXINLINE HIMAGELIST uixTreeViewCtrl::GetImageList(INT type) const
{
    uixASSERT(this != 0);
    uixASSERT(::IsWindow(m_Handle));
    return TreeView_GetImageList(m_Handle, type);
}
//----------------------------------------------------------------------------//
UIXINLINE UINT uixTreeViewCtrl::GetIndent() const
{
    uixASSERT(this != 0);
    uixASSERT(::IsWindow(m_Handle));
    return TreeView_GetIndent(m_Handle);
}
//----------------------------------------------------------------------------//
UIXINLINE uixColor uixTreeViewCtrl::GetInsertMarkColor() const
{
    uixASSERT(this != 0);
    uixASSERT(::IsWindow(m_Handle));
    return TreeView_GetInsertMarkColor(m_Handle);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixTreeViewCtrl::GetISearchString(uixChar* text) const
{
    uixASSERT(this != 0);
    uixASSERT(::IsWindow(m_Handle));
    return TreeView_GetISearchString(m_Handle, text);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixTreeViewCtrl::GetItem(TVITEMEX& item) const
{
    uixASSERT(this != 0);
    uixASSERT(::IsWindow(m_Handle));
    return TreeView_GetItem(m_Handle, &item);
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixTreeViewCtrl::GetItemHeight() const
{
    uixASSERT(this != 0);
    uixASSERT(::IsWindow(m_Handle));
    return TreeView_GetItemHeight(m_Handle);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixTreeViewCtrl::GetItemPartRect(HTREEITEM item, RECT& rect) const
{
    uixASSERT(this != 0);
    uixASSERT(::IsWindow(m_Handle));
    uixASSERT(item != 0);

    TVGETITEMPARTRECTINFO info;
    info.hti = item;
    info.prc = &rect;
    \
    info.partID = TVGIPR_BUTTON;
    return (BOOL)SendMessage(TVM_GETITEMPARTRECT, 0, (LPARAM)&info);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixTreeViewCtrl::GetItemRect(HTREEITEM item, RECT& rect, BOOL itemRect) const
{
    uixASSERT(this != 0);
    uixASSERT(::IsWindow(m_Handle));
    uixASSERT(item != 0);
    return TreeView_GetItemRect(m_Handle, item, &rect, itemRect);
}
//----------------------------------------------------------------------------//
UIXINLINE UINT uixTreeViewCtrl::GetItemState(HTREEITEM item, UINT stateMask) const
{
    uixASSERT(this != 0);
    uixASSERT(::IsWindow(m_Handle));
    uixASSERT(item != 0);
    return TreeView_GetItemState(m_Handle, item, stateMask);
}
//----------------------------------------------------------------------------//
UIXINLINE HTREEITEM uixTreeViewCtrl::GetLastVisible() const
{
    uixASSERT(this != 0);
    uixASSERT(::IsWindow(m_Handle));
    return TreeView_GetLastVisible(m_Handle);
}
//----------------------------------------------------------------------------//
UIXINLINE uixColor uixTreeViewCtrl::GetLineColor() const
{
    uixASSERT(this != 0);
    uixASSERT(::IsWindow(m_Handle));
    return TreeView_GetLineColor(m_Handle);
}
//----------------------------------------------------------------------------//
UIXINLINE HTREEITEM uixTreeViewCtrl::GetNext_Item(HTREEITEM item, UINT flag) const
{
    uixASSERT(this != 0);
    uixASSERT(::IsWindow(m_Handle));
    uixASSERT(item != 0);
    return TreeView_GetNextItem(m_Handle, item, flag);
}
//----------------------------------------------------------------------------//
UIXINLINE HTREEITEM uixTreeViewCtrl::GetNext_Selected(HTREEITEM item) const
{
    uixASSERT(this != 0);
    uixASSERT(::IsWindow(m_Handle));
    uixASSERT(item != 0);
    return TreeView_GetNextSelected(m_Handle, item);
}
//----------------------------------------------------------------------------//
UIXINLINE HTREEITEM uixTreeViewCtrl::GetNext_Sibling(HTREEITEM item) const
{
    uixASSERT(this != 0);
    uixASSERT(::IsWindow(m_Handle));
    uixASSERT(item != 0);
    return TreeView_GetNextSibling(m_Handle, item);
}
//----------------------------------------------------------------------------//
UIXINLINE HTREEITEM uixTreeViewCtrl::GetNext_Visible(HTREEITEM item) const
{
    uixASSERT(this != 0);
    uixASSERT(::IsWindow(m_Handle));
    uixASSERT(item != 0);
    return TreeView_GetNextVisible(m_Handle, item);
}
//----------------------------------------------------------------------------//
UIXINLINE HTREEITEM uixTreeViewCtrl::GetParent(HTREEITEM item) const
{
    uixASSERT(this != 0);
    uixASSERT(::IsWindow(m_Handle));
    uixASSERT(item != 0);
    return TreeView_GetParent(m_Handle, item);
}
//----------------------------------------------------------------------------//
UIXINLINE HTREEITEM uixTreeViewCtrl::GetPrev_Sibling(HTREEITEM item) const
{
    uixASSERT(this != 0);
    uixASSERT(::IsWindow(m_Handle));
    uixASSERT(item != 0);
    return TreeView_GetPrevSibling(m_Handle, item);
}
//----------------------------------------------------------------------------//
UIXINLINE HTREEITEM uixTreeViewCtrl::GetPrev_Visible(HTREEITEM item) const
{
    uixASSERT(this != 0);
    uixASSERT(::IsWindow(m_Handle));
    uixASSERT(item != 0);
    return TreeView_GetPrevVisible(m_Handle, item);
}
//----------------------------------------------------------------------------//
UIXINLINE HTREEITEM uixTreeViewCtrl::GetRoot() const
{
    uixASSERT(this != 0);
    uixASSERT(::IsWindow(m_Handle));
    return TreeView_GetRoot(m_Handle);
}
//----------------------------------------------------------------------------//
UIXINLINE UINT uixTreeViewCtrl::GetScrollTime() const
{
    uixASSERT(this != 0);
    uixASSERT(::IsWindow(m_Handle));
    return TreeView_GetScrollTime(m_Handle);
}
//----------------------------------------------------------------------------//
UIXINLINE HTREEITEM uixTreeViewCtrl::GetSelection() const
{
    uixASSERT(this != 0);
    uixASSERT(::IsWindow(m_Handle));
    return TreeView_GetSelection(m_Handle);
}
//----------------------------------------------------------------------------//
UIXINLINE uixColor uixTreeViewCtrl::GetTextColor() const
{
    uixASSERT(this != 0);
    uixASSERT(::IsWindow(m_Handle));
    return TreeView_GetTextColor(m_Handle);
}
//----------------------------------------------------------------------------//
UIXINLINE HWND uixTreeViewCtrl::GetToolTips() const
{
    uixASSERT(this != 0);
    uixASSERT(::IsWindow(m_Handle));
    return TreeView_GetToolTips(m_Handle);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixTreeViewCtrl::GetUnicodeFormat() const
{
    uixASSERT(this != 0);
    uixASSERT(::IsWindow(m_Handle));
    return TreeView_GetUnicodeFormat(m_Handle);
}
//----------------------------------------------------------------------------//
UIXINLINE UINT uixTreeViewCtrl::GetVisibleCount() const
{
    uixASSERT(this != 0);
    uixASSERT(::IsWindow(m_Handle));
    return TreeView_GetVisibleCount(m_Handle);
}
//----------------------------------------------------------------------------//
UIXINLINE HTREEITEM uixTreeViewCtrl::HitTest(TVHITTESTINFO& info) const
{
    uixASSERT(this != 0);
    uixASSERT(::IsWindow(m_Handle));
    return TreeView_HitTest(m_Handle, &info);
}
//----------------------------------------------------------------------------//
UIXINLINE HTREEITEM uixTreeViewCtrl::InsertItem(TVINSERTSTRUCT& item)
{
    uixASSERT(this != 0);
    uixASSERT(::IsWindow(m_Handle));
    return TreeView_InsertItem(m_Handle, &item);
}
//----------------------------------------------------------------------------//
UIXINLINE HTREEITEM uixTreeViewCtrl::MapAccIDToHTREEITEM(UINT id) const
{
    uixASSERT(this != 0);
    uixASSERT(::IsWindow(m_Handle));
    return TreeView_MapAccIDToHTREEITEM(m_Handle, id);
}
//----------------------------------------------------------------------------//
UIXINLINE UINT uixTreeViewCtrl::MapHTREEITEMtoAccID(HTREEITEM item) const
{
    uixASSERT(this != 0);
    uixASSERT(::IsWindow(m_Handle));
    uixASSERT(item != 0);
    return TreeView_MapHTREEITEMToAccID(m_Handle, item);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixTreeViewCtrl::Select(HTREEITEM item, UINT flag)
{
    uixASSERT(this != 0);
    uixASSERT(::IsWindow(m_Handle));
    uixASSERT(item != 0);
    return TreeView_Select(m_Handle, item, flag);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixTreeViewCtrl::SelectDropTarget(HTREEITEM item)
{
    uixASSERT(this != 0);
    uixASSERT(::IsWindow(m_Handle));
    uixASSERT(item != 0);
    return TreeView_SelectDropTarget(m_Handle, item);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixTreeViewCtrl::SelectItem(HTREEITEM item)
{
    uixASSERT(this != 0);
    uixASSERT(::IsWindow(m_Handle));
    uixASSERT(item != 0);
    return TreeView_SelectItem(m_Handle, item);
}
//----------------------------------------------------------------------------//
UIXINLINE LRESULT uixTreeViewCtrl::SetAutoScrollInfo(UINT pixPerSecond, UINT updateTime)
{
    uixASSERT(this != 0);
    uixASSERT(::IsWindow(m_Handle));
    return TreeView_SetAutoScrollInfo(m_Handle, pixPerSecond, updateTime);
}
//----------------------------------------------------------------------------//
UIXINLINE uixColor uixTreeViewCtrl::SetBackgroundColor(uixColor color)
{
    uixASSERT(this != 0);
    uixASSERT(::IsWindow(m_Handle));
    return TreeView_SetBkColor(m_Handle, color);
}
//----------------------------------------------------------------------------//
UIXINLINE UINT uixTreeViewCtrl::SetCheckState(HTREEITEM item, BOOL check)
{
    uixASSERT(this != 0);
    uixASSERT(::IsWindow(m_Handle));
    uixASSERT(item != 0);
    return SetItemState(
               item,
               INDEXTOSTATEIMAGEMASK(check ? 2 : 1),
               TVIS_STATEIMAGEMASK);
}
//----------------------------------------------------------------------------//
UIXINLINE HRESULT uixTreeViewCtrl::SetControlExStyle(DWORD style, UINT mask)
{
    uixASSERT(this != 0);
    uixASSERT(::IsWindow(m_Handle));
    return TreeView_SetExtendedStyle(m_Handle, style, mask);
}
//----------------------------------------------------------------------------//
UIXINLINE HIMAGELIST uixTreeViewCtrl::SetImageList(HIMAGELIST imageList, INT type)
{
    uixASSERT(this != 0);
    uixASSERT(::IsWindow(m_Handle));
    return TreeView_SetImageList(m_Handle, imageList, type);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixTreeViewCtrl::SetIndent(INT indent)
{
    uixASSERT(this != 0);
    uixASSERT(::IsWindow(m_Handle));
    return TreeView_SetIndent(m_Handle, indent);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixTreeViewCtrl::SetInsertMark(HTREEITEM item, BOOL after)
{
    uixASSERT(this != 0);
    uixASSERT(::IsWindow(m_Handle));
    uixASSERT(item != 0);
    return TreeView_SetInsertMark(m_Handle, item, after);
}
//----------------------------------------------------------------------------//
UIXINLINE uixColor uixTreeViewCtrl::SetInsertMarkColor(uixColor color)
{
    uixASSERT(this != 0);
    uixASSERT(::IsWindow(m_Handle));
    return TreeView_SetInsertMarkColor(m_Handle, color);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixTreeViewCtrl::SetItem(const TVITEMEX& item)
{
    uixASSERT(this != 0);
    uixASSERT(::IsWindow(m_Handle));
    return TreeView_SetItem(m_Handle, &item);
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixTreeViewCtrl::SetItemHeight(SHORT itemHeight)
{
    uixASSERT(this != 0);
    uixASSERT(::IsWindow(m_Handle));
    return TreeView_SetItemHeight(m_Handle, itemHeight);
}
//----------------------------------------------------------------------------//
UIXINLINE UINT uixTreeViewCtrl::SetItemState(HTREEITEM item, UINT state, UINT stateMask)
{
    uixASSERT(this != 0);
    uixASSERT(::IsWindow(m_Handle));
    uixASSERT(item != 0);

    TVITEM _ms_TVi;
    _ms_TVi.mask = TVIF_STATE;
    _ms_TVi.hItem = item;
    _ms_TVi.stateMask = stateMask;
    _ms_TVi.state = state;
    return (UINT)SendMessage(TVM_SETITEM, 0, (LPARAM)(TV_ITEM*)&_ms_TVi);
}
//----------------------------------------------------------------------------//
UIXINLINE uixColor uixTreeViewCtrl::SetLineColor(uixColor color)
{
    uixASSERT(this != 0);
    uixASSERT(::IsWindow(m_Handle));
    return TreeView_SetLineColor(m_Handle, color);
}
//----------------------------------------------------------------------------//
UIXINLINE UINT uixTreeViewCtrl::SetScrollTime(UINT maxScrollTime)
{
    uixASSERT(this != 0);
    uixASSERT(::IsWindow(m_Handle));
    return TreeView_SetScrollTime(m_Handle, maxScrollTime);
}
//----------------------------------------------------------------------------//
UIXINLINE uixColor uixTreeViewCtrl::SetTextColor(uixColor color)
{
    uixASSERT(this != 0);
    uixASSERT(::IsWindow(m_Handle));
    return TreeView_SetTextColor(m_Handle, color);
}
//----------------------------------------------------------------------------//
UIXINLINE HWND uixTreeViewCtrl::SetToolTips(HWND toolTip)
{
    uixASSERT(this != 0);
    uixASSERT(::IsWindow(m_Handle));
    return TreeView_SetToolTips(m_Handle, toolTip);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixTreeViewCtrl::SetUnicodeFormat(BOOL unicode)
{
    uixASSERT(this != 0);
    uixASSERT(::IsWindow(m_Handle));
    return TreeView_SetUnicodeFormat(m_Handle, unicode);
}
//----------------------------------------------------------------------------//
UIXINLINE DWORD uixTreeViewCtrl::ShowInfoTip(HTREEITEM item)
{
    uixASSERT(this != 0);
    uixASSERT(::IsWindow(m_Handle));
    uixASSERT(item != 0);
    return TreeView_ShowInfoTip(m_Handle, item);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixTreeViewCtrl::SortChildren(HTREEITEM item, BOOL recurse)
{
    uixASSERT(this != 0);
    uixASSERT(::IsWindow(m_Handle));
    uixASSERT(item != 0);
    return TreeView_SortChildren(m_Handle, item, recurse);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixTreeViewCtrl::SortChildrenCallback(TVSORTCB& sort, BOOL recurse)
{
    uixASSERT(this != 0);
    uixASSERT(::IsWindow(m_Handle));
    return TreeView_SortChildrenCB(m_Handle, &sort, recurse);
}
//----------------------------------------------------------------------------//
}
//----------------------------------------------------------------------------//
#endif /* _UIX_TREEVIEWCTRL_INL__ */