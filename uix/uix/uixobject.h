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
#ifndef _UIX_OBJECT_H__
#define _UIX_OBJECT_H__
//----------------------------------------------------------------------------//
#include "uixMetaClass.h"
//----------------------------------------------------------------------------//
namespace UIX
{
class uixDumpContext;

//! Base object class
//! @brief
//!     Base class for all classes in framework
class UIXAPI UIX_NOVTABLE uixObject
{
public:
    static ::UIX::uixMetaClass uixCLASS_NAME(uixObject);
    virtual const ::UIX::uixMetaClass* GetMetaClass() const;
public:
    //! Destructor
    virtual ~uixObject() {}

    //! Check if object is derived from another class type
    //! @param[in] RuntimeClass
    //!     Other meta class
    //! @return
    //!     True when successful
    BOOL IsDerivedFrom(const uixMetaClass* RuntimeClass) const;

#if defined UIX_DEBUG
    //! Validate object
    virtual void ValidateObject() const;

    virtual void DumpObject(uixDumpContext& ctx) const;
#endif

protected:
    //! Protected constructor to prevent object creation on stack
    uixObject() {}
private:
    //! Private copy constructor
    uixObject(const uixObject&);

    //! Private assigment operator
    //! @return
    //!     This object
    uixObject& operator = (const uixObject&);
};
}
//----------------------------------------------------------------------------//
#include "uixobject.inl"
//----------------------------------------------------------------------------//
#endif /* _UIX_OBJECT_H__ */