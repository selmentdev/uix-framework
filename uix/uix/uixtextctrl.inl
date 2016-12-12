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
#ifndef _UIX_TEXTCTRL_INL__
#define _UIX_TEXTCTRL_INL__
//----------------------------------------------------------------------------//
#include "uixtextctrl.h"
//----------------------------------------------------------------------------//
namespace UIX
{
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixTextCtrl::CanUndo() const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return Edit_CanUndo(m_Handle);
}
//----------------------------------------------------------------------------//
UIXINLINE void uixTextCtrl::EmptyUndoBuffer()
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    Edit_EmptyUndoBuffer(m_Handle);
}
//----------------------------------------------------------------------------//
UIXINLINE void uixTextCtrl::FmtLines(BOOL addEOL)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    Edit_FmtLines(m_Handle, addEOL);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixTextCtrl::GetCueBannerText(uixChar* text, UINT length) const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (BOOL)Edit_GetCueBannerText(m_Handle, text, length);
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixTextCtrl::GetFirstVisibleLine() const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (INT)Edit_GetFirstVisibleLine(m_Handle);
}
//----------------------------------------------------------------------------//
UIXINLINE HLOCAL uixTextCtrl::GetTextHandle() const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (HLOCAL)Edit_GetHandle(m_Handle);
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixTextCtrl::GetLine(INT line, uixChar* text, UINT length) const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (INT)Edit_GetLine(m_Handle, line, text, length);
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixTextCtrl::GetLineCount() const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (INT)Edit_GetLineCount(m_Handle);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixTextCtrl::GetModify() const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (BOOL)Edit_GetModify(m_Handle);
}
//----------------------------------------------------------------------------//
UIXINLINE uixChar uixTextCtrl::GetPasswordChar() const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (uixChar)Edit_GetPasswordChar(m_Handle);
}
//----------------------------------------------------------------------------//
UIXINLINE void uixTextCtrl::GetFormatRect(RECT& rect) const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    Edit_GetRect(m_Handle, &rect);
}
//----------------------------------------------------------------------------//
UIXINLINE DWORD uixTextCtrl::GetSelection() const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return Edit_GetSel(m_Handle);
}
//----------------------------------------------------------------------------//
UIXINLINE void uixTextCtrl::GetSelection(UINT& start, UINT& stop) const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    DWORD result = Edit_GetSel(m_Handle);
    start = LOWORD(result);
    stop = HIWORD(result);
}
//----------------------------------------------------------------------------//
UIXINLINE EDITWORDBREAKPROC uixTextCtrl::GetWordBreakProc() const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return Edit_GetWordBreakProc(m_Handle);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixTextCtrl::HideBalloonTip()
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return Edit_HideBalloonTip(m_Handle);
}
//----------------------------------------------------------------------------//
UIXINLINE void uixTextCtrl::LimitText(UINT limit)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    Edit_LimitText(m_Handle, limit);
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixTextCtrl::LineFromChar(INT charID) const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (INT)Edit_LineFromChar(m_Handle, charID);
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixTextCtrl::LineIndex(INT lineID) const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (INT)Edit_LineIndex(m_Handle, lineID);
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixTextCtrl::LineLength(INT lineID) const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (INT)Edit_LineLength(m_Handle, lineID);
}
//----------------------------------------------------------------------------//
UIXINLINE void uixTextCtrl::ReplaceSelection(const uixChar* text)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    Edit_ReplaceSel(m_Handle, text);
}
//----------------------------------------------------------------------------//
UIXINLINE void uixTextCtrl::Scroll(INT dx, INT dy)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    Edit_Scroll(m_Handle, dx, dy);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixTextCtrl::ScrollCaret()
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (BOOL)Edit_ScrollCaret(m_Handle);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixTextCtrl::SetCueBannerText(const uixChar* text)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (BOOL)Edit_SetCueBannerText(m_Handle, text);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixTextCtrl::SetCueBannerTextFocused(const uixChar* text, BOOL drawFocused)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (BOOL)Edit_SetCueBannerTextFocused(m_Handle, text, drawFocused);
}
//----------------------------------------------------------------------------//
UIXINLINE void uixTextCtrl::SetTextHandle(HLOCAL handle)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    uixASSERT(handle != 0);
    Edit_SetHandle(m_Handle, handle);
}
//----------------------------------------------------------------------------//
UIXINLINE void uixTextCtrl::SetModify(BOOL modified)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    Edit_SetModify(m_Handle, modified);
}
//----------------------------------------------------------------------------//
UIXINLINE void uixTextCtrl::SetPasswordChar(UINT character)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    Edit_SetPasswordChar(m_Handle, character);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixTextCtrl::SetReadOnly(BOOL readOnly)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (BOOL)Edit_SetReadOnly(m_Handle, readOnly);
}
//----------------------------------------------------------------------------//
UIXINLINE void uixTextCtrl::SetFormatRect(RECT* rect)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    Edit_SetRect(m_Handle, rect);
}
//----------------------------------------------------------------------------//
UIXINLINE void uixTextCtrl::SetFormatRectNoPaint(RECT* rect)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    Edit_SetRectNoPaint(m_Handle, rect);
}
//----------------------------------------------------------------------------//
UIXINLINE void uixTextCtrl::SetSelection(INT start, INT stop)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    Edit_SetSel(m_Handle, start, stop);
}
//----------------------------------------------------------------------------//
UIXINLINE void uixTextCtrl::SetTabStops(INT tabs[], INT count)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    Edit_SetTabStops(m_Handle, count, tabs);
}
//----------------------------------------------------------------------------//
UIXINLINE void uixTextCtrl::SetWordBreakProc(EDITWORDBREAKPROC proc)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    Edit_SetWordBreakProc(m_Handle, proc);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixTextCtrl::ShowBalloonTip(EDITBALLOONTIP& params)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (BOOL)Edit_ShowBalloonTip(m_Handle, &params);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixTextCtrl::Undo()
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (BOOL)Edit_Undo(m_Handle);
}
//----------------------------------------------------------------------------//
}
//----------------------------------------------------------------------------//
#endif /* _UIX_TEXTCTRL_INL__ */