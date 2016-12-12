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
#ifndef _UIX_STREAM_H__
#define _UIX_STREAM_H__
//----------------------------------------------------------------------------//
#include "uixrequired.h"
//----------------------------------------------------------------------------//
#include "uixsharedptr.h"
//----------------------------------------------------------------------------//
namespace UIX
{
//! Stream access mode
enum uixStreamAccessMode
{
    //! Read
    uixStreamAccessMode_Read        = 1 << 0,
    //! Write
    uixStreamAccessMode_Write       = 1 << 1,
    //! Append
    uixStreamAccessMode_Append      = 1 << 2,
    //! Read & write
    uixStreamAccessMode_ReadWrite   =
        uixStreamAccessMode_Read |
        uixStreamAccessMode_Write,
};

//! Access pattern
enum uixStreamAccessPattern
{
    //! Sequential
    uixStreamAccessPattern_Sequential,
    //! Random
    uixStreamAccessPattern_Random,
};

//! Access mode
enum uixStreamSeekMode
{
    //! Begin
    uixStreamSeekMode_Begin,
    //! Current
    uixStreamSeekMode_Current,
    //! End
    uixStreamSeekMode_End,
};

//! Stream
//! @brief
//!     Base class for all streams
class UIXAPI uixStream
{
public:
    //! Constructor
    uixStream();

    //! Destructor
    virtual ~uixStream();

    //! Opens stream
    //! @return
    //!     True when successful
    virtual BOOL Open();

    //! Opens stream using access mode
    //! @param[in] accessMode
    //!     Access mode
    //! @return
    //!     True when successful
    virtual BOOL Open(uixStreamAccessMode accessMode);

    //! Closes stream
    //! @return
    //!     True when successful
    virtual BOOL Close();

    //! Reads data block
    //! @param[in] buffer
    //!     Buffer for data
    //! @param[in] size
    //!     Buffer size
    //! @param[out] read
    //!     Bytes read
    //! @return
    //!     True when successful
    virtual BOOL ReadBlock(void* buffer, INT32 size, INT32* read);

    //! Writes data block
    //! @param[in] buffer
    //!     Buffer with data
    //! @param[in] size
    //!     Buffer size
    //! @param[out] written
    //!     Bytes written
    //! @return
    //!     True when successful
    virtual BOOL WriteBlock(const void* buffer, INT32 size, INT32* written);

    //! Gets current position
    //! @return
    //!     Current position
    virtual INT64 GetCurrentPosition() const;

    //! Sets current position
    //! @param[in] position
    //!     Position
    //! @param[in] seekMode
    //!     Seek mode
    //! @return
    //!     True when sucecssful
    virtual BOOL SetCurrentPosition(INT64 position, uixStreamSeekMode seekMode);

    //! Seeks stream
    //! @param[in] offset
    //!     Offset
    //! @param[in] seekMode
    //!     Seek mode
    //! @return
    //!     True when successful
    BOOL Seek(INT64 offset, uixStreamSeekMode seekMode)
    {
        return SetCurrentPosition(offset, seekMode);
    }

    //! Gets stream length
    //! @return
    //!     Stream length
    virtual INT64 GetLength() const;

    //! Sets stream length
    //! @param[in] size
    //!     Stream size
    //! @return
    //!     True when successful
    virtual BOOL SetLength(INT64 size);

    //! Flushes stream I/O operations
    //! @return
    //!     True when successful
    virtual BOOL Flush();

    //! Rollbacks stream I/O operations
    //! @return
    //!     True when successful
    virtual BOOL Rollback();

    //! Tests if stream cursor reached end
    //! @return
    //!     True when successful
    virtual BOOL IsEnd() const;

    //! Can read from stream?
    //! @return
    //!     True when successful
    virtual BOOL CanRead() const
    {
        return FALSE;
    }

    //! Can write from stream?
    //! @return
    //!     True when successful
    virtual BOOL CanWrite() const
    {
        return FALSE;
    }

    //! Can seek from stream?
    //! @return
    //!     True when successful
    virtual BOOL CanSeek() const
    {
        return FALSE;
    }

    //! Sets access mode
    //! @param[in] accessMode
    //!     Access mode
    void SetAccessMode(uixStreamAccessMode accessMode);

    //! Gets access mode
    //! @return
    //!     Access mode
    uixStreamAccessMode GetAccessMode() const;

    //! Sets access pattern
    //! @param[in] accessPattern
    //!     Access pattern
    void SetAccessPattern(uixStreamAccessPattern accessPattern);

    //! Gets access pattern
    //! @return
    //!     Access pattern
    uixStreamAccessPattern GetAccessPattern() const;

    //! Checks if stream is open
    //! @return
    //!     True when successful
    BOOL IsOpen() const;

protected:
    BOOL                    m_IsOpen;           //! Open flag
    uixStreamAccessMode     m_AccessMode;       //! Access mode
    uixStreamAccessPattern  m_AccessPattern;    //! Access pattern
};

//! Stream pointer type
typedef UIXAPI uixSharedPtr<uixStream>      uixStreamPtr;
}
//----------------------------------------------------------------------------//
#endif /* _UIX_STREAM_H__ */