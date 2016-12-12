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
#include "uixexception.h"
//----------------------------------------------------------------------------//
namespace UIX
{
//----------------------------------------------------------------------------//
// uixException
//----------------------------------------------------------------------------//
//uixIMPLEMENT_ABSTRACT_CLASS(uixException, uixObject);
//----------------------------------------------------------------------------//
uixException::uixException()
{
}
//----------------------------------------------------------------------------//
uixException::uixException(const uixException& exception)
{
}
//----------------------------------------------------------------------------//
// uixInvalidArgumentException
//----------------------------------------------------------------------------//
//uixIMPLEMENT_DYNAMIC_CLASS(uixInvalidArgumentException, uixException);
//----------------------------------------------------------------------------//
uixInvalidArgumentException::uixInvalidArgumentException()
{
}
//----------------------------------------------------------------------------//
uixInvalidArgumentException::uixInvalidArgumentException(const uixInvalidArgumentException&
        exception)
{
}
//----------------------------------------------------------------------------//
void uixInvalidArgumentException::Report(uixString& message) const
{
    message.assign(_("Invalid argument"));
}
//----------------------------------------------------------------------------//
// uixNotSupportedException
//----------------------------------------------------------------------------//
//uixIMPLEMENT_DYNAMIC_CLASS(uixNotSupportedException, uixException);
//----------------------------------------------------------------------------//
uixNotSupportedException::uixNotSupportedException()
{
}
//----------------------------------------------------------------------------//
uixNotSupportedException::uixNotSupportedException(const uixNotSupportedException& exception)
{
}
//----------------------------------------------------------------------------//
void uixNotSupportedException::Report(uixString& message) const
{
    message.assign(_("Not supported"));
}
//----------------------------------------------------------------------------//
// uixInvalidOperationException
//----------------------------------------------------------------------------//
//uixIMPLEMENT_DYNAMIC_CLASS(uixInvalidOperationException, uixException);
//----------------------------------------------------------------------------//
uixInvalidOperationException::uixInvalidOperationException()
    : m_ErrorCode(::GetLastError())
    , m_Message()
{
}
//----------------------------------------------------------------------------//
uixInvalidOperationException::uixInvalidOperationException(const uixInvalidOperationException&
        exception)
    : m_ErrorCode(exception.m_ErrorCode)
    , m_Message(exception.m_Message)
{
}
//----------------------------------------------------------------------------//
uixInvalidOperationException::uixInvalidOperationException(DWORD errorCode)
    : m_ErrorCode(errorCode)
    , m_Message()
{
}
//----------------------------------------------------------------------------//
uixInvalidOperationException::uixInvalidOperationException(DWORD errorCode,
        const uixString& message)
    : m_ErrorCode(errorCode)
    , m_Message(message)
{
}
//----------------------------------------------------------------------------//
void uixInvalidOperationException::Report(uixString& message) const
{
    UixFormatString(message,
                    _("Invalid operation\n[ErrorCode: %d]\n%s\n[Message: %s]"),
                    m_ErrorCode,
                    UixErrorString(m_ErrorCode).c_str(),
                    m_Message.c_str());
}
//----------------------------------------------------------------------------//
// uixUserException
//----------------------------------------------------------------------------//
//uixIMPLEMENT_DYNAMIC_CLASS(uixUserException, uixException);
//----------------------------------------------------------------------------//
uixUserException::uixUserException()
{
}
//----------------------------------------------------------------------------//
uixUserException::uixUserException(const uixUserException& exception)
    : m_Message(exception.m_Message)
{
}
//----------------------------------------------------------------------------//
uixUserException::uixUserException(const uixString& message)
    : m_Message(message)
{
}
//----------------------------------------------------------------------------//
void uixUserException::Report(uixString& message) const
{
    message = m_Message;
}
//----------------------------------------------------------------------------//
// uixNotImplementedException
//----------------------------------------------------------------------------//
//uixIMPLEMENT_DYNAMIC_CLASS(uixNotImplementedException, uixException);
//----------------------------------------------------------------------------//
uixNotImplementedException::uixNotImplementedException()
{
}
//----------------------------------------------------------------------------//
uixNotImplementedException::uixNotImplementedException(const uixNotImplementedException& exception)
    : m_Message(exception.m_Message)
{
}
//----------------------------------------------------------------------------//
uixNotImplementedException::uixNotImplementedException(const uixString& message)
    : m_Message(message)
{
}
//----------------------------------------------------------------------------//
void uixNotImplementedException::Report(uixString& message) const
{
    message = m_Message;
}
//----------------------------------------------------------------------------//
}
//----------------------------------------------------------------------------//