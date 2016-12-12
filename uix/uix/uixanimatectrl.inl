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
#ifndef _UIX_ANIMATECTRL_INL__
#define _UIX_ANIMATECTRL_INL__
//----------------------------------------------------------------------------//
#include "uixanimatectrl.inl"
//----------------------------------------------------------------------------//
#include "uixresource.h"
//----------------------------------------------------------------------------//
namespace UIX
{
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixAnimateCtrl::OpenFile(const uixChar* fileName)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    return (BOOL)Animate_Open(m_Handle, fileName);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixAnimateCtrl::Load(uixResourceName resource)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    return Load(
               UixFindResourceHandle(resource, _("AVI")),
               resource);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixAnimateCtrl::Load(uixResourceID resourceID)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    return Load(
               UixFindResourceHandle(resourceID, _("AVI")),
               resourceID);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixAnimateCtrl::Load(HINSTANCE instance, uixResourceName resource)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    return (BOOL)Animate_OpenEx(m_Handle, instance, resource);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixAnimateCtrl::Load(HINSTANCE instance, uixResourceID resourceID)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    return Load(instance, MAKEINTRESOURCE(resourceID));
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixAnimateCtrl::Play(INT from, INT to, INT repeat)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    return (BOOL)Animate_Play(m_Handle, from, to, repeat);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixAnimateCtrl::Stop()
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    return (BOOL)Animate_Stop(m_Handle);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixAnimateCtrl::IsPlaying()
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    return (BOOL)Animate_IsPlaying(m_Handle);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixAnimateCtrl::Close()
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    return (BOOL)Animate_Close(m_Handle);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixAnimateCtrl::Seek(INT frame)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));

    return (BOOL)Animate_Seek(m_Handle, frame);
}
//----------------------------------------------------------------------------//
}
//----------------------------------------------------------------------------//
#endif /* _UIX_ANIMATECTRL_INL__ */