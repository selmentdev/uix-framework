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
#include "uixtrace.h"
//----------------------------------------------------------------------------//
namespace UIX
{
//----------------------------------------------------------------------------//
void UixTrace(const wchar_t* format, ...)
{
    const int bufferSize = 1024;
    wchar_t buffer[bufferSize];
    va_list args;
    va_start(args, format);

    if (vswprintf_s(buffer, format, args) > 0)
    {
        OutputDebugStringW(buffer);
        OutputDebugStringA("\n");
    }
    else
    {
        OutputDebugStringA("Failed to trace\n");
    }
}
//----------------------------------------------------------------------------//
void UixTrace(const char* format, ...)
{
    const int bufferSize = 1024;
    char buffer[bufferSize];
    va_list args;
    va_start(args, format);

    if (vsprintf_s(buffer, format, args) > 0)
    {
        OutputDebugStringA(buffer);
        OutputDebugStringA("\n");
    }
    else
    {
        OutputDebugStringA("Failed to trace\n");
    }
}
//----------------------------------------------------------------------------//
}
//----------------------------------------------------------------------------//