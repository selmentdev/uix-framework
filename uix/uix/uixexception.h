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
#ifndef _UIX_EXCEPTION_H__
#define _UIX_EXCEPTION_H__
//----------------------------------------------------------------------------//
#include "uixobject.h"
//----------------------------------------------------------------------------//
namespace UIX
{
//! Gets error description from system
//! @param[in] errorCode
//!     Error code
//! @return
//!     Localized error description text
UIXINLINE uixString UixErrorString(DWORD errorCode)
{
    uixString result;
    LPTSTR str;

    if (::FormatMessage(
            FORMAT_MESSAGE_ALLOCATE_BUFFER |
            FORMAT_MESSAGE_FROM_SYSTEM,
            NULL,
            errorCode,
            0,
            (LPTSTR)&str,
            0,
            NULL) == 0)
    {
        result.assign(_("Unknown error"));
    }
    else
    {
        result.assign(str);
        ::LocalFree(str);
    }

    return result;
}

//! Exception class
//! @brief
//!     This class implements base exception class
class UIXAPI uixException/* : public uixObject*/
{
    /*uixDECLARE_ABSTRACT_CLASS(uixException)*/
public:
    //! Constructor
    uixException();

    //! Copy constructor
    //! @param[in] exception
    //!     Exception to copy
    uixException(const uixException& exception);

    //! Generate report error message
    //! @param[out] message
    //!     Exception message
    virtual void Report(uixString& message) const = 0;
};

//! Invalid argument exception
//! @brief
//!     This class implements invalid argument exception
class UIXAPI uixInvalidArgumentException : public uixException
{
    /*uixDECLARE_DYNAMIC_CLASS(uixInvalidArgumentException)*/
public:
    //! Constructor
    uixInvalidArgumentException();

    //! Copy constructor
    //! @param[in] exception
    //!     Exception to copy
    uixInvalidArgumentException(const uixInvalidArgumentException& exception);

    //! @copydoc uixException::Report
    virtual void Report(uixString& message) const override;
};

//! Not supported exception
//! @brief
//!     This class implements not supported exception
class UIXAPI uixNotSupportedException : public uixException
{
    /*uixDECLARE_DYNAMIC_CLASS(uixNotSupportedException)*/
public:
    //! Constructor
    uixNotSupportedException();

    //! Copy constructor
    //! @param[in] exception
    //!     Exception to copy
    uixNotSupportedException(const uixNotSupportedException& exception);

    //! @copydoc uixException::Report
    virtual void Report(uixString& message) const override;
};

//! Invalid operation exception
//! @brief
//!     This class implements invalid operation exception
class UIXAPI uixInvalidOperationException : public uixException
{
    /*uixDECLARE_DYNAMIC_CLASS(uixInvalidOperationException)*/
public:
    //! Constructor
    uixInvalidOperationException();

    //! Copy constructor
    //! @param[in] exception
    //!     Exception to copy
    uixInvalidOperationException(const uixInvalidOperationException& exception);

    uixInvalidOperationException(DWORD errorCode);

    //! Constructor
    //! @param[in] errorCode
    //!     Result error code
    //! @param[in] message
    //!     Additional message
    uixInvalidOperationException(DWORD errorCode, const uixString& message);

    //! @copydoc uixException::Report
    virtual void Report(uixString& message) const override;

private:
    DWORD       m_ErrorCode;
    uixString   m_Message;
};

//! Not implemented exception
//! @brief
//!     This class implements not implemented exception
class UIXAPI uixNotImplementedException : public uixException
{
    /*uixDECLARE_DYNAMIC_CLASS(uixNotImplementedException)*/
public:
    //! Constructor
    uixNotImplementedException();

    //! Copy constructor
    //! @param[in] exception
    //!     Exception to copy
    uixNotImplementedException(const uixNotImplementedException& exception);

    //! Constructor
    //! @param[in] message
    //!     Message
    uixNotImplementedException(const uixString& message);

    //! @copydoc uixException::Report
    virtual void Report(uixString& message) const override;
private:
    uixString   m_Message;
};

//! User exception
//! @brief
//!     This class implements user exception class
class UIXAPI uixUserException : public uixException
{
    /*uixDECLARE_DYNAMIC_CLASS(uixUserException)*/
public:
    //! Constructor
    uixUserException();

    //! Copy constructor
    //! @param[in] exception
    //!     Exception to copy
    uixUserException(const uixUserException& exception);

    //! Constructor
    //! @param[in] message
    //!     Message
    uixUserException(const uixString& message);

    //! @copydoc uixException::Report
    virtual void Report(uixString& message) const override;

private:
    uixString   m_Message;
};
}
//----------------------------------------------------------------------------//
#endif /* _UIX_EXCEPTION_H__ */