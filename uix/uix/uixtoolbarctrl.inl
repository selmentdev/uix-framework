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
#ifndef _UIX_TOOLBARCTRL_INL__
#define _UIX_TOOLBARCTRL_INL__
//----------------------------------------------------------------------------//
#include "uixtoolbarctrl.h"
#include "uixstate.h"
//----------------------------------------------------------------------------//
namespace UIX
{
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixToolBarCtrl::UpdateLayout()
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    SendMessage(WM_SIZE, 0, 0);

    return TRUE;
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixToolBarCtrl::IsButtonEnabled(UINT cmdID) const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    return (BOOL)SendMessage(TB_ISBUTTONENABLED, cmdID, 0);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixToolBarCtrl::IsButtonChecked(UINT cmdID) const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    return (BOOL)SendMessage(TB_ISBUTTONCHECKED, cmdID, 0);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixToolBarCtrl::IsButtonPressed(UINT cmdID) const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    return (BOOL)SendMessage(TB_ISBUTTONPRESSED, cmdID, 0);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixToolBarCtrl::IsButtonHidden(UINT cmdID) const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    return (BOOL)SendMessage(TB_ISBUTTONHIDDEN, cmdID, 0);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixToolBarCtrl::IsButtonIndeterminate(UINT cmdID) const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    return (BOOL)SendMessage(TB_ISBUTTONINDETERMINATE, cmdID, 0);
}
//----------------------------------------------------------------------------//
UIXINLINE UINT uixToolBarCtrl::GetState(UINT cmdID) const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    return (UINT)SendMessage(TB_GETSTATE, cmdID, 0);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixToolBarCtrl::SetState(UINT cmdID, UINT state)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    return (BOOL)SendMessage(TB_SETSTATE, cmdID, MAKELPARAM(state, 0));
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixToolBarCtrl::GetButton(INT buttonID, TBBUTTON& button) const
{
    return (BOOL)SendMessage(TB_GETBUTTON, buttonID, (LPARAM)&button);
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixToolBarCtrl::GetButtonCount() const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    return (INT)SendMessage(TB_BUTTONCOUNT, 0, 0);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixToolBarCtrl::GetItemRect(INT buttonID, RECT& rect) const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    return (BOOL)SendMessage(TB_GETITEMRECT, buttonID, (LPARAM)&rect);
}
//----------------------------------------------------------------------------//
UIXINLINE void uixToolBarCtrl::SetButtonStructSize(INT size)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    SendMessage(TB_BUTTONSTRUCTSIZE, size, 0);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixToolBarCtrl::SetButtonSize(SIZE size)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    return (BOOL)SendMessage(TB_SETBUTTONSIZE, 0, MAKELPARAM(size.cx, size.cy));
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixToolBarCtrl::SetButtonSize(INT cx, INT cy)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    return (BOOL)SendMessage(TB_SETBUTTONSIZE, 0, MAKELPARAM(cx, cy));
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixToolBarCtrl::SetBitmapSize(SIZE size)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    return (BOOL)SendMessage(TB_SETBITMAPSIZE, 0, MAKELPARAM(size.cx, size.cy));
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixToolBarCtrl::SetBitmapSize(INT cx, INT cy)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    return (BOOL)SendMessage(TB_SETBITMAPSIZE, 0, MAKELPARAM(cx, cy));
}
//----------------------------------------------------------------------------//
UIXINLINE HWND uixToolBarCtrl::GetToolTips() const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (HWND)SendMessage(TB_GETTOOLTIPS, 0, 0);
}
//----------------------------------------------------------------------------//
UIXINLINE void uixToolBarCtrl::SetToolTips(HWND handle)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    SendMessage(TB_SETTOOLTIPS, (WPARAM)handle, 0);
}
//----------------------------------------------------------------------------//
UIXINLINE void uixToolBarCtrl::SetNotifyWindow(HWND handle)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    SendMessage(TB_SETPARENT, (WPARAM)handle, 0);
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixToolBarCtrl::GetRows() const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (INT)SendMessage(TB_GETROWS, 0, 0);
}
//----------------------------------------------------------------------------//
UIXINLINE void uixToolBarCtrl::SetRows(INT rows, BOOL larger, const RECT& rect)
{
    SendMessage(TB_SETROWS, MAKEWPARAM(rows, larger), (LPARAM)&rect);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixToolBarCtrl::SetCmdID(INT index, UINT id)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    return (BOOL)SendMessage(TB_SETCMDID, index, id);
}
//----------------------------------------------------------------------------//
UIXINLINE DWORD uixToolBarCtrl::GetBitmapFlags() const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    return (DWORD)SendMessage(TB_GETBITMAPFLAGS, 0, 0);
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixToolBarCtrl::GetBitmap(UINT cmdID) const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    return (INT)SendMessage(TB_GETBITMAP, cmdID, 0);
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixToolBarCtrl::GetButtonText(UINT cmdID, uixChar* text) const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    return (INT)SendMessage(TB_GETBUTTONTEXT, cmdID, (LPARAM)text);
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixToolBarCtrl::GetButtonTextLength(UINT cmdID) const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    return (INT)SendMessage(TB_GETBUTTONTEXT, cmdID, 0);
}
//----------------------------------------------------------------------------//
UIXINLINE HIMAGELIST uixToolBarCtrl::GetImageList() const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    return (HIMAGELIST)SendMessage(TB_GETIMAGELIST, 0, 0);
}
//----------------------------------------------------------------------------//
UIXINLINE HIMAGELIST uixToolBarCtrl::SetImageList(HIMAGELIST handle)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    return (HIMAGELIST)SendMessage(TB_SETIMAGELIST, 0, (LPARAM)handle);
}
//----------------------------------------------------------------------------//
UIXINLINE HIMAGELIST uixToolBarCtrl::GetDisabledImageList() const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    return (HIMAGELIST)SendMessage(TB_GETDISABLEDIMAGELIST, 0, 0);
}
//----------------------------------------------------------------------------//
UIXINLINE HIMAGELIST uixToolBarCtrl::SetDisabledImageList(HIMAGELIST handle)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    return (HIMAGELIST)SendMessage(TB_SETDISABLEDIMAGELIST, 0, (LPARAM)handle);
}
//----------------------------------------------------------------------------//
UIXINLINE HIMAGELIST uixToolBarCtrl::GetHotImageList() const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    return (HIMAGELIST)SendMessage(TB_GETHOTIMAGELIST, 0, 0);
}
//----------------------------------------------------------------------------//
UIXINLINE HIMAGELIST uixToolBarCtrl::SetHotImageList(HIMAGELIST handle)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    return (HIMAGELIST)SendMessage(TB_GETHOTIMAGELIST, 0, (LPARAM)handle);
}
//----------------------------------------------------------------------------//
UIXINLINE DWORD uixToolBarCtrl::GetStyle() const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    return (DWORD)SendMessage(TB_GETSTYLE, 0, 0);
}
//----------------------------------------------------------------------------//
UIXINLINE void uixToolBarCtrl::SetStyle(DWORD style)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    SendMessage(TB_SETSTYLE, 0, style);
}
//----------------------------------------------------------------------------//
UIXINLINE DWORD uixToolBarCtrl::GetButtonSize() const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    return (DWORD)SendMessage(TB_GETBUTTONSIZE, 0, 0);
}
//----------------------------------------------------------------------------//
UIXINLINE void uixToolBarCtrl::GetButtonSize(SIZE& size) const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    DWORD r = GetButtonSize();
    size.cx = LOWORD(r);
    size.cy = HIWORD(r);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixToolBarCtrl::GetButtonRect(UINT cmdID, RECT& rect) const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    return (BOOL)SendMessage(TB_GETRECT, cmdID, (LPARAM)&rect);
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixToolBarCtrl::GetTextRows() const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    return (INT)SendMessage(TB_GETTEXTROWS, 0, 0);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixToolBarCtrl::SetButtonWidth(INT min, INT max)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    return (BOOL)SendMessage(TB_SETBUTTONWIDTH, 0, MAKELPARAM(min, max));
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixToolBarCtrl::SetIndent(INT indent)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    return (BOOL)SendMessage(TB_SETINDENT, indent, 0);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixToolBarCtrl::SetMaxTextRows(INT max)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    return (BOOL)SendMessage(TB_SETMAXTEXTROWS, max, 0);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixToolBarCtrl::GetAnchorHighlight() const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    return (BOOL)SendMessage(TB_GETANCHORHIGHLIGHT, 0, 0);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixToolBarCtrl::GetButtonInfo(INT buttonID, UINT& cmdID, UINT& style,
        INT& image) const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    TBBUTTON button;
    BOOL result = GetButton(buttonID, button);
    cmdID = button.idCommand;
    style = MAKELONG(button.fsStyle, button.fsState);
    image = button.iBitmap;

    return result;
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixToolBarCtrl::GetButtonInfo(UINT cmdID, TBBUTTONINFO& tbbi) const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    return (INT)SendMessage(TB_GETBUTTONINFO, cmdID, (LPARAM)&tbbi);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixToolBarCtrl::SetButtonInfo(UINT cmdID, const TBBUTTONINFO& tbbi)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    return (BOOL)SendMessage(TB_SETBUTTONINFO, cmdID, (LPARAM)&tbbi);
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixToolBarCtrl::GetHotItem() const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    return (INT)SendMessage(TB_GETHOTITEM, 0, 0);
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixToolBarCtrl::SetHotItem(INT buttonID)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    return (INT)SendMessage(TB_SETHOTITEM, buttonID, 0);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixToolBarCtrl::IsButtonHighlighted(INT buttonID) const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (BOOL)SendMessage(TB_ISBUTTONHIGHLIGHTED, buttonID, 0);
}
//----------------------------------------------------------------------------//
UIXINLINE DWORD uixToolBarCtrl::SetDrawTextFlags(DWORD mask, DWORD flags)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    return (DWORD)SendMessage(TB_SETDRAWTEXTFLAGS, mask, flags);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixToolBarCtrl::GetColorScheme(COLORSCHEME& cs) const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    return (BOOL)SendMessage(TB_GETCOLORSCHEME, 0, (LPARAM)&cs);
}
//----------------------------------------------------------------------------//
UIXINLINE void uixToolBarCtrl::SetColorScheme(const COLORSCHEME& cs)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    SendMessage(TB_SETCOLORSCHEME, 0, (LPARAM)&cs);
}
//----------------------------------------------------------------------------//
UIXINLINE DWORD uixToolBarCtrl::GetControlStyle() const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    return (DWORD)SendMessage(TB_GETEXTENDEDSTYLE, 0, 0);
}
//----------------------------------------------------------------------------//
UIXINLINE DWORD uixToolBarCtrl::SetControlStyle(DWORD style)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    return (DWORD)SendMessage(TB_SETEXTENDEDSTYLE, 0, style);
}
//----------------------------------------------------------------------------//
UIXINLINE void uixToolBarCtrl::GetInsertMark(TBINSERTMARK& tbim) const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    SendMessage(TB_GETINSERTMARK, 0, (LPARAM)&tbim);
}
//----------------------------------------------------------------------------//
UIXINLINE void uixToolBarCtrl::SetInsertMark(const TBINSERTMARK& tbim)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    SendMessage(TB_SETINSERTMARK, 0, (LPARAM)&tbim);
}
//----------------------------------------------------------------------------//
UIXINLINE uixColor uixToolBarCtrl::GetInsertMarkColor() const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    return (uixColorRef)SendMessage(TB_GETINSERTMARKCOLOR, 0, 0);
}
//----------------------------------------------------------------------------//
UIXINLINE uixColor uixToolBarCtrl::SetInsertMarkColor(uixColor color)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    return (uixColorRef)SendMessage(TB_SETINSERTMARKCOLOR, 0, (LPARAM)color);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixToolBarCtrl::GetMaxSize(SIZE& size) const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    return (BOOL)SendMessage(TB_GETMAXSIZE, 0, (LPARAM)&size);
}
//----------------------------------------------------------------------------//
UIXINLINE void uixToolBarCtrl::GetPadding(SIZE& size) const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    DWORD result = (DWORD)SendMessage(TB_GETPADDING, 0, 0);
    size.cx = LOWORD(result);
    size.cy = HIWORD(result);
}
//----------------------------------------------------------------------------//
UIXINLINE void uixToolBarCtrl::SetPadding(INT cx, INT cy, SIZE* previous)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    DWORD result = (DWORD)SendMessage(TB_SETPADDING, 0, MAKELPARAM(cx, cy));

    if (previous != NULLPTR)
    {
        previous->cx = LOWORD(result);
        previous->cy = HIWORD(result);
    }
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixToolBarCtrl::GetUnicodeFormat() const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    return (BOOL)SendMessage(TB_GETUNICODEFORMAT, 0, 0);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixToolBarCtrl::SetUnicodeFormat(BOOL unicode)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    return (BOOL)SendMessage(TB_SETUNICODEFORMAT, unicode, 0);
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixToolBarCtrl::GetString(INT index, uixChar* text, INT maxLength) const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    return (INT)SendMessage(TB_GETSTRING, MAKEWPARAM(maxLength, index), (LPARAM)text);
}
//----------------------------------------------------------------------------//
UIXINLINE void uixToolBarCtrl::GetMetrics(TBMETRICS& tbm) const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    SendMessage(TB_GETMETRICS, 0, (LPARAM)&tbm);
}
//----------------------------------------------------------------------------//
UIXINLINE void uixToolBarCtrl::SetMetrics(const TBMETRICS& tbm)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    SendMessage(TB_SETMETRICS, 0, (LPARAM)&tbm);
}
//----------------------------------------------------------------------------//
UIXINLINE void uixToolBarCtrl::SetWindowTheme(const uixChar* themeName)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    SendMessage(TB_SETWINDOWTHEME, 0, (LPARAM)themeName);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixToolBarCtrl::EnableButton(UINT cmdID, BOOL enable)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    return (BOOL)SendMessage(TB_ENABLEBUTTON, cmdID, MAKELPARAM(enable, 0));
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixToolBarCtrl::CheckButton(UINT cmdID, BOOL check)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    return (BOOL)SendMessage(TB_CHECKBUTTON, cmdID, MAKELPARAM(check, 0));
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixToolBarCtrl::PressButton(UINT cmdID, BOOL press)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    return (BOOL)SendMessage(TB_PRESSBUTTON, cmdID, MAKELPARAM(press, 0));
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixToolBarCtrl::HideButton(UINT cmdID, BOOL hide)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    return (BOOL)SendMessage(TB_HIDEBUTTON, cmdID, MAKELPARAM(hide, 0));
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixToolBarCtrl::Indeterminate(UINT cmdID, BOOL indeterminate)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    return (BOOL)SendMessage(TB_INDETERMINATE, cmdID, MAKELPARAM(indeterminate, 0));
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixToolBarCtrl::AddBitmap(INT buttonCount, HBITMAP bitmap)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    TBADDBITMAP tbab;
    tbab.hInst = 0;
    tbab.nID = (UINT_PTR)bitmap;
    return (INT)SendMessage(TB_ADDBITMAP, (WPARAM)buttonCount, (LPARAM)&tbab);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixToolBarCtrl::AddButtons(const TBBUTTON buttons[], INT count)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    return (BOOL)SendMessage(TB_ADDBUTTONS, count, (LPARAM)&buttons[0]);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixToolBarCtrl::InsertButton(INT buttonID, const TBBUTTON& button)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    return (BOOL)SendMessage(TB_INSERTBUTTON, buttonID, (LPARAM)&button);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixToolBarCtrl::DeleteButton(INT buttonID)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    return (BOOL)SendMessage(TB_DELETEBUTTON, buttonID, 0);
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixToolBarCtrl::CommandToIndex(UINT cmdID) const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    return (INT)SendMessage(TB_COMMANDTOINDEX, cmdID, 0);
}
//----------------------------------------------------------------------------//
UIXINLINE void uixToolBarCtrl::Customize()
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    SendMessage(TB_CUSTOMIZE, 0, 0);
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixToolBarCtrl::AddStringRes(uixResourceID stringID)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    return AddStringRes(
               UixFindResourceHandle(stringID, RT_STRING),
               stringID);
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixToolBarCtrl::AddStringRes(uixResourceName resource)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    return AddStringRes(
               UixFindResourceHandle(resource, RT_STRING),
               resource);
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixToolBarCtrl::AddStringRes(HINSTANCE instance, uixResourceID stringID)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    return (INT)SendMessage(TB_ADDSTRING, (WPARAM)instance, (LPARAM)stringID);
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixToolBarCtrl::AddStringRes(HINSTANCE instance, uixResourceName resource)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    return (INT)SendMessage(TB_ADDSTRING, (WPARAM)instance, (LPARAM)resource);
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixToolBarCtrl::AddString(const uixChar* text)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    return (INT)SendMessage(TB_ADDSTRING, 0, (LPARAM)text);
}
//----------------------------------------------------------------------------//
UIXINLINE void uixToolBarCtrl::RecalcLayout()
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    SendMessage(TB_AUTOSIZE, 0, 0);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixToolBarCtrl::ChangeBitmap(UINT cmdID, INT bitmapIndex)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    return (BOOL)SendMessage(TB_CHANGEBITMAP, cmdID, MAKELPARAM(bitmapIndex, 0));
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixToolBarCtrl::LoadImagesStd(uixResourceID resourceID)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    return (INT)SendMessage(TB_LOADIMAGES, (WPARAM)resourceID, (LPARAM)HINST_COMMCTRL);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixToolBarCtrl::ReplaceBitmap(const TBREPLACEBITMAP& tbrb)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    return (BOOL)SendMessage(TB_REPLACEBITMAP, 0, (LPARAM)&tbrb);
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixToolBarCtrl::HitTest(const POINT& point)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    return (BOOL)SendMessage(TB_HITTEST, 0, (LPARAM)&point);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixToolBarCtrl::InsertMarkHitTest(INT x, INT y, TBINSERTMARK& tbim)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    POINT pt = {x, y};

    return (BOOL)SendMessage(TB_INSERTMARKHITTEST, (WPARAM)&pt, (LPARAM)&tbim);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixToolBarCtrl::InsertMarkHitTest(POINT pt, TBINSERTMARK& tbim)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (BOOL)SendMessage(TB_INSERTMARKHITTEST, (WPARAM)&pt, (LPARAM)&tbim);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixToolBarCtrl::MapAccelerator(TCHAR accel, UINT& id)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    return (BOOL)SendMessage(TB_MAPACCELERATOR, accel, (LPARAM)&id);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixToolBarCtrl::MarkButton(UINT cmdID, BOOL highlight)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    return (BOOL)SendMessage(TB_MARKBUTTON, cmdID, MAKELPARAM(highlight, 0));
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixToolBarCtrl::MoveButton(INT buttonID, INT newButtonID)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    return (BOOL)SendMessage(TB_MOVEBUTTON, buttonID, newButtonID);
}
//----------------------------------------------------------------------------//
}
//----------------------------------------------------------------------------//
#endif /* _UIX_TOOLBARCTRL_INL__ */