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
#ifndef _UIX_LINKCTRL_H__
#define _UIX_LINKCTRL_H__
//----------------------------------------------------------------------------//
#include "uixwindow.h"
//----------------------------------------------------------------------------//
namespace UIX
{
//! Handle link ctrl click
#define uixEVT_LNN_CLICK(Identifier, Handler) \
    uixEVT_NOTIFY(NM_CLICK, Identifier, Handler)

//! Handle link ctrl return
#define uixEVT_LNN_RETURN(Identifier, Handler) \
    uixEVT_NOTIFY(NM_RETURN, Identifier, Handler)


//! Link Item
struct uixLinkItem : LITEM
{
    //! Constructor
    uixLinkItem();

    //! Checks if item has index
    //! @return
    //!     True when successful
    BOOL HasItemIndex() const;

    //! Checks if item has State
    //! @return
    //!     True when successful
    BOOL HasState() const;

    //! Checks if item has ID
    //! @return
    //!     True when successful
    BOOL HasItemID() const;

    //! Checks if item has Url
    //! @return
    //!     True when successful
    BOOL HasUrl() const;

    //! Gets item index
    //! @return
    //!     Item index
    INT GetItemIndex() const;

    //! Sets item index
    //! @param[in] index
    //!     Index
    void SetItemIndex(INT index);

    //! Gets item state
    //! @return
    //!     State
    DWORD GetState() const;

    //! Sets item state
    //! @param[in] value
    //!     State
    void SetState(DWORD value);

    //! Gets state mask
    //! @return
    //!     State mask
    DWORD GetStateMask() const;

    //! Sets state mask
    //! @param[in] value
    //!     State mask
    void SetStateMask(DWORD value);

    //! Gets ID string
    //! @return
    //!     ID string
    const wchar_t* GetID() const;

    //! Sets ID string
    //! @param[in] id
    //!     String id
    void SetID(const wchar_t* id);

    //! Gets url string
    //! @return
    //!     Url string
    const wchar_t* GetUrl() const;

    //! Sets url string
    //! @param[in] url
    //!     Url string
    void SetUrl(const wchar_t* url);
};

//! Link item hit test
struct uixLinkHitTest : LHITTESTINFO
{
    //! Gets hit point
    //! @return
    //!     Hit point
    const POINT& GetPoint() const
    {
        return pt;
    }

    //! Sets hit point
    //! @param[in] point
    //!     Hit point
    void SetPoint(POINT& point)
    {
        pt = point;
    }

    //! Gets item
    //! @return
    //!     Item
    const LITEM& GetItem() const
    {
        return item;
    }
};

//! Link control
//! @brief
//!     This class implements link control
//! @note
//!     Notify message entries are starting with uixEVT_LNN_
class UIXAPI uixLinkCtrl : public uixWindow
{
    uixDECLARE_DYNAMIC_CLASS(uixLinkCtrl);
public:
    //! Constructor
    uixLinkCtrl();

    //! Destructor
    virtual ~uixLinkCtrl();

    //! @copydoc uixWindow::BeforeWindowCreate
    virtual BOOL BeforeWindowCreate(CREATESTRUCT& cs) override;

    //! Gets ideal height
    //! @return
    //!     Ideal height
    INT GetIdealHeight() const;

    //! Gets ideal size
    //! @param[in] maxWidth
    //!     Max width
    //! @param[out] size
    //!     Ideal size
    //! @return
    //!     Ideal height
    INT GetIdealSize(INT maxWidth, SIZE& size) const;

    //! Gets item
    //! @param[in, out] item
    //!     Item to get
    //! @return
    //!     True when successful
    BOOL GetItem(LITEM& item) const;

    //! Perform hit test
    //! @param[in, out] info
    //!     Hit test info
    //! @return
    //!     True when successful
    BOOL HitTest(LHITTESTINFO& info) const;

    //! Sets item
    //! @param[in] item
    //!     Item to set
    //! @return
    //!     True when successful
    BOOL SetItem(const LITEM& item);
};
}
//----------------------------------------------------------------------------//
#include "uixlinkctrl.inl"
//----------------------------------------------------------------------------//
#endif /* _UIX_LINKCTRL_H__ */