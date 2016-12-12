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
#ifndef _UIX_FILESTREAM_H__
#define _UIX_FILESTREAM_H__
//----------------------------------------------------------------------------//
#include "uixstream.h"
//----------------------------------------------------------------------------//
namespace UIX
{
//! File stream implementation
//! @brief
//!     File stream is used to load and save data
class UIXAPI uixFileStream : public uixStream
{
public:
    //! Constructor
    //! @param[in] filename
    //!     File name
    uixFileStream(const uixChar* filename);

    //! Destructor
    virtual ~uixFileStream();

    //! @copydoc uixStream::CanRead
    virtual BOOL CanRead() const override;

    //! @copydoc uixStream::CanWrite
    virtual BOOL CanWrite() const override;

    //! @copydoc uixStream::CanSeek
    virtual BOOL CanSeek() const override;

    //! @copydoc uixStream::Open
    virtual BOOL Open() override;

    //! @copydoc uixStream::Close
    virtual BOOL Close() override;

    //! @copydoc uixStream::ReadBlock
    virtual BOOL ReadBlock(void* buffer, INT32 size, INT32* read) override;

    //! @copydoc uixStream::WriteBlock
    virtual BOOL WriteBlock(const void* buffer, INT32 size, INT32* written) override;

    //! @copydoc uixStream::GetCurrentPosition
    virtual INT64 GetCurrentPosition() const override;

    //! @copydoc uixStream::SetCurrentPosition
    virtual BOOL SetCurrentPosition(INT64 position, uixStreamSeekMode seekMode) override;

    //! @copydoc uixStream::GetLength
    virtual INT64 GetLength() const override;

    //! @copydoc uixStream::SetLength
    virtual BOOL SetLength(INT64 size) override;

    //! @copydoc uixStream::Flush
    virtual BOOL Flush() override;

    //! @copydoc uixStream::IsEnd
    virtual BOOL IsEnd() const override;

protected:
    const uixChar*  m_FileName; //! File name
    HANDLE          m_Handle;   //! File handle
};
}
//----------------------------------------------------------------------------//
#endif /* _UIX_FILESTREAM_H__ */