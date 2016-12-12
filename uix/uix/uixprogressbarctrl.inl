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
#ifndef _UIX_PROGRESSBARCTRL_INL__
#define _UIX_PROGRESSBARCTRL_INL__
//----------------------------------------------------------------------------//
#include "uixprogressbarctrl.h"
//----------------------------------------------------------------------------//
namespace UIX
{
//----------------------------------------------------------------------------//
UIXINLINE INT uixProgressBarRange::GetLow() const
{
    return iLow;
}
//----------------------------------------------------------------------------//
UIXINLINE void uixProgressBarRange::SetLow(INT value)
{
    iLow = value;
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixProgressBarRange::GetHigh() const
{
    return iHigh;
}
//----------------------------------------------------------------------------//
UIXINLINE void uixProgressBarRange::SetHigh(INT value)
{
    iHigh = value;
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixProgressBarCtrl::DeltaPos(INT delta)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (INT)SendMessage(PBM_DELTAPOS, delta, 0);
}
//----------------------------------------------------------------------------//
UIXINLINE uixColor uixProgressBarCtrl::GetBarColor() const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (uixColorRef)SendMessage(PBM_GETBARCOLOR, 0, 0);
}
//----------------------------------------------------------------------------//
UIXINLINE uixColor uixProgressBarCtrl::GetBackgroundColor() const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (uixColorRef)SendMessage(PBM_GETBKCOLOR, 0, 0);
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixProgressBarCtrl::GetPosition() const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (INT)SendMessage(PBM_GETPOS, 0, 0);
}
//----------------------------------------------------------------------------//
UIXINLINE void uixProgressBarCtrl::GetRange(uixProgressBarRange& range) const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    SendMessage(PBM_GETRANGE, TRUE, (LPARAM)&range);
}
//----------------------------------------------------------------------------//
UIXINLINE uixProgressBarState uixProgressBarCtrl::GetState() const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (uixProgressBarState)SendMessage(PBM_GETSTATE, 0, 0);
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixProgressBarCtrl::GetStep() const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (INT)SendMessage(PBM_GETSTEP, 0, 0);
}
//----------------------------------------------------------------------------//
UIXINLINE uixColor uixProgressBarCtrl::SetBarColor(uixColor color)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (uixColorRef)SendMessage(PBM_SETBARCOLOR, 0, (LPARAM)color);
}
//----------------------------------------------------------------------------//
UIXINLINE uixColor uixProgressBarCtrl::SetBackgroundColor(uixColor color)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (uixColorRef)SendMessage(PBM_SETBKCOLOR, 0, (LPARAM)color);
}
//----------------------------------------------------------------------------//
UIXINLINE void uixProgressBarCtrl::SetMarquee(BOOL enable, UINT deltaTime)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    SendMessage(PBM_SETMARQUEE, enable, (LPARAM)deltaTime);
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixProgressBarCtrl::SetPosition(INT position)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (INT)SendMessage(PBM_SETPOS, position, 0);
}
//----------------------------------------------------------------------------//
UIXINLINE void uixProgressBarCtrl::SetRange(INT low, INT high)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    SendMessage(PBM_SETRANGE32, low, high);
}
//----------------------------------------------------------------------------//
UIXINLINE uixProgressBarState uixProgressBarCtrl::SetState(uixProgressBarState state)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (uixProgressBarState)SendMessage(PBM_SETSTATE, state, 0);
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixProgressBarCtrl::SetStep(INT step)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (INT)SendMessage(PBM_SETSTEP, step, 0);
}
//----------------------------------------------------------------------------//
UIXINLINE INT uixProgressBarCtrl::StepIt()
{
    uixASSERT(this != NULLPTR);
    uixASSERT(::IsWindow(m_Handle));
    return (INT)SendMessage(PBM_STEPIT, 0, 0);
}
//----------------------------------------------------------------------------//
}
//----------------------------------------------------------------------------//
#endif /* _UIX_PROGRESSBARCTRL_INL__ */