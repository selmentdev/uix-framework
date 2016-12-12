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
#ifndef _UIX_THREADING_H__
#define _UIX_THREADING_H__
//----------------------------------------------------------------------------//
#include "uixrequired.h"
#include "uixobject.h"
#include "uixexception.h"
//----------------------------------------------------------------------------//
namespace UIX
{
//! Thread local object
template <typename TType>
class uixThreadLocalStorage
{
public:
    //! Create object functor type
    typedef TType* (*CreateObject)();
public:
    //! Constructor
    uixThreadLocalStorage()
    {
        m_Slot = TlsAlloc();
    }

    //! Destructor
    ~uixThreadLocalStorage()
    {
        TlsFree(m_Slot);
    }

    //! Gets data
    //! @param[in] Delegate
    //!     Delegate which create object
    //! @return
    //!     Created or retrieved object
    TType* GetData(CreateObject Delegate)
    {
        TType* Object = (TType*)TlsGetValue(m_Slot);

        if (Object)
        {
            delete Object;
        }

        Object = Delegate();

        TlsSetValue(m_Slot, Object);
        return Object;
    }

    //! Gets data
    //! @return
    //!     Data
    TType* GetData()
    {
        return (TType*)TlsGetValue(m_Slot);
    }
private:
    DWORD m_Slot;   //!< TLS slot index
};

//! Thread local storage
template <typename TType>
class uixThreadLocal
{
public:
    //! Gets data
    //! @param[in] create
    //!     Create flag
    //! @return
    //!     Created or retrieved object
    TType* GetData(BOOL create = TRUE)
    {
        TType* Object = m_Object.GetData();

        if ((Object == NULLPTR) && (create == TRUE))
        {
            Object = m_Object.GetData(uixThreadLocal<TType>::CreateObject);
        }

        return Object;
    }

    //! Cast operator
    operator TType* ()
    {
        return GetData();
    }

    //! Dereference operator
    TType* operator -> ()
    {
        return GetData();
    }

    //! Create object static functor
    static TType* CreateObject()
    {
        return new TType();
    }

private:
    //! TLS object
    uixThreadLocalStorage<TType>        m_Object;
};

class uixWindow;

//!@note Partially implemented, may change
class UIXAPI uixThread : public uixObject
{
    uixDECLARE_DYNAMIC_CLASS(uixThread);
protected:
    HANDLE          m_ThreadHandle; //!< Thread Handle
    DWORD           m_ThreadID;     //!< Thread ID
public:
    //! Constructor
    uixThread();

    //! Destructor
    virtual ~uixThread();

    //! Suspends thread
    //! @return
    //!     Flags
    DWORD SuspendThread();

    //! Resume thread
    //! @return
    //!     Flags
    DWORD ResumeThread();

    LCID GetThreadLocale() const
    {
        return ::GetThreadLocale();
    }

    BOOL SetThreadLocale(LCID languageID)
    {
        return ::SetThreadLocale(languageID);
    }
};

//! Synchronization object base
class uixThreadSyncObject : public uixObject
{
    uixDECLARE_ABSTRACT_CLASS(uixThreadSyncObject);
public:
    //! Destructor
    virtual ~uixThreadSyncObject() {}

    //! Locks object
    //! @return
    //!     True when successful
    virtual BOOL Lock() = 0;

    //! tries to lock object
    //! @return
    //!     True when successful
    virtual BOOL TryLock() = 0;

    //! Unlocks object
    //! @return
    //!     True when successful
    virtual BOOL Unlock() = 0;
};

//! Critical section
class uixCriticalSection : public uixThreadSyncObject
{
public:
    //! Constructor
    uixCriticalSection()
    {
        InitializeCriticalSection(&m_CriticalSection);
    }

    //! Destructor
    virtual ~uixCriticalSection()
    {
        DeleteCriticalSection(&m_CriticalSection);
    }

    //! @copydoc uixThreadSyncObject::Lock
    BOOL Lock() override
    {
        uixASSERT(this != NULLPTR);
        EnterCriticalSection(&m_CriticalSection);
        return TRUE;
    }

    //! @copydoc uixThreadSyncObject::TryLock
    BOOL TryLock() override
    {
        uixASSERT(this != NULLPTR);
        return TryEnterCriticalSection(&m_CriticalSection);
    }

    //! @copydoc uixThreadSyncObject::Unlock
    BOOL Unlock() override
    {
        uixASSERT(this != NULLPTR);
        LeaveCriticalSection(&m_CriticalSection);
        return TRUE;
    }
protected:
    //! Copy Constructor
    uixCriticalSection(const uixCriticalSection&);
    //! Assigment operator
    uixCriticalSection& operator = (const uixCriticalSection&);

    CRITICAL_SECTION    m_CriticalSection;  //!< Critical section object
};

//! Semaphore
class uixSemaphore : public uixThreadSyncObject
{
public:
    //! Constructor
    //! @param[in] maxCount
    //!     Max semaphore count
    //! @param[in] initialCount
    //!     Initial count value
    //! @param[in] name
    //!     Semaphore name
    uixSemaphore(LONG maxCount, LONG initialCount = 0, const uixChar* name = NULLPTR)
    {
        m_Handle = CreateSemaphore(NULLPTR, initialCount, maxCount, name);
        uixASSERT(m_Handle != 0);
    }

    //! Destructor
    virtual ~uixSemaphore()
    {
        uixASSERT(m_Handle != 0);
        CloseHandle(m_Handle);
    }

    //! @copydoc uixThreadSyncObject::Lock
    BOOL Lock() override
    {
        uixASSERT(this != NULLPTR);
        uixASSERT(m_Handle != 0);
        ::WaitForSingleObject(m_Handle, INFINITE);
        return TRUE;
    }

    //! @copydoc uixThreadSyncObject::TryLock
    BOOL TryLock() override
    {
        uixASSERT(this != NULLPTR);
        uixASSERT(m_Handle != 0);
        DWORD result = ::WaitForSingleObject(m_Handle, 0);
        return (BOOL)(result == WAIT_OBJECT_0);
    }

    //! @copydoc uixThreadSyncObject::Unlock
    BOOL Unlock(INT count = 1)
    {
        uixASSERT(this != NULLPTR);
        uixASSERT(m_Handle != 0);
        return ::ReleaseSemaphore(m_Handle, count, NULLPTR);
    }

protected:
    //! Copy Constructor
    uixSemaphore(const uixSemaphore&);
    //! Assigment operator
    uixSemaphore& operator = (const uixSemaphore&);

    HANDLE  m_Handle;   //!< Handle
};

//! Mutex
class uixMutex : public uixThreadSyncObject
{
public:
    //! Constructor
    //! @param[in] owner
    //!     Is application owner of mutex?
    //! @param[in] name
    //!     Mutex name
    uixMutex(BOOL owner, const uixChar* name = NULLPTR)
    {
        m_Handle = ::CreateMutex(NULLPTR, owner, name);
    }

    //! Destructor
    virtual ~uixMutex()
    {
        uixASSERT(m_Handle != 0);
        CloseHandle(m_Handle);
    }

    //! @copydoc uixThreadSyncObject::Lock
    BOOL Lock() override
    {
        uixASSERT(this != NULLPTR);
        uixASSERT(m_Handle != 0);
        ::WaitForSingleObject(m_Handle, INFINITE);
        return TRUE;
    }

    //! @copydoc uixThreadSyncObject::TryLock
    BOOL TryLock() override
    {
        uixASSERT(this != NULLPTR);
        uixASSERT(m_Handle != 0);
        DWORD result = ::WaitForSingleObject(m_Handle, 0);
        return (BOOL)(result == WAIT_OBJECT_0);
    }

    //! @copydoc uixThreadSyncObject::Unlock
    BOOL Unlock() override
    {
        uixASSERT(this != NULLPTR);
        uixASSERT(m_Handle != 0);
        ::ReleaseMutex(m_Handle);
        return TRUE;
    }

protected:
    //! Copy Constructor
    uixMutex(const uixMutex&);
    //! Assigment operator
    uixMutex& operator = (const uixMutex&);

    HANDLE  m_Handle;   //!< Handle
};

//! Scoped lock
class uixScopedLock
{
public:
    //! Constructor
    //! @param[in] lock
    //!     Pointer to lock
    uixScopedLock(uixThreadSyncObject* lock)
        : m_Lock(lock)
    {
        uixASSERT(m_Lock != NULLPTR);

        m_Lock->Lock();
    }

    //! Destructor
    ~uixScopedLock()
    {
        uixASSERT(m_Lock != NULLPTR);
        m_Lock->Unlock();
    }

private:
    uixThreadSyncObject*    m_Lock;     //!< Lock
};
}
//----------------------------------------------------------------------------//
#endif /* _UIX_THREADING_H__ */