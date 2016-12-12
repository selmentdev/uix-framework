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
#ifndef _UIX_INIT_H__
#define _UIX_INIT_H__
//----------------------------------------------------------------------------//
#include "uixrequired.h"
#include "uixuithread.h"
#include "uixprocess.h"
//----------------------------------------------------------------------------//
namespace UIX
{
struct uixModuleState;

//! Runs application
//! @param[in] thisInstance
//!     This instance
//! @param[in] prevInstance
//!     Previous instance
//! @param[in] commandLine
//!     Command line text
//! @param[in] showCommand
//!     Show command
//! @return
//!     System result value
INT UIXAPI UixMain(
    HINSTANCE thisInstance,
    HINSTANCE prevInstance,
    const uixChar* commandLine,
    INT showCommand);

//! Initialize library
//! @param[in] thisInstance
//!     This instance handle
//! @param[in] prevInstance
//!     Previous instance handle
//! @param[in] commandLine
//!     CommandLine
//! @param[in] showCommand
//!     Show Command
//! @return
//!     True when successful
BOOL UIXAPI UixInitializeAppModule(
    HINSTANCE thisInstance,
    HINSTANCE prevInstance,
    const TCHAR* commandLine,
    INT showCommand);

//! Shutdowns library
//! @return
//!     True when successful
BOOL UIXAPI UixShutdownAppModule();

//! Executes application
//! @return
//!     Value returned from application
INT UIXAPI UixExecuteAppModule();

//! Initialize core module
//! @param[in] instance
//!     Core module handle
//! @return
//!     True when successful
BOOL UixInitializeCoreModule(HINSTANCE instance);

//! Shutdowns core module
//! @return
//!     True when successful
BOOL UixShutdownCoreModule();

//! Initialize extension module
//! @param[out] module
//!     Module state object
//! @param[in] instance
//!     Instance handle
//! @return
//!     True when successful
BOOL UIXAPI UixInitializeExtModule(uixModuleState& module, HINSTANCE instance, BOOL hasResources);

//! Shutdowns extension module
//! @param[in] module
//!     Module state object
//! @return
//!     True when successful
BOOL UIXAPI UixShutdownExtModule(uixModuleState& module);

//! Registers module in chain
//! @param[in] module
//!     Module pointer
//! @return
//!     True when successful
BOOL UIXAPI UixRegisterModule(uixModuleState* module);

//! Unregisters module in chain
//! @param[in] module
//!     Module pointer
//! @return
//!     True when successful
BOOL UIXAPI UixUnregisterModule(uixModuleState* module);
}
//----------------------------------------------------------------------------//
#define uixIMPLEMENT_APPLICATION(ApplicationClass)                              \
    ApplicationClass TheApplication;                                            \
    extern "C" INT WINAPI _tWinMain(                                            \
            HINSTANCE ThisInstance,                                                 \
            HINSTANCE PrevInstance,                                                 \
            TCHAR* CommandLine,                                                     \
            INT ShowCommand)                                                        \
    {                                                                           \
        _CrtSetDbgFlag(                                                         \
                _CRTDBG_ALLOC_MEM_DF |                                              \
                _CRTDBG_LEAK_CHECK_DF |                                             \
                _CRTDBG_CHECK_ALWAYS_DF |                                           \
                _CRTDBG_MODE_DEBUG);                                                \
        \
        return UIX::UixMain(                                                    \
                ThisInstance,                                                       \
                PrevInstance,                                                       \
                CommandLine,                                                        \
                ShowCommand);                                                       \
    }

//----------------------------------------------------------------------------//
#endif /* _UIX_INIT_H__ */