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
#ifndef _UIX_GDIBRUSH_INL__
#define _UIX_GDIBRUSH_INL__
//----------------------------------------------------------------------------//
#include "uixgdibrush.h"
//----------------------------------------------------------------------------//
namespace UIX
{
//----------------------------------------------------------------------------//
UIXINLINE uixBrush::uixBrush(HBRUSH handle)
    : m_Handle(handle)
{
}
//----------------------------------------------------------------------------//
UIXINLINE uixBrush::uixBrush(uixColor color)
{
    Attach(::CreateSolidBrush(color));
}
//----------------------------------------------------------------------------//
UIXINLINE uixBrush::~uixBrush()
{
    DeleteObject();
}
//----------------------------------------------------------------------------//
UIXINLINE HBRUSH uixBrush::GetHandle() const
{
    uixASSERT(this != NULLPTR);
    return m_Handle;
}
//----------------------------------------------------------------------------//
UIXINLINE HBRUSH uixBrush::GetHandleSafe() const
{
    if (this)
    {
        return m_Handle;
    }

    return 0;
}
//----------------------------------------------------------------------------//
UIXINLINE uixBrush::operator HBRUSH () const
{
    return GetHandleSafe();
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixBrush::IsValid() const
{
    uixASSERT(this != NULLPTR);
    return m_Handle != 0;
}
//----------------------------------------------------------------------------//
UIXINLINE uixBrush& uixBrush::Attach(HBRUSH handle)
{
    uixASSERT(this != NULLPTR);

    if (m_Handle != 0)
    {
        ::DeleteObject(m_Handle);
    }

    m_Handle = handle;
    return (*this);
}
//----------------------------------------------------------------------------//
UIXINLINE HBRUSH uixBrush::Detach()
{
    uixASSERT(this != NULLPTR);
    HBRUSH handle = m_Handle;
    m_Handle = 0;
    return handle;
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixBrush::CreateSolid(uixColor color)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle == NULLPTR);
    m_Handle = ::CreateSolidBrush(color);
    return m_Handle != 0;
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixBrush::CreateHatch(uixBrushHatchStyle style, uixColor color)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle == NULLPTR);
    m_Handle = ::CreateHatchBrush(style, color);
    return m_Handle != 0;
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixBrush::CreateIndirect(const LOGBRUSH& logbrush)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle == NULLPTR);
    m_Handle = ::CreateBrushIndirect(&logbrush);
    return m_Handle != 0;
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixBrush::CreatePattern(HBITMAP bitmap)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle == NULLPTR);
    m_Handle = ::CreatePatternBrush(bitmap);
    return m_Handle != 0;
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixBrush::CreateSystemColor(uixSystemColor color)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle == NULLPTR);
    m_Handle = ::GetSysColorBrush(color);
    return m_Handle != 0;
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixBrush::DeleteObject()
{
    uixASSERT(this != NULLPTR);
    BOOL result = ::DeleteObject(m_Handle);

    if (result)
    {
        m_Handle = 0;
    }

    return result;
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixBrush::GetLogBrush(LOGBRUSH& logbrush)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != NULLPTR);
    return ::GetObject(m_Handle, sizeof(LOGBRUSH), &logbrush);
}
//----------------------------------------------------------------------------//
}
//----------------------------------------------------------------------------//
#endif /* _UIX_GDIBRUSH_INL__ */