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
#ifndef _UIX_TABCTRL_INL__
#define _UIX_TABCTRL_INL__
//----------------------------------------------------------------------------//
#include "uixtabctrl.h"
//----------------------------------------------------------------------------//
namespace UIX
{
//----------------------------------------------------------------------------//
// uixTabCtrlItem
//----------------------------------------------------------------------------//
UIXINLINE uixTabCtrlItem::uixTabCtrlItem()
{
    mask = 0;
    dwStateMask = (DWORD) - 1;
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixTabCtrlItem::HasState() const
{
    return (mask & TCIF_STATE) != 0;
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixTabCtrlItem::HasImage() const
{
    return (mask & TCIF_IMAGE) != 0;
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixTabCtrlItem::HasData() const
{
    return (mask & TCIF_PARAM) != 0;
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixTabCtrlItem::HasText() const
{
    return (mask & TCIF_TEXT) != 0;
}
//----------------------------------------------------------------------------//
UIXINLINE DWORD uixTabCtrlItem::GetState() const
{
    if (mask & TCIF_STATE)
    {
        return dwState;
    }

    return 0;
}
//----------------------------------------------------------------------------//
UIXINLINE void uixTabCtrlItem::SetState(DWORD state)
{
    mask |= TCIF_STATE;
    dwState = state;
}
//----------------------------------------------------------------------------//
UIXINLINE DWORD uixTabCtrlItem::GetStateMask() const
{
    return dwStateMask;
}
//----------------------------------------------------------------------------//
UIXINLINE void uixTabCtrlItem::SetStateMask(DWORD mask)
{
    dwStateMask = mask;
}
//----------------------------------------------------------------------------//
UIXINLINE void uixTabCtrlItem::SetText(const uixChar* text)
{
    if (text != NULLPTR)
    {
        mask |= TCIF_TEXT;
        pszText = (LPTSTR)text;
        cchTextMax = lstrlen(text);
    }
    else
    {
        // If passed null, discard text
        mask &= ~TCIF_TEXT;
    }
}
//----------------------------------------------------------------------------//
UIXINLINE void uixTabCtrlItem::SetText(const uixChar* text, INT length)
{
    mask |= TCIF_TEXT;
    pszText = (LPTSTR)text;
    cchTextMax = length;
}
//----------------------------------------------------------------------------//
UIXINLINE uixChar* uixTabCtrlItem::GetText() const
{
    if (mask & TCIF_TEXT)
    {
        return pszText;
    }

    return NULLPTR;
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixTabCtrlItem::GetTextLength() const
{
    if (mask & TCIF_TEXT)
    {
        return cchTextMax;
    }

    return 0;
}
//----------------------------------------------------------------------------//
UIXINLINE void uixTabCtrlItem::SetTextLength(INT length)
{
    cchTextMax = length;
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixTabCtrlItem::GetImageIndex() const
{
    if (mask & TCIF_IMAGE)
    {
        return iImage;
    }

    return -1;
}
//----------------------------------------------------------------------------//
UIXINLINE void uixTabCtrlItem::SetImageIndex(INT index)
{
    mask |= TCIF_IMAGE;
    iImage = index;
}
//----------------------------------------------------------------------------//
UIXINLINE void* uixTabCtrlItem::GetData() const
{
    if (mask & TCIF_PARAM)
    {
        return (void*)lParam;
    }

    return NULLPTR;
}
//----------------------------------------------------------------------------//
UIXINLINE void uixTabCtrlItem::SetData(const void* data)
{
    mask |= TCIF_PARAM;
    lParam = (LPARAM)data;
}
//----------------------------------------------------------------------------//
// uixTabCtrl
//----------------------------------------------------------------------------//
UIXINLINE INT uixTabCtrl::GetItemCount() const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (INT)TabCtrl_GetItemCount(m_Handle);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixTabCtrl::GetItem(INT itemID, TCITEM& item) const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (BOOL)TabCtrl_GetItem(m_Handle, itemID, &item);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixTabCtrl::SetItem(INT itemID, const TCITEM& item)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (BOOL)TabCtrl_SetItem(m_Handle, itemID, &item);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixTabCtrl::GetItemRect(INT itemID, RECT& rect) const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (BOOL)TabCtrl_GetItemRect(m_Handle, itemID, &rect);
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixTabCtrl::GetCurrentSelection() const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (INT)TabCtrl_GetCurSel(m_Handle);
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixTabCtrl::SetCurrentSelection(INT itemID)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (INT)TabCtrl_SetCurSel(m_Handle, itemID);
}
//----------------------------------------------------------------------------//
UIXINLINE void uixTabCtrl::SetItemSize(INT width, INT height)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    TabCtrl_SetItemSize(m_Handle, width, height);
}
//----------------------------------------------------------------------------//
UIXINLINE void uixTabCtrl::SetItemSize(SIZE size)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    TabCtrl_SetItemSize(m_Handle, size.cx, size.cy);
}
//----------------------------------------------------------------------------//
UIXINLINE void uixTabCtrl::SetPadding(INT width, INT height)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    TabCtrl_SetPadding(m_Handle, width, height);
}
//----------------------------------------------------------------------------//
UIXINLINE void uixTabCtrl::SetPadding(SIZE size)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    TabCtrl_SetPadding(m_Handle, size.cx, size.cy);
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixTabCtrl::GetRowCount() const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (INT)TabCtrl_GetRowCount(m_Handle);
}
//----------------------------------------------------------------------------//
UIXINLINE HWND uixTabCtrl::GetToolTipCtrl() const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (HWND)TabCtrl_GetToolTips(m_Handle);
}
//----------------------------------------------------------------------------//
UIXINLINE void uixTabCtrl::SetToolTipCtrl(HWND handle)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    uixASSERT(::IsWindow(handle));
    TabCtrl_SetToolTips(m_Handle, handle);
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixTabCtrl::GetCurrentFocus() const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (INT)TabCtrl_GetCurFocus(m_Handle);
}
//----------------------------------------------------------------------------//
UIXINLINE void uixTabCtrl::SetCurrentFocus(INT itemID)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    TabCtrl_SetCurFocus(m_Handle, itemID);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixTabCtrl::SetItemExtra(INT count)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (BOOL)TabCtrl_SetItemExtra(m_Handle, count);
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixTabCtrl::SetMinTabWidth(INT width)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (INT)TabCtrl_SetMinTabWidth(m_Handle, width);
}
//----------------------------------------------------------------------------//
UIXINLINE DWORD uixTabCtrl::GetControlStyle() const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (DWORD)TabCtrl_GetExtendedStyle(m_Handle);
}
//----------------------------------------------------------------------------//
UIXINLINE DWORD uixTabCtrl::SetControlStyle(DWORD style)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (DWORD)TabCtrl_SetExtendedStyle(m_Handle, style);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixTabCtrl::GetUnicodeFormat() const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (BOOL)TabCtrl_GetUnicodeFormat(m_Handle);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixTabCtrl::SetUnicodeFormat(BOOL unicode)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (BOOL)TabCtrl_SetUnicodeFormat(m_Handle, unicode);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixTabCtrl::InsertItem(INT itemID, TCITEM& item)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (BOOL)TabCtrl_InsertItem(m_Handle, itemID, &item);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixTabCtrl::DeleteItem(INT itemID)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (BOOL)TabCtrl_DeleteItem(m_Handle, itemID);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixTabCtrl::DeleteAllItems()
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (BOOL)TabCtrl_DeleteAllItems(m_Handle);
}
//----------------------------------------------------------------------------//
UIXINLINE void uixTabCtrl::AdjustRect(BOOL larger, RECT& rect)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    TabCtrl_AdjustRect(m_Handle, larger, &rect);
}
//----------------------------------------------------------------------------//
UIXINLINE void uixTabCtrl::RemoveImage(INT itemID)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    TabCtrl_RemoveImage(m_Handle, itemID);
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixTabCtrl::HitTest(TC_HITTESTINFO& hti)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (INT)TabCtrl_HitTest(m_Handle, &hti);
}
//----------------------------------------------------------------------------//
UIXINLINE void uixTabCtrl::DeselectAll(BOOL excludeFocus)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    TabCtrl_DeselectAll(m_Handle, excludeFocus);
}
//----------------------------------------------------------------------------//
UIXINLINE HIMAGELIST uixTabCtrl::GetImageList() const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (HIMAGELIST)TabCtrl_GetImageList(m_Handle);
}
//----------------------------------------------------------------------------//
UIXINLINE HIMAGELIST uixTabCtrl::SetImageList(HIMAGELIST handle)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (HIMAGELIST)TabCtrl_SetImageList(m_Handle, handle);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixTabCtrl::HighlightItem(INT itemID, BOOL highlight)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (BOOL)TabCtrl_HighlightItem(m_Handle, itemID, highlight);
}
//----------------------------------------------------------------------------//
}
//----------------------------------------------------------------------------//
#endif /* _UIX_TABCTRL_INL__ */