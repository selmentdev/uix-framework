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
#include "uixfilestream.h"
//----------------------------------------------------------------------------//
namespace UIX
{
//----------------------------------------------------------------------------//
uixFileStream::uixFileStream(const uixChar* filename)
{
    m_FileName = filename;
    m_Handle = 0;
}
//----------------------------------------------------------------------------//
uixFileStream::~uixFileStream()
{
    if (IsOpen())
    {
        Close();
    }
}
//----------------------------------------------------------------------------//
BOOL uixFileStream::CanRead() const
{
    uixASSERT(this != NULLPTR);
    return TRUE;
}
//----------------------------------------------------------------------------//
BOOL uixFileStream::CanWrite() const
{
    uixASSERT(this != NULLPTR);
    return TRUE;
}
//----------------------------------------------------------------------------//
BOOL uixFileStream::CanSeek() const
{
    uixASSERT(this != NULLPTR);
    return TRUE;
}
//----------------------------------------------------------------------------//
BOOL uixFileStream::Open()
{
    uixASSERT(this != NULLPTR);
    uixASSERT(!IsOpen());
    uixASSERT(m_Handle == 0);

    if (uixStream::Open())
    {
        DWORD access = 0;
        DWORD disposition = 0;
        DWORD share = 0;

        switch (m_AccessMode)
        {
        case uixStreamAccessMode_Read:
            {
                access = GENERIC_READ;
                disposition = OPEN_EXISTING;
                share = FILE_SHARE_READ | FILE_SHARE_WRITE;
                break;
            }

        case uixStreamAccessMode_Write:
            {
                access = GENERIC_WRITE;
                disposition = OPEN_ALWAYS;
                share = FILE_SHARE_READ;
                break;
            }

        case uixStreamAccessMode_ReadWrite:
        case uixStreamAccessMode_Append:
            {
                access = GENERIC_READ | GENERIC_WRITE;
                disposition = OPEN_ALWAYS;
                share = FILE_SHARE_READ | FILE_SHARE_WRITE;
                break;
            }
        }

        DWORD flags = 0;

        switch (m_AccessPattern)
        {
        case uixStreamAccessPattern_Random:
            {
                flags |= FILE_FLAG_RANDOM_ACCESS;
                break;
            }

        case uixStreamAccessPattern_Sequential:
            {
                flags |= FILE_FLAG_SEQUENTIAL_SCAN;
                break;
            }
        }

        m_Handle = ::CreateFile(
                       m_FileName,
                       access,
                       share,
                       NULLPTR,
                       disposition,
                       flags,
                       NULLPTR);

        if (m_Handle != INVALID_HANDLE_VALUE)
        {
            if (m_AccessMode == uixStreamAccessMode_Append)
            {
                ::SetFilePointer(m_Handle, 0, NULLPTR, FILE_END);
            }

            return TRUE;
        }

        if (m_Handle != INVALID_HANDLE_VALUE)
        {
            return TRUE;
        }
    }

    uixStream::Close();
    return FALSE;
}
//----------------------------------------------------------------------------//
BOOL uixFileStream::Close()
{
    uixASSERT(this != NULLPTR);
    uixASSERT(IsOpen());
    uixASSERT(m_Handle != 0);

    BOOL result = ::CloseHandle(m_Handle);
    result &= uixStream::Close();
    m_Handle = 0;
    return result;
}
//----------------------------------------------------------------------------//
BOOL uixFileStream::ReadBlock(void* buffer, INT32 size, INT32* read)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(IsOpen());
    uixASSERT(m_Handle != 0);

    DWORD processed = 0;

    BOOL result = ::ReadFile(m_Handle, buffer, size, (LPDWORD)&processed, NULLPTR);

    if (read)
    {
        *read = processed;
    }

    return result;
}
//----------------------------------------------------------------------------//
BOOL uixFileStream::WriteBlock(const void* buffer, INT32 size, INT32* written)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(IsOpen());
    uixASSERT(m_Handle != 0);

    DWORD processed = 0;

    BOOL result = ::WriteFile(m_Handle, buffer, size, (LPDWORD)&processed, NULLPTR);

    if (written)
    {
        *written = processed;
    }

    return result;
}
//----------------------------------------------------------------------------//
INT64 uixFileStream::GetCurrentPosition() const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(IsOpen());
    uixASSERT(m_Handle != 0);

    LARGE_INTEGER zero, pos;
    zero.QuadPart = 0;
    ::SetFilePointerEx(m_Handle, zero, &pos, FILE_CURRENT);

    return (INT64)pos.QuadPart;
}
//----------------------------------------------------------------------------//
BOOL uixFileStream::SetCurrentPosition(INT64 position, uixStreamSeekMode seekMode)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(IsOpen());
    uixASSERT(m_Handle != 0);

    LARGE_INTEGER current;
    current.QuadPart = position;

    DWORD move = 0;

    switch (seekMode)
    {
    case uixStreamSeekMode_Begin:
        {
            move = FILE_BEGIN;
            break;
        }

    case uixStreamSeekMode_Current:
        {
            move = FILE_CURRENT;
            break;
        }

    case uixStreamSeekMode_End:
        {
            move = FILE_END;
            break;
        }
    }

    return ::SetFilePointerEx(m_Handle, current, NULLPTR, move);
}
//----------------------------------------------------------------------------//
INT64 uixFileStream::GetLength() const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(IsOpen());
    uixASSERT(m_Handle != 0);

    LARGE_INTEGER size;
    ::GetFileSizeEx(m_Handle, &size);

    return (INT64)size.QuadPart;
}
//----------------------------------------------------------------------------//
BOOL uixFileStream::SetLength(INT64 size)
{
    uixASSERT(this != NULLPTR);
    uixASSERT(IsOpen());
    uixASSERT(m_Handle != 0);

    uixUNREFERENCED(size);
    return FALSE;
}
//----------------------------------------------------------------------------//
BOOL uixFileStream::Flush()
{
    uixASSERT(this != NULLPTR);
    uixASSERT(!IsOpen());
    uixASSERT(m_Handle == 0);

    return ::FlushFileBuffers(m_Handle);
}
//----------------------------------------------------------------------------//
BOOL uixFileStream::IsEnd() const
{
    uixASSERT(this != NULLPTR);
    uixASSERT(!IsOpen());
    uixASSERT(m_Handle == 0);

    return GetCurrentPosition() >= GetLength();
}
//----------------------------------------------------------------------------//
}
//----------------------------------------------------------------------------//