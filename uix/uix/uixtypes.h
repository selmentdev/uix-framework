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
#ifndef _UIX_TYPES_H__
#define _UIX_TYPES_H__
//----------------------------------------------------------------------------//
#include "uixrequired.h"
//----------------------------------------------------------------------------//
namespace UIX
{
class uixPoint;
class uixSize;
class uixRect;

//! Size
class UIXAPI uixSize : public SIZE
{
public:
    //! Constructor
    uixSize();

    //! Constructor
    //! @param[in] width
    //!     Width
    //! @param[in] height
    //!     Height
    uixSize(LONG width, LONG height);

    //! Constructor
    //! @param[in] point
    //!     Point
    uixSize(POINT point);

    //! Constructor
    //! @param[in] size
    //!     Size
    uixSize(SIZE size);

    //! Constructor
    //! @param[in] size
    //!     Packed size
    uixSize(DWORD size);

    //! Gets width
    //! @return
    //!     Width
    LONG Width() const;

    //! Gets height
    //! @return
    //!     Height
    LONG Height() const;

    //! Sets width and height
    //! @param[in] width
    //!     Width
    //! @param[in] height
    //!     Height
    //! @return
    //!     This object
    uixSize& Set(LONG width, LONG height);

    //! Equality test
    //! @param[in] size
    //!     Comparand
    //! @return
    //!     True when successful
    BOOL Equals(SIZE size) const;

    //! Equality operator
    //! @param[in] size
    //!     Comparand
    //! @return
    //!     True when successful
    BOOL operator == (SIZE size) const;

    //! Inequality operator
    //! @param[in] size
    //!     Comparand
    //! @return
    //!     Thue when successful
    BOOL operator != (SIZE size) const;

    //! Adds size
    //! @param[in] size
    //!     Size to add
    //! @return
    //!     This object
    uixSize& operator += (SIZE size);

    //! Subs size
    //! @param[in] size
    //!     Size to subtract
    //! @return
    //!     This object
    uixSize& operator -= (SIZE size);

    //! Sums this and size
    //! @param[in] size
    //!     Size to sum
    //! @return
    //!     Sum of this and size
    uixSize operator + (SIZE size) const;

    //! Subtract this and size
    //! @param[in] size
    //!     Size to subtract
    //! @return
    //!     Subtract of this and size
    uixSize operator - (SIZE size) const;

    //! Negative
    //! @return
    //!     Negative value
    uixSize operator - () const;

    //! Sum this and point
    //! @param[in] point
    //!     Point to sum
    //! @return
    //!     Sum of this and point
    uixPoint operator + (POINT point) const;

    //! Subtract this and point
    //! @param[in] point
    //!     Point to subtract
    //! @return
    //!     Subtract of this and point
    uixPoint operator - (POINT point) const;
};

//! Point
class UIXAPI uixPoint : public POINT
{
public:
    //! Constructor
    uixPoint();

    //! Constructor
    //! @param[in] left
    //!     Left
    //! @param[in] top
    //!     Top
    uixPoint(LONG left, LONG top);

    //! Constructor
    //! @param[in] point
    //!     Point
    uixPoint(POINT point);

    //! Constructor
    //! @param[in] size
    //!     Size
    uixPoint(SIZE size);

    //! Constructor
    //! @param[in] point
    //!     Raw point
    uixPoint(DWORD point);

    //! Gets left value
    //! @return
    //!     Left coordinate
    LONG Left() const;

    //! Gets top value
    //! @return
    //!     Top coordinate
    LONG Top() const;

    //! Sets values
    //! @param[in] left
    //!     Left coord
    //! @param[in] top
    //!     Top coord
    //! @return
    //!     This object
    uixPoint& Set(LONG left, LONG top);

    //! Test equality
    //! @param[in] point
    //!     Comparand
    //! @return
    //!     True when successful
    BOOL Equals(POINT point) const;

    //! Equality operator
    //! @param[in] point
    //!     Comparand
    //! @return
    //!     True when successful
    BOOL operator == (POINT point) const;

    //! Inequality operator
    //! @param[in] point
    //!     Comparand
    //! @return
    //!     True when successful
    BOOL operator != (POINT point) const;

    //! Adds size
    //! @param[in] size
    //!     Size
    //! @return
    //!     This object
    uixPoint& operator += (SIZE size);

    //! Subtracts size
    //! @param[in] size
    //!     Size
    //! @return
    //!     This object
    uixPoint& operator -= (SIZE size);

    //! Adds point
    //! @param[in] point
    //!     Point
    //! @return
    //!     This object
    uixPoint& operator += (POINT point);

    //! Subtracts point
    //! @param[in] point
    //!     Point
    //! @return
    //!     This object
    uixPoint& operator -= (POINT point);

    //! Sum of this and size
    //! @param[in] size
    //!     Size
    //! @return
    //!     Sum of this and size
    uixPoint operator + (SIZE size) const;

    //! Subtract of this and size
    //! @param[in] size
    //!     Size
    //! @return
    //!     Subtract of this and size
    uixPoint operator - (SIZE size) const;

    //! Negative value
    //! @return
    //!     Negative value
    uixPoint operator - () const;

    //! Sum of this and point
    //! @param[in] point
    //!     Point
    //! @return
    //!     New point
    uixPoint operator + (POINT point) const;

    //! Subtract of this and point
    //! @param[in] point
    //!     Point
    //! @return
    //!     Size
    uixSize operator - (POINT point) const;
};

//! Rectangle
//! @note implemented
class UIXAPI uixRect : public RECT
{
public:
    //! Constructor
    uixRect();

    //! Constructor
    //! @param[in] left
    //!     Left coord
    //! @param[in] top
    //!     Top coord
    //! @param[in] right
    //!     Right coord
    //! @param[in] bottom
    //!     Bottom coord
    uixRect(LONG left, LONG top, LONG right, LONG bottom);

    //! Constructor
    //! @param[in] rect
    //!     Rect
    uixRect(const RECT& rect);

    //! Constructor
    //! @param[in] point
    //!     Position
    //! @param[in] size
    //!     Size of rect
    uixRect(POINT point, SIZE size);

    //! Constructor
    //! @param[in] topLeft
    //!     Top Left point
    //! @param[in] bottomRight
    //!     Bottom Right point
    uixRect(POINT topLeft, POINT bottomRight);

    //! Gets Left coordinate
    //! @return
    //!     Left coord
    LONG Left() const;

    //! Gets Top coordinate
    //! @return
    //!     Top coord
    LONG Top() const;

    //! Gets Right coordinate
    //! @return
    //!     Right coord
    LONG Right() const;

    //! Gets Bottom coordinate
    //! @return
    //!     Bottom coord
    LONG Bottom() const;

    //! Gets width of rect
    //! @return
    //!     Width
    LONG Width() const;

    //! Gets height of rect
    //! @return
    //!     Height
    LONG Height() const;

    //! Gets size of rect
    //! @return
    //!     Size
    uixSize Size() const;

    //! Gets top left point
    //! @return
    //!     Top left point
    uixPoint& TopLeft();

    //! Gets bottom right point
    //! @return
    //!     Bottom right point
    uixPoint& BottomRight();

    //! Gets top left point
    //! @return
    //!     Top left point
    const uixPoint& TopLeft() const;

    //! Gets bottom right point
    //! @return
    //!     Bottom right point
    const uixPoint& BottomRight() const;

    //! Gets center point of rect
    //! @return
    //!     Center point
    uixPoint CenterPoint() const;

    //! Sets coordinates
    //! @param[in] left
    //!     Left coordinate
    //! @param[in] top
    //!     Top coordinate
    //! @param[in] right
    //!     Right coordinate
    //! @param[in] bottom
    //!     Bottom coordinate
    //! @return
    //!     This object
    uixRect& Set(LONG left, LONG top, LONG right, LONG bottom);

    //! Sets from points
    //! @param[in] topLeft
    //!     Top left point
    //! @param[in] rightBottom
    //!     Right bottom point
    //! @return
    //!     This object
    uixRect& Set(POINT topLeft, POINT rightBottom);

    //! Sets rect to empty
    //! @return
    //!     This object
    uixRect& SetEmpty();

    //! Equals test
    //! @param[in] rect
    //!     Comparand
    //! @return
    //!     True when successful
    BOOL Equals(const RECT& rect) const;

    //! Equality operator
    //! @param[in] rect
    //!     Comparand
    //! @return
    //!     True when successful
    BOOL operator == (const RECT& rect) const;

    //! Inequality operator
    //! @param[in] rect
    //!     Comparand
    //! @return
    //!     True when successful
    BOOL operator != (const RECT& rect) const;

    //! Tests if rect is empty
    //! @return
    //!     True when successful
    BOOL IsEmpty() const;

    //! Tests if rect is null
    //! @return
    //!     True when successful
    BOOL IsNull() const;

    //! Tests if point is in rect
    //! @param[in] point
    //!     Point
    //! @return
    //!     True when successful
    BOOL PtInRect(POINT point) const;

    //! Copy rect from another
    //! @param[in] rect
    //!     Rect to copy
    //! @return
    //!     This object
    uixRect& CopyFrom(RECT& rect);

    //! Copy rect from another
    //! @param[in] rect
    //!     Rect to copy
    //! @return
    //!     This object
    uixRect& CopyFrom(RECT* rect);

    //! Infalte rect by values
    //! @param[in] x
    //!     Left
    //! @param[in] y
    //!     Top
    //! @return
    //!     This object
    uixRect& Inflate(INT x, INT y);

    //! Infalte rect by values
    //! @param[in] size
    //!     Size
    //! @return
    //!     This object
    uixRect& Inflate(SIZE size);

    //! Infalte rect by values
    //! @param[in] rect
    //!     Rect
    //! @return
    //!     This object
    uixRect& Inflate(RECT rect);

    //! Infalte rect by values
    //! @param[in] l
    //!     Left
    //! @param[in] t
    //!     Top
    //! @param[in] r
    //!     Right
    //! @param[in] b
    //!     Bottom
    //! @return
    //!     This object
    uixRect& Inflate(INT l, INT t, INT r, INT b);

    //! Defalte rect by values
    //! @param[in] x
    //!     Left
    //! @param[in] y
    //!     Top
    //! @return
    //!     This object
    uixRect& Deflate(INT x, INT y);

    //! Defalte rect by values
    //! @param[in] size
    //!     Size
    //! @return
    //!     This object
    uixRect& Deflate(SIZE size);

    //! Defalte rect by values
    //! @param[in] rect
    //!     Rect
    //! @return
    //!     This object
    uixRect& Deflate(RECT rect);

    //! Defalte rect by values
    //! @param[in] l
    //!     Left
    //! @param[in] t
    //!     Top
    //! @param[in] r
    //!     Right
    //! @param[in] b
    //!     Bottom
    //! @return
    //!     This object
    uixRect& Deflate(INT l, INT t, INT r, INT b);

    //! Offsets rect
    //! @param[in] x
    //!     Width
    //! @param[in] y
    //!     Height
    //! @return
    //!     This object
    uixRect& Offset(INT x, INT y);

    //! Offsets rect
    //! @param[in] pt
    //!     Point
    //! @return
    //!     This object
    uixRect& Offset(POINT pt);

    //! Offsets rect
    //! @param[in] size
    //!     Size
    //! @return
    //!     This object
    uixRect& Offset(SIZE size);

    //! Intersects two rects
    //! @param[in] lhs
    //!     Left rect
    //! @param[in] rhs
    //!     Right rect
    //! @return
    //!     True when intersect
    BOOL Intersect(const RECT* lhs, const RECT* rhs);

    //! Intersects two rects
    //! @param[in] lhs
    //!     Left rect
    //! @param[in] rhs
    //!     Right rect
    //! @return
    //!     True when intersect
    BOOL Intersect(const RECT& lhs, const RECT& rhs);

    //! Union two rects
    //! @param[in] lhs
    //!     Left rect
    //! @param[in] rhs
    //!     Right rect
    //! @return
    //!     True when union
    BOOL Union(const RECT* lhs, const RECT* rhs);

    //! Union two rects
    //! @param[in] lhs
    //!     Left rect
    //! @param[in] rhs
    //!     Right rect
    //! @return
    //!     True when union
    BOOL Union(const RECT& lhs, const RECT& rhs);

    uixRect& operator = (const RECT& rhs);
    uixRect& operator += (POINT pt);
    uixRect& operator -= (POINT pt);
    uixRect& operator += (SIZE size);
    uixRect& operator -= (SIZE size);
    uixRect& operator += (const RECT& rect);
    uixRect& operator -= (const RECT& rect);

    uixRect& operator &= (const RECT& rect);
    uixRect& operator |= (const RECT& rect);

    uixRect operator + (POINT pt) const;
    uixRect operator - (POINT pt) const;
    uixRect operator + (SIZE size) const;
    uixRect operator - (SIZE size) const;

    //! Subtract
    //! @param[in] lhs
    //!     Left rect
    //! @param[in] rhs
    //!     Right rect
    //! @return
    //!     Difference between two rects
    uixRect Subtract(const RECT* lhs, const RECT* rhs);

    //! Subtract
    //! @param[in] lhs
    //!     Left rect
    //! @param[in] rhs
    //!     Right rect
    //! @return
    //!     Difference between two rects
    uixRect Subtract(const RECT& lhs, const RECT& rhs);

    //! Intersection operator
    //! @param[in] rc
    //!     With rect
    //! @return
    //!     Intersection result
    uixRect operator & (const RECT& rc);

    //! Union operator
    //! @param[in] rc
    //!     With rect
    //! @return
    //!     Union result
    uixRect operator | (const RECT& rc);
};

//! Char type
typedef TCHAR uixChar;
//! String
typedef std::basic_string<TCHAR> uixString;
//! WString
typedef std::basic_string<wchar_t> uixWString;
//! CString
typedef std::basic_string<char> uixCString;

//! Color Reference
typedef COLORREF uixColorRef;

//! Color
struct uixColor
{
#pragma warning(push)
#pragma warning(disable : 4201)
    union
    {
        uixColorRef colorref;   //!< Ref value
        struct
        {
            BYTE red;           //!< Red
            BYTE green;         //!< Green
            BYTE blue;          //!< Blue
            BYTE alpha;         //!< Alpha
        };
    };
#pragma warning(pop)

    //! Constructor
    uixColor()
    {
    }

    //! Constructor
    //! @param[in] r
    //!     Red value
    //! @param[in] g
    //!     Green value
    //! @param[in] b
    //!     Blue value
    uixColor(BYTE r, BYTE g, BYTE b)
        : red(r)
        , green(g)
        , blue(b)
        , alpha(0)
    {
    }

    //! Constructor
    //! @param[in] color
    //!     Color
    uixColor(uixColorRef color)
        : colorref(color)
    {
    }

    //! Copy Constructor
    //! @param[in] color
    //!     Copied object
    uixColor(const uixColor& color)
        : colorref(color.colorref)
    {
    }

    //! Cast operator
    //! @return
    //!     Color reference value
    operator uixColorRef () const
    {
        return colorref;
    }

    //! Assigment operator
    //! @param[in] color
    //!     New color
    //! @return
    //!     This color object
    uixColor& operator = (const uixColor& color)
    {
        /**
        @note
            CPPCheck warns that red, green, blue and alpha are not assigned.
            They won't be because they are fields of union
        */
        colorref = color.colorref;
        return (*this);
    }

    //! Assigment operator
    //! @param[in] color
    //!     Color reference value
    //! @return
    //!     This color object
    uixColor& operator = (uixColorRef color)
    {
        /**
        @note
            CPPCheck warns that red, green, blue and alpha are not assigned.
            They won't be because they are fields of union
        */
        colorref = color;
        return (*this);
    }
};

//! System Color
enum uixSystemColor
{
    uixSystemColor_ScrollBar = COLOR_SCROLLBAR,
    uixSystemColor_Background = COLOR_BACKGROUND,
    uixSystemColor_ActiveCaption = COLOR_ACTIVECAPTION,
    uixSystemColor_InactiveCaption = COLOR_INACTIVECAPTION,
    uixSystemColor_Menu = COLOR_MENU,
    uixSystemColor_Window = COLOR_WINDOW,
    uixSystemColor_WindowFrame = COLOR_WINDOWFRAME,
    uixSystemColor_MenuText = COLOR_MENUTEXT,
    uixSystemColor_WindowText = COLOR_WINDOWTEXT,
    uixSystemColor_CaptionText = COLOR_CAPTIONTEXT,
    uixSystemColor_ActiveBorder = COLOR_ACTIVEBORDER,
    uixSystemColor_InactiveBorder = COLOR_INACTIVEBORDER,
    uixSystemColor_AppWorkspace = COLOR_APPWORKSPACE,
    uixSystemColor_Highlight = COLOR_HIGHLIGHT,
    uixSystemColor_HighlightText = COLOR_HIGHLIGHTTEXT,
    uixSystemColor_ButtonFace = COLOR_BTNFACE,
    uixSystemColor_ButtonShadow = COLOR_BTNSHADOW,
    uixSystemColor_GrayText = COLOR_GRAYTEXT,
    uixSystemColor_ButtonText = COLOR_BTNTEXT,
    uixSystemColor_InactiveCaptionText = COLOR_INACTIVECAPTIONTEXT,
    uixSystemColor_ButtonHighlight = COLOR_BTNHIGHLIGHT,
    uixSystemColor_3DDarkShadow = COLOR_3DDKSHADOW,
    uixSystemColor_3DLight = COLOR_3DLIGHT,
    uixSystemColor_InfoText = COLOR_INFOTEXT,
    uixSystemColor_InfoBackground = COLOR_INFOBK,
    uixSystemColor_HotLight = COLOR_HOTLIGHT,
    uixSystemColor_GradientActiveCaption = COLOR_GRADIENTACTIVECAPTION,
    uixSystemColor_GradientInactiveCaption = COLOR_GRADIENTINACTIVECAPTION,
    uixSystemColor_MenuHighlight = COLOR_MENUHILIGHT,
    uixSystemColor_MenuBar = COLOR_MENUBAR,
    uixSystemColor_Desktop = COLOR_DESKTOP,
};

//! Resource Name
typedef const uixChar* uixResourceName;

//! Resource ID
typedef UINT uixResourceID;

//! Window ID
typedef int uixWindowID;

//! Window ID values
enum uixID
{
    uixID_ANY               = -1,
    uixID_OK                = IDOK,
    uixID_CANCEL            = IDCANCEL,
    uixID_ABORT             = IDABORT,
    uixID_RETRY             = IDRETRY,
    uixID_IGNORE            = IDIGNORE,
    uixID_YES               = IDYES,
    uixID_NO                = IDNO,
    uixID_CLOSE             = IDCLOSE,
    uixID_HELP              = IDHELP,
    uixID_TRYAGAIN          = IDTRYAGAIN,
    uixID_CONTINUE          = IDCONTINUE,
    uixID_LAST,
};

//! Control color type
enum uixControlColorType
{
    uixControlColorType_MsgBox = 0,
    uixControlColorType_Edit,
    uixControlColorType_ListBox,
    uixControlColorType_Button,
    uixControlColorType_Dialog,
    uixControlColorType_ScrollBar,
    uixControlColorType_Static,
};

//! @todo Implement
class uixPrintDialog;

//! @todo Implement
class uixFontDialog;

//! Formats string
//! @param[out] result
//!     Result string
//! @param[in] format
//!     Format string
//! @return
//!     True when successful
UIXINLINE BOOL UixFormatString(uixCString& result, const CHAR* format, ...);

//! Formats string
//! @param[out] result
//!     Result string
//! @param[in] format
//!     Format string
//! @return
//!     True when successful
UIXINLINE BOOL UixFormatString(uixWString& result, const WCHAR* format, ...);

//! Formats string
//! @param[out] result
//!     Result string
//! @param[in] format
//!     Format string
//! @param[in] args
//!     Variadic args
//! @return
//!     True when successful
UIXINLINE BOOL UixFormatStringArgs(uixCString& result, const CHAR* format, va_list args);

//! Formats string
//! @param[out] result
//!     Result string
//! @param[in] format
//!     Format string
//! @param[in] args
//!     Variadic args
//! @return
//!     True when successful
UIXINLINE BOOL UixFormatStringArgs(uixWString& result, const WCHAR* format, va_list args);
}
//----------------------------------------------------------------------------//
#include "uixtypes.inl"
//----------------------------------------------------------------------------//
#endif /* _UIX_TYPES_H__ */