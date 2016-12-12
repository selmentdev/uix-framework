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
#ifndef _UIX_SHAREDPTR_H__
#define _UIX_SHAREDPTR_H__
//----------------------------------------------------------------------------//
#include "uixrequired.h"
//----------------------------------------------------------------------------//
namespace UIX
{
//! Shared pointer
//! @tparam T
//!     Parametrized type
//! @brief
//!     This class implements shared pointer for any T type
template <typename T>
class uixSharedPtr
{
public:
    uixSharedPtr()
        : m_Pointer(NULLPTR)
        , m_RefCount(NULLPTR)
    {
    }

    uixSharedPtr(T* pointer)
        : m_Pointer(pointer)
        , m_RefCount(NULLPTR)
    {
        try
        {
            if (m_Pointer)
            {
                m_RefCount = new LONG(0);
                AddRef();
            }
        }
        catch (const std::bad_alloc&)
        {
            delete m_Pointer;
            throw;
        }
    }

    uixSharedPtr(const uixSharedPtr& pointer)
        : m_Pointer(pointer.m_Pointer)
        , m_RefCount(pointer.m_RefCount)
    {
        AddRef();
    }

    ~uixSharedPtr()
    {
        if ((m_RefCount != NULLPTR) && (Release() == 0))
        {
            delete m_Pointer;
            delete m_RefCount;
        }
    }

    T* Pointer() const
    {
        return m_Pointer;
    }

    LONG NumRefCount() const
    {
        return (m_RefCount != NULLPTR)
               ? (*m_RefCount)
               : 0;
    }

    BOOL IsUnique() const
    {
        return (m_RefCount != NULLPTR)
               && ((*m_RefCount) == 1);
    }

    void swap(uixSharedPtr& pointer)
    {
        std::swap(m_Pointer, pointer.m_Pointer);
        std::swap(m_RefCount, pointer.m_RefCount);
    }

    uixSharedPtr& operator = (const uixSharedPtr& pointer)
    {
        uixSharedPtr copy(pointer);
        this->swap(copy);

        return (*this);
    }

    T* operator -> () const
    {
        uixASSERT(m_Pointer);
        return m_Pointer;
    }

    T& operator * () const
    {
        uixASSERT(m_Pointer);
        return (*m_Pointer);
    }

    bool operator == (const uixSharedPtr& pointer) const
    {
        return (*m_Pointer) == (*pointer.m_Pointer);
    }

    bool operator != (const uixSharedPtr& pointer) const
    {
        return (*m_Pointer) != (*pointer.m_Pointer);
    }

    bool operator < (const uixSharedPtr& pointer) const
    {
        return (*m_Pointer) < (*pointer.m_Pointer);
    }

    bool operator > (const uixSharedPtr& pointer) const
    {
        return (*m_Pointer) > (*pointer.m_Pointer);
    }

    bool operator <= (const uixSharedPtr& pointer) const
    {
        return (*m_Pointer) <= (*pointer.m_Pointer);
    }

    bool operator >= (const uixSharedPtr& pointer) const
    {
        return (*m_Pointer) >= (*pointer.m_Pointer);
    }

private:
    void AddRef()
    {
        if (m_RefCount != NULLPTR)
        {
            ::InterlockedIncrement(m_RefCount);
        }
    }

    LONG Release()
    {
        uixASSERT(m_RefCount != NULLPTR);

        return ::InterlockedDecrement(m_RefCount);
    }

    T*              m_Pointer;
    volatile LONG*  m_RefCount;
};
}
//----------------------------------------------------------------------------//
#endif