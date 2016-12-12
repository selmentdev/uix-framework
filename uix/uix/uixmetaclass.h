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
#ifndef _UIX_METACLASS_H__
#define _UIX_METACLASS_H__
//----------------------------------------------------------------------------//
#include "uixrequired.h"
//----------------------------------------------------------------------------//
namespace UIX
{
// Forward declaration of base object
class uixObject;

//! Run time object construction delegate
typedef uixObject* (*uixCreateObjectDelegate)();

//! Meta class
//! @brief
//!     This class implements meta class info
class UIXAPI uixMetaClass
{
private:
    //! Class name
    const char*                 m_ClassName;
    //! Base class
    const uixMetaClass*         m_BaseClass;
    //! Size
    int                         m_Size;
    //! Create object delegate
    uixCreateObjectDelegate     m_CreateObjectDelegate;
public:
    //! Constructor
    //! @param[in] ClassName
    //!     Class name
    //! @param[in] BaseClass
    //!     Pointer to base class
    //! @param[in] Size
    //!     Size of described object
    //! @param[in] CreateObjectDelegate
    //!     Delegate used to create instance of object
    uixMetaClass(const char* ClassName, const uixMetaClass* BaseClass,
                 int Size, uixCreateObjectDelegate CreateObjectDelegate);

    //! Destructor
    ~uixMetaClass();

    //! Create instance of object
    //! @return
    //!     Created object or NULLPTR when described class is not dynamic class
    uixObject* Create() const;

    //! Checks if class is dynamic
    //! @return
    //!     True when successful
    BOOL IsDynamic() const;

    //! Checks if class is derived from another class
    //! @param[in] Class
    //!     Class to check
    //! @return
    //!     true when successful
    BOOL IsDerivedFrom(const uixMetaClass* Class) const;

    //! Gets name of class
    //! @return
    //!     Class name
    const char* GetName() const;

    //! Gets pointer to base class
    //! @return
    //!     Base class meta object
    const uixMetaClass* GetBaseClass() const;

    //! Gets object size
    //! @return
    //!     Size of class
    int GetSize() const;

    //! Gets create object delegate
    //! @return
    //!     Create object delegate
    uixCreateObjectDelegate GetCreateObjectDelegate() const;
};
}
//----------------------------------------------------------------------------//
#if 0
#   define uixCLASS_NAME(Class) class ## Class
#else
#   define uixCLASS_NAME(Class) metaClass
#endif
//----------------------------------------------------------------------------//
#define uixDECLARE_ABSTRACT_CLASS(Class) \
    public: \
    static ::UIX::uixMetaClass uixCLASS_NAME(Class); \
    virtual const ::UIX::uixMetaClass* GetMetaClass() const;
//----------------------------------------------------------------------------//
#define uixDECLARE_CLASS(Class) \
    uixDECLARE_ABSTRACT_CLASS(Class)
//----------------------------------------------------------------------------//
#define uixDECLARE_DYNAMIC_CLASS(Class) \
    uixDECLARE_ABSTRACT_CLASS(Class) \
    static ::UIX::uixObject* CreateObject();
//----------------------------------------------------------------------------//
#define uixIMPLEMENT_CLASS_COMMON(Class, BaseClass, CreateObjectDelegate) \
    ::UIX::uixMetaClass Class::uixCLASS_NAME(Class)(#Class, &BaseClass::uixCLASS_NAME(BaseClass), (int)sizeof(Class), CreateObjectDelegate); \
    const ::UIX::uixMetaClass* Class::GetMetaClass() const { return &Class::uixCLASS_NAME(Class); }
//----------------------------------------------------------------------------//
#define uixIMPLEMENT_ABSTRACT_CLASS(Class, BaseClass) \
    uixIMPLEMENT_CLASS_COMMON(Class, BaseClass, NULLPTR)
//----------------------------------------------------------------------------//
#define uixIMPLEMENT_DYNAMIC_CLASS(Class, BaseClass) \
    uixIMPLEMENT_CLASS_COMMON(Class, BaseClass, Class::CreateObject) \
    ::UIX::uixObject* Class::CreateObject() { return new Class(); }
//----------------------------------------------------------------------------//
#define uixMETA_CLASS(Class) \
    (&Class::uixCLASS_NAME(Class))
//----------------------------------------------------------------------------//
#define uixDYNAMIC_CAST(Class, Object) \
    ((Class*)::UIX::UixDynamicCast(Object, uixMETA_CLASS(Class)))
//----------------------------------------------------------------------------//
#define uixDYNAMIC_CAST_THIS(Class) \
    uixDYNAMIC_CAST(Class, this)
//----------------------------------------------------------------------------//
#define uixIS_DERIVED_FROM(Object, Class) \
    ((Object)->IsDerivedFrom(uixMETA_CLASS(Class)))
//----------------------------------------------------------------------------//
#include "uixMetaClass.inl"
//----------------------------------------------------------------------------//
#endif /* _UIX_METACLASS_H__ */