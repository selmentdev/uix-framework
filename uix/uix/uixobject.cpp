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
#include "uixobject.h"
#include "uixdump.h"
//----------------------------------------------------------------------------//
namespace UIX
{
//----------------------------------------------------------------------------//
uixMetaClass uixObject::uixCLASS_NAME(uixObject)("uixObject", NULLPTR, sizeof(uixObject), NULLPTR);
//----------------------------------------------------------------------------//
const uixMetaClass* uixObject::GetMetaClass() const
{
    return &uixObject::uixCLASS_NAME(uixObject);
}
//----------------------------------------------------------------------------//
BOOL uixObject::IsDerivedFrom(const uixMetaClass* RuntimeClass) const
{
    const uixMetaClass* ThisClass = GetMetaClass();

    if (ThisClass != NULLPTR)
    {
        return ThisClass->IsDerivedFrom(RuntimeClass);
    }

    return FALSE;
}
//----------------------------------------------------------------------------//
#if defined UIX_DEBUG
//----------------------------------------------------------------------------//
void uixObject::ValidateObject() const
{
    // Do Nothing
}
//----------------------------------------------------------------------------//
void uixObject::DumpObject(UIX::uixDumpContext& ctx) const
{
}
#endif
//----------------------------------------------------------------------------//
}
//----------------------------------------------------------------------------//