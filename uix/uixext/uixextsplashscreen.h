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
#ifndef _UIXEXT_SPLASHSCREEN_H__
#define _UIXEXT_SPLASHSCREEN_H__
//----------------------------------------------------------------------------//
#include "uixextrequired.h"
//----------------------------------------------------------------------------//
#include <uixWindow.h>
#include <uixgdibitmap.h>
#include <uixtimer.h>
#include <uixlabel.h>
#include <uixdialog.h>
#include <uixstatusbarctrl.h>
//----------------------------------------------------------------------------//
namespace UIX
{
class UIXEXTAPI uixExtSplashScreen : public uixDialog
{
    uixDECLARE_EVENT_MAP()
public:
    uixExtSplashScreen();
    virtual ~uixExtSplashScreen();

    BOOL CreateFromFile(const uixString& filename, UINT timeout = 2000);
    BOOL CreateFromFile(uixWindow* parent, const uixString& filename, UINT timeout = 2000);

    BOOL CreateFromResource(uixResourceID resID, UINT timeout = 2000);
    BOOL CreateFromResource(uixWindow* parent, uixResourceID resID, UINT timeout = 2000);

    BOOL DoShow();

    virtual BOOL BeforeTranslateMessage(MSG* m);
    virtual BOOL BeforeWindowCreate(CREATESTRUCT& cs);

    void OnCreate(uixCreateEventArgs& e);
    void OnTimer(uixTimerEventArgs& e);
    void OnPaint(uixPaintEventArgs& e);

    void RecalcLayout();

    enum IDs
    {
        ID_TIMER = uixID_LAST,
        ID_BITMAP,
    };

    void SetMessage(const uixString& message);

    uixBitmap           m_Bitmap;
    uixTimer            m_Timer;
    uixStatusBarCtrl    m_StatusBar;
    UINT                m_Timeout;
};
}
//----------------------------------------------------------------------------//
#endif /* _UIXEXT_SPLASHSCREEN_H__ */