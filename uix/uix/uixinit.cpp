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
#include "uixinit.h"
#include "uixapplication.h"
#include "uixstate.h"
//----------------------------------------------------------------------------//
namespace UIX
{
//----------------------------------------------------------------------------//
INT UixMain(
    HINSTANCE thisInstance,
    HINSTANCE prevInstance,
    const uixChar* commandLine,
    INT showCommand)
{
    INT result = 0;

    if (!UixInitializeAppModule(
            thisInstance,
            prevInstance,
            commandLine,
            showCommand))
    {
        goto Failed;
    }

    result = UixExecuteAppModule();

Failed:
    UixShutdownAppModule();
    return result;
}
//----------------------------------------------------------------------------//
BOOL UixInitializeAppModule(
    HINSTANCE ThisInstance,
    HINSTANCE PrevInstance,
    const TCHAR* CommandLine,
    INT ShowCommand)
{
    // Initialize COM module
    HRESULT hr = CoInitializeEx(0, COINIT_APARTMENTTHREADED);

    if (FAILED(hr))
    {
        throw uixInvalidOperationException(hr, _("Cannot initialize COM module"));
    }


    uixASSERT(PrevInstance == 0);

    uixProcessState& ps = uixProcessState::Get();

    // This module handle
    ps.m_Handle = ThisInstance;
    // We assume that resources are in this module too
    ps.m_Resource = ThisInstance;
    ps.m_LangResource = 0;

    uixApplication* app = ps.m_Application;

    if (app)
    {
        app->InitializeHandles(ThisInstance, CommandLine, ShowCommand);
    }

    return TRUE;
}
//----------------------------------------------------------------------------//
BOOL UixShutdownAppModule()
{
    //! @todo Free any TLS'es and process states

    return TRUE;
}
//----------------------------------------------------------------------------//
INT UixExecuteAppModule()
{
    INT result = 0;

    uixApplication* app = UixGetCurrentApp();

    if (!app->InitInstance())
    {
        result = (INT)app->ExitInstance();
        goto Failure;
    }

    result = (INT)app->Run();

Failure:
    return result;
}
//----------------------------------------------------------------------------//
uixModuleState  gs_CoreModule;
//----------------------------------------------------------------------------//
BOOL UixInitializeCoreModule(HINSTANCE instance)
{
    uixASSERT(uixProcessState::Get().m_CoreModule == NULLPTR);
    uixASSERT(gs_CoreModule.m_Handle == 0);
    uixASSERT(gs_CoreModule.m_Resource == 0);
    uixASSERT(gs_CoreModule.m_NextModule == NULLPTR);
    uixASSERT(gs_CoreModule.m_IsCore == FALSE);
    uixASSERT(gs_CoreModule.m_Initialized == FALSE);

    gs_CoreModule.m_Handle = instance;
    // This module also contains resources
    gs_CoreModule.m_Resource = instance;
    gs_CoreModule.m_NextModule = NULLPTR;
    gs_CoreModule.m_IsCore = TRUE;
    gs_CoreModule.m_Initialized = TRUE;

    uixProcessState::Get().m_CoreModule = &gs_CoreModule;

    return TRUE;
}
//----------------------------------------------------------------------------//
BOOL UixShutdownCoreModule()
{
    uixASSERT(uixProcessState::Get().m_CoreModule != NULLPTR);
    uixASSERT(gs_CoreModule.m_Handle != 0);
    uixASSERT(gs_CoreModule.m_IsCore == TRUE);
    uixASSERT(gs_CoreModule.m_Initialized == TRUE);

    gs_CoreModule.m_Initialized = FALSE;
    return TRUE;
}
//----------------------------------------------------------------------------//
BOOL UixInitializeExtModule(uixModuleState& module, HINSTANCE instance, BOOL hasResources)
{
    uixASSERT(module.m_Handle == 0);
    uixASSERT(module.m_Resource == 0);
    uixASSERT(module.m_NextModule == NULLPTR);
    uixASSERT(module.m_IsCore == FALSE);
    uixASSERT(module.m_Initialized == FALSE);

    module.m_Handle = instance;

    if (hasResources)
    {
        module.m_Resource = instance;
    }
    else
    {
        module.m_Resource = 0;
    }

    module.m_NextModule = NULLPTR;
    module.m_IsCore = FALSE;
    module.m_Initialized = TRUE;

    return UixRegisterModule(&module);
}
//----------------------------------------------------------------------------//
BOOL UixShutdownExtModule(uixModuleState& module)
{
    uixASSERT(module.m_Handle != 0);
    uixASSERT(module.m_IsCore == FALSE);
    uixASSERT(module.m_Initialized == TRUE);

    module.m_Initialized = FALSE;

    return UixUnregisterModule(&module);
}
//----------------------------------------------------------------------------//
BOOL UixRegisterModule(uixModuleState* module)
{
    uixASSERT(module != NULLPTR);
    uixASSERT(module->m_NextModule == NULLPTR);
    uixASSERT(module->m_Handle != 0);

    // Get process state
    uixProcessState& ps = uixProcessState::Get();

    if (ps.m_ModuleListHead == NULLPTR)
    {
        // Case 1: no modules at list
        ps.m_ModuleListHead = module;
    }
    else
    {
        // Case 2: there are some modules at list
        uixModuleState* current = ps.m_ModuleListHead;

        // Iterate through all modules
        while (current->m_NextModule != NULLPTR)
        {
            current = current->m_NextModule;
        }

        current->m_NextModule = module;
        module->m_NextModule = NULLPTR;
    }

    return TRUE;
}
//----------------------------------------------------------------------------//
BOOL UixUnregisterModule(uixModuleState* module)
{
    uixASSERT(module != NULLPTR);
    uixASSERT(module->m_Handle != 0);

    // Get process state
    uixProcessState& ps = uixProcessState::Get();

    if (ps.m_ModuleListHead == NULLPTR)
    {
        // Case 1: No modules at list
        return FALSE;
    }
    else
    {
        // Case 2: Erase one of modules at list

        if (module == ps.m_ModuleListHead)
        {
            // Case 2.1: Erase first module at list
            ps.m_ModuleListHead = ps.m_ModuleListHead->m_NextModule;
        }
        else
        {
            // Case 2.2: More complicated
            uixModuleState* current = ps.m_ModuleListHead->m_NextModule;
            uixModuleState* previous = ps.m_ModuleListHead;

            while ((current != NULLPTR) && (current != module))
            {
                previous = current;
                current = current->m_NextModule;
            }

            if (current == module)
            {
                uixASSERT(previous != NULLPTR);
                uixASSERT(current != NULLPTR);

                previous->m_NextModule = current->m_NextModule;
            }
            else
            {
                return FALSE;
            }
        }
    }

    return TRUE;
}
//----------------------------------------------------------------------------//
}
//----------------------------------------------------------------------------//