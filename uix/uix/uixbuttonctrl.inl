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
#ifndef _UIX_BUTTONCTRL_INL__
#define _UIX_BUTTONCTRL_INL__
//----------------------------------------------------------------------------//
#include "uixbuttonctrl.h"
//----------------------------------------------------------------------------//
namespace UIX
{
//----------------------------------------------------------------------------//
// uixButtonImageList
//----------------------------------------------------------------------------//
UIXINLINE HIMAGELIST uixButtonImageList::GetImageList() const
{
    return himl;
}
//----------------------------------------------------------------------------//
UIXINLINE void uixButtonImageList::SetImageList(HIMAGELIST value)
{
    himl = value;
}
//----------------------------------------------------------------------------//
UIXINLINE const RECT& uixButtonImageList::GetMargin() const
{
    return margin;
}
//----------------------------------------------------------------------------//
UIXINLINE void uixButtonImageList::SetMargin(const RECT& rect)
{
    margin = rect;
}
//----------------------------------------------------------------------------//
UIXINLINE uixButtonImageListAlign uixButtonImageList::GetAlign() const
{
    return (uixButtonImageListAlign)uAlign;
}
//----------------------------------------------------------------------------//
UIXINLINE void uixButtonImageList::SetAlign(uixButtonImageListAlign value)
{
    uAlign = (UINT)value;
}
//----------------------------------------------------------------------------//
// uixButtonSplitInfo
//----------------------------------------------------------------------------//
UIXINLINE DWORD uixButtonSplitInfo::GetMask() const
{
    return mask;
}
//----------------------------------------------------------------------------//
UIXINLINE void uixButtonSplitInfo::SetMask(DWORD value)
{
    mask = value;
}
//----------------------------------------------------------------------------//
UIXINLINE HIMAGELIST uixButtonSplitInfo::GetImageList() const
{
    if (uSplitStyle & BCSIF_IMAGE)
    {
        return himlGlyph;
    }

    return 0;
}
//----------------------------------------------------------------------------//
UIXINLINE void uixButtonSplitInfo::SetImageList(HIMAGELIST handle)
{
    uSplitStyle |= BCSS_IMAGE;
    mask |= BCSIF_IMAGE;
    mask &= ~BCSIF_GLYPH;
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixButtonSplitInfo::GetSize(SIZE& value) const
{
    if (mask & BCSIF_SIZE)
    {
        value = size;
        return TRUE;
    }

    return FALSE;
}
//----------------------------------------------------------------------------//
UIXINLINE void uixButtonSplitInfo::SetSize(const SIZE& value)
{
    mask |= BCSIF_SIZE;
    size = value;
}
//----------------------------------------------------------------------------//
UIXINLINE uixButtonSplitStyle uixButtonSplitInfo::GetStyle() const
{
    if (mask & BCSIF_STYLE)
    {
        return (uixButtonSplitStyle)uSplitStyle;
    }

    return (uixButtonSplitStyle)uixButtonSplitStyle_None;
}
//----------------------------------------------------------------------------//
UIXINLINE void uixButtonSplitInfo::SetStyle(uixButtonSplitStyle value)
{
    mask |= BCSIF_STYLE;
    uSplitStyle = (UINT)value;
}
//----------------------------------------------------------------------------//
// uixButton
//----------------------------------------------------------------------------//
UIXINLINE uixButtonState uixButton::GetCheck() const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (uixButtonState)Button_GetCheck(m_Handle);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixButton::GetIdealSize(SIZE& size) const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (BOOL)Button_GetIdealSize(m_Handle, &size);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixButton::GetImageList(BUTTON_IMAGELIST& imageList) const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (BOOL)Button_GetImageList(m_Handle, &imageList);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixButton::GetNote(uixChar* text, INT length) const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (BOOL)Button_GetNote(m_Handle, text, length);
}
//----------------------------------------------------------------------------//
UIXINLINE UINT uixButton::GetNoteLength() const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (UINT)Button_GetNoteLength(m_Handle);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixButton::GetSplitInfo(BUTTON_SPLITINFO& info) const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (BOOL)Button_GetSplitInfo(m_Handle, &info);
}
//----------------------------------------------------------------------------//
UIXINLINE UINT uixButton::GetState() const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (UINT)Button_GetState(m_Handle);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixButton::GetTextMargin(RECT& rect) const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (BOOL)Button_GetTextMargin(m_Handle, &rect);
}
//----------------------------------------------------------------------------//
UIXINLINE void uixButton::SetCheck(uixButtonState check)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    Button_SetCheck(m_Handle, check);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixButton::SetDropDownState(BOOL dropDown)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (BOOL)Button_SetDropDownState(m_Handle, dropDown);
}
//----------------------------------------------------------------------------//
UIXINLINE UINT uixButton::SetElevationRequiredState(BOOL required)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (UINT)Button_SetElevationRequiredState(m_Handle, required);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixButton::SetImageList(BUTTON_IMAGELIST& imageList)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (BOOL)Button_SetImageList(m_Handle, &imageList);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixButton::SetNote(const uixChar* text)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (BOOL)Button_SetNote(m_Handle, text);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixButton::SetSplitInfo(BUTTON_SPLITINFO& info)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (BOOL)Button_SetSplitInfo(m_Handle, &info);
}
//----------------------------------------------------------------------------//
UIXINLINE void uixButton::SetState(BOOL state)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    Button_SetState(m_Handle, state);
}
//----------------------------------------------------------------------------//
UIXINLINE void uixButton::SetStyle(uixButtonStyle style, BOOL redraw)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    Button_SetStyle(m_Handle, style, redraw);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixButton::SetTextMargin(const RECT& rect)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (BOOL)Button_SetTextMargin(m_Handle, &rect);
}
//----------------------------------------------------------------------------//
}
//----------------------------------------------------------------------------//
#endif /* _UIX_BUTTONCTRL_INL__ */