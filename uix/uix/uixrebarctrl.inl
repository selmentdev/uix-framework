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
#ifndef _UIX_REBARCTRL_INL__
#define _UIX_REBARCTRL_INL__
//----------------------------------------------------------------------------//
#include "uixrebarctrl.h"
//----------------------------------------------------------------------------//
namespace UIX
{
//----------------------------------------------------------------------------//
// uixRebarBandInfo
//----------------------------------------------------------------------------//
UIXINLINE uixRebarBandInfo::uixRebarBandInfo()
{
    cbSize = sizeof(uixRebarBandInfo);
    fMask = 0;
}
//----------------------------------------------------------------------------//
UIXINLINE uixRebarBandStyle uixRebarBandInfo::GetStyle() const
{
    if (fMask & RBBIM_STYLE)
    {
        return fStyle;
    }

    return 0;
}
//----------------------------------------------------------------------------//
UIXINLINE void uixRebarBandInfo::SetStyle(uixRebarBandStyle value)
{
    fMask |= RBBIM_STYLE;
    fStyle = value;
}
//----------------------------------------------------------------------------//
UIXINLINE uixColor uixRebarBandInfo::GetForegroundColor() const
{
    if (fMask & RBBIM_COLORS)
    {
        return clrFore;
    }

    return 0;
}
//----------------------------------------------------------------------------//
UIXINLINE void uixRebarBandInfo::SetForegroundColor(uixColor value)
{
    fMask |= RBBIM_COLORS;
    clrFore = value;
}
//----------------------------------------------------------------------------//
UIXINLINE uixColor uixRebarBandInfo::GetBackgroundColor() const
{
    if (fMask & RBBIM_COLORS)
    {
        return clrBack;
    }

    return 0;
}
//----------------------------------------------------------------------------//
UIXINLINE void uixRebarBandInfo::SetBackgroundColor(uixColor value)
{
    fMask |= RBBIM_COLORS;
    clrBack = value;
}
//----------------------------------------------------------------------------//
UIXINLINE const uixChar* uixRebarBandInfo::GetText() const
{
    if (fMask & RBBIM_TEXT)
    {
        return lpText;
    }

    return NULLPTR;
}
//----------------------------------------------------------------------------//
UIXINLINE void uixRebarBandInfo::SetText(const uixChar* value)
{
    fMask |= RBBIM_TEXT;
    lpText = (LPTSTR)value;
    cch = lstrlen(value);
}
//----------------------------------------------------------------------------//
UIXINLINE void uixRebarBandInfo::SetText(const uixChar* value, INT length)
{
    fMask |= RBBIM_TEXT;
    lpText = (LPTSTR)value;
    cch = length;
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixRebarBandInfo::GetTextLength() const
{
    if (fMask & RBBIM_TEXT)
    {
        return cch;
    }

    return 0;
}
//----------------------------------------------------------------------------//
UIXINLINE void uixRebarBandInfo::SetTextLength(INT length)
{
    cch = length;
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixRebarBandInfo::GetImage() const
{
    if (fMask & RBBIM_IMAGE)
    {
        return iImage;
    }

    return 0;
}
//----------------------------------------------------------------------------//
UIXINLINE void uixRebarBandInfo::SetImage(INT image)
{
    fMask |= RBBIM_IMAGE;
    iImage = image;
}
//----------------------------------------------------------------------------//
UIXINLINE HWND uixRebarBandInfo::GetChildWindow() const
{
    if (fMask & RBBIM_CHILD)
    {
        return hwndChild;
    }

    return 0;
}
//----------------------------------------------------------------------------//
UIXINLINE void uixRebarBandInfo::SetChildWindow(HWND handle)
{
    fMask |= RBBIM_CHILD;
    hwndChild = handle;
}
//----------------------------------------------------------------------------//
UIXINLINE void uixRebarBandInfo::GetMinChildSize(SIZE& size) const
{
    if (fMask & RBBIM_CHILDSIZE)
    {
        size.cx = cxMinChild;
        size.cy = cyMinChild;
    }
}
//----------------------------------------------------------------------------//
UIXINLINE void uixRebarBandInfo::SetMinChildSize(const SIZE& size)
{
    fMask |= RBBIM_CHILDSIZE;
    cxMinChild = size.cx;
    cyMinChild = size.cy;
}
//----------------------------------------------------------------------------//
UIXINLINE UINT uixRebarBandInfo::GetChildHeight() const
{
    if (fMask & RBBIM_CHILDSIZE)
    {
        return cyChild;
    }

    return 0;
}
//----------------------------------------------------------------------------//
UIXINLINE void uixRebarBandInfo::SetChildHeight(UINT height)
{
    fMask |= RBBIM_CHILDSIZE;
    cyChild = height;
}
//----------------------------------------------------------------------------//
UIXINLINE UINT uixRebarBandInfo::GetChildMaxHeight() const
{
    if (fMask & RBBIM_CHILDSIZE)
    {
        return cyMaxChild;
    }

    return 0;
}
//----------------------------------------------------------------------------//
UIXINLINE void uixRebarBandInfo::SetChildMaxHeight(UINT height)
{
    fMask |= RBBIM_CHILDSIZE;
    cyMaxChild = height;
}
//----------------------------------------------------------------------------//
UIXINLINE UINT uixRebarBandInfo::GetWidth() const
{
    if (fMask & RBBIM_SIZE)
    {
        return cx;
    }

    return 0;
}
//----------------------------------------------------------------------------//
UIXINLINE void uixRebarBandInfo::SetWidth(UINT width)
{
    fMask |= RBBIM_SIZE;
    cx = width;
}
//----------------------------------------------------------------------------//
UIXINLINE HBITMAP uixRebarBandInfo::GetBackgroundBitmap() const
{
    if (fMask & RBBIM_BACKGROUND)
    {
        return hbmBack;
    }

    return 0;
}
//----------------------------------------------------------------------------//
UIXINLINE void uixRebarBandInfo::SetBackgroundBitmap(HBITMAP handle)
{
    fMask |= RBBIM_BACKGROUND;
    hbmBack = handle;
}
//----------------------------------------------------------------------------//
UIXINLINE UINT uixRebarBandInfo::GetID() const
{
    if (fMask & RBBIM_ID)
    {
        return wID;
    }

    return 0;
}
//----------------------------------------------------------------------------//
UIXINLINE void uixRebarBandInfo::SetID(UINT value)
{
    fMask |= RBBIM_ID;
    wID = value;
}
//----------------------------------------------------------------------------//
UIXINLINE UINT uixRebarBandInfo::GetIdealSize() const
{
    if (fMask & RBBIM_IDEALSIZE)
    {
        return cxIdeal;
    }

    return 0;
}
//----------------------------------------------------------------------------//
UIXINLINE void uixRebarBandInfo::SetIdealSize(UINT size)
{
    fMask |= RBBIM_IDEALSIZE;
    cxIdeal = size;
}
//----------------------------------------------------------------------------//
UIXINLINE UINT uixRebarBandInfo::GetIntegralStep() const
{
    return cyIntegral;
}
//----------------------------------------------------------------------------//
UIXINLINE void uixRebarBandInfo::SetIntegralStep(UINT value)
{
    cyIntegral = value;
}
//----------------------------------------------------------------------------//
UIXINLINE void* uixRebarBandInfo::GetData() const
{
    if (fMask & RBBIM_LPARAM)
    {
        return (void*)lParam;
    }

    return NULLPTR;
}
//----------------------------------------------------------------------------//
UIXINLINE void uixRebarBandInfo::SetData(const void* value)
{
    fMask |= RBBIM_LPARAM;
    lParam = (LPARAM)value;
}
//----------------------------------------------------------------------------//
UIXINLINE UINT uixRebarBandInfo::GetHeaderSize() const
{
    if (fMask & RBBIM_HEADERSIZE)
    {
        return cxHeader;
    }

    return 0;
}
//----------------------------------------------------------------------------//
UIXINLINE void uixRebarBandInfo::SetHeaderSize(UINT value)
{
    fMask |= RBBIM_HEADERSIZE;
    cxHeader = value;
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixRebarBandInfo::GetChevronLocation(RECT& rect) const
{
    if (fMask & RBBIM_CHEVRONLOCATION)
    {
        rect = rcChevronLocation;
        return TRUE;
    }

    return FALSE;
}
//----------------------------------------------------------------------------//
UIXINLINE void uixRebarBandInfo::SetChevronLocation(const RECT& rect)
{
    fMask |= RBBIM_CHEVRONLOCATION;
    rcChevronLocation = rect;
}
//----------------------------------------------------------------------------//
UIXINLINE UINT uixRebarBandInfo::GetChevronState() const
{
    if (fMask & RBBIM_CHEVRONSTATE)
    {
        return uChevronState;
    }

    return 0;
}
//----------------------------------------------------------------------------//
UIXINLINE void uixRebarBandInfo::SetChevronState(UINT state)
{
    fMask |= RBBIM_CHEVRONSTATE;
    uChevronState = state;
}
//----------------------------------------------------------------------------//
// uixRebarInfo
//----------------------------------------------------------------------------//
UIXINLINE uixRebarInfo::uixRebarInfo()
{
    cbSize = sizeof(uixRebarInfo);
    fMask = 0;
}
//----------------------------------------------------------------------------//
UIXINLINE HIMAGELIST uixRebarInfo::GetImageList() const
{
    if (fMask & RBIM_IMAGELIST)
    {
        return himl;
    }

    return 0;
}
//----------------------------------------------------------------------------//
UIXINLINE void uixRebarInfo::SetImageList(HIMAGELIST handle)
{
    fMask |= RBIM_IMAGELIST;
    himl = handle;
}
//----------------------------------------------------------------------------//
// uixColorSheme
//----------------------------------------------------------------------------//
UIXINLINE uixColorSheme::uixColorSheme()
{
    dwSize = sizeof(uixColorSheme);
}
//----------------------------------------------------------------------------//
UIXINLINE uixColor uixColorSheme::GetHighlight() const
{
    return clrBtnHighlight;
}
//----------------------------------------------------------------------------//
UIXINLINE void uixColorSheme::SetHighlight(uixColor color)
{
    clrBtnHighlight = color;
}
//----------------------------------------------------------------------------//
UIXINLINE uixColor uixColorSheme::GetShadow() const
{
    return clrBtnShadow;
}
//----------------------------------------------------------------------------//
UIXINLINE void uixColorSheme::SetShadow(uixColor color)
{
    clrBtnShadow = color;
}
//----------------------------------------------------------------------------//
// uixRebarCtrl
//----------------------------------------------------------------------------//
UIXINLINE UINT uixRebarCtrl::GetBandCount() const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (UINT)SendMessage(RB_GETBANDCOUNT, 0, 0);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixRebarCtrl::GetBandInfo(UINT bandID, REBARBANDINFO& band) const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (BOOL)SendMessage(RB_GETBANDINFO, bandID, (LPARAM)&band);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixRebarCtrl::SetBandInfo(UINT bandID, const REBARBANDINFO& band)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (BOOL)SendMessage(RB_SETBANDINFO, bandID, (LPARAM)&band);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixRebarCtrl::GetBarInfo(REBARINFO& info) const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (BOOL)SendMessage(RB_GETBARINFO, 0, (LPARAM)&info);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixRebarCtrl::SetBarInfo(const REBARINFO& info)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (BOOL)SendMessage(RB_SETBARINFO, 0, (LPARAM)&info);
}
//----------------------------------------------------------------------------//
UIXINLINE UINT uixRebarCtrl::GetRowCount() const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (UINT)SendMessage(RB_GETROWCOUNT, 0, 0);
}
//----------------------------------------------------------------------------//
UIXINLINE UINT uixRebarCtrl::GetRowHeight(UINT bandID) const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (UINT)SendMessage(RB_GETROWHEIGHT, bandID, 0);
}
//----------------------------------------------------------------------------//
UIXINLINE uixColor uixRebarCtrl::GetTextColor() const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (uixColorRef)SendMessage(RB_GETTEXTCOLOR, 0, 0);
}
//----------------------------------------------------------------------------//
UIXINLINE uixColor uixRebarCtrl::SetTextColor(uixColor color)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (uixColorRef)SendMessage(RB_SETTEXTCOLOR, 0, (LPARAM)color);
}
//----------------------------------------------------------------------------//
UIXINLINE uixColor uixRebarCtrl::GetBackgroundColor() const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (uixColorRef)SendMessage(RB_GETBKCOLOR, 0, 0);
}
//----------------------------------------------------------------------------//
UIXINLINE uixColor uixRebarCtrl::SetBackgroundColor(uixColor color)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (uixColorRef)SendMessage(RB_SETBKCOLOR, 0, (LPARAM)color);
}
//----------------------------------------------------------------------------//
UIXINLINE UINT uixRebarCtrl::GetBarHeight() const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (UINT)SendMessage(RB_GETBARHEIGHT, 0, 0);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixRebarCtrl::GetRect(UINT bandID, RECT& rect) const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (BOOL)SendMessage(RB_GETRECT, bandID, (LPARAM)&rect);
}
//----------------------------------------------------------------------------//
UIXINLINE HWND uixRebarCtrl::GetToolTips() const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (HWND)SendMessage(RB_GETTOOLTIPS, 0, 0);
}
//----------------------------------------------------------------------------//
UIXINLINE void uixRebarCtrl::SetToolTips(HWND handle)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    SendMessage(RB_SETTOOLTIPS, (WPARAM)handle, 0);
}
//----------------------------------------------------------------------------//
UIXINLINE void uixRebarCtrl::GetBandBorders(UINT bandID, RECT& rect) const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    SendMessage(RB_GETBANDBORDERS, bandID, (LPARAM)&rect);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixRebarCtrl::GetColorScheme(COLORSCHEME& scheme) const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (BOOL)SendMessage(RB_GETCOLORSCHEME, 0, (LPARAM)&scheme);
}
//----------------------------------------------------------------------------//
UIXINLINE void uixRebarCtrl::SetColorScheme(const COLORSCHEME& scheme)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    SendMessage(RB_SETCOLORSCHEME, 0, (LPARAM)&scheme);
}
//----------------------------------------------------------------------------//
UIXINLINE HPALETTE uixRebarCtrl::GetPalette() const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (HPALETTE)SendMessage(RB_GETPALETTE, 0, 0);
}
//----------------------------------------------------------------------------//
UIXINLINE HPALETTE uixRebarCtrl::SetPalette(HPALETTE palette)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (HPALETTE)SendMessage(RB_SETPALETTE, 0, (LPARAM)palette);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixRebarCtrl::GetUnicodeFormat() const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (BOOL)SendMessage(RB_GETUNICODEFORMAT, 0, 0);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixRebarCtrl::SetUnicodeFormat(BOOL unicode)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (BOOL)SendMessage(RB_SETUNICODEFORMAT, unicode, 0);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixRebarCtrl::InsertBand(REBARBANDINFO& rbbi, INT bandID)
{
    //!@todo retype bandID to INT
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    rbbi.cbSize = sizeof(REBARBANDINFO);
    return (BOOL)SendMessage(RB_INSERTBAND, bandID, (LPARAM)&rbbi);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixRebarCtrl::DeleteBand(INT bandID)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (BOOL)SendMessage(RB_DELETEBAND, bandID, 0);
}
//----------------------------------------------------------------------------//
UIXINLINE HWND uixRebarCtrl::SetNotifyWindow(HWND window)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    uixASSERT(::IsWindow(window));
    return (HWND)SendMessage(RB_SETPARENT, (WPARAM)window, 0);
}
//----------------------------------------------------------------------------//
UIXINLINE void uixRebarCtrl::BeginDrag(INT bandID, DWORD position)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    SendMessage(RB_BEGINDRAG, bandID, position);
}
//----------------------------------------------------------------------------//
UIXINLINE void uixRebarCtrl::BeginDrag(INT bandID, INT x, INT y)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    SendMessage(RB_BEGINDRAG, bandID, MAKELPARAM(x, y));
}
//----------------------------------------------------------------------------//
UIXINLINE void uixRebarCtrl::BeginDrag(INT bandID, POINT pt)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    SendMessage(RB_BEGINDRAG, bandID, MAKELPARAM(pt.x, pt.y));
}
//----------------------------------------------------------------------------//
UIXINLINE void uixRebarCtrl::EndDrag()
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    SendMessage(RB_ENDDRAG, 0, 0);
}
//----------------------------------------------------------------------------//
UIXINLINE void uixRebarCtrl::DragMove(DWORD position)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    SendMessage(RB_DRAGMOVE, 0, position);
}
//----------------------------------------------------------------------------//
UIXINLINE void uixRebarCtrl::DragMove(INT x, INT y)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    SendMessage(RB_DRAGMOVE, 0, MAKELPARAM(x, y));
}
//----------------------------------------------------------------------------//
UIXINLINE void uixRebarCtrl::DragMove(POINT pt)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    SendMessage(RB_DRAGMOVE, 0, MAKELPARAM(pt.x, pt.y));
}
//----------------------------------------------------------------------------//
UIXINLINE void uixRebarCtrl::MaximizeBand(INT bandID)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    SendMessage(RB_MAXIMIZEBAND, bandID, 0);
}
//----------------------------------------------------------------------------//
UIXINLINE void uixRebarCtrl::MinimizeBand(INT bandID)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    SendMessage(RB_MINIMIZEBAND, bandID, 0);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixRebarCtrl::SizeToRect(RECT& rect)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (BOOL)SendMessage(RB_SIZETORECT, 0, (LPARAM)&rect);
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixRebarCtrl::BandIdToIndex(INT bandID)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (INT)SendMessage(RB_IDTOINDEX, bandID, 0);
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixRebarCtrl::HitTest(RBHITTESTINFO& info)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (INT)SendMessage(RB_HITTEST, 0, (LPARAM)&info);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixRebarCtrl::ShowBand(INT bandID, BOOL show)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (BOOL)SendMessage(RB_SHOWBAND, bandID, show);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixRebarCtrl::MoveBand(INT bandID, INT newPos)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    uixASSERT((0 <= newPos) && (newPos <= ((INT)GetBandCount() - 1)));
    return (BOOL)SendMessage(RB_MOVEBAND, bandID, newPos);
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixRebarCtrl::HandleToIndex(HWND handle)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    REBARBANDINFO rbbi;
    rbbi.cbSize = sizeof(rbbi);
    rbbi.fMask = RBBIM_CHILD | RBBIM_STYLE;
    INT count = GetBandCount();

    for (INT i = 0; i < count; ++i)
    {
        GetBandInfo(i, rbbi);

        if (rbbi.hwndChild == handle)
        {
            return i;
        }
    }

    return -1;
}
//----------------------------------------------------------------------------//
UIXINLINE void uixRebarCtrl::RecalcLayout()
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    SendMessage(WM_SIZE, 0, 0);
}
//----------------------------------------------------------------------------//
UIXINLINE void uixRebarCtrl::GetBandMargins(MARGINS& margins) const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    SendMessage(RB_GETBANDMARGINS, 0, (LPARAM)&margins);
}
//----------------------------------------------------------------------------//
UIXINLINE void uixRebarCtrl::GetDropTarget(IDropTarget** target) const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    SendMessage(RB_GETDROPTARGET, 0, (LPARAM)target);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixRebarCtrl::SetBandWidth(INT bandID, INT width)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    return (BOOL)SendMessage(RB_SETBANDWIDTH, bandID, width);
}
//----------------------------------------------------------------------------//
UIXINLINE void uixRebarCtrl::SetWindowTheme(const wchar_t* theme)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    SendMessage(RB_SETWINDOWTHEME, 0, (LPARAM)theme);
}
//----------------------------------------------------------------------------//
}
//----------------------------------------------------------------------------//
#endif /* _UIX_REBARCTRL_INL__ */