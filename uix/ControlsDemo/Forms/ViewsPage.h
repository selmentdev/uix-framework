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
#include <uixtabctrl.h>
#include <uixbuttonctrl.h>
//----------------------------------------------------------------------------//
#include "../Resources/resource.h"
//----------------------------------------------------------------------------//
namespace ControlsDemo
{
using namespace UIX;

class ViewsPage : public uixTabPage
{
    uixDECLARE_EVENT_MAP();
public:
    BOOL CreateDlgFrame(uixWindow* parent);

    virtual BOOL OnInitDialog() override;
};
}
//----------------------------------------------------------------------------//