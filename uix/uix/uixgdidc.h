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
#ifndef _UIX_GDIDC_H__
#define _UIX_GDIDC_H__
//----------------------------------------------------------------------------//
#include "uixgdibitmap.h"
//----------------------------------------------------------------------------//
namespace UIX
{
//! Arc direction
enum uixDCArcDirection
{
    //! Counter Clock Wise
    uixDCArcDirection_CounterClockWise = AD_COUNTERCLOCKWISE,
    //! Clock Wise
    uixDCArcDirection_ClockWise = AD_CLOCKWISE,
};

enum uixDCPolyType
{
    uixDCPolyType_MoveTo = PT_MOVETO,
    uixDCPolyType_LineTo = PT_LINETO,
    uixDCPolyType_BezierZero = PT_BEZIERTO,
};

//! Bounds Mode
enum uixDCBounds
{
    //! No bounds
    uixDCBounds_None = 0,
    //! Accumulate
    uixDCBounds_Accumulate = DCB_ACCUMULATE,
    //! Disable
    uixDCBounds_Disable = DCB_DISABLE,
    //! Enable
    uixDCBounds_Enable = DCB_ENABLE,
};

//! Background mode
enum uixDCBackgroundMode
{
    uixDCBackgroundMode_Opaque = OPAQUE,
    uixDCBackgroundMode_Transparent = TRANSPARENT,
};

//! Poly fill mode
enum uixDCPolyFillMode
{
    uixDCPolyFillMode_Alternate = ALTERNATE,
    uixDCPolyFillMode_Winding = WINDING,
};

//! Render operation
enum uixDCRop2
{
    uixDCRop2_Black = R2_BLACK,
    uixDCRop2_White = R2_WHITE,
    uixDCRop2_Nop = R2_NOP,
    uixDCRop2_Not = R2_NOT,
    uixDCRop2_CopyPen = R2_COPYPEN,
    uixDCRop2_NotCopyPen = R2_NOTCOPYPEN,
    uixDCRop2_MergePenNot = R2_MERGEPENNOT,
    uixDCRop2_MaskPenNot = R2_MASKPENNOT,
    uixDCRop2_MergeNotPen = R2_MERGENOTPEN,
    uixDCRop2_MaskNotPen = R2_MASKNOTPEN,
    uixDCRop2_MergePen = R2_MERGEPEN,
    uixDCRop2_NotMergePen = R2_NOTMERGEPEN,
    uixDCRop2_MaskPen = R2_MASKPEN,
    uixDCRop2_NotMaskPen = R2_NOTMASKPEN,
    uixDCRop2_XorPen = R2_XORPEN,
    uixDCRop2_NotXorPen = R2_NOTXORPEN,
};

//! Stretch mode
enum uixDCStretchMode
{
    uixDCStretchMode_AndScans = STRETCH_ANDSCANS,
    uixDCStretchMode_DeleteScans = STRETCH_DELETESCANS,
    uixDCStretchMode_HalfTone = STRETCH_HALFTONE,
    uixDCStretchMode_OrScans = STRETCH_ORSCANS,
};

//! Map mode
enum uixDCMapMode
{
    uixDCMapMode_Anisotropic = MM_ANISOTROPIC,
    uixDCMapMode_HiEnglish = MM_HIENGLISH,
    uixDCMapMode_HiMetric = MM_HIMETRIC,
    uixDCMapMode_Isotropic = MM_ISOTROPIC,
    uixDCMapMode_LoEnglish = MM_LOENGLISH,
    uixDCMapMode_LoMetric = MM_LOMETRIC,
    uixDCMapMode_Text = MM_TEXT,
    uixDCMapMode_Twips = MM_TWIPS,
};

//! Region mode
enum uixRegionMode
{
    uixRegionMode_And = RGN_AND,
    uixRegionMode_Copy = RGN_COPY,
    uixRegionMode_Difference = RGN_DIFF,
    uixRegionMode_Or = RGN_OR,
    uixRegionMode_Xor = RGN_XOR,
};

//! Draw Border Edge
enum uixDrawBorderEdge
{
    uixDrawBorderEdge_RaisedInner = BDR_RAISEDINNER,
    uixDrawBorderEdge_RaisedOuter = BDR_RAISEDOUTER,
    uixDrawBorderEdge_SunkenInner = BDR_SUNKENINNER,
    uixDrawBorderEdge_SunkenOuter = BDR_SUNKENOUTER,

    uixDrawBorderEdge_Raised =
        uixDrawBorderEdge_RaisedInner |
        uixDrawBorderEdge_RaisedOuter,

    uixDrawBorderEdge_Sunken =
        uixDrawBorderEdge_SunkenInner |
        uixDrawBorderEdge_SunkenOuter,

    uixDrawBorderEdge_Bump =
        uixDrawBorderEdge_RaisedOuter |
        uixDrawBorderEdge_SunkenInner,

    uixDrawBorderEdge_Etched =
        uixDrawBorderEdge_SunkenOuter |
        uixDrawBorderEdge_RaisedInner,
};

//! Draw Border flags
enum uixDrawBorderFlags
{
    uixDrawBorderFlags_Adjust = BF_ADJUST,
    uixDrawBorderFlags_Bottom = BF_BOTTOM,
    uixDrawBorderFlags_BottomLeft = BF_BOTTOMLEFT,
    uixDrawBorderFlags_BottomRight = BF_BOTTOMRIGHT,
    uixDrawBorderFlags_Diagonal = BF_DIAGONAL,
    uixDrawBorderFlags_DiagonalEndBottomLeft = BF_DIAGONAL_ENDBOTTOMLEFT,
    uixDrawBorderFlags_DiagonalEndBottomRight = BF_DIAGONAL_ENDBOTTOMRIGHT,
    uixDrawBorderFlags_DiagonalEndTopLeft = BF_DIAGONAL_ENDTOPLEFT,
    uixDrawBorderFlags_DiagonalEndTopRight = BF_DIAGONAL_ENDTOPRIGHT,
    uixDrawBorderFlags_Flat = BF_FLAT,
    uixDrawBorderFlags_Left = BF_LEFT,
    uixDrawBorderFlags_Middle = BF_MIDDLE,
    uixDrawBorderFlags_Mono = BF_MONO,
    uixDrawBorderFlags_Rect = BF_RECT,
    uixDrawBorderFlags_Right = BF_RIGHT,
    uixDrawBorderFlags_Soft = BF_SOFT,
    uixDrawBorderFlags_Top = BF_TOP,
    uixDrawBorderFlags_TopLeft = BF_TOPLEFT,
    uixDrawBorderFlags_TopRight = BF_TOPRIGHT,
};

//! Draw frame type
enum uixDrawFrameType
{
    uixDrawFrameType_Button = DFC_BUTTON,
    uixDrawFrameType_Caption = DFC_CAPTION,
    uixDrawFrameType_Menu = DFC_MENU,
    uixDrawFrameType_PopupMenu = DFC_POPUPMENU,
    uixDrawFrameType_Scroll = DFC_SCROLL,
};

//! Draw frame state
enum uixDrawFrameState
{
    uixDrawFrameState_Button3State = DFCS_BUTTON3STATE,
    uixDrawFrameState_ButtonCheck = DFCS_BUTTONCHECK,
    uixDrawFrameState_ButtonPush = DFCS_BUTTONPUSH,
    uixDrawFrameState_ButtonRadio = DFCS_BUTTONRADIO,
    uixDrawFrameState_ButtonImage = DFCS_BUTTONRADIOIMAGE,
    uixDrawFrameState_ButtonMask = DFCS_BUTTONRADIOMASK,

    uixDrawFrameState_CaptionClose = DFCS_CAPTIONCLOSE,
    uixDrawFrameState_CaptionHelp = DFCS_CAPTIONHELP,
    uixDrawFrameState_CaptionMax = DFCS_CAPTIONMAX,
    uixDrawFrameState_CaptionMin = DFCS_CAPTIONMIN,
    uixDrawFrameState_CaptionRestore = DFCS_CAPTIONRESTORE,

    uixDrawFrameState_MenuArrow = DFCS_MENUARROW,
    uixDrawFrameState_MenuArrowRight = DFCS_MENUARROWRIGHT,
    uixDrawFrameState_MenuBullet = DFCS_MENUBULLET,
    uixDrawFrameState_MenuCheck = DFCS_MENUCHECK,

    uixDrawFrameState_ScrollComboBox = DFCS_SCROLLCOMBOBOX,
    uixDrawFrameState_ScrollDown = DFCS_SCROLLDOWN,
    uixDrawFrameState_ScrollLeft = DFCS_SCROLLLEFT,
    uixDrawFrameState_ScrollRight = DFCS_SCROLLRIGHT,
    uixDrawFrameState_ScrollSizeGrip = DFCS_SCROLLSIZEGRIP,
    uixDrawFrameState_ScrollSizeGripRight = DFCS_SCROLLSIZEGRIPRIGHT,
    uixDrawFrameState_ScrollUp = DFCS_SCROLLUP,

    uixDrawFrameState_AdjustRect = DFCS_ADJUSTRECT,
    uixDrawFrameState_Checked = DFCS_CHECKED,
    uixDrawFrameState_Flat = DFCS_FLAT,
    uixDrawFrameState_Hot = DFCS_HOT,
    uixDrawFrameState_Inactive = DFCS_INACTIVE,
    uixDrawFrameState_Mono = DFCS_MONO,
    uixDrawFrameState_Pushed = DFCS_PUSHED,
    uixDrawFrameState_Transparent = DFCS_TRANSPARENT,
};

//! Device Context
//! @brief
//!     This class allows you to paint on specified device context handle
class uixDC
{
protected:
    HDC m_Handle;   //!< Handle

public:
    //! Constructor
    uixDC(HDC handle = 0);

    //! Handle cast operator
    //! @return
    //!     Handle value
    operator HDC () const;

    //! Checks if DC is valid
    //! @return
    //!     True when DC is valid
    BOOL IsValid() const;

    //! Gets handle
    //! @return
    //!     DC's handle
    HDC GetHandle() const;

    //! Gets safe handle
    //! @return
    //!     Handle value
    HDC GetHandleSafe() const;

    //! Save DC state
    //! @return
    //!     State ID
    INT Save();

    //! Restore saved DC state
    //! @param[in] saved
    //!     Saved DC id
    //! @return
    //!     True when successful
    BOOL Restore(INT saved);

    //! Gets device capabilities
    //! @param[in] index
    //!     Caps index
    //! @return
    //!     Value
    INT GetDeviceCaps(INT index);

    //! Gets nearest color
    //! @param[in] color
    //!     Color to compare
    //! @return
    //!     Nearest color in DC
    uixColor GetNearestColor(uixColor color);

    //! Sets bounds rectangle
    //! @param[in] rect
    //!     Rectangle
    //! @param[in] flags
    //!     Bounds
    //! @return
    //!     Bounds
    uixDCBounds SetBoundsRect(const uixRect* rect, uixDCBounds flags);

    //! Gets bounds rectangle
    //! @param[out] rect
    //!     Rectangle
    //! @param[in] bounds
    //!     Bounds
    //! @return
    //!     Bounds
    uixDCBounds GetBoundsRect(uixRect& rect, uixDCBounds bounds);

    //! Resets DC
    //! @param[in] mode
    //!     Device mode
    //! @return
    //!     True when successful
    BOOL Reset(DEVMODE* mode);

    //! Selects GDI object
    //! @param[in] object
    //!     Object to select
    //! @return
    //!     Previous object
    HGDIOBJ Select(HGDIOBJ object);

    //! Selects GDI font
    //! @param[in] font
    //!     Object to select
    //! @return
    //!     Previous font
    HFONT Select(HFONT font);

    //! Selects GDI pen
    //! @param[in] pen
    //!     Object to select
    //! @return
    //!     Previous pen
    HPEN Select(HPEN pen);

    //! Selects GDI brush
    //! @param[in] brush
    //!     Object to select
    //! @return
    //!     Previous brush
    HBRUSH Select(HBRUSH brush);

    //! Selects GDI bitmap
    //! @param[in] bitmap
    //!     Object to select
    //! @return
    //!     Previous bitmap
    HBITMAP Select(HBITMAP bitmap);

    //! Selects GDI stock object
    //! @param[in] index
    //!     Index of object to select
    //! @return
    //!     Previous object index
    HGDIOBJ SelectStock(INT index);

    //! Selects GDI stock font
    //! @param[in] index
    //!     Index of font to select
    //! @return
    //!     Previous font index
    HFONT SelectStockFont(INT index);

    //! Selects GDI stock pen
    //! @param[in] index
    //!     Index of pen to select
    //! @return
    //!     Previous pen index
    HPEN SelectStockPen(INT index);

    //! Selects GDI stock brush
    //! @param[in] index
    //!     Index of brush to select
    //! @return
    //!     Previous brush index
    HBRUSH SelectStockBrush(INT index);

    //! Selects GDI stock bitmap
    //! @param[in] index
    //!     Index of bitmap to select
    //! @return
    //!     Previous bitmap index
    HBITMAP SelectStockBitmap(INT index);

    //! Gets window handle from DC
    //! @return
    //!     Owner's window handle
    HWND FromDC();

    //! Gets current pen
    //! @return
    //!     Handle to pen
    HPEN GetCurrentPen() const;

    //! Gets current brush
    //! @return
    //!     Handle to brush
    HBRUSH GetCurrentBrush() const;

    //! Gets current font
    //! @return
    //!     Handle to font
    HFONT GetCurrentFont() const;

    //! Gets current bitmap
    //! @return
    //!     Handle to bitmap
    HBITMAP GetCurrentBitmap() const;

    //! Creates DC
    //! @param[in] driverName
    //!     Driver name
    //! @param[in] deviceName
    //!     Device name
    //! @param[in] output
    //!     Output name
    //! @param[in] initData
    //!     Init Data
    //! @return
    //!     True when successful
    BOOL Create(LPCTSTR driverName, LPCTSTR deviceName, LPCTSTR output, DEVMODE* initData);

    //! Creates compatible DC
    //! @param[in] dc
    //!     Handle to DC
    //! @return
    //!     True when successful
    BOOL CreateCompatible(HDC dc = 0);

    //! Destroy DC
    //! @return
    //!     True when successful
    BOOL Destroy();

    //! Update colors
    //! @return
    //!     True when successful
    BOOL UpdateColors();

    //! Gets background color
    //! @return
    //!     Background color
    uixColor GetBackgroundColor() const;

    //! Gets background mode
    //! @return
    //!     Background mode
    uixDCBackgroundMode GetBackgroundMode() const;

    //! Gets poly fill mode
    //! @return
    //!     Poly fill mode
    uixDCPolyFillMode GetPolyFillMode() const;

    //! Gets ROP2 mode
    //! @return
    //!     Rop2 mode
    uixDCRop2 GetROP2() const;

    //! Gets stretch blt mode
    //! @return
    //!     Mode
    uixDCStretchMode GetStretchBltMode();

    //! Gets text color
    //! @return
    //!     Text color
    uixColor GetTextColor() const;

    //! Sets background color
    //! @param[in] color
    //!     Background color
    //! @return
    //!     Previous background color
    uixColor SetBackgroundColor(uixColor color);

    //! Sets background mode
    //! @param[in] mode
    //!     New background mode
    //! @return
    //!     Previous background mode
    uixDCBackgroundMode SetBackgroundMode(uixDCBackgroundMode mode);

    //! Sets poly fill mode
    //! @param[in] mode
    //!     Poly fill mode
    //! @return
    //!     Previous mode
    uixDCPolyFillMode SetPolyFillMode(uixDCPolyFillMode mode);

    //! Sets rop2 mode
    //! @param[in] mode
    //!     Mode
    //! @return
    //!     Previous mode
    uixDCRop2 SetROP2(uixDCRop2 mode);

    //! Sets stretch mode
    //! @param[in] mode
    //!     Mode
    //! @return
    //!     Previuos mode
    uixDCStretchMode SetStretchBltMode(uixDCStretchMode mode);

    //! Sets text color
    //! @param[in] color
    //!     Text color
    //! @return
    //!     Previous color
    uixColor SetTextColor(uixColor color);

    //! Gets color adjustment
    //! @param[in] params
    //!     Color adjustment
    //! @return
    //!     True when successful
    BOOL GetColorAdjustment(COLORADJUSTMENT& params);

    //! Sets color adjustment
    //! @param[in] params
    //!     Color adjustment
    //! @return
    //!     True when successful
    BOOL SetColorAdjustment(const COLORADJUSTMENT& params);

    //! Gets map mode
    //! @return
    //!     Map mode
    uixDCMapMode GetMapMode() const;

    //! Gets viewport origin
    //! @param[out] point
    //!     Origin point
    //! @return
    //!     True when successful
    BOOL GetViewportOrg(uixPoint& point) const;

    //! Sets map mode
    //! @param[in] mode
    //!     New mode
    //! @return
    //!     Previous mode
    uixDCMapMode SetMapMode(uixDCMapMode mode);

    //! Sets viewport origin
    //! @param[in] x
    //!     Left position
    //! @param[in] y
    //!     Top position
    //! @param[out] point
    //!     Optional previuos origin
    //! @return
    //!     True when successful
    BOOL SetViewportOrg(INT x, INT y, uixPoint* point = NULLPTR);

    //! Sets viewport origin
    //! @param[in] point
    //!     Position
    //! @param[out] ret
    //!     Optional previuos origin
    //! @return
    //!     True when successful
    BOOL SetViewportOrg(uixPoint point, uixPoint* ret = NULLPTR);

    //! Offsets viewport origin
    //! @param[in] width
    //!     Width
    //! @param[in] height
    //!     Height
    //! @param[out] ret
    //!     Result value
    //! @return
    //!     True when successful
    BOOL OffsetViewportOrg(INT width, INT height, uixPoint* ret = NULLPTR);

    //! Gets viewport extent
    //! @param[out] size
    //!     Extent size
    //! @return
    //!     True when successful
    BOOL GetViewportExt(uixSize& size) const;

    //! Sets viewport extent
    //! @param[in] x
    //!     Left position
    //! @param[in] y
    //!     Top position
    //! @param[out] size
    //!     Previuos extent
    //! @return
    //!     True when successful
    BOOL SetViewportExt(INT x, INT y, uixSize* size = NULLPTR);

    //! Sets viewport extent
    //! @param[in] size
    //!     New extent
    //! @param[out] ret
    //!     Previous extent
    //! @return
    //!     True when successful
    BOOL SetViewportExt(uixSize size, uixSize* ret = NULLPTR);

    //! Scales viewport extent
    //! @param[in] xNum
    //!     X numerator
    //! @param[in] xDenom
    //!     X denominator
    //! @param[in] yNum
    //!     Y numerator
    //! @param[in] yDenom
    //!     Y denominator
    //! @param[out] result
    //!     Result extent
    //! @return
    //!     True when successful
    BOOL ScaleViewportExt(INT xNum, INT xDenom, INT yNum, INT yDenom, uixSize* result);

    //! Gets window origin
    //! @param[in] point
    //!     Origin
    //! @return
    //!     True when successful
    BOOL GetWindowOrg(uixPoint& point) const;

    //! Sets window origin
    //! @param[in] x
    //!     X position
    //! @param[in] y
    //!     Y position
    //! @param[out] result
    //!     Result origin
    //! @return
    //!     True when successful
    BOOL SetWindowOrg(INT x, INT y, uixPoint* result = NULLPTR);

    //! Sets window origin
    //! @param[in] point
    //!     New window origin
    //! @param[out] result
    //!     Result origin
    //! @return
    //!     True when successful
    BOOL SetWindowOrg(uixPoint point, uixPoint* result = NULLPTR);

    //! Offsets window origin
    //! @param[in] width
    //!     Width
    //! @param[in] height
    //!     Height
    //! @param[out] result
    //!     Result window origin
    //! @return
    //!     True when successful
    BOOL OffsetWindowOrg(INT width, INT height, uixPoint* result = NULLPTR);

    //! Gets window extent
    //! @param[out] size
    //!     Extent
    //! @return
    //!     True when successful
    BOOL GetWindowExt(uixSize& size) const;

    //! Sets window extent
    //! @param[in] x
    //!     X position
    //! @param[in] y
    //!     Y position
    //! @param[out] result
    //!     Result window extent
    //! @return
    //!     True when successful
    BOOL SetWindowExt(INT x, INT y, uixSize* result = NULLPTR);

    //! Sets window extent
    //! @param[in] size
    //!     New window extent
    //! @param[out] result
    //!     Result extent
    //! @return
    //!     True when successful
    BOOL SetWindowExt(uixSize size, uixSize* result = NULLPTR);

    //! Scales window extent
    //! @param[in] xNum
    //!     X numerator
    //! @param[in] xDenom
    //!     X denominator
    //! @param[in] yNum
    //!     Y numerator
    //! @param[in] yDenom
    //!     Y denominator
    //! @param[out] result
    //!     Result
    //! @return
    //!     True when successful
    BOOL ScaleWindowExt(INT xNum, INT xDenom, INT yNum, INT yDenom, uixSize* result = NULLPTR);

    //! Converts to logical units
    //! @param[in, out] elements
    //!     Array
    //! @param[in] count
    //!     Number of items in array
    //! @return
    //!     True when successful
    BOOL ToLogicalUnits(uixPoint elements[], INT count);

    //! Converts to logical units
    //! @param[in, out] element
    //!     Element to convert
    //! @return
    //!     True when successful
    BOOL ToLogicalUnits(uixPoint& element);

    //! Converts to logical units
    //! @param[in, out] elements
    //!     Array
    //! @param[in] count
    //!     Number of items in array
    //! @return
    //!     True when successful
    BOOL ToLogicalUnits(uixSize elements[], INT count);

    //! Converts to logical units
    //! @param[in, out] element
    //!     Element to convert
    //! @return
    //!     True when successful
    BOOL ToLogicalUnits(uixSize& element);

    //! Converts to logical units
    //! @param[in, out] elements
    //!     Array
    //! @param[in] count
    //!     Number of items in array
    //! @return
    //!     True when successful
    BOOL ToLogicalUnits(uixRect elements[], INT count);

    //! Converts to logical units
    //! @param[in, out] element
    //!     Element to convert
    //! @return
    //!     True when successful
    BOOL ToLogicalUnits(uixRect& element);

    //! Converts to device units
    //! @param[in, out] elements
    //!     Array
    //! @param[in] count
    //!     Number of items in array
    //! @return
    //!     True when successful
    BOOL ToDeviceUnits(uixPoint elements[], INT count);

    //! Converts to device units
    //! @param[in, out] element
    //!     Element to convert
    //! @return
    //!     True when successful
    BOOL ToDeviceUnits(uixPoint& element);

    //! Converts to device units
    //! @param[in, out] elements
    //!     Array
    //! @param[in] count
    //!     Number of items in array
    //! @return
    //!     True when successful
    BOOL ToDeviceUnits(uixSize elements[], INT count);

    //! Converts to device units
    //! @param[in, out] element
    //!     Element to convert
    //! @return
    //!     True when successful
    BOOL ToDeviceUnits(uixSize& element);

    //! Converts to device units
    //! @param[in, out] elements
    //!     Array
    //! @param[in] count
    //!     Number of items in array
    //! @return
    //!     True when successful
    BOOL ToDeviceUnits(uixRect elements[], INT count);

    //! Converts to device units
    //! @param[in, out] element
    //!     Element to convert
    //! @return
    //!     True when successful
    BOOL ToDeviceUnits(uixRect& element);

    //! Fills region using brush
    //! @param[in] region
    //!     Region to fill
    //! @param[in] brush
    //!     Used brush
    //! @return
    //!     True when successful
    BOOL FillRegion(HRGN region, HBRUSH brush);

    //! Paints region frame
    //! @param[in] region
    //!     Region to fill
    //! @param[in] brush
    //!     Used brush
    //! @param[in] width
    //!     Width
    //! @param[in] height
    //!     Height
    //! @return
    //!     True when successful
    BOOL FrameRegion(HRGN region, HBRUSH brush, INT width, INT height);

    //! Inverts region
    //! @param[in] region
    //!     Region to invert
    //! @return
    //!     True when successful
    BOOL InvertRegion(HRGN region);

    //! Paints region
    //! @param[in] region
    //!     Region to paint
    //! @return
    //!     True when successful
    BOOL PaintRegion(HRGN region);

    //! Gets clipping box
    //! @param[out] rect
    //!     Clip box
    //! @return
    //!     Flags
    INT GetClipBox(uixRect& rect) const;

    //! Checks if point is visible
    //! @param[in] x
    //!     Left position
    //! @param[in] y
    //!     Top position
    //! @return
    //!     True when successful
    BOOL IsPointVisible(INT x, INT y);

    //! Checks if point is visible
    //! @param[in] point
    //!     Point to check
    //! @return
    //!     True when successful
    BOOL IsPointVisible(uixPoint point);

    //! Checks if rect is visible
    //! @param[in] rect
    //!     Rectangle to check
    //! @return
    //!     True when successful
    BOOL IsRectVisible(const uixRect& rect);

    //! Sets clipping region
    //! @param[in] region
    //!     Region to clip
    //! @return
    //!     Flags
    INT SetClipRegion(HRGN region);

    //! Exclude clip rect
    //! @param[in] left
    //!     Left position
    //! @param[in] top
    //!     Top position
    //! @param[in] right
    //!     Right position
    //! @param[in] bottom
    //!     Bottom position
    //! @return
    //!     Flags
    INT ExcludeClipRect(INT left, INT top, INT right, INT bottom);

    //! Exclude clip rect
    //! @param[in] rect
    //!     Rect to exclude
    //! @return
    //!     Flags
    INT ExcludeClipRect(const uixRect& rect);

    //! Exculde update region
    //! @param[in] window
    //!     Window region
    //! @return
    //!     Flags
    INT ExcludeUpdateRegion(HWND window);

    //! Intersect clip rect
    //! @param[in] left
    //!     Left position
    //! @param[in] top
    //!     Top position
    //! @param[in] right
    //!     Right position
    //! @param[in] bottom
    //!     Bottom position
    //! @return
    //!     Flags
    INT IntersectClipRect(INT left, INT top, INT right, INT bottom);

    //! Intersect clip rect
    //! @param[in] rect
    //!     Rectangle
    //! @return
    //!     Flags
    INT IntersectClipRect(const uixRect& rect);

    //! Offsets clip region
    //! @param[in] x
    //!     X position
    //! @param[in] y
    //!     Y position
    //! @return
    //!     Flags
    INT OffsetClipRegion(INT x, INT y);

    //! Offsets clip region
    //! @param[in] size
    //!     Size
    //! @return
    //!     Flags
    INT OffsetClipRegion(uixSize size);

    //! Selects clip region
    //! @param[in] region
    //!     Region
    //! @param[in] mode
    //!     Mode
    //! @return
    //!     Flags
    INT SelectClipRegion(HRGN region, uixRegionMode mode);

    //! Gets current pen position
    //! @param[out] position
    //!     Current position
    //! @return
    //!     True when successful
    BOOL GetCurrentPosition(uixPoint& position);

    //! Moves pen to position
    //! @param[in] x
    //!     Left position
    //! @param[in] y
    //!     Top position
    //! @param[out] result
    //!     Result position
    //! @return
    //!     True when successful
    BOOL MoveTo(INT x, INT y, uixPoint* result = NULLPTR);

    //! Moves pen to position
    //! @param[in] point
    //!     New position
    //! @param[out] result
    //!     Result position
    //! @return
    //!     True when successful
    BOOL MoveTo(uixPoint point, uixPoint* result = NULLPTR);

    //! Draw line to position
    //! @param[in] x
    //!     Left position
    //! @param[in] y
    //!     Top position
    //! @return
    //!     True when successful
    BOOL LineTo(INT x, INT y);

    //! Draw line to position
    //! @param[in] point
    //!     Destination position
    //! @return
    //!     True when successful
    BOOL LineTo(uixPoint point);

    //! Draws line
    //! @param[in] source
    //!     Source position
    //! @param[in] target
    //!     Target position
    //! @return
    //!     True when successful
    BOOL DrawLine(uixPoint source, uixPoint target);

    //! Draws line using color
    //! @param[in] source
    //!     Source position
    //! @param[in] target
    //!     Target position
    //! @param[in] color
    //!     Color
    //! @return
    //!     True when successful
    BOOL DrawLine(uixPoint source, uixPoint target, uixColor color);

    //! Fills solid rectangle
    //! @param[in] rect
    //!     Rectangle to fill
    //! @param[in] color
    //!     Color
    //! @return
    //!     True when successful
    BOOL FillSolidRect(const uixRect& rect, uixColor color);

    //! Fills solid rectangle
    //! @param[in] left
    //!     Left position
    //! @param[in] top
    //!     Top position
    //! @param[in] width
    //!     Width
    //! @param[in] height
    //!     Height
    //! @param[in] color
    //!     Color
    //! @return
    //!     True when successful
    BOOL FillSolidRect(INT left, INT top, INT width, INT height, uixColor color);

    //! Fills gradient
    //! @param[in] vertices
    //!     Pointer to array of vertices
    //! @param[in] verticesCount
    //!     Number of vertices
    //! @param[in] mesh
    //!     Mesh
    //! @param[in] meshCount
    //!     Number of mesh elements
    //! @param[in] mode
    //!     Draw mode
    //! @return
    //!     True when successful
    BOOL GradientFill(TRIVERTEX* vertices, ULONG verticesCount, void* mesh, ULONG meshCount,
                      DWORD mode);

    //! Fills gradient rectangle
    //! @param[in] start
    //!     Start color
    //! @param[in] stop
    //!     Stop color
    //! @param[in] rect
    //!     Rectangle to fill
    //! @param[in] horizontal
    //!     Horizontal or vertical gradient
    //! @return
    //!     True when successful
    BOOL GradientFillRect(uixColor start, uixColor stop, const uixRect& rect, BOOL horizontal);

    //! Fills gradient rectangle
    //! @param[in] start
    //!     Start color
    //! @param[in] stop
    //!     Stop color
    //! @param[in] startAlpha
    //!     Start alpha
    //! @param[in] stopAlpha
    //!     Stop alpha
    //! @param[in] rect
    //!     Rectangle to fill
    //! @param[in] horizontal
    //!     Horizontal or vertical gradient
    //! @return
    //!     True when successful
    BOOL GradientFillRect(uixColor start, uixColor stop, USHORT startAlpha, USHORT stopAlpha,
                          const uixRect& rect, BOOL horizontal);

    //! Draws 3D rectangle
    //! @param[in] left
    //!     Left position
    //! @param[in] top
    //!     Top position
    //! @param[in] width
    //!     Width
    //! @param[in] height
    //!     Height
    //! @param[in] colorTopLeft
    //!     Top left color
    //! @param[in] colorBottomRight
    //!     Bottom right color
    void DrawRect3D(INT left, INT top, INT width, INT height, uixColor colorTopLeft,
                    uixColor colorBottomRight);

    //! Draws 3D rectangle
    //! @param[in] rect
    //!     Rectangle
    //! @param[in] colorTopLeft
    //!     Top left color
    //! @param[in] colorBottomRight
    //!     Bottom right color
    void DrawRect3D(RECT& rect, uixColor colorTopLeft, uixColor colorBottomRight);

    //! Fills rectangle using brush
    //! @param[in] rect
    //!     Rectangle to fill
    //! @param[in] brush
    //!     Using brush
    //! @return
    //!     True when successful
    BOOL FillRect(const uixRect& rect, HBRUSH brush);

    //! Draws rect frame
    //! @param[in] rect
    //!     Rectangle frame
    //! @param[in] brush
    //!     Using brush
    //! @return
    //!     True when successful
    BOOL FrameRect(const uixRect& rect, HBRUSH brush);

    //! Inverts rectangle
    //! @param[in] rect
    //!     Rectangle to invert
    //! @return
    //!     True when successful
    BOOL InvertRect(const uixRect& rect);

    //! Draws icon
    //! @param[in] x
    //!     Left position
    //! @param[in] y
    //!     Top position
    //! @param[in] icon
    //!     Handle to icon
    //! @return
    //!     True when successful
    BOOL DrawIcon(INT x, INT y, HICON icon);

    //! Draws icon
    //! @param[in] point
    //!     Position
    //! @param[in] icon
    //!     Icon handle
    //! @return
    //!     True when successful
    BOOL DrawIcon(uixPoint point, HICON icon);

    //! Draws icon
    //! @param[in] x
    //!     Left position
    //! @param[in] y
    //!     Top positon
    //! @param[in] icon
    //!     Icon handle
    //! @param[in] width
    //!     Width
    //! @param[in] height
    //!     Height
    //! @param[in] stepIfAniCursor
    //!     If handle is animated cursor, go to stepIfAniCursor frame
    //! @param[in] flickerFreeDraw
    //!     Flicker free draw brush
    //! @param[in] flags
    //!     Draw flags
    //! @return
    //!     True when successful
    BOOL DrawIconEx(INT x, INT y, HICON icon, INT width, INT height, UINT stepIfAniCursor = 0,
                    HBRUSH flickerFreeDraw = NULLPTR, UINT flags = DI_NORMAL);

    //! Draws icon
    //! @param[in] point
    //!     Position
    //! @param[in] size
    //!     Size
    //! @param[in] icon
    //!     Icon handle
    //! @param[in] stepIfAniCursor
    //!     If handle is animated cursor, go to stepIfAniCursor frame
    //! @param[in] flickerFreeDraw
    //!     Flicker free draw brush
    //! @param[in] flags
    //!     Draw flags
    //! @return
    //!     True when successful
    BOOL DrawIconEx(uixPoint point, uixSize size, HICON icon, UINT stepIfAniCursor = 0,
                    HBRUSH flickerFreeDraw = NULLPTR, UINT flags = DI_NORMAL);

    //! Draw state
    //! @param[in] point
    //!     Position
    //! @param[in] size
    //!     Size
    //! @param[in] icon
    //!     Icon handle
    //! @param[in] flags
    //!     Flags
    //! @param[in] brush
    //!     Brush
    //! @return
    //!     True when successful
    BOOL DrawState(uixPoint point, uixSize size, HICON icon, UINT flags, HBRUSH brush);

    //! Draw state
    //! @param[in] point
    //!     Position
    //! @param[in] size
    //!     Size
    //! @param[in] bitmap
    //!     Bitmap handle
    //! @param[in] flags
    //!     Flags
    //! @param[in] brush
    //!     Brush
    //! @return
    //!     True when successful
    BOOL DrawState(uixPoint point, uixSize size, HBITMAP bitmap, UINT flags, HBRUSH brush);

    //! Draw state
    //! @param[in] point
    //!     Position
    //! @param[in] size
    //!     Size
    //! @param[in] text
    //!     Text
    //! @param[in] flags
    //!     Flags
    //! @param[in] prefixText
    //!     Previx Text
    //! @param[in] textLength
    //!     Text length
    //! @param[in] brush
    //!     Brush
    //! @return
    //!     True when successful
    BOOL DrawState(uixPoint point, uixSize size, const uixChar* text, UINT flags, BOOL prefixText,
                   INT textLength, HBRUSH brush);

    //! Draw state
    //! @param[in] point
    //!     Position
    //! @param[in] size
    //!     Size
    //! @param[in] proc
    //!     Draw State Procedure
    //! @param[in] data
    //!     Data
    //! @param[in] flags
    //!     Flags
    //! @param[in] brush
    //!     Brush
    //! @return
    //!     True when successful
    BOOL DrawState(uixPoint point, uixSize size, DRAWSTATEPROC proc, LPARAM data, UINT flags,
                   HBRUSH brush);

    //! Draws edge
    //! @param[in] rect
    //!     Rect to draw edges
    //! @param[in] edge
    //! @param[in] flags
    //! @return
    //!     True when successful
    BOOL DrawEdge(RECT& rect, uixDrawBorderEdge edge, uixDrawBorderFlags flags);

    //! Draws frame control
    //! @param[in] rect
    //!     Rectangle
    //! @param[in] type
    //!     Frame type
    //! @param[in] state
    //!     Frame state
    //! @return
    //!     True when successful
    BOOL DrawFrameControl(RECT& rect, uixDrawFrameType type, uixDrawFrameState state);

    //! Draws arc
    //! @param[in] x1
    //!     Left of TopLeft
    //! @param[in] y1
    //!     Top of TopLeft
    //! @param[in] x2
    //!     Right of BottomRight
    //! @param[in] y2
    //!     Bottom of BottomRight
    //! @param[in] x3
    //!     Left of start arc point
    //! @param[in] y3
    //!     Top of start arc point
    //! @param[in] x4
    //!     Left of end arc point
    //! @param[in] y4
    //!     Top of end arc point
    //! @return
    //!     True when successful
    BOOL Arc(INT x1, INT y1, INT x2, INT y2, INT x3, INT y3, INT x4, INT y4);

    //! Draws arc
    //! @param[in] rect
    //!     Arc area
    //! @param[in] start
    //!     Start point
    //! @param[in] end
    //!     End point
    //! @return
    //!     True when successful
    BOOL Arc(const uixRect& rect, uixPoint start, uixPoint end);

    //! Draws angle arc
    //! @param[in] x
    //!     Left position
    //! @param[in] y
    //!     Top position
    //! @param[in] radius
    //!     Radius
    //! @param[in] startAngle
    //!     Start angle
    //! @param[in] sweepAngle
    //!     Sweep angle
    //! @return
    //!     True when successful
    BOOL AngleArc(INT x, INT y, INT radius, FLOAT startAngle, FLOAT sweepAngle);

    BOOL ArcTo(INT x1, INT y1, INT x2, INT y2, INT x3, INT y3, INT x4, INT y4);
    BOOL ArcTo(const uixRect& rect, uixPoint start, uixPoint end);

    //! Gets arc direction
    //! @return
    //!     Current direction
    uixDCArcDirection GetArcDirection();

    //! Sets arc direction
    //! @param[in] direction
    //!     New arc direction
    //! @return
    //!     Current direction
    uixDCArcDirection SetArcDirection(uixDCArcDirection direction);

    //! Draws poly line
    //! @param[in] points
    //!     Array of points
    //! @param[in] count
    //!     Number of elements in points array
    //! @return
    //!     True when successful
    BOOL Polyline(const uixPoint points[], INT count);

    //! Draws poly line to
    //! @param[in] points
    //!     Array of points
    //! @param[in] count
    //!     Number of elements in points array
    //! @return
    //!     True when successful
    BOOL PolylineTo(const uixPoint points[], INT count);

    //! Draw poly
    //! @param[in] points
    //!     Array of points
    //! @param[in] types
    //!     Array of types. @see uixDCPolyType
    //! @param[in] count
    //!     Numer of elements in points and types
    //! @return
    //!     True when successful
    BOOL PolyDraw(const uixPoint points[], const BYTE types[], INT count);

    //! Draws poly line
    //! @param[in] points
    //!     Array of points
    //! @param[in] polyPoints
    //!     Poly points
    //! @param[in] count
    //!     Number of elements in points array
    //! @return
    //!     True when successful
    BOOL PolyPolyline(const uixPoint points[], const DWORD polyPoints[], INT count);

    //! Draws bezier poly
    //! @param[in] points
    //!     Array of points
    //! @param[in] count
    //!     Number of elements in points array
    //! @return
    //!     True when successful
    BOOL PolyBezier(const uixPoint points[], INT count);

    //! Draws poly bezier to
    //! @param[in] points
    //!     Array of points
    //! @param[in] count
    //!     Number of elements in points array
    //! @return
    //!     True when successful
    BOOL PolyBezierTo(const uixPoint points[], INT count);

    BOOL Chord(INT x1, INT y1, INT x2, INT y2, INT x3, INT y3, INT x4, INT y4);
    BOOL Chord(const uixRect& rect, uixPoint start, uixPoint end);

    //! Draws focus rect
    //! @param[in] rect
    //!     Rect
    //! @return
    //!     True when successful
    BOOL DrawFocusRect(const uixRect& rect);
    BOOL Ellipse(INT x1, INT y1, INT x2, INT y2);
    BOOL Ellipse(const uixRect& rect);
    BOOL Pie(INT x1, INT y1, INT x2, INT y2, INT x3, INT y3, INT x4, INT y4);
    BOOL Pie(const uixRect& rect, uixPoint start, uixPoint end);
    BOOL Polygon(const uixPoint points[], INT count);
    BOOL PolyPolygon(const uixPoint points[], const INT counts[], INT count);
    BOOL Rectangle(INT x1, INT y1, INT x2, INT y2);
    BOOL Rectangle(const uixRect& rect);
    BOOL RoundRect(INT x1, INT y1, INT x2, INT y2, INT xRadius, INT yRadius);
    BOOL RoundRect(const uixRect& rect, uixPoint radius);
    BOOL PatBlt(INT x, INT y, INT width, INT height, DWORD rop);
    BOOL PatBlt(const uixRect& rect, DWORD rop);
    BOOL BitBlt(INT x, INT y, INT width, INT height, HDC sourceDC, INT xSrc, INT ySrc, DWORD rop);
    BOOL BitBlt(const uixRect& rect, HDC sourceDC, uixPoint source, DWORD rop);
    BOOL StretchBlt(INT x, INT y, INT width, INT height,
                    HDC sourceDC, INT xSrc, INT ySrc, INT wSrc, INT hSrc, DWORD rop);
    BOOL StretchBlt(const uixRect& targetRC, HDC sourceDC, const uixRect& sourceRC, DWORD rop);
    BOOL MaskBlt(INT x, INT y, INT width, INT height, HDC sourceDC, INT xSrc, INT ySrc, HBITMAP mask,
                 INT xMask, INT yMask, DWORD rop);
    BOOL MaskBlt(const uixRect& rc, HDC sourceDC, uixPoint srcPt, HBITMAP mask, uixPoint maskPt,
                 DWORD rop);
    BOOL PlgBlt(const uixPoint* point, HDC sourceDC, INT xSrc, INT ySrc, INT width, INT height,
                HBITMAP mask, INT xMask, INT yMask);
    BOOL PlgBlt(const uixPoint* point, HDC sourceDC, uixPoint srcPt, uixSize size, HBITMAP mask,
                uixPoint maskPt);

    //! Gets pixel at position
    //! @param[in] x
    //!     Left position
    //! @param[in] y
    //!     Top position
    //! @return
    //!     Color at position
    uixColor GetPixel(INT x, INT y);

    //! Gets pixel at position
    //! @param[in] pt
    //!     Position
    //! @return
    //!     Color at position
    uixColor GetPixel(uixPoint pt);

    //! Sets pixel at position
    //! @param[in] x
    //!     Left position
    //! @param[in] y
    //!     Top position
    //! @param[in] color
    //!     Color to set
    //! @return
    //!     Color at position
    uixColor SetPixel(INT x, INT y, uixColor color);

    //! Sets pixel at position
    //! @param[in] pt
    //!     Position
    //! @param[in] color
    //!     Color to set
    //! @return
    //!     Color at position
    uixColor SetPixel(uixPoint pt, uixColor color);

    //! Sets pixel at position
    //! @param[in] x
    //!     Left position
    //! @param[in] y
    //!     Top position
    //! @param[in] color
    //!     Color to set
    //! @return
    //!     True when successful
    BOOL SetPixelV(INT x, INT y, uixColor color);

    //! Sets pixel at position
    //! @param[in] pt
    //!     Position
    //! @param[in] color
    //!     Color to set
    //! @return
    //!     True when successful
    BOOL SetPixelV(uixPoint pt, uixColor color);

    //! Flood Fill
    //! @param[in] x
    //!     Left position
    //! @param[in] y
    //!     Top position
    //! @param[in] color
    //!     Color to set
    //! @return
    //!     True when successful
    BOOL FloodFill(INT x, INT y, uixColor color);

    //! Flood Fill
    //! @param[in] pt
    //!     Position
    //! @param[in] color
    //!     Color to set
    //! @return
    //!     True when successful
    BOOL FloodFill(uixPoint pt, uixColor color);

    //! Flood Fill
    //! @param[in] x
    //!     Left position
    //! @param[in] y
    //!     Top position
    //! @param[in] color
    //!     Color to set
    //! @param[in] fillType
    //!     Fill type
    //! @return
    //!     True when successful
    BOOL FloodFillExt(INT x, INT y, uixColor color, UINT fillType);

    //! Flood Fill
    //! @param[in] pt
    //!     Position
    //! @param[in] color
    //!     Color to set
    //! @param[in] fillType
    //!     Fill type
    //! @return
    //!     True when successful
    BOOL FloodFillExt(uixPoint pt, uixColor color, UINT fillType);
    BOOL TextOut(INT x, INT y, const uixChar* text, INT count = -1);
    BOOL TextOut(uixPoint pt, const uixChar* text, INT count = -1);
    BOOL TextOutExt(INT x, INT y, UINT flags, const uixRect* rect, const uixChar* text, INT count = -1,
                    INT* widths = NULLPTR);
    BOOL TextOutExt(uixPoint pt, UINT flags, const uixRect* rect, const uixChar* text, INT count = -1,
                    INT* widths = NULLPTR);
    LONG TabbedTextOut(INT x, INT y, const uixChar* text, INT count = -1, INT tabPositions = 0,
                       INT* tabStopArray = NULLPTR, INT tabOrigin = 0);
    LONG TabbedTextOut(uixPoint pt, const uixChar* text, INT count = -1, INT tabPositions = 0,
                       INT* tabStopArray = NULLPTR, INT tabOrigin = 0);
    INT DrawText(const uixChar* text, INT count, RECT& rect, UINT format);
    INT DrawText(const uixChar* text, RECT& rect, UINT format = 0);
    INT DrawTextEx(uixChar* text, INT count, uixRect& rect, UINT format,
                   DRAWTEXTPARAMS* params = NULLPTR);
    BOOL GetTextExtent(const uixChar* text, INT count, uixSize& size);
    DWORD GetTabbedTextExtent(const uixChar* text, INT count = -1, INT tabPositions = 0,
                              INT* tabStopArray = NULLPTR);
    BOOL GrayString(HBRUSH brush, GRAYSTRINGPROC proc, LPARAM data, INT count, INT x, INT y, INT width,
                    INT height);

    //! Gets text align
    //! @return
    //!     Text align
    UINT GetTextAlign() const;

    //! Sets text align
    //! @param[in] flags
    //!     New align flags
    //! @return
    //!     Previous align flags
    UINT SetTextAlign(UINT flags);

    //! Gets text face
    //! @param[in] faceName
    //!     Name of face
    //! @param[in] count
    //!     Count
    //! @return
    //!     Face
    INT GetTextFace(uixChar* faceName, INT count);

    //! Gets text face length
    //! @return
    //!     Length
    INT GetTextFaceLength() const;

    //! Gets text metrics
    //! @param[out] params
    //!     Text metric
    //! @return
    //!     True when successful
    BOOL GetTextMetrics(TEXTMETRIC* params);

    //! Sets text justification
    //! @param[in] breakExtra
    //! @param[in] breakCount
    //! @return ?
    INT SetTextJustification(INT breakExtra, INT breakCount);

    //! Gets text character extra
    //! @return
    //!     Extra
    INT GetTextCharacterExtra();

    //! Sets text character extra
    //! @param[in] extra
    //!     Extra
    //! @return
    //!     Previuos extra
    INT SetTextCharacterExtra(INT extra);

    BOOL Scroll(INT dx, INT dy, const uixRect& rect, const uixRect& clip, HRGN regionUpdate,
                uixRect* rectUpdate);
    BOOL GetCharWidth(UINT firstChar, UINT lastChar, INT* buffer);
    BOOL GetCharWidth32(UINT firstChar, UINT lastChar, INT* buffer);
    DWORD SetMapperFlags(DWORD flags);
    BOOL GetAspectRatioFilter(uixSize& size);
    BOOL GetCharABCWidths(UINT firstChar, UINT lastChar, ABC* abc);
    DWORD GetFontData(DWORD table, DWORD offset, void* data, DWORD count);
    INT GetKerningPairs(INT pairs, KERNINGPAIR* pair);
    UINT GetOutlineTextMetrics(UINT cbData, OUTLINETEXTMETRIC* params);
    DWORD GetGlyphOutline(UINT uChar, UINT format, GLYPHMETRICS* glyph, DWORD cbBuffer, void* buffer,
                          MAT2* mat2);
    BOOL GetCharABCWidths(UINT firstChar, UINT lastChar, ABCFLOAT* abc);
    BOOL GetCharWidth(UINT firstChar, UINT lastChar, FLOAT* buffer);

    //! Aborts path
    //! @return
    //!     True when successful
    BOOL AbortPath();

    //! Begins path
    //! @return
    //!     True when successful
    BOOL BeginPath();

    //! Close path
    //! @return
    //!     True when successful
    BOOL CloseFigure();

    //! Ends path
    //! @return
    //!     True when successful
    BOOL EndPath();

    //! Fills path
    //! @return
    //!     True when successful
    BOOL FillPath();

    //! Flattern path
    //! @return
    //!     True when successful
    BOOL FlattenPath();

    //! Stroke and fill path
    //! @return
    //!     True when successful
    BOOL StrokeAndFillPath();

    //! Stroke path
    //! @return
    //!     True when successful
    BOOL StrokePath();

    //! Widen path
    //! @return
    //!     True when successful
    BOOL WidenPath();

    //! Gets miter limit
    //! @param[out] miterLimit
    //! @return
    //!     True when successful
    BOOL GetMiterLimit(FLOAT* miterLimit);

    //! Sets miter limit
    //! @param[in] miterLimit
    //! @return
    //!     True when successful
    BOOL SetMiterLimit(FLOAT miterLimit);

    //! Gets path
    //! @param[out] points
    //!     Path's points
    //! @param[out] types
    //!     Types
    //! @param[in] count
    //!     Number of elements in arrays
    //! @return
    //!     Number of enumerated points
    INT GetPath(uixPoint points[], BYTE types[], INT count);

    //! Sets clip path
    //! @param[in] mode
    //!     Mode
    //! @return
    //!     True when successful
    BOOL SelectClipPath(INT mode);

    //! Gets pen color
    //! @return
    //!     Pen color
    uixColor GetPenColor() const;

    //! Sets pen color
    //! @param[in] color
    //!     Pen color
    //! @return
    //!     Previous pen color
    uixColor SetPenColor(uixColor color);

    //! Gets brush color
    //! @return
    //!     Brush color
    uixColor GetBrushColor() const;

    //! Sets brush color
    //! @param[in] color
    //!     Brush color
    //! @return
    //!     Previous color
    uixColor SetBrushColor(uixColor color);

    DWORD GetFontUnicodeRanges(GLYPHSET* glyphset);
    DWORD GetGlyphIndices(const uixChar* text, INT count, WORD* pgi, DWORD flags);
    DWORD GetTextExtentPointI(WORD* pgi, INT count, uixSize* size);
    DWORD GetTextExtentExPointI(WORD* pgi, INT count, INT maxExtent, INT* fit, INT* alpDx,
                                uixSize* size);
    BOOL GetCharWidthI(UINT first, UINT cgi, WORD* pgi, INT* buffer);
    BOOL GetCharABCWidthsI(UINT first, UINT cgi, WORD* pgi, ABC* abc);


    BOOL AlphaBlend(const uixRect& targetRC, const uixRect& sourceRC, HDC sourceDC, BYTE alpha = 255,
                    BOOL blendAlpha = TRUE)
    {
        BLENDFUNCTION fn;
        fn.BlendOp = AC_SRC_OVER;
        fn.BlendFlags = 0;
        fn.SourceConstantAlpha = alpha;
        fn.AlphaFormat = blendAlpha ? AC_SRC_ALPHA : 0;

        return ::GdiAlphaBlend(m_Handle,
                               targetRC.Left(), targetRC.Top(),
                               targetRC.Width(), targetRC.Height(),
                               sourceDC,
                               sourceRC.Left(), sourceRC.Top(),
                               sourceRC.Width(), sourceRC.Height(),
                               fn);
    }
};

//! Print DC
class uixPrintDC : public uixDC
{
public:
    //! Starts document
    //! @param[in] docinfo
    //!     Document Info
    //! @return
    //!
    INT StartDoc(DOCINFO* docinfo);

    //! Starts page
    //! @return
    //!
    INT StartPage();

    //! Ends page
    //! @return
    //!
    INT EndPage();

    //! Sets abort procedure
    //! @param[in] proc
    //!     Abort procedure
    //! @return
    //!
    INT SetAbortProc(ABORTPROC proc);

    //! Abort document
    //! @return
    //!
    INT AbortDoc();

    //! End document
    //! @return
    //!
    INT EndDoc();
};

//! Client Window DC
//! @brief
//!     This DC allows you to paint on client window area
class uixClientDC : public uixDC
{
protected:
    HWND    m_Window;           //!< Window handle
public:
    //! Constructor
    //! @param[in] handle
    //!     Window handle
    uixClientDC(HWND handle);

    //! Destructor
    ~uixClientDC();
};

//! Memory DC
class uixMemoryDC : public uixDC
{
protected:
    HDC m_OriginalDC;           //!< Original DC
    uixRect m_PaintRect;        //!< Paint rect
    uixBitmap m_Bitmap;         //!< Bitmap DC
    HBITMAP m_PreviousBitmap;   //!< Previous bitmap
    BOOL    m_AutoBlit;         //!< Auto blit flag
public:
    //! Constructor
    //! @param[in] dc
    //!     Parent DC
    //! @param[in] rect
    //!     Area rect
    uixMemoryDC(HDC dc, uixRect& rect, BOOL autoBlit = TRUE);

    //! Destructor
    ~uixMemoryDC();
};

//! Paint DC
//! @brief
//!     Use this class to draw on client window area in OnPaint event handler
class uixPaintDC : public uixDC
{
protected:
    HWND            m_Window;   //!< Window handle
    PAINTSTRUCT     m_PS;       //!< Paint struct
public:
    //! Constructor
    //! @param[in] handle
    //!     Window handle
    uixPaintDC(HWND handle);

    //! Destructor
    ~uixPaintDC();

    //! Gets paint area
    //! @return
    //!     Paint area rectangle
    const uixRect GetPaintArea() const;

    //! Checks if painter needs erase
    //! @return
    //!     True when successful
    BOOL NeedErase() const;
};

class uixBufferDC : public uixPaintDC
{
private:
    HDC m_OutputDC;
    HDC m_AttributeDC;
    HDC m_MemoryDC;

    HBITMAP m_PaintBitmap;
    HBITMAP m_PreviousBitmap;

    uixRect m_ClientRect;
    BOOL    m_BoundsUpdated;

    void Flush();

public:
    uixBufferDC(HWND handle);
    ~uixBufferDC();

public:
    uixDCBounds SetBoundsRect(const uixRect* rect, uixDCBounds flags);
    virtual BOOL Restore(INT saved);
};

//! Window DC
//! @brief
//!     Use this class to draw on whole window
class uixWindowDC : public uixDC
{
protected:
    HWND    m_Window;       //!< Window handle
public:
    //! Constructor
    //! @param[in] handle
    //!     Window handle
    uixWindowDC(HWND handle);

    //! Destructor
    ~uixWindowDC();
};

//! Non client DC
class uixNonClientDC : public uixDC
{
protected:
    HWND        m_Window;
    HRGN        m_Region;
public:
    //! Constructor
    //! @param[in] window
    //!     Window handle
    //! @param[in] region
    //!     Region handle
    uixNonClientDC(HWND window, HRGN region);

    //! Destructor
    ~uixNonClientDC();
};
}
//----------------------------------------------------------------------------//
#include "uixgdidc.inl"
//----------------------------------------------------------------------------//
#endif /* _UIX_GDIDC_H__ */