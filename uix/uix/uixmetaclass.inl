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
#ifndef _UIX_METACLASS_INL__
#define _UIX_METACLASS_INL__
//----------------------------------------------------------------------------//
#include "uixMetaClass.h"
//----------------------------------------------------------------------------//
namespace UIX
{
//----------------------------------------------------------------------------//
UIXINLINE uixMetaClass::uixMetaClass(const char* ClassName,
                                     const uixMetaClass* BaseClass,
                                     int Size,
                                     uixCreateObjectDelegate CreateObjectDelegate
                                    )
    : m_ClassName(ClassName)
    , m_BaseClass(BaseClass)
    , m_Size(Size)
    , m_CreateObjectDelegate(CreateObjectDelegate)
{
}
//----------------------------------------------------------------------------//
UIXINLINE uixMetaClass::~uixMetaClass()
{
}
//----------------------------------------------------------------------------//
UIXINLINE uixObject* uixMetaClass::Create() const
{
    if (m_CreateObjectDelegate == NULLPTR)
    {
        uixTRACE(_("Invoked runtime constructor, but no create object delegate found"));
        return NULLPTR;
    }

    uixObject* Object = NULLPTR;

    try
    {
        Object = m_CreateObjectDelegate();
    }
    catch (...)
    {
        uixTRACE(_("Exception thrown while object delegate invocation"));
        Object = NULLPTR;
    }

    return Object;
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixMetaClass::IsDynamic() const
{
    return m_CreateObjectDelegate != NULLPTR;
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixMetaClass::IsDerivedFrom(const uixMetaClass* Class) const
{
    if (Class != NULLPTR)
    {
        return (Class == this) ||
               (m_BaseClass && m_BaseClass->IsDerivedFrom(Class));
    }

    return FALSE;
}
//----------------------------------------------------------------------------//
UIXINLINE const char* uixMetaClass::GetName() const
{
    return m_ClassName;
}
//----------------------------------------------------------------------------//
UIXINLINE const uixMetaClass* uixMetaClass::GetBaseClass() const
{
    return m_BaseClass;
}
//----------------------------------------------------------------------------//
UIXINLINE int uixMetaClass::GetSize() const
{
    return m_Size;
}
//----------------------------------------------------------------------------//
UIXINLINE uixCreateObjectDelegate uixMetaClass::GetCreateObjectDelegate() const
{
    return m_CreateObjectDelegate;
}
//----------------------------------------------------------------------------//
}
//----------------------------------------------------------------------------//
#endif /* _UIX_METACLASS_INL__ */