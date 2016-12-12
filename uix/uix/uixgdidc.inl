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
#ifndef _UIX_GDIDC_INL__
#define _UIX_GDIDC_INL__
//----------------------------------------------------------------------------//
#include "uixexception.h"
//----------------------------------------------------------------------------//
namespace UIX
{
//----------------------------------------------------------------------------//
UIXINLINE uixDC::uixDC(HDC handle)
    : m_Handle(handle)
{
}
//----------------------------------------------------------------------------//
UIXINLINE uixDC::operator HDC () const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);
    return m_Handle;
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixDC::IsValid() const
{
    uixASSERT(this != NULLPTR);
    return m_Handle != 0;
}
//----------------------------------------------------------------------------//
UIXINLINE HDC uixDC::GetHandle() const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);
    return m_Handle;
}
//----------------------------------------------------------------------------//
UIXINLINE HDC uixDC::GetHandleSafe() const
{
    uixASSERT(this != NULLPTR);

    if (this != NULLPTR)
    {
        return m_Handle;
    }

    return 0;
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixDC::Save()
{
    uixASSERT(this != NULLPTR);

    if (m_Handle != 0)
    {
        return ::SaveDC(m_Handle);
    }

    return 0;
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixDC::Restore(INT saved)
{
    uixASSERT(this != NULLPTR);

    if (m_Handle != 0)
    {
        return ::RestoreDC(m_Handle, saved);
    }

    return FALSE;
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixDC::GetDeviceCaps(INT index)
{
    uixASSERT(this != NULLPTR);

    if (m_Handle != 0)
    {
        return ::GetDeviceCaps(m_Handle, index);
    }

    return 0;
}
//----------------------------------------------------------------------------//
UIXINLINE uixColor uixDC::GetNearestColor(uixColor color)
{
    uixASSERT(this != NULLPTR);

    if (IsValid())
    {
        return ::GetNearestColor(m_Handle, color);
    }

    return 0;
}
//----------------------------------------------------------------------------//
UIXINLINE uixDCBounds uixDC::SetBoundsRect(const uixRect* rect, uixDCBounds flags)
{
    uixASSERT(this != NULLPTR);

    if (IsValid())
    {
        return (uixDCBounds)::SetBoundsRect(m_Handle, rect, flags);
    }

    return uixDCBounds_None;
}
//----------------------------------------------------------------------------//
UIXINLINE uixDCBounds uixDC::GetBoundsRect(uixRect& rect, uixDCBounds flags)
{
    uixASSERT(this != NULLPTR);

    if (IsValid())
    {
        return (uixDCBounds)::GetBoundsRect(m_Handle, &rect, flags);
    }

    return uixDCBounds_None;
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixDC::Reset(DEVMODE* mode)
{
    uixASSERT(this != NULLPTR);

    if (IsValid())
    {
        return ::ResetDC(m_Handle, mode) != 0;
    }

    return FALSE;
}
//----------------------------------------------------------------------------//
UIXINLINE HGDIOBJ uixDC::Select(HGDIOBJ object)
{
    uixASSERT(this != NULLPTR);

    if (IsValid())
    {
        return ::SelectObject(m_Handle, object);
    }

    return 0;
}
//----------------------------------------------------------------------------//
UIXINLINE HFONT uixDC::Select(HFONT font)
{
    uixASSERT(this != NULLPTR);
    return (HFONT)Select((HGDIOBJ)font);
}
//----------------------------------------------------------------------------//
UIXINLINE HPEN uixDC::Select(HPEN pen)
{
    uixASSERT(this != NULLPTR);
    return (HPEN)Select((HGDIOBJ)pen);
}
//----------------------------------------------------------------------------//
UIXINLINE HBRUSH uixDC::Select(HBRUSH brush)
{
    uixASSERT(this != NULLPTR);
    return (HBRUSH)Select((HGDIOBJ)brush);
}
//----------------------------------------------------------------------------//
UIXINLINE HBITMAP uixDC::Select(HBITMAP bitmap)
{
    uixASSERT(this != NULLPTR);
    return (HBITMAP)Select((HGDIOBJ)bitmap);
}
//----------------------------------------------------------------------------//
UIXINLINE HGDIOBJ uixDC::SelectStock(INT index)
{
    uixASSERT(this != NULLPTR);

    if (IsValid())
    {
        return ::SelectObject(m_Handle, ::GetStockObject(index));
    }

    return 0;
}
//----------------------------------------------------------------------------//
UIXINLINE HFONT uixDC::SelectStockFont(INT index)
{
    uixASSERT(this != NULLPTR);
    return (HFONT)SelectStock(index);
}
//----------------------------------------------------------------------------//
UIXINLINE HPEN uixDC::SelectStockPen(INT index)
{
    uixASSERT(this != NULLPTR);
    return (HPEN)SelectStock(index);
}
//----------------------------------------------------------------------------//
UIXINLINE HBRUSH uixDC::SelectStockBrush(INT index)
{
    uixASSERT(this != NULLPTR);
    return (HBRUSH)SelectStock(index);
}
//----------------------------------------------------------------------------//
UIXINLINE HBITMAP uixDC::SelectStockBitmap(INT index)
{
    uixASSERT(this != NULLPTR);
    return (HBITMAP)SelectStock(index);
}
//----------------------------------------------------------------------------//
UIXINLINE HWND uixDC::FromDC()
{
    uixASSERT(this != NULLPTR);

    if (IsValid())
    {
        return ::WindowFromDC(m_Handle);
    }

    return 0;
}
//----------------------------------------------------------------------------//
UIXINLINE HPEN uixDC::GetCurrentPen() const
{
    uixASSERT(this != NULLPTR);

    if (IsValid())
    {
        return (HPEN)::GetCurrentObject(m_Handle, OBJ_PEN);
    }

    return 0;
}
//----------------------------------------------------------------------------//
UIXINLINE HBRUSH uixDC::GetCurrentBrush() const
{
    uixASSERT(this != NULLPTR);

    if (IsValid())
    {
        return (HBRUSH)::GetCurrentObject(m_Handle, OBJ_BRUSH);
    }

    return 0;
}
//----------------------------------------------------------------------------//
UIXINLINE HFONT uixDC::GetCurrentFont() const
{
    uixASSERT(this != NULLPTR);

    if (IsValid())
    {
        return (HFONT)::GetCurrentObject(m_Handle, OBJ_FONT);
    }

    return 0;
}
//----------------------------------------------------------------------------//
UIXINLINE HBITMAP uixDC::GetCurrentBitmap() const
{
    uixASSERT(this != NULLPTR);

    if (IsValid())
    {
        return (HBITMAP)::GetCurrentObject(m_Handle, OBJ_BITMAP);
    }

    return 0;
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixDC::Create(LPCTSTR driverName, LPCTSTR deviceName, LPCTSTR output,
                             DEVMODE* initData)
{
    uixASSERT(this != NULLPTR);

    if (!IsValid())
    {
        m_Handle = ::CreateDC(driverName, deviceName, output, initData);
    }

    return IsValid();
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixDC::CreateCompatible(HDC dc)
{
    uixASSERT(this != NULLPTR);

    if (!IsValid())
    {
        m_Handle = ::CreateCompatibleDC(dc);
    }

    return IsValid();
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixDC::Destroy()
{
    uixASSERT(this != NULLPTR);

    if (IsValid())
    {
        BOOL result = ::DeleteDC(m_Handle);

        if (result)
        {
            m_Handle = 0;
        }

        return result;
    }

    return FALSE;
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixDC::UpdateColors()
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);
    return ::UpdateColors(m_Handle);
}
//----------------------------------------------------------------------------//
UIXINLINE uixColor uixDC::GetBackgroundColor() const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);
    return (uixColor)::GetBkColor(m_Handle);
}
//----------------------------------------------------------------------------//
UIXINLINE uixDCBackgroundMode uixDC::GetBackgroundMode() const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);
    return (uixDCBackgroundMode)::GetBkMode(m_Handle);
}
//----------------------------------------------------------------------------//
UIXINLINE uixDCPolyFillMode uixDC::GetPolyFillMode() const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);
    return (uixDCPolyFillMode)::GetPolyFillMode(m_Handle);
}
//----------------------------------------------------------------------------//
UIXINLINE uixDCRop2 uixDC::GetROP2() const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);
    return (uixDCRop2)::GetROP2(m_Handle);
}
//----------------------------------------------------------------------------//
UIXINLINE uixDCStretchMode uixDC::GetStretchBltMode()
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);
    return (uixDCStretchMode)::GetStretchBltMode(m_Handle);
}
//----------------------------------------------------------------------------//
UIXINLINE uixColor uixDC::GetTextColor() const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);
    return (uixColor)::GetTextColor(m_Handle);
}
//----------------------------------------------------------------------------//
UIXINLINE uixColor uixDC::SetBackgroundColor(uixColor color)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);
    return (uixColor)::SetBkColor(m_Handle, color);
}
//----------------------------------------------------------------------------//
UIXINLINE uixDCBackgroundMode uixDC::SetBackgroundMode(uixDCBackgroundMode mode)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);
    return (uixDCBackgroundMode)::SetBkMode(m_Handle, mode);
}
//----------------------------------------------------------------------------//
UIXINLINE uixDCPolyFillMode uixDC::SetPolyFillMode(uixDCPolyFillMode mode)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);
    return (uixDCPolyFillMode)::SetPolyFillMode(m_Handle, mode);
}
//----------------------------------------------------------------------------//
UIXINLINE uixDCRop2 uixDC::SetROP2(uixDCRop2 mode)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);
    return (uixDCRop2)::SetROP2(m_Handle, mode);
}
//----------------------------------------------------------------------------//
UIXINLINE uixDCStretchMode uixDC::SetStretchBltMode(uixDCStretchMode mode)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);
    return (uixDCStretchMode)::SetStretchBltMode(m_Handle, mode);
}
//----------------------------------------------------------------------------//
UIXINLINE uixColor uixDC::SetTextColor(uixColor color)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);
    return ::SetTextColor(m_Handle, color);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixDC::GetColorAdjustment(COLORADJUSTMENT& params)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);
    return ::GetColorAdjustment(m_Handle, &params);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixDC::SetColorAdjustment(const COLORADJUSTMENT& params)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);
    return ::SetColorAdjustment(m_Handle, &params);
}
//----------------------------------------------------------------------------//
UIXINLINE uixDCMapMode uixDC::GetMapMode() const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);
    return (uixDCMapMode)::GetMapMode(m_Handle);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixDC::GetViewportOrg(uixPoint& point) const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);
    return ::GetViewportOrgEx(m_Handle, &point);
}
//----------------------------------------------------------------------------//
UIXINLINE uixDCMapMode uixDC::SetMapMode(uixDCMapMode mode)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);
    return (uixDCMapMode)::SetMapMode(m_Handle, mode);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixDC::SetViewportOrg(INT x, INT y, uixPoint* point)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);
    return ::SetViewportOrgEx(m_Handle, x, y, point);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixDC::SetViewportOrg(uixPoint point, uixPoint* ret)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);
    return ::SetViewportOrgEx(m_Handle, point.x, point.y, ret);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixDC::OffsetViewportOrg(INT width, INT height, uixPoint* ret)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);
    return ::OffsetViewportOrgEx(m_Handle, width, height, ret);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixDC::GetViewportExt(uixSize& size) const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);
    return ::GetViewportExtEx(m_Handle, &size);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixDC::SetViewportExt(INT x, INT y, uixSize* size)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);
    return ::SetViewportExtEx(m_Handle, x, y, size);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixDC::SetViewportExt(uixSize size, uixSize* ret)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);
    return ::SetViewportExtEx(m_Handle, size.cx, size.cy, ret);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixDC::ScaleViewportExt(INT xNum, INT xDenom, INT yNum, INT yDenom, uixSize* result)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);
    return ::ScaleViewportExtEx(m_Handle, xNum, xDenom, yNum, yDenom, result);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixDC::GetWindowOrg(uixPoint& point) const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);
    return ::GetWindowOrgEx(m_Handle, &point);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixDC::SetWindowOrg(INT x, INT y, uixPoint* result)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);
    return ::SetWindowOrgEx(m_Handle, x, y, result);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixDC::SetWindowOrg(uixPoint point, uixPoint* result)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);
    return ::SetWindowOrgEx(m_Handle, point.x, point.y, result);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixDC::OffsetWindowOrg(INT width, INT height, uixPoint* result)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);
    return ::OffsetWindowOrgEx(m_Handle, width, height, result);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixDC::GetWindowExt(uixSize& size) const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);
    return ::GetWindowExtEx(m_Handle, &size);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixDC::SetWindowExt(INT x, INT y, uixSize* result)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);
    return ::SetWindowExtEx(m_Handle, x, y, result);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixDC::SetWindowExt(uixSize size, uixSize* result)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);
    return ::SetWindowExtEx(m_Handle, size.cx, size.cy, result);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixDC::ScaleWindowExt(INT xNum, INT xDenom, INT yNum, INT yDenom, uixSize* result)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);
    return ::ScaleWindowExtEx(m_Handle, xNum, xDenom, yNum, yDenom, result);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixDC::ToLogicalUnits(uixPoint points[], INT count)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);
    return ::DPtoLP(m_Handle, points, count);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixDC::ToLogicalUnits(uixPoint& point)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);
    return ::DPtoLP(m_Handle, &point, 1);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixDC::ToLogicalUnits(uixSize points[], INT count)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);
    return ::DPtoLP(m_Handle, (uixPoint*)points, count);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixDC::ToLogicalUnits(uixSize& point)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);
    return ::DPtoLP(m_Handle, (uixPoint*)&point, 1);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixDC::ToLogicalUnits(uixRect points[], INT count)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);
    return ::DPtoLP(m_Handle, (uixPoint*)points, count * 2);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixDC::ToLogicalUnits(uixRect& point)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);
    return ::DPtoLP(m_Handle, (uixPoint*)&point, 2);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixDC::ToDeviceUnits(uixPoint points[], INT count)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);
    return ::LPtoDP(m_Handle, points, count);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixDC::ToDeviceUnits(uixPoint& point)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);
    return ::LPtoDP(m_Handle, &point, 1);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixDC::ToDeviceUnits(uixSize points[], INT count)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);
    return ::LPtoDP(m_Handle, (uixPoint*)points, count);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixDC::ToDeviceUnits(uixSize& point)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);
    return ::LPtoDP(m_Handle, (uixPoint*)&point, 1);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixDC::ToDeviceUnits(uixRect points[], INT count)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);
    return ::LPtoDP(m_Handle, (uixPoint*)points, count * 2);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixDC::ToDeviceUnits(uixRect& point)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);
    return ::LPtoDP(m_Handle, (uixPoint*)&point, 2);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixDC::FillRegion(HRGN region, HBRUSH brush)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);
    return ::FillRgn(m_Handle, region, brush);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixDC::FrameRegion(HRGN region, HBRUSH brush, INT width, INT height)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);
    return ::FrameRgn(m_Handle, region, brush, width, height);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixDC::InvertRegion(HRGN region)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);
    return ::InvertRgn(m_Handle, region);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixDC::PaintRegion(HRGN region)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);
    return ::PaintRgn(m_Handle, region);
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixDC::GetClipBox(uixRect& rect) const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);
    return ::GetClipBox(m_Handle, &rect);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixDC::IsPointVisible(INT x, INT y)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);
    return ::PtVisible(m_Handle, x, y);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixDC::IsPointVisible(uixPoint point)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);
    return ::PtVisible(m_Handle, point.x, point.y);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixDC::IsRectVisible(const uixRect& rect)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);
    return ::RectVisible(m_Handle, &rect);
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixDC::SetClipRegion(HRGN region)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);
    return ::SelectClipRgn(m_Handle, region);
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixDC::ExcludeClipRect(INT left, INT top, INT right, INT bottom)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);
    return ::ExcludeClipRect(m_Handle, left, top, right, bottom);
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixDC::ExcludeClipRect(const uixRect& rect)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);
    return ::ExcludeClipRect(m_Handle, rect.left, rect.top, rect.right, rect.bottom);
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixDC::ExcludeUpdateRegion(HWND window)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);
    uixASSERT(window != 0);
    ::ExcludeUpdateRgn(m_Handle, window);
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixDC::IntersectClipRect(INT left, INT top, INT right, INT bottom)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);
    return ::IntersectClipRect(m_Handle, left, top, right, bottom);
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixDC::IntersectClipRect(const uixRect& rect)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);
    return ::IntersectClipRect(m_Handle, rect.left, rect.top, rect.right, rect.bottom);
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixDC::OffsetClipRegion(INT x, INT y)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);
    return ::OffsetClipRgn(m_Handle, x, y);
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixDC::OffsetClipRegion(uixSize size)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);
    return ::OffsetClipRgn(m_Handle, size.cx, size.cy);
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixDC::SelectClipRegion(HRGN region, uixRegionMode mode)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);
    return ::ExtSelectClipRgn(m_Handle, region, mode);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixDC::GetCurrentPosition(uixPoint& position)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);
    return ::GetCurrentPositionEx(m_Handle, &position);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixDC::MoveTo(INT x, INT y, uixPoint* result)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);
    return ::MoveToEx(m_Handle, x, y, result);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixDC::MoveTo(uixPoint point, uixPoint* result)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);
    return ::MoveToEx(m_Handle, point.x, point.y, result);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixDC::LineTo(INT x, INT y)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);
    return ::LineTo(m_Handle, x, y);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixDC::LineTo(uixPoint point)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);
    return ::LineTo(m_Handle, point.x, point.y);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixDC::DrawLine(uixPoint source, uixPoint target)
{
    uixASSERT(this != NULLPTR);

    if (m_Handle != 0)
    {
        MoveTo(source);
        LineTo(target);
        return TRUE;
    }

    return FALSE;
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixDC::DrawLine(uixPoint source, uixPoint target, uixColor color)
{
    uixASSERT(this != NULLPTR);

    if (m_Handle != 0)
    {
        throw uixNotSupportedException();
        return TRUE;
    }

    return FALSE;
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixDC::FillSolidRect(const uixRect& rect, uixColor color)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);

    uixColor previous = ::SetBkColor(m_Handle, color);
    uixASSERT(previous != CLR_INVALID);

    if (previous != CLR_INVALID)
    {
        BOOL result = ::ExtTextOut(m_Handle, 0, 0, ETO_OPAQUE, &rect, NULLPTR, 0, NULLPTR);
        ::SetBkColor(m_Handle, previous);
        return result;
    }

    return FALSE;
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixDC::FillSolidRect(INT left, INT top, INT width, INT height, uixColor color)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);

    uixColor previous = ::SetBkColor(m_Handle, color);
    uixASSERT(previous != CLR_INVALID);

    if (previous != CLR_INVALID)
    {
        uixRect rect(left, top, left + width, top + height);
        BOOL result = ::ExtTextOut(m_Handle, 0, 0, ETO_OPAQUE, &rect, NULLPTR, 0, NULLPTR);
        ::SetBkColor(m_Handle, previous);
        return result;
    }

    return FALSE;
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixDC::GradientFill(TRIVERTEX* vertices, ULONG verticesCount, void* mesh,
                                   ULONG meshCount, DWORD mode)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);

    return ::GradientFill(m_Handle, vertices, verticesCount, mesh, meshCount, mode);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixDC::GradientFillRect(uixColor start, uixColor stop, const uixRect& rect,
                                       BOOL horizontal)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);

    TRIVERTEX        vert[2];
    GRADIENT_RECT    gRect;
    vert[0].x      = rect.left;
    vert[0].y      = rect.top;
    vert[0].Red    = GetRValue(start) << 8;
    vert[0].Green  = GetGValue(start) << 8;
    vert[0].Blue   = GetBValue(start) << 8;
    vert[0].Alpha  = 0x0000;

    vert[1].x      = rect.right;
    vert[1].y      = rect.bottom;
    vert[1].Red    = GetRValue(stop) << 8;
    vert[1].Green  = GetGValue(stop) << 8;
    vert[1].Blue   = GetBValue(stop) << 8;
    vert[1].Alpha  = 0x0000;
    gRect.UpperLeft  = 0;
    gRect.LowerRight = 1;

    return ::GdiGradientFill(
               m_Handle,
               vert, 2,
               &gRect, 1,
               horizontal
               ? GRADIENT_FILL_RECT_H
               : GRADIENT_FILL_RECT_V);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixDC::GradientFillRect(uixColor start, uixColor stop, USHORT startAlpha,
                                       USHORT stopAlpha, const uixRect& rect, BOOL horizontal)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);

    TRIVERTEX        vert[2];
    GRADIENT_RECT    gRect;
    vert[0].x      = rect.left;
    vert[0].y      = rect.top;
    vert[0].Red    = GetRValue(start) << 8;
    vert[0].Green  = GetGValue(start) << 8;
    vert[0].Blue   = GetBValue(start) << 8;
    vert[0].Alpha  = startAlpha;

    vert[1].x      = rect.right;
    vert[1].y      = rect.bottom;
    vert[1].Red    = GetRValue(stop) << 8;
    vert[1].Green  = GetGValue(stop) << 8;
    vert[1].Blue   = GetBValue(stop) << 8;
    vert[1].Alpha  = stopAlpha;
    gRect.UpperLeft  = 0;
    gRect.LowerRight = 1;

    return ::GdiGradientFill(
               m_Handle,
               vert, 2,
               &gRect, 1,
               horizontal
               ? GRADIENT_FILL_RECT_H
               : GRADIENT_FILL_RECT_V);
}
//----------------------------------------------------------------------------//
UIXINLINE void uixDC::DrawRect3D(INT left, INT top, INT width, INT height, uixColor colorTopLeft,
                                 uixColor colorBottomRight)
{
    uixASSERT(this != NULLPTR);
    FillSolidRect(left, top, width - 1, 1, colorTopLeft);
    FillSolidRect(left, top, 1, height - 1, colorTopLeft);
    FillSolidRect(left + width, top, -1, height, colorBottomRight);
    FillSolidRect(left, top + height, width, -1, colorBottomRight);
}
//----------------------------------------------------------------------------//
UIXINLINE void uixDC::DrawRect3D(RECT& rect, uixColor colorTopLeft, uixColor colorBottomRight)
{
    uixASSERT(this != NULLPTR);
    FillSolidRect(rect.left, rect.top, rect.right - rect.left - 1, 1, colorTopLeft);
    FillSolidRect(rect.left, rect.top, 1, rect.bottom - rect.top - 1, colorTopLeft);
    FillSolidRect(rect.left + (rect.right - rect.left), rect.top, -1, rect.bottom - rect.top,
                  colorBottomRight);
    FillSolidRect(rect.left, rect.top + (rect.bottom - rect.top), rect.right - rect.left, -1,
                  colorBottomRight);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixDC::FillRect(const uixRect& rect, HBRUSH brush)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);
    return ::FillRect(m_Handle, &rect, brush) != 0;
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixDC::FrameRect(const uixRect& rect, HBRUSH brush)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);
    return ::FrameRect(m_Handle, &rect, brush) != 0;
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixDC::InvertRect(const uixRect& rect)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);
    return ::InvertRect(m_Handle, &rect);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixDC::DrawIcon(INT x, INT y, HICON icon)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);
    return ::DrawIcon(m_Handle, x, y, icon);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixDC::DrawIcon(uixPoint point, HICON icon)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);
    return ::DrawIcon(m_Handle, point.x, point.y, icon);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixDC::DrawIconEx(INT x, INT y, HICON icon, INT width, INT height,
                                 UINT stepIfAniCursor, HBRUSH flickerFreeDraw, UINT flags)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);
    return ::DrawIconEx(m_Handle, x, y, icon, width, height, stepIfAniCursor, flickerFreeDraw, flags);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixDC::DrawIconEx(uixPoint point, uixSize size, HICON icon, UINT stepIfAniCursor,
                                 HBRUSH flickerFreeDraw, UINT flags)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);
    return ::DrawIconEx(m_Handle, point.x, point.y, icon, size.cx, size.cy, stepIfAniCursor,
                        flickerFreeDraw, flags);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixDC::DrawState(uixPoint point, uixSize size, HICON icon, UINT flags, HBRUSH brush)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);
    return ::DrawState(m_Handle, brush, NULLPTR, (LPARAM)icon, 0, point.x, point.y, size.cx, size.cy,
                       flags | DST_ICON);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixDC::DrawState(uixPoint point, uixSize size, HBITMAP bitmap, UINT flags,
                                HBRUSH brush)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);
    return ::DrawState(m_Handle, brush, NULLPTR, (LPARAM)bitmap, 0, point.x, point.y, size.cx, size.cy,
                       flags | DST_BITMAP);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixDC::DrawState(uixPoint point, uixSize size, const uixChar* text, UINT flags,
                                BOOL prefixText, INT textLength, HBRUSH brush)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);
    return ::DrawState(m_Handle, brush, NULLPTR, (LPARAM)text, (WPARAM)textLength, point.x, point.y,
                       size.cx, size.cy, flags | (prefixText ? DST_PREFIXTEXT : DST_TEXT));
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixDC::DrawState(uixPoint point, uixSize size, DRAWSTATEPROC proc, LPARAM data,
                                UINT flags, HBRUSH brush)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);
    return ::DrawState(m_Handle, brush, proc, data, 0, point.x, point.y, size.cx, size.cy,
                       flags | DST_COMPLEX);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixDC::DrawEdge(RECT& rect, uixDrawBorderEdge edge, uixDrawBorderFlags flags)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);
    return ::DrawEdge(m_Handle, &rect, edge, flags);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixDC::DrawFrameControl(RECT& rect, uixDrawFrameType type, uixDrawFrameState state)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);
    return ::DrawFrameControl(m_Handle, &rect, type, state);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixDC::Arc(INT x1, INT y1, INT x2, INT y2, INT x3, INT y3, INT x4, INT y4)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);
    return ::Arc(m_Handle, x1, y1, x2, y2, x3, y3, x4, y4);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixDC::Arc(const uixRect& rect, uixPoint start, uixPoint end)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);
    return ::Arc(m_Handle,
                 rect.left, rect.top, rect.right, rect.bottom,
                 start.x, start.y, end.x, end.y);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixDC::AngleArc(INT x, INT y, INT radius, FLOAT startAngle, FLOAT sweepAngle)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);
    return ::AngleArc(m_Handle, x, y, radius, startAngle, sweepAngle);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixDC::ArcTo(INT x1, INT y1, INT x2, INT y2, INT x3, INT y3, INT x4, INT y4)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);
    return ::ArcTo(m_Handle, x1, y1, x2, y2, x3, y3, x4, y4);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixDC::ArcTo(const uixRect& rect, uixPoint start, uixPoint end)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);
    return ::ArcTo(m_Handle,
                   rect.left, rect.top, rect.right, rect.bottom,
                   start.x, start.y, end.x, end.y);
}
//----------------------------------------------------------------------------//
UIXINLINE uixDCArcDirection uixDC::GetArcDirection()
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);
    return (uixDCArcDirection)::GetArcDirection(m_Handle);
}
//----------------------------------------------------------------------------//
UIXINLINE uixDCArcDirection uixDC::SetArcDirection(uixDCArcDirection direction)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);
    return (uixDCArcDirection)::SetArcDirection(m_Handle, direction);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixDC::Polyline(const uixPoint points[], INT count)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(points != NULLPTR);
    uixASSERT(count >= 0);
    uixASSERT(m_Handle != 0);
    return ::Polyline(m_Handle, points, count);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixDC::PolylineTo(const uixPoint points[], INT count)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(points != NULLPTR);
    uixASSERT(count >= 0);
    uixASSERT(m_Handle != 0);
    return ::PolylineTo(m_Handle, points, count);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixDC::PolyDraw(const uixPoint points[], const BYTE types[], INT count)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(points != NULLPTR);
    uixASSERT(types != NULLPTR);
    uixASSERT(count >= 0);
    uixASSERT(m_Handle != 0);

    return ::PolyDraw(m_Handle, points, types, count);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixDC::PolyPolyline(const uixPoint points[], const DWORD polyPoints[], INT count)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(points != NULLPTR);
    uixASSERT(polyPoints != NULLPTR);
    uixASSERT(count >= 0);
    uixASSERT(m_Handle != 0);

    return ::PolyPolyline(m_Handle, points, polyPoints, count);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixDC::PolyBezier(const uixPoint points[], INT count)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(points != NULLPTR);
    uixASSERT(count >= 0);
    uixASSERT(m_Handle != 0);
    return ::PolyBezier(m_Handle, points, count);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixDC::PolyBezierTo(const uixPoint points[], INT count)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(points != NULLPTR);
    uixASSERT(count >= 0);
    uixASSERT(m_Handle != 0);
    return ::PolyBezierTo(m_Handle, points, count);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixDC::Chord(INT x1, INT y1, INT x2, INT y2, INT x3, INT y3, INT x4, INT y4)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);
    return ::Chord(m_Handle, x1, y1, x2, y2, x3, y3, x4, y4);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixDC::Chord(const uixRect& rect, uixPoint start, uixPoint end)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);
    return ::Chord(m_Handle, rect.left, rect.top, rect.right, rect.bottom,
                   start.x, start.y, end.x, end.y);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixDC::DrawFocusRect(const uixRect& rect)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);
    return ::DrawFocusRect(m_Handle, &rect);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixDC::Ellipse(INT x1, INT y1, INT x2, INT y2)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);
    return ::Ellipse(m_Handle, x1, y1, x2, y2);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixDC::Ellipse(const uixRect& rect)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);
    return ::Ellipse(m_Handle, rect.left, rect.top, rect.right, rect.bottom);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixDC::Pie(INT x1, INT y1, INT x2, INT y2, INT x3, INT y3, INT x4, INT y4)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);
    return ::Pie(m_Handle, x1, y1, x2, y2, x3, y3, x4, y4);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixDC::Pie(const uixRect& rect, uixPoint start, uixPoint end)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);
    return ::Pie(m_Handle, rect.left, rect.top, rect.right, rect.bottom,
                 start.x, start.y, end.x, end.y);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixDC::Polygon(const uixPoint points[], INT count)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);
    return ::Polygon(m_Handle, points, count);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixDC::PolyPolygon(const uixPoint points[], const INT counts[], INT count)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);
    return ::PolyPolygon(m_Handle, points, counts, count);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixDC::Rectangle(INT x1, INT y1, INT x2, INT y2)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);
    return ::Rectangle(m_Handle, x1, y1, x2, y2);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixDC::Rectangle(const uixRect& rect)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);
    return ::Rectangle(m_Handle, rect.left, rect.top, rect.right, rect.bottom);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixDC::RoundRect(INT x1, INT y1, INT x2, INT y2, INT xRadius, INT yRadius)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);
    return ::RoundRect(m_Handle, x1, y1, x2, y2, xRadius, yRadius);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixDC::RoundRect(const uixRect& rect, uixPoint radius)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);
    return ::RoundRect(m_Handle, rect.left, rect.top, rect.right, rect.bottom, radius.x, radius.y);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixDC::PatBlt(INT x, INT y, INT width, INT height, DWORD rop)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);
    return ::PatBlt(m_Handle, x, y, width, height, rop);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixDC::PatBlt(const uixRect& rect, DWORD rop)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);
    return ::PatBlt(m_Handle, rect.left, rect.top, rect.Width(), rect.Height(), rop);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixDC::BitBlt(INT x, INT y, INT width, INT height, HDC sourceDC, INT xSrc, INT ySrc,
                             DWORD rop)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);
    uixASSERT(sourceDC != 0);
    return ::BitBlt(m_Handle, x, y, width, height, sourceDC, xSrc, ySrc, rop);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixDC::BitBlt(const uixRect& rect, HDC sourceDC, uixPoint source, DWORD rop)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);
    uixASSERT(sourceDC != 0);
    return ::BitBlt(m_Handle, rect.left, rect.top, rect.Width(), rect.Height(),
                    sourceDC, source.x, source.y, rop);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixDC::StretchBlt(INT x, INT y, INT width, INT height,
                                 HDC sourceDC, INT xSrc, INT ySrc, INT wSrc, INT hSrc, DWORD rop)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);
    uixASSERT(sourceDC != 0);
    return ::StretchBlt(m_Handle, x, y, width, height, sourceDC,
                        xSrc, ySrc, wSrc, hSrc, rop);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixDC::StretchBlt(const uixRect& targetRC, HDC sourceDC, const uixRect& sourceRC,
                                 DWORD rop)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);
    uixASSERT(sourceDC != 0);
    return ::StretchBlt(m_Handle,
                        targetRC.left, targetRC.top, targetRC.Width(), targetRC.Height(),
                        sourceDC, sourceRC.left, sourceRC.top, sourceRC.Width(), sourceRC.Height(), rop);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixDC::MaskBlt(INT x, INT y, INT width, INT height, HDC sourceDC, INT xSrc, INT ySrc,
                              HBITMAP mask, INT xMask, INT yMask, DWORD rop)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);
    uixASSERT(sourceDC != 0);
    return ::MaskBlt(m_Handle, x, y, width, height,
                     sourceDC, xSrc, ySrc,
                     mask, xMask, yMask, rop);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixDC::MaskBlt(const uixRect& rc, HDC sourceDC, uixPoint srcPt, HBITMAP mask,
                              uixPoint maskPt, DWORD rop)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);
    uixASSERT(sourceDC != 0);
    return ::MaskBlt(m_Handle,
                     rc.left, rc.top, rc.Width(), rc.Height(),
                     sourceDC, srcPt.x, srcPt.y,
                     mask, maskPt.x, maskPt.y, rop);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixDC::PlgBlt(const uixPoint* point, HDC sourceDC, INT xSrc, INT ySrc, INT width,
                             INT height, HBITMAP mask, INT xMask, INT yMask)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);
    uixASSERT(sourceDC != 0);
    return ::PlgBlt(m_Handle, point, sourceDC, xSrc, ySrc, width, height, mask, xMask, yMask);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixDC::PlgBlt(const uixPoint* point, HDC sourceDC, uixPoint srcPt, uixSize size,
                             HBITMAP mask, uixPoint maskPt)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);
    uixASSERT(sourceDC != 0);
    return ::PlgBlt(m_Handle, point,
                    sourceDC, srcPt.x, srcPt.y,
                    size.cx, size.cy,
                    mask, maskPt.x, maskPt.y);
}
//----------------------------------------------------------------------------//
UIXINLINE uixColor uixDC::GetPixel(INT x, INT y)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);
    return ::GetPixel(m_Handle, x, y);
}
//----------------------------------------------------------------------------//
UIXINLINE uixColor uixDC::GetPixel(uixPoint pt)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);
    return ::GetPixel(m_Handle, pt.x, pt.y);
}
//----------------------------------------------------------------------------//
UIXINLINE uixColor uixDC::SetPixel(INT x, INT y, uixColor color)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);
    return ::SetPixel(m_Handle, x, y, color);
}
//----------------------------------------------------------------------------//
UIXINLINE uixColor uixDC::SetPixel(uixPoint pt, uixColor color)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);
    return ::SetPixel(m_Handle, pt.x, pt.y, color);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixDC::SetPixelV(INT x, INT y, uixColor color)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);
    return ::SetPixelV(m_Handle, x, y, color);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixDC::SetPixelV(uixPoint pt, uixColor color)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);
    return ::SetPixelV(m_Handle, pt.x, pt.y, color);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixDC::FloodFill(INT x, INT y, uixColor color)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);
    return ::FloodFill(m_Handle, x, y, color);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixDC::FloodFill(uixPoint pt, uixColor color)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);
    return ::FloodFill(m_Handle, pt.x, pt.y, color);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixDC::FloodFillExt(INT x, INT y, uixColor color, UINT fillType)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);
    return ::ExtFloodFill(m_Handle, x, y, color, fillType);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixDC::FloodFillExt(uixPoint pt, uixColor color, UINT fillType)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);
    return ::ExtFloodFill(m_Handle, pt.x, pt.y, color, fillType);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixDC::TextOut(INT x, INT y, const uixChar* text, INT count)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);

    if (count == -1)
    {
        count = lstrlen(text);
    }

    return ::TextOut(m_Handle, x, y, text, count);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixDC::TextOut(uixPoint pt, const uixChar* text, INT count)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);

    if (count == -1)
    {
        count = lstrlen(text);
    }

    return ::TextOut(m_Handle, pt.x, pt.y, text, count);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixDC::TextOutExt(INT x, INT y, UINT flags, const uixRect* rect, const uixChar* text,
                                 INT count, INT* widths)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);

    if (count == -1)
    {
        count = lstrlen(text);
    }

    return ::ExtTextOut(m_Handle, x, y, flags, rect, text, count, widths);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixDC::TextOutExt(uixPoint pt, UINT flags, const uixRect* rect, const uixChar* text,
                                 INT count, INT* widths)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);

    if (count == -1)
    {
        count = lstrlen(text);
    }

    return ::ExtTextOut(m_Handle, pt.x, pt.y, flags, rect, text, count, widths);
}
//----------------------------------------------------------------------------//
UIXINLINE LONG uixDC::TabbedTextOut(INT x, INT y, const uixChar* text, INT count, INT tabPositions,
                                    INT* tabStopArray, INT tabOrigin)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);

    if (count == -1)
    {
        count = lstrlen(text);
    }

    return ::TabbedTextOut(m_Handle, x, y, text, count, tabPositions, tabStopArray, tabOrigin);
}
//----------------------------------------------------------------------------//
UIXINLINE LONG uixDC::TabbedTextOut(uixPoint pt, const uixChar* text, INT count, INT tabPositions,
                                    INT* tabStopArray, INT tabOrigin)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);

    if (count == -1)
    {
        count = lstrlen(text);
    }

    return ::TabbedTextOut(m_Handle, pt.x, pt.y, text, count, tabPositions, tabStopArray, tabOrigin);
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixDC::DrawText(const uixChar* text, INT count, RECT& rect, UINT format)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);
    return ::DrawText(m_Handle, text, count, &rect, format);
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixDC::DrawText(const uixChar* text, RECT& rect, UINT format)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);
    return ::DrawText(m_Handle, text, lstrlen(text), &rect, format);
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixDC::DrawTextEx(uixChar* text, INT count, uixRect& rect, UINT format,
                                DRAWTEXTPARAMS* params)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);
    return ::DrawTextEx(m_Handle, text, count, &rect, format, params);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixDC::GetTextExtent(const uixChar* text, INT count, uixSize& size)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);
    return ::GetTextExtentPoint32(m_Handle, text, count, &size);
}
//----------------------------------------------------------------------------//
UIXINLINE DWORD uixDC::GetTabbedTextExtent(const uixChar* text, INT count, INT tabPositions,
        INT* tabStopArray)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);

    if (count == -1)
    {
        count = lstrlen(text);
    }

    return ::GetTabbedTextExtent(m_Handle, text, count, tabPositions, tabStopArray);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixDC::GrayString(HBRUSH brush, GRAYSTRINGPROC proc, LPARAM data, INT count, INT x,
                                 INT y, INT width, INT height)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);
    return ::GrayString(m_Handle, brush, proc, data, count, x, y, width, height);
}
//----------------------------------------------------------------------------//
UIXINLINE UINT uixDC::GetTextAlign() const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);
    return ::GetTextAlign(m_Handle);
}
//----------------------------------------------------------------------------//
UIXINLINE UINT uixDC::SetTextAlign(UINT flags)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);
    return ::SetTextAlign(m_Handle, flags);
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixDC::GetTextFace(uixChar* faceName, INT count)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);
    return ::GetTextFace(m_Handle, count, faceName);
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixDC::GetTextFaceLength() const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);
    return ::GetTextFace(m_Handle, 0, NULLPTR);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixDC::GetTextMetrics(TEXTMETRIC* params)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);
    return ::GetTextMetrics(m_Handle, params);
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixDC::SetTextJustification(INT breakExtra, INT breakCount)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);
    return ::SetTextJustification(m_Handle, breakExtra, breakCount);
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixDC::GetTextCharacterExtra()
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);
    return ::GetTextCharacterExtra(m_Handle);
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixDC::SetTextCharacterExtra(INT extra)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);
    return ::SetTextCharacterExtra(m_Handle, extra);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixDC::Scroll(INT dx, INT dy, const uixRect& rect, const uixRect& clip,
                             HRGN regionUpdate, uixRect* rectUpdate)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);
    return ::ScrollDC(m_Handle, dx, dy, &rect, &clip, regionUpdate, rectUpdate);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixDC::GetCharWidth(UINT firstChar, UINT lastChar, INT* buffer)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);
    return ::GetCharWidth(m_Handle, firstChar, lastChar, buffer);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixDC::GetCharWidth32(UINT firstChar, UINT lastChar, INT* buffer)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);
    return ::GetCharWidth32(m_Handle, firstChar, lastChar, buffer);
}
//----------------------------------------------------------------------------//
UIXINLINE DWORD uixDC::SetMapperFlags(DWORD flags)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);
    return ::SetMapperFlags(m_Handle, flags);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixDC::GetAspectRatioFilter(uixSize& size)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);
    return ::GetAspectRatioFilterEx(m_Handle, &size);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixDC::GetCharABCWidths(UINT firstChar, UINT lastChar, ABC* abc)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);
    return ::GetCharABCWidths(m_Handle, firstChar, lastChar, abc);
}
//----------------------------------------------------------------------------//
UIXINLINE DWORD uixDC::GetFontData(DWORD table, DWORD offset, void* data, DWORD count)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);
    return ::GetFontData(m_Handle, table, offset, data, count);
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixDC::GetKerningPairs(INT pairs, KERNINGPAIR* pair)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);
    return ::GetKerningPairs(m_Handle, pairs, pair);
}
//----------------------------------------------------------------------------//
UIXINLINE UINT uixDC::GetOutlineTextMetrics(UINT cbData, OUTLINETEXTMETRIC* params)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);
    return ::GetOutlineTextMetrics(m_Handle, cbData, params);
}
//----------------------------------------------------------------------------//
UIXINLINE DWORD uixDC::GetGlyphOutline(UINT uChar, UINT format, GLYPHMETRICS* glyph, DWORD cbBuffer,
                                       void* buffer, MAT2* mat2)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);
    return ::GetGlyphOutline(m_Handle, uChar, format, glyph, cbBuffer, buffer, mat2);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixDC::GetCharABCWidths(UINT firstChar, UINT lastChar, ABCFLOAT* abc)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);
    return ::GetCharABCWidthsFloat(m_Handle, firstChar, lastChar, abc);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixDC::GetCharWidth(UINT firstChar, UINT lastChar, FLOAT* buffer)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);
    return ::GetCharWidthFloat(m_Handle, firstChar, lastChar, buffer);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixDC::AbortPath()
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);
    return ::AbortPath(m_Handle);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixDC::BeginPath()
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);
    return ::BeginPath(m_Handle);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixDC::CloseFigure()
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);
    return ::CloseFigure(m_Handle);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixDC::EndPath()
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);
    return ::EndPath(m_Handle);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixDC::FillPath()
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);
    return ::FillPath(m_Handle);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixDC::FlattenPath()
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);
    return ::FlattenPath(m_Handle);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixDC::StrokeAndFillPath()
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);
    return ::StrokeAndFillPath(m_Handle);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixDC::StrokePath()
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);
    return ::StrokePath(m_Handle);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixDC::WidenPath()
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);
    return ::WidenPath(m_Handle);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixDC::GetMiterLimit(FLOAT* miterLimit)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);
    return ::GetMiterLimit(m_Handle, miterLimit);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixDC::SetMiterLimit(FLOAT miterLimit)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);
    return ::SetMiterLimit(m_Handle, miterLimit, NULLPTR);
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixDC::GetPath(uixPoint points[], BYTE types[], INT count)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);
    return ::GetPath(m_Handle, points, types, count);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixDC::SelectClipPath(INT mode)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);
    return ::SelectClipPath(m_Handle, mode);
}
//----------------------------------------------------------------------------//
UIXINLINE uixColor uixDC::GetPenColor() const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);
    return ::GetDCPenColor(m_Handle);
}
//----------------------------------------------------------------------------//
UIXINLINE uixColor uixDC::SetPenColor(uixColor color)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);
    return ::SetDCPenColor(m_Handle, color);
}
//----------------------------------------------------------------------------//
UIXINLINE uixColor uixDC::GetBrushColor() const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);
    return ::GetDCBrushColor(m_Handle);
}
//----------------------------------------------------------------------------//
UIXINLINE uixColor uixDC::SetBrushColor(uixColor color)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);
    return ::SetDCBrushColor(m_Handle, color);
}
//----------------------------------------------------------------------------//
UIXINLINE DWORD uixDC::GetFontUnicodeRanges(GLYPHSET* glyphset)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);
    return ::GetFontUnicodeRanges(m_Handle, glyphset);
}
//----------------------------------------------------------------------------//
UIXINLINE DWORD uixDC::GetGlyphIndices(const uixChar* text, INT count, WORD* pgi, DWORD flags)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);
    return ::GetGlyphIndices(m_Handle, text, count, pgi, flags);
}
//----------------------------------------------------------------------------//
UIXINLINE DWORD uixDC::GetTextExtentPointI(WORD* pgi, INT count, uixSize* size)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);
    return ::GetTextExtentPointI(m_Handle, pgi, count, size);
}
//----------------------------------------------------------------------------//
UIXINLINE DWORD uixDC::GetTextExtentExPointI(WORD* pgi, INT count, INT maxExtent, INT* fit,
        INT* alpDx, uixSize* size)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);
    return ::GetTextExtentExPointI(m_Handle, pgi, count, maxExtent, fit, alpDx, size);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixDC::GetCharWidthI(UINT first, UINT cgi, WORD* pgi, INT* buffer)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);
    return ::GetCharWidthI(m_Handle, first, cgi, pgi, buffer);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixDC::GetCharABCWidthsI(UINT first, UINT cgi, WORD* pgi, ABC* abc)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);
    return ::GetCharABCWidthsI(m_Handle, first, cgi, pgi, abc);
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixPrintDC::StartDoc(DOCINFO* docinfo)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);
    return ::StartDoc(m_Handle, docinfo);
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixPrintDC::StartPage()
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);
    return ::StartPage(m_Handle);
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixPrintDC::EndPage()
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);
    return ::EndPage(m_Handle);
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixPrintDC::SetAbortProc(ABORTPROC proc)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);
    return ::SetAbortProc(m_Handle, proc);
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixPrintDC::AbortDoc()
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);
    return ::AbortDoc(m_Handle);
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixPrintDC::EndDoc()
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != 0);
    return ::EndDoc(m_Handle);
}
//----------------------------------------------------------------------------//
UIXINLINE uixClientDC::uixClientDC(HWND handle)
{
    uixASSERT(handle != NULLPTR);
    uixASSERT(::IsWindow(handle));
    m_Window = handle;
    m_Handle = ::GetDC(handle);
}
//----------------------------------------------------------------------------//
UIXINLINE uixClientDC::~uixClientDC()
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != NULLPTR);
    ::ReleaseDC(m_Window, m_Handle);
    m_Handle = 0;
}
//----------------------------------------------------------------------------//
UIXINLINE uixMemoryDC::uixMemoryDC(HDC dc, uixRect& rect, BOOL autoBlit)
    : m_OriginalDC(dc)
    , m_PaintRect(rect)
    , m_PreviousBitmap(0)
    , m_AutoBlit(autoBlit)
{
    CreateCompatible(m_OriginalDC);
    uixASSERT(m_Handle != 0);
    m_Bitmap.CreateCompatible(m_OriginalDC, m_PaintRect.Width(), m_PaintRect.Height());
    uixASSERT(m_Bitmap.GetHandle() != 0);
    m_PreviousBitmap = Select(m_Bitmap.GetHandle());

    SetViewportOrg(-m_PaintRect.left, -m_PaintRect.top);
}
//----------------------------------------------------------------------------//
UIXINLINE uixMemoryDC::~uixMemoryDC()
{
    uixASSERT(this != NULLPTR);

    if (m_AutoBlit)
    {
        ::BitBlt(m_OriginalDC, m_PaintRect.left, m_PaintRect.top, m_PaintRect.Width(), m_PaintRect.Height(),
                 m_Handle, m_PaintRect.left, m_PaintRect.top, SRCCOPY);
    }

    Select(m_PreviousBitmap);
}
//----------------------------------------------------------------------------//
UIXINLINE uixPaintDC::uixPaintDC(HWND handle)
{
    uixASSERT(::IsWindow(handle));
    m_Window = handle;
    m_Handle = ::BeginPaint(m_Window, &m_PS);
}
//----------------------------------------------------------------------------//
UIXINLINE uixPaintDC::~uixPaintDC()
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != NULLPTR);
    uixASSERT(::IsWindow(m_Window));
    ::EndPaint(m_Window, &m_PS);
    m_Handle = 0;
    m_Window = 0;
}
//----------------------------------------------------------------------------//
UIXINLINE const uixRect uixPaintDC::GetPaintArea() const
{
    uixASSERT(this != NULLPTR);
    return m_PS.rcPaint;
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixPaintDC::NeedErase() const
{
    uixASSERT(this != NULLPTR);
    return m_PS.fErase != 0;
}
//----------------------------------------------------------------------------//
UIXINLINE uixWindowDC::uixWindowDC(HWND handle)
{
    uixASSERT(handle != NULLPTR);
    uixASSERT(::IsWindow(handle));
    m_Window = handle;
    m_Handle = ::GetWindowDC(handle);
}
//----------------------------------------------------------------------------//
UIXINLINE uixWindowDC::~uixWindowDC()
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != NULLPTR);
    ::ReleaseDC(m_Window, m_Handle);
    m_Handle = 0;
}
//----------------------------------------------------------------------------//
UIXINLINE uixNonClientDC::uixNonClientDC(HWND window, HRGN region)
    : m_Window(window)
    , m_Region(region)
{
    m_Handle = ::GetDCEx(m_Window, m_Region, DCX_WINDOW | DCX_INTERSECTRGN | DCX_PARENTCLIP);
    DWORD rer = ::GetLastError();
    rer;
}
//----------------------------------------------------------------------------//
UIXINLINE uixNonClientDC::~uixNonClientDC()
{
    ::ReleaseDC(m_Window, m_Handle);
}
//----------------------------------------------------------------------------//
}
//----------------------------------------------------------------------------//
#endif /* _UIX_GDIDC_INL__ */