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
#ifndef _UIX_LINKCTRL_INL__
#define _UIX_LINKCTRL_INL__
//----------------------------------------------------------------------------//
#include "uixlinkctrl.h"
//----------------------------------------------------------------------------//
namespace UIX
{
//----------------------------------------------------------------------------//
// Link list item
//----------------------------------------------------------------------------//
UIXINLINE uixLinkItem::uixLinkItem()
{
    mask = 0;
    stateMask = (UINT) - 1;
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixLinkItem::HasItemIndex() const
{
    return (mask & LIF_ITEMINDEX) != 0;
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixLinkItem::HasState() const
{
    return (mask & LIF_STATE) != 0;
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixLinkItem::HasItemID() const
{
    return (mask & LIF_ITEMID) != 0;
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixLinkItem::HasUrl() const
{
    return (mask & LIF_URL) != 0;
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixLinkItem::GetItemIndex() const
{
    return iLink;
}
//----------------------------------------------------------------------------//
UIXINLINE void uixLinkItem::SetItemIndex(INT index)
{
    mask |= LIF_ITEMINDEX;
    iLink = index;
}
//----------------------------------------------------------------------------//
UIXINLINE DWORD uixLinkItem::GetState() const
{
    return state;
}
//----------------------------------------------------------------------------//
UIXINLINE void uixLinkItem::SetState(DWORD value)
{
    mask |= LIF_STATE;
    state = value;
}
//----------------------------------------------------------------------------//
UIXINLINE DWORD uixLinkItem::GetStateMask() const
{
    return stateMask;
}
//----------------------------------------------------------------------------//
UIXINLINE void uixLinkItem::SetStateMask(DWORD value)
{
    stateMask = value;
}
//----------------------------------------------------------------------------//
UIXINLINE const wchar_t* uixLinkItem::GetID() const
{
    return szID;
}
//----------------------------------------------------------------------------//
UIXINLINE void uixLinkItem::SetID(const wchar_t* id)
{
    mask |= LIF_ITEMID;
    lstrcpyn(szID, id, MAX_LINKID_TEXT);
}
//----------------------------------------------------------------------------//
UIXINLINE const wchar_t* uixLinkItem::GetUrl() const
{
    return szUrl;
}
//----------------------------------------------------------------------------//
UIXINLINE void uixLinkItem::SetUrl(const wchar_t* url)
{
    mask |= LIF_URL;
    lstrcpyn(szUrl, url, L_MAX_URL_LENGTH);
}
//----------------------------------------------------------------------------//
// Link Control
//----------------------------------------------------------------------------//
UIXINLINE INT uixLinkCtrl::GetIdealHeight() const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (INT)SendMessage(LM_GETIDEALHEIGHT, 0, 0);
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixLinkCtrl::GetIdealSize(INT maxWidth, SIZE& size) const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (INT)SendMessage(LM_GETIDEALSIZE, maxWidth, (LPARAM)&size);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixLinkCtrl::GetItem(LITEM& item) const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (BOOL)SendMessage(LM_GETITEM, 0, (LPARAM)&item);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixLinkCtrl::HitTest(LHITTESTINFO& info) const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (BOOL)SendMessage(LM_HITTEST, 0, (LPARAM)&info);
}
//----------------------------------------------------------------------------//
UIXINLINE BOOL uixLinkCtrl::SetItem(const LITEM& item)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (BOOL)SendMessage(LM_SETITEM, 0, (LPARAM)&item);
}
//----------------------------------------------------------------------------//
}
//----------------------------------------------------------------------------//
#endif /* _UIX_LINKCTRL_INL__ */