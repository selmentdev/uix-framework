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
#ifndef _UIX_LISTBOXCTRL_INL__
#define _UIX_LISTBOXCTRL_INL__
//----------------------------------------------------------------------------//
#include "uixlistboxctrl.h"
//----------------------------------------------------------------------------//
namespace UIX
{
//----------------------------------------------------------------------------//
UIXINLINE DWORD uixListBoxCtrl::GetListBoxInfo() const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return ::GetListBoxInfo(m_Handle);
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixListBoxCtrl::ItemFromPoint(POINT pt, BOOL autoScroll) const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return LBItemFromPt(m_Handle, pt, autoScroll);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixListBoxCtrl::MakeDragList()
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return ::MakeDragList(m_Handle);
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixListBoxCtrl::AddString(const uixChar* text)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (INT)ListBox_AddString(m_Handle, text);
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixListBoxCtrl::AddItemData(const void* data)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (INT)ListBox_AddItemData(m_Handle, (LPARAM)data);
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixListBoxCtrl::DeleteString(INT itemID)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (INT)ListBox_DeleteString(m_Handle, itemID);
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixListBoxCtrl::Dir(UINT attributes, const uixChar* fileSpec)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (INT)ListBox_Dir(m_Handle, attributes, fileSpec);
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixListBoxCtrl::FindItemData(INT startID, const void* data) const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (INT)ListBox_FindItemData(m_Handle, startID, data);
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixListBoxCtrl::FindString(INT startID, const uixChar* text) const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (INT)ListBox_FindString(m_Handle, startID, text);
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixListBoxCtrl::FindStringExact(INT startID, const uixChar* text) const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (INT)ListBox_FindStringExact(m_Handle, startID, text);
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixListBoxCtrl::GetCaretIndex() const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (INT)ListBox_GetCaretIndex(m_Handle);
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixListBoxCtrl::GetCount() const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (INT)ListBox_GetCount(m_Handle);
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixListBoxCtrl::GetCurrentSelection() const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (INT)ListBox_GetCurSel(m_Handle);
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixListBoxCtrl::GetHorizontalExtent() const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (INT)ListBox_GetHorizontalExtent(m_Handle);
}
//----------------------------------------------------------------------------//
UIXINLINE void* uixListBoxCtrl::GetItemData(INT itemID) const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (void*)ListBox_GetItemData(m_Handle, itemID);
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixListBoxCtrl::GetItemHeight(INT itemID) const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (INT)ListBox_GetItemHeight(m_Handle, itemID);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixListBoxCtrl::GetItemRect(INT itemID, RECT& rect) const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return ListBox_GetItemRect(m_Handle, itemID, &rect) != LB_ERR;
}
//----------------------------------------------------------------------------//
UIXINLINE DWORD uixListBoxCtrl::GetSelected(INT itemID) const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (DWORD)ListBox_GetSel(m_Handle, itemID);
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixListBoxCtrl::GetSelectedCount() const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (INT)ListBox_GetSelCount(m_Handle);
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixListBoxCtrl::GetSelectedItems(INT items[], INT itemCount) const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (INT)ListBox_GetSelItems(m_Handle, itemCount, items);
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixListBoxCtrl::GetString(INT itemID, uixChar* text) const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (INT)ListBox_GetText(m_Handle, itemID, text);
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixListBoxCtrl::GetStringLength(INT itemID) const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (INT)ListBox_GetTextLen(m_Handle, itemID);
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixListBoxCtrl::GetTopIndex() const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (INT)ListBox_GetTopIndex(m_Handle);
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixListBoxCtrl::InsertItemData(INT itemID, const void* data)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (INT)ListBox_InsertItemData(m_Handle, itemID, (LPARAM)data);
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixListBoxCtrl::InsertString(INT itemID, const uixChar* text)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (INT)ListBox_InsertString(m_Handle, itemID, text);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixListBoxCtrl::ResetContent()
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (BOOL)ListBox_ResetContent(m_Handle);
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixListBoxCtrl::SelectItemData(INT startID, const void* data)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (INT)ListBox_SelectItemData(m_Handle, startID, (LPARAM)data);
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixListBoxCtrl::SelectString(INT startID, const uixChar* text)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (INT)ListBox_SelectString(m_Handle, startID, text);
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixListBoxCtrl::SelectItemRange(INT firstID, INT lastID, BOOL select)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (INT)ListBox_SelItemRange(m_Handle, select, firstID, lastID);
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixListBoxCtrl::SetCaretIndex(INT itemID)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (INT)ListBox_SetCaretIndex(m_Handle, itemID);
}
//----------------------------------------------------------------------------//
UIXINLINE void uixListBoxCtrl::SetColumnWidth(INT width)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    ListBox_SetColumnWidth(m_Handle, width);
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixListBoxCtrl::SetCurrentSelection(INT itemID)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (INT)ListBox_SetCurSel(m_Handle, itemID);
}
//----------------------------------------------------------------------------//
UIXINLINE void uixListBoxCtrl::SetHorizontalExtent(INT extent)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    ListBox_SetHorizontalExtent(m_Handle, extent);
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixListBoxCtrl::SetItemData(INT itemID, const void* data)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (INT)ListBox_SetItemData(m_Handle, itemID, (LPARAM)data);
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixListBoxCtrl::SetItemHeight(INT itemID, INT height)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (INT)ListBox_SetItemHeight(m_Handle, itemID, height);
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixListBoxCtrl::SetSelection(INT itemID, BOOL select)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (INT)ListBox_SetSel(m_Handle, select, itemID);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixListBoxCtrl::SetTabStops(INT tabs[], INT count)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (BOOL)ListBox_SetTabStops(m_Handle, count, tabs);
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixListBoxCtrl::SetTopIndex(INT itemID)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (INT)ListBox_SetTopIndex(m_Handle, itemID);
}
//----------------------------------------------------------------------------//
}
//----------------------------------------------------------------------------//
#endif /* _UIX_LISTBOXCTRL_INL__ */