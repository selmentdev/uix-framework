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
#ifndef _UIX_GDIPEN_INL__
#define _UIX_GDIPEN_INL__
//----------------------------------------------------------------------------//
#include "uixgdipen.h"
//----------------------------------------------------------------------------//
namespace UIX
{
//----------------------------------------------------------------------------//
UIXINLINE uixPen::uixPen(HPEN handle)
    : m_Handle(handle)
{
}
//----------------------------------------------------------------------------//
UIXINLINE uixPen::~uixPen()
{
    DeleteObject();
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixPen::IsValid() const
{
    uixASSERT(this != NULLPTR);
    return m_Handle != 0;
}
//----------------------------------------------------------------------------//
UIXINLINE HPEN uixPen::GetHandle()
{
    uixASSERT(this != NULLPTR);
    return m_Handle;
}
//----------------------------------------------------------------------------//
UIXINLINE HPEN uixPen::GetHandleSafe()
{
    if (this)
    {
        return m_Handle;
    }

    return 0;
}
//----------------------------------------------------------------------------//
UIXINLINE uixPen::operator HPEN ()
{
    return GetHandleSafe();
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixPen::Create(uixPenStyle style, INT width, uixColor color)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle == NULLPTR);

    m_Handle = ::CreatePen(style, width, color);
    return m_Handle != 0;
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixPen::CreateExt(const LOGBRUSH& params, uixPenStyle style, INT width,
                                 INT styleCount, DWORD* styleData)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle == NULLPTR);

    m_Handle = ::ExtCreatePen(style, width, &params, styleCount, styleData);
    return m_Handle != 0;
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixPen::CreateIndirect(const LOGPEN& params)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle == NULLPTR);

    m_Handle = ::CreatePenIndirect(&params);

    return m_Handle != 0;
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixPen::DeleteObject()
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != NULLPTR);

    BOOL result = ::DeleteObject(m_Handle);

    if (result)
    {
        m_Handle = 0;
    }

    return result;
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixPen::GetLogPen(LOGPEN& logpen)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != NULLPTR);
    return ::GetObject(m_Handle, sizeof(LOGPEN), &logpen);
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixPen::GetExtLogPen(EXTLOGPEN& logpen)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != NULLPTR);
    return ::GetObject(m_Handle, sizeof(EXTLOGPEN), &logpen);
}
//----------------------------------------------------------------------------//
}
//----------------------------------------------------------------------------//
#endif /* _UIX_GDIPEN_INL__ */