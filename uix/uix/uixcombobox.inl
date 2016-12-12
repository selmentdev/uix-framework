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
#ifndef _UIX_COMBOBOX_INL__
#define _UIX_COMBOBOX_INL__
//----------------------------------------------------------------------------//
#include "uixcombobox.h"
//----------------------------------------------------------------------------//
namespace UIX
{
//----------------------------------------------------------------------------//
UIXINLINE INT uixComboBox::AddItemData(const void* data)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (INT)ComboBox_AddItemData(m_Handle, (LPARAM)data);
}
//----------------------------------------------------------------------------//
template <typename TType>
UIXINLINE INT uixComboBox::AddItemData(const TType& data)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return AddItemData((const void*)&data);
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixComboBox::AddString(const uixChar* text)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (INT)ComboBox_AddString(m_Handle, text);
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixComboBox::DeleteString(INT itemID)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (INT)ComboBox_DeleteString(m_Handle, itemID);
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixComboBox::Dir(UINT attributes, const uixChar* fileSpec)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (INT)ComboBox_Dir(m_Handle, attributes, fileSpec);
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixComboBox::FindItemData(INT firstID, const void* data) const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (INT)ComboBox_FindItemData(m_Handle, firstID, (LPARAM)data);
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixComboBox::FindString(INT firstID, const uixChar* text) const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (INT)ComboBox_FindString(m_Handle, firstID, (LPCTSTR)text);
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixComboBox::FindStringExact(INT firstID, const uixChar* text) const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (INT)ComboBox_FindStringExact(m_Handle, firstID, text);
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixComboBox::GetItemCount() const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (INT)ComboBox_GetCount(m_Handle);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixComboBox::GetCueBanner(uixChar* text, INT length) const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (BOOL)ComboBox_GetCueBannerText(m_Handle, text, length);
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixComboBox::GetCurrentSelection() const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (INT)ComboBox_GetCurSel(m_Handle);
}
//----------------------------------------------------------------------------//
UIXINLINE void uixComboBox::GetDroppedControlRect(RECT& rect) const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    ComboBox_GetDroppedControlRect(m_Handle, &rect);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixComboBox::GetDroppedState() const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (BOOL)ComboBox_GetDroppedState(m_Handle);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixComboBox::GetExtendedUI() const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (BOOL)ComboBox_GetExtendedUI(m_Handle) != 0;
}
//----------------------------------------------------------------------------//
UIXINLINE void* uixComboBox::GetItemData(INT itemID) const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (void*)ComboBox_GetItemData(m_Handle, itemID);
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixComboBox::GetItemHeight() const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (INT)ComboBox_GetItemHeight(m_Handle);
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixComboBox::GetItemString(INT itemID, uixChar* text) const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (INT)ComboBox_GetLBText(m_Handle, itemID, (LPCTSTR)text);
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixComboBox::GetItemStringLength(INT itemID) const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (INT)ComboBox_GetLBTextLen(m_Handle, itemID);
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixComboBox::GetMinVisible() const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (INT)ComboBox_GetMinVisible(m_Handle);
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixComboBox::InsertItemData(INT itemID, const void* data)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (INT)ComboBox_InsertItemData(m_Handle, itemID, (LPARAM)data);
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixComboBox::InsertString(INT itemID, uixChar* text)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (INT)ComboBox_InsertString(m_Handle, itemID, text);
}
//----------------------------------------------------------------------------//
UIXINLINE void uixComboBox::LimitText(INT limit)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    ComboBox_LimitText(m_Handle, limit);
}
//----------------------------------------------------------------------------//
UIXINLINE void uixComboBox::ResetContent()
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    ComboBox_ResetContent(m_Handle);
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixComboBox::SelectItemData(INT startID, const void* data)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (INT)ComboBox_SelectItemData(m_Handle, startID, (LPARAM)data);
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixComboBox::SelectString(INT startID, const uixChar* text)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (INT)ComboBox_SelectString(m_Handle, startID, text);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixComboBox::SetCueBanner(const uixChar* text)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (BOOL)ComboBox_SetCueBannerText(m_Handle, text);
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixComboBox::SetCurrentSelection(INT itemID)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (INT)ComboBox_SetCurSel(m_Handle, itemID);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixComboBox::SetExtendedUI(BOOL flags)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (BOOL)ComboBox_SetExtendedUI(m_Handle, flags);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixComboBox::SetItemData(INT itemID, const void* data)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (BOOL)ComboBox_SetItemData(m_Handle, itemID, (LPARAM)data) != CB_ERR;
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixComboBox::SetItemHeight(INT itemID, INT height)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (BOOL)ComboBox_SetItemHeight(m_Handle, itemID, height) != CB_ERR;
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixComboBox::SetMinVisible(INT minVisible)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (BOOL)ComboBox_SetMinVisible(m_Handle, minVisible);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixComboBox::ShowDropdown(BOOL show)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (BOOL)ComboBox_ShowDropdown(m_Handle, show);
}
//----------------------------------------------------------------------------//
}
//----------------------------------------------------------------------------//
#endif /* _UIX_COMBOBOX_INL__ */