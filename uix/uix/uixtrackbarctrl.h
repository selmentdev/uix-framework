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
#ifndef _UIX_TRACKBARCTRL_H__
#define _UIX_TRACKBARCTRL_H__
//----------------------------------------------------------------------------//
#include "uixwindow.h"
//----------------------------------------------------------------------------//
namespace UIX
{
//! Track bar changing reason
enum uixTrackBarChangingReason
{
    //! Line up
    uixTrackBarChangingReason_LineUp = TB_LINEUP,
    //! Line down
    uixTrackBarChangingReason_LineDown = TB_LINEDOWN,
    //! Page up
    uixTrackBarChangingReason_PageUp = TB_PAGEUP,
    //! Page down
    uixTrackBarChangingReason_PageDown = TB_PAGEDOWN,
    //! Thumb position
    uixTrackBarChangingReason_ThumbPosition = TB_THUMBPOSITION,
    //! Thumb track
    uixTrackBarChangingReason_ThumbTrack = TB_THUMBTRACK,
    //! Top
    uixTrackBarChangingReason_Top = TB_TOP,
    //! Bottom
    uixTrackBarChangingReason_Bottom = TB_BOTTOM,
    //! End track
    uixTrackBarChangingReason_EndTrack = TB_ENDTRACK,
};

//! @todo Rething notification mechanism
struct uixTrackBarThumbPosChanging : NMTRBTHUMBPOSCHANGING
{
    DWORD GetPosition() const
    {
        return dwPos;
    }

    uixTrackBarChangingReason GetReason() const
    {
        return (uixTrackBarChangingReason)nReason;
    }
};

//! Handle
#define uixEVT_TRBN_THUMBPOSCHANGING(Identifier, Handler) /* LRESULT (NMHDR* header) */ \
    uixEVT_NOTIFY(TRBN_THUMBPOSCHANGING, Identifier, Handler)

//! Track bar style
enum uixTrackBarStyle
{
    //! Auto ticks
    uixTrackBarStyle_AutoTicks = TBS_AUTOTICKS,
    //! Vertical
    uixTrackBarStyle_Vertical = TBS_VERT,
    //! Horizontal
    uixTrackBarStyle_Horizontal = TBS_HORZ,
    //! Top
    uixTrackBarStyle_Top = TBS_TOP,
    //! Bottom
    uixTrackBarStyle_Bottom = TBS_BOTTOM,
    //! Left
    uixTrackBarStyle_Left = TBS_LEFT,
    //! Right
    uixTrackBarStyle_Right = TBS_RIGHT,
    //! Both
    uixTrackBarStyle_Both = TBS_BOTH,
    //! No ticks
    uixTrackBarStyle_NoTicks = TBS_NOTICKS,
    //! Enable select range
    uixTrackBarStyle_EnableSelectRange = TBS_ENABLESELRANGE,
    //! Fixed length
    uixTrackBarStyle_FixedLength = TBS_FIXEDLENGTH,
    //! No thumb
    uixTrackBarStyle_NoThumb = TBS_NOTHUMB,
    //! Tool tips
    uixTrackBarStyle_ToolTips = TBS_TOOLTIPS,
    //! Reversed
    uixTrackBarStyle_Reversed = TBS_REVERSED,
    //! Down is left
    uixTrackBarStyle_DownIsLeft = TBS_DOWNISLEFT,
    //! Notify before remove
    uixTrackBarStyle_NotifyBeforeRemove = TBS_NOTIFYBEFOREMOVE,
    //! Transparent background
    uixTrackBarStyle_TransparentBackground = TBS_TRANSPARENTBKGND,
};

//! Track Bar Control
//! @brief
//!     This class implements control to change values from specified range.
//!     It is similar to scrollbar, but allows to select specified ranges
class UIXAPI uixTrackBarCtrl : public uixWindow
{
    uixDECLARE_DYNAMIC_CLASS(uixTrackBarCtrl);
public:
    //! Constructor
    uixTrackBarCtrl();

    //! Destructor
    virtual ~uixTrackBarCtrl();

    //! @copydoc uixWindow::BeforeWindowCreate
    virtual BOOL BeforeWindowCreate(CREATESTRUCT& cs);

    //! Clears selection
    //! @param[in] redraw
    //!     True to redraw
    void ClearSelection(BOOL redraw = TRUE);

    //! Clear tics
    //! @param[in] redraw
    //!     True to redraw
    void ClearTics(BOOL redraw = TRUE);

    //! Gets buddy window
    //! @param[in] left
    //!     - TRUE means left or top
    //!     - FALSE means right or bottom
    //! @return
    //!     Handle to associated window
    HWND GetBuddyWindow(BOOL left) const;

    //! Gets channel rect
    //! @param[out] rect
    //!     Rect of channel
    void GetChannelRect(RECT& rect) const;

    //! Gets line size
    //! @return
    //!     Line size
    INT GetLineSize() const;

    //! Gets number tics
    //! @return
    //!     Tics count
    INT GetNumTics() const;

    //! Gets page size
    //! @return
    //!     Page size
    INT GetPageSize() const;

    //! Gets position
    //! @return
    //!     Position
    INT GetPosition() const;

    //! Gets tics data
    //! @return
    //!     Pointer to tics array
    DWORD* GetTics() const;

    //! Gets max range
    //! @return
    //!     Max range
    INT GetRangeMax() const;

    //! Gets min range
    //! @return
    //!     Min range
    INT GetRangeMin() const;

    //! Gets selection end
    //! @return
    //!     End of selection
    INT GetSelectionEnd() const;

    //! Gets selection start
    //! @return
    //!     Start of selection
    INT GetSelectionStart() const;

    //! Gets thumb length
    //! @return
    //!     Thumb length
    INT GetThumbLength() const;

    //! Gets thumb rect
    //! @param[out] rect
    //!     Thumb rect
    void GetThumbRect(RECT& rect) const;

    //! Gets tic
    //! @param[in] ticID
    //!     Tic ID
    //! @return
    //!     Value at tic
    INT GetTic(INT ticID) const;

    //! Gets tic position
    //! @param[in] ticID
    //!     Tic ID
    //! @return
    //!     Tic position
    INT GetTicPosition(INT ticID) const;

    //! Gets tool tip window
    //! @return
    //!     Handle to tooltip window
    HWND GetToolTips() const;

    //! Gets unicode format support
    //! @return
    //!     True when unicode supported
    BOOL GetUnicodeFormat() const;

    //! Gets buddy window
    //! @param[in] left
    //!     - TRUE means left or top
    //!     - FALSE means right or bottom
    //! @param[in] buddy
    //!     Handle to new buddy window
    //! @return
    //!     Handle to previous associated window
    HWND SetBuddy(BOOL left, HWND buddy);

    //! Sets line size
    //! @param[in] size
    //!     New size
    //! @return
    //!     Previous size
    INT SetLineSize(INT size);

    //! Sets page size
    //! @param[in] size
    //!     Page size
    //! @return
    //!     Previuos page size
    INT SetPageSize(INT size);

    //! Sets position
    //! @param[in] position
    //!     Position
    //! @param[in] redraw
    //!     True to redraw
    void SetPosition(INT position, BOOL redraw = TRUE);

    //! Sets position notify
    //! @param[in] position
    //!     Position
    void SetPositionNotify(INT position);

    //! Sets range
    //! @param[in] low
    //!     Low range
    //! @param[in] high
    //!     High range
    //! @param[in] redraw
    //!     True to redraw
    void SetRange(INT low, INT high, BOOL redraw = TRUE);

    //! Sets range max
    //! @param[in] max
    //!     Max range value
    //! @param[in] redraw
    //!     True to redraw
    void SetRangeMax(INT max, BOOL redraw = TRUE);

    //! Sets range min
    //! @param[in] min
    //!     Min range value
    //! @param[in] redraw
    //!     True to redraw
    void SetRangeMin(INT min, BOOL redraw = TRUE);

    //! Sets selection
    //! @param[in] start
    //!     Start of selection
    //! @param[in] end
    //!     End of selection
    //! @param[in] redraw
    //!     True to redraw
    void SetSelection(INT start, INT end, BOOL redraw = TRUE);

    //! Sets selection
    //! @param[in] end
    //!     End of selection
    //! @param[in] redraw
    //!     True to redraw
    void SetSelectionEnd(INT end, BOOL redraw = TRUE);

    //! Sets selection
    //! @param[in] start
    //!     Start of selection
    //! @param[in] redraw
    //!     True to redraw
    void SetSelectionStart(INT start, BOOL redraw = TRUE);

    //! Sets thumb length
    //! @param[in] length
    //!     Thumb length
    void SetThumbLength(INT length);

    //! Sets tic position
    //! @param[in] ticPosition
    //!     Tic position
    //! @return
    //!     True when successful
    BOOL SetTic(INT ticPosition);

    //! Sets tic frequency
    //! @param[in] frequency
    //!     Frequency
    void SetTicFrequency(INT frequency);

    //! Sets tips side
    //! @param[in] side
    //!     - TBTS_TOP
    //!     - TBTS_LEFT
    //!     - TBTS_BOTTOM
    //!     - TBTS_RIGHT
    //! @return
    //!     Previous tips side
    INT SetTipSide(INT tipSide);

    //! Sets tool tips window
    //! @param[in] toolTip
    //!     Tool tip window handle
    void SetToolTips(HWND toolTip);

    //! Sets unicode format
    //! @param[in] unicode
    //!     Unicode format flag
    //! @return
    //!     True when successful
    BOOL SetUnicodeFormat(BOOL unicode);
};
}
//----------------------------------------------------------------------------//
#include "uixtrackbarctrl.inl"
//----------------------------------------------------------------------------//
#endif /* _UIX_TRACKBARCTRL_H__ */