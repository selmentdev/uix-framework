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
#include "uixstream.h"
//----------------------------------------------------------------------------//
#include "uixexception.h"
//----------------------------------------------------------------------------//
namespace UIX
{
//----------------------------------------------------------------------------//
uixStream::uixStream()
{
    m_IsOpen = FALSE;
    m_AccessMode = uixStreamAccessMode_Read;
    m_AccessPattern = uixStreamAccessPattern_Sequential;
}
//----------------------------------------------------------------------------//
uixStream::~uixStream()
{
}
//----------------------------------------------------------------------------//
BOOL uixStream::Open()
{
    uixASSERT(this != NULLPTR);
    uixASSERT(!IsOpen());

    m_IsOpen = TRUE;
    return TRUE;
}
//----------------------------------------------------------------------------//
BOOL uixStream::Open(uixStreamAccessMode accessMode)
{
    uixASSERT(this != NULLPTR);

    SetAccessMode(accessMode);
    return Open();
}
//----------------------------------------------------------------------------//
BOOL uixStream::Close()
{
    uixASSERT(this != NULLPTR);

    uixASSERT(IsOpen());
    m_IsOpen = FALSE;

    return FALSE;
}
//----------------------------------------------------------------------------//
BOOL uixStream::ReadBlock(void* buffer, INT32 size, INT32* read)
{
    uixASSERT(this != NULLPTR);

    uixUNREFERENCED(buffer);
    uixUNREFERENCED(size);
    uixUNREFERENCED(read);

    return FALSE;
}
//----------------------------------------------------------------------------//
BOOL uixStream::WriteBlock(const void* buffer, INT32 size, INT32* written)
{
    uixASSERT(this != NULLPTR);

    uixUNREFERENCED(buffer);
    uixUNREFERENCED(size);
    uixUNREFERENCED(written);

    return FALSE;
}
//----------------------------------------------------------------------------//
INT64 uixStream::GetCurrentPosition() const
{
    uixASSERT(this != NULLPTR);

    return 0;
}
//----------------------------------------------------------------------------//
BOOL uixStream::SetCurrentPosition(INT64 position, uixStreamSeekMode seekMode)
{
    uixASSERT(this != NULLPTR);

    uixASSERT(position >= 0);
    uixUNREFERENCED(position);
    uixUNREFERENCED(seekMode);

    return FALSE;
}
//----------------------------------------------------------------------------//
INT64 uixStream::GetLength() const
{
    uixASSERT(this != NULLPTR);

    return 0;
}
//----------------------------------------------------------------------------//
BOOL uixStream::SetLength(INT64 size)
{
    uixASSERT(this != NULLPTR);
    uixUNREFERENCED(size);

    return FALSE;
}
//----------------------------------------------------------------------------//
BOOL uixStream::Flush()
{
    uixASSERT(this != NULLPTR);
    uixASSERT(IsOpen());

    return FALSE;
}
//----------------------------------------------------------------------------//
BOOL uixStream::Rollback()
{
    uixASSERT(this != NULLPTR);
    uixASSERT(IsOpen());

    return FALSE;
}
//----------------------------------------------------------------------------//
void uixStream::SetAccessMode(uixStreamAccessMode accessMode)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(!IsOpen());

    m_AccessMode = accessMode;
}
//----------------------------------------------------------------------------//
uixStreamAccessMode uixStream::GetAccessMode() const
{
    uixASSERT(this != NULLPTR);

    return m_AccessMode;
}
//----------------------------------------------------------------------------//
void uixStream::SetAccessPattern(uixStreamAccessPattern accessPattern)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(!IsOpen());

    m_AccessPattern = accessPattern;
}
//----------------------------------------------------------------------------//
uixStreamAccessPattern uixStream::GetAccessPattern() const
{
    uixASSERT(this != NULLPTR);

    return m_AccessPattern;
}
//----------------------------------------------------------------------------//
BOOL uixStream::IsEnd() const
{
    uixASSERT(this != NULLPTR);

    return FALSE;
}
//----------------------------------------------------------------------------//
BOOL uixStream::IsOpen() const
{
    uixASSERT(this != NULLPTR);

    return m_IsOpen;
}
//----------------------------------------------------------------------------//
}
//----------------------------------------------------------------------------//