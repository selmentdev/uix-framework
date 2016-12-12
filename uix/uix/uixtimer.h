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
#ifndef _UIX_TIMER_H__
#define _UIX_TIMER_H__
//----------------------------------------------------------------------------//
#include "uixwindow.h"
//----------------------------------------------------------------------------//
namespace UIX
{
//! Timer class
//! @brief
//!     This class supports timers manipulation
class UIXEXTAPI uixTimer : public uixObject
{
public:
    //! Constructor
    //! @param[in] parent
    //!     Parent window
    //! @param[in] id
    //!     Timer ID
    UIXINLINE uixTimer(uixWindow* parent, UINT_PTR id)
        : m_Parent(parent)
        , m_EventID(id)
    {
    }

    //! Gets timer ID
    //! @return
    //!     Timer ID
    UIXINLINE UINT_PTR GetID() const
    {
        return m_EventID;
    }

    //! Starts timer
    //! @param[in] interval
    //!     Interval
    //! @return
    //!     True when successul
    UIXINLINE BOOL Start(INT interval)
    {
        m_EventID = m_Parent->SetTimer(m_EventID, interval, NULLPTR);
        return TRUE;
    }

    //! Stops timer
    //! @return
    //!     True when successful
    UIXINLINE BOOL Stop()
    {
        return m_Parent->KillTimer(m_EventID);
    }

private:
    uixWindow*  m_Parent;
    UINT_PTR    m_EventID;
};
}
//----------------------------------------------------------------------------//
#endif /* _UIX_TIMER_H__ */