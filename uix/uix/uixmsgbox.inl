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
#ifndef _UIX_MSGBOX_INL__
#define _UIX_MSGBOX_INL__
//----------------------------------------------------------------------------//
#include "uixmsgbox.h"
#include "uixresource.h"
//----------------------------------------------------------------------------//
namespace UIX
{
//----------------------------------------------------------------------------//
UIXINLINE void uixMessageBox::SetIcon(uixResourceID resourceID)
{
    uixASSERT(this != NULLPTR);

    SetIcon(
        UixFindResourceHandle(resourceID, RT_ICON),
        resourceID);
}
//----------------------------------------------------------------------------//
UIXINLINE void uixMessageBox::SetIcon(uixResourceName resource)
{
    uixASSERT(this != NULLPTR);

    SetIcon(
        UixFindResourceHandle(resource, RT_ICON),
        resource);
}
//----------------------------------------------------------------------------//
UIXINLINE void uixMessageBox::SetLangID(DWORD langID)
{
    uixASSERT(this != NULLPTR);

    m_Params.dwLanguageId = langID;
}
//----------------------------------------------------------------------------//
UIXINLINE void uixMessageBox::SetHelpContext(DWORD helpID)
{
    uixASSERT(this != NULLPTR);

    m_Params.dwContextHelpId = helpID;
}
//----------------------------------------------------------------------------//
UIXINLINE void uixMessageBox::SetStyle(DWORD style)
{
    uixASSERT(this != NULLPTR);

    m_Params.dwStyle = style;
}
//----------------------------------------------------------------------------//
UIXINLINE void uixMessageBox::SetHelpCallback(MSGBOXCALLBACK callback)
{
    uixASSERT(this != NULLPTR);

    m_Params.lpfnMsgBoxCallback = callback;
}
//----------------------------------------------------------------------------//
UIXINLINE void uixMessageBox::SetText(const uixChar* text)
{
    uixASSERT(this != NULLPTR);

    m_Params.lpszText = text;
}
//----------------------------------------------------------------------------//
UIXINLINE void uixMessageBox::SetCaption(const uixChar* caption)
{
    uixASSERT(this != NULLPTR);

    m_Params.lpszCaption = caption;
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixMessageBox::DoModal()
{
    uixASSERT(this != NULLPTR);
    uixCreateWindowHook::Begin(this);
    INT result = ::MessageBoxIndirect(&m_Params);
    uixCreateWindowHook::End();
    return result;
}
//----------------------------------------------------------------------------//
}
//----------------------------------------------------------------------------//
#endif /* _UIX_MSGBOX_INL__ */