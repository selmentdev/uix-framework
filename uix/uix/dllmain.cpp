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
#include "uixrequired.h"
//----------------------------------------------------------------------------//
#include "uixinit.h"
#include "uixstate.h"

//----------------------------------------------------------------------------//
BOOL APIENTRY DllMain(
    HINSTANCE instance,
    DWORD reason,
    LPVOID reserved)
{
    uixUNREFERENCED(reserved);

    switch (reason)
    {
    case DLL_PROCESS_ATTACH:
        {
            UIX::UixInitializeCoreModule(instance);
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
            UIX::UixShutdownCoreModule();
        }
        break;
    }

    return TRUE;
}
//----------------------------------------------------------------------------//
// Force to compile:
#include "uixanimatectrl.h"
#include "uixapplication.h"
#include "uixbuttonctrl.h"
#include "uixcolordialog.h"
#include "uixconfig.h"
#include "uixdiagnostic.h"
#include "uixdialog.h"
#include "uixexception.h"
#include "uixfiledialog.h"
#include "uixframe.h"
#include "uixgdibitmap.h"
#include "uixgdibrush.h"
#include "uixgdidc.h"
#include "uixgdifont.h"
#include "uixgdipen.h"
#include "uixhotkeyctrl.h"
#include "uiximagelistctrl.h"
#include "uixinit.h"
#include "uixmacros.h"
#include "uixmenu.h"
#include "uixmessagemap.h"
#include "uixobject.h"
#include "uixpagescrollerctrl.h"
#include "uixrebarctrl.h"
#include "uixrequired.h"
#include "uixMetaClass.h"
#include "uixstate.h"
#include "uixstatusbarctrl.h"
#include "uixtextctrl.h"
#include "uixthreading.h"
#include "uixtoolbarctrl.h"
#include "uixtooltipctrl.h"
#include "uixtrace.h"
#include "uixtypes.h"
#include "uixview.h"
#include "uixwindow.h"
//----------------------------------------------------------------------------//