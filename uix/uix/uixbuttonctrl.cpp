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
#include "uixbuttonctrl.h"
//----------------------------------------------------------------------------//
namespace UIX
{
//----------------------------------------------------------------------------//
uixIMPLEMENT_DYNAMIC_CLASS(uixButton, uixWindow);
//----------------------------------------------------------------------------//
// uixButton
//----------------------------------------------------------------------------//
uixButton::uixButton()
{
}
//----------------------------------------------------------------------------//
uixButton::~uixButton()
{
    DestroyWindow();
}
//----------------------------------------------------------------------------//
BOOL uixButton::BeforeWindowCreate(CREATESTRUCT& cs)
{
    if (!uixWindow::BeforeWindowCreate(cs))
    {
        return FALSE;
    }

    cs.lpszClass = WC_BUTTON;

    cs.style &= ~BS_TYPEMASK;
    cs.style |= BS_PUSHBUTTON;
    cs.style |= WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS | WS_TABSTOP;

    return TRUE;
}
//----------------------------------------------------------------------------//
// uixGroupPane
//----------------------------------------------------------------------------//
uixIMPLEMENT_DYNAMIC_CLASS(uixGroupPane, uixButton);
//----------------------------------------------------------------------------//
BOOL uixGroupPane::BeforeWindowCreate(CREATESTRUCT& cs)
{
    if (!uixButton::BeforeWindowCreate(cs))
    {
        return FALSE;
    }

    cs.style &= ~BS_TYPEMASK;
    cs.style |= BS_GROUPBOX;

    return TRUE;
}
//----------------------------------------------------------------------------//
// uixCheckBox
//----------------------------------------------------------------------------//
uixIMPLEMENT_DYNAMIC_CLASS(uixCheckBox, uixButton);
//----------------------------------------------------------------------------//
BOOL uixCheckBox::BeforeWindowCreate(CREATESTRUCT& cs)
{
    if (!uixButton::BeforeWindowCreate(cs))
    {
        return FALSE;
    }

    cs.style &= ~BS_TYPEMASK;
    cs.style |= BS_AUTOCHECKBOX;

    return TRUE;
}
//----------------------------------------------------------------------------//
// uixRadioButton
//----------------------------------------------------------------------------//
uixIMPLEMENT_DYNAMIC_CLASS(uixRadioButton, uixButton);
//----------------------------------------------------------------------------//
BOOL uixRadioButton::BeforeWindowCreate(CREATESTRUCT& cs)
{
    if (!uixButton::BeforeWindowCreate(cs))
    {
        return FALSE;
    }

    cs.style &= ~BS_TYPEMASK;
    cs.style |= BS_AUTORADIOBUTTON;

    return TRUE;
}
//----------------------------------------------------------------------------//
// uixCommandLink
//----------------------------------------------------------------------------//
uixIMPLEMENT_DYNAMIC_CLASS(uixCommandLink, uixButton);
//----------------------------------------------------------------------------//
BOOL uixCommandLink::BeforeWindowCreate(CREATESTRUCT& cs)
{
    if (!uixButton::BeforeWindowCreate(cs))
    {
        return FALSE;
    }

    cs.style &= ~BS_TYPEMASK;
    cs.style |= BS_COMMANDLINK;

    return TRUE;
}
//----------------------------------------------------------------------------//
}
//----------------------------------------------------------------------------//