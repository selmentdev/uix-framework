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
#include "uixdatetimectrl.h"
//----------------------------------------------------------------------------//
namespace UIX
{
//----------------------------------------------------------------------------//
uixIMPLEMENT_DYNAMIC_CLASS(uixDateTimeCtrl, uixWindow);
//----------------------------------------------------------------------------//
uixDateTimeCtrl::uixDateTimeCtrl()
{
}
//----------------------------------------------------------------------------//
uixDateTimeCtrl::~uixDateTimeCtrl()
{
    DestroyWindow();
}
//----------------------------------------------------------------------------//
BOOL uixDateTimeCtrl::BeforeWindowCreate(CREATESTRUCT& cs)
{
    if (!uixWindow::BeforeWindowCreate(cs))
    {
        return FALSE;
    }

    cs.lpszClass = DATETIMEPICK_CLASS;
    cs.style |= WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS | WS_TABSTOP;

    return TRUE;
}
//----------------------------------------------------------------------------//
}
//----------------------------------------------------------------------------//