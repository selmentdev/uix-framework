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
#ifndef _UIX_COLORDIALOG_INL__
#define _UIX_COLORDIALOG_INL__
//----------------------------------------------------------------------------//
#include "uixcolordialog.h"
//----------------------------------------------------------------------------//
namespace UIX
{
//----------------------------------------------------------------------------//
UIXINLINE uixColor uixColorDialog::GetColor() const
{
    uixASSERT(this != NULLPTR);

    return m_Data.rgbResult;
}
//----------------------------------------------------------------------------//
}
//----------------------------------------------------------------------------//
#endif /* _UIX_COLORDIALOG_INL__ */