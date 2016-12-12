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
#ifndef _UIX_MESSAGEMAP_H__
#define _UIX_MESSAGEMAP_H__
//----------------------------------------------------------------------------//
#include "uixrequired.h"
//----------------------------------------------------------------------------//
#include "uixtypes.h"
//----------------------------------------------------------------------------//

#define WM_REFLECTBASE 0xbc00

#define uixEVT_COMMON_NORESULT(Event, Handler) \
    { uix##Event##EventArgs e(wParam, lParam); \
        ThisClass::Handler(e); \
        *result = 0; \
        return TRUE; }

#define uixEVT_COMMON_RESULT(Event, Handler) \
    { uix##Event##EventArgs e(wParam, lParam); \
        ThisClass::Handler(e); \
        *result = (LRESULT)e.Result; \
        return TRUE; }

#define uixEVT_COMMON_DEFAULT(Handler) \
    { uixEventArgs e(wParam, lParam); \
        ThisClass::Handler(e); \
        *result = (LRESULT)0; \
        return TRUE; }

//! WM_ACTIVATE
#define uixEVT_ACTIVATE() \
    if (message == WM_ACTIVATE) uixEVT_COMMON_NORESULT(Activate, OnActivate)

//! WM_ACTIVATEAPP
#define uixEVT_ACTIVATEAPP() \
    if (message == WM_ACTIVATEAPP) uixEVT_COMMON_NORESULT(ActivateApp, OnActivateApp)

//! WM_APPCOMMAND
#define uixEVT_APPCOMMAND() \
    if (message == WM_APPCOMMAND) uixEVT_COMMON_NORESULT(AppCommand, OnAppCommand)

//! WM_ASKCBFORMATNAME
#define uixEVT_ASKCLIPBOARDFORMATNAME() \
    if (message == WM_ASKCBFORMATNAME) uixEVT_COMMON_NORESULT(ClipboardFormatName, OnClipboardFormatName)

//! WM_CANCELJOURNAL
#define uixEVT_CANCELJOURNAL() \
    if (message == WM_CANCELJOURNAL) uixEVT_COMMON_DEFAULT(OnCancelJournal)

//! WM_CANCELMODE
#define uixEVT_CANCELMODE() \
    if (message == WM_CANCELMODE) uixEVT_COMMON_DEFAULT(OnCancelMode)

//! WM_CAPTURECHANGED
#define uixEVT_CAPTURECHANGED() \
    if (message == WM_CAPTURECHANGED) uixEVT_COMMON_NORESULT(CaptureChanged, OnCaptureChanged)

//! WM_CHANGECBCHAIN
#define uixEVT_CHANGECLIPBOARDCHAIN() \
    if (message == WM_CHANGECBCHAIN) uixEVT_COMMON_NORESULT(ChangeClipboardChain, OnChangeClipboardChain)

//! WM_CHANGEUISTATE
#define uixEVT_CHANGEUISTATE() \
    if (message == WM_CHANGEUISTATE) uixEVT_COMMON_NORESULT(ChangeUiState, OnChangeUiState)

//! Common key handler
#define uixEVT_COMMON_KEY(Message, Handler) \
    if (message == (Message)) uixEVT_COMMON_NORESULT(Key, Handler)

//! WM_CHAR
#define uixEVT_CHAR() uixEVT_COMMON_KEY(WM_CHAR, OnChar)

//! WM_CHARTOITEM
#define uixEVT_CHARTOITEM() \
    if (message == WM_CHARTOITEM) uixEVT_COMMON_NORESULT(CharToItem, OnCharToItem)

//! WM_CHILDACTIVATE
#define uixEVT_CHILDACTIVATE() \
    if (message == WM_CHILDACTIVATE) uixEVT_COMMON_DEFAULT(OnChildActivate)

//! WM_CLEAR
#define uixEVT_CLEAR() \
    if (message == WM_CLEAR) uixEVT_COMMON_DEFAULT(OnClear)

//! WM_CLIPBOARDUPDATE
#define uixEVT_CLIPBOARDUPDATE() \
    if (message == WM_CLIPBOARDUPDATE) uixEVT_COMMON_DEFAULT(OnClipboardUpdate)

//! WM_CLOSE
#define uixEVT_CLOSE() \
    if (message == WM_CLOSE) uixEVT_COMMON_NORESULT(Close, OnClose)

//! WM_COMMAND
#define uixEVT_COMMAND(Identifier, Handler) \
    if ((message == WM_COMMAND) && (LOWORD(wParam) == Identifier)) \
        uixEVT_COMMON_NORESULT(Command, Handler)

//! WM_COMMAND
#define uixEVT_COMMAND_RANGE(IdFirst, IdLast, Handler) \
    if ((message == WM_COMMAND) && ((IdFirst <= LOWORD(wParam)) && (LOWORD(wParam) <= IdLast))) \
        uixEVT_COMMON_NORESULT(Command, Handler)

//! WM_COMMAND notify
#define uixEVT_CONTROL(NotifyCode, Identifier, Handler) \
    if ((message == WM_COMMAND) && (LOWORD(wParam) == Identifier) && (HIWORD(wParam) == NotifyCode)) \
        uixEVT_COMMON_NORESULT(Command, Handler)

//! WM_COMMAND_NOTIFY_RANGE
#define uixEVT_CONTROL_RANGE(NotifyCode, IdFirst, IdLast, Handler) \
    if ((message == WM_COMMAND) && ((IdFirst <= LOWORD(wParam)) && (LOWORD(wParam) <= IdLast)) && (HIWORD(wParam) == NotifyCode)) \
        uixEVT_COMMON_NORESULT(Command, Handler)

//! WM_COMPACTING
#define uixEVT_COMPACTING() \
    if (message == WM_COMPACTING) uixEVT_COMMON_NORESULT(Compacting, OnCompacting)

//! WM_COMPAREITEM
#define uixEVT_COMPAREITEM(Identifier, Handler) \
    if ((message == WM_COMPAREITEM) && ((Identifier) == ((UINT)wParam))) \
        uixEVT_COMMON_RESULT(CompareItem, Handler)

//! WM_CONTEXTMENU
#define uixEVT_CONTEXTMENU() \
    if (message == WM_CONTEXTMENU) uixEVT_COMMON_NORESULT(ContextMenu, OnContextMenu)


//! WM_COPY
#define uixEVT_COPY() \
    if (message == WM_COPY) uixEVT_COMMON_NORESULT(Copy, OnCopy)

//! WM_COPYDATA
#define uixEVT_COPYDATA() \
    if (message == WM_COPYDATA) uixEVT_COMMON_RESULT(CopyData, OnCopyData)

//! WM_CREATE
#define uixEVT_CREATE() \
    if (message == WM_CREATE) uixEVT_COMMON_RESULT(Create, OnCreate)

//! WM_CUT
#define uixEVT_CUT() \
    if (message == WM_CUT) uixEVT_COMMON_DEFAULT(OnCut)

//! WM_DEADCHAR
#define uixEVT_DEADCHAR() uixEVT_COMMON_KEY(WM_DEADCHAR, OnDeadChar)

//! WM_DELETEITEM
#define uixEVT_DELETEITEM(Identifier, Handler) \
    if ((message == WM_DELETEITEM) && ((Identifier) == ((UINT)wParam))) uixEVT_COMMON_RESULT(DeleteItem, Handler)

#define uixEVT_REFLECT_DELETEITEM(Handler) \
    if (message == (WM_DELETEITEM + WM_REFLECTBASE)) uixEVT_COMMON_RESULT(DeleteItem, Handler)

//! WM_DESTROY
#define uixEVT_DESTROY() \
    if (message == WM_DESTROY) uixEVT_COMMON_NORESULT(Destroy, OnDestroy)

//! WM_DESTROYCLIPBOARD
#define uixEVT_DESTROYCLIPBOARD() \
    if (message == WM_DESTROYCLIPBOARD) uixEVT_COMMON_NORESULT(DestroyClipboard, OnDestroyClipboard)

//! WM_DEVICECHANGE
#define uixEVT_DEVICECHANGE() \
    if (message == WM_DEVICECHANGE) uixEVT_COMMON_NORESULT(DeviceChange, OnDeviceChange)

//! WM_DEVMODECHANGE
#define uixEVT_DEVMODECHANGE() \
    if (message == WM_DEVMODECHANGE) uixEVT_COMMON_NORESULT(DevModeChange, OnDevModeChange)

//! WM_DISPLAYCHANGE
#define uixEVT_DISPLAYCHANGE() \
    if (message == WM_DISPLAYCHANGE) uixEVT_COMMON_NORESULT(DisplayChange, OnDisplayChange)

//! WM_DRAWCLIPBOARD
#define uixEVT_DRAWCLIPBOARD() \
    if (message == WM_DRAWCLIPBOARD) uixEVT_COMMON_NORESULT(DrawClipboard, OnDrawClipboard)

//! WM_DRAWITEM
#define uixEVT_DRAWITEM(Identifier, Handler) \
    if ((message == WM_DRAWITEM) && (((UINT)Identifier) == ((UINT)wParam))) \
        uixEVT_COMMON_RESULT(DrawItem, Handler)

#define uixEVT_REFLECT_DRAWITEM(Handler) \
    if (message == (WM_DRAWITEM + WM_REFLECTBASE)) \
        uixEVT_COMMON_RESULT(DrawItem, Handler)

//! WM_DROPFILES
#define uixEVT_DROPFILES() \
    if (message == WM_DROPFILES) uixEVT_COMMON_NORESULT(DropFiles, OnDropFiles)

//! WM_ENABLE
#define uixEVT_ENABLE() \
    if (message == WM_ENABLE) uixEVT_COMMON_NORESULT(Enable, OnEnable)

//! WM_ENDSESSION
#define uixEVT_ENDSESSION() \
    if (message == WM_ENDSESSION) uixEVT_COMMON_NORESULT(EndSession, OnEndSession)

//! WM_ENTERIDLE
#define uixEVT_ENTERIDLE() \
    if (message == WM_ENTERIDLE) uixEVT_COMMON_NORESULT(EnterIdle, OnEnterIdle)

//! WM_ENTERMENULOOP
#define uixEVT_ENTERMENULOOP() \
    if (message == WM_ENTERMENULOOP) uixEVT_COMMON_NORESULT(EnterMenuLoop, OnEnterMenuLoop)

//! WM_ENTERSIZEMOVE
#define uixEVT_ENTERSIZEMOVE() \
    if (message == WM_ENTERSIZEMOVE) uixEVT_COMMON_DEFAULT(OnEnterSizeMove)

//! WM_ERASEBACKGROUND
#define uixEVT_ERASEBACKGROUND() \
    if (message == WM_ERASEBKGND) uixEVT_COMMON_RESULT(EraseBackground, OnEraseBackground)

//! WM_EXITMENULOOP
#define uixEVT_EXITMENULOOP() \
    if (message == WM_EXITMENULOOP) uixEVT_COMMON_NORESULT(MenuLoop, OnExitMenuLoop)

//! WM_EXITSIZEMOVE
#define uixEVT_EXITSIZEMOVE() \
    if (message == WM_EXITSIZEMOVE) uixEVT_COMMON_DEFAULT(OnExitSizeMove)

//! WM_FONTCHANGE
#define uixEVT_FONTCHANGE() \
    if (message == WM_FONTCHANGE) uixEVT_COMMON_DEFAULT(OnFontChange)


//! WM_GETMINMAXINFO
#define uixEVT_SIZECONSTRAINTS() \
    if (message == WM_GETMINMAXINFO) uixEVT_COMMON_NORESULT(SizeConstraints, OnSizeConstraints)

//! WM_HELP
#define uixEVT_HELP() \
    if (message == WM_HELP) uixEVT_COMMON_RESULT(Help, OnHelp)

//! WM_HOTKEY
#define uixEVT_HOTKEY() \
    if (message == WM_HOTKEY) uixEVT_COMMON_NORESULT(HotKey, OnHotKey)

//! WM_HSCROLL
#define uixEVT_HSCROLL() \
    if (message == WM_HSCROLL) uixEVT_COMMON_NORESULT(Scroll, OnHScroll)

//! WM_HSCROLLCLIPBOARD
#define uixEVT_HSCROLLCLIPBOARD() \
    if (message == WM_HSCROLLCLIPBOARD) uixEVT_COMMON_NORESULT(ScrollClipboard, OnHScrollClipboard)

//! WM_INITDIALOG
#define uixEVT_INITDIALOG() \
    if (message == WM_INITDIALOG) uixEVT_COMMON_RESULT(InitDialog, OnInitDialog)

//! WM_INITMENU
#define uixEVT_INITMENU() \
    if (message == WM_INITMENU) uixEVT_COMMON_NORESULT(InitMenu, OnInitMenu)

//! WM_INITMENUPOPUP
#define uixEVT_INITMENUPOPUP() \
    if (message == WM_INITMENUPOPUP) uixEVT_COMMON_NORESULT(InitMenuPopup, OnInitMenuPopup)

//! WM_INPUT
//! WM_INPUT_DEVICE_CHANGE
//! WM_INPUTLANGCHANGE
//! WM_INPUTLANGCHANGEREQUEST

//! WM_KEYDOWN
#define uixEVT_KEYDOWN() uixEVT_COMMON_KEY(WM_KEYDOWN, OnKeyDown)

//! WM_KEYUP
#define uixEVT_KEYUP() uixEVT_COMMON_KEY(WM_KEYUP, OnKeyUp)

//! WM_KILLFOCUS
#define uixEVT_KILLFOCUS() \
    if (message == WM_KILLFOCUS) uixEVT_COMMON_NORESULT(FocusChange, OnKillFocus)

//! Mouse common
#define uixEVT_MOUSE_COMMON(Message, Handler, Button, Clicks) \
    if (message == (Message)) { \
        uixMouseEventArgs e((UINT)wParam | (Button), lParam, Clicks); \
        ThisClass::Handler(e); \
        *result = 0; \
        return TRUE; }

//! WM_LBUTTONDBLCLK
#define uixEVT_LMOUSEDOUBLECLICK() uixEVT_MOUSE_COMMON(WM_LBUTTONDBLCLK, OnMouseDoubleClick, MK_LBUTTON, 2)
//! WM_MBUTTONDBLCLK
#define uixEVT_MMOUSEDOUBLECLICK() uixEVT_MOUSE_COMMON(WM_MBUTTONDBLCLK, OnMouseDoubleClick, MK_MBUTTON, 2)
//! WM_RBUTTONDBLCLK
#define uixEVT_RMOUSEDOUBLECLICK() uixEVT_MOUSE_COMMON(WM_RBUTTONDBLCLK, OnMouseDoubleClick, MK_RBUTTON, 2)
//! WM_XBUTTONDBLCLK
#define uixEVT_XMOUSEDOUBLECLICK() uixEVT_MOUSE_COMMON(WM_XBUTTONDBLCLK, OnMouseDoubleClick, MK_XBUTTON1, 2)

//! WM_LBUTTONDOWN
#define uixEVT_LMOUSEDOWN() uixEVT_MOUSE_COMMON(WM_LBUTTONDOWN, OnMouseDown, MK_LBUTTON, 1)
//! WM_MBUTTONDOWN
#define uixEVT_MMOUSEDOWN() uixEVT_MOUSE_COMMON(WM_MBUTTONDOWN, OnMouseDown, MK_MBUTTON, 1)
//! WM_RBUTTONDOWN
#define uixEVT_RMOUSEDOWN() uixEVT_MOUSE_COMMON(WM_RBUTTONDOWN, OnMouseDown, MK_RBUTTON, 1)
//! WM_XBUTTONDOWN
#define uixEVT_XMOUSEDOWN() uixEVT_MOUSE_COMMON(WM_XBUTTONDOWN, OnMouseDown, MK_XBUTTON1, 1)

//! WM_LBUTTONUP
#define uixEVT_LMOUSEUP() uixEVT_MOUSE_COMMON(WM_LBUTTONUP, OnMouseUp, MK_LBUTTON, 1)
//! WM_MBUTTONUP
#define uixEVT_MMOUSEUP() uixEVT_MOUSE_COMMON(WM_MBUTTONUP, OnMouseUp, MK_MBUTTON, 1)
//! WM_RBUTTONUP
#define uixEVT_RMOUSEUP() uixEVT_MOUSE_COMMON(WM_RBUTTONUP, OnMouseUp, MK_RBUTTON, 1)
//! WM_XBUTTONUP
#define uixEVT_XMOUSEUP() uixEVT_MOUSE_COMMON(WM_XBUTTONUP, OnMouseUp, MK_XBUTTON1, 1)

//! WM_MOUSEHOVER
#define uixEVT_MOUSEHOVER() uixEVT_MOUSE_COMMON(WM_MOUSEHOVER, OnMouseHover, 0, 0)
//! WM_MOUSEMOVE
#define uixEVT_MOUSEMOVE() uixEVT_MOUSE_COMMON(WM_MOUSEMOVE, OnMouseMove, 0, 0)

//! WM_MOUSEWHEEL
#define uixEVT_MOUSEWHEEL() uixEVT_MOUSE_COMMON(WM_MOUSEWHEEL, OnMouseWheel, 0, 0)
//! WM_MOUSEHWHEEL
#define uixEVT_MOUSEHWHEEL() uixEVT_MOUSE_COMMON(WM_MOUSEHWHEEL, OnMouseHWheel, 0, 0)

//! WM_NCMOUSELEAVE
#define uixEVT_NCMOUSELEAVE() \
    if (message == WM_NCMOUSELEAVE) uixEVT_COMMON_DEFAULT(OnNcMouseLeave)

//! WM_MOUSELEAVE
#define uixEVT_MOUSELEAVE() \
    if (message == WM_MOUSELEAVE) uixEVT_COMMON_DEFAULT(OnMouseLeave)

//! WM_MOUSEACTIVATE
#define uixEVT_MOUSEACTIVATE() \
    if (message == WM_MOUSEACTIVATE) uixEVT_COMMON_RESULT(MouseActivate, OnMouseActivate)

//! Mouse common
#define uixEVT_NCMOUSE_COMMON(Message, Handler) \
    if (message == (Message)) uixEVT_COMMON_NORESULT(NcMouse, Handler)

//! WM_NCMOUSEHOVER
#define uixEVT_NCMOUSEHOVER() uixEVT_NCMOUSE_COMMON(WM_NCMOUSEHOVER, OnNcMouseHover)
//! WM_NCMOUSEMOVE
#define uixEVT_NCMOUSEMOVE() uixEVT_NCMOUSE_COMMON(WM_NCMOUSEMOVE, OnNcMouseMove)

//! WM_NCLBUTTONDBLCLK
#define uixEVT_LNCMOUSEDOUBLECLICK() uixEVT_NCMOUSE_COMMON(WM_NCLBUTTONDBLCLK, OnNcMouseDoubleClick)
//! WM_NCMBUTTONDBLCLK
#define uixEVT_MNCMOUSEDOUBLECLICK() uixEVT_NCMOUSE_COMMON(WM_NCMBUTTONDBLCLK, OnNcMouseDoubleClick)
//! WM_NCRBUTTONDBLCLK
#define uixEVT_RNCMOUSEDOUBLECLICK() uixEVT_NCMOUSE_COMMON(WM_NCRBUTTONDBLCLK, OnNcMouseDoubleClick)
//! WM_NCXBUTTONDBLCLK
#define uixEVT_XNCMOUSEDOUBLECLICK() uixEVT_NCMOUSE_COMMON(WM_NCXBUTTONDBLCLK, OnNcMouseDoubleClick)

//! WM_NCLBUTTONDOWN
#define uixEVT_LNCMOUSEDOWN() uixEVT_NCMOUSE_COMMON(WM_NCLBUTTONDOWN, OnNcMouseDown)
//! WM_NCMBUTTONDOWN
#define uixEVT_MNCMOUSEDOWN() uixEVT_NCMOUSE_COMMON(WM_NCMBUTTONDOWN, OnNcMouseDown)
//! WM_NCRBUTTONDOWN
#define uixEVT_RNCMOUSEDOWN() uixEVT_NCMOUSE_COMMON(WM_NCRBUTTONDOWN, OnNcMouseDown)
//! WM_NCXBUTTONDOWN
#define uixEVT_XNCMOUSEDOWN() uixEVT_NCMOUSE_COMMON(WM_NCXBUTTONDOWN, OnNcMouseDown)

//! WM_NCLBUTTONUP
#define uixEVT_LNCMOUSEUP() uixEVT_NCMOUSE_COMMON(WM_NCLBUTTONUP, OnNcMouseUp)
//! WM_NCMBUTTONUP
#define uixEVT_MNCMOUSEUP() uixEVT_NCMOUSE_COMMON(WM_NCMBUTTONUP, OnNcMouseUp)
//! WM_NCRBUTTONUP
#define uixEVT_RNCMOUSEUP() uixEVT_NCMOUSE_COMMON(WM_NCRBUTTONUP, OnNcMouseUp)
//! WM_NCXBUTTONUP
#define uixEVT_XNCMOUSEUP() uixEVT_NCMOUSE_COMMON(WM_NCXBUTTONUP, OnNcMouseUp)

//! WM_MDIACTIVATE
//! WM_MDICASCADE
//! WM_MDICREATE
//! WM_MDIDESTROY
//! WM_MDIGETACTIVE
//! WM_MDIICONARRANGE
//! WM_MDIMAXIMIZE
//! WM_MDINEXT
//! WM_MDIREFRESHMENU
//! WM_MDIRESTORE
//! WM_MDISETMENU
//! WM_MDITILE

//! WM_MEASUREITEM
#define uixEVT_MEASUREITEM(Identifier, Handler) \
    if ((message == WM_MEASUREITEM) && ((Identifier) == ((UINT)wParam))) \
        uixEVT_COMMON_RESULT(MeasureItem, Handler)

#define uixEVT_REFLECT_MEASUREITEM(Handler) \
    if (message == (WM_MEASUREITEM + WM_REFLECTBASE)) \
        uixEVT_COMMON_RESULT(MeasureItem, Handler)

//! WM_MENUCHAR
//! WM_MENUCOMMAND
//! WM_MENUDRAG
//! WM_MENUGETOBJECT
//! WM_MENURBUTTONUP
//! WM_MENUSELECT

//! WM_MOVE
#define uixEVT_MOVE() \
    if (message == WM_MOVE) uixEVT_COMMON_NORESULT(Move, OnMove)

//! WM_MOVING
#define uixEVT_MOVING() \
    if (message == WM_MOVING) uixEVT_COMMON_RESULT(BorderChange, OnMoving)

//! WM_NCACTIVATE

//! WM_NCCALCSIZE
#define uixEVT_NCCALCSIZE() \
    if (message == WM_NCCALCSIZE) uixEVT_COMMON_RESULT(NcCalcSize, OnNcCalcSize)

//! WM_NCCREATE
//! WM_NCDESTROY
//! WM_NCHITTEST

//! WM_NCPAINT
#define uixEVT_NCPAINT() \
    if (message == WM_NCPAINT) uixEVT_COMMON_NORESULT(NcPaint, OnNcPaint)

//! WM_NEXTDLGCTL
//! WM_NEXTMENU

//! WM_NOTIFY
#define uixEVT_NOTIFY(Code, Identifier, Handler) \
    if ((message == WM_NOTIFY) && (Code == ((NMHDR*)lParam)->code) && (Identifier == ((NMHDR*)lParam)->idFrom)) \
        uixEVT_COMMON_RESULT(Notify, Handler)

#define uixEVT_NOTIFY_RANGE(Code, IdFirst, IdLast, Handler) \
    if ((message == WM_NOTIFY) && (Code == ((NMHDR*)lParam)->code) && ((IdFirst <= ((NMHDR*)lParam)->idFrom) && (((NMHDR*)lParam)->idFrom <= IdLast))) \
        uixEVT_COMMON_RESULT(Notify, Handler)

#define uixEVT_REFLECT_NOTIFY(Code, Handler) \
    if ((message == (WM_NOTIFY + WM_REFLECTBASE)) && (Code == ((NMHDR*)lParam)->code)) \
        uixEVT_COMMON_RESULT(Notify, Handler)

//! WM_NOTIFYFORMAT

//! WM_PAINT
#define uixEVT_PAINT() \
    if (message == WM_PAINT) uixEVT_COMMON_NORESULT(Paint, OnPaint)

//! WM_PAINTCLIPBOARD
//! WM_PAINTICON
//! WM_PALETTECHANGED
//! WM_PALETTEISCHANGING
//! WM_PARENTNOTIFY
//! WM_PASTE
//! WM_POWER
//! WM_POWERBROADCAST
//! WM_PRINT
//! WM_PRINTCLIENT
//! WM_QUERYDRAGICON
//! WM_QUERYENDSESSION
//! WM_QUERYNEWPALETTE
//! WM_QUERYOPEN

//! WM_QUERYUISTATE
#define uixEVT_QUERYUISTATE() \
    if (message == WM_QUERYUISTATE) uixEVT_COMMON_RESULT(QueryUiState, OnQueryUiState)

//! WM_QUEUESYNC
#define uixEVT_QUEUESYNC() \
    if (message == WM_QUIT) uixEVT_COMMON_DEFAULT(OnQueueSync)

//! WM_QUIT
#define uixEVT_QUIT() \
    if (message == WM_QUIT) uixEVT_COMMON_NORESULT(Quit, OnQuit)

//! WM_RENDERALLFORMATS
#define uixEVT_RENDERALLFORMATS() \
    if (message == WM_RENDERALLFORMATS) uixEVT_COMMON_DEFAULT(OnRenderAllFormats)

//! WM_RENDERFORMAT
#define uixEVT_RENDERFORMAT() \
    if (message == WM_RENDERFORMAT) uixEVT_COMMON_NORESULT(RenderFormat, OnRenderFormat)

//! WM_SETFOCUS
#define uixEVT_SETFOCUS() \
    if (message == WM_SETFOCUS) uixEVT_COMMON_NORESULT(FocusChange, OnSetFocus)

//! WM_SETTINGCHANGE
#define uixEVT_SETTINGCHANGE() \
    if (message == WM_SETTINGCHANGE) uixEVT_COMMON_NORESULT(SettingChange, OnSettingChange)

//! WM_SHOWWINDOW
#define uixEVT_SHOWWINDOW() \
    if (message == WM_SHOWWINDOW) uixEVT_COMMON_NORESULT(ShowWindow, OnShowWindow)

//! WM_SIZECLIPBOARD
#define uixEVT_SIZECLIPBOARD() \
    if (message == WM_SIZECLIPBOARD) uixEVT_COMMON_NORESULT(SizeClipboard, OnSizeClipboard)

//! WM_SIZE
#define uixEVT_SIZE() \
    if (message == WM_SIZE) uixEVT_COMMON_NORESULT(Size, OnSize)

//! WM_SIZING
#define uixEVT_SIZING() \
    if (message == WM_SIZING) uixEVT_COMMON_RESULT(BorderChange, OnSizing)

//! WM_SPOOLERSTATUS
#define uixEVT_SPOOLERSTATUS() \
    if (message == WM_SPOOLERSTATUS) uixEVT_COMMON_NORESULT(SpoolerStatus, OnSpoolerStatus)

//! WM_STYLECHANGED
#define uixEVT_STYLECHANGED() \
    if (message == WM_STYLECHANGED) uixEVT_COMMON_NORESULT(StyleChange, OnStyleChanged)

//! WM_STYLECHANGING
#define uixEVT_STYLECHANGING() \
    if (message == WM_STYLECHANGING) uixEVT_COMMON_NORESULT(StyleChange, OnStyleChanging)

//! WM_SYNCPAINT
#define uixEVT_SYNCPAINT() \
    if (message == WM_SYNCPAINT) uixEVT_COMMON_DEFAULT(OnSyncPaint)

//! WM_SYSCHAR
#define uixEVT_SYSCHAR() uixEVT_COMMON_KEY(WM_SYSCHAR, OnSysChar)

//! WM_SYSCOLORCHANGE
#define uixEVT_SYSCOLORCHANGE() \
    if (message == WM_SYSCOLORCHANGE) uixEVT_COMMON_DEFAULT(OnSysColorChange)

//! WM_SYSCOMMAND
#define uixEVT_SYSCOMMAND(Identifier, Handler) \
    if ((message == WM_SYSCOMMAND) && (wParam == Identifier)) \
        uixEVT_COMMON_NORESULT(Command, Handler)

//! WM_SYSDEADCHAR
#define uixEVT_SYSDEADCHAR() uixEVT_COMMON_KEY(WM_SYSDEADCHAR, OnSysDeadChar)

//! WM_SYSKEYDOWN
#define uixEVT_SYSKEYDOWN() uixEVT_COMMON_KEY(WM_SYSKEYDOWN, OnSysKeyDown)

//! WM_SYSKEYUP
#define uixEVT_SYSKEYUP() uixEVT_COMMON_KEY(WM_SYSKEYUP, OnSysKeyUp)

//! WM_TCARD

//! WM_THEMECHANGED
#define uixEVT_THEMECHANGED() \
    if (message == WM_THEMECHANGED) uixEVT_COMMON_DEFAULT(OnThemeChanged)

//! WM_TIMECHANGE
#define uixEVT_TIMECHANGE() \
    if (message == WM_TIMECHANGE) uixEVT_COMMON_DEFAULT(OnTimeChange)

//! WM_TIMER
#define uixEVT_TIMER() \
    if (message == WM_TIMER) uixEVT_COMMON_NORESULT(Timer, OnTimer)

//! WM_UNDO
#define uixEVT_UNDO() \
    if (message == WM_UNDO) uixEVT_COMMON_RESULT(Undo, OnUndo)

//! WM_UNICHAR
#define uixEVT_UNICHAR() uixEVT_COMMON_KEY(WM_UNICHAR, OnUniChar)

//! WM_UNINITMENUPOPUP
#define uixEVT_UNINITMENUPOPUP() \
    if (message == WM_UNINITMENUPOPUP) uixEVT_COMMON_NORESULT(UnInitMenuPopup, OnUnInitMenuPopup)

//! WM_UPDATEUISTATE
#define uixEVT_UPDATEUISTATE() \
    if (message == WM_UPDATEUISTATE) uixEVT_COMMON_NORESULT(UpdateUiState, OnUpdateUiState)

//! WM_USERCHANGED
#define uixEVT_USERCHANGED() \
    if (message == WM_USERCHANGED) uixEVT_COMMON_DEFAULT(OnUserChanged)

//! WM_VKEYTOITEM
#define uixEVT_VKEYTOITEM() \
    if (message == WM_VKEYTOITEM) uixEVT_COMMON_RESULT(VKeyToItem, OnVKeyToItem)

//! WM_VSCROLL
#define uixEVT_VSCROLL() \
    if (message == WM_VSCROLL) uixEVT_COMMON_NORESULT(Scroll, OnVScroll)

//! WM_VSCROLLCLIPBOARD
#define uixEVT_VSCROLLCLIPBOARD() \
    if (message == WM_VSCROLLCLIPBOARD) uixEVT_COMMON_NORESULT(ScrollClipboard, OnVScrollClipboard)

//! WM_WINDOWPOSCHANGED
#define uixEVT_WINDOWPOSCHANGED() \
    if (message == WM_WINDOWPOSCHANGED) uixEVT_COMMON_NORESULT(WindowPosChange, OnWindowPosChanged)

//! WM_WINDOWPOSCHANGING
#define uixEVT_WINDOWPOSCHANGING() \
    if (message == WM_WINDOWPOSCHANGING) uixEVT_COMMON_NORESULT(WindowPosChange, OnWindowPosChanging)

//! WM_WTSSESSION_CHANGE
#define uixEVT_WTSSESSIONCHANGE() \
    if (message == WM_WTSSESSION_CHANGE) uixEVT_COMMON_NORESULT(WtsSessionChange, OnWtsSessionChange)


// Notifies

//!
#define uixEVT_NM_CACHEHINT(Identifier, Handler) \
    uixEVT_NOTIFY(NM_CACHEHINT, Identifier, Handler)

//!
#define uixEVT_NM_CHAR(Identifier, Handler) \
    uixEVT_NOTIFY(NM_CHAR, Identifier, Handler)

//!
#define uixEVT_NM_CLICK(Identifier, Handler) \
    uixEVT_NOTIFY(NM_CLICK, Identifier, Handler)

//!
#define uixEVT_NM_CUSTOMDRAW(Identifier, Handler) \
    uixEVT_NOTIFY(NM_CUSTOMDRAW, Identifier, Handler)

//!
#define uixEVT_NM_CUSTOMTEXT(Identifier, Handler) \
    uixEVT_NOTIFY(NM_CUSTOMTEXT, Identifier, Handler)

//!
#define uixEVT_NM_DBLCLK(Identifier, Handler) \
    uixEVT_NOTIFY(NM_DBLCLK, Identifier, Handler)

//!
#define uixEVT_NM_FINDITEM(Identifier, Handler) \
    uixEVT_NOTIFY(NM_FINDITEM, Identifier, Handler)

//!
#define uixEVT_NM_FONTCHANGED(Identifier, Handler) \
    uixEVT_NOTIFY(NM_FONTCHANGED, Identifier, Handler)

//!
#define uixEVT_NM_GETCUSTOMSPLITRECT(Identifier, Handler) \
    uixEVT_NOTIFY(NM_GETCUSTOMSPLITRECT, Identifier, Handler)

//!
#define uixEVT_NM_HOVER(Identifier, Handler) \
    uixEVT_NOTIFY(NM_HOVER, Identifier, Handler)

//!
#define uixEVT_NM_KEYDOWN(Identifier, Handler) \
    uixEVT_NOTIFY(NM_KEYDOWN, Identifier, Handler)

//!
#define uixEVT_NM_KILLFOCUS(Identifier, Handler) \
    uixEVT_NOTIFY(NM_KILLFOCUS, Identifier, Handler)

//!
#define uixEVT_NM_LDOWN(Identifier, Handler) \
    uixEVT_NOTIFY(NM_LDOWN, Identifier, Handler)

//!
#define uixEVT_NM_LISTVIEW(Identifier, Handler) \
    uixEVT_NOTIFY(NM_LISTVIEW, Identifier, Handler)

//!
#define uixEVT_NM_NCHITTEST(Identifier, Handler) \
    uixEVT_NOTIFY(NM_NCHITTEST, Identifier, Handler)

//!
#define uixEVT_NM_ODSTATECHANGE(Identifier, Handler) \
    uixEVT_NOTIFY(NM_ODSTATECHANGE, Identifier, Handler)

//!
#define uixEVT_NM_OUTOFMEMORY(Identifier, Handler) \
    uixEVT_NOTIFY(NM_OUTOFMEMORY, Identifier, Handler)

//!
#define uixEVT_NM_RCLICK(Identifier, Handler) \
    uixEVT_NOTIFY(NM_RCLICK, Identifier, Handler)

//!
#define uixEVT_NM_RDBLCLK(Identifier, Handler) \
    uixEVT_NOTIFY(NM_RDBLCLK, Identifier, Handler)

//!
#define uixEVT_NM_RDOWN(Identifier, Handler) \
    uixEVT_NOTIFY(NM_RDOWN, Identifier, Handler)

//!
#define uixEVT_NM_RELEASEDCAPTURE(Identifier, Handler) \
    uixEVT_NOTIFY(NM_RELEASEDCAPTURE, Identifier, Handler)

//!
#define uixEVT_NM_RETURN(Identifier, Handler) \
    uixEVT_NOTIFY(NM_RETURN, Identifier, Handler)

//!
#define uixEVT_NM_SETCURSOR(Identifier, Handler) \
    uixEVT_NOTIFY(NM_SETCURSOR, Identifier, Handler)

//!
#define uixEVT_NM_SETFOCUS(Identifier, Handler) \
    uixEVT_NOTIFY(NM_SETFOCUS, Identifier, Handler)

//!
#define uixEVT_NM_THEMECHANGED(Identifier, Handler) \
    uixEVT_NOTIFY(NM_THEMECHANGED, Identifier, Handler)

//!
#define uixEVT_NM_TOOLTIPSCREATED(Identifier, Handler) \
    uixEVT_NOTIFY(NM_TOOLTIPSCREATED, Identifier, Handler)

//!
#define uixEVT_NM_TREEVIEW(Identifier, Handler) \
    uixEVT_NOTIFY(NM_TREEVIEW, Identifier, Handler)

//!
#define uixEVT_NM_TVSTATEIMAGECHANGING(Identifier, Handler) \
    uixEVT_NOTIFY(NM_TVSTATEIMAGECHANGING, Identifier, Handler)

//!
#define uixEVT_NM_UPDOWN(Identifier, Handler) \
    uixEVT_NOTIFY(NM_UPDOWN, Identifier, Handler)

// End-Notifies

#define uixEVT_REFLECT_COMMAND_PARENT() \
    if (message == WM_COMMAND) { \
        HWND parent = this->GetParent(); \
        *result = ::SendMessage(parent, message, wParam, lParam); \
    }

#define uixEVT_REFLECT_COLOR(Handler) \
    switch (message) \
    { \
    case WM_REFLECTBASE + WM_CTLCOLORMSGBOX: \
    case WM_REFLECTBASE + WM_CTLCOLOREDIT: \
    case WM_REFLECTBASE + WM_CTLCOLORLISTBOX: \
    case WM_REFLECTBASE + WM_CTLCOLORBTN: \
    case WM_REFLECTBASE + WM_CTLCOLORDLG: \
    case WM_REFLECTBASE + WM_CTLCOLORSCROLLBAR: \
    case WM_REFLECTBASE + WM_CTLCOLORSTATIC: \
        { \
            UIX::uixControlColorEventArgs e(message, wParam, lParam); \
            Handler(e); \
            *result = (LRESULT)e.Result; \
            return TRUE; \
        } \
    }

#define uixEVT_COLOR(Handler) \
    switch (message) \
    { \
    case WM_CTLCOLORMSGBOX: \
    case WM_CTLCOLOREDIT: \
    case WM_CTLCOLORLISTBOX: \
    case WM_CTLCOLORBTN: \
    case WM_CTLCOLORDLG: \
    case WM_CTLCOLORSCROLLBAR: \
    case WM_CTLCOLORSTATIC: \
        { \
            UIX::uixControlColorEventArgs e(message, wParam, lParam); \
            Handler(e); \
            *result = (LRESULT)e.Result; \
            return e.Processed; \
        } \
    }



namespace UIX
{
//! Base event struct
struct uixEventArgs
{
    uixEventArgs(WPARAM w, LPARAM l)
        : WParam(w)
        , LParam(l)
    {

    }

    WPARAM WParam;  //!< WPARAM Value
    LPARAM LParam;  //!< LPARAM Value
};

struct uixControlColorEventArgs : uixEventArgs
{
    enum uixColorRequest
    {
        uixColorRequest_MessageBox      = WM_CTLCOLOR,
        uixColorRequest_Edit            = WM_CTLCOLOREDIT,
        uixColorRequest_ListBox         = WM_CTLCOLORLISTBOX,
        uixColorRequest_Button          = WM_CTLCOLORBTN,
        uixColorRequest_Dialog          = WM_CTLCOLORDLG,
        uixColorRequest_ScrollBar       = WM_CTLCOLORSCROLLBAR,
        uixColorRequest_Label           = WM_CTLCOLORSTATIC,
    };

    uixControlColorEventArgs(UINT request, WPARAM w, LPARAM l)
        : uixEventArgs(w, l)
    {
        Request = (uixColorRequest)request;
        Sender = (HWND)l;
        DeviceContext = (HDC)w;
        Processed = FALSE;
    }

    uixColorRequest     Request;            //!< Color Request
    HWND                Sender;             //!< Sender window handle
    HDC                 DeviceContext;      //!< Device context
    HBRUSH              Result;             //!< Handle to brush
    BOOL                Processed;          //!< Processed flag
};

enum uixActivateState
{
    uixActivateState_Active = WA_ACTIVE,
    uixActivateState_ClickActive = WA_CLICKACTIVE,
    uixActivateState_Inactive = WA_INACTIVE,
};

struct uixActivateEventArgs : uixEventArgs
{
    uixActivateEventArgs(WPARAM w, LPARAM l)
        : uixEventArgs(w, l)
    {
        State = (uixActivateState)LOWORD(w);
        Minimized = (BOOL)HIWORD(w);
        PreviousWindow = (HWND)l;
    }

    uixActivateState    State;              //!< Activation state
    BOOL                Minimized;          //!< Is minimized
    HWND                PreviousWindow;     //!< Previous window handle
};

struct uixActivateAppEventArgs : uixEventArgs
{
    uixActivateAppEventArgs(WPARAM w, LPARAM l)
        : uixEventArgs(w, l)
    {
        Active = (BOOL)w;
        ThreadID = (DWORD)l;
    }

    BOOL Active;                            //!< Active flag
    DWORD ThreadID;                         //!< Thread ID
};

struct uixAppCommandEventArgs : uixEventArgs
{
    uixAppCommandEventArgs(WPARAM w, LPARAM l)
        : uixEventArgs(w, l)
    {
        Window = (HWND)w;
        Command = (UINT)GET_APPCOMMAND_LPARAM(l);
        Device = (UINT)GET_DEVICE_LPARAM(l);
        Keys = (UINT)GET_KEYSTATE_LPARAM(l);
    }

    HWND    Window;                         //!< Window handle
    UINT    Command;                        //!< Command ID
    UINT    Device;                         //!< Device ID
    UINT    Keys;                           //!< Key ID
};

struct uixClipboardFormatNameEventArgs : uixEventArgs
{
    uixClipboardFormatNameEventArgs(WPARAM w, LPARAM l)
        : uixEventArgs(w, l)
    {
        Name = (uixChar*)l;
        Length = (UINT)w;;
    }

    uixChar*    Name;                       //!< Clipboard format name
    UINT        Length;                     //!< Name length
};

struct uixCaptureChangedEventArgs : uixEventArgs
{
    uixCaptureChangedEventArgs(WPARAM w, LPARAM l)
        : uixEventArgs(w, l)
    {
        NextWindow = (HWND)l;
    }

    HWND    NextWindow;                     //!< Next window handle
};

struct uixChangeClipboardChainEventArgs : uixEventArgs
{
    uixChangeClipboardChainEventArgs(WPARAM w, LPARAM l)
        : uixEventArgs(w, l)
    {
        Removed = (HWND)w;
        Next = (HWND)l;
    }

    HWND    Removed;                        //!< Removed window handle
    HWND    Next;                           //!< Next window handle
};

struct uixChangeUiStateEventArgs : uixEventArgs
{
    uixChangeUiStateEventArgs(WPARAM w, LPARAM l)
        : uixEventArgs(w, l)
    {
        Action = (UINT)LOWORD(w);
        Element = (UINT)HIWORD(w);
    }

    UINT    Action;                         //!< Action ID
    UINT    Element;                        //!< Element ID
};

struct uixKeyEventArgs : uixEventArgs
{
    uixKeyEventArgs(WPARAM w, LPARAM l)
        : uixEventArgs(w, l)
    {
        Char = (UINT)w;
        Flags = (UINT)l;
    }

    UINT        Char;                       //!< Virtual key

    union
    {
        UINT    Flags;                      //!< Flags
        struct
        {
            UINT    RepeatCount : 16;       //!< Repeat count
            UINT    ScanCode : 8;           //!< Snap code
            UINT    Extended : 1;           //!< Extended key
            UINT    Reserved : 4;           //!< Unused
            UINT    Alt : 1;                //!< Alt pressed
            UINT    KeyDown : 1;            //!< Key is down
            UINT    Released : 1;           //!< Released
        };
    };
};

struct uixCharToItemEventArgs : uixEventArgs
{
    uixCharToItemEventArgs(WPARAM w, LPARAM l)
        : uixEventArgs(w, l)
    {
        Char = (UINT)LOWORD(w);
        Index = (UINT)HIWORD(w);
        Sender = (HWND)l;
        Result = 0;
    }

    UINT    Char;                           //!< Character
    UINT    Index;                          //!< Item index
    HWND    Sender;                         //!< Sender window handle
    INT     Result;                         //!< Result code
};

struct uixCloseEventArgs : uixEventArgs
{
    uixCloseEventArgs(WPARAM w, LPARAM l)
        : uixEventArgs(w, l)
    {
    }
};

struct uixCommandEventArgs : uixEventArgs
{
    uixCommandEventArgs(WPARAM w, LPARAM l)
        : uixEventArgs(w, l)
    {
        NotifyCode = HIWORD(w);
        ID = LOWORD(w);
        Sender = (HWND)l;
    }

    HWND        Sender;                     //!< Sender window handle
    UINT        ID;                         //!< Command ID
    UINT        NotifyCode;                 //!< Notify code
};

struct uixCompactingEventArgs : uixEventArgs
{
    uixCompactingEventArgs(WPARAM w, LPARAM l)
        : uixEventArgs(w, l)
    {
        Percent = (WORD)w;
    }

    WORD    Percent;                        //!< Percentage of compacting process
};

struct uixCompareItemEventArgs : uixEventArgs
{
    uixCompareItemEventArgs(WPARAM w, LPARAM l)
        : uixEventArgs(w, l)
    {
        SenderID = (UINT)w;
        Params = (COMPAREITEMSTRUCT*)l;
        Result = 0;
    }

    UINT                SenderID;           //!< Sender control ID
    COMPAREITEMSTRUCT*  Params;             //!< Additional params
    INT                 Result;             //!< Result code
};

struct uixContextMenuEventArgs : uixEventArgs
{
    uixContextMenuEventArgs(WPARAM w, LPARAM l)
        : uixEventArgs(w, l)
    {
        Position.x = LOWORD(l);
        Position.y = HIWORD(l);

        Window = (HWND)w;
    }

    uixPoint    Position;                   //!< Context click mouse position
    HWND        Window;                     //!< Window handle
};

struct uixCopyDataEventArgs : uixEventArgs
{
    uixCopyDataEventArgs(WPARAM w, LPARAM l)
        : uixEventArgs(w, l)
    {
        Sender = (HWND)w;
        CopyData = (COPYDATASTRUCT*)l;
        Result = FALSE;
    }

    HWND                Sender;             //!< Sender handle
    COPYDATASTRUCT*     CopyData;           //!< Additional data
    BOOL                Result;             //!< Processed flag
};

struct uixCreateEventArgs : uixEventArgs
{
    uixCreateEventArgs(WPARAM w, LPARAM l)
        : uixEventArgs(w, l)
    {
        CreateParams = (CREATESTRUCT*)l;
        Result = 0;
    }

    CREATESTRUCT*   CreateParams;           //!< Additional params
    INT             Result;                 //!< Result code
};

struct uixDeleteItemEventArgs : uixEventArgs
{
    uixDeleteItemEventArgs(WPARAM w, LPARAM l)
        : uixEventArgs(w, l)
    {
        SenderID = (UINT)w;
        Params = (DELETEITEMSTRUCT*)l;
        Result = FALSE;
    }

    UINT                SenderID;           //!< Sender control ID
    DELETEITEMSTRUCT*   Params;             //!< Additional params
    BOOL                Result;             //!< Processed flag
};

struct uixDestroyEventArgs : uixEventArgs
{
    uixDestroyEventArgs(WPARAM w, LPARAM l)
        : uixEventArgs(w, l)
    {
    }
};

struct uixDeviceChangeEventArgs : uixEventArgs
{
    uixDeviceChangeEventArgs(WPARAM w, LPARAM l)
        : uixEventArgs(w, l)
    {
    }
};

struct uixDevModeChangeEventArgs : uixEventArgs
{
    uixDevModeChangeEventArgs(WPARAM w, LPARAM l)
        : uixEventArgs(w, l)
    {
        DeviceName = (const uixChar*)l;
    }

    const uixChar* DeviceName;                  //!< Device name
};

struct uixMouseEventArgs : uixEventArgs
{
    enum Key
    {
        Key_Left = MK_LBUTTON,
        Key_Right = MK_RBUTTON,
        Key_Shift = MK_SHIFT,
        Key_Control = MK_CONTROL,
        Key_Middle = MK_MBUTTON,
        Key_X1 = MK_XBUTTON1,
        Key_X2 = MK_XBUTTON2,
    };

    uixMouseEventArgs(WPARAM keys, LPARAM position, UINT clicks = 1)
        : uixEventArgs(0, 0)
    {
        Keys = GET_KEYSTATE_WPARAM(keys);
        Delta = GET_WHEEL_DELTA_WPARAM(keys);
        Position.x = GET_X_LPARAM(position);
        Position.y = GET_Y_LPARAM(position);
        Clicks = clicks;
    };

    BOOL IsKeyLeft() const
    {
        return (Keys & Key_Left) != 0;
    }

    BOOL IsKeyRight() const
    {
        return (Keys & Key_Right) != 0;
    }

    BOOL IsKeyShift() const
    {
        return (Keys & Key_Shift) != 0;
    }

    BOOL IsKeyCtrl() const
    {
        return (Keys & Key_Control) != 0;
    }

    BOOL IsKeyMiddle() const
    {
        return (Keys & Key_Middle) != 0;
    }

    BOOL IsKeyX1() const
    {
        return (Keys & Key_X1) != 0;
    }

    BOOL IsKeyX2() const
    {
        return (Keys & Key_X2) != 0;
    }

    UINT        Keys;                       //!< Mouse keys
    UINT        Clicks;                     //!< Amount of clicks
    INT         Delta;                      //!< Wheel delta
    uixPoint    Position;                   //!< Mouse position
};

struct uixNcMouseEventArgs : uixEventArgs
{
    uixNcMouseEventArgs(WPARAM w, LPARAM l)
        : uixEventArgs(w, l)
    {
        HitResult = (UINT)w;
        Position.x = GET_X_LPARAM(l);
        Position.y = GET_Y_LPARAM(l);
    }

    UINT        HitResult;                  //!< Hit result flags
    uixPoint    Position;                   //!< Position
};

struct uixMouseActivateEventArgs : uixEventArgs
{
    enum ResultValue
    {
        ResultValue_Activate = MA_ACTIVATE,
        ResultValue_ActivateDiscard = MA_ACTIVATEANDEAT,
        ResultValue_NoActivate = MA_NOACTIVATE,
        ResultValue_NoActivateDiscard = MA_NOACTIVATEANDEAT,
    };

    uixMouseActivateEventArgs(WPARAM w, LPARAM l)
        : uixEventArgs(w, l)
    {
        Sender = (HWND)w;
        HitResult = LOWORD(l);
        Message = HIWORD(l);
        Result = ResultValue_Activate;
    }

    HWND        Sender;                         //!< Sender window handle
    UINT        HitResult;                      //!< Hit result code
    UINT        Message;                        //!< Message
    UINT        Result;                         //!< Result
};

struct uixSizeEventArgs : uixEventArgs
{
    enum uixSizeType
    {
        uixSizeType_Maximized = SIZE_MAXIMIZED,
        uixSizeType_Minimized = SIZE_MINIMIZED,
        uixSizeType_Restored = SIZE_RESTORED,
        uixSizeType_MaxHide = SIZE_MAXHIDE,
        uixSizeType_MaxShow = SIZE_MAXSHOW,
    } ;

    UINT    Type;                               //!< Size type
    UINT    Width;                              //!< New width
    UINT    Height;                             //!< New height

    uixSizeEventArgs(WPARAM w, LPARAM l)
        : uixEventArgs(w, l)
    {
        Type = (UINT)w;
        Width = LOWORD(l);
        Height = HIWORD(l);
    }
};

struct uixEraseBackgroundEventArgs : uixEventArgs
{
    uixEraseBackgroundEventArgs(WPARAM w, LPARAM l)
        : uixEventArgs(w, l)
    {
        DC = (HDC)w;
        Result = TRUE;
    }

    HDC     DC;                                 //!< Device context
    BOOL    Result;                             //!< Result flag, false to suppress
};

struct uixPaintEventArgs : uixEventArgs
{
    uixPaintEventArgs(WPARAM w, LPARAM l)
        : uixEventArgs(w, l)
    {
        DC = (HDC)w;
    }

    HDC     DC;                                 //!< Device context
};

struct uixNotifyEventArgs : uixEventArgs
{
    uixNotifyEventArgs(WPARAM w, LPARAM l)
        : uixEventArgs(w, l)
    {
        Data = (NMHDR*)l;
        Result = 0;
    }

    NMHDR*      Data;                           //!< Notify header
    LRESULT     Result;                         //!< Result code
};

struct uixDisplayChangeEventArgs : uixEventArgs
{
    uixDisplayChangeEventArgs(WPARAM w, LPARAM l)
        : uixEventArgs(w, l)
    {
        Depth = (UINT)w;
        Width = (UINT)LOWORD(l);
        Height = (UINT)HIWORD(l);
    }

    UINT    Depth;                              //!< Display depth in bits
    UINT    Width;                              //!< Display width in px
    UINT    Height;                             //!< Display height in px
};

struct uixDrawItemEventArgs : uixEventArgs
{
    uixDrawItemEventArgs(WPARAM w, LPARAM l)
        : uixEventArgs(w, l)
    {
        SenderID = (UINT)w;
        Params = (DRAWITEMSTRUCT*)l;
        Result = FALSE;
    }

    UINT                SenderID;               //!< Sender control ID
    DRAWITEMSTRUCT*     Params;                 //!< Additional params
    BOOL                Result;                 //!< Result flag
};

struct uixDropFilesEventArgs : uixEventArgs
{
    uixDropFilesEventArgs(WPARAM w, LPARAM l)
        : uixEventArgs(w, l)
    {
        Data = (HDROP)w;
    }

    HDROP       Data;                           //!< Drag&drop data handle
};

struct uixTimerEventArgs : uixEventArgs
{
    uixTimerEventArgs(WPARAM w, LPARAM l)
        : uixEventArgs(w, l)
    {
        ID = (UINT_PTR)w;
        Callback = (TIMERPROC)l;
    }

    UINT_PTR    ID;                             //!< Timer ID
    TIMERPROC   Callback;                       //!< Timer callback procedure
};

struct uixEnableEventArgs : uixEventArgs
{
    uixEnableEventArgs(WPARAM w, LPARAM l)
        : uixEventArgs(w, l)
    {
        Enabled = (BOOL)w;
    }

    BOOL    Enabled;                            //!< Enabled status
};

struct uixEndSessionEventArgs : uixEventArgs
{
    enum
    {
        Reason_Shutdown = 0,
        Reason_CloseApp = ENDSESSION_CLOSEAPP,
        Reason_Critical = ENDSESSION_CRITICAL,
        Reason_LogOff = ENDSESSION_LOGOFF,
    };

    uixEndSessionEventArgs(WPARAM w, LPARAM l)
        : uixEventArgs(w, l)
    {
        Ending = (BOOL)w;
        Reason = (UINT)l;
    }

    BOOL    Ending;                             //!< Is ending
    UINT    Reason;                             //!< Reason
};

struct uixEnterIdleEventArgs : uixEventArgs
{
    uixEnterIdleEventArgs(WPARAM w, LPARAM l)
        : uixEventArgs(w, l)
    {
        Reason = (UINT)w;
        Sender = (HWND)l;
    }

    enum
    {
        Reason_DialogBox = MSGF_DIALOGBOX,
        Reason_Menu = MSGF_MAX,
    };

    UINT    Reason;                             //!< Reason
    HWND    Sender;                             //!< Sender
};

struct uixMenuLoopEventArgs : uixEventArgs
{
    uixMenuLoopEventArgs(WPARAM w, LPARAM l)
        : uixEventArgs(w, l)
    {
        PopupMenu = (BOOL)w;
    }

    BOOL    PopupMenu;                          //!< Is menu loop in popup menu
};

struct uixSizeConstraintsEventArgs : uixEventArgs
{
    uixSizeConstraintsEventArgs(WPARAM w, LPARAM l)
        : uixEventArgs(w, l)
    {
        Data = (MINMAXINFO*)l;
    }

    MINMAXINFO*     Data;                       //!< Min max info
};

struct uixHelpEventArgs : uixEventArgs
{
    uixHelpEventArgs(WPARAM w, LPARAM l)
        : uixEventArgs(w, l)
    {
        Data = (HELPINFO*)l;
        Result = FALSE;
    }

    HELPINFO*   Data;                           //!< Help data
    BOOL        Result;                         //!< Result code
};

struct uixMoveEventArgs : uixEventArgs
{
    uixMoveEventArgs(WPARAM w, LPARAM l)
        : uixEventArgs(w, l)
    {
        Position.x = GET_X_LPARAM(l);
        Position.y = GET_Y_LPARAM(l);
    }

    uixPoint    Position;                       //!< Mouse last position
};

struct uixBorderChangeEventArgs : uixEventArgs
{
    uixBorderChangeEventArgs(WPARAM w, LPARAM l)
        : uixEventArgs(w, l)
    {
        Side = (UINT)w;
        Rect = (uixRect*)l;
        Result = FALSE;
    }

    enum
    {
        Side_Bottom = WMSZ_BOTTOM,
        Side_BottoMLeft = WMSZ_BOTTOMLEFT,
        Side_BottomRight = WMSZ_BOTTOMRIGHT,
        Side_Left = WMSZ_LEFT,
        Side_Right = WMSZ_RIGHT,
        Side_Top = WMSZ_TOP,
        Side_TopLeft = WMSZ_TOPLEFT,
        Side_TopRight = WMSZ_TOPRIGHT,
    };

    UINT        Side;                               //!< Sizing side
    uixRect*    Rect;                               //!< Rectangle
    BOOL        Result;                             //!< Result state
};

struct uixHotKeyEventArgs : uixEventArgs
{
    uixHotKeyEventArgs(WPARAM w, LPARAM l)
        : uixEventArgs(w, l)
    {
        ID = (UINT)w;
        Modifier = (UINT)l;
    }

    enum
    {
        ID_SnapDesktop = IDHOT_SNAPDESKTOP,
        ID_SnapWindow = IDHOT_SNAPWINDOW,
    };

    enum
    {
        Modifier_Alt = MOD_ALT,
        Modifier_Ctrl = MOD_CONTROL,
        Modifier_Shift = MOD_SHIFT,
        Modifier_Super = MOD_WIN,
    };

    UINT    ID;                                     //!< ID
    UINT    Modifier;                               //!< Modifier flags
};

//! Scroll Codes
enum uixScrollCode
{
    uixScrollCode_LineIncrement = SB_LINEUP,
    uixScrollCode_LineDecrement = SB_LINEDOWN,
    uixScrollCode_PageIncrement = SB_PAGEUP,
    uixScrollCode_PageDecrement = SB_PAGEDOWN,
    uixScrollCode_ThumbPosition = SB_THUMBPOSITION,
    uixScrollCode_ThumbTrack = SB_THUMBTRACK,
    uixScrollCode_First = SB_TOP,
    uixScrollCode_Last = SB_BOTTOM,
    uixScrollCode_EndScroll = SB_ENDSCROLL,
};

//! @remarks
//!     This event handles:
//!     - WM_HSCROLL
//!     - WM_VSCROLL
struct uixScrollEventArgs : uixEventArgs
{
    //! Constructor
    //! @param[in] w
    //!     wparam
    //! @param[in] l
    //!     lparam
    uixScrollEventArgs(WPARAM w, LPARAM l)
        : uixEventArgs(w, l)
    {
        Code = (uixScrollCode)LOWORD(w);
        Position = (UINT)HIWORD(w);
        Sender = (HWND)l;
    }

    //! Scroll code
    uixScrollCode   Code;
    //! Scroll position
    UINT            Position;
    //! Message sender
    HWND            Sender;
};

//! @remarks
//!     This event handles:
//!     - WM_HSCROLLCLIPBOARD
//!     - WM_VSCROLLCLIPBOARD
struct uixScrollClipboardEventArgs : uixEventArgs
{
    //! Constructor
    //! @param[in] w
    //!     wparam
    //! @param[in] l
    //!     lparam
    uixScrollClipboardEventArgs(WPARAM w, LPARAM l)
        : uixEventArgs(w, l)
    {
        Code = (uixScrollCode)LOWORD(l);
        Position = (UINT)HIWORD(l);
        Sender = (HWND)w;
    }

    //! Scroll code
    uixScrollCode   Code;
    //! Scroll position
    UINT            Position;
    //! Message sender
    HWND            Sender;
};

struct uixInitDialogEventArgs : uixEventArgs
{
    uixInitDialogEventArgs(WPARAM w, LPARAM l)
        : uixEventArgs(w, l)
    {
        FocusTarget = (HWND)w;
        Data = (void*)l;
        Result = FALSE;
    }

    HWND    FocusTarget;                        //!< Focus target window handle
    void*   Data;                               //!< Additional data
    BOOL    Result;                             //!< Result code
};

struct uixInitMenuEventArgs : uixEventArgs
{
    uixInitMenuEventArgs(WPARAM w, LPARAM l)
        : uixEventArgs(w, l)
    {
        Menu = (HMENU)w;
    }

    HMENU   Menu;                               //!< Menu handle
};

struct uixInitMenuPopupEventArgs : uixEventArgs
{
    uixInitMenuPopupEventArgs(WPARAM w, LPARAM l)
        : uixEventArgs(w, l)
    {
        Menu = (HMENU)w;
        Index = (UINT)LOWORD(l);
        System = (BOOL)HIWORD(l);
    }

    HMENU   Menu;                               //!< Menu handle
    UINT    Index;                              //!< Item Index
    BOOL    System;                             //!< Is system menu
};

//! @note
//!     Handles
//!     - WM_UNINITMENUPOPUP
struct uixUnInitMenuPopupEventArgs : uixEventArgs
{
    uixUnInitMenuPopupEventArgs(WPARAM w, LPARAM l)
        : uixEventArgs(w, l)
    {
        Menu = (HMENU)w;
        Flags = (BOOL)HIWORD(l);
    }

    HMENU   Menu;                               //!< Menu handle
    UINT    Flags;                              //!< Flags
};

//! @note
//!     Handles
//!     - WM_UNDO
struct uixUndoEventArgs : uixEventArgs
{
    uixUndoEventArgs(WPARAM w, LPARAM l)
        : uixEventArgs(w, l)
    {
        Result = FALSE;
    }

    BOOL    Result;                             //!< Result state
};

struct uixUpdateUiState : uixEventArgs
{
    uixUpdateUiState(WPARAM w, LPARAM l)
        : uixEventArgs(w, l)
    {
        Action = LOWORD(w);
        Element = HIWORD(w);
    }

    enum
    {
        Action_Clear = UIS_CLEAR,
        Action_Initialize = UIS_INITIALIZE,
        Action_Set = UIS_SET,
    };

    enum
    {
        Element_Active = UISF_ACTIVE,
        Element_HideAccel = UISF_HIDEACCEL,
        Element_HideFocus = UISF_HIDEFOCUS,
    };

    UINT    Action;                             //!< Action ID
    UINT    Element;                            //!< Element ID
};

struct uixWindowPosChangeEventArgs : uixEventArgs
{
    uixWindowPosChangeEventArgs(WPARAM w, LPARAM l)
        : uixEventArgs(w, l)
    {
        Params = (WINDOWPOS*)l;
    }

    WINDOWPOS*  Params;                         //!< Window position
};

struct uixVKeyToItem : uixEventArgs
{
    uixVKeyToItem(WPARAM w, LPARAM l)
        : uixEventArgs(w, l)
    {
        Key = (UINT)LOWORD(w);
        Index = (UINT)HIWORD(w);
        Sender = (HWND)l;
        Result = 0;
    }

    UINT    Key;                                //!< Key pressed
    UINT    Index;                              //!< Item index
    HWND    Sender;                             //!< Sender window handle
    INT     Result;                             //!< Result code
};

//! @note
//!     This event may change
struct uixWtsSessionChangeEventArgs : uixEventArgs
{
    uixWtsSessionChangeEventArgs(WPARAM w, LPARAM l)
        : uixEventArgs(w, l)
    {
        Status = (UINT)w;
        ID = (UINT)l;
    }

    enum
    {
        Status_Console_Connect = WTS_CONSOLE_CONNECT,
        Status_Console_Disconnect = WTS_CONSOLE_DISCONNECT,
        Status_Remote_Connect = WTS_REMOTE_CONNECT,
        Status_Remote_Disconnect = WTS_REMOTE_DISCONNECT,
        Status_Session_LogOn = WTS_SESSION_LOGON,
        Status_Session_LogOff = WTS_SESSION_LOGOFF,
        Status_Session_Lock = WTS_SESSION_LOCK,
        Status_Session_RemoteControl = WTS_SESSION_REMOTE_CONTROL,
        //Status_Session_Create = WTS_SESSION_CREATE,
        //Status_Session_Terminate = WTS_SESSION_TERMINATE,
    };

    //! Status
    UINT    Status;

    //! Session ID
    UINT    ID;
};

struct uixStyleChangeEventArgs : uixEventArgs
{
    uixStyleChangeEventArgs(WPARAM w, LPARAM l)
        : uixEventArgs(w, l)
    {
        Type = (UINT)w;
        Style = (STYLESTRUCT*)l;
    }

    enum
    {
        Type_Style = GWL_STYLE,
        Type_ExStyle = GWL_EXSTYLE,
    };

    UINT            Type;                   //!< Style type
    STYLESTRUCT*    Style;                  //!< Style data
};

struct uixSpoolerStatusEventArgs : uixEventArgs
{
    uixSpoolerStatusEventArgs(WPARAM w, LPARAM l)
        : uixEventArgs(w, l)
    {
        Status = (UINT)w;
        Jobs = (UINT)LOWORD(l);
    }

    UINT    Status;                         //!< Spooler status
    UINT    Jobs;                           //!< Jobs count
};

struct uixSizeClipboardEventArgs : uixEventArgs
{
    uixSizeClipboardEventArgs(WPARAM w, LPARAM l)
        : uixEventArgs(w, l)
    {
        Sender = (HWND)w;
        Rect = (HGLOBAL)l;
    }

    HWND    Sender;                             //!< Sender window handle
    HGLOBAL Rect;                               //!< Pointer to rectangle
};

struct uixShowWindowEventArgs : uixEventArgs
{
    uixShowWindowEventArgs(WPARAM w, LPARAM l)
        : uixEventArgs(w, l)
    {
        Show = (BOOL)w;
        Status = (UINT)l;
    }

    enum
    {
        Status_UnZoom = SW_OTHERUNZOOM,
        Status_Zoom = SW_OTHERZOOM,
        Status_ParentClosing = SW_PARENTCLOSING,
        Status_ParentOpening = SW_PARENTOPENING,
    };

    BOOL    Show;                               //!< Show or hide
    UINT    Status;                             //!< Status
};

struct uixMeasureItemEventArgs : uixEventArgs
{
    uixMeasureItemEventArgs(WPARAM w, LPARAM l)
        : uixEventArgs(w, l)
    {
        ID = (UINT)w;
        Params = (MEASUREITEMSTRUCT*)l;
        Result = FALSE;
    }

    UINT                ID;                     //!< Item ID
    MEASUREITEMSTRUCT*  Params;                 //!< Params
    BOOL                Result;                 //!< Result state
};

struct uixFocusChangeEventArgs : uixEventArgs
{
    uixFocusChangeEventArgs(WPARAM w, LPARAM l)
        : uixEventArgs(w, l)
    {
        Handle = (HWND)w;
    }

    //! @note When: OnSetFocus - Previous window handle
    //! @note When: OnKillFocus - Next window handle
    HWND Handle;
};

struct uixSettingChangeEventArgs : uixEventArgs
{
    uixSettingChangeEventArgs(WPARAM w, LPARAM l)
        : uixEventArgs(w, l)
    {
        Flags = (UINT)w;
        Section = (const uixChar*)l;
    }

    UINT            Flags;                  //!< Flags
    const uixChar*  Section;                //!< Section in settings file
};

struct uixRenderFormatEventArgs : uixEventArgs
{
    uixRenderFormatEventArgs(WPARAM w, LPARAM l)
        : uixEventArgs(w, l)
    {
        Format = (UINT)w;
    }

    UINT    Format;                         //!< Render format ID
};

struct uixQuitEventArgs : uixEventArgs
{
    uixQuitEventArgs(WPARAM w, LPARAM l)
        : uixEventArgs(w, l)
    {
        ExitCode = (UINT)w;
    }

    UINT    ExitCode;                       //!< Exit code
};

struct uixQueryUiStateEventArgs : uixEventArgs
{
    uixQueryUiStateEventArgs(WPARAM w, LPARAM l)
        : uixEventArgs(w, l)
    {
        Result = 0;
    }

    //! See @see uixUpdateUiState::Element
    INT Result;                                 //!< Result value
};

struct uixNcCalcSizeEventArgs : uixEventArgs
{
    uixNcCalcSizeEventArgs(WPARAM w, LPARAM l)
        : uixEventArgs(w, l)
    {
        Result = 0;

        IsCalcSize = (BOOL)w;
        Rect = (RECT*)l;
    }

    union
    {
        NCCALCSIZE_PARAMS*  CalcSizeParams; //!< Params
        RECT*               Rect;           //!< Or rectangle
    };

    BOOL    IsCalcSize;                     //!< Calc size

    enum ResultFlags
    {
        ResultFlags_AlignTop = WVR_ALIGNTOP,
        ResultFlags_AlignRight = WVR_ALIGNRIGHT,
        ResultFlags_AlignLeft = WVR_ALIGNLEFT,
        ResultFlags_AlignBottom = WVR_ALIGNBOTTOM,
        ResultFlags_HRedraw = WVR_HREDRAW,
        ResultFlags_VRedraw = WVR_VREDRAW,
        ResultFlags_Redraw = WVR_REDRAW,
        ResultFlags_ValidRects = WVR_VALIDRECTS
    };

    UINT Result;                            //!< Result code
};

struct uixNcPaintEventArgs : uixEventArgs
{
    uixNcPaintEventArgs(WPARAM w, LPARAM l)
        : uixEventArgs(w, l)
    {
        Region = (HRGN)w;
    }

    HRGN    Region;                         //!< Non client region
};
}

//! Declares event map
#define uixDECLARE_EVENT_MAP() \
    public: \
    virtual BOOL OnWindowMessage(UINT message, WPARAM wParam, LPARAM lParam, LRESULT* result) override;

//! Begins event map
//! @param[in] Class
//!     Class
//! @param[in] Base
//!     Base class for Class
#define uixBEGIN_EVENT_MAP(Class, Base) \
    BOOL Class::OnWindowMessage(UINT message, WPARAM wParam, LPARAM lParam, LRESULT* result) { \
        typedef Class ThisClass; typedef Base BaseClass;

//! Ends event map
#define uixEND_EVENT_MAP() \
    return BaseClass::OnWindowMessage(message, wParam, lParam, result); \
    };
//----------------------------------------------------------------------------//
#endif /* _UIX_MESSAGEMAP_H__ */