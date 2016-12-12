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
#include "uixcolordialog.h"
//----------------------------------------------------------------------------//
namespace UIX
{
//----------------------------------------------------------------------------//
uixIMPLEMENT_DYNAMIC_CLASS(uixColorDialog, uixObject);
//----------------------------------------------------------------------------//
uixColorDialog::uixColorDialog(uixWindow* parent, uixColor color, DWORD flags)
{
    ZeroMemory(&m_Data, sizeof(m_Data));

    // Default custom colors
    static uixColor colors[16] =
    {
        0x00000000,
        0x00111111,
        0x00222222,
        0x00333333,
        0x00444444,
        0x00555555,
        0x00666666,
        0x00777777,
        0x00888888,
        0x00999999,
        0x00aaaaaa,
        0x00bbbbbb,
        0x00cccccc,
        0x00dddddd,
        0x00eeeeee,
        0x00ffffff
    };

    m_Data.lStructSize = sizeof(m_Data);
    m_Data.hwndOwner = parent->GetHandleSafe();
    m_Data.lpCustColors = (LPDWORD)colors;
    m_Data.Flags = CC_FULLOPEN;

    if (color != 0)
    {
        m_Data.rgbResult = color;
        m_Data.Flags |= CC_RGBINIT;
    }
}
//----------------------------------------------------------------------------//
uixColorDialog::~uixColorDialog()
{
}
//----------------------------------------------------------------------------//
DWORD uixColorDialog::DoModal(uixWindow* parent)
{
    uixASSERT(this != NULLPTR);

    if (m_Data.hwndOwner == NULLPTR)
    {
        m_Data.hwndOwner = parent->GetHandleSafe();
    }

    BOOL result = ::ChooseColor(&m_Data);

    if (result)
    {
        return IDOK;
    }

    return IDCANCEL;
}
//----------------------------------------------------------------------------//
}
//----------------------------------------------------------------------------//