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
#ifndef _UIX_TYPES_INL__
#define _UIX_TYPES_INL__
//----------------------------------------------------------------------------//
#include "uixtypes.h"
//----------------------------------------------------------------------------//
namespace UIX
{
//----------------------------------------------------------------------------//
// uixSize
//----------------------------------------------------------------------------//
UIXINLINE uixSize::uixSize()
{
}
//----------------------------------------------------------------------------//
UIXINLINE uixSize::uixSize(LONG width, LONG height)
{
    cx = width;
    cy = height;
}
//----------------------------------------------------------------------------//
UIXINLINE uixSize::uixSize(POINT point)
{
    cx = point.x;
    cy = point.y;
}
//----------------------------------------------------------------------------//
UIXINLINE uixSize::uixSize(SIZE size)
{
    cx = size.cx;
    cy = size.cy;
}
//----------------------------------------------------------------------------//
UIXINLINE uixSize::uixSize(DWORD size)
{
    cx = LOWORD(size);
    cy = HIWORD(size);
}
//----------------------------------------------------------------------------//
UIXINLINE LONG uixSize::Width() const
{
    return cx;
}
//----------------------------------------------------------------------------//
UIXINLINE LONG uixSize::Height() const
{
    return cy;
}
//----------------------------------------------------------------------------//
UIXINLINE uixSize& uixSize::Set(LONG width, LONG height)
{
    cx = width;
    cy = height;
    return (*this);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixSize::Equals(SIZE size) const
{
    return (cx == size.cx) &&
           (cy == size.cy);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixSize::operator == (SIZE size) const
{
    return Equals(size);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixSize::operator != (SIZE size) const
{
    return !Equals(size);
}
//----------------------------------------------------------------------------//
UIXINLINE uixSize& uixSize::operator += (SIZE size)
{
    cx += size.cx;
    cy += size.cy;
    return (*this);
}
//----------------------------------------------------------------------------//
UIXINLINE uixSize& uixSize::operator -= (SIZE size)
{
    cx -= size.cx;
    cy -= size.cy;
    return (*this);
}
//----------------------------------------------------------------------------//
UIXINLINE uixSize uixSize::operator + (SIZE size) const
{
    return uixSize(cx + size.cx, cy + size.cy);
}
//----------------------------------------------------------------------------//
UIXINLINE uixSize uixSize::operator - (SIZE size) const
{
    return uixSize(cx - size.cx, cy - size.cy);
}
//----------------------------------------------------------------------------//
UIXINLINE uixSize uixSize::operator - () const
{
    return uixSize(-cx, -cy);
}
//----------------------------------------------------------------------------//
UIXINLINE uixPoint uixSize::operator + (POINT point) const
{
    return uixPoint(cx + point.x, cy + point.y);
}
//----------------------------------------------------------------------------//
UIXINLINE uixPoint uixSize::operator -(POINT point) const
{
    return uixPoint(cx - point.x, cy - point.y);
}
//----------------------------------------------------------------------------//
// uixPoint
//----------------------------------------------------------------------------//
UIXINLINE uixPoint::uixPoint()
{
}
//----------------------------------------------------------------------------//
UIXINLINE uixPoint::uixPoint(LONG left, LONG top)
{
    x = left;
    y = top;
}
//----------------------------------------------------------------------------//
UIXINLINE uixPoint::uixPoint(POINT point)
{
    x = point.x;
    y = point.y;
}
//----------------------------------------------------------------------------//
UIXINLINE uixPoint::uixPoint(SIZE size)
{
    x = size.cx;
    y = size.cy;
}
//----------------------------------------------------------------------------//
UIXINLINE uixPoint::uixPoint(DWORD point)
{
    x = LOWORD(point);
    y = HIWORD(point);
}
//----------------------------------------------------------------------------//
UIXINLINE LONG uixPoint::Left() const
{
    return x;
}
//----------------------------------------------------------------------------//
UIXINLINE LONG uixPoint::Top() const
{
    return y;
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixPoint::Equals(POINT point) const
{
    return (x == point.x) &&
           (y == point.y);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixPoint::operator == (POINT point) const
{
    return Equals(point);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixPoint::operator != (POINT point) const
{
    return !Equals(point);
}
//----------------------------------------------------------------------------//
UIXINLINE uixPoint& uixPoint::Set(LONG left, LONG top)
{
    x = left;
    y = top;
    return (*this);
}
//----------------------------------------------------------------------------//
UIXINLINE uixPoint& uixPoint::operator += (SIZE size)
{
    x += size.cx;
    y += size.cy;
    return (*this);
}
//----------------------------------------------------------------------------//
UIXINLINE uixPoint& uixPoint::operator -= (SIZE size)
{
    x -= size.cx;
    y -= size.cy;
    return (*this);
}
//----------------------------------------------------------------------------//
UIXINLINE uixPoint& uixPoint::operator += (POINT point)
{
    x += point.x;
    y += point.y;
    return (*this);
}
//----------------------------------------------------------------------------//
UIXINLINE uixPoint& uixPoint::operator -= (POINT point)
{
    x -= point.x;
    y -= point.y;
    return (*this);
}
//----------------------------------------------------------------------------//
UIXINLINE uixPoint uixPoint::operator + (SIZE size) const
{
    return uixPoint(x + size.cx, y + size.cy);
}
//----------------------------------------------------------------------------//
UIXINLINE uixPoint uixPoint::operator - (SIZE size) const
{
    return uixPoint(x - size.cx, y - size.cy);
}
//----------------------------------------------------------------------------//
UIXINLINE uixPoint uixPoint::operator - () const
{
    return uixPoint(-x, -y);
}
//----------------------------------------------------------------------------//
UIXINLINE uixPoint uixPoint::operator + (POINT point) const
{
    return uixPoint(x + point.x, y + point.y);
}
//----------------------------------------------------------------------------//
UIXINLINE uixSize uixPoint::operator - (POINT point) const
{
    return uixSize(x - point.x, y - point.y);
}
//----------------------------------------------------------------------------//
// uixRect
//----------------------------------------------------------------------------//
UIXINLINE uixRect::uixRect()
{
}
//----------------------------------------------------------------------------//
UIXINLINE uixRect::uixRect(LONG left, LONG top, LONG right, LONG bottom)
{
    this->left = left;
    this->top = top;
    this->right = right;
    this->bottom = bottom;
}
//----------------------------------------------------------------------------//
UIXINLINE uixRect::uixRect(const RECT& rect)
{
    CopyRect(this, &rect);
}
//----------------------------------------------------------------------------//
UIXINLINE uixRect::uixRect(POINT point, SIZE size)
{
    left = point.x;
    top = point.y;
    right = left + size.cx;
    bottom = top + size.cy;
}
//----------------------------------------------------------------------------//
UIXINLINE uixRect::uixRect(POINT topLeft, POINT bottomRight)
{
    left = topLeft.x;
    top = topLeft.y;
    right = bottomRight.x;
    bottom = bottomRight.y;
}
//----------------------------------------------------------------------------//
UIXINLINE LONG uixRect::Left() const
{
    return left;
}
//----------------------------------------------------------------------------//
UIXINLINE LONG uixRect::Top() const
{
    return top;
}
//----------------------------------------------------------------------------//
UIXINLINE LONG uixRect::Right() const
{
    return right;
}
//----------------------------------------------------------------------------//
UIXINLINE LONG uixRect::Bottom() const
{
    return bottom;
}
//----------------------------------------------------------------------------//
UIXINLINE LONG uixRect::Width() const
{
    return right - left;
}
//----------------------------------------------------------------------------//
UIXINLINE LONG uixRect::Height() const
{
    return bottom - top;
}
//----------------------------------------------------------------------------//
UIXINLINE uixSize uixRect::Size() const
{
    return uixSize(Width(), Height());
}
//----------------------------------------------------------------------------//
UIXINLINE uixPoint& uixRect::TopLeft()
{
    return *(((uixPoint*)this) + 0);
}
//----------------------------------------------------------------------------//
UIXINLINE const uixPoint& uixRect::TopLeft() const
{
    return *(((uixPoint*)this) + 0);
}
//----------------------------------------------------------------------------//
UIXINLINE uixPoint& uixRect::BottomRight()
{
    return *(((uixPoint*)this) + 1);
}
//----------------------------------------------------------------------------//
UIXINLINE const uixPoint& uixRect::BottomRight() const
{
    return *(((uixPoint*)this) + 1);
}
//----------------------------------------------------------------------------//
UIXINLINE uixPoint uixRect::CenterPoint() const
{
    return uixPoint(
               left + (Width() / 2),
               top + (Height() / 2));
}
//----------------------------------------------------------------------------//
UIXINLINE uixRect& uixRect::Set(LONG left, LONG top, LONG right, LONG bottom)
{
    this->left = left;
    this->top = top;
    this->right = right;
    this->bottom = bottom;
    return (*this);
}
//----------------------------------------------------------------------------//
UIXINLINE uixRect& uixRect::Set(POINT topLeft, POINT bottomRight)
{
    left = topLeft.x;
    top = topLeft.y;
    right = bottomRight.x;
    bottom = bottomRight.y;
    return (*this);
}
//----------------------------------------------------------------------------//
UIXINLINE uixRect& uixRect::SetEmpty()
{
    ::SetRectEmpty(this);
    return (*this);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixRect::Equals(const RECT& rect) const
{
    return ::EqualRect(this, &rect);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixRect::operator == (const RECT& rect) const
{
    return Equals(rect);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixRect::operator != (const RECT& rect) const
{
    return !Equals(rect);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixRect::IsEmpty() const
{
    return ::IsRectEmpty(this);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixRect::IsNull() const
{
    return (left == 0) &&
           (right == 0) &&
           (top == 0) &&
           (bottom == 0);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixRect::PtInRect(POINT point) const
{
    return ::PtInRect(this, point);
}
//----------------------------------------------------------------------------//
UIXINLINE uixRect& uixRect::CopyFrom(RECT& rect)
{
    ::CopyRect(this, &rect);
    return (*this);
}
//----------------------------------------------------------------------------//
UIXINLINE uixRect& uixRect::CopyFrom(RECT* rect)
{
    ::CopyRect(this, rect);
    return (*this);
}
//----------------------------------------------------------------------------//
UIXINLINE uixRect& uixRect::Inflate(INT x, INT y)
{
    left -= x;
    top -= y;
    right += x;
    bottom += y;
    return (*this);
}
//----------------------------------------------------------------------------//
UIXINLINE uixRect& uixRect::Inflate(SIZE size)
{
    left -= size.cx;
    top -= size.cy;
    right += size.cx;
    bottom += size.cy;
    return (*this);
}
//----------------------------------------------------------------------------//
UIXINLINE uixRect& uixRect::Inflate(RECT rect)
{
    left -= rect.left;
    top -= rect.top;
    right += rect.right;
    bottom += rect.bottom;
    return (*this);
}
//----------------------------------------------------------------------------//
UIXINLINE uixRect& uixRect::Inflate(INT l, INT t, INT r, INT b)
{
    left -= l;
    top -= t;
    right += r;
    bottom += b;
    return (*this);
}
//----------------------------------------------------------------------------//
UIXINLINE uixRect& uixRect::Deflate(INT x, INT y)
{
    left += x;
    top += y;
    right -= x;
    bottom -= y;
    return (*this);
}
//----------------------------------------------------------------------------//
UIXINLINE uixRect& uixRect::Deflate(SIZE size)
{
    left += size.cx;
    top += size.cy;
    right -= size.cx;
    bottom -= size.cy;
    return (*this);
}
//----------------------------------------------------------------------------//
UIXINLINE uixRect& uixRect::Deflate(RECT rect)
{
    left += rect.left;
    top += rect.top;
    right -= rect.right;
    bottom -= rect.bottom;
    return (*this);
}
//----------------------------------------------------------------------------//
UIXINLINE uixRect& uixRect::Deflate(INT l, INT t, INT r, INT b)
{
    left += l;
    top += t;
    right -= r;
    bottom -= b;
    return (*this);
}
//----------------------------------------------------------------------------//
UIXINLINE uixRect& uixRect::Offset(INT x, INT y)
{
    left += x;
    right += x;
    top += y;
    bottom += y;
    return (*this);
}
//----------------------------------------------------------------------------//
UIXINLINE uixRect& uixRect::Offset(POINT pt)
{
    left += pt.x;
    right += pt.x;
    top += pt.y;
    bottom += pt.y;
    return (*this);
}
//----------------------------------------------------------------------------//
UIXINLINE uixRect& uixRect::Offset(SIZE size)
{
    left += size.cx;
    right += size.cx;
    top += size.cy;
    bottom += size.cy;
    return (*this);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixRect::Intersect(const RECT* lhs, const RECT* rhs)
{
    return ::IntersectRect(this, lhs, rhs);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixRect::Intersect(const RECT& lhs, const RECT& rhs)
{
    return ::IntersectRect(this, &lhs, &rhs);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixRect::Union(const RECT* lhs, const RECT* rhs)
{
    return ::UnionRect(this, lhs, rhs);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixRect::Union(const RECT& lhs, const RECT& rhs)
{
    return ::UnionRect(this, &lhs, &rhs);
}
//----------------------------------------------------------------------------//
UIXINLINE uixRect& uixRect::operator = (const RECT& rhs)
{
    left = rhs.left;
    top = rhs.top;
    right = rhs.right;
    bottom = rhs.bottom;
    return (*this);
}
//----------------------------------------------------------------------------//
UIXINLINE uixRect& uixRect::operator += (POINT pt)
{
    return Offset(pt.x, pt.y);
}
//----------------------------------------------------------------------------//
UIXINLINE uixRect& uixRect::operator -= (POINT pt)
{
    return Offset(-pt.x, -pt.y);
}
//----------------------------------------------------------------------------//
UIXINLINE uixRect& uixRect::operator += (SIZE size)
{
    return Offset(size);
}
//----------------------------------------------------------------------------//
UIXINLINE uixRect& uixRect::operator -= (SIZE size)
{
    return Offset(-size.cx, -size.cy);
}
//----------------------------------------------------------------------------//
UIXINLINE uixRect& uixRect::operator += (const RECT& rect)
{
    return Inflate(rect);
}
//----------------------------------------------------------------------------//
UIXINLINE uixRect& uixRect::operator -= (const RECT& rect)
{
    return Deflate(rect);
}
//----------------------------------------------------------------------------//
UIXINLINE uixRect& uixRect::operator &= (const RECT& rect)
{
    Intersect(this, &rect);
    return (*this);
}
//----------------------------------------------------------------------------//
UIXINLINE uixRect& uixRect::operator |= (const RECT& rect)
{
    Union(this, &rect);
    return (*this);
}
//----------------------------------------------------------------------------//
UIXINLINE uixRect uixRect::operator + (POINT pt) const
{
    uixRect rc(*this);
    ::OffsetRect(&rc, pt.x, pt.y);
    return rc;
}
//----------------------------------------------------------------------------//
UIXINLINE uixRect uixRect::operator - (POINT pt) const
{
    uixRect rc(*this);
    ::OffsetRect(&rc, -pt.x, -pt.y);
    return rc;
}
//----------------------------------------------------------------------------//
UIXINLINE uixRect uixRect::operator + (SIZE size) const
{
    uixRect rc(*this);
    ::OffsetRect(&rc, size.cx, size.cy);
    return rc;
}
//----------------------------------------------------------------------------//
UIXINLINE uixRect uixRect::operator - (SIZE size) const
{
    uixRect rc(*this);
    ::OffsetRect(&rc, -size.cx, -size.cy);
    return rc;
}
//----------------------------------------------------------------------------//
UIXINLINE uixRect uixRect::Subtract(const RECT* lhs, const RECT* rhs)
{
    uixRect result;
    SubtractRect(&result, lhs, rhs);
    return result;
}
//----------------------------------------------------------------------------//
UIXINLINE uixRect uixRect::Subtract(const RECT& lhs, const RECT& rhs)
{
    uixRect result;
    SubtractRect(&result, &lhs, &rhs);
    return result;
}
//----------------------------------------------------------------------------//
UIXINLINE uixRect uixRect::operator & (const RECT& rc)
{
    uixRect result;
    result.Intersect(this, &rc);
    return result;
}
//----------------------------------------------------------------------------//
UIXINLINE uixRect uixRect::operator | (const RECT& rc)
{
    uixRect result;
    result.Union(this, &rc);
    return result;
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL UixFormatString(uixCString& result, const CHAR* format, ...)
{
    va_list args;
    va_start(args, format);

    int count = _vscprintf(format, args);

    if (count < 0)
    {
        return FALSE;
    }

    result.resize(count);
    _vsnprintf_s(
        const_cast<CHAR*>(result.c_str()),
        count + 1,
        count,
        format, args);

    va_end(args);
    return TRUE;
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL UixFormatString(uixWString& result, const WCHAR* format, ...)
{
    va_list args;
    va_start(args, format);

    int count = _vscwprintf(format, args);

    if (count < 0)
    {
        return FALSE;
    }

    result.resize(count);
    _vsnwprintf_s(
        const_cast<WCHAR*>(result.c_str()),
        count + 1,
        count,
        format, args);

    va_end(args);
    return TRUE;
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL UixFormatStringArgs(uixCString& result, const CHAR* format, va_list args)
{
    int count = _vscprintf(format, args);

    if (count < 0)
    {
        return FALSE;
    }

    result.resize(count);
    _vsnprintf_s(
        const_cast<CHAR*>(result.c_str()),
        count + 1,
        count,
        format, args);

    return TRUE;
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL UixFormatStringArgs(uixWString& result, const WCHAR* format, va_list args)
{
    int count = _vscwprintf(format, args);

    if (count < 0)
    {
        return FALSE;
    }

    result.resize(count);
    _vsnwprintf_s(
        const_cast<WCHAR*>(result.c_str()),
        count + 1,
        count,
        format, args);

    return TRUE;
}
//----------------------------------------------------------------------------//
}
//----------------------------------------------------------------------------//
#endif /* _UIX_TYPES_INL__ */