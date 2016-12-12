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
#include "uixdump.h"
//----------------------------------------------------------------------------//
namespace UIX
{
//----------------------------------------------------------------------------//
uixDumpContext::uixDumpContext(uixStreamPtr stream)
    : m_Stream(stream)
{
    m_Stream->Open(uixStreamAccessMode_Write);
}
//----------------------------------------------------------------------------//
uixDumpContext::~uixDumpContext()
{
    m_Stream->Close();
}
//----------------------------------------------------------------------------//
void uixDumpContext::Write(const wchar_t* name, const wchar_t* format, ...)
{
    uixWString raw, message;

    va_list args;
    va_start(args, format);
    UixFormatStringArgs(message, format, args);
    va_end(args);

    UixFormatString(raw, L"%s: %s\r\n", name, message.c_str());

    m_Stream->WriteBlock(raw.data(), (INT32)(raw.length() * sizeof(wchar_t)), NULLPTR);
}
//----------------------------------------------------------------------------//
void uixDumpContext::Write(const char* name, const char* format, ...)
{
    uixCString raw, message;

    va_list args;
    va_start(args, format);
    UixFormatStringArgs(message, format, args);
    va_end(args);

    UixFormatString(raw, "%s: %s\r\n", name, message.c_str());

    m_Stream->WriteBlock(raw.data(), (INT32)(raw.length() * sizeof(char)), NULLPTR);
}
//----------------------------------------------------------------------------//
}
//----------------------------------------------------------------------------//