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
#ifndef _UIX_STATE_H__
#define _UIX_STATE_H__
//----------------------------------------------------------------------------//
#include "uixrequired.h"
#include "uixtypes.h"
#include "uixprocess.h"
//----------------------------------------------------------------------------//
namespace UIX
{
class uixThread;
class uixUiThread;
class uixWindow;
struct uixModuleState;
class uixApplication;

//! Current thread state
//! @brief
//!     Thread state represent state of current thread. It allows to use many
//!     thread loops in application.
struct UIXAPI uixThreadState : uixProcessLocalObject
{
    //! Constructor
    uixThreadState()
    {
        ZeroMemory(this, sizeof(uixThreadState));
    }

    //! Gets instance of this structure per thread
    static uixThreadState& Get();

    //! Currently processed message
    MSG             m_CurrentMsg;
    //! Last cursor position
    uixPoint        m_LastCursorPos;
    //! Last processed message
    UINT            m_LastMsg;
    //! Pointer to current thread
    uixUiThread*    m_CurrentThread;
    //! Last sent message
    MSG             m_LastSentMsg;

    //! Create window hook
    HHOOK           m_CreateWindowHook_Handle;
    //! Create window hook pointer
    uixWindow*      m_CreateWindowHook_Window;
};

//! Gets current thread state
//! @return
//!     Reference to thread state object for current thread
UIXINLINE uixThreadState& UixGetThreadState()
{
    return uixThreadState::Get();
}

//! Gets current thread pointer object
//! @return
//!     Pointer to current thread object
//! @remarks
//!     Returned pointer may be null, since thread object is not created
//!     for all threads by default
UIXINLINE uixThread* UixGetCurrentThread()
{
    return (uixThread*)uixThreadState::Get().m_CurrentThread;
}

//! Module state
struct uixModuleState : uixProcessLocalObject
{
    //! Module state
    uixModuleState()
        : m_Handle(NULLPTR)
        , m_Resource(NULLPTR)
        , m_LangResource(NULLPTR)
        , m_NextModule(NULLPTR)
        , m_IsCore(FALSE)
        , m_Initialized(FALSE)
    {
    }

    //! Module handle
    HMODULE             m_Handle;
    //! Module handle with resource
    //! @note
    //!     When module sets this handle to zero, it means that module has no resources
    HMODULE             m_Resource;
    //! Language module handle
    HMODULE             m_LangResource;
    //! Next module pointer
    uixModuleState*     m_NextModule;
    //! Specify if module is core module or user module
    BOOL                m_IsCore;
    BOOL                m_Initialized;
};

//! Process state lock
class UIXAPI uixProcessStateLock
{
public:
    enum
    {
        //! Module list lock
        Lock_ModuleList = 0,
        //! Max lock list count
        Lock_MaxCount,
    };

    //! Initializes process state lock
    //! @return
    //!     True when successful
    static BOOL Initialize();

    //! Terminate process state lock
    static void Terminate();

    //! Begins specified type lock
    //! @param[in] type
    //!     Lock type
    static void Lock(UINT type);

    //! Ends specified type lock
    //! @param[in] type
    //!     Lock type
    static void Unlock(UINT type);
public:
    //! Lock for initializing all specialized locks
    static ::CRITICAL_SECTION   ms_Lock;
    //! Specialized locks
    static ::CRITICAL_SECTION   ms_Locks[Lock_MaxCount];
    //! Is lock initialized
    static BOOL                 ms_LockInitialized[Lock_MaxCount];
    //! Is lock locked
    static BOOL                 ms_LockLocked[Lock_MaxCount];
    //! Is whole subsystem initialized
    static BOOL                 ms_Initialized;
};

//! Process state
//! @brief
//!     This struct holds all data needed by process to run application
struct UIXAPI uixProcessState : uixProcessLocalObject
{
    uixProcessState()
        : m_Application(NULLPTR)
        , m_Handle(0)
        , m_Resource(0)
        , m_LangResource(0)
        , m_ModuleListHead(NULLPTR)
        , m_CoreModule(NULLPTR)
    {
    }

    static uixProcessState& Get();

    //! Current application pointer
    uixApplication*     m_Application;

    //! Application module handle
    HMODULE             m_Handle;
    //! Module handle with resource
    //! @note
    //!     When module sets this handle to zero, it means that module has no resources
    HMODULE             m_Resource;
    //! Additional language resource module handle
    HMODULE             m_LangResource;
    //! Pointer to resource chain
    uixModuleState*     m_ModuleListHead;
    //! Pointer to core module
    uixModuleState*     m_CoreModule;
};

//! Gets process state object
//! @return
//!     Current process state object
UIXINLINE uixProcessState& UixGetProcessState()
{
    return uixProcessState::Get();
}

//! Gets current application pointer
//! @return
//!     Pointer to current application object
UIXINLINE uixApplication* UixGetCurrentApp()
{
    return uixProcessState::Get().m_Application;
}
}
//----------------------------------------------------------------------------//
#endif /* _UIX_STATE_H__ */