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
#ifndef _UIX_APPLICATION_H__
#define _UIX_APPLICATION_H__
//----------------------------------------------------------------------------//
#include "uixobject.h"
#include "uixuithread.h"
#include "uixinit.h"
//----------------------------------------------------------------------------//
namespace UIX
{
class uixWindow;

//! Application Class
//! @brief
//!     This class implements application thread loop. By implementing
//!     InitInstance method you can create main window and init whole
//!     Application.
class UIXAPI uixApplication : public uixUiThread
{
    uixDECLARE_DYNAMIC_CLASS(uixApplication);
public:
    //! Constructor
    uixApplication();

    //! Destructor
    virtual ~uixApplication();

    //! Initialize application instance
    //! @return
    //!     True when successful
    virtual BOOL InitInstance() override;

    //! Shut down application instance
    //! @return
    //!     Message result value
    virtual LRESULT ExitInstance() override;

    //! Runs application's message queue
    //! @return
    //!     Last message result value
    virtual LRESULT Run() override;

    //! Gets handle to instance of application
    //! @return
    //!     Handle to current instance
    HINSTANCE GetInstance() const;

    //! Called when exception occurs
    //! @param[in] e
    //!     Exception object
    virtual void OnException(const uixException& e) override;

    //! Sets process current handles and other important data
    //! @param[in] showCmd
    //!     Command
    void InitializeHandles(HINSTANCE instance, const uixChar* cmdLine, UINT showCmd);

    //! Gets application file name
    //! @return
    //!     File name
    const uixString& GetFileName() const;

    //! Gets application command line
    //! @return
    //!     Command line
    const uixString& GetCommandLine() const;

    //! Gets application title
    //! @return
    //!     Title
    const uixString& GetTitle() const;

    //! Gets application identifier
    //! @return
    //!     Application ID
    const uixString& GetAppID() const;

    //! Gets application
    //! @return
    //!     Application
    static uixApplication* Get();

    //! Sets main window
    //! @param[in] window
    //!     New main window
    void SetMainWindow(uixWindow* window);
protected:
    HINSTANCE   m_Instance;         //!< Application instance
    HMODULE     m_RichEditModule;   //!< Rich edit module handle

    uixString   m_CommandLine;
    UINT        m_ShowCommand;

    uixString   m_FileName;
    uixString   m_AppName;
    uixString   m_AppID;
};
}
//----------------------------------------------------------------------------//
#include "uixapplication.inl"
//----------------------------------------------------------------------------//
#endif /* _UIX_APPLICATION_H__ */