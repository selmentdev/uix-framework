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
#ifndef _UIX_IPADDRESSCTRL_H__
#define _UIX_IPADDRESSCTRL_H__
//----------------------------------------------------------------------------//
#include "uixwindow.h"
//----------------------------------------------------------------------------//
namespace UIX
{
//! Handle field changed
#define uixEVT_IPN_FIELDCHANGED(Identifier, Handler) \
    uixEVT_NOTIFY(IPN_FIELDCHANGED, Identifier, Handler)

//! IP address struct
struct uixIPAddress
{
    union
    {
        struct
        {
            BYTE A;     //!< First byte
            BYTE B;     //!< Second byte
            BYTE C;     //!< Third byte
            BYTE D;     //!< Fourth byte
        };
        DWORD Address;  //!< IP Address
    };

    //! Constructor
    uixIPAddress()
        : Address(0)
    {
    }

    //! Copy Constructor
    //! @param[in] rhs
    //!     Copied object
    uixIPAddress(const uixIPAddress& rhs)
        : Address(rhs.Address)
    {
    }

    //! Constructor
    //! @param[in] raw
    //!     Raw IP address
    uixIPAddress(::DWORD raw)
        : Address(raw)
    {
    }

    //! Assigment operator
    //! @param[in] rhs
    //!     IP address
    //! @return
    //!     This object
    uixIPAddress& operator = (const uixIPAddress& rhs)
    {
        Address = rhs.Address;
        return (*this);
    }

    //! Assigment operator
    //! @param[in] raw
    //!     Raw IP address
    //! @return
    //!     This object
    uixIPAddress& operator = (::DWORD raw)
    {
        Address = raw;
        return (*this);
    }

    //! Conversion operator
    operator DWORD () const
    {
        return Address;
    }
};

//! IP address control
//! @brief
//!     This class implements IP address control
//! @note
//!     Notify message entries are starting with uixEVT_IPN_
class UIXAPI uixIPAddressCtrl : public uixWindow
{
    uixDECLARE_DYNAMIC_CLASS(uixIPAddressCtrl);
public:
    //! Constructor
    uixIPAddressCtrl();

    //! Destructor
    virtual ~uixIPAddressCtrl();

    //! @copydoc uixWindow::BeforeWindowCreate
    virtual BOOL BeforeWindowCreate(CREATESTRUCT& cs) override;

    //! Clears control
    void Clear();

    //! Checks if control is blank
    //! @return
    //!     True when successful
    BOOL IsBlank() const;

    //! Gets IP address
    //! @param[out] address
    //!     IP address
    //! @return
    //!     Number of non blank fields
    INT GetAddress(uixIPAddress& address) const;

    //! Sets IP address
    //! @param[in] address
    //!     IP address
    void SetAddress(uixIPAddress address);

    //! Sets focus
    //! @param[in] fieldID
    //!     ID of field to focus
    void SetFocus(UINT fieldID);

    //! Sets range for specified field
    //! @param[in] fieldID
    //!     ID of field
    //! @param[in] low
    //!     Low limit
    //! @param[in] high
    //!     High limit
    //! @return
    //!     True when successful
    BOOL SetRange(UINT fieldID, BYTE low, BYTE high);
};
}
//----------------------------------------------------------------------------//
#include "uixipaddressctrl.inl"
//----------------------------------------------------------------------------//
#endif /* _UIX_IPADDRESSCTRL_H__ */