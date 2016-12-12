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
#ifndef _UIX_TOOLBARCTRL_H__
#define _UIX_TOOLBARCTRL_H__
//----------------------------------------------------------------------------//
#include "uixwindow.h"
#include "uiximagelistctrl.h"
//----------------------------------------------------------------------------//
namespace UIX
{

//! Handle
#define uixEVT_TBN_BEGINADJUST(Identifier, Handler) \
    uixEVT_NOTIFY(TBN_BEGINADJUST, Identifier, Handler)

//! Handle
#define uixEVT_TBN_BEGINDRAG(Identifier, Handler) \
    uixEVT_NOTIFY(TBN_BEGINDRAG, Identifier, Handler)

//! Handle
#define uixEVT_TBN_CUSTHELP(Identifier, Handler) \
    uixEVT_NOTIFY(TBN_CUSTHELP, Identifier, Handler)

//! Handle
#define uixEVT_TBN_DELETINGBUTTON(Identifier, Handler) \
    uixEVT_NOTIFY(TBN_DELETINGBUTTON, Identifier, Handler)

//! Handle
#define uixEVT_TBN_DRAGOUT(Identifier, Handler) \
    uixEVT_NOTIFY(TBN_DRAGOUT, Identifier, Handler)

//! Handle
#define uixEVT_TBN_DRAGOVER(Identifier, Handler) \
    uixEVT_NOTIFY(TBN_DRAGOVER, Identifier, Handler)

//! Handle
#define uixEVT_TBN_DROPDOWN(Identifier, Handler) \
    uixEVT_NOTIFY(TBN_DROPDOWN, Identifier, Handler)

//! Handle
#define uixEVT_TBN_DUPACCELERATOR(Identifier, Handler) \
    uixEVT_NOTIFY(TBN_DUPACCELERATOR, Identifier, Handler)

//! Handle
#define uixEVT_TBN_ENDADJUST(Identifier, Handler) \
    uixEVT_NOTIFY(TBN_ENDADJUST, Identifier, Handler)

//! Handle
#define uixEVT_TBN_ENDDRAG(Identifier, Handler) \
    uixEVT_NOTIFY(TBN_ENDDRAG, Identifier, Handler)

//! Handle
#define uixEVT_TBN_GETBUTTONINFO(Identifier, Handler) \
    uixEVT_NOTIFY(TBN_GETBUTTONINFO, Identifier, Handler)

//! Handle
#define uixEVT_TBN_GETDISPINFO(Identifier, Handler) \
    uixEVT_NOTIFY(TBN_GETDISPINFO, Identifier, Handler)

//! Handle
#define uixEVT_TBN_GETINFOTIP(Identifier, Handler) \
    uixEVT_NOTIFY(TBN_GETINFOTIP, Identifier, Handler)

//! Handle
#define uixEVT_TBN_GETOBJECT(Identifier, Handler) \
    uixEVT_NOTIFY(TBN_GETOBJECT, Identifier, Handler)

//! Handle
#define uixEVT_TBN_HOTITEMCHANGE(Identifier, Handler) \
    uixEVT_NOTIFY(TBN_HOTITEMCHANGE, Identifier, Handler)

//! Handle
#define uixEVT_TBN_INITCUSTOMIZE(Identifier, Handler) \
    uixEVT_NOTIFY(TBN_INITCUSTOMIZE, Identifier, Handler)

//! Handle
#define uixEVT_TBN_MAPACCELERATOR(Identifier, Handler) \
    uixEVT_NOTIFY(TBN_MAPACCELERATOR, Identifier, Handler)

//! Handle
#define uixEVT_TBN_QUERYDELETE(Identifier, Handler) \
    uixEVT_NOTIFY(TBN_QUERYDELETE, Identifier, Handler)

//! Handle
#define uixEVT_TBN_QUERYINSERT(Identifier, Handler) \
    uixEVT_NOTIFY(TBN_QUERYINSERT, Identifier, Handler)

//! Handle
#define uixEVT_TBN_RESET(Identifier, Handler) \
    uixEVT_NOTIFY(TBN_RESET, Identifier, Handler)

//! Handle
#define uixEVT_TBN_RESTORE(Identifier, Handler) \
    uixEVT_NOTIFY(TBN_RESTORE, Identifier, Handler)

//! Handle
#define uixEVT_TBN_SAVE(Identifier, Handler) \
    uixEVT_NOTIFY(TBN_SAVE, Identifier, Handler)

//! Handle
#define uixEVT_TBN_TOOLBARCHANGE(Identifier, Handler) \
    uixEVT_NOTIFY(TBN_TOOLBARCHANGE, Identifier, Handler)

//! Handle
#define uixEVT_TBN_WRAPACCELERATOR(Identifier, Handler) \
    uixEVT_NOTIFY(TBN_WRAPACCELERATOR, Identifier, Handler)

//! Handle
#define uixEVT_TBN_WRAPHOTITEM(Identifier, Handler) \
    uixEVT_NOTIFY(TBN_WRAPHOTITEM, Identifier, Handler)

//! @todo Implement
struct uixToolBarButton : TBBUTTON
{
    uixToolBarButton()
    {
        ZeroMemory(this, sizeof(uixToolBarButton));
        iBitmap = -1;
        iString = -1;
    }

    INT GetBitmap() const
    {
        return iBitmap;
    }

    void SetBitmap(INT bitmap)
    {
        iBitmap = bitmap;
    }

    UINT GetCommand() const
    {
        return (UINT)idCommand;
    }

    void SetCommand(UINT id)
    {
        idCommand = (INT)id;
    }

    UINT GetState() const
    {
        return (UINT)fsState;
    }

    void SetState(UINT toolButtonState)
    {
        fsState = (BYTE)toolButtonState;
    }

    UINT GetStyle() const
    {
        return (UINT)fsStyle;
    }

    void SetStyle(UINT style)
    {
        fsStyle = (BYTE)style;
    }

    void* GetData() const
    {
        return (void*)dwData;
    }

    void SetData(const void* data)
    {
        dwData = (DWORD)data;
    }

    INT_PTR GetString() const
    {
        return iString;
    }

    void SetString(INT_PTR stringID)
    {
        iString = stringID;
    }
};

//! @todo Implement
struct uixToolBarButtonInfo : TBBUTTONINFO
{
    BOOL IsChecked() const
    {
        return (fsState & TBSTATE_CHECKED) != 0;
    }

    BOOL IsPressed() const
    {
        return (fsState & TBSTATE_CHECKED) != 0;
    }

    BOOL IsEnabled() const
    {
        return (fsState & TBSTATE_ENABLED) != 0;
    }

    BOOL IsHidden() const
    {
        return (fsState & TBSTATE_HIDDEN) != 0;
    }

    BOOL IsWrap() const
    {
        return (fsState & TBSTATE_WRAP) != 0;
    }

    BOOL IsEllipses() const
    {
        return (fsState & TBSTATE_ELLIPSES) != 0;
    }

    BOOL IsMarked() const
    {
        return (fsState & TBSTATE_MARKED) != 0;
    }

    BOOL IsIndeterminate() const
    {
        return (fsState & TBSTATE_INDETERMINATE) != 0;
    }

    BOOL IsStyleFlat() const
    {
        return (fsStyle & TBSTYLE_FLAT) != 0;
    }

    BOOL IsStyleList() const
    {
        return (fsStyle & TBSTYLE_LIST) != 0;
    }

    BOOL IsSeparator() const
    {
        return (fsStyle & TBSTYLE_SEP) != 0;
    }

    BOOL IsStyleCheck() const
    {
        return (fsStyle & TBSTYLE_CHECK) != 0;
    }

    BOOL IsStyleDropDown() const
    {
        return (fsStyle & TBSTYLE_DROPDOWN) != 0;
    }

    BOOL IsImage() const
    {
        return (BOOL)(iImage >= 0);
    }
};

//! @todo Implement
struct uixToolBarInsertMark : TBINSERTMARK
{
};

//! @todo Implement
struct uixToolBarMetrics : TBMETRICS
{
};

//! @todo Implement
struct uixToolBarReplaceBitmap : TBREPLACEBITMAP
{
};

//! Toolbar resource data
struct uixToolBarResourceData
{
    WORD    Version;        //!< Version
    WORD    Width;          //!< Width
    WORD    Height;         //!< Height
    WORD    ItemCount;      //!< Item Count
    WORD    Items[1];       //!< Item array
};

//! Tool bar style
enum uixToolBarStyle
{
    //! Alt drag
    uixToolBarStyle_AltDrag = TBSTYLE_ALTDRAG,
    //! Custom erase
    uixToolBarStyle_CustomErase = TBSTYLE_CUSTOMERASE,
    //! Flat
    uixToolBarStyle_Flat = TBSTYLE_FLAT,
    //! List
    uixToolBarStyle_List = TBSTYLE_LIST,
    //! Register drop
    uixToolBarStyle_RegisterDrop = TBSTYLE_REGISTERDROP,
    //! Tool tips
    uixToolBarStyle_ToolTips = TBSTYLE_TOOLTIPS,
    //! Transparent
    uixToolBarStyle_Transparent = TBSTYLE_TRANSPARENT,
    //! Wrapable
    uixToolBarStyle_Wrapable = TBSTYLE_WRAPABLE,
};

//! Tool bar extended style
enum uixToolBarStyleEx
{
    //! Draw DD arrows
    uixToolBarStyleEx_DrawDDArrows = TBSTYLE_EX_DRAWDDARROWS,
    //! Hide clipped buttons
    uixToolBarStyleEx_HideClippedButtons = TBSTYLE_EX_HIDECLIPPEDBUTTONS,
    //! Double buffer
    uixToolBarStyleEx_DoubleBuffer = TBSTYLE_EX_DOUBLEBUFFER,
    //! Mixed buttons
    uixToolBarStyleEx_MixedButtons = TBSTYLE_EX_MIXEDBUTTONS,
};

//! Tool bar button state
enum uixToolBarButtonState
{
    //! Checked
    uixToolBarButtonState_Checked = TBSTATE_CHECKED,
    //! Ellipses
    uixToolBarButtonState_Ellipses = TBSTATE_ELLIPSES,
    //! Enabled
    uixToolBarButtonState_Enabled = TBSTATE_ENABLED,
    //! Hidden
    uixToolBarButtonState_Hidden = TBSTATE_HIDDEN,
    //! Indeterminate
    uixToolBarButtonState_Indeterminate = TBSTATE_INDETERMINATE,
    //! Marked
    uixToolBarButtonState_Marked = TBSTATE_MARKED,
    //! Pressed
    uixToolBarButtonState_Pressed = TBSTATE_PRESSED,
    //! Wrap
    uixToolBarButtonState_Wrap = TBSTATE_WRAP,
};

//! Tool bar button style
enum uixToolBarButtonStyle
{
    //! Auto size
    uixToolBarButtonStyle_AutoSize = BTNS_AUTOSIZE,
    //! Button
    uixToolBarButtonStyle_Button = BTNS_BUTTON,
    //! Check
    uixToolBarButtonStyle_Check = BTNS_CHECK,
    //! Check group
    uixToolBarButtonStyle_CheckGroup = BTNS_CHECKGROUP,
    //! Drop down
    uixToolBarButtonStyle_DropDown = BTNS_DROPDOWN,
    //! Group
    uixToolBarButtonStyle_Group = BTNS_GROUP,
    //! No prefix
    uixToolBarButtonStyle_NoPrefix = BTNS_NOPREFIX,
    //! Separator
    uixToolBarButtonStyle_Separator = BTNS_SEP,
    //! Show text
    uixToolBarButtonStyle_ShowText = BTNS_SHOWTEXT,
    //! Whole drop down
    uixToolBarButtonStyle_WholeDropDown = BTNS_WHOLEDROPDOWN,
};

//! ToolBar Control
//! @todo
//!     Implement
//!     - TB_GETIDEALSIZE
//!     - TB_GETIMAGELISTCOUNT
//!     - TB_GETITEMDROPDOWNRECT
//!     - TB_GETOBJECT
//!     - TB_GETPRESSEDIMAGELIST
//!     - TB_SETANCHORHIGHLIGHT
//!     - TB_SETHOTIMAGELIST
//!     - TB_SETHOTITEM2
//!     - TB_SETPRESSEDIMAGELIST
//!
//! @todo
//!     Implement loading toolbars from resources:
//!     - Loading images from imagelists
//!     - Loading strings from specified string lists
//!     - Loading buttons list from resource
class UIXAPI uixToolBarCtrl : public uixWindow
{
    uixDECLARE_DYNAMIC_CLASS(uixToolBarCtrl);
    uixDECLARE_EVENT_MAP();
public:
    //! Constructor
    //! @todo Move to cpp file
    uixToolBarCtrl();

    //! Destructor
    virtual ~uixToolBarCtrl();

    //! @copydoc uixWindow::BeforeWindowCreate
    virtual BOOL BeforeWindowCreate(CREATESTRUCT& cs) override;

    //! @copydoc uixWindow::OnCreate
    void OnCreate(uixCreateEventArgs& e);

    //! Update layout
    virtual BOOL UpdateLayout() override;

    //! Checks if button is enabled
    //! @param[in] cmdID
    //!     Command ID
    //! @return
    //!     True when successful
    BOOL IsButtonEnabled(UINT cmdID) const;

    //! Checks if button is checked
    //! @param[in] cmdID
    //!     Command ID
    //! @return
    //!     True when successful
    BOOL IsButtonChecked(UINT cmdID) const;

    //! Checks if button is pressed
    //! @param[in] cmdID
    //!     Command ID
    //! @return
    //!     True when successful
    BOOL IsButtonPressed(UINT cmdID) const;

    //! Checks if button is hidden
    //! @param[in] cmdID
    //!     Command ID
    //! @return
    //!     True when successful
    BOOL IsButtonHidden(UINT cmdID) const;

    //! Checks if button is indeterminate
    //! @param[in] cmdID
    //!     Command ID
    //! @return
    //!     True when successful
    BOOL IsButtonIndeterminate(UINT cmdID) const;

    //! Gets button state
    //! @param[in] cmdID
    //!     Command ID
    //! @return
    //!     State
    UINT GetState(UINT cmdID) const;

    //! Sets button state
    //! @param[in] cmdID
    //!     Command ID
    //! @param[in] state
    //!     Button state
    //! @return
    //!     True when successful
    BOOL SetState(UINT cmdID, UINT state);

    //! Gets button
    //! @param[in] buttonID
    //!     Button ID
    //! @param[out] button
    //!     Button
    //! @return
    //!     True when successful
    BOOL GetButton(INT buttonID, TBBUTTON& button) const;

    //! Gets button count
    //! @return
    //!     Button count
    INT GetButtonCount() const;

    //! Gets item rect
    //! @param[in] buttonID
    //!     Button ID
    //! @param[out] rect
    //!     Item rect
    //! @return
    //!     True when successful
    BOOL GetItemRect(INT buttonID, RECT& rect) const;

    //! Sets button struct size
    //! @param[in] size
    //!     Size of button struct
    void SetButtonStructSize(INT size = sizeof(TBBUTTON));

    //! Sets button size
    //! @param[in] size
    //!     Button size
    //! @return
    //!     True when successful
    BOOL SetButtonSize(SIZE size);

    //! Sets button size
    //! @param[in] cx
    //!     Width
    //! @param[in] cy
    //!     Height
    //! @return
    //!     True when successful
    BOOL SetButtonSize(INT cx, INT cy);

    //! Sets bitmap size
    //! @param[in] size
    //!     Bitmap size
    //! @return
    //!     True when successful
    BOOL SetBitmapSize(SIZE size);

    //! Sets bitmap size
    //! @param[in] cx
    //!     Width
    //! @param[in] cy
    //!     Height
    //! @return
    //!     True when successful
    BOOL SetBitmapSize(INT cx, INT cy);

    //! Gets tool tips window
    //! @return
    //!     Tool tips window handle
    HWND GetToolTips() const;

    //! Sets tool tips window handle
    //! @param[in] handle
    //!     Tool tips window handle
    void SetToolTips(HWND handle);

    //! Sets notification window
    //! @param[in] handle
    //!     Window handle
    void SetNotifyWindow(HWND handle);

    //! Gets number of rows
    //! @return
    //!     Rows count
    INT GetRows() const;

    //! Sets rows data
    //! @param[in] rows
    //!     Number of rows
    //! @param[in] larger
    //!     Grow
    //! @param[in] rect
    //!     Rect
    void SetRows(INT rows, BOOL larger, const RECT& rect);

    //! Sets command ID
    //! @param[in] index
    //!     Button index
    //! @param[in] id
    //!     Command ID
    //! @return
    //!     True when successful
    BOOL SetCmdID(INT index, UINT id);

    //! Gets bitmap flags
    //! @return
    //!     Flags
    DWORD GetBitmapFlags() const;

    //! Gets bitmap
    //! @param[in] cmdID
    //!     Command ID
    //! @return
    //!     Bitmap index
    INT GetBitmap(UINT cmdID) const;

    //! Gets button text
    //! @param[in] cmdID
    //!     Command ID
    //! @param[out] text
    //!     Button text
    //! @return
    //!     Length of text
    INT GetButtonText(UINT cmdID, uixChar* text) const;

    //! Gets button text length
    //! @param[in] cmdID
    //!     Command ID
    //! @return
    //!     Text length
    INT GetButtonTextLength(UINT cmdID) const;

    //! Gets image list handle
    //! @return
    //!     Image list handle
    HIMAGELIST GetImageList() const;

    //! Sets image list handle
    //! @param[in] handle
    //!     Image list handle
    //! @return
    //!     Previous image list handle
    HIMAGELIST SetImageList(HIMAGELIST handle);

    //! Gets disabled image list
    //! @return
    //!     Image list handle
    HIMAGELIST GetDisabledImageList() const;

    //! Sets disabled image list handle
    //! @param[in] handle
    //!     New image list handle
    //! @return
    //!     Previous image list handle
    HIMAGELIST SetDisabledImageList(HIMAGELIST handle);

    //! Gets hot image list handle
    //! @return
    //!     Image list handle
    HIMAGELIST GetHotImageList() const;

    //! Sets hot image list handle
    //! @param[in] handle
    //!     Image list handle
    //! @return
    //!     Previous image list handle
    HIMAGELIST SetHotImageList(HIMAGELIST handle);

    //! Gets style
    //! @return
    //!     Style
    DWORD GetStyle() const;

    //! Sets style
    //! @param[in] style
    //!     Style
    void SetStyle(DWORD style);

    //! Gets button size
    //! @return
    //!     Packed button size
    DWORD GetButtonSize() const;

    //! Gets button size
    //! @param[out] size
    //!     Button size
    void GetButtonSize(SIZE& size) const;

    //! Gets button rect
    //! @param[in] cmdID
    //!     Command ID
    //! @param[out] rect
    //!     Rect
    //! @return
    //!     True when successful
    BOOL GetButtonRect(UINT cmdID, RECT& rect) const;

    //! Gets number of text rows
    //! @return
    //!     Number of text rows
    INT GetTextRows() const;

    //! Sets button width
    //! @param[in] min
    //!     Min width
    //! @param[in] max
    //!     Max width
    //! @return
    //!     True when successful
    BOOL SetButtonWidth(INT min, INT max);

    //! Sets indent value
    //! @param[in] indent
    //!     Indent value
    //! @return
    //!     True when successful
    BOOL SetIndent(INT indent);

    //! Sets max text rows
    //! @param[in] max
    //!     Max text rows
    //! @return
    //!     True when successful
    BOOL SetMaxTextRows(INT max);

    //! Gets anchor highlight
    //! @return
    //!     True when successful
    BOOL GetAnchorHighlight() const;

    //! Gets button info
    //! @param[in] buttonID
    //!     Button ID
    //! @param[out] cmdID
    //!     Command ID
    //! @param[out] style
    //!     Style
    //! @param[out] image
    //!     Image index
    //! @return
    //!     True when successful
    BOOL GetButtonInfo(INT buttonID, UINT& cmdID, UINT& style, INT& image) const;

    //! Gets button info
    //! @param[in] cmdID
    //!     Command ID
    //! @param[out] tbbi
    //!     Button info
    //! @return
    //!     Button ID
    INT GetButtonInfo(UINT cmdID, TBBUTTONINFO& tbbi) const;

    //! Sets button info
    //! @param[in] cmdID
    //!     Command ID
    //! @param[in] tbbi
    //!     Button info
    //! @return
    //!     True when successful
    BOOL SetButtonInfo(UINT cmdID, const TBBUTTONINFO& tbbi);

    //! Gets hot item index
    //! @return
    //!     Index of hot item
    INT GetHotItem() const;

    //! Sets hot item index
    //! @param[in] buttonID
    //!     Button ID
    //! @return
    //!     Previous hot item index
    INT SetHotItem(INT buttonID);

    //! Checks if button is highlighted
    //! @param[in] buttonID
    //!     Button ID
    //! @return
    //!     True when successful
    BOOL IsButtonHighlighted(INT buttonID) const;

    //! Sets draw text flags
    //! @param[in] mask
    //!     Mask
    //! @param[in] flags
    //!     Flags
    //! @return
    //!     Previous draw text flags
    DWORD SetDrawTextFlags(DWORD mask, DWORD flags);

    //! Gets color scheme
    //! @param[out] cs
    //!     Color scheme
    //! @return
    //!     True when successful
    BOOL GetColorScheme(COLORSCHEME& cs) const;

    //! Sets color scheme
    //! @param[in] cs
    //!     Color scheme
    void SetColorScheme(const COLORSCHEME& cs);

    //! Gets control style
    //! @return
    //!     Style
    DWORD GetControlStyle() const;

    //! Sets control style
    //! @param[in] style
    //!     Style
    //! @return
    //!     Previous style
    DWORD SetControlStyle(DWORD style);

    //! Gets insert mark
    //! @param[out] tbim
    //!     Insert mark data
    void GetInsertMark(TBINSERTMARK& tbim) const;

    //! Sets insert mark data
    //! @param[in] tbim
    //!     Insert mark data
    void SetInsertMark(const TBINSERTMARK& tbim);

    //! Gets insert mark color
    //! @return
    //!     Color
    uixColor GetInsertMarkColor() const;

    //! Sets insert mark color
    //! @param[in] color
    //!     New color
    //! @return
    //!     Previous color
    uixColor SetInsertMarkColor(uixColor color);

    //! Gets max size
    //! @param[out] size
    //!     Size
    //! @return
    //!     True when successful
    BOOL GetMaxSize(SIZE& size) const;

    //! Gets padding
    //! @param[in] size
    //!     Padding
    void GetPadding(SIZE& size) const;

    //! Sets padding
    //! @param[in] cx
    //!     Padding width
    //! @param[in] cy
    //!     Padding height
    //! @param[out] previous
    //!     Previous padding
    void SetPadding(INT cx, INT cy, SIZE* previous = NULLPTR);

    //! Gets unicode format support
    //! @return
    //!     True when unicode supported
    BOOL GetUnicodeFormat() const;

    //! Sets unicode format
    //! @param[in] unicode
    //!     Unicode format flag
    //! @return
    //!     Previous unicode format state
    BOOL SetUnicodeFormat(BOOL unicode = TRUE);

    //! Gets string
    //! @param[in] index
    //!     Button ID
    //! @param[out] text
    //!     Text buffer
    //! @param[in] maxLength
    //!     Max text buffer length
    //! @return
    //!     Chars copied
    INT GetString(INT index, uixChar* text, INT maxLength) const;

    //! Gets metrics
    //! @param[out] tbm
    //!     Metrics
    void GetMetrics(TBMETRICS& tbm) const;

    //! Sets metrics
    //! @param[in] tbm
    //!     Metrics
    void SetMetrics(const TBMETRICS& tbm);

    //! Sets window theme
    //! @param[in] themeName
    //!     Theme name
    void SetWindowTheme(const uixChar* themeName);

    //! Enable button
    //! @param[in] cmdID
    //!     Command ID
    //! @param[in] hide
    //!     State
    //! @return
    //!     True when successful
    BOOL EnableButton(UINT cmdID, BOOL enable = TRUE);

    //! Checks button
    //! @param[in] cmdID
    //!     Command ID
    //! @param[in] hide
    //!     State
    //! @return
    //!     True when successful
    BOOL CheckButton(UINT cmdID, BOOL check = TRUE);

    //! Press button
    //! @param[in] cmdID
    //!     Command ID
    //! @param[in] hide
    //!     State
    //! @return
    //!     True when successful
    BOOL PressButton(UINT cmdID, BOOL press = TRUE);

    //! Hides button
    //! @param[in] cmdID
    //!     Command ID
    //! @param[in] hide
    //!     State
    //! @return
    //!     True when successful
    BOOL HideButton(UINT cmdID, BOOL hide = TRUE);

    //! Sets button state to indeterminate
    //! @param[in] cmdID
    //!     Command ID
    //! @param[in] indeterminate
    //!     True to indeterminate state
    //! @return
    //!     True when successful
    BOOL Indeterminate(UINT cmdID, BOOL indeterminate = TRUE);

    //! Adds bitmap
    //! @param[in] buttonCount
    //!     Number of buttons in bitmap
    //! @param[in] instance
    //!     Instance handle
    //! @param[in] bitmap
    //!     Bitmap to add
    //! @return
    //!     Number of bitmaps
    INT AddBitmap(INT buttonCount, HBITMAP bitmap);

    //! Adds buttons
    //! @param[in] buttons
    //!     Array of buttons
    //! @param[in] count
    //!     Number of elements in buttons array
    //! @return
    //!     True when successful
    BOOL AddButtons(const TBBUTTON buttons[], INT count);

    //! Inserts button
    //! @param[in] buttonID
    //!     Button ID
    //! @param[in] button
    //!     Button data
    //! @return
    //!     True when successful
    BOOL InsertButton(INT buttonID, const TBBUTTON& button);

    //! Deletes button
    //! @param[in] buttonID
    //!     Button to delete
    //! @return
    //!     True when successful
    BOOL DeleteButton(INT buttonID);

    //! Maps command to button index
    //! @param[in] cmdID
    //!     Command ID
    //! @return
    //!     Button index
    INT CommandToIndex(UINT cmdID) const;

    //! Customize toolbar
    //!
    //! @todo
    //!     Handle TBN_QUERYINSERT & TBN_QUERYDELETE
    void Customize();

    //! @todo Document this
    INT AddStringRes(uixResourceID stringID);

    //! @todo Document this
    INT AddStringRes(uixResourceName resource);

    //! Add string
    //! @param[in] instance
    //!     Instance handle
    //! @param[in] stringID
    //!     String resource ID
    //! @return
    //!     Number of chars in text
    INT AddStringRes(HINSTANCE instance, uixResourceID stringID);

    //! @todo Document this
    INT AddStringRes(HINSTANCE instance, uixResourceName resource);

    //! Add string
    //! @param[in] text
    //!     Text
    //! @return
    //!     Number of chars in text
    INT AddString(const uixChar* text);

    //! Auto size control
    void RecalcLayout();

    //! Changes bitmap
    //! @param[in] cmdID
    //!     Command ID
    //! @param[in] bitmapIndex
    //!     Bitmap index
    //! @return
    //!     True when successful
    BOOL ChangeBitmap(UINT cmdID, INT bitmapIndex);

    //! @todo Document this
    INT LoadImages(uixResourceID resourceID);

    //! @todo Document this
    INT LoadImages(uixResourceName resource);

    //! Load images
    //! @param[in] instance
    //!     Instance
    //! @param[in] resourceID
    //!     Resource ID
    //! @return
    //!     Number of images in resource
    INT LoadImages(HINSTANCE instance, uixResourceID resourceID);

    //! @todo Document this
    INT LoadImages(HINSTANCE instance, uixResourceName resource);

    //! Load standard images
    //! @param[in] resourceID
    //!     Resource ID
    //! @return
    //!     Number of images in resource
    INT LoadImagesStd(uixResourceID resourceID);

    //! Replaces bitmap
    //! @param[in] tbrb
    //!     Replace bitmap data
    //! @return
    //!     True when successful
    BOOL ReplaceBitmap(const TBREPLACEBITMAP& tbrb);

    //! @todo Document this, add overloads
    BOOL Load(uixResourceID resourceID);

    //! Perform hit test
    //! @param[in] point
    //!     Point
    //! @return
    //!     Hit test result
    INT HitTest(const POINT& point);

    //! Perform insert mark hit test
    //! @param[in] x
    //!     Left position
    //! @param[in] y
    //!     Top position
    //! @param[out] tbim
    //!     Insert mark
    //! @return
    //!     True when sucessful
    BOOL InsertMarkHitTest(INT x, INT y, TBINSERTMARK& tbim);

    //! Perform insert mark hit test
    //! @param[in] pt
    //!     Point
    //! @param[out] tbim
    //!     Insert mark
    //! @return
    //!     True when sucessful
    BOOL InsertMarkHitTest(POINT pt, TBINSERTMARK& tbim);

    //! Maps accelerator
    //! @param[in] accel
    //!     Accel char
    //! @param[out] id
    //!     ID
    //! @return
    //!     True when successful
    BOOL MapAccelerator(TCHAR accel, UINT& id);

    //! Marks button
    //! @param[in] cmdID
    //!     Command ID
    //! @param[in] highlight
    //!     Highlight
    //! @return
    //!     True when successful
    BOOL MarkButton(UINT cmdID, BOOL highlight = TRUE);

    //! Moves button
    //! @param[in] buttonID
    //!     Button ID
    //! @param[in] newButtonID
    //!     New button ID
    //! @return
    //!     True when successful
    BOOL MoveButton(INT buttonID, INT newButtonID);

protected:
    uixImageListCtrl    m_ImageList;
};
}
//----------------------------------------------------------------------------//
#include "uixtoolbarctrl.inl"
//----------------------------------------------------------------------------//
#endif /* _UIX_TOOLBARCTRL_H__ */