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
#ifndef _UIX_WINDOW_H__
#define _UIX_WINDOW_H__
//----------------------------------------------------------------------------//
#include "uixobject.h"
#include "uixtypes.h"
#include "uixmessagemap.h"
//----------------------------------------------------------------------------//
namespace UIX
{
enum uixWindowRelativePos
{
    uixWindowRelativePos_Parent,
    uixWindowRelativePos_Desktop,
    uixWindowRelativePos_Monitor,
    uixWindowRelativePos_Default,
};

//! Scroll bar ID
enum uixScrollBarID
{
    //! Horizontal scrollbar
    uixScrollBarID_Horizontal = SB_HORZ,
    //! Vertical scrollbar
    uixScrollBarID_Vertical = SB_VERT,
    //! Control scrollbar
    uixScrollBarID_Control = SB_CTL,
    //! Both vertical and horizontal scrollbars
    uixScrollBarID_Both = SB_BOTH,
};

//! System command
enum uixSysCommand
{
    //! Close
    uixSysCommand_Close = SC_CLOSE,
    //! Context help
    uixSysCommand_ContextHelp = SC_CONTEXTHELP,
    //! Default
    uixSysCommand_Default = SC_DEFAULT,
    //! Hot key
    uixSysCommand_HotKey = SC_HOTKEY,
    //! Horizontal scroll
    uixSysCommand_HScroll = SC_HSCROLL,
    //! Is secure
    uixSysCommand_IsSecure = SCF_ISSECURE,
    //! Key menu
    uixSysCommand_KeyMenu = SC_KEYMENU,
    //! Maximize
    uixSysCommand_Maximize = SC_MAXIMIZE,
    //! Minimize
    uixSysCommand_Minimize = SC_MINIMIZE,
    //! Monitor power
    uixSysCommand_MonitorPower = SC_MONITORPOWER,
    //! Mouse menu
    uixSysCommand_MouseMenu = SC_MOUSEMENU,
    //! Move
    uixSysCommand_Move = SC_MOVE,
    //! Next window
    uixSysCommand_NextWindow = SC_NEXTWINDOW,
    //! Previous window
    uixSysCommand_PrevWindow = SC_PREVWINDOW,
    //! Restore
    uixSysCommand_Restore = SC_RESTORE,
    //! Screen save
    uixSysCommand_ScreenSave = SC_SCREENSAVE,
    //! Size
    uixSysCommand_Size = SC_SIZE,
    //! Task list
    uixSysCommand_TaskList = SC_TASKLIST,
    //! Vertical scroll
    uixSysCommand_VScroll = SC_VSCROLL,
};

//! Common Controls styles
enum uixControlStyle
{
    //! Control is adjustable
    uixControlStyle_Adjustable = CCS_ADJUSTABLE,
    //! Control is aligned bottom
    uixControlStyle_Bottom = CCS_BOTTOM,
    //! Control is aligned left
    uixControlStyle_Left = CCS_LEFT,
    //! Control has not top 2 px margin
    uixControlStyle_NoDivider = CCS_NODIVIDER,
    //! Control don't move itself horizontally
    uixControlStyle_NoMoveX = CCS_NOMOVEX,
    //! Control don't move itself vertically
    uixControlStyle_NoMoveY = CCS_NOMOVEY,
    //! Control isn't aligned to parent window
    uixControlStyle_NoParentAlign = CCS_NOPARENTALIGN,
    //! Control don't resize
    uixControlStyle_NoResize = CCS_NORESIZE,
    //! Control is aligned to right
    uixControlStyle_Right = CCS_RIGHT,
    //! Control is aligned to top
    uixControlStyle_Top = CCS_TOP,
    //! Control is aligned vertically
    uixControlStyle_Vertical = CCS_VERT,
};

//! Window styles
enum uixWindowStyle
{
    //! Window is overlapped
    uixWindowStyle_Overlapped = WS_OVERLAPPED,
    //! Popup window
    uixWindowStyle_Popup = WS_POPUP,
    //! Child window
    uixWindowStyle_Child = WS_CHILD,
    //! Minimized
    uixWindowStyle_Minimize = WS_MINIMIZE,
    //! Visible
    uixWindowStyle_Visible = WS_VISIBLE,
    //! Disabled
    uixWindowStyle_Disabled = WS_DISABLED,
    //! Clip siblings
    uixWindowStyle_ClipSiblings = WS_CLIPSIBLINGS,
    //! Clip children
    uixWindowStyle_ClipChildren = WS_CLIPCHILDREN,
    //! Maximized
    uixWindowStyle_Maximize = WS_MAXIMIZE,
    //! Caption
    uixWindowStyle_Caption = WS_CAPTION,
    //! Border
    uixWindowStyle_Border = WS_BORDER,
    //! Dialog frame
    uixWindowStyle_DialogFrame = WS_DLGFRAME,
    //! Vertical scroll
    uixWindowStyle_VScroll = WS_VSCROLL,
    //! Horizontal scroll
    uixWindowStyle_HScroll = WS_HSCROLL,
    //! System menu
    uixWindowStyle_SystemMenu = WS_SYSMENU,
    //! Thick frame
    uixWindowStyle_ThickFrame = WS_THICKFRAME,
    //! Starts group
    uixWindowStyle_Group = WS_GROUP,
    //! Tab stop
    uixWindowStyle_TabStop = WS_TABSTOP,
    //! Minimize box
    uixWindowStyle_MinimizeBox = WS_MINIMIZEBOX,
    //! Maximize box
    uixWindowStyle_MaximizeBox = WS_MAXIMIZEBOX,
    //! Overlapped window
    uixWindowStyle_OverlappedWindow = WS_OVERLAPPEDWINDOW,
    //! Popup window
    uixWindowStyle_PopupWindow = WS_POPUPWINDOW,
};

enum uixWindowStyleEx
{
    //! Dialog modal frame
    uixWindowStyleEx_DlgModalFrame = WS_EX_DLGMODALFRAME,
    //! No parent notify
    uixWindowStyleEx_NoParentNotify = WS_EX_NOPARENTNOTIFY,
    //! Top most window
    uixWindowStyleEx_TopMost = WS_EX_TOPMOST,
    //! Accept files
    uixWindowStyleEx_AcceptFiles = WS_EX_ACCEPTFILES,
    //! Transparent window
    uixWindowStyleEx_Transparent = WS_EX_TRANSPARENT,
    //! Mdi child
    uixWindowStyleEx_MdiChild = WS_EX_MDICHILD,
    //! Tool window
    uixWindowStyleEx_ToolWindow = WS_EX_TOOLWINDOW,
    //! Window edge
    uixWindowStyleEx_WindowEdge = WS_EX_WINDOWEDGE,
    //! Client edge
    uixWindowStyleEx_ClientEdge = WS_EX_CLIENTEDGE,
    //! Context help
    uixWindowStyleEx_ContextHelp = WS_EX_CONTEXTHELP,
    //! Right
    uixWindowStyleEx_Right = WS_EX_RIGHT,
    //! Left
    uixWindowStyleEx_Left = WS_EX_LEFT,
    //! LTR reading
    uixWindowStyleEx_LtrReading = WS_EX_LTRREADING,
    //! RTL reading
    uixWindowStyleEx_RtlReading = WS_EX_RTLREADING,
    //! Left Scrollbar
    uixWindowStyleEx_LeftScrollBar = WS_EX_LEFTSCROLLBAR,
    //! Right scrollbar
    uixWindowStyleEx_RightScrollBar = WS_EX_RIGHTSCROLLBAR,
    //! Control parent
    uixWindowStyleEx_ControlParent = WS_EX_CONTROLPARENT,
    //! Static edge
    uixWindowStyleEx_StaticEdge = WS_EX_STATICEDGE,
    //! Application window
    uixWindowStyleEx_AppWindow = WS_EX_APPWINDOW,
    //! Overlapped window
    uixWindowStyleEx_OverlappedWindow = WS_EX_OVERLAPPEDWINDOW,
    //! Palette window
    uixWindowStyleEx_PaletteWindow = WS_EX_PALETTEWINDOW,
    //! Layered window
    uixWindowStyleEx_Layered = WS_EX_LAYERED,
    //! No inherit layout
    uixWindowStyleEx_NoInheritLayout = WS_EX_NOINHERITLAYOUT,
    //! Layout RTL
    uixWindowStyleEx_LayoutRtl = WS_EX_LAYOUTRTL,
    //! Composited
    uixWindowStyleEx_Composited = WS_EX_COMPOSITED,
    //! No activate
    uixWindowStyleEx_NoActivate = WS_EX_NOACTIVATE,
};

enum enumUixLayeredWindowAttribute
{
    uixLayeredWindowAttribute_ColorKey = LWA_COLORKEY,
    uixLayeredWindowAttribute_Alpha = LWA_ALPHA,
};
typedef UINT uixLayeredWindowAttribute;

//! Window object
//! @brief
//!     This class allows you to implement new controls and subclass existing
//!     ones using set of implemented methods.
//! @note
//!     This class all
class UIXAPI uixWindow : public uixObject
{
    uixDECLARE_DYNAMIC_CLASS(uixWindow);
protected:
    HWND    m_Handle;       //< Window handle
    WNDPROC m_SuperWndProc; //< Window's super window procedure
public:
    //! Constructor
    uixWindow();

    //! Destructor
    virtual ~uixWindow();
public:
    //! Constructor
    //! @param[in] handle
    //!     Handle to set
    //! @note
    //!     Note that this constructor <b>don't</b> attach window proc to
    //!     window handle. It's may be used only to perform operations,
    //!     not to subclassing
    uixWindow(HWND handle);

    #pragma region Window Create and Destroy
public:
    //! Gets window attached to handle
    //! @param[in] handle
    //!     Window handle
    //! @return
    //!     Instance of window if attached, NULLPTR otherwise
    static uixWindow* FromHandle(HWND handle);

    //! Creates window
    //! @param[in] parent
    //!     Parent window object
    //! @param[in] text
    //!     Text
    //! @param[in] position
    //!     Window position
    //! @param[in] size
    //!     Window size
    //! @param[in] id
    //!     Window ID
    //! @param[in] style
    //!     Style flags
    //! @param[in] exStyle
    //!     Extended style
    //! @return
    //!     True when successful
    virtual BOOL Create(
        uixWindow* parent,
        const uixChar* text,
        const uixPoint& position,
        const uixSize& size,
        uixWindowID id = uixID_ANY,
        DWORD style = 0,
        DWORD exStyle = 0);

    //! Creates window
    //! @param[in] parent
    //!     Parent window object
    //! @param[in] position
    //!     Window position
    //! @param[in] size
    //!     Window size
    //! @param[in] id
    //!     Window ID
    //! @param[in] style
    //!     Style flags
    //! @param[in] exStyle
    //!     Extended style
    //! @return
    //!     True when successful
    virtual BOOL Create(
        uixWindow* parent,
        const uixPoint& position,
        const uixSize& size,
        uixWindowID id = uixID_ANY,
        DWORD style = 0,
        DWORD exStyle = 0);

    //! Creates window
    //! @param[in] parent
    //!     Parent window object
    //! @param[in] id
    //!     Window ID
    //! @param[in] style
    //!     Style flags
    //! @param[in] exStyle
    //!     Extended style
    //! @return
    //!     True when successful
    virtual BOOL Create(
        uixWindow* parent,
        uixWindowID id = uixID_ANY,
        DWORD style = 0,
        DWORD exStyle = 0);

    //! Creates window
    //! @param[in] text
    //!     Text
    //! @param[in] position
    //!     Window position
    //! @param[in] size
    //!     Window size
    //! @param[in] menu
    //!     Window menu handle
    //! @param[in] style
    //!     Style flags
    //! @param[in] exStyle
    //!     Extended style
    //! @return
    //!     True when successful
    virtual BOOL Create(
        const uixChar* text,
        const uixPoint& position,
        const uixSize& size,
        HMENU menu = 0,
        DWORD style = 0,
        DWORD exStyle = 0);

    //! Calls windows CreateWindowEx
    //! @param[in] styleEx
    //!     Extended style
    //! @param[in] className
    //!     Class name
    //! @param[in] windowName
    //!     Window name
    //! @param[in] style
    //!     Style
    //! @param[in] left
    //!     Left position
    //! @param[in] top
    //!     Top position
    //! @param[in] width
    //!     Window width
    //! @param[in] height
    //!     Window height
    //! @param[in] parent
    //!     Parent window handle
    //! @param[in] menu
    //!     Menu handle
    //! @param[in] param
    //!     Param pointer, unused
    //! @return
    //!     True when successful
    virtual BOOL CreateEx(
        DWORD styleEx,
        const uixChar* className,
        const uixChar* windowName,
        DWORD style,
        INT left,
        INT top,
        INT width,
        INT height,
        HWND parent,
        HMENU menu,
        void* param = NULLPTR);

    //! Destroy window
    //! @return
    //!     True when successful
    virtual BOOL DestroyWindow();

    //! Called before window create
    //! @param[in] cs
    //!     Create Struct
    //! @return
    //!     True when successful
    virtual BOOL BeforeWindowCreate(CREATESTRUCT& cs);

    //! Attach this instance of uixWindow to this handle
    //! @param[in] handle
    //!     Handle to attach
    //! @return
    //!     true when successful
    BOOL Attach(HWND handle);

    //! Detach handle from instance
    //! @return
    //!     Handle of attached window
    HWND Detach();

    //! Subclass window handle using this object
    //! @param[in] handle
    //!     Handle of window to subclass
    //! @return
    //!     true when successful
    BOOL Subclass(HWND handle);

    //! Unsubclass window
    //! @return
    //!     Handle of subclassed window
    HWND Unsubclass();

    //! Checks if window is created
    //! @return
    //!     True when created
    BOOL IsCreated() const;

#if defined UIX_DEBUG

    //! @copydoc uixObject::ValidateObject
    virtual void ValidateObject() const;

    //! @copydoc uixObject::DumpObject
    virtual void DumpObject(uixDumpContext& ctx) const;
#endif

    #pragma endregion

    #pragma region Window Tree
public:
    //! Gets window handle
    //! @note
    //!     This method will fail, if this == NULLPTR
    //! @return
    //!     Window handle
    HWND GetHandle() const;

    //! Gets window handle
    //! @note
    //!     This method returns NULLPTR when window isn't created or this == NULLPTR
    HWND GetHandleSafe() const;

    //! Sets parent window handle
    //! @param[in] newParent
    //!     New parent window handle
    //! @return
    //!     Previous parent window handle
    HWND SetParent(HWND newParent);

    //! Gets parent window handle
    //! @return
    //!     Parent window handle
    HWND GetParent() const;

    //! Gets window ID
    //! @return
    //!     Window ID
    uixWindowID GetID() const;

    //! Sets window ID
    //! @param[in] id
    //!     New ID
    //! @return
    //!     Previous ID
    uixWindowID SetID(uixWindowID id);

    //! Gets ancestor window
    //! @param[in] flags
    //!     - GA_PARENT - gets parent window
    //!     - GA_ROOT - gets root
    //!     - GA_ROOTOWNER - gets root owner
    //! @return
    //!     Handle to proper ancestor
    HWND GetAncestor(UINT flags) const;

    //! Gets active window handle
    //! @return
    //!     Active window handle
    static HWND GetActiveWindow();

    //! Sets active window handle
    //! @param[in] handle
    //!     Window handle to activate
    //! @return
    //!     Handle to previous active window
    static HWND SetActiveWindow(HWND handle);

    //! Sets to active window
    //! @return
    //!     Handle to previous active window
    HWND SetActiveWindow();

    //! Gets foreground window
    //! @return
    //!     Handle to foreground window
    static HWND GetForegroundWindow();

    //! Sets foreground window
    //! @param[in] handle
    //!     Window handle to be foreground window
    //! @return
    //!     True when successful
    static BOOL SetForegroundWindow(HWND handle);

    //! Sets foreground window
    //! @remarks
    //!     Makes this window foreground window
    //! @return
    //!     True when sucessful
    BOOL SetForegroundWindow();

    //! Gets currently captured window
    //! @return
    //!     Handle to captured window
    static HWND GetCapture();

    //! Sets currently captured window
    //! @param[in] handle
    //!     Handle to window to capture
    //! @return
    //!     Handle to previously captured window
    static HWND SetCapture(HWND handle);

    //! Sets currently captured window
    //! @remarks
    //!     Makes this window captured
    //! @return
    //!     Handle to previously captured window
    HWND SetCapture();

    //! Releases capture
    //! @return
    //!
    static BOOL ReleaseCapture();

    //! Gets focused window handle
    //! @return
    //!     Handle to focused window
    static HWND GetFocus();

    //! Sets focused window
    //! @param[in] handle
    //!     Handle to focused window
    //! @return
    //!     Handle to previously focused window
    static HWND SetFocus(HWND handle);

    //! Sets focused window
    //! @brief
    //!     Makes this window focused
    //! @return
    //!     Handle to previously focused window
    HWND SetFocus();

    //! Gets desktop window
    //! @return
    //!     Handle to desktop window
    static HWND GetDesktopWindow();

    //! Gets child window from point
    //! @param[in] point
    //!     Child window hit test point
    //! @return
    //!     Handle to child window
    HWND ChildWindowFromPoint(POINT point) const;

    //! Gets child window from point
    //! @param[in] point
    //!     Child window hit test point
    //! @param[in] flags
    //!     - CWP_ALL - retrieve all windows
    //!     - CWP_SKIPDISABLED - skips disabled windows
    //!     - CWP_SKIPINVISIBLE - skips invisible windows
    //!     - CWP_SKIPTRANSPARENT - skips transparent windows
    //! @return
    //!     Handle to child window
    HWND ChildWindowFromPoint(POINT point, UINT flags) const;

    //! Finds window
    //! @param[in] className
    //!     Window class name
    //! @param[in] windowName
    //!     Window name
    //! @return
    //!     Handle to window
    static HWND FindWindow(const uixChar* className, const uixChar* windowName);

    //! Finds window
    //! @param[in] parent
    //!     Window root
    //! @param[in] after
    //!     Handle to first search window
    //! @param[in] className
    //!     Window class name
    //! @param[in] windowName
    //!     Window name
    //! @return
    //!     Handle to window
    static HWND FindWindow(HWND parent, HWND after, const uixChar* className,
                           const uixChar* windowName);

    //! Gets next window handle in windows tree
    //! @return
    //!     Next window at tree level
    HWND GetNext() const;

    //! Gets previous window handle in windows tree
    //! @return
    //!     Previous window at tree level
    HWND GetPrev() const;

    //! Gets first window handle in windows tree
    //! @return
    //!     First window at tree level
    HWND GetFirst() const;

    //! Gets last window handle in windows tree
    //! @return
    //!     Last window at tree level
    HWND GetLast() const;

    //! Gets window owner
    //! @return
    //!     Handle to owner window
    HWND GetOwner() const;

    //! Gets window child
    //! @return
    //!     Handle to first child window
    //! @remarks
    //!     Use GetNext, GetPrev, GetFist, GetLast to traverse trough window tree
    HWND GetChild() const;

    //! Gets popup enabled window handle
    //! @return
    //!     Handle to popup window
    HWND GetEnabledPopup() const;

    //! Gets top window
    //! @return
    //!     Handle to top window
    HWND GetTopWindow() const;

    //! Gets window by command
    //! @param[in] cmd
    //!     - GW_CHILD - child window
    //!     - GW_ENABELDPOPUP - enabled popup
    //!     - GW_HWNDFIRST - first window
    //!     - GW_HWNDLAST - last window
    //!     - GW_HWNDNEXT - next window
    //!     - GW_HWNDPREV - previous window
    //!     - GW_OWNER - owner window
    //! @return
    //!     Window handle
    HWND GetWindow(UINT cmd) const;

    //! Gets last active popup window
    //! @return
    //!     Handle to popup window
    HWND GetLastActivePopup() const;

    //! Checks if window is child of this window
    //! @param[in] child
    //!     Child window
    //! @return
    //!     True when successful
    BOOL IsChild(HWND child) const;

    //! Gets window from point
    //! @param[in] point
    //!     Point
    //! @return
    //!     Window handle at point
    static HWND WindowFromPoint(POINT point);

    //! Flash window
    //! @param[in] invert
    //!     Invert flag
    //! @return
    //!     True when successful
    BOOL FlashWindow(BOOL invert);

    //! Flash window
    //! @param[in] flags
    //!     - FLASHW_ALL - caption & tray
    //!     - FLASHW_CAPTION - caption
    //!     - FLASHW_STOP - stop flashing
    //!     - FLASHW_TIMER - use timer
    //!     - FLASHW_TIMERNOFG - flash until window comes foreground
    //!     - FLASHW_TRAY - flash taskbar button
    //! @param[in] count
    //!     Number of flashes
    //! @param[in] timeout
    //!     Timeout in ms
    //! @return
    //!     True when sucecssful
    BOOL FlashWindow(DWORD flags, UINT count, DWORD timeout);

    //! Gets control by ID
    //! @param[in] id
    //!     Control ID
    //! @return
    //!     Control handle
    HWND GetChildByID(uixWindowID id)
    {
        uixASSERT(this != NULLPTR);
        uixASSERT(::IsWindow(m_Handle));

        return ::GetDlgItem(GetHandle(), (INT)id);
    }
    #pragma endregion

    #pragma region Scrolling

    //! Gets scroll position
    //! @param[in] barID
    //!     Bar ID
    //! @return
    //!     Scroll position
    INT GetScrollPosition(uixScrollBarID barID) const;

    //! Gets scroll range
    //! @param[in] barID
    //!     Bar ID
    //! @param[out] min
    //!     Min range
    //! @param[out] max
    //!     Max range
    //! @return
    //!     True when successful
    BOOL GetScrollRange(uixScrollBarID barID, INT& min, INT& max) const;

    //! Scrolls window
    //! @param[in] dx
    //!     Delta X
    //! @param[in] dy
    //!     Delta y
    //! @param[in] rect
    //!     Rect
    //! @param[in] clip
    //!     Clip rect
    //! @return
    //!     True when successful
    BOOL ScrollWindow(INT dx, INT dy, const RECT* rect = NULLPTR, const RECT* clip = NULLPTR);

    //! Sets scroll position
    //! @param[in] barID
    //!     Bar ID
    //! @param[in] position
    //!     Position
    //! @param[in] redraw
    //!     Redraw flag
    //! @return
    //!     Previous position
    INT SetScrollPosition(uixScrollBarID barID, INT position, BOOL redraw = TRUE);

    //! Sets scroll range
    //! @param[in] barID
    //!     Bar ID
    //! @param[in] min
    //!     Min range
    //! @param[in] max
    //!     Max range
    //! @param[in] redraw
    //!     Redraw flag
    //! @return
    //!     True when successful
    BOOL SetScrollRange(uixScrollBarID barID, INT min, INT max, BOOL redraw = TRUE);

    //! Shows scroll bar
    //! @param[in] barID
    //!     Bar ID
    //! @param[in] show
    //!     Show flag
    //! @return
    //!     True when sucessful
    BOOL ShowScrollBar(uixScrollBarID barID, BOOL show = TRUE);

    //! Scrolls window
    //! @param[in] dx
    //!     Delta X
    //! @param[in] dy
    //!     Delta y
    //! @param[in] scroll
    //!     Scroll rect
    //! @param[in] clip
    //!     Clip rect
    //! @param[in] updateRegion
    //!     Update region
    //! @param[in] update
    //!     Update rect
    //! @param[in] flags
    //!     Flags
    //! @return
    //!     ??
    //! @todo Describe flags and result value
    INT ScrollWindow(INT dx, INT dy, const RECT* scroll, const RECT* clip, HRGN updateRegion,
                     RECT* update, UINT flags);

    //! Sets scroll info
    //! @param[in] barID
    //!     Bar ID
    //! @param[in] info
    //!     Scroll info
    //! @param[in] redraw
    //!     Redraw flag
    //! @return
    //!     True when successful
    BOOL SetScrollInfo(uixScrollBarID barID, const SCROLLINFO& info, BOOL redraw = TRUE);

    //! Gets scroll info
    //! @param[in] barID
    //!     Bar ID
    //! @param[out] info
    //!     Scroll info
    //! @return
    //!     True when successful
    BOOL GetScrollInfo(uixScrollBarID barID, SCROLLINFO& info) const;

    //! Gets scrollbar info
    //! @param[in] objectID
    //!     ID of object
    //! @param[out] info
    //!     Scroll bar info
    //! @return
    //!     True when successful
    BOOL GetScrollBarInfo(LONG objectID, SCROLLBARINFO& info) const;
    #pragma endregion

    #pragma region Dialog Box methods
    /*
    Note that not all dialog box methods are need in uixDialog class only! Some of them use
    dialog resource, but not necessarily them must be dialog boxes
    */
    #pragma endregion

    #pragma region Style Manipulation
public:

    //! Gets window style
    //! @return
    //!     Style
    DWORD GetStyle() const;

    //! Gets window extended style
    //! @return
    //!     Extended style
    DWORD GetStyleEx() const;

    //! Sets window style
    //! @param[in] style
    //!     New style
    //! @return
    //!     Previous style
    DWORD SetStyle(DWORD style);

    //! Sets window extended style
    //! @param[in] style
    //!     New extended style
    //! @return
    //!     Previous extended style
    DWORD SetStyleEx(DWORD style);

    //! Updates style
    //! @param[in] remove
    //!     Styles to remove
    //! @param[in] add
    //!     Styles to add
    //! @param[in] flags
    //!     Update flags
    //! @return
    //!     True when successful
    BOOL UpdateStyle(DWORD remove, DWORD add, UINT flags = 0);

    //! Updates extended style
    //! @param[in] remove
    //!     Styles to remove
    //! @param[in] add
    //!     Styles to add
    //! @param[in] flags
    //!     Update flags
    //! @return
    //!     True when successful
    BOOL UpdateStyleEx(DWORD remove, DWORD add, UINT flags = 0);

    //! Enables scroll bar
    //! @param[in] flags
    //! @todo describe flags
    //! @param[in] arrows
    //! @todo arrows flags
    //! @return
    //!     True when successful
    BOOL EnableScrollBar(UINT flags, UINT arrows = ESB_ENABLE_BOTH);
    #pragma endregion

    #pragma region Window State
public:

    //! Checks if window is enabled
    //! @return
    //!     True when enabled
    BOOL IsWindowEnabled() const;

    //! Enables window
    //! @param[in] value
    //!     Enable flag
    //! @return
    //!     True when successful
    BOOL EnableWindow(BOOL value = TRUE);

    //! Shows window
    //! @param[in] command
    //!     Show command
    //! @return
    //!     True when successful
    BOOL Show(UINT command = SW_SHOWNORMAL);

    //! Update window
    //! @return
    //!     True when successful
    BOOL Update();

    //! Checks if window is visible
    //! @return
    //!     True when visible
    BOOL IsVisible() const;

    //! Gets window info
    //! @param[out] info
    //!     Window info
    //! @return
    //!     True when successful
    BOOL GetWindowInfo(WINDOWINFO& info) const;

    //! Gets title bar info
    //! @param[out] info
    //!     Title bar info
    //! @return
    //!     True when successful
    BOOL GetTitleBarInfo(TITLEBARINFO& info) const;

    //! Gets window menu handle
    //! @return
    //!     Menu handle
    HMENU GetMenu() const;

    //! @todo Document this
    BOOL Close();

    //! Sets window menu handle
    //! @param[in] menu
    //!     Menu handle
    //! @return
    //!     True when successful
    BOOL SetMenu(HMENU menu);

    //! Draws menu bar
    void DrawMenuBar();

    //! Gets system menu
    //! @param[in] revert
    //!     Set true to revert original menu
    //! @return
    //!     System menu handle
    HMENU GetSystemMenu(BOOL revert = FALSE) const;

    //! Checks if window is iconic
    //! @return
    //!     True when window is iconic
    BOOL IsIconic() const;

    //! Checks if window is zoomed
    //! @return
    //!     True when window is zoomed
    BOOL IsZoomed() const;

    //! Arrange iconic windows
    //! @return
    //!     Flags
    UINT ArrangeIconicWindows();

    //! Bring window to top
    BOOL BringToTop();

    //! Locks window update
    //! @return
    //!     True when successful
    BOOL LockWindowUpdate();

    //! Unlocks window update
    //! @return
    //!     True when successful
    BOOL UnlockWindowUpdate();

    //! Sets timer
    //! @param[in] eventID
    //!     Event ID
    //! @param[in] interval
    //!     Interval, in milliseconds
    //! @param[in] proc
    //!     Timer procedure
    //! @return
    //!     Timer ID
    UINT_PTR SetTimer(UINT_PTR eventID, UINT interval, TIMERPROC proc = NULLPTR);

    //! Kills timer
    //! @param[in] eventID
    //!     ID of timer to kill
    //! @return
    //!     True when successful
    BOOL KillTimer(UINT_PTR eventID);

    //! Sets icon
    //! @param[in] icon
    //!     Icon handle
    //! @param[in] bigIcon
    //!     True to big icon, false to small
    //! @return
    //!     Handle to previuos icon
    HICON SetIcon(HICON icon, BOOL bigIcon);

    //! Gets icon
    //! @param[in] bigIcon
    //!     True to big icon, false to small
    //! @return
    //!     Handle to previuos icon
    HICON GetIcon(BOOL bigIcon) const;

    //! Sets window context help ID
    //! @param[in] helpID
    //!     Context help ID
    //! @return
    //!     True when successful
    //! @todo
    //!     New Type: uixContextHelpID
    BOOL SetWindowContextHelpId(DWORD helpID);

    //! Gets window context help ID
    //! @return
    //!     Context help ID
    DWORD GetWindowContextHelpId() const;

    //! Updates window layout
    virtual BOOL UpdateLayout()
    {
        return TRUE;
    }
    #pragma endregion

    #pragma region Object Comparison
public:
    //! Compare two objects
    //! @param[in] window
    //!     Window to compare
    //! @return
    //!     True when objects are equals
    BOOL Equals(const uixWindow& window) const;

    //! Equality operator
    //! @param[in] window
    //!     Window
    //! @return
    //!     True when equals
    BOOL operator == (const uixWindow& window) const;

    //! Inequality operator
    //! @param[in] window
    //!     Window
    //! @return
    //!     True when not equals
    BOOL operator != (const uixWindow& window) const;
    #pragma endregion

    #pragma region Painting

    //! Invalidate rectangle
    //! @param[in] rect
    //!     Rect to invalidate
    //! @param[in] erase
    //!     True to erase
    //! @return
    //!     True when successful
    BOOL InvalidateRect(const uixRect& rect, BOOL erase = FALSE);

    //! Invalidate whole window
    //! @param[in] erase
    //!     True to erase
    //! @return
    //!     True when successful
    BOOL Invalidate(BOOL erase = FALSE);

    //! Invalidate region
    //! @param[in] region
    //!     Region to invalidate
    //! @param[in] erase
    //!     True to erase
    //! @return
    //!     True when successful
    BOOL InvalidateRgn(HRGN region, BOOL erase = TRUE);

    //! Validate rect
    //! @param[in] rect
    //!     Rect to validate
    //! @return
    //!     True when sucessful
    BOOL ValidateRect(const RECT& rect);

    //! Validate region
    //! @param[in] region
    //!     Region to validate
    //! @return
    //!     True when successful
    BOOL ValidateRgn(HRGN region);

    //! Begins painting process
    //! @param[out] ps
    //!     Paint data
    //! @return
    //!     DC to window
    HDC BeginPaint(PAINTSTRUCT& ps);

    //! Ends painting process
    //! @param[in] ps
    //!     Paint data
    //! @return
    //!     True when successful
    BOOL EndPaint(const PAINTSTRUCT& ps);

    //! Gets client area Device Context
    //! @return
    //!     Client area DC
    HDC GetDC() const;

    //! Gets window area Device Context
    //! @return
    //!     Window area DC
    HDC GetWindowDC() const;

    //! Releases acquired DC
    //! @param[in] dc
    //!     DC to release
    //! @return
    //!     Operation result
    INT ReleaseDC(HDC dc);

    //! Sets redraw flag
    //! @param[in] redraw
    //!     Redraw flag
    void SetRedraw(BOOL redraw = TRUE);

    //! Gets update rect
    //! @param[out] rect
    //!     Rect with update area
    //! @param[in] erase
    //!     True to erase
    //! @return
    //!     True when successful
    BOOL GetUpdateRect(RECT& rect, BOOL erase = TRUE) const;

    //! Gets update region
    //! @param[out] region
    //!     Region with udpate area
    //! @param[in] erase
    //!     True to erase
    //! @return
    //!     True when successful
    INT GetUpdateRgn(HRGN region, BOOL erase = TRUE) const;

    //! Redraws window
    //! @param[in] update
    //!     Update rect
    //! @param[in] region
    //!     Region
    //! @param[in] flags
    //!     - RDW_INVALIDATE
    //!     - RDW_INTERNALPAINT
    //!     - RDW_ERASE
    //!     - RDW_VALIDATE
    //!     - RDW_NOINTERNALPAINT
    //!     - RDW_NOERASE
    //!     - RDW_NOCHILDREN
    //!     - RDW_ALLCHILDREN
    //!     - RDW_UPDATENOW
    //!     - RDW_ERASENOW
    //!     - RDW_FRAME
    //!     - RDW_NOFRAME
    //! @return
    //!     True when sucessful
    BOOL RedrawWindow(
        const RECT* update = NULLPTR,
        HRGN region = 0,
        UINT flags = RDW_INVALIDATE | RDW_UPDATENOW | RDW_ERASE);

    //! Draws animated rectangles
    //! @param[in] animation
    //!     Type of animation, must be IDANI_CAPTION
    //! @param[in] from
    //!     Starting rectangle
    //! @param[in] to
    //!     Ending rectangle
    //! @return
    //!     True when successful
    BOOL DrawAnimatedRects(INT animation, const RECT& from, const RECT& to);

    //! Draws caption
    //! @param[in] dc
    //!     DC to draw
    //! @param[in] rect
    //!     Rect area
    //! @param[in] flags
    //!     Flags
    //! @return
    //!     True when successful
    BOOL DrawCaption(HDC dc, const RECT& rect, UINT flags);

    //! Animates window
    //! @param[in] time
    //!     Time of animation
    //! @param[in] flags
    //!     @todo Flags
    //! @return
    //!     True when sucessful
    BOOL AnimateWindow(DWORD time, DWORD flags);

    //! Prints window
    //! @param[in] dc
    //!     Target DC
    //! @param[in] flags
    //!     @todo Flags
    //! @return
    //!     True when successful
    BOOL PrintWindow(HDC dc, UINT flags);

    //! @todo Document this
    BOOL SetLayeredAttributes(uixColor colorkey, BYTE alpha, uixLayeredWindowAttribute flags);
    #pragma endregion

    #pragma region Message Manipulation
public:
    //! Checks if message is dialog message
    //! @param[in] m
    //!     Message
    //! @return
    //!     True when successful
    BOOL IsDialogMessage(MSG* m);

    //! Sends message to window
    //! @param[in] message
    //!     Message
    //! @param[in] wParam
    //!     wparam
    //! @param[in] lParam
    //!     lparam
    //! @return
    //!     Message result value
    LRESULT SendMessage(UINT message, WPARAM wParam, LPARAM lParam) const;

    //! Posts message to message queue
    //! @param[in] message
    //!     Message
    //! @param[in] wParam
    //!     wparam
    //! @param[in] lParam
    //!     lparam
    //! @return
    //!     True when successful
    BOOL PostMessage(UINT message, WPARAM wParam, LPARAM lParam) const;
    #pragma endregion

    #pragma region Window Text
public:
    //! Sets window text
    //! @param[in] text
    //!     Text
    void SetText(const uixChar* text);

    //! Sets window text
    //! @param[in] text
    //!     Text
    void SetText(const uixString& text);

    //! Gets window text
    //! @param[in] text
    //!     Text
    //! @param[in] maxLength
    //!     Max length
    //! @return
    //!     Length of text
    INT GetText(uixChar* text, INT maxLength) const;

    //! Gets window text
    //! @param[in] text
    //!     Text
    //! @param[in] maxLength
    //!     Max length
    //! @return
    //!     Length of text
    INT GetText(uixString& text, INT maxLength) const;

    //! Gets window text
    //! @param[in] text
    //!     Text
    //! @return
    //!     Length of text
    INT GetText(uixString& text) const;

    //! Gets window text length
    //! @return
    //!     Length of text
    INT GetTextLength() const;
    #pragma endregion

    #pragma region Size and position management
public:
    //! Gets window rect area
    //! @param[out] rect
    //!     Window area
    //! @return
    //!     True when successful
    BOOL GetWindowRect(RECT& rect) const;

    //! Gets client rect area
    //! @param[out] rect
    //!     Client area
    //! @return
    //!     True when successful
    BOOL GetClientRect(RECT& rect) const;

    //! @todo Document this
    BOOL SetWindowRect(const RECT& rect);

    //! @todo Document this
    BOOL SetClientSize(const SIZE& size);

    //! @todo Document this
    BOOL SetClientSize(UINT width, UINT height);

    //! Centers window
    //! @return
    //!     True when successful
    BOOL CenterWindow();

    //! @todo document this
    BOOL CenterWindow(uixWindowRelativePos relative);

    //! Sets window position
    //! @param[in] x
    //!     Left position
    //! @param[in] y
    //!     Top positon
    //! @param[in] width
    //!     Width
    //! @param[in] height
    //!     Height
    //! @param[in] flags
    //!     @todo flags
    //! @return
    //!     True when successful
    BOOL SetWindowPos(INT x, INT y, INT width, INT height, UINT flags = SWP_NOZORDER);

    //! Sets window position
    //! @param[in] position
    //!     Position
    //! @param[in] size
    //!     Size
    //! @param[in] flags
    //!     @todo flags
    //! @return
    //!     True when successful
    BOOL SetWindowPos(const uixPoint& position, const uixSize& size, UINT flags = SWP_NOZORDER);

    //! Sets window position
    //! @param[in] rect
    //!     Window rect
    //! @param[in] flags
    //!     @todo flags
    //! @return
    //!     True when successful
    BOOL SetWindowPos(const uixRect& rect, UINT flags = SWP_NOZORDER);

    //! Sets window position
    //! @param[in] insertAfter
    //!     Handle to window
    //! @param[in] x
    //!     Left position
    //! @param[in] y
    //!     Top positon
    //! @param[in] width
    //!     Width
    //! @param[in] height
    //!     Height
    //! @param[in] flags
    //!     @todo flags
    //! @return
    //!     True when successful
    BOOL SetWindowPosZ(HWND insertAfter, INT x, INT y, INT width, INT height,
                       UINT flags = SWP_NOZORDER);

    //! Sets window position
    //! @param[in] insertAfter
    //!     Handle to window
    //! @param[in] position
    //!     Position
    //! @param[in] size
    //!     Size
    //! @param[in] flags
    //!     @todo flags
    //! @return
    //!     True when successful
    BOOL SetWindowPosZ(HWND insertAfter, const uixPoint& position, const uixSize& size,
                       UINT flags = SWP_NOZORDER);

    //! Sets window position
    //! @param[in] insertAfter
    //!     Handle to window
    //! @param[in] rect
    //!     Window rect
    //! @param[in] flags
    //!     @todo flags
    //! @return
    //!     True when successful
    BOOL SetWindowPosZ(HWND insertAfter, const uixRect& rect, UINT flags = SWP_NOZORDER);

    //! Maps screen point to client
    //! @param[in] point
    //!     Point
    //! @return
    //!     True when successful
    BOOL ScreenToClient(POINT& point) const;

    //! Maps screen rect to client
    //! @param[in] rect
    //!     Rect
    //! @return
    //!     True when successful
    BOOL ScreenToClient(RECT& rect) const;

    //! Maps client point to screen
    //! @param[in] point
    //!     Point
    //! @return
    //!     True when successful
    BOOL ClientToScreen(POINT& point) const;

    //! Maps client rect to screen
    //! @param[in] rect
    //!     Rect
    //! @return
    //!     True when successful
    BOOL ClientToScreen(RECT& rect) const;

    //! Maps points to another window
    //! @param[in] target
    //!     Target window handle
    //! @param[in] points
    //!     Array of points
    //! @param[in] count
    //!     Number of elements in points array
    //! @return
    //!     Number of converted points
    INT MapPoints(HWND target, POINT points[], UINT count) const;

    //! Maps points to another window
    //! @param[in] target
    //!     Target window handle
    //! @param[in] points
    //!     Array of points
    //! @param[in] count
    //!     Number of elements in points array
    //! @return
    //!     Number of converted points
    INT MapPoints(HWND target, uixPoint points[], UINT count) const;

    //! Maps rects to another window
    //! @param[in] target
    //!     Target window handle
    //! @param[in] rects
    //!     Array of rects
    //! @param[in] count
    //!     Number of elements in rects array
    //! @return
    //!     Number of converted rects
    INT MapPoints(HWND target, RECT rects[], UINT count) const;

    //! Maps rects to another window
    //! @param[in] target
    //!     Target window handle
    //! @param[in] rects
    //!     Array of rects
    //! @param[in] count
    //!     Number of elements in rects array
    //! @return
    //!     Number of converted rects
    INT MapPoints(HWND target, uixRect rects[], UINT count) const;

    //! Moves window
    //! @param[in] left
    //!     Left position
    //! @param[in] top
    //!     Top position
    //! @param[in] width
    //!     Width
    //! @param[in] height
    //!     Height
    //! @param[in] repaint
    //!     True to repaint window
    //! @return
    //!     True when successful
    BOOL MoveWindow(INT left, INT top, INT width, INT height, BOOL repaint = TRUE);

    //! Moves window
    //! @param[in] position
    //!     Position
    //! @param[in] size
    //!     Window size
    //! @param[in] repaint
    //!     True to repaint window
    //! @return
    //!     True when successful
    BOOL MoveWindow(const POINT& position, const SIZE& size, BOOL repaint = TRUE);

    //! Moves window
    //! @param[in] rect
    //!     Rect of window
    //! @param[in] repaint
    //!     True to repaint window
    //! @return
    //!     True when successful
    BOOL MoveWindow(const RECT& rect, BOOL repaint = TRUE);

    //! Gets window placement
    //! @param[out] params
    //!     Window placement
    //! @return
    //!     True when succecssful
    BOOL GetWindowPlacement(WINDOWPLACEMENT& params) const;

    //! Sets window placement
    //! @param[in] params
    //!     Window placement
    //! @return
    //!     True when successful
    BOOL SetWindowPlacement(const WINDOWPLACEMENT& params);

    //! Sets window region
    //! @param[in] region
    //!     New window region
    //! @param[in] redraw
    //!     True to redraw
    //! @return
    //!     @todo check
    INT SetWindowRgn(HRGN region, BOOL redraw = TRUE);

    //! Gets window region
    //! @param[out] region
    //!     Window region
    //! @return
    //!     @todo check
    INT GetWindowRgn(HRGN region) const;

    #pragma endregion

    #pragma region Message Handling
public:
    //! Called before message queue translate message
    //! @param[in] m
    //!     Message
    //! @return
    //!     True to eat message
    virtual BOOL BeforeTranslateMessage(MSG* m);

    //! Window procedure
    //! @param[in] message
    //!     Message
    //! @param[in] wParam
    //!     wparam
    //! @param[in] lParam
    //!     lparam
    //! @return
    //!     Message result
    virtual LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam);

    //! Default window procedure handler
    //! @param[in] message
    //!     Message
    //! @param[in] wParam
    //!     wparam
    //! @param[in] lParam
    //!     lparam
    //! @return
    //!     Message result
    virtual LRESULT DefaultWindowProc(UINT message, WPARAM wParam, LPARAM lParam);

    //! Window message handler
    //! @param[in] message
    //!     Message
    //! @param[in] wParam
    //!     wparam
    //! @param[in] lParam
    //!     lparam
    //! @param[out] result
    //!     Result value
    //! @return
    //!     True when message was processed
    virtual BOOL OnWindowMessage(UINT message, WPARAM wParam, LPARAM lParam, LRESULT* result);

    //! @todo DOcument this
    BOOL ReflectMessage(UINT message, WPARAM wParam, LPARAM lParam, LRESULT* result);

    //! Calls default procecure
    //! @remarks
    //!     This method must be called when you want to manually process
    //!     message
    //! @return
    //!     Default window procedure result
    LRESULT CallDefaultProc();
public:
    //! Static window callback
    //! @remarks
    //!     This method is used to subclassing and calling proper window message handler procedure
    //! @param[in] handle
    //!     Window handle
    //! @param[in] message
    //!     Message
    //! @param[in] wParam
    //!     wparam
    //! @param[in] lParam
    //!     lparam
    //! @return
    //!     Processed message result value
    static LRESULT CALLBACK UixWindowProc(HWND handle, UINT message, WPARAM wParam, LPARAM lParam);

    //!@bug remove //static LRESULT CALLBACK UixCallWindowProc(uixWindow* window, HWND handle, UINT message, WPARAM wParam, LPARAM lParam);
    #pragma endregion

    #pragma region Event Handler methods
public:

    //! @note
    //!     Handles:
    //!     - WM_ACTIVATE
    //!
    //!     Use uixEVT_ACTIVATE
    void OnActivate(uixActivateEventArgs& e);

    //! @note
    //!     Handles:
    //!     - WM_ACTIVATEAPP
    //!
    //!     Use uixEVT_ACTIVATEAPP
    void OnActivateApp(uixActivateAppEventArgs& e);

    //! @note
    //!     Handles:
    //!     - WM_APPCOMMAND
    //!
    //!     Use uixEVT_APPCOMMAND
    void OnAppCommand(uixAppCommandEventArgs& e);

    //! @note
    //!     Handles:
    //!     - WM_ASKCBFORMATNAME
    //!
    //!     Use uixEVT_ASKCLIPBOARDFORMATNAME
    void OnAskClipboardFormatName(uixClipboardFormatNameEventArgs& e);

    //! @note
    //!     Handles:
    //!     - WM_CANCELJOURNAL
    //!
    //!     Use uixEVT_CANCELJOURNAL
    void OnCancelJournal(uixEventArgs& e);

    //! @note
    //!     Handles:
    //!     - WM_CANCELMODE
    //!
    //!     Use uixEVT_CANCELMODE
    void OnCancelMode(uixEventArgs& e);

    //! @note
    //!     Handles:
    //!     - WM_CAPTURECHANGED
    //!
    //!     Use uixEVT_CAPTURECHANGED
    void OnCaptureChanged(uixCaptureChangedEventArgs& e);

    //! @note
    //!     Handles:
    //!     - WM_CHANGECBCHAIN
    //!
    //!     Use uixEVT_CHANGECLIPBOARDCHAIN
    void OnChangeClipboardChain(uixChangeClipboardChainEventArgs& e);

    //! @note
    //!     Handles:
    //!     - WM_CHANGEUISTATE
    //!
    //!     Use uixEVT_CHANGEUISTATE
    void OnChangeUIState(uixChangeUiStateEventArgs& e);

    //! @note
    //!     Handles:
    //!     - WM_CHAR
    //!
    //!     Use uixEVT_CHAR
    void OnChar(uixKeyEventArgs& e);

    //! @note
    //!     Handles:
    //!     - WM_CHARTOITEM
    //!
    //!     Use uixEVT_CHARTOITEM
    //! @remarks
    //!     This event returns value, see @see uixCharToItemEventArgs
    void OnCharToItem(uixCharToItemEventArgs& e);

    //! @note
    //!     Handles:
    //!     - WM_CHILDACTIVATE
    //!
    //!     Use uixEVT_CHILDACTIVATE
    void OnChildActivate(uixEventArgs& e);

    //! @note
    //!     Handles:
    //!     - WM_CLEAR
    //!
    //!     Use uixEVT_CLEAR
    void OnClear(uixEventArgs& e);

    //! @note
    //!     Handles:
    //!     - WM_CLIPBOARDUPDATE
    //!
    //!     Use uixEVT_CLIPBOARDUPDATE
    void OnClipboardUpdate(uixEventArgs& e);

    //! @note
    //!     Handles:
    //!     - WM_CLOSE
    //!
    //!     Use uixEVT_CLOSE
    void OnClose(uixCloseEventArgs& e);

    //! @note
    //!     Handles:
    //!     - WM_COMPACTING
    //!
    //!     Use uixEVT_COMPACTING
    void OnCompacting(uixCompactingEventArgs& e);

    //! @note
    //!     Handles:
    //!     - WM_COMPAREITEM
    //!
    //!     Use uixEVT_COMPAREITEM
    //! @remarks
    //!     This event returns value, see @see uixCompareItemEventArgs
    void OnCompareItem(uixCompareItemEventArgs& e);

    //! @note
    //!     Handles:
    //!     - WM_CONTEXTMENU
    //!
    //!     Use uixEVT_CONTEXTMENU
    void OnContextMenu(uixContextMenuEventArgs& e);

    //! @note
    //!     Handles:
    //!     - WM_COPY
    //!
    //!     Use uixEVT_COPY
    void OnCopy(uixEventArgs& e);

    //! @note
    //!     Handles:
    //!     - WM_COPYDATA
    //!
    //!     Use uixEVT_COPYDATA
    //! @remarks
    //!     Returns true when processed
    void OnCopyData(uixCopyDataEventArgs& e);

    //! @note
    //!     Handles:
    //!     - WM_CREATE
    //!
    //!     Use uixEVT_CREATE
    //! @remarks
    //!     Returns 0 when success, -1 otherwise
    void OnCreate(uixCreateEventArgs& e);

    //! @note
    //!     Handles:
    //!     - WM_CTLCOLORMSGBOX
    //!     - WM_CTLCOLOREDIT
    //!     - WM_CTLCOLORLISTBOX
    //!     - WM_CTLCOLORBTN
    //!     - WM_CTLCOLORDLG
    //!     - WM_CTLCOLORSCROLLBAR
    //!     - WM_CTLCOLORSTATIC
    //!
    //!     Use uixEVT_CTRLCOLOR

    //! @note
    //!     Handles:
    //!     - WM_CUT
    //!
    //!     Use uixEVT_CUT
    void OnCut(uixEventArgs& e);

    //! @note
    //!     Handles:
    //!     - WM_DEADCHAR
    //!
    //!     Use uixEVT_DEADCHAR
    void OnDeadChar(uixKeyEventArgs& e);

    //! @note
    //!     Handles:
    //!     - WM_DELETEITEM
    //!
    //!     Use uixEVT_DELETEITEM
    //! @remarks
    //!     Returns true when processed
    void OnDeleteItem(uixDeleteItemEventArgs& e);

    //! @note
    //!     Handles:
    //!     - WM_DESTROY
    //!
    //!     Use uixEVT_DESTROY
    void OnDestroy(uixDestroyEventArgs& e);

    //! @note
    //!     Handles:
    //!     - WM_DESTROYCLIPBOARD
    //!
    //!     Use uixEVT_DESTROYCLIPBOARD
    void OnDestroyClipboard(uixEventArgs& e);

    //! @note
    //!     Handles:
    //!     - WM_DEVICECHANGE
    //!
    //!     Use uixEVT_DEVICECHANGE
    void OnDeviceChange(uixDeviceChangeEventArgs& e);

    //! @note
    //!     Handles:
    //!     - WM_DEVMODECHANGE
    //!
    //!     Use uixEVT_DEVMODECHANGE
    void OnDevModeChange(uixDevModeChangeEventArgs& e);

    //! @note
    //!     Handles:
    //!     - WM_DISPLAYCHANGE
    //!
    //!     Use uixEVT_DISPLAYCHANGE
    void OnDisplayChange(uixDisplayChangeEventArgs& e);

    //! @note
    //!     Handles:
    //!     - WM_DRAWCLIPBOARD
    //!
    //!     Use uixEVT_DRAWCLIPBOARD
    void OnDrawClipboard(uixEventArgs& e);

    //! @note
    //!     Handles:
    //!     - WM_DRAWITEM
    //!
    //!     Use uixEVT_DRAWITEM
    //! @remarks
    //!     Returns true when processed
    void OnDrawItem(uixDrawItemEventArgs& e);

    //! @note
    //!     Handles:
    //!     - WM_DROPFILES
    //!
    //!     Use uixEVT_DROPFILES
    void OnDropFiles(uixDropFilesEventArgs& e);

    //! @note
    //!     Handles:
    //!     - WM_DWMCOLORIZATIONCOLORCHANGED
    //!
    //!     Use uixEVT_

    //! @note
    //!     Handles:
    //!     - WM_DWMCOMPOSITIONCHANGED
    //!
    //!     Use uixEVT_

    //! @note
    //!     Handles:
    //!     - WM_DWMNCRENDERINGCHANGED
    //!
    //!     Use uixEVT_

    //! @note
    //!     Handles:
    //!     - WM_DWMSENDICONICLIVEPREVIEVBITMAP
    //!
    //!     Use uixEVT_

    //! @note
    //!     Handles:
    //!     - WM_DWMSENDICONICTHUMBNAIL
    //!
    //!     Use uixEVT_

    //! @note
    //!     Handles:
    //!     - WM_DWMWINDOWMAXIMIZECHANGE
    //!
    //!     Use uixEVT_

    //! @note
    //!     Handles:
    //!     - WM_ENABLE
    //!
    //!     Use uixEVT_ENABLE
    void OnEnable(uixEnableEventArgs& e);

    //! @note
    //!     Handles:
    //!     - WM_ENDSESSION
    //!
    //!     Use uixEVT_ENDSESSION
    void OnEndSession(uixEndSessionEventArgs& e);

    //! @note
    //!     Handles:
    //!     - WM_ENTERIDLE
    //!
    //!     Use uixEVT_ENTERIDLE
    void OnEnterIdle(uixEnterIdleEventArgs& e);

    //! @note
    //!     Handles:
    //!     - WM_ENTERMENULOOP
    //!
    //!     Use uixEVT_ENTERMENULOOP
    void OnEnterMenuLoop(uixMenuLoopEventArgs& e);

    //! @note
    //!     Handles:
    //!     - WM_ENTERSIZEMOVE
    //!
    //!     Use uixEVT_ENTERSIZEMOVE
    void OnEnterSizeMove(uixEventArgs& e);

    //! @note
    //!     Handles:
    //!     - WM_ERASEBACKGROUND
    //!
    //!     Use uixEVT_ERASEBACKGROUND
    //! @remarks
    //!     Returns true when processed
    void OnEraseBackground(uixEraseBackgroundEventArgs& e);

    //! @note
    //!     Handles:
    //!     - WM_
    //!
    //!     Use uixEVT_EXITMENULOOP
    void OnExitMenuLoop(uixMenuLoopEventArgs& e);

    //! @note
    //!     Handles:
    //!     - WM_EXITSIZEMOVE
    //!
    //!     Use uixEVT_EXITSIZEMOVE
    void OnExitSizeMove(uixEventArgs& e);

    //! @note
    //!     Handles:
    //!     - WM_FONTCHANGE
    //!
    //!     Use uixEVT_FONTCHANGE
    void OnFontChange(uixEventArgs& e);

    //! @note
    //!     Handles:
    //!     - WM_GESTURE
    //!
    //!     Use uixEVT_

    //! @note
    //!     Handles:
    //!     - WM_GESTURENOTIFY
    //!
    //!     Use uixEVT_

    //! @note
    //!     Handles:
    //!     - WM_GETDLGCODE
    //!
    //!     Use uixEVT_

    //! @note
    //!     Handles:
    //!     - WM_GETOBJECT
    //! @todo in newer releases
    //!     Use uixEVT_

    //! @note
    //!     Handles:
    //!     - WM_HELP
    //!
    //!     Use uixEVT_HELP
    //! @remarks
    //!     Returns true when processed
    void OnHelp(uixHelpEventArgs& e);

    //! @note
    //!     Handles:
    //!     - WM_HOTKEY
    //!
    //!     Use uixEVT_HOTKEY
    void OnHotKey(uixHotKeyEventArgs& e);

    //! @note
    //!     Handles:
    //!     - WM_HSCROLL
    //!
    //!     Use uixEVT_HSCROLL
    void OnHScroll(uixScrollEventArgs& e);

    //! @note
    //!     Handles:
    //!     - WM_HSCROLLCLIPBOARD
    //!
    //!     Use uixEVT_HSCROLLCLIPBOARD
    void OnHScrollClipboard(uixScrollClipboardEventArgs& e);

    //! @note
    //!     Handles:
    //!     - WM_INITDIALOG
    //!
    //!     Use uixEVT_INITDIALOG
    void OnInitDialog(uixInitDialogEventArgs& e);

    //! @note
    //!     Handles:
    //!     - WM_INITMENU
    //!
    //!     Use uixEVT_INITMENU
    void OnInitMenu(uixInitMenuEventArgs& e);


    //! @note
    //!     Handles:
    //!     - WM_INITMENUPOPUP
    //!
    //!     Use uixEVT_
    void OnInitMenuPopup(uixInitMenuPopupEventArgs& e);

    //! @note
    //!     Handles:
    //!     - WM_INPUT
    //!
    //!     Use uixEVT_

    //! @note
    //!     Handles:
    //!     - WM_INPUTDEVICECHANGE
    //!
    //!     Use uixEVT_

    //! @note
    //!     Handles:
    //!     - WM_INPUTLANGCHANGE
    //!
    //!     Use uixEVT_

    //! @note
    //!     Handles:
    //!     - WM_INPUTANCHANGEREQUEST
    //!
    //!     Use uixEVT_

    //! @note
    //!     Handles:
    //!     - WM_KEYDOWN
    //!
    //!     Use uixEVT_KEYDOWN
    void OnKeyDown(uixKeyEventArgs& e);

    //! @note
    //!     Handles:
    //!     - WM_KEYUP
    //!
    //!     Use uixEVT_KEYUP
    void OnKeyUp(uixKeyEventArgs& e);

    //! @note
    //!     Handles:
    //!     - WM_KILLFOCUS
    //!
    //!     Use uixEVT_KILLFOCUS
    void OnKillFocus(uixFocusChangeEventArgs& e);

    ////////////////////
    // MDI MESSAGES - uixMdiChild, uixMdiFrame
    ////////////////////

    //! @note
    //!     Handles:
    //!     - WM_MEASUREITEM
    //!
    //!     Use uixEVT_MEASUREITEM
    void OnMeasureItem(uixMeasureItemEventArgs& e);

    //! @note
    //!     Handles:
    //!     - WM_MENUCHAR
    //!
    //!     Use uixEVT_

    //! @note
    //!     Handles:
    //!     - WM_MENUCOMMAND
    //!
    //!     Use uixEVT_

    //! @note
    //!     Handles:
    //!     - WM_MENUDRAG
    //!
    //!     Use uixEVT_

    //! @note
    //!     Handles:
    //!     - WM_MENUGETOBJECT
    //!
    //!     Use uixEVT_

    //! @note
    //!     Handles:
    //!     - WM_MENURBUTTONUP
    //!
    //!     Use uixEVT_

    //! @note
    //!     Handles:
    //!     - WM_MENUSELECT
    //!
    //!     Use uixEVT_

    //! @note
    //!     Handles:
    //!     - WM_
    //!
    //!     Use uixEVT_MOUSEACTIVATE
    //! @remarks
    //!     Returns activation cue flag
    void OnMouseActivate(uixMouseActivateEventArgs& e);

    //! @note
    //!     Handles:
    //!     - WM_LBUTTONDBLCLK
    //!     - WM_MBUTTONDBLCLK
    //!     - WM_RBUTTONDBLCLK
    //!     - WM_XBUTTONDBLCLK
    //!
    //!     Use uixEVT_LMOUSEDOUBLECLICK, uixEVT_MMOUSEDOUBLECLICK,
    //!     uixEVT_RMOUSEDOUBLECLICK or uixEVT_XMOUSEDOUBLECLICK
    void OnMouseDoubleClick(uixMouseEventArgs& e);

    //! @note
    //!     Handles:
    //!     - WM_LBUTTONDOWN
    //!     - WM_MBUTTONDOWN
    //!     - WM_RBUTTONDOWN
    //!     - WM_XBUTTONDOWN
    //!
    //!     Use uixEVT_LMOUSEDOWN, uixEVT_MMOUSEDOWN, uixEVT_RMOUSEDOWN or
    //!     uixEVT_XMOUSEDOWN
    void OnMouseDown(uixMouseEventArgs& e);

    //! @note
    //!     Handles:
    //!     - WM_LBUTTONUP
    //!     - WM_MBUTTONUP
    //!     - WM_RBUTTONUP
    //!     - WM_XBUTTONUP
    //!
    //!     Use uixEVT_LMOUSEUP, uixEVT_MMOUSEUP, uixEVT_RMOUSEUP or
    //!     uixEVT_XMOUSEUP
    void OnMouseUp(uixMouseEventArgs& e);

    //! @note
    //!     Handles:
    //!     - WM_MOUSEHOVER
    //!
    //!     Use uixEVT_MOUSEHOVER
    void OnMouseHover(uixMouseEventArgs& e);

    //! @note
    //!     Handles:
    //!     - WM_MOUSEMOVE
    //!
    //!     Use uixEVT_MOUSEHMOVE
    void OnMouseMove(uixMouseEventArgs& e);

    //! @todo Document this
    void OnMouseLeave(uixEventArgs& e);

    //! @note
    //!     Handles:
    //!     - WM_MOUSEWHEEL
    //!
    //!     Use uixEVT_MOUSEWHEEL
    void OnMouseWheel(uixMouseEventArgs& e);

    //! @note
    //!     Handles:
    //!     - WM_MOUSEHWHEEL
    //!
    //!     Use uixEVT_MOUSEHWHEEL
    void OnMouseHWheel(uixMouseEventArgs& e);

    //! @note
    //!     Handles:
    //!     - uixEVT_MOVE
    //!
    //!     Use uixEVT_MOVE
    void OnMove(uixMoveEventArgs& e);

    //! @note
    //!     Handles:
    //!     - WM_MOVING
    //!
    //!     Use uixEVT_MOVING
    //! @remarks
    //!     Returns true when processed
    void OnMoving(uixBorderChangeEventArgs& e);

    //! @note
    //!     Handles:
    //!     - WM_NCACTIVATE
    //!
    //!     Use uixEVT_

    //! @note
    //!     Handles:
    //!     - WM_NCCALCSIZE
    //!
    //!     Use uixEVT_

    //! @note
    //!     Handles:
    //!     - WM_NCCREATE
    //!
    //!     Use uixEVT_

    //! @note
    //!     Handles:
    //!     - WM_NCDESTROY
    //!
    //!     Use uixEVT_

    //! @note
    //!     Handles:
    //!     - WM_NCHITTEST
    //!
    //!     Use uixEVT_

    //! @note
    //!     Handles:
    //!     - WM_NCPAINT
    //!
    //!     Use uixEVT_

    //! @note
    //!     Handles:
    //!     - WM_MOUSELEAVE
    //!
    //!     Use uixEVT_MOUSELEAVE
    void OnNcMouseLeave(uixEventArgs& e);

    //! @note
    //!     Handles:
    //!     - WM_NCMOUSEHOVER
    //!
    //!     Use uixEVT_NCMOUSEHOVER
    void OnNcMouseHover(uixNcMouseEventArgs& e);

    //! @note
    //!     Handles:
    //!     - WM_NCMOUSEMOVE
    //!
    //!     Use uixEVT_NCMOUSEMOVE
    void OnNcMouseMove(uixNcMouseEventArgs& e);

    //! @note
    //!     Handles:
    //!     - WM_NCLBUTTONDBLCLK
    //!     - WM_NCMBUTTONDBLCLK
    //!     - WM_NCRBUTTONDBLCLK
    //!     - WM_NCXBUTTONDBLCLK
    //!
    //!     Use uixEVT_LNCMOUSEDOUBLECLICK, uixEVT_MNCMOUSEDOUBLECLICK, uixEVT_RNCMOUSEDOUBLECLICK or
    //!     uixEVT_XNCMOUSEDOUBLECLICK
    void OnNcMouseDoubleClick(uixNcMouseEventArgs& e);

    //! @note
    //!     Handles:
    //!     - WM_NCLBUTTONDOWN
    //!     - WM_NCMBUTTONDOWN
    //!     - WM_NCRBUTTONDOWN
    //!     - WM_NCXBUTTONDOWN
    //!
    //!     Use uixEVT_LNCMOUSEDOWN, uixEVT_MNCMOUSEDOWN, uixEVT_RNCMOUSEDOWN or
    //!     uixEVT_XNCMOUSEDOWN
    void OnNcMouseDown(uixNcMouseEventArgs& e);

    //! @note
    //!     Handles:
    //!     - WM_NCLBUTTONUP
    //!     - WM_NCMBUTTONUP
    //!     - WM_NCRBUTTONUP
    //!     - WM_NCXBUTTONUP
    //!
    //!     Use uixEVT_LNCMOUSEUP, uixEVT_MNCMOUSEUP, uixEVT_RNCMOUSEUP or
    //!     uixEVT_XNCMOUSEUP
    void OnNcMouseUp(uixNcMouseEventArgs& e);

    //! @note
    //!     Handles:
    //!     - WM_NEXTDLGCTRL
    //!
    //!     Use uixEVT_

    //! @note
    //!     Handles:
    //!     - WM_NEXTMENU
    //!
    //!     Use uixEVT_

    //void OnNotify(uixEventArgs& e);

    //! @note
    //!     Handles:
    //!     - WM_NOTIFYFORMAT
    //!
    //!     Use uixEVT_

    //! @note
    //!     Handles:
    //!     - WM_PAINT
    //!
    //!     Use uixEVT_PAINT
    void OnPaint(uixPaintEventArgs& e);

    //! @note
    //!     Handles:
    //!     - WM_PAINTCLIPBOARD
    //!
    //!     Use uixEVT_

    //! @note
    //!     Handles:
    //!     - WM_PAINTICON
    //!
    //!     Use uixEVT_

    //! @note
    //!     Handles:
    //!     - WM_PALETTECHANGED
    //!
    //!     Use uixEVT_

    //! @note
    //!     Handles:
    //!     - WM_PALETTEISCHANGING
    //!
    //!     Use uixEVT_

    //! @note
    //!     Handles:
    //!     - WM_PARENTNOTIFY
    //!
    //!     Use uixEVT_

    //! @note
    //!     Handles:
    //!     - WM_PASTE
    //!
    //!     Use uixEVT_

    //! @note
    //!     Handles:
    //!     - WM_POWER
    //!
    //!     Use uixEVT_

    //! @note
    //!     Handles:
    //!     - WM_POWERBROADCAST
    //!
    //!     Use uixEVT_

    //! @note
    //!     Handles:
    //!     - WM_PRINT
    //!
    //!     Use uixEVT_

    //! @note
    //!     Handles:
    //!     - WM_PRINTCLIENT
    //!
    //!     Use uixEVT_

    //! @note
    //!     Handles:
    //!     - WM_QUERYDRAGICON
    //!
    //!     Use uixEVT_

    //! @note
    //!     Handles:
    //!     - WM_QUERYENDSESSION
    //!
    //!     Use uixEVT_

    //! @note
    //!     Handles:
    //!     - WM_QUERYNEWPALETTE
    //!
    //!     Use uixEVT_

    //! @note
    //!     Handles:
    //!     - WM_QUERYOPEN
    //!
    //!     Use uixEVT_

    //! @note
    //!     Handles:
    //!     - WM_QUERYUISTATE
    //!
    //!     Use uixEVT_QUERYUISTATE
    void OnQueryUiState(uixQueryUiStateEventArgs& e);

    //! @note
    //!     Handles:
    //!     - WM_QUEUESYNC
    //!
    //!     Use uixEVT_
    void OnQueueSync(uixEventArgs& e);

    //! @note
    //!     Handles:
    //!     - WM_QUIT
    //!
    //!     Use uixEVT_QUIT
    void OnQuit(uixQuitEventArgs& e);

    //! @note
    //!     Handles:
    //!     - WM_RENDERALLFORMATS
    //!
    //!     Use uixEVT_RENDERALLFORMATS
    void OnRenderAllFormats(uixEventArgs& e);

    //! @note
    //!     Handles:
    //!     - WM_RENDERFORMAT
    //!
    //!     Use uixEVT_RENDERFORMAT
    void OnRenderFormat(uixRenderFormatEventArgs& e);

    //! @note
    //!     Handles:
    //!     - WM_SETFOCUS
    //!
    //!     Use uixEVT_SETFOCUS
    void OnSetFocus(uixFocusChangeEventArgs& e);

    //! @note
    //!     Handles:
    //!     - WM_SETTINGCHANGE
    //!
    //!     Use uixEVT_SETTINGCHANGE
    void OnSettingChange(uixSettingChangeEventArgs& e);

    //! @note
    //!     Handles:
    //!     - WM_SHOWWINDOW
    //!
    //!     Use uixEVT_SHOWWINDOW
    void OnShowWindow(uixShowWindowEventArgs& e);

    //! @note
    //!     Handles:
    //!     - WM_SIZE
    //!
    //!     Use uixEVT_SIZE
    void OnSize(uixSizeEventArgs& e);

    //! @note
    //!     Handles:
    //!     - WM_SIZECLIPBOARD
    //!
    //!     Use uixEVT_SIZECLIPBOARD
    void OnSizeClipboard(uixSizeClipboardEventArgs& e);

    //! @note
    //!     Handles:
    //!     - WM_GETMINMAXINFO
    //!
    //!     Use uixEVT_SIZINGCONSTRAINTS
    void OnSizeConstraints(uixSizeConstraintsEventArgs& e);

    //! @note
    //!     Handles:
    //!     - WM_SIZING
    //!
    //!     Use uixEVT_SIZING
    //! @remarks
    //!     Returns true when processed
    void OnSizing(uixBorderChangeEventArgs& e);

    //! @note
    //!     Handles:
    //!     - WM_SPOOLERSTATUS
    //!
    //!     Use uixEVT_SPOOLERSTATUS
    void OnSpoolerStatus(uixSpoolerStatusEventArgs& e);

    //! @note
    //!     Handles:
    //!     - WM_STYLECHANGED
    //!
    //!     Use uixEVT_STYLECHANGED
    void OnStyleChanged(uixStyleChangeEventArgs& e);

    //! @note
    //!     Handles:
    //!     - WM_STYLECHANGING
    //!
    //!     Use uixEVT_STYLECHANGING
    void OnStyleChanging(uixStyleChangeEventArgs& e);

    //! @note
    //!     Handles:
    //!     - WM_SYNCPAINT
    //!
    //!     Use uixEVT_
    void OnSyncPaint(uixEventArgs& e);

    //! @note
    //!     Handles:
    //!     - WM_SYSCHAR
    //!
    //!     Use uixEVT_
    void OnSysChar(uixKeyEventArgs& e);

    //! @note
    //!     Handles:
    //!     - WM_SYSCOLORCHANGE
    //!
    //!     Use uixEVT_SYSCOLORCHANGE
    void OnSysColorChange(uixEventArgs& e);

    //! @note
    //!     Handles:
    //!     - WM_SYSDEADCHAR
    //!
    //!     Use uixEVT_SYSDEADCHAR
    void OnSysDeadChar(uixKeyEventArgs& e);

    //! @note
    //!     Handles:
    //!     - WM_SYSKEYDOWN
    //!
    //!     Use uixEVT_SYSKEYDOWN
    void OnSysKeyDown(uixKeyEventArgs& e);

    //! @note
    //!     Handles:
    //!     - WM_SYSKEYUP
    //!
    //!     Use uixEVT_SYSKEYUP
    void OnSysKeyUp(uixKeyEventArgs& e);

    //! @note
    //!     Handles:
    //!     - WM_TCARD
    //! @todo Implement in newer versions
    //!     Use uixEVT_

    //! @note
    //!     Handles:
    //!     - WM_THEMECHANGED
    //!
    //!     Use uixEVT_THEMECHANGED
    void OnThemeChanged(uixEventArgs& e);

    //! @note
    //!     Handles:
    //!     - WM_TIMECHANGE
    //!
    //!     Use uixEVT_TIMECHANGE
    void OnTimeChange(uixEventArgs& e);

    //! @note
    //!     Handles:
    //!     - WM_TIMER
    //!
    //!     Use uixEVT_TIMER
    void OnTimer(uixTimerEventArgs& e);

    //! @note
    //!     Handles:
    //!     - WM_TOUCH
    //! @todo Implement in newer versions
    //!     Use uixEVT_

    //! @note
    //!     Handles:
    //!     - WM_UNDO
    //!
    //!     Use uixEVT_UNDO
    void OnUndo(uixUndoEventArgs& e);

    //! @note
    //!     Handles:
    //!     - WM_UNICHAR
    //!
    //!     Use uixEVT_UNICHAR
    void OnUniChar(uixKeyEventArgs& e);

    //! @note
    //!     Handles:
    //!     - WM_UNINITPOPUPMENU
    //!
    //!     Use uixEVT_UNINITPOPUPMENU
    void OnUnInitMenuPopup(uixUnInitMenuPopupEventArgs& e);

    //! @note
    //!     Handles:
    //!     - WM_UPDATEUISTATE
    //!
    //!     Use uixEVT_UPDATEUISTATE
    void OnUpdateUIState(uixUpdateUiState& e);

    //! @note
    //!     Handles:
    //!     - WM_USERCHANGED
    //!
    //!     Use uixEVT_USERCHANGED
    void OnUserChanged(uixEventArgs& e);

    //! @note
    //!     Handles:
    //!     - WM_VKEYTOITEM
    //!
    //!     Use uixEVT_VKEYTOITEM
    void OnVKeyToItem(uixVKeyToItem& e);

    //! @note
    //!     Handles:
    //!     - WM_VSCROLL
    //!
    //!     Use uixEVT_VSCROLL
    void OnVScroll(uixScrollEventArgs& e);

    //! @note
    //!     Handles:
    //!     - WM_VSCROLLCLIPBOARD
    //!
    //!     Use uixEVT_VSCROLLCLIPBOARD
    void OnVScrollClipboard(uixScrollClipboardEventArgs& e);

    //! @note
    //!     Handles:
    //!     - WM_WINDOWPOSCHANGED
    //!
    //!     Use uixEVT_WINDOWPOSCHANGED
    void OnWindowPosChanged(uixWindowPosChangeEventArgs& e);

    //! @note
    //!     Handles:
    //!     - WM_WINDOWPOSCHANGING
    //!
    //!     Use uixEVT_WINDOWPOSCHANGING
    void OnWindowPosChanging(uixWindowPosChangeEventArgs& e);

    //! @note
    //!     Handles:
    //!     - WM_WTSESSIONCHANGE
    //!
    //!     Use uixEVT_
    void OnWtsSessionChange(uixWtsSessionChangeEventArgs& e);

    #pragma endregion
};

//! Window creation hook
//! @brief
//!     This class is used to hook window creation process. By hooking
//!     CreateWindow call, we can subclass newly created window and attach
//!     object's pointer to handle.
class UIXAPI uixCreateWindowHook
{
public:
    //! Callback filter method
    //! @param[in] code
    //!     Hook code
    //! @param[in] wParam
    //!     Message wParam
    //! @param[in] lParam
    //!     Message lParam
    //! @return
    //!     Result value
    static LRESULT CALLBACK Filter(INT code, WPARAM wParam, LPARAM lParam);

    //! Begins hook process
    //! @remarks
    //!     By calling this method, we set new hook and pointer to attach
    //!     to this handle. This method assume that pointer passed by window
    //!     is meant to be attached to handle
    //! @param[in] window
    //!     Pointer to window
    static void Begin(uixWindow* window);

    //! Ends hook process
    //! @return
    //!     True when successful, false otherwise
    static BOOL End();
};
}
//----------------------------------------------------------------------------//
#include "uixwindow.inl"
//----------------------------------------------------------------------------//
#endif /* _UIX_WINDOW_H__ */