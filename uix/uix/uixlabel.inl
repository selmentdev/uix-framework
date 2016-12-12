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
#ifndef _UIX_LABEL_INL__
#define _UIX_LABEL_INL__
//----------------------------------------------------------------------------//
#include "uixlabel.h"
//----------------------------------------------------------------------------//
namespace UIX
{
//----------------------------------------------------------------------------//
UIXINLINE HICON uixLabel::GetIcon() const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    //!@note Bug in Windows API: GetIcon needs param hIcon, but it's unused
    return (HICON)SendMessage(STM_GETICON, 0, 0);
}
//----------------------------------------------------------------------------//
UIXINLINE HBITMAP uixLabel::GetBitmap() const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (HBITMAP)SendMessage(STM_GETIMAGE, IMAGE_BITMAP, 0);
}
//----------------------------------------------------------------------------//
UIXINLINE HCURSOR uixLabel::GetCursor() const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (HCURSOR)SendMessage(STM_GETIMAGE, IMAGE_CURSOR, 0);
}
//----------------------------------------------------------------------------//
UIXINLINE HICON uixLabel::SetIcon(HICON icon)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (HICON)SendMessage(STM_SETICON, (WPARAM)icon, 0);
}
//----------------------------------------------------------------------------//
UIXINLINE HBITMAP uixLabel::SetBitmap(HBITMAP bitmap)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (HBITMAP)SendMessage(STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)bitmap);
}
//----------------------------------------------------------------------------//
UIXINLINE HCURSOR uixLabel::SetCursor(HCURSOR cursor)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (HCURSOR)SendMessage(STM_SETIMAGE, IMAGE_CURSOR, (LPARAM)cursor);
}
//----------------------------------------------------------------------------//
}
//----------------------------------------------------------------------------//
#endif /* _UIX_LABEL_INL__ */