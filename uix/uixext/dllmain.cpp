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
#include "uixextrequired.h"
//----------------------------------------------------------------------------//
#include <uixinit.h>
#include <uixstate.h>
//----------------------------------------------------------------------------//
UIX::uixModuleState gs_UixExtModule;
//----------------------------------------------------------------------------//
BOOL APIENTRY DllMain(HINSTANCE instance,
                      DWORD reason,
                      LPVOID /*Reserved*/)
{
    switch (reason)
    {
    case DLL_PROCESS_ATTACH:
        {
            UIX::UixInitializeExtModule(gs_UixExtModule, instance, TRUE);
            break;
        }

    case DLL_THREAD_ATTACH:
        {
            break;
        }

    case DLL_THREAD_DETACH:
        {
            break;
        }

    case DLL_PROCESS_DETACH:
        {
            UIX::UixShutdownExtModule(gs_UixExtModule);
        }
        break;
    }

    return TRUE;
}