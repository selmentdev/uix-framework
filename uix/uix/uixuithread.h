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
#ifndef _UIX_UITHREAD_H__
#define _UIX_UITHREAD_H__
//----------------------------------------------------------------------------//
#include "uixthreading.h"
//----------------------------------------------------------------------------//
namespace UIX
{
//! User Interface Thread
//! @brief
//!     This class implements custom thread message queue. It's used to
//!     process messages from GUI controls and communicate with Windows
//!     system
class UIXAPI uixUiThread : public uixThread
{
    uixDECLARE_DYNAMIC_CLASS(uixUiThread);
public:
    //! Constructor
    uixUiThread();

    //! Destructor
    virtual ~uixUiThread();

    //! Posts thread message
    //! @param[in] message
    //!     Message
    //! @param[in] wParam
    //!     wParam
    //! @param[in] lParam
    //!     lParam
    //! @return
    //!     True when successful
    BOOL PostThreadMessage(UINT message, WPARAM wParam, LPARAM lParam);

    //! Initialize instance
    //! @return
    //!     True when successful
    virtual BOOL InitInstance();

    //! Exits instance
    //! @return
    //!     Result value
    virtual LRESULT ExitInstance();

    //! Runs thread loop
    //! @return
    //!     Result value
    virtual LRESULT Run();

    //! Called before translate message
    //! @param[in] m
    //!     Message
    //! @return
    //!     True when successful
    virtual BOOL BeforeTranslateMessage(MSG* m);

    //! Process message
    //! @param[in] m
    //!     Message
    //! @return
    //!     True when successful
    virtual BOOL ProcessMessage(MSG* m);

    //! Called when idle
    //! @param[in] idleCount
    //!     Idle counter
    //! @return
    //!     True when successful
    virtual BOOL OnIdle(LONG idleCount);

    //! Checks if m is idle message
    //! @param[in] m
    //!     Message
    //! @return
    //!     True when successful
    virtual BOOL IsIdleMessage(MSG* m);

    //! Called to process window procedure exception
    //! @param[in] e
    //!     Exception object
    //! @param[in] m
    //!     Message
    //! @return
    //!     Result value
    virtual LRESULT ProcessWindowProcException(uixException& e, const MSG* m);

    //! User callback for exception
    //! @param[in] e
    //!     Exception object
    virtual void OnException(const uixException& e);

protected:
    uixWindow*      m_MainWindow;       //< Main window pointer
    uixWindow*      m_ActiveWindow;     //< Active window pointer
};
}
//----------------------------------------------------------------------------//
#endif /* _UI_WINTHREAD_H__ */