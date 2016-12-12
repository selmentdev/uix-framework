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
#include "uixresource.h"
#include "uixstate.h"
//----------------------------------------------------------------------------//
namespace UIX
{
//----------------------------------------------------------------------------//
HINSTANCE UixFindResourceHandle(uixResourceID id, UINT type)
{
    return UixFindResourceHandle(MAKEINTRESOURCE(id), MAKEINTRESOURCE(type));
}
//----------------------------------------------------------------------------//
HINSTANCE UixFindResourceHandle(uixResourceName name, UINT type)
{
    return UixFindResourceHandle(name, MAKEINTRESOURCE(type));
}
//----------------------------------------------------------------------------//
HINSTANCE UixFindResourceHandle(uixResourceID id, const uixChar* type)
{
    return UixFindResourceHandle(MAKEINTRESOURCE(id), type);
}
//----------------------------------------------------------------------------//
HINSTANCE UixFindResourceHandle(uixResourceName name, const uixChar* type)
{
    // Get current process state
    UIX::uixProcessState& ps = UIX::uixProcessState::Get();

    // Check application resource module
    if (ps.m_Resource != 0)
    {
        if (::FindResource(ps.m_Resource, name, type))
        {
            return ps.m_Resource;
        }
    }

    std::vector<HINSTANCE>  instances;

    // Pass 3. Push any additional modules
    UIX::uixModuleState* module = ps.m_ModuleListHead;

    // Locks module list
    uixProcessStateLock::Lock(uixProcessStateLock::Lock_ModuleList);

    // Iterate through all extended modules
    while (module != NULLPTR)
    {
        // Pass 3.1. Check module handle
        if (module->m_Handle != 0)
        {
            // Pass 3.1.1. Check for resource handle - 0 means no resources in module
            if (
                //(module->m_Resource != module->m_Handle) &&
                (module->m_Resource != 0)
            )
            {
                instances.push_back(module->m_Resource);
            }
        }

        module = module->m_NextModule;
    }

    // Unlocks module list
    uixProcessStateLock::Unlock(uixProcessStateLock::Lock_ModuleList);

    if (!instances.empty())
    {
        for (std::vector<HINSTANCE>::const_iterator it = instances.begin();
             it != instances.end();
             ++it)
        {
            if (::FindResource(*it, name, type))
            {
                return *it;
            }
        }
    }

    // Check core resource module
    if ((ps.m_CoreModule != NULLPTR) && (ps.m_CoreModule->m_Resource != 0))
    {
        if (::FindResource(ps.m_CoreModule->m_Resource, name, type))
        {
            return ps.m_CoreModule->m_Resource;
        }
    }

    // Failed to search for it
    //return ps.m_Handle;

    // Return system instance handle to notify user of this function, that this
    // resource wasn't found in active modules list
    return 0;
}
//----------------------------------------------------------------------------//
void* UixLockResource(HGLOBAL resourceData)
{
    return ::LockResource(resourceData);
}
//----------------------------------------------------------------------------//
void UixUnlockResource(HGLOBAL resourceData)
{
    UnlockResource(resourceData);
}
//----------------------------------------------------------------------------//
HRSRC UixFindResource(HINSTANCE instance, uixResourceName resource, const uixChar* type)
{
    return ::FindResource(instance, resource, type);
}
//----------------------------------------------------------------------------//
HRSRC UixFindResource(HINSTANCE instance, uixResourceID resourceID, UINT typeID)
{
    return ::FindResource(instance, MAKEINTRESOURCE(resourceID), MAKEINTRESOURCE(typeID));
}
//----------------------------------------------------------------------------//
HGLOBAL UixLoadResource(HINSTANCE instance, HRSRC resource)
{
    return ::LoadResource(instance, resource);
}
//----------------------------------------------------------------------------//
HICON UixLoadIcon(HINSTANCE instance, uixResourceID iconID)
{
    return ::LoadIcon(instance, MAKEINTRESOURCE(iconID));
}
//----------------------------------------------------------------------------//
HICON UixLoadIcon(HINSTANCE instance, uixResourceName iconName)
{
    return ::LoadIcon(instance, iconName);
}
//----------------------------------------------------------------------------//
HICON UixLoadIcon(uixResourceID iconID)
{
    HINSTANCE instance = UixFindResourceHandle(iconID, RT_ICON);

    if (instance == 0)
    {
        instance = UixFindResourceHandle(iconID, RT_GROUP_ICON);
    }

    return ::LoadIcon(
               instance,
               MAKEINTRESOURCE(iconID));
}
//----------------------------------------------------------------------------//
HICON UixLoadIcon(uixResourceName iconName)
{
    HINSTANCE instance = UixFindResourceHandle(iconName, RT_ICON);

    if (instance == 0)
    {
        instance = UixFindResourceHandle(iconName, RT_GROUP_ICON);
    }

    return ::LoadIcon(
               instance,
               iconName);
}
//----------------------------------------------------------------------------//
HBITMAP UixLoadImage(HINSTANCE instance, uixResourceID imageID)
{
    return (HBITMAP)::LoadImage(instance, MAKEINTRESOURCE(imageID), IMAGE_BITMAP, 0, 0, 0);
}
//----------------------------------------------------------------------------//
HBITMAP UixLoadImage(HINSTANCE instance, uixResourceName imageName)
{
    return (HBITMAP)::LoadImage(instance, imageName, IMAGE_BITMAP, 0, 0, 0);
}
//----------------------------------------------------------------------------//
HBITMAP UixLoadImage(uixResourceID imageID)
{
    HINSTANCE instance = UixFindResourceHandle(imageID, RT_BITMAP);

    if (instance == 0)
    {
        instance = UixFindResourceHandle(imageID, RT_BITMAP);
    }

    return UixLoadImage(
               instance,
               MAKEINTRESOURCE(imageID));
}
//----------------------------------------------------------------------------//
HBITMAP UixLoadImage(uixResourceName imageName)
{
    HINSTANCE instance = UixFindResourceHandle(imageName, RT_BITMAP);

    if (instance == 0)
    {
        instance = UixFindResourceHandle(imageName, RT_BITMAP);
    }

    return UixLoadImage(
               instance,
               imageName);
}
//----------------------------------------------------------------------------//
HINSTANCE UixLoadLibrary(const uixChar* libFileName)
{
    // Lock module list before load call
    uixProcessStateLock::Lock(uixProcessStateLock::Lock_ModuleList);
    // Load library
    HINSTANCE result = ::LoadLibrary(libFileName);
    // Unlock module list
    uixProcessStateLock::Unlock(uixProcessStateLock::Lock_ModuleList);

    return result;
}
//----------------------------------------------------------------------------//
BOOL UixFreeLibrary(HINSTANCE instance)
{
    // Lock module list before load call
    uixProcessStateLock::Lock(uixProcessStateLock::Lock_ModuleList);
    // Load library
    BOOL result = ::FreeLibrary(instance);
    // Unlock module list
    uixProcessStateLock::Unlock(uixProcessStateLock::Lock_ModuleList);

    return result;
}
//----------------------------------------------------------------------------//
uixString UixLoadString(uixResourceID resourceID)
{
    HINSTANCE instance = UixFindResourceHandle(resourceID, RT_STRING);
    WORD* length = NULLPTR;
    LPTSTR str = NULLPTR;
    INT ret = ::LoadString(instance, resourceID, str, 0);
    (void)ret;
    length = (WORD*)str;
    --length;

    if (str != NULLPTR)
    {
        return uixString(str, 0, *length);
    }

    return uixString();
}
//----------------------------------------------------------------------------//
}
//----------------------------------------------------------------------------//