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
#ifndef _UIXEXT_CRSPANEL_H__
#define _UIXEXT_CRSPANEL_H__
//----------------------------------------------------------------------------//
#include "uixextrequired.h"
//----------------------------------------------------------------------------//
#include <uixwindow.h>
#include <uixwindowclass.h>
#include <uixexception.h>
#include <uixgdidc.h>
#include <uixgdifont.h>
#include <uixbuttonctrl.h>
//----------------------------------------------------------------------------//
namespace UIX
{
//! Custom Rendered Style Panel
//! @brief
//!     This panel extends generic system Window to acts like panel with
//!     custom rendered style
class UIXEXTAPI uixCrsPanel : public uixWindow
{
    uixDECLARE_EVENT_MAP();
private:
    uixColor    m_CaptionBeginColor;
    uixColor    m_CaptionEndColor;
    uixColor    m_GradientBegin;
    uixColor    m_GradientEnd;
    uixColor    m_BorderColor;
    uixColor    m_FontColor;
    uixFont     m_HeaderFont;
    UINT        m_HeaderHeight;

public:
    //! Destructor
    virtual ~uixCrsPanel();
    //! @copydoc uixWindow::BeforeWindowCreate
    virtual BOOL BeforeWindowCreate(CREATESTRUCT& cs) override;
    //! @copydoc uixWindow::OnEraseBackground
    void OnEraseBackground(uixEraseBackgroundEventArgs& e);
    //! @copydoc uixWindow::OnPaint
    void OnPaint(uixPaintEventArgs& e);
    //! @copydoc uixWindow::OnNcPaint
    void OnNcPaint(uixNcPaintEventArgs& e);
    //! @copydoc uixWindow::OnNcCalcSize
    void OnNcCalcSize(uixNcCalcSizeEventArgs& e);
    //! @copydoc uixWindow::CalcNcSize
    void CalcNcSize(RECT& rc);
    //! @copydoc uixWindow::OnSize
    void OnSize(uixSizeEventArgs& e);
    //! @copydoc uixWindow::OnThemeChanged
    void OnThemeChanged(uixEventArgs& e);
};
}
//----------------------------------------------------------------------------//
#endif /* _UIXEXT_CRSPANEL_H__ */