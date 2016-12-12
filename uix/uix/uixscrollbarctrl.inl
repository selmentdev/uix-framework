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
#ifndef _UIX_SCROLLBARCTRL_INL__
#define _UIX_SCROLLBARCTRL_INL__
//----------------------------------------------------------------------------//
#include "uixscrollbarctrl.h"
//----------------------------------------------------------------------------//
namespace UIX
{
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixScrollBarCtrl::EnableScroll(UINT flags)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    return ::ScrollBar_Enable(m_Handle(), flags);
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixScrollBarCtrl::GetPosition() const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    return ::ScrollBar_GetPos(m_Handle);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixScrollBarCtrl::GetRange(INT& min, INT& max) const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    return ::ScrollBar_GetRange(m_Handle, &min, &max);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixScrollBarCtrl::SetRange(INT min, INT max, BOOL redraw)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    return ::ScrollBar_SetRange(m_Handle, min, max, redraw);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixScrollBarCtrl::ShowScrollBar(BOOL show)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    return ::ScrollBar_Show(m_Handle, show);
}
//----------------------------------------------------------------------------//
}
//----------------------------------------------------------------------------//
#endif /* _UIX_SCROLLBARCTRL_INL__ */