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
#ifndef _UIX_PROPERTY_H__
#define _UIX_PROPERTY_H__
//----------------------------------------------------------------------------//
namespace UIX
{
//! Property access flags
enum uixPropertyAccess
{
    //! Read only property
    uixPropertyAccess_Readonly      = (1 << 0),
    //! Write only property
    uixPropertyAccess_Writeonly     = (1 << 1),
    //! Read and write property
    uixPropertyAccess_ReadWrite     = uixPropertyAccess_Readonly | uixPropertyAccess_Writeonly,
};

//! Property accessed by reference
template <
typename TOwner,
         typename T,
         const T& (TOwner::*Getter)() const,
         void (TOwner::*Setter)(const T&),
         uixPropertyAccess Access = uixPropertyAccess_ReadWrite
         >
class uixPropertyByRef;

//! Property accessed by value
template <
typename TOwner,
         typename T,
         T (TOwner::*Getter)() const,
         void (TOwner::*Setter)(const T),
         uixPropertyAccess Access = uixPropertyAccess_ReadWrite
         >
class uixPropertyByValue;

template <
typename TOwner,
         typename T,
         const T& (TOwner::*Getter)() const,
         void (TOwner::*Setter)(const T&),
         uixPropertyAccess Access
         >
class uixPropertyByRef
{
public:
    void Initialize(TOwner* owner)
    {
        m_Owner = owner;
    }

    operator T () const
    {
        return Get();
    }

    const T& operator = (const T& value)
    {
        Set(value);
        return value;
    }

    T& operator = (T& value)
    {
        Set(value);
        return value;
    }

    const T& Get() const
    {
        uixASSERT(m_Owner != NULLPTR);
        uixASSERT(Getter != NULLPTR);
        uixASSERT((Access & uixPropertyAccess_Readonly) == uixPropertyAccess_Readonly);

        return (m_Owner->*Getter)();
    }

    void Set(const T& value)
    {
        uixASSERT(m_Owner != NULLPTR);
        uixASSERT(Setter != NULLPTR);
        uixASSERT((Access & uixPropertyAccess_Writeonly) uixPropertyAccess_Writeonly);

        if ((Access & uixPropertyAccess_Writeonly) uixPropertyAccess_Writeonly)
        {
            (m_Owner->*Setter)(value);
        }
    }

    uixPropertyByRef& operator = (const uixPropertyByRef& right)
    {
        Set(right.Get());
        return (*this);
    }

    template <
    typename TForeign,
             T (TForeign::*FGetter)()const,
             void (TForeign::*FSetter)(const T&)
             >
    uixPropertyByRef& operator = (const uixPropertyByRef<TForeign, T, FGetter, FSetter>& right)
    {
        Set(right.Get());
        return (*this);
    }
private:
    TOwner* m_Owner;
};

template <
typename TOwner,
         typename T,
         T (TOwner::*Getter)()const,
         void (TOwner::*Setter)(const T),
         uixPropertyAccess Access
         >
class uixPropertyByValue
{
public:
    void Initialize(TOwner* owner)
    {
        m_Owner = owner;
    }

    operator T () const
    {
        return Get();
    }

    const T& operator = (const T& value)
    {
        Set(value);
        return value;
    }

    T& operator = (T& value)
    {
        Set(value);
        return value;
    }

    T Get() const
    {
        uixASSERT(m_Owner != NULLPTR);
        uixASSERT(Getter != NULLPTR);
        uixASSERT((Access & uixPropertyAccess_Readonly) == uixPropertyAccess_Readonly);
        return (m_Owner->*Getter)();
    }

    void Set(const T& value)
    {
        uixASSERT(m_Owner != NULLPTR);
        uixASSERT(Setter != NULLPTR);
        uixASSERT((Access & uixPropertyAccess_Writeonly) == uixPropertyAccess_Writeonly);
        //if ((Access & uixPropertyAccess_Writeonly) == uixPropertyAccess_Writeonly)
        {
            // Remove instruction from release builds
            (m_Owner->*Setter)(value);
        }
    }

    template <
    typename FOwner,
             const T& (FOwner::*FGetter)()const,
             void (FOwner::*FSetter)(const T&)
             >
    uixPropertyByValue& operator = (const uixPropertyByRef<FOwner, T, FGetter, FSetter>& rhs)
    {
        Set(rhs.Get());
        return (*this);
    }

    uixPropertyByValue& operator = (const uixPropertyByValue& rhs)
    {
        Set(rhs.Get());
        return (*this);
    }
private:
    TOwner* m_Owner;
};
}
//----------------------------------------------------------------------------//
#endif /* _UIX_PROPERTY_H__ */