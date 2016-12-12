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
#ifndef _UIX_APPLICATION_INL__
#define _UIX_APPLICATION_INL__
//----------------------------------------------------------------------------//
#include "uixapplication.h"
#include "uixstate.h"
//----------------------------------------------------------------------------//
namespace UIX
{
//----------------------------------------------------------------------------//
UIXINLINE const uixString& uixApplication::GetFileName() const
{
    uixASSERT(this != NULLPTR);
    return m_FileName;
}
//----------------------------------------------------------------------------//
UIXINLINE const uixString& uixApplication::GetCommandLine() const
{
    uixASSERT(this != NULLPTR);
    return m_CommandLine;
}
//----------------------------------------------------------------------------//
UIXINLINE const uixString& uixApplication::GetTitle() const
{
    uixASSERT(this != NULLPTR);
    return m_AppName;
}
//----------------------------------------------------------------------------//
UIXINLINE const uixString& uixApplication::GetAppID() const
{
    uixASSERT(this != NULLPTR);
    return m_AppID;
}
//----------------------------------------------------------------------------//
UIXINLINE HINSTANCE uixApplication::GetInstance() const
{
    uixASSERT(this != NULLPTR);
    return m_Instance;
}
//----------------------------------------------------------------------------//
UIXINLINE uixApplication* uixApplication::Get()
{
    return uixProcessState::Get().m_Application;
}
//----------------------------------------------------------------------------//
UIXINLINE void uixApplication::SetMainWindow(uixWindow* window)
{
    uixASSERT(this != NULLPTR);
    m_MainWindow = window;
}
//----------------------------------------------------------------------------//
}
//----------------------------------------------------------------------------//
#endif /* _UIX_APPLICATION_INL__ */