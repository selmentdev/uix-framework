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
#ifndef _UIX_RESID_H__
#define _UIX_RESID_H__
//----------------------------------------------------------------------------//
namespace UIX
{
enum uixStandardResourceID
{
    uixRESID_UIX_ID_FIRST = 0xfa00,

    // Dialogs
    uixRESID_DIALOG_ABOUT = 0xfa00,
    uixRESID_DIALOG_EXCEPTION,

    // Default strings
    uixRESID_STRING_APPNAME = 0xf100,

    uixRESID_UIX_ID_LAST,
};

enum uixStandardCommandID
{
    uixCMDID_UIX_ID_FIRST = 0xe100,
    // Menu -> File
    uixCMDID_FILE_NEW = 0xe100,
    uixCMDID_FILE_OPEN,
    uixCMDID_FILE_CLOSE,
    uixCMDID_FILE_SAVE,
    uixCMDID_FILE_SAVE_AS,
    uixCMDID_FILE_SAVE_ALL,
    uixCMDID_FILE_PAGE_SETUP,
    uixCMDID_FILE_PRINT_SETUP,
    uixCMDID_FILE_PRINT,
    uixCMDID_FILE_PRINT_DIRECT,
    uixCMDID_FILE_PRINT_PREVIEW,
    uixCMDID_FILE_UPDATE,
    uixCMDID_FILE_SAVE_COPY_AS,
    uixCMDID_FILE_SEND_MAIL,

    // Menu -> File -> MRU
    uixCMDID_FILE_MRU_FIRST = 0xe110,
    uixCMDID_FILE_MRU_FILE1,
    uixCMDID_FILE_MRU_FILE2,
    uixCMDID_FILE_MRU_FILE3,
    uixCMDID_FILE_MRU_FILE4,
    uixCMDID_FILE_MRU_FILE5,
    uixCMDID_FILE_MRU_FILE6,
    uixCMDID_FILE_MRU_FILE7,
    uixCMDID_FILE_MRU_FILE8,
    uixCMDID_FILE_MRU_FILE9,
    uixCMDID_FILE_MRU_FILE10,
    uixCMDID_FILE_MRU_FILE11,
    uixCMDID_FILE_MRU_FILE12,
    uixCMDID_FILE_MRU_FILE13,
    uixCMDID_FILE_MRU_FILE14,
    uixCMDID_FILE_MRU_FILE15,
    uixCMDID_FILE_MRU_FILE16,
    uixCMDID_FILE_MRU_LAST = uixCMDID_FILE_MRU_FILE16,

    // Menu -> Edit
    uixCMDID_EDIT_CLEAR = 0xe120,
    uixCMDID_EDIT_CLEAR_ALL,
    uixCMDID_EDIT_COPY,
    uixCMDID_EDIT_CUT,
    uixCMDID_EDIT_FIND,
    uixCMDID_EDIT_PASTE,
    uixCMDID_EDIT_PASTE_LINK,
    uixCMDID_EDIT_PASTE_SPECIAL,
    uixCMDID_EDIT_REPEAT,
    uixCMDID_EDIT_REPLACE,
    uixCMDID_EDIT_SELECT_ALL,
    uixCMDID_EDIT_UNDO,
    uixCMDID_EDIT_REDO,

    // Menu -> Window
    uixCMDID_WINDOW_NEW = 0xe130,
    uixCMDID_WINDOW_ARRANGE,
    uixCMDID_WINDOW_CASCADE,
    uixCMDID_WINDOW_TILE_HORZ,
    uixCMDID_WINDOW_TILE_VERT,
    uixCMDID_WINDOW_SPLIT,
    uixCMDID_WINDOW_TABFIRST,
    uixCMDID_WINDOW_TABLAST,
    uixCMDID_WINDOW_SHOWTABLIST,

    // App menu
    uixCMDID_APP_ABOUT = 0xe140,
    uixCMDID_APP_EXIT,
    uixCMDID_HELP_INDEX,
    uixCMDID_HELP_FIND,
    uixCMDID_HELP_USING,
    uixCMDID_HELP_CONTEXT,

    uixCMDID_UIX_ID_LAST = uixCMDID_HELP_CONTEXT,

    // Property sheet IDs
    uixCMDID_PROPSHEET_APPLY_NOW = 0x3021,
    uixCMDID_PROPSHEET_BACK = 0x3023,
    uixCMDID_PROPSHEET_NEXT = 0x3024,
    uixCMDID_PROPSHEET_FINISH = 0x3025,
    uixCMDID_PROPSHEET_TABCONTORL = 0x3020,
};
}
//----------------------------------------------------------------------------//
#endif /* _UIX_RESID_H__ */