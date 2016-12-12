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
#include "uixrequired.h"
//----------------------------------------------------------------------------//
namespace UIX
{
//----------------------------------------------------------------------------//
BOOL UixAssertFailed(const char* FileName, int Line)
{
#if defined(UIX_DEBUG)
    return _CrtDbgReport(_CRT_ASSERT, FileName, Line, NULLPTR, NULLPTR);
#else
    uixUNREFERENCED(FileName);
    uixUNREFERENCED(Line);
    return FALSE;
#endif
}
//----------------------------------------------------------------------------//
}
//----------------------------------------------------------------------------//