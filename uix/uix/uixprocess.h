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
#ifndef _UIX_PROCESS_H__
#define _UIX_PROCESS_H__
//----------------------------------------------------------------------------//
#include "uixrequired.h"
//----------------------------------------------------------------------------//
namespace UIX
{
//! Process local object base
//! @brief
//!     This is base class for all objects, which are suppose to be created
//!     on demand, by working application. Typically, it would cover all
//!     objects that are local to current process
//! @remarks
//!     It uses process local heap to allocate memory for object
class uixProcessLocalObject
{
public:
    //! new operator
    //! @param[in] size
    //!     Size of object
    //! @return
    //!     Pointer to allocated memory
    void* operator new(size_t size)
    {
        HANDLE heap = ::GetProcessHeap();
        uixASSERT(heap != NULLPTR);

        void* pointer = ::HeapAlloc(
                            heap,
                            HEAP_ZERO_MEMORY,
                            size);

        uixASSERT(pointer);
        return pointer;
    }

    //! delete operator
    //! @param[in] pointer
    //!     Pointer to free
    void operator delete(void* pointer)
    {
        if (pointer != NULLPTR)
        {
            HANDLE heap = ::GetProcessHeap();
            uixASSERT(heap != NULLPTR);

#if defined(UIX_DEBUG)
            BOOL result =
#endif
                ::HeapFree(heap, 0, pointer);
            uixASSERT(result);
        }
    }
};

//! Process local storage
//! @tparam T
//!     Type to store
template <typename T>
class uixProcessLocalStorage
{
public:
    //! Delegate to create object
    typedef T* (*CreateObject)();
public:
    //! Constructor
    uixProcessLocalStorage()
        : m_Pointer(NULLPTR)
    {
    }

    //! Destructor
    ~uixProcessLocalStorage()
    {
        m_Pointer = NULLPTR;
    }

    //! Gets or create object using create object delegate
    //! @param[in] Delegate
    //!     Create object delegate
    //! @return
    //!     Pointer to object
    T* GetData(CreateObject Delegate)
    {
        T* object = m_Pointer;

        if (object)
        {
            delete object;
        }

        object = Delegate();

        m_Pointer = object;
        return object;
    }

    //! Gets pointer object
    //! @return
    //!     Pointer object
    T* GetData()
    {
        return m_Pointer;
    }

private:
    T*  m_Pointer;
};

//! Process local object
//! @tparam T
//!     Type to store
template <typename T>
class uixProcessLocal
{
public:
    //! Gets data
    //! @param[in] create
    //!     True to create, false to simply get stored pointer
    //! @return
    //!     Pointer to object
    T* GetData(BOOL create = TRUE)
    {
        T* object = m_Storage.GetData();

        if ((object == NULLPTR) && (create == TRUE))
        {
            object = m_Storage.GetData(uixProcessLocal::CreateObject);
        }

        return object;
    }

    //! Cast operator
    //! @return
    //!     Casted pointer
    operator T* ()
    {
        return GetData();
    }

    //! Dereference operator
    //! @return
    //!     Pointer data
    T* operator -> ()
    {
        return GetData();
    }

    //! Create object delegate
    static T* CreateObject()
    {
        return new T();
    }
private:
    uixProcessLocalStorage<T>   m_Storage;
};
}
//----------------------------------------------------------------------------//
#endif /* _UIX_PROCESS_H__ */