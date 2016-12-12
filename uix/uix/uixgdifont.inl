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
#ifndef _UIX_GDIFONT_INL__
#define _UIX_GDIFONT_INL__
//----------------------------------------------------------------------------//
#include "uixgdifont.h"
//----------------------------------------------------------------------------//
namespace UIX
{
//----------------------------------------------------------------------------//
UIXINLINE uixFont::uixFont(HFONT handle)
    : m_Handle(handle)
{
}
//----------------------------------------------------------------------------//
UIXINLINE uixFont::~uixFont()
{
    uixASSERT(this != NULLPTR);

    if ((m_Handle != 0) && (!::DeleteObject(m_Handle)))
    {
        m_Handle = 0;
    }
}
//----------------------------------------------------------------------------//
UIXINLINE uixFont::operator HFONT()
{
    return GetHandleSafe();
}
//----------------------------------------------------------------------------//
UIXINLINE HFONT uixFont::GetHandle()
{
    uixASSERT(this != NULLPTR);
    return m_Handle;
}
//----------------------------------------------------------------------------//
UIXINLINE HFONT uixFont::GetHandleSafe() const
{
    if (this != NULLPTR)
    {
        return m_Handle;
    }

    return NULLPTR;
}
//----------------------------------------------------------------------------//
UIXINLINE uixFont& uixFont::Attach(HFONT handle)
{
    uixASSERT(this != NULLPTR);

    if (m_Handle)
    {
        ::DeleteObject(m_Handle);
    }

    m_Handle = handle;

    return (*this);
}
//----------------------------------------------------------------------------//
UIXINLINE HFONT uixFont::Detach()
{
    uixASSERT(this != NULLPTR);
    HFONT handle = m_Handle;
    m_Handle = 0;
    return handle;
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixFont::DeleteObject()
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != NULLPTR);

    if (m_Handle != 0)
    {
        return ::DeleteObject(m_Handle);
    }

    return FALSE;
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixFont::CreateIndirect(const LOGFONT* params)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle == NULLPTR);
    m_Handle = ::CreateFontIndirect(params);

    return m_Handle != 0;
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixFont::Create(INT height, INT width, INT escapement, INT orientation, INT weight,
                               BYTE italic, BYTE underline, BYTE strikeOut, BYTE charSet, BYTE outPrecision,
                               BYTE clipPrecision, BYTE quality, BYTE pitchAndFamily, const uixChar* facename)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle == NULLPTR);

    m_Handle = ::CreateFont(height, width, escapement, orientation, weight,
                            italic, underline, strikeOut, charSet, outPrecision, clipPrecision,
                            quality, pitchAndFamily, facename);
    return m_Handle != 0;
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixFont::GetStock(INT index)
{
    uixASSERT(this != NULLPTR);
    HFONT handle = (HFONT)::GetStockObject(index);

    if (!handle)
    {
        return FALSE;
    }

    Attach(handle);
    return TRUE;
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixFont::GetLogFont(LOGFONT* params)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != NULLPTR);
    return ::GetObject(m_Handle, sizeof(LOGFONT), params);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixFont::GetLogFont(LOGFONT& params)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(m_Handle != NULLPTR);
    return (::GetObject(m_Handle, sizeof(LOGFONT), &params) == sizeof(LOGFONT));
}
//----------------------------------------------------------------------------//
}
//----------------------------------------------------------------------------//
#endif /* _UIX_GDIFONT_INL__ */