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
#include "uixwindow.h"
#include "uixstate.h"
#include "uixexception.h"
#include "uixuithread.h"
#include "uixdump.h"
//----------------------------------------------------------------------------//
namespace UIX
{
//----------------------------------------------------------------------------//
BOOL UixReflectMessage(HWND handle, UINT message, WPARAM wParam, LPARAM lParam, LRESULT* result)
{
    // Get window from handle
    uixWindow* sender = uixWindow::FromHandle(handle);

    // And if available
    if (sender != NULLPTR)
    {
        // Process reflected message
        return sender->OnWindowMessage(message + WM_REFLECTBASE, wParam, lParam, result);
    }

    // otherwise allow process message by parent window..
    return FALSE;
}
//----------------------------------------------------------------------------//
//! Filter callback
//! @param[in] code
//!     Code
//! @param[in] wParam
//!     wParam
//! @param[in] lParam
//!     lParam
//! @return
//!     Result value
LRESULT uixCreateWindowHook::Filter(INT code, WPARAM wParam, LPARAM lParam)
{
    if (code != HCBT_CREATEWND)
    {
        // We're interested in create window only
        goto Success;
    }

    uixASSERT(lParam != 0);

    // Getting create struct from lparam
    CREATESTRUCT* cs = ((CBT_CREATEWND*)lParam)->lpcs;
    uixASSERT(cs != NULLPTR);
    uixUNREFERENCED(cs);

    uixThreadState& ts = uixThreadState::Get();

    // Get window pointer from thread storage
    uixWindow* window = ts.m_CreateWindowHook_Window;

    // If window available
    if (window)
    {
        // Subclass it using passed handle
        uixASSERT(wParam != 0);
        HWND handle = (HWND)wParam;
        window->Subclass(handle);

        // Setting back to null
        ts.m_CreateWindowHook_Window = NULLPTR;
    }

Success:
    return CallNextHookEx(uixThreadState::Get().m_CreateWindowHook_Handle, code, wParam, lParam);
}
//----------------------------------------------------------------------------//
//! Set hook to window creation
//! @param[in] window
//!     Hooked window instance
void uixCreateWindowHook::Begin(uixWindow* window)
{
    uixThreadState& ts = uixThreadState::Get();

    // Do not hook window twice's
    if (ts.m_CreateWindowHook_Window == window)
    {
        uixTRACE(_("Warning: trying to hook window creation twice!"));
        return;
    }

    // Set hook if it is not hooked
    if (ts.m_CreateWindowHook_Handle == 0)
    {
        ts.m_CreateWindowHook_Handle = SetWindowsHookEx(
                                           WH_CBT,
                                           uixCreateWindowHook::Filter, 0, GetCurrentThreadId());

        // Check for failure
        if (ts.m_CreateWindowHook_Handle == 0)
        {
            uixTRACE(_("Cannot set window creation hook"));
            uixASSERT(FALSE);
        }
    }

    uixASSERT(ts.m_CreateWindowHook_Handle != 0);
    uixASSERT(window != NULLPTR);
    uixASSERT(window->GetHandle() == 0);
    uixASSERT(ts.m_CreateWindowHook_Window == NULLPTR);

    // Set window to hook
    ts.m_CreateWindowHook_Window = window;
}
//----------------------------------------------------------------------------//
//! Ends create window hook
//! @return
//!     True when successful
BOOL uixCreateWindowHook::End()
{
    uixThreadState& ts = uixThreadState::Get();

    // Unhook filter
    if (ts.m_CreateWindowHook_Handle != 0)
    {
        UnhookWindowsHookEx(ts.m_CreateWindowHook_Handle);
        ts.m_CreateWindowHook_Handle = 0;
    }

    // Check for unhooked window
    if (ts.m_CreateWindowHook_Window != NULLPTR)
    {
        ts.m_CreateWindowHook_Window = NULLPTR;
        return FALSE;
    }

    return TRUE;
}
//----------------------------------------------------------------------------//
namespace
{
//! Window Property: Instance
const uixChar* UixWindowPropertyInstance = _("uixWindow.Instance");
}
//----------------------------------------------------------------------------//
uixIMPLEMENT_DYNAMIC_CLASS(uixWindow, uixObject);
//----------------------------------------------------------------------------//
#pragma region Constructor & Destructor
//----------------------------------------------------------------------------//
uixWindow::uixWindow()
    : m_Handle(0)
    , m_SuperWndProc(NULLPTR)
{
}
//----------------------------------------------------------------------------//
uixWindow::uixWindow(HWND handle)
    : m_Handle(0)
    , m_SuperWndProc(NULLPTR)
{
}
//----------------------------------------------------------------------------//
uixWindow::~uixWindow()
{
    if (m_Handle != 0)
    {
        uixTRACE("Calling DestroyWindow in destructor: Class [%s]", this->GetMetaClass()->GetName());
        uixASSERT(false && "Modify inherited destructor to destroy window automatically");
        DestroyWindow();
    }
}
//----------------------------------------------------------------------------//
#pragma endregion
//----------------------------------------------------------------------------//
#pragma region Window Create and Destroy
//----------------------------------------------------------------------------//
uixWindow* uixWindow::FromHandle(HWND handle)
{
    if (IsWindow(handle))
    {
        return (uixWindow*)GetProp(handle, UixWindowPropertyInstance);
    }

    return NULLPTR;
}
//----------------------------------------------------------------------------//
BOOL uixWindow::Create(
    uixWindow* parent,
    const uixChar* text,
    const uixPoint& position,
    const uixSize& size,
    uixWindowID id,
    DWORD style,
    DWORD exStyle)
{
    uixASSERT(parent != NULLPTR);
    uixASSERT(::IsWindow(parent->GetHandle()));

    return uixWindow::CreateEx(
               exStyle,
               NULLPTR,
               text,
               style,
               position.x,
               position.y,
               size.cx,
               size.cy,
               parent->GetHandle(),
               (HMENU)id);
}
//----------------------------------------------------------------------------//
BOOL uixWindow::Create(
    uixWindow* parent,
    const uixPoint& position,
    const uixSize& size,
    uixWindowID id,
    DWORD style,
    DWORD exStyle)
{
    return uixWindow::Create(
               parent,
               NULLPTR,
               position,
               size,
               id,
               style,
               exStyle);
}
//----------------------------------------------------------------------------//
BOOL uixWindow::Create(
    uixWindow* parent,
    uixWindowID id,
    DWORD style,
    DWORD exStyle)
{
    return uixWindow::Create(
               parent,
               NULLPTR,
               uixPoint(0, 0),
               uixSize(0, 0),
               id,
               style,
               exStyle);
}
//----------------------------------------------------------------------------//
BOOL uixWindow::Create(
    const uixChar* text,
    const uixPoint& position,
    const uixSize& size,
    HMENU menu,
    DWORD style,
    DWORD exStyle)
{
    return uixWindow::CreateEx(
               exStyle,
               NULLPTR,
               text,
               style,
               position.x,
               position.y,
               size.cx,
               size.cy,
               0,
               menu);
}
//----------------------------------------------------------------------------//
BOOL uixWindow::CreateEx(
    DWORD styleEx, const uixChar* className, const uixChar* windowName,
    DWORD style, INT left, INT top, INT width, INT height, HWND parent,
    HMENU menu, void* param)
{
    CREATESTRUCT cs;
    cs.lpCreateParams = param;
    cs.hInstance = uixProcessState::Get().m_Handle;
    cs.hMenu = menu;
    cs.hwndParent = parent;
    cs.cy = height;
    cs.cx = width;
    cs.y = top;
    cs.x = left;
    cs.style = style;
    cs.lpszName = windowName;
    cs.lpszClass = className;
    cs.dwExStyle = styleEx;

    if (!this->BeforeWindowCreate(cs))
    {
        return FALSE;
    }

    uixASSERT(cs.lpszClass != NULLPTR);

    // Hook creation
    uixCreateWindowHook::Begin(this);

    // Create window
    HWND handle = CreateWindowEx(
                      cs.dwExStyle,
                      cs.lpszClass,
                      cs.lpszName,
                      cs.style,
                      cs.x,
                      cs.y,
                      cs.cx,
                      cs.cy,
                      cs.hwndParent,
                      cs.hMenu,
                      cs.hInstance,
                      cs.lpCreateParams);

#if defined UIX_DEBUG
    DWORD errorCode = ::GetLastError();
#endif
    // Unhook
    uixCreateWindowHook::End();

#if defined UIX_DEBUG

    if (errorCode != 0)
    {
        uixTRACE(_("CreateWindow: [ErrorCode: %d]\n[Message: %s]"),
                 errorCode,
                 UixErrorString(errorCode).c_str());
    }

#endif

    // if creation failed
    if (handle == 0)
    {
        uixTRACE(_("Cannot create window class [%s]"), cs.lpszClass);
        return FALSE;
    }

    // Should be same
    uixASSERT(handle == m_Handle);

    // Also set default UI font since CreateWindow* uses fixedsys font
    ::SendMessage(m_Handle, WM_SETFONT, (::WPARAM)::GetStockObject(DEFAULT_GUI_FONT), (::LPARAM)TRUE);

    return TRUE;
}
//----------------------------------------------------------------------------//
BOOL uixWindow::DestroyWindow()
{
    BOOL result = ::DestroyWindow(m_Handle);
    m_Handle = 0;
    return result;
}
//----------------------------------------------------------------------------//
BOOL uixWindow::BeforeWindowCreate(CREATESTRUCT& cs)
{
    return TRUE;
}
//----------------------------------------------------------------------------//
BOOL uixWindow::Attach(HWND handle)
{
    uixASSERT(m_Handle == 0);
    uixASSERT(handle != 0);
    uixASSERT(::IsWindow(handle));

    // Window shouldn't be attached to this handle
    uixASSERT(uixWindow::FromHandle(handle) == 0);

    if (handle == 0)
    {
        return FALSE;
    }

    // Set handle
    m_Handle = handle;

    // Ensure that handle property don't contain this value
    uixENSURE(GetProp(m_Handle, UixWindowPropertyInstance) != (HANDLE)this);
    // Set net instance property
    SetProp(m_Handle, UixWindowPropertyInstance, (HANDLE)this);

    return TRUE;
}
//----------------------------------------------------------------------------//
HWND uixWindow::Detach()
{
    uixASSERT(::IsWindow(m_Handle));

    HWND handle = m_Handle;

    if (handle != 0)
    {
        SetProp(handle, UixWindowPropertyInstance, (HANDLE)NULLPTR);
        m_Handle = 0;
    }

    return handle;
}
//----------------------------------------------------------------------------//
BOOL uixWindow::Subclass(HWND handle)
{
    uixASSERT(::IsWindow(handle));

    if (!Attach(handle))
    {
        return FALSE;
    }

    WNDPROC super = m_SuperWndProc;
    WNDPROC previous = (WNDPROC)SetWindowLongPtr(handle, GWLP_WNDPROC,
                       (INT_PTR)uixWindow::UixWindowProc);

    // Do not need to subclass
    if (previous == uixWindow::UixWindowProc)
    {
        return FALSE;
    }

    if (super == NULLPTR)
    {
        m_SuperWndProc = previous;
    }
    else if (super != previous)
    {
        uixASSERT(false);
        SetWindowLongPtr(handle, GWLP_WNDPROC, (LONG_PTR)previous);
    }

    return TRUE;
}
//----------------------------------------------------------------------------//
HWND uixWindow::Unsubclass()
{
    uixASSERT(::IsWindow(m_Handle));

    WNDPROC super = m_SuperWndProc;
    SetWindowLongPtr(m_Handle, GWLP_WNDPROC, (LONG_PTR)super);
    m_SuperWndProc = NULLPTR;

    return Detach();
}
//----------------------------------------------------------------------------//
BOOL uixWindow::IsCreated() const
{
    return (this != NULLPTR) && (m_Handle != 0) && (::IsWindow(m_Handle));
}
#if defined UIX_DEBUG
//----------------------------------------------------------------------------//
void uixWindow::ValidateObject() const
{
    uixObject::ValidateObject();

    uixASSERT(m_Handle != 0);
    uixASSERT(::IsWindow(m_Handle));
}
//----------------------------------------------------------------------------//
void uixWindow::DumpObject(UIX::uixDumpContext& ctx) const
{
    uixObject::DumpObject(ctx);

    ctx.Write("this", "%p", this);
    ctx.Write("handle", "%p", m_Handle);
    ctx.Write("is_window", "%d", ::IsWindow(m_Handle));
    ctx.Write("is_visible", "%d", ::IsWindowVisible(m_Handle));
    ctx.Write("is_enabled", "%d", ::IsWindowEnabled(m_Handle));
    ctx.Write("is_unicode", "%d", ::IsWindowUnicode(m_Handle));
}
#endif
//----------------------------------------------------------------------------//
#pragma endregion
//----------------------------------------------------------------------------//
#pragma region Size and position management
//----------------------------------------------------------------------------//
BOOL uixWindow::CenterWindow()
{
    HWND hwndParent;
    RECT rect, rectP;
    int width, height;
    int screenwidth, screenheight;
    int x, y;

    hwndParent = GetParent();

    ::GetWindowRect(m_Handle, &rect);

    // Fix: center to desktop, when window is minimized
    if (::IsIconic(hwndParent))
    {
        ::HMONITOR m = ::MonitorFromWindow(hwndParent, MONITOR_DEFAULTTONEAREST);

        MONITORINFO nfo = {0};
        nfo.cbSize = sizeof(nfo);
        ::GetMonitorInfo(m, &nfo);
        rectP = nfo.rcWork;
    }
    // Fix: center to desktop, when window is top root window
    else if (hwndParent == 0)
    {
        ::HMONITOR m = ::MonitorFromWindow(m_Handle, MONITOR_DEFAULTTONEAREST);

        MONITORINFO nfo = {0};
        nfo.cbSize = sizeof(nfo);
        ::GetMonitorInfo(m, &nfo);
        rectP = nfo.rcWork;
    }
    // Normal window - normal case
    else
    {
        ::GetWindowRect(hwndParent, &rectP);
    }

    width = rect.right - rect.left;
    height = rect.bottom - rect.top;

    x = ((rectP.right - rectP.left) - width) / 2 + rectP.left;
    y = ((rectP.bottom - rectP.top) - height) / 2 + rectP.top;

    screenwidth = GetSystemMetrics(SM_CXSCREEN);
    screenheight = GetSystemMetrics(SM_CYSCREEN);

    if (x < 0)
    {
        x = 0;
    }

    if (y < 0)
    {
        y = 0;
    }

    if (x + width > screenwidth)
    {
        x = screenwidth - width;
    }

    if (y + height > screenheight)
    {
        y = screenheight - height;
    }

    ::MoveWindow(m_Handle, x, y, width, height, FALSE);
    return TRUE;
}
//----------------------------------------------------------------------------//
BOOL uixWindow::CenterWindow(uixWindowRelativePos relative)
{
    uixRect parentRect;
    uixRect wndRect;

    switch (relative)
    {
    default:
    case uixWindowRelativePos_Default:
    case uixWindowRelativePos_Desktop:
    case uixWindowRelativePos_Monitor:
        {
            ::HMONITOR m = ::MonitorFromWindow(m_Handle, MONITOR_DEFAULTTONEAREST);

            MONITORINFO nfo = {0};
            nfo.cbSize = sizeof(nfo);
            ::GetMonitorInfo(m, &nfo);
            parentRect = nfo.rcWork;
            break;
        }

    case uixWindowRelativePos_Parent:
        {
            HWND parent = GetParent();

            if (parent == 0)
            {
                return CenterWindow(uixWindowRelativePos_Default);
            }

            if (::IsIconic(parent))
            {
                return CenterWindow(uixWindowRelativePos_Monitor);
            }

            ::GetWindowRect(parent, &parentRect);

            break;
        }
    }

    GetWindowRect(wndRect);

    INT screenwidth = GetSystemMetrics(SM_CXSCREEN);
    INT screenheight = GetSystemMetrics(SM_CYSCREEN);

    INT width = wndRect.Width();
    INT height = wndRect.Height();

    INT x = ((parentRect.Width()) - width) / 2 + parentRect.left;
    INT y = ((parentRect.Height()) - height) / 2 + parentRect.top;

    if (x < 0)
    {
        x = 0;
    }

    if (y < 0)
    {
        y = 0;
    }

    if (x + width > screenwidth)
    {
        x = screenwidth - width;
    }

    if (y + height > screenheight)
    {
        y = screenheight - height;
    }

    ::SetWindowPos(m_Handle, 0, x, y, width, height, SWP_NOZORDER);

    return TRUE;
}
//----------------------------------------------------------------------------//
#pragma endregion
#pragma region Message Handling
//----------------------------------------------------------------------------//
BOOL uixWindow::BeforeTranslateMessage(MSG* m)
{
    uixUNREFERENCED(m);
    return FALSE;
}
//----------------------------------------------------------------------------//
BOOL uixWindow::OnWindowMessage(UINT message, WPARAM wParam, LPARAM lParam, LRESULT* result)
{
    uixUNREFERENCED(message);
    uixUNREFERENCED(wParam);
    uixUNREFERENCED(lParam);
    uixUNREFERENCED(result);

    return FALSE;
}
//----------------------------------------------------------------------------//
BOOL uixWindow::ReflectMessage(UINT message, WPARAM wParam, LPARAM lParam, LRESULT* result)
{
    return FALSE;
}
//----------------------------------------------------------------------------//
LRESULT uixWindow::WindowProc(UINT message, WPARAM wParam, LPARAM lParam)
{
    LRESULT result = 0;

    // Reflect target
    HWND reflectTarget = 0;

    // Filter for reflectable messages
    switch (message)
    {
    case WM_NOTIFY:
        {
            reflectTarget = uixNotifyEventArgs(wParam, lParam).Data->hwndFrom;
            break;
        }

    case WM_DRAWITEM:
        {
            uixDrawItemEventArgs e(wParam, lParam);
            reflectTarget = ::GetDlgItem(m_Handle, e.Params->CtlID);
            break;
        }

    case WM_COMPAREITEM:
        {
            uixCompareItemEventArgs e(wParam, lParam);
            {
                reflectTarget = ::GetDlgItem(m_Handle, e.Params->CtlID);
            }
            break;
        }

    case WM_DELETEITEM:
        {
            uixDeleteItemEventArgs e(wParam, lParam);
            reflectTarget = e.Params->hwndItem;
            break;
        }

    case WM_CHARTOITEM:
        {
            reflectTarget = (HWND)lParam;
            break;
        }

    case WM_MEASUREITEM:
        {
            uixMeasureItemEventArgs e(wParam, lParam);
            {
                reflectTarget = ::GetDlgItem(m_Handle, e.Params->CtlID);
            }
            break;
        }

    case WM_VKEYTOITEM:
        {
            uixVKeyToItem e(wParam, lParam);
            reflectTarget = e.Sender;
            break;
        }

    case WM_CTLCOLORSTATIC:
    case WM_CTLCOLOREDIT:
    case WM_CTLCOLORBTN:
    case WM_CTLCOLORLISTBOX:
    case WM_CTLCOLORDLG:
    case WM_CTLCOLORMSGBOX:
    case WM_CTLCOLORSCROLLBAR:
        {
            reflectTarget = (HWND)lParam;
            break;
        }
    }

    // If reflect target found
    if (reflectTarget != 0)
    {
        // Reflect message
        if (UixReflectMessage(reflectTarget, message, wParam, lParam, &result))
        {
            // And if message was processed, return result
            return result;
        }
    }

    // Otherwise, try to process message locally
    if (!OnWindowMessage(message, wParam, lParam, &result))
    {
        // TODO: Forward WM_COMMAND to parent control if not handled
        if (message == WM_COMMAND)
        {
            // Don't need to return this message, since we don't care at all
            /*result = */::SendMessage(GetParent(), message, wParam, lParam);
        }

        // If it wasn't processed, call default
        result = DefaultWindowProc(message, wParam, lParam);
    }

    return result;
}
//----------------------------------------------------------------------------//
LRESULT uixWindow::DefaultWindowProc(UINT message, WPARAM wParam, LPARAM lParam)
{
    if (m_SuperWndProc != NULLPTR)
    {
        return ::CallWindowProc(m_SuperWndProc, m_Handle, message, wParam, lParam);
    }

    return ::DefWindowProc(m_Handle, message, wParam, lParam);
}
//----------------------------------------------------------------------------//
LRESULT uixWindow::CallDefaultProc()
{
    uixThreadState& ts = uixThreadState::Get();
    return DefaultWindowProc(
               ts.m_LastSentMsg.message,
               ts.m_LastSentMsg.wParam,
               ts.m_LastSentMsg.lParam);
}
//----------------------------------------------------------------------------//
LRESULT uixWindow::UixWindowProc(HWND handle, UINT message, WPARAM wParam, LPARAM lParam)
{
    uixWindow* window = uixWindow::FromHandle(handle);

    uixASSERT(window != NULLPTR);
    uixASSERT(window->m_Handle == handle);

    if ((window == NULLPTR) || (window->m_Handle != handle))
    {
        return DefWindowProc(handle, message, wParam, lParam);
    }

    uixThreadState& ts = uixThreadState::Get();

    // We need to store last sent message to support nested message handling
    MSG previousMsg = ts.m_LastSentMsg;

    // Set this message as last sent
    ts.m_LastSentMsg.hwnd = handle;
    ts.m_LastSentMsg.message = message;
    ts.m_LastSentMsg.wParam = wParam;
    ts.m_LastSentMsg.lParam = lParam;

    LRESULT result = 0;

    try
    {
        // Try to call window proc
        result = window->WindowProc(message, wParam, lParam);
    }
    catch (uixException& e)
    {
        // Call application exception handler
        if (ts.m_CurrentThread != NULLPTR)
        {
            result = ts.m_CurrentThread->ProcessWindowProcException(e, &previousMsg);
        }
    }

    ts.m_LastSentMsg = previousMsg;
    return result;
}
//----------------------------------------------------------------------------//
#pragma endregion
//----------------------------------------------------------------------------//
}
//----------------------------------------------------------------------------//