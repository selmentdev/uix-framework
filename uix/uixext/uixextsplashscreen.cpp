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
#include "uixextsplashscreen.h"
#include <uixwindowclass.h>
#include <uixexception.h>
#include <uixgdidc.h>
//----------------------------------------------------------------------------//
namespace UIX
{
//----------------------------------------------------------------------------//
uixBEGIN_EVENT_MAP(uixExtSplashScreen, uixDialog)
uixEVT_CREATE()
uixEVT_TIMER()
uixEVT_PAINT()
uixEND_EVENT_MAP()
//----------------------------------------------------------------------------//
uixExtSplashScreen::uixExtSplashScreen()
    : m_Timer(this, ID_TIMER)
    , m_Timeout(2000)
{
}
//----------------------------------------------------------------------------//
uixExtSplashScreen::~uixExtSplashScreen()
{
    DestroyWindow();
}
//----------------------------------------------------------------------------//
BOOL uixExtSplashScreen::BeforeWindowCreate(CREATESTRUCT& cs)
{
    if (!uixDialog::BeforeWindowCreate(cs))
    {
        return FALSE;
    }

    uixSize size;
    m_Bitmap.GetSize(size);
    cs.cx = size.cx;
    cs.cy = size.cy;
    cs.lpszClass = _("uixExtSplashScreen");
    cs.style
    |= uixWindowStyle_Popup | uixWindowStyle_ThickFrame;
    cs.style &= ~uixWindowStyle_Visible;
    cs.dwExStyle
    |= uixWindowStyleEx_TopMost;

    cs.hMenu = 0;

    if (!uixWindowClass::TryRegister(cs.lpszClass, ::GetSysColorBrush(uixSystemColor_ButtonFace)))
    {
        throw uixInvalidOperationException();
    }

    return TRUE;
}
//----------------------------------------------------------------------------//
BOOL uixExtSplashScreen::BeforeTranslateMessage(MSG* m)
{
    return uixDialog::BeforeTranslateMessage(m);
}
//----------------------------------------------------------------------------//
BOOL uixExtSplashScreen::CreateFromFile(const uixString& filename, UINT timeout)
{
    m_Bitmap.LoadFromFile(filename.c_str(), FALSE);
    m_Timeout = timeout;
    return uixDialog::Create(_(""), uixPoint(0, 0), uixSize(100, 100));
}
//----------------------------------------------------------------------------//
BOOL uixExtSplashScreen::CreateFromFile(uixWindow* parent, const uixString& filename, UINT timeout)
{
    m_Bitmap.LoadFromFile(filename.c_str(), FALSE);
    m_Timeout = timeout;
    return uixDialog::Create(parent, uixPoint(0, 0), uixPoint(0, 0));
}
//----------------------------------------------------------------------------//
BOOL uixExtSplashScreen::CreateFromResource(uixResourceID resID, UINT timeout)
{
    m_Bitmap.Load(resID);
    m_Timeout = timeout;
    return uixDialog::Create(_(""), uixPoint(0, 0), uixPoint(0, 0));
}
//----------------------------------------------------------------------------//
BOOL uixExtSplashScreen::CreateFromResource(uixWindow* parent, uixResourceID resID, UINT timeout)
{
    m_Bitmap.Load(resID);
    m_Timeout = timeout;
    return uixDialog::Create(parent, uixPoint(0, 0), uixPoint(0, 0));
}
//----------------------------------------------------------------------------//
void uixExtSplashScreen::OnCreate(uixCreateEventArgs& e)
{
    uixDialog::OnCreate(e);

    if (e.Result == -1)
    {
        return;
    }

    CenterWindow(uixWindowRelativePos_Desktop);

    //uixSize size;
    //m_Bitmap.GetSize(size);
    //m_BitmapDisplay.Create(this, uixPoint(0, 0), size, ID_BITMAP, uixLabelStyle_Bitmap);
    //m_BitmapDisplay.SetBitmap(m_Bitmap.GetHandle());

    m_StatusBar.Create(this);

    m_Timer.Start(m_Timeout);
}
//----------------------------------------------------------------------------//
void uixExtSplashScreen::OnTimer(uixTimerEventArgs& e)
{
    m_Timer.Stop();
    EndDialog(uixID_OK);
    DestroyWindow();
}
//----------------------------------------------------------------------------//
void uixExtSplashScreen::OnPaint(uixPaintEventArgs& e)
{
    uixPaintDC dc(GetHandle());

    uixDC mdc;
    mdc.CreateCompatible(dc);
    HBITMAP prevBmp = mdc.Select(m_Bitmap.GetHandle());

    uixSize size;
    m_Bitmap.GetSize(size);

    dc.BitBlt(0, 0, size.cx, size.cy, mdc, 0, 0, SRCCOPY);

    mdc.Select(prevBmp);
}
//----------------------------------------------------------------------------//
void uixExtSplashScreen::RecalcLayout()
{
}
//----------------------------------------------------------------------------//
BOOL uixExtSplashScreen::DoShow()
{
    return uixDialog::Show();
}
//----------------------------------------------------------------------------//
void uixExtSplashScreen::SetMessage(const uixString& message)
{
    m_StatusBar.SetText(message);
}
//----------------------------------------------------------------------------//
}
//----------------------------------------------------------------------------//