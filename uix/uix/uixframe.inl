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
#ifndef _UIX_FRAME_INL__
#define _UIX_FRAME_INL__
//----------------------------------------------------------------------------//
#include "uixframe.h"
//----------------------------------------------------------------------------//
namespace UIX
{
//----------------------------------------------------------------------------//
UIXINLINE void uixFrame::SetView(uixView* view, BOOL deleteView)
{
    uixASSERT(this != NULLPTR);

    if (m_View && deleteView)
    {
        delete m_View;
    }

    m_View = view;
}
//----------------------------------------------------------------------------//
UIXINLINE uixView* uixFrame::GetView() const
{
    uixASSERT(this != NULLPTR);

    return m_View;
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixFrame::Close()
{
    uixASSERT(this != NULLPTR);
    uixASSERT(IsWindow(m_Handle));

    SendMessage(WM_SYSCOMMAND, SC_CLOSE, 0);
    return TRUE;
}
//----------------------------------------------------------------------------//
}
//----------------------------------------------------------------------------//
#endif /* _UIX_FRAME_INL__ */