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
#include "uixextcrspanel.h"
//----------------------------------------------------------------------------//
namespace UIX
{
//----------------------------------------------------------------------------//
uixBEGIN_EVENT_MAP(uixCrsPanel, uixWindow)
uixEVT_NCCALCSIZE()
uixEVT_ERASEBACKGROUND()
uixEVT_PAINT()
uixEVT_NCPAINT()
uixEVT_SIZE()
uixEVT_THEMECHANGED()
uixEND_EVENT_MAP()
//----------------------------------------------------------------------------//
uixCrsPanel::~uixCrsPanel()
{
    DestroyWindow();
}
//----------------------------------------------------------------------------//
BOOL uixCrsPanel::BeforeWindowCreate(CREATESTRUCT& cs)
{
    if (!uixWindow::BeforeWindowCreate(cs))
    {
        return FALSE;
    }

    cs.lpszClass = _("uixCrsPanel");
    cs.style
    |= uixWindowStyle_Child
       | uixWindowStyle_Visible
       | uixWindowStyle_ClipChildren
       | uixWindowStyle_ClipSiblings;

    // Try to register window class
    if (!uixWindowClass::TryRegister(cs.lpszClass, ::GetSysColorBrush(uixSystemColor_ButtonFace)))
    {
        throw uixInvalidOperationException(::GetLastError());
    }

    // Default height
    m_HeaderHeight = 18;

    // Stock GUI font
    m_HeaderFont.GetStock(DEFAULT_GUI_FONT);

    // Force to update colors from current theme
    uixEventArgs e(0, 0);
    OnThemeChanged(e);

    return TRUE;
}
//----------------------------------------------------------------------------//
void uixCrsPanel::OnEraseBackground(uixEraseBackgroundEventArgs& e)
{
    // Skip default background erasing
    e.Result = TRUE;
}
//----------------------------------------------------------------------------//
void uixCrsPanel::OnPaint(uixPaintEventArgs& e)
{
    uixPaintDC dc(GetHandle());
    uixRect rc;
    GetClientRect(rc);
    //rc.Deflate(1, 1);

    // Draw gradient in background, on client screen area
    dc.GradientFillRect(m_GradientBegin, m_GradientEnd, rc, FALSE);
}
//----------------------------------------------------------------------------//
void uixCrsPanel::OnNcPaint(uixNcPaintEventArgs& e)
{
    HRGN region = e.Region;

    if (region == (HRGN)1)
    {
        uixRect rc;
        GetWindowRect(rc);
        region = CreateRectRgnIndirect(&rc);
    }

    // Device context
    uixNonClientDC ndc(GetHandle(), region);

    uixRect nc;
    GetClientRect(nc);

    // Draw caption background gradient
    nc.bottom = nc.top + m_HeaderHeight - 1;
    nc.Offset(1, 1);
    ndc.GradientFillRect(
        m_CaptionBeginColor,
        m_CaptionEndColor,
        nc, TRUE);

    uixString caption;
    GetText(caption);

    // Draw transparent caption
    ndc.SetBackgroundMode(uixDCBackgroundMode_Transparent);
    ndc.SetTextColor(m_FontColor);
    HFONT prevFont = ndc.Select(m_HeaderFont);
    ndc.DrawText(
        caption.c_str(),
        (INT)caption.length(),
        nc,
        DT_CENTER | DT_VCENTER | DT_SINGLELINE | DT_NOCLIP | DT_NOPREFIX);

    ndc.Select(prevFont);

    // Draw borders
    GetWindowRect(nc);
    nc.Set(0, 0, nc.Size().cx, nc.Size().cy);
    //nc.Inflate(1, 1);
    ndc.DrawRect3D(nc, m_BorderColor, m_BorderColor);


    nc.top = nc.bottom = m_HeaderHeight - 1;
    nc.top++;
    ndc.FillSolidRect(nc, m_BorderColor);

    DeleteRgn(region);
}
//----------------------------------------------------------------------------//
void uixCrsPanel::OnNcCalcSize(uixNcCalcSizeEventArgs& e)
{
    if (e.IsCalcSize)
    {
        CalcNcSize(e.CalcSizeParams->rgrc[0]);
    }
    else
    {
        CalcNcSize(*(e.Rect));
    }

    e.Result = 0;
}
//----------------------------------------------------------------------------//
void uixCrsPanel::CalcNcSize(RECT& rc)
{
    // Clip client area
    rc.top += m_HeaderHeight - 1;
    rc.left += 1;
    rc.top += 1;
    rc.bottom -= 1;
    rc.right -= 1;
}
//----------------------------------------------------------------------------//
void uixCrsPanel::OnSize(uixSizeEventArgs& e)
{
    RedrawWindow(NULLPTR, NULLPTR, RDW_FRAME | RDW_ERASE | RDW_INVALIDATE );
    uixWindow::OnSize(e);
}
//----------------------------------------------------------------------------//
void uixCrsPanel::OnThemeChanged(uixEventArgs& e)
{
    // Aktualizacja kolorów
    m_CaptionBeginColor = ::GetSysColor(uixSystemColor_ActiveCaption);
    m_CaptionEndColor = ::GetSysColor(uixSystemColor_GradientActiveCaption);
    m_GradientBegin = ::GetSysColor(uixSystemColor_ButtonHighlight);
    m_GradientEnd = ::GetSysColor(uixSystemColor_ButtonFace);
    m_BorderColor = ::GetSysColor(uixSystemColor_ButtonShadow);
    m_FontColor = ::GetSysColor(uixSystemColor_CaptionText);
}
//----------------------------------------------------------------------------//
}
//----------------------------------------------------------------------------//