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
#include "uixstate.h"
#include "uixthreading.h"
//----------------------------------------------------------------------------//
namespace UIX
{
//----------------------------------------------------------------------------//
namespace
{
static uixProcessLocal<uixProcessState>     gs_ProcessState;
static uixThreadLocal<uixThreadState>       gs_ThreadState;
}
//----------------------------------------------------------------------------//
uixProcessState& uixProcessState::Get()
{
    return *(gs_ProcessState.GetData());
}
//----------------------------------------------------------------------------//
uixThreadState& uixThreadState::Get()
{
    return (*gs_ThreadState.GetData());
}
//----------------------------------------------------------------------------//
// Process State Lock
//----------------------------------------------------------------------------//
BOOL uixProcessStateLock::Initialize()
{
    if (!ms_Initialized)
    {
        ms_Initialized = TRUE;
        ::InitializeCriticalSection(&ms_Lock);
    }

    return ms_Initialized;
}
//----------------------------------------------------------------------------//
void uixProcessStateLock::Terminate()
{
    if (ms_Initialized)
    {
        ms_Initialized = FALSE;

        ::DeleteCriticalSection(&ms_Lock);

        for (UINT i = 0; i < Lock_MaxCount; ++i)
        {
            uixASSERT(!ms_LockLocked[i]);

            if (ms_LockInitialized[i])
            {
                ::DeleteCriticalSection(&ms_Locks[i]);
                ms_LockInitialized[i] = FALSE;
            }
        }
    }
}
//----------------------------------------------------------------------------//
void uixProcessStateLock::Lock(UINT type)
{
    uixASSERT(type < Lock_MaxCount);

    Initialize();

    if (!ms_LockInitialized[type])
    {
        ::EnterCriticalSection(&ms_Lock);

        // Double check used.
        //!@todo Use something better and faster!
        if (!ms_LockInitialized[type])
        {
            ::InitializeCriticalSection(&ms_Locks[type]);
            ms_LockInitialized[type] = TRUE;
        }

        ::LeaveCriticalSection(&ms_Lock);
    }

    ::EnterCriticalSection(&ms_Locks[type]);

    ms_LockLocked[type] = TRUE;
    uixASSERT(ms_LockLocked[type] != FALSE);
}
//----------------------------------------------------------------------------//
void uixProcessStateLock::Unlock(UINT type)
{
    uixASSERT(ms_Initialized);
    uixASSERT(type < Lock_MaxCount);

    uixASSERT(ms_LockInitialized[type]);

    ms_LockLocked[type] = TRUE;

    ::LeaveCriticalSection(&ms_Locks[type]);
}
//----------------------------------------------------------------------------//
UIXAPI ::CRITICAL_SECTION   uixProcessStateLock::ms_Lock = {0};
UIXAPI ::CRITICAL_SECTION   uixProcessStateLock::ms_Locks[] = {{0}};
UIXAPI BOOL                 uixProcessStateLock::ms_LockInitialized[] = {{0}};
UIXAPI BOOL                 uixProcessStateLock::ms_LockLocked[] = {{0}};
UIXAPI BOOL                 uixProcessStateLock::ms_Initialized = FALSE;
//----------------------------------------------------------------------------//
}
//----------------------------------------------------------------------------//