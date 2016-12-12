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
#ifndef _UIX_TEXTCTRL_H__
#define _UIX_TEXTCTRL_H__
//----------------------------------------------------------------------------//
#include "uixwindow.h"
//----------------------------------------------------------------------------//
namespace UIX
{
//! Handle
#define uixEVT_TXN_SETFOCUS(Identifier, Handler) \
    uixEVT_CONTROL(EN_SETFOCUS, Identifier, Handler)

//! Handle
#define uixEVT_TXN_KILLFOCUS(Identifier, Handler) \
    uixEVT_CONTROL(EN_KILLFOCUS, Identifier, Handler)

//! Handle
#define uixEVT_TXN_CHANGE(Identifier, Handler) \
    uixEVT_CONTROL(EN_CHANGE, Identifier, Handler)

//! Handle
#define uixEVT_TXN_UPDATE(Identifier, Handler) \
    uixEVT_CONTROL(EN_UPDATE, Identifier, Handler)

//! Handle
#define uixEVT_TXN_ERRSPACE(Identifier, Handler) \
    uixEVT_CONTROL(EN_ERRSPACE, Identifier, Handler)

//! Handle
#define uixEVT_TXN_MAXTEXT(Identifier, Handler) \
    uixEVT_CONTROL(EN_MAXTEXT, Identifier, Handler)

//! Handle
#define uixEVT_TXN_HSCROLL(Identifier, Handler) \
    uixEVT_CONTROL(EN_HSCROLL, Identifier, Handler)

//! Handle
#define uixEVT_TXN_VSCROLL(Identifier, Handler) \
    uixEVT_CONTROL(EN_VSCROLL, Identifier, Handler)

//! Handle
#define uixEVT_TXN_ALIGN_LTR_EC(Identifier, Handler) \
    uixEVT_CONTROL(EN_ALIGN_LTR_EC, Identifier, Handler)

//! Handle
#define uixEVT_TXN_ALIGN_RTL_EC(Identifier, Handler) \
    uixEVT_CONTROL(EN_ALIGN_RTL_EC, Identifier, Handler)

//! Handle
#define uixEVT_TXN_IMECHANGE(Identifier, Handler) \
    uixEVT_CONTROL(EN_IMECHANGE, Identifier, Handler)

//! Handle
#define uixEVT_TXN_ALIGNLTR(Identifier, Handler) \
    uixEVT_CONTROL(EN_ALIGNLTR, Identifier, Handler)

//! Handle
#define uixEVT_TXN_ALIGNRTL(Identifier, Handler) \
    uixEVT_CONTROL(EN_ALIGNRTL, Identifier, Handler)

//! Balloon tip icon
enum uixTextCtrlBalloonTipIcon
{
    //! Small error
    uixTextCtrlBalloonTipIcon_Error = TTI_ERROR,
    //! Small info
    uixTextCtrlBalloonTipIcon_Info = TTI_INFO,
    //! None
    uixTextCtrlBalloonTipIcon_None = TTI_NONE,
    //! Small warning
    uixTextCtrlBalloonTipIcon_Warning = TTI_WARNING,
    //! Large error
    uixTextCtrlBalloonTipIcon_ErrorLarge = TTI_ERROR_LARGE,
    //! Large info
    uixTextCtrlBalloonTipIcon_InfoLarge = TTI_INFO_LARGE,
    //! Large warning
    uixTextCtrlBalloonTipIcon_WarningLarge = TTI_WARNING_LARGE,
};

//! Balloon tip info
struct uixTextCtrlBalloonTip : EDITBALLOONTIP
{
    //! Constructor
    uixTextCtrlBalloonTip()
    {
        ZeroMemory(this, sizeof(uixTextCtrlBalloonTip));
        cbStruct = sizeof(uixTextCtrlBalloonTip);
    }

    //! Gets title
    //! @return
    //!     Title
    const wchar_t* GetTitle() const
    {
        return pszTitle;
    }

    //! Sets title
    //! @param[in] text
    //!     Text title
    void SetTitle(const wchar_t* text)
    {
        pszTitle = text;
    }

    //! Gets text
    //! @return
    //!     Text
    const wchar_t* GetText() const
    {
        return pszText;
    }

    //! Sets text
    //! @param[in] text
    //!     Text
    void SetText(const wchar_t* text)
    {
        pszText = text;
    }

    //! Gets icon handle
    //! @return
    //!     Icon handle or ID
    HICON GetIcon() const
    {
        return (HICON)ttiIcon;
    }

    //! Sets icon ID
    //! @param[in] icon
    //!     Icon ID
    void SetIcon(uixTextCtrlBalloonTipIcon icon)
    {
        ttiIcon = (INT)icon;
    }

    //! Sets icon handle
    //! @param[in] icon
    //!     Icon handle
    void SetIcon(HICON icon)
    {
        ttiIcon = (INT)icon;
    }
};

enum uixTextCtrlStyle
{
    uixTextCtrlStyle_AutoHScroll = ES_AUTOHSCROLL,
    uixTextCtrlStyle_AutoVScroll = ES_AUTOVSCROLL,
    uixTextCtrlStyle_Center = ES_CENTER,
    uixTextCtrlStyle_Left = ES_LEFT,
    uixTextCtrlStyle_LowerCase = ES_LOWERCASE,
    uixTextCtrlStyle_MultiLine = ES_MULTILINE,
    uixTextCtrlStyle_NoHideSelection = ES_NOHIDESEL,
    uixTextCtrlStyle_Number = ES_NUMBER,
    uixTextCtrlStyle_OemConvert = ES_OEMCONVERT,
    uixTextCtrlStyle_Password = ES_PASSWORD,
    uixTextCtrlStyle_ReadOnly = ES_READONLY,
    uixTextCtrlStyle_Right = ES_RIGHT,
    uixTextCtrlStyle_UpperCase = ES_UPPERCASE,
    uixTextCtrlStyle_WantReturn = ES_WANTRETURN,
};

//! Text Control
//! @brief
//!     This class implements GUI control, which is able to display and
//!     edit texts
class UIXAPI uixTextCtrl : public uixWindow
{
    uixDECLARE_DYNAMIC_CLASS(uixTextCtrl);
public:
    //! Constructor
    uixTextCtrl();

    //! Destructor
    virtual ~uixTextCtrl();

    //! @copydoc uixWindow::BeforeWindowCreate
    virtual BOOL BeforeWindowCreate(CREATESTRUCT& cs);

    //! Checks if text box can perform undo operation
    //! @return
    //!     True when successful
    BOOL CanUndo() const;

    //! Empty undo buffer
    void EmptyUndoBuffer();

    //! Format lines
    //! @param[in] addEOL
    //!     Set true to add end of line marks
    void FmtLines(BOOL addEOL);

    //! Gets cue banner text
    //! @param[out] text
    //!     Text buffer
    //! @param[in] length
    //!     Length of text buffer
    //! @return
    //!     True when successful
    BOOL GetCueBannerText(uixChar* text, UINT length) const;

    //! Gets first visible line
    //! @return
    //!     Index of line
    INT GetFirstVisibleLine() const;

    //! Gets text handle
    //! @return
    //!     Handle to allocated memory for text
    HLOCAL GetTextHandle() const;

    //! Gets line
    //! @param[in] line
    //!     Line
    //! @param[out] text
    //!     Text buffer
    //! @param[in] length
    //!     Length of text buffer
    //! @return
    //!     Characters readed
    INT GetLine(INT line, uixChar* text, UINT length) const;

    //! Gets line count
    //! @return
    //!     Number of lines in text box
    INT GetLineCount() const;

    //! Gets modify status
    //! @return
    //!     True when text was modified
    BOOL GetModify() const;

    //! Gets password character
    //! @return
    //!     Password character
    uixChar GetPasswordChar() const;

    //! Gets format rectangle
    //! @param[out] rect
    //!     Format rectangle
    void GetFormatRect(RECT& rect) const;

    //! Gets selection
    //! @return
    //!     Packed selection
    DWORD GetSelection() const;

    //! Gets selection
    //! @param[out] start
    //!     Start selection
    //! @param[out] end
    //!     End of selection
    void GetSelection(UINT& start, UINT& end) const;

    //! Gets word break procedure
    //! @return
    //!     Word break procedure
    EDITWORDBREAKPROC GetWordBreakProc() const;

    //! Hides balloon tip
    //! @return
    //!     True when successful
    BOOL HideBalloonTip();

    //! Sets max text length limit
    //! @param[in] limit
    //!     Limit value
    void LimitText(UINT limit);

    //! Gets line number from character index
    //! @param[in] charID
    //!     Character index
    //! @return
    //!     Line number
    INT LineFromChar(INT charID) const;

    //! Gets line index
    //! @param[in] lineID
    //!     Line index
    //! @return
    //!     Line index
    //! @note
    //!     set lineID to -1 to get current line number
    INT LineIndex(INT lineID) const;

    //! Gets line length
    //! @param[in] lineID
    //!     Line ID
    //! @return
    //!     Line length
    INT LineLength(INT lineID) const;

    //! Replaces selected text
    //! @param[in] text
    //!     New text
    void ReplaceSelection(const uixChar* text);

    //! Scrolls view
    //! @param[in] dx
    //!     Delta X value
    //! @param[in] dy
    //!     Delta y value
    void Scroll(INT dx, INT dy);

    //! Scrolls caret
    //! @return
    //!     True when successful
    BOOL ScrollCaret();

    //! Sets cue banner text
    //! @param[in] text
    //!     Text
    //! @return
    //!     True when successful
    BOOL SetCueBannerText(const uixChar* text);

    //! Sets focused cue banner text
    //! @param[in] text
    //!     Text
    //! @param[in] drawFocused
    //!     Draws focused
    //! @return
    //!     True when successful
    BOOL SetCueBannerTextFocused(const uixChar* text, BOOL drawFocused);

    //! Sets text handle
    //! @param[in] handle
    //!     Handle to memory alloacated with text
    void SetTextHandle(HLOCAL handle);

    //! Sets modify flag
    //! @param[in] modified
    //!     Modified flag
    void SetModify(BOOL modified);

    //! Sets password character
    //! @param[in] character
    //!     Password character. Set 0 to disable password character
    void SetPasswordChar(UINT character);

    //! Sets read only flag
    //! @param[in] readOnly
    //!     Read only flag
    //! @return
    //!     Previous read only flag
    BOOL SetReadOnly(BOOL readOnly);

    //! Sets format rect
    //! @param[in] rect
    //!     Rectangle
    void SetFormatRect(RECT* rect = NULLPTR);

    //! Sets no paint rectangle
    //! @param[in] rect
    //!     Rectangle
    void SetFormatRectNoPaint(RECT* rect = NULLPTR);

    //! Sets selection
    //! @param[in] start
    //!     First character
    //! @param[in] end
    //!     Last character
    void SetSelection(INT start, INT end);

    //! Sets tab stops
    //! @param[in] tabs
    //!     Array of tab stops
    //! @param[in] count
    //!     Number of elements in tabs array
    void SetTabStops(INT tabs[], INT count);

    //! Sets word break procedure
    //! @param[in] proc
    //!     Word break procedure
    void SetWordBreakProc(EDITWORDBREAKPROC proc);

    //! Shows balloon tip
    //! @param[in] params
    //!     Balloon tip params
    //! @return
    //!     True when successful
    BOOL ShowBalloonTip(EDITBALLOONTIP& params);

    //! Performs undo
    //! @return
    //!     True when successful
    BOOL Undo();
};
}
//----------------------------------------------------------------------------//
#include "uixtextctrl.inl"
//----------------------------------------------------------------------------//
#endif /* _UIX_TEXTCTRL_H__ */