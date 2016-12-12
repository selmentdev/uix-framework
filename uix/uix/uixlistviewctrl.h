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
#ifndef _UIX_LISTVIEWCTRL_H__
#define _UIX_LISTVIEWCTRL_H__
//----------------------------------------------------------------------------//
#include "uixwindow.h"
//----------------------------------------------------------------------------//
namespace UIX
{
//! Handle begin drag
#define uixEVT_LVN_BEGINDRAG(Identifier, Handler) \
    uixEVT_NOTIFY(LVN_BEGINDRAG, Identifier, Handler)

//! Handle begin label edit
#define uixEVT_LVN_BEGINLABELEDIT(Identifier, Handler) \
    uixEVT_NOTIFY(LVN_BEGINLABELEDIT, Identifier, Handler)

//! Handle begin rdrag
#define uixEVT_LVN_BEGINRDRAG(Identifier, Handler) \
    uixEVT_NOTIFY(LVN_BEGINRDRAG, Identifier, Handler)

//! Handle begin scroll
#define uixEVT_LVN_BEGINSCROLL(Identifier, Handler) \
    uixEVT_NOTIFY(LVN_BEGINSCROLL, Identifier, Handler)

//! Handle column click
#define uixEVT_LVN_COLUMNCLICK(Identifier, Handler) \
    uixEVT_NOTIFY(LVN_COLUMNCLICK, Identifier, Handler)

//! Handle column drop down
#define uixEVT_LVN_COLUMNDROPDOWN(Identifier, Handler) \
    uixEVT_NOTIFY(LVN_COLUMNDROPDOWN, Identifier, Handler)

//! Handle column overflow click
#define uixEVT_LVN_COLUMNOVERFLOWCLICK(Identifier, Handler) \
    uixEVT_NOTIFY(LVN_COLUMNOVERFLOWCLICK, Identifier, Handler)

//! Handle delete all items
#define uixEVT_LVN_DELETEALLITEMS(Identifier, Handler) \
    uixEVT_NOTIFY(LVN_DELETEALLITEMS, Identifier, Handler)

//! Handle delete item
#define uixEVT_LVN_DELETEITEM(Identifier, Handler) \
    uixEVT_NOTIFY(LVN_DELETEITEM, Identifier, Handler)

//! Handle end label edit
#define uixEVT_LVN_ENDLABELEDIT(Identifier, Handler) \
    uixEVT_NOTIFY(LVN_ENDLABELEDIT, Identifier, Handler)

//! Handle end scroll
#define uixEVT_LVN_ENDSCROLL(Identifier, Handler) \
    uixEVT_NOTIFY(LVN_ENDSCROLL, Identifier, Handler)

//! Handle get display info
#define uixEVT_LVN_GETDISPINFO(Identifier, Handler) \
    uixEVT_NOTIFY(LVN_GETDISPINFO, Identifier, Handler)

//! Handle get empty markup
#define uixEVT_LVN_GETEMPTYMARKUP(Identifier, Handler) \
    uixEVT_NOTIFY(LVN_GETEMPTYMARKUP, Identifier, Handler)

//! Handle get info tip
#define uixEVT_LVN_GETINFOTIP(Identifier, Handler) \
    uixEVT_NOTIFY(LVN_GETINFOTIP, Identifier, Handler)

//! Handle hot track
#define uixEVT_LVN_HOTTRACK(Identifier, Handler) \
    uixEVT_NOTIFY(LVN_HOTTRACK, Identifier, Handler)

//! Handle incremental search
#define uixEVT_LVN_INCREMENTALSEARCH(Identifier, Handler) \
    uixEVT_NOTIFY(LVN_INCREMENTALSEARCH, Identifier, Handler)

//! Handle insert item
#define uixEVT_LVN_INSERTITEM(Identifier, Handler) \
    uixEVT_NOTIFY(LVN_INSERTITEM, Identifier, Handler)

//! Handle item activate
#define uixEVT_LVN_ITEMACTIVATE(Identifier, Handler) \
    uixEVT_NOTIFY(LVN_ITEMACTIVATE, Identifier, Handler)

//! Handle item changed
#define uixEVT_LVN_ITEMCHANGED(Identifier, Handler) \
    uixEVT_NOTIFY(LVN_ITEMCHANGED, Identifier, Handler)

//! Handle item changing
#define uixEVT_LVN_ITEMCHANGING(Identifier, Handler) \
    uixEVT_NOTIFY(LVN_ITEMCHANGING, Identifier, Handler)

//! Handle key down
#define uixEVT_LVN_KEYDOWN(Identifier, Handler) \
    uixEVT_NOTIFY(LVN_KEYDOWN, Identifier, Handler)

//! Handle link click
#define uixEVT_LVN_LINKCLICK(Identifier, Handler) \
    uixEVT_NOTIFY(LVN_LINKCLICK, Identifier, Handler)

//! Handle marquee begin
#define uixEVT_LVN_MARQUEEBEGIN(Identifier, Handler) \
    uixEVT_NOTIFY(LVN_MARQUEEBEGIN, Identifier, Handler)

//! Handle od cache hint
#define uixEVT_LVN_ODCACHEHINT(Identifier, Handler) \
    uixEVT_NOTIFY(LVN_ODCACHEHINT, Identifier, Handler)

//! Handle od find item
#define uixEVT_LVN_ODFINDITEM(Identifier, Handler) \
    uixEVT_NOTIFY(LVN_ODFINDITEM, Identifier, Handler)

//! Handle od state changed
#define uixEVT_LVN_ODSTATECHANGED(Identifier, Handler) \
    uixEVT_NOTIFY(LVN_ODSTATECHANGED, Identifier, Handler)

//! Handle set display info
#define uixEVT_LVN_SETDISPINFO(Identifier, Handler) \
    uixEVT_NOTIFY(LVN_SETDISPINFO, Identifier, Handler)

//! List View Item
struct uixListViewItem : LVITEM
{
    //! Constructor
    uixListViewItem();

    //! Gets mask
    //! @return
    //!     Mask
    DWORD GetMask() const;

    //! Sets mask
    //! @param[in] value
    //!     Mask
    void SetMask(DWORD value);

    //! Gets item ID
    //! @return
    //!     Item ID
    INT GetItem() const;

    //! Sets item ID
    //! @param[in] value
    //!     Item ID
    void SetItem(INT value);

    //! Gets sub item index
    //! @return
    //!     Sub item index
    INT GetSubItem() const;

    //! Sets sub item index
    //! @param[in] value
    //!     Sub item index
    void SetSubItem(INT value);

    //! Gets item state
    //! @return
    //!     State
    UINT GetState() const;

    //! Sets item state
    //! @param[in] value
    //!     Ite mstae
    void SetState(UINT value);

    //! Gets state mask
    //! @return
    //!     State mask
    UINT GetStateMask() const;

    //! Sets state mask
    //! @param[in] value
    //!     State mask
    void SetStateMask(UINT value);

    //! Gets text
    //! @return
    //!     Text
    const uixChar* GetText() const;

    //! Sets text
    //! @param[in] text
    //!     Text
    void SetText(const uixChar* text);

    //! Sets text
    //! @param[in] text
    //!     Text
    //! @param[in] length
    //!     Text length
    void SetText(const uixChar* text, INT length);

    //! Gets text length
    //! @return
    //!     Text length
    INT GetTextLength() const;

    //! Sets text length
    //! @param[in] length
    //!     Text length
    void SetTextLength(INT length);

    //! Gets item image index
    //! @return
    //!     Item image index
    INT GetImage() const;

    //! Sets item image index
    //! @param[in] value
    //!     Item image index
    void SetImage(INT value);

    //! Gets item data
    //! @return
    //!     Item data
    const void* GetData() const;

    //! Sets item data
    //! @param[in] value
    //!     Item data
    void SetData(const void* value);

    //! Gets item indent
    //! @return
    //!     Indent
    INT GetIndent() const;

    //! Sets item indent
    //! @param[in] value
    //!     Indent
    void SetIndent(INT value);

    //! Gets group ID
    //! @return
    //!     Group ID
    INT GetGroupID() const;

    //! Sets group ID
    //! @param[in] value
    //!     Group ID
    void SetGroupID(INT value);
};

//! List view column
struct uixListViewColumn : LVCOLUMN
{
    //! Constructor
    uixListViewColumn();

    //! Gets mark
    //! @return
    //!     Mask
    DWORD GetMask() const;

    //! Sets mask
    //! @param[in] value
    //!     Mask
    void SetMask(DWORD value);

    //! Gets format
    //! @return
    //!     Format
    INT GetFormat() const;

    //! Sets format
    //! @param[in] value
    //!     Format
    void SetFormat(INT value);

    //! Gets width
    //! @return
    //!     Width
    INT GetWidth() const;

    //! Gets text
    //! @return
    //!     Text
    const uixChar* GetText() const;

    //! Sets text
    //! @param[in] text
    //!     Text
    void SetText(const uixChar* text);

    //! Sets text
    //! @param[in] text
    //!     Text
    //! @param[in] length
    //!     Text length
    void SetText(const uixChar* text, INT length);

    //! Gets text length
    //! @return
    //!     Text length
    INT GetTextLength() const;

    //! Sets text length
    //! @param[in] length
    //!     Text length
    void SetTextLenght(INT length);

    //! Gets sub item index
    //! @return
    //!     Sub item index
    INT GetSubItem() const;

    //! Sets sub item index
    //! @param[in] value
    //!     Sub item index
    void SetSubItem(INT value);

    //! Gets image index
    //! @return
    //!     Image index
    INT GetImage() const;

    //! Sets image index
    //! @param[in] value
    //!     Image index
    void SetImage(INT value);

    //! Gets order index
    //! @return
    //!     Order index
    INT GetOrder() const;

    //! Sets order
    //! @param[in] value
    //!     Order index
    void SetOrder(INT value);

    //! Gets min width
    //! @return
    //!     Width
    INT GetMinWidth() const;

    //! Sets min width
    //! @param[in] value
    //!     Min width
    void SetMinWidth(INT value);

    //! Gets default width
    //! @return
    //!     Default width
    INT GetDefaultWidth() const;

    //! Sets default width
    //! @param[in] value
    //!     Default width
    void SetDefaultWidth(INT value);

    //! Gets ideal width
    //! @return
    //!     Ideal width
    INT GetIdealWidth() const;

    //! Sets ideal width
    //! @param[in] value
    //!     Ideal width
    void SetIdealWidth(INT value);

    void SetWidth(INT value)
    {
        mask |= LVCF_WIDTH;
        cx = value;
    }
};

//! List View background image
struct uixListViewBackgroundImage : LVBKIMAGE
{
    //! Constructor
    uixListViewBackgroundImage();

    //! Gets X offset
    //! @return
    //!     X offset
    INT GetXOffset() const;

    //! Gets Y offset
    //! @return
    //!     Y offset
    INT GetYOffset() const;

    //! Sets offset
    //! @param[in] x
    //!     X offset
    //! @param[in] y
    //!     Y offset
    void SetOffset(INT x, INT y);

    //! Sets image from bitmap handle
    //! @param[in] handle
    //!     Bitmap handle
    void FromHandle(HBITMAP handle);

    //! Sets image from Url
    //! @param[in] url
    //!     Url to image
    void FromUrl(const uixChar* url);

    //! Sets empty image
    void FromEmpty();

    //! Sets style
    //! @param[in] tile
    //!     Image is tiled?
    void SetStyle(BOOL tile);

    //! Sets watermark
    //! @param[in] value
    //!     Specify watermark
    void SetWatermark(BOOL value);

    //! Sets alpha blend
    //! @param[in] value
    //!     Specify alpha blend
    void SetAlphaBlend(BOOL value);
};

//! Footer item
struct uixListViewFooterItem : LVFOOTERITEM
{
};

//! Footer info
struct uixListViewFooterInfo : LVFOOTERINFO
{
};

//! List view group
struct uixListViewGroup : LVGROUP
{
};

//! List view tile info
struct uixListViewTileInfo : LVTILEINFO
{
};

//! List view tile view info
struct uixListViewTileViewInfo : LVTILEVIEWINFO
{
};

//! List view insert group sorted
struct uixListViewInsertGroupSorted : LVINSERTGROUPSORTED
{
};

//! List View find info
struct uixListViewFindInfo : LVFINDINFO
{
};

//! List view hit test
struct uixListViewHitTest : LVHITTESTINFO
{
};

//! List view control styles
enum uixListViewStyle
{
    //! Align left
    uixListViewStyle_AlignLeft = LVS_ALIGNLEFT,
    //! Align mask
    uixListViewStyle_AlignMask = LVS_ALIGNMASK,
    //! Align top
    uixListViewStyle_AlignTop = LVS_ALIGNTOP,
    //! Auto arrange
    uixListViewStyle_AutoArrange = LVS_AUTOARRANGE,
    //! Icon
    uixListViewStyle_Icon = LVS_ICON,
    //! List
    uixListViewStyle_List = LVS_LIST,
    //! Report
    uixListViewStyle_Report = LVS_REPORT,
    //! Small icon
    uixListViewStyle_SmallIcon = LVS_SMALLICON,
    //! No column header
    uixListViewStyle_NoColumnHeader = LVS_NOCOLUMNHEADER,
    //! No label wrap
    uixListViewStyle_NoLabelWrap = LVS_NOLABELWRAP,
    //! No scroll
    uixListViewStyle_NoScroll = LVS_NOSCROLL,
    //! No sort header
    uixListViewStyle_NoSortHeader = LVS_NOSORTHEADER,
    //! Owner data
    uixListViewStyle_OwnerData = LVS_OWNERDATA,
    //! Owner draw fixed
    uixListViewStyle_OwnerDrawFixed = LVS_OWNERDRAWFIXED,
    //! Share image lists
    uixListViewStyle_ShareImageLists = LVS_SHAREIMAGELISTS,
    //! Show selection always
    uixListViewStyle_ShowSelectionAlways = LVS_SHOWSELALWAYS,
    //! Single selection
    uixListViewStyle_SingleSelection = LVS_SINGLESEL,
    //! Sort ascending
    uixListViewStyle_SortAscending = LVS_SORTASCENDING,
    //! Sort descending
    uixListViewStyle_SortDescending = LVS_SORTDESCENDING,
    //! Type mask
    uixListViewStyle_TypeMask = LVS_TYPEMASK,
    //! Type style mask
    uixListViewStyle_TypeStyleMask = LVS_TYPESTYLEMASK,
};

enum uixListViewControlStyle
{
    uixListViewControlStyle_AutoAutoArrange = LVS_EX_AUTOAUTOARRANGE,
    uixListViewControlStyle_AutoCheckSelect = LVS_EX_AUTOCHECKSELECT,
    uixListViewControlStyle_AutoSizeColumns = LVS_EX_AUTOSIZECOLUMNS,
    uixListViewControlStyle_BorderSelect = LVS_EX_BORDERSELECT,
    uixListViewControlStyle_Checkboxes = LVS_EX_CHECKBOXES,
    uixListViewControlStyle_ColumnOverflow = LVS_EX_COLUMNOVERFLOW,
    uixListViewControlStyle_ColumnSnapPoints = LVS_EX_COLUMNSNAPPOINTS,
    uixListViewControlStyle_DoubleBuffer = LVS_EX_DOUBLEBUFFER,
    uixListViewControlStyle_FlatSB = LVS_EX_FLATSB,
    uixListViewControlStyle_FullRowSelect = LVS_EX_FULLROWSELECT,
    uixListViewControlStyle_GridLines = LVS_EX_GRIDLINES,
    uixListViewControlStyle_HeaderDragDrop = LVS_EX_HEADERDRAGDROP,
    uixListViewControlStyle_HeaderInAllViews = LVS_EX_HEADERINALLVIEWS,
    uixListViewControlStyle_HideLabels = LVS_EX_HIDELABELS,
    uixListViewControlStyle_InfoTip = LVS_EX_INFOTIP,
    uixListViewControlStyle_JustifyColumns = LVS_EX_JUSTIFYCOLUMNS,
    uixListViewControlStyle_LabelTip = LVS_EX_LABELTIP,
    uixListViewControlStyle_MultiWorkareas = LVS_EX_MULTIWORKAREAS,
    uixListViewControlStyle_OneClickActivate = LVS_EX_ONECLICKACTIVATE,
    uixListViewControlStyle_Regional = LVS_EX_REGIONAL,
    uixListViewControlStyle_SimpleSelect = LVS_EX_SIMPLESELECT,
    uixListViewControlStyle_SingleRow = LVS_EX_SINGLEROW,
    uixListViewControlStyle_SnapToGrid = LVS_EX_SNAPTOGRID,
    uixListViewControlStyle_SubitemImages = LVS_EX_SUBITEMIMAGES,
    uixListViewControlStyle_TrackSelect = LVS_EX_TRACKSELECT,
    uixListViewControlStyle_TransparentBackground = LVS_EX_TRANSPARENTBKGND,
    uixListViewControlStyle_TransparentShadowText = LVS_EX_TRANSPARENTSHADOWTEXT,
    uixListViewControlStyle_TwoClickActivate = LVS_EX_TWOCLICKACTIVATE,
    uixListViewControlStyle_UnderlineCold = LVS_EX_UNDERLINECOLD,
    uixListViewControlStyle_UnderlineHot = LVS_EX_UNDERLINEHOT,
};

//! List view mode
enum uixListViewViewMode
{
    //! Details
    uixListViewViewMode_Details = LV_VIEW_DETAILS,
    //! Icon
    uixListViewViewMode_Icon = LV_VIEW_ICON,
    //! List
    uixListViewViewMode_List = LV_VIEW_LIST,
    //! Small icon
    uixListViewViewMode_SmallIcon = LV_VIEW_SMALLICON,
    //! Tile
    uixListViewViewMode_Tile = LV_VIEW_TILE,
};

//! List view image list
enum uixListViewImageList
{
    //! Normal
    uixListViewImageList_Normal = LVSIL_NORMAL,
    //! Small
    uixListViewImageList_Small = LVSIL_SMALL,
    //! State
    uixListViewImageList_State = LVSIL_STATE,
    //! Group header
    uixListViewImageList_GroupHeader = LVSIL_GROUPHEADER,
};

enum enumUixListViewColumnFormat
{
    uixListViewColumnFormat_Left = LVCFMT_LEFT,
    uixListViewColumnFormat_Right = LVCFMT_RIGHT,
    uixListViewColumnFormat_Center = LVCFMT_CENTER,
    uixListViewColumnFormat_JustyfyMask = LVCFMT_JUSTIFYMASK,
    uixListViewColumnFormat_Image = LVCFMT_IMAGE,
    uixListViewColumnFormat_BitmapOnRight = LVCFMT_BITMAP_ON_RIGHT,
    uixListViewColumnFormat_ColumnHasImages = LVCFMT_COL_HAS_IMAGES,
    uixListViewColumnFormat_FixedWidth = LVCFMT_FIXED_WIDTH,
    uixListViewColumnFormat_FixedRatio = LVCFMT_FIXED_RATIO,
    uixListViewColumnFormat_NoDpiScale = LVCFMT_NO_DPI_SCALE,
    uixListViewColumnFormat_SplitButton = LVCFMT_SPLITBUTTON,
};
typedef UINT uixListViewColumnFormat;

enum enumUixListViewGetItem
{
    uixListViewGetItem_All = LVNI_ALL,
    uixListViewGetItem_Focused = LVNI_FOCUSED,
    uixListViewGetItem_Selected = LVNI_SELECTED,
    uixListViewGetItem_Cut = LVNI_CUT,
    uixListViewGetItem_DropHilited = LVNI_DROPHILITED,
    uixListViewGetItem_StateMask = LVNI_STATEMASK,
    uixListViewGetItem_VisibleOrder = LVNI_VISIBLEORDER,
    uixListViewGetItem_Previous = LVNI_PREVIOUS,
    uixListViewGetItem_VisibleOnly = LVNI_VISIBLEONLY,
    uixListViewGetItem_SameGroupOnly = LVNI_SAMEGROUPONLY,
    uixListViewGetItem_Above = LVNI_ABOVE,
    uixListViewGetItem_Below = LVNI_BELOW,
    uixListViewGetItem_ToLeft = LVNI_TOLEFT,
    uixListViewGetItem_ToRight = LVNI_TORIGHT,
    uixListViewGetItem_DirectionMask = LVNI_DIRECTIONMASK,
};
typedef UINT uixListViewGetItem;

//! List View Control
//! @brief
//!     This class implements list view GUI control
class UIXAPI uixListViewCtrl : public uixWindow
{
    uixDECLARE_DYNAMIC_CLASS(uixListViewCtrl);
public:
    //! Constructor
    uixListViewCtrl();

    //! Destructor
    virtual ~uixListViewCtrl();

    //! @copydoc uixWindow::BeforeWindowCreate
    virtual BOOL BeforeWindowCreate(CREATESTRUCT& cs) override;

    //! Approximate view rect
    //! @param[in] width
    //!     Width
    //! @param[in] height
    //!     Height
    //! @param[in] itemCount
    //!     Item count
    //! @return
    //!     Flags
    DWORD ApproximateViewRect(INT width, INT height, INT itemCount);

    //! Arrange
    //! @param[in] code
    //!     Code
    //! @return
    //!     True when successful
    BOOL Arrange(UINT code);

    //! Cancel edit label
    void CancelEditLabel();

    //! Create drag image
    //! @param[in] itemID
    //!     Item ID
    //! @param[in] upperLeft
    //!     Upper left position
    //! @return
    //!     Image list
    HIMAGELIST CreateDragImage(INT itemID, POINT* upperLeft = NULLPTR) const;

    //! Delete all items
    //! @return
    //!     True when sucessful
    BOOL DeleteAllItems();

    //! Delete column
    //! @param[in] columnID
    //!     Column ID
    //! @return
    //!     True when successful
    BOOL DeleteColumn(INT columnID);

    //! Delete item
    //! @param[in] itemID
    //!     Item ID
    //! @return
    //!     True when successful
    BOOL DeleteItem(INT itemID);

    //! Edit label
    //! @param[in] itemID
    //!     ID of item to edit
    //! @return
    //!     Handle to edit box
    HWND EditLabel(INT itemID);

    //! Enable group view
    //! @param[in] enable
    //!     Enable flag
    //! @return
    //!     True when successful
    BOOL EnableGroupView(BOOL enable);

    //! Ensure that item is visible
    //! @param[in] itemID
    //!     Item ID
    //! @param[in] partial
    //!     Allow item to be partially visible
    //! @return
    //!     True when successful
    BOOL EnsureVisible(INT itemID, BOOL partial = FALSE);

    //! Finds item
    //! @param[in] startID
    //!     Start item ID
    //! @param[in] findInfo
    //!     Find info
    //! @return
    //!     Item ID of found item
    INT FindItem(INT startID, const LVFINDINFO& findInfo) const;

    //! Gets background color
    //! @return
    //!     Background color
    uixColor GetBackgroundColor() const;

    //! Gets background image
    //! @param[out] image
    //!     Background image description
    //! @return
    //!     True when successful
    BOOL GetBackgroundImage(LVBKIMAGE& image) const;

    //! Gets callback mask
    //! @return
    //!     Callback mask
    UINT GetCallbackMask() const;

    //! Gets check state
    //! @param[in] itemID
    //!     Item ID
    //! @return
    //!     True when successful
    BOOL GetCheckState(UINT itemID) const;

    //! Gets column
    //! @param[in] columnID
    //!     Column ID
    //! @param[out] column
    //!     Column data
    //! @return
    //!     True when successful
    BOOL GetColumn(INT columnID, LVCOLUMN& column) const;

    //! Gets column order array
    //! @param[out] columns
    //!     Columns
    //! @param[in] count
    //!     Number of elements in columns array
    //! @return
    //!     True when successful
    BOOL GetColumnOrderArray(INT columns[], INT count) const;

    //! Gets column width
    //! @param[in] columnID
    //!     Column ID
    //! @return
    //!     Column width
    INT GetColumnWidth(INT columnID) const;

    //! Gets count per page
    //! @return
    //!     Item count per page
    INT GetCountPerPage() const;

    //! Gets edit control
    //! @return
    //!     Handle to edit control
    HWND GetEditControl() const;

    //! Gets empty text
    //! @param[out] text
    //!     Text
    //! @param[in] length
    //!     Length of text buffer
    //! @return
    //!     True when successful
    BOOL GetEmptyText(WCHAR* text, UINT length) const;

    //! Gets control style
    //! @return
    //!     Control style
    DWORD GetControlStyle() const;

    //! Gets focused group ID
    //! @return
    //!     Index of focused group
    INT GetFocusedGroup() const;

    //! Gets footer info
    //! @param[out] footer
    //!     Footer
    //! @return
    //!     True when successful
    BOOL GetFooterInfo(LVFOOTERINFO& footer) const;

    //! Gets footer item
    //! @param[in] footerID
    //!     Footer item ID
    //! @param[out] item
    //!     Item data
    //! @return
    //!     True when successful
    BOOL GetFooterItem(UINT footerID, LVFOOTERITEM& item) const;

    //! Gets footer item rect
    //! @param[in] footerID
    //!     Footer item ID
    //! @param[out] rect
    //!     Item rect
    //! @return
    //!     True when successful
    BOOL GetFooterItemRect(UINT footerID, RECT& rect) const;

    //! Gets footer rect
    //! @param[out] rect
    //!     Footer rect
    //! @return
    //!     True when successful
    BOOL GetFooterRect(RECT& rect) const;

    //! Gets group count
    //! @return
    //!     Group count
    INT GetGroupCount() const;

    //! Gets group header image list
    //! @return
    //!     Handle to image list
    HIMAGELIST GetGroupHeaderImageList() const;

    //! Gets group info
    //! @param[in] groupID
    //!     Group ID
    //! @param[out] group
    //!     Group data
    //! @return
    //!     ID of group
    INT GetGroupInfo(INT groupID, LVGROUP& group) const;

    //! Gets group info by index
    //! @param[in] index
    //!     Group index
    //! @param[out] group
    //!     Group data
    //! @return
    //!     Result value
    LRESULT GetGroupInfoByIndex(INT index, LVGROUP& group);

    //! Gets group metrics
    //! @param[out] metrics
    //!     Group metrics
    void GetGroupMetrics(LVGROUPMETRICS& metrics) const;

    //! Gets group rect
    //! @param[in] groupID
    //!     Group ID
    //! @param[in] type
    //!     Type
    //! @param[out] rect
    //!     Rect
    //! @return
    //!     True when successful
    BOOL GetGroupRect(UINT groupID, LONG type, RECT& rect) const;

    //! Gets group state
    //! @param[in] groupID
    //!     Group ID
    //! @param[in] mask
    //!     Mask
    //! @return
    //!     Group state
    UINT GetGroupState(UINT groupID, UINT mask) const;

    //! Gets header control handle
    //! @return
    //!     Header control handle
    HWND GetHeader() const;

    //! Gets hot cursor
    //! @return
    //!     Cursor handle
    HCURSOR GetHotCursor() const;

    //! Gets hot item ID
    //! @return
    //!     Item ID
    INT GetHotItem() const;

    //! Gets hover time
    //! @return
    //!     Hover time
    DWORD GetHoverTime() const;

    //! Gets image list
    //! @param[in] type
    //!     Image list type
    //! @return
    //!     Handle to image list
    HIMAGELIST GetImageList(uixListViewImageList type) const;

    //! Gets insertion mark
    //! @param[out] mark
    //!     Insertion mark
    //! @return
    //!     True when successful
    BOOL GetInsertMark(LVINSERTMARK& mark) const;

    //! Gets insertion mark color
    //! @return
    //!     Current insertion mark color
    uixColor GetInsertMarkColor() const;

    //! Gets insert mark rect
    //! @param[out] rect
    //!     Rect
    //! @return
    //!     True when successful
    BOOL GetInsertMarkRect(RECT& rect) const;

    //! Gets incremental search string
    //! @param[out] text
    //!     Text
    //! @return
    //!     True when successful
    BOOL GetISearchString(uixChar* text) const;

    //! Gets incremental search string length
    //! @return
    //!     Length of string
    INT GetISearchStringLength() const;

    //! Gets item
    //! @param[out] item
    //!     Item
    //! @return
    //!     True when successful
    BOOL GetItem(LVITEM& item) const;

    //! Gets item count
    //! @return
    //!     Item count
    INT GetItemCount() const;

    //! Gets item index rect
    //! @param[in] index
    //!     Index
    //! @param[in] subItem
    //!     Sub item
    //! @param[in] code
    //!     Code
    //! @param[out] rect
    //!     Rect
    //! @return
    //!     True when successful
    BOOL GetItemIndexRect(LVITEMINDEX& index, LONG subItem, LONG code, RECT& rect) const;

    //! Gets item position
    //! @param[in] itemID
    //!     Item ID
    //! @param[out] position
    //!     Item position
    //! @return
    //!     True when successful
    BOOL GetItemPosition(INT itemID, POINT& position) const;

    //! Gets item rect
    //! @param[in] itemID
    //!     Item ID
    //! @param[in] code
    //!     Code
    //! @param[out] rect
    //!     Rect
    //! @return
    //!     True when succesful
    BOOL GetItemRect(INT itemID, INT code, RECT& rect) const;

    //! Gets item spacing
    //! @param[in] isSmall
    //!     True when small item spacing
    //! @return
    //!     Item spacing flags
    DWORD GetItemSpacing(BOOL isSmall = FALSE) const;

    //! Gets item state
    //! @param[in] itemID
    //!     Item ID
    //! @param[in] mask
    //!     Mask
    //! @return
    //!     Item state
    UINT GetItemState(INT itemID, UINT mask) const;

    //! Gets item text
    //! @param[in] itemID
    //!     Item ID
    //! @param[in] subItemID
    //!     Sub item ID
    //! @param[out] text
    //!     Text buffer
    //! @param[in] length
    //!     Length of text buffer
    void GetItemText(INT itemID, INT subItemID, uixChar* text, INT length) const;

    //! Gets next item ID
    //! @param[in] startID
    //!     First ID
    //! @param[in] flags
    //!     Flags
    //! @return
    //!     ID of next item
    INT GetNextItem(INT startID, uixListViewGetItem flags) const;

    //! Gets next item ID
    //! @param[in] index
    //!     Item Index
    //! @param[in] flags
    //!     Flags
    //! @return
    //!     True when successful
    BOOL GetNextItemIndex(LVITEMINDEX& index, LPARAM flags) const;

    //! Gets bunber of workareas
    //! @param[out] workAreas
    //!     Number of workareas
    //! @return
    //!     True when successful
    BOOL GetNumberOfWorkAreas(UINT& workAreas) const;

    //! Gets origin
    //! @param[out] point
    //!     Origin
    //! @return
    //!     True when successful
    BOOL GetOrigin(POINT& point) const;

    //! Gets outline color
    //! @return
    //!     Outline color
    uixColor GetOutlineColor() const;

    //! Gets selected column ID
    //! @return
    //!     ID of selected column
    UINT GetSelectedColumn() const;

    //! Gets selected items count
    //! @return
    //!     Count of selected items
    UINT GetSelectedCount() const;

    //! Gets seleciton mark
    //! @return
    //!     Selection mark
    INT GetSelectionMark() const;

    //! Gets string width
    //! @param[in] text
    //!     Text to measure
    //! @return
    //!     Text width
    INT GetStringWidth(const uixChar* text) const;

    //! Gets sub item rect
    //! @param[in] itemID
    //!     Item ID
    //! @param[in] subItemID
    //!     Sub item ID
    //! @param[in] code
    //!     Code
    //! @param[out] rect
    //!     Rect
    //! @return
    //!     True when successful
    BOOL GetSubItemRect(INT itemID, INT subItemID, INT code, RECT& rect) const;

    //! Gets text background color
    //! @return
    //!     Background color
    uixColor GetTextBackgroundColor() const;

    //! Gets text color
    //! @return
    //!     Text color
    uixColor GetTextColor() const;

    //! Gets tile info
    //! @param[out] info
    //!     Tile info
    void GetTileInfo(LVTILEINFO& info) const;

    //! Gets tile view info
    //! @param[out] info
    //!     Tile view info
    void GetTileViewInfo(LVTILEVIEWINFO& info) const;

    //! Get tool tips window
    //! @return
    //!     Tool tips window handle
    HWND GetToolTips() const;

    //! Gets top item index
    //! @return
    //!     Index of top item
    INT GetTopIndex() const;

    //! Gets unicode format support
    //! @return
    //!     True when control supports unicode format
    BOOL GetUnicodeFormat() const;

    //! Gets view mode
    //! @return
    //!     View mode
    uixListViewViewMode GetViewMode() const;

    //! Gets view rect
    //! @param[out] rect
    //!     View rect
    //! @return
    //!     True when successful
    BOOL GetViewRect(RECT& rect) const;

    //! Gets work areas
    //! @param[out] areas
    //!     Array of rects
    //! @param[in] count
    //!     Number of elements in areas array
    void GetWorkAreas(RECT areas[], INT count) const;

    //! Checks if control has group
    //! @param[in] groupID
    //!     Group ID
    //! @return
    //!     True when successful
    BOOL HasGroup(INT groupID) const;

    //! Perform hit test
    //! @param[in] info
    //!     Hit test data
    //! @return
    //!     Result flags
    INT HitTest(LVHITTESTINFO& info) const;

    //! Perform hit test
    //! @param[in] info
    //!     Hit test data
    //! @return
    //!     Result flags
    INT HitTestEx(LVHITTESTINFO& info) const;

    //! Inserts column
    //! @param[in] columnID
    //!     Column ID
    //! @param[in] column
    //!     Column data
    //! @return
    //!     Inserted column ID
    INT InsertColumn(INT columnID, const LVCOLUMN& column);

    //! Inserts group
    //! @param[in] groupID
    //!     Group ID
    //! @param[in] group
    //!     Group data
    //! @return
    //!     Inserted group ID
    INT InsertGroup(INT groupID, LVGROUP& group);

    //! Inserts group and sort
    //! @param[in] insert
    //!     Insert group data
    void InsertGroupSorted(LVINSERTGROUPSORTED& insert);

    //! Inserts item
    //! @param[in] item
    //!     Item
    //! @return
    //!     Item ID
    INT InsertItem(const LVITEM& item);

    //! Insert mark hit test
    //! @param[in] point
    //!     Point
    //! @param[in] mark
    //!     Mark data
    //! @return
    //!     True when successful
    BOOL InsertMarkHitTest(POINT& point, LVINSERTMARK& mark);

    //! Checks if group view is enabled
    //! @return
    //!     True when successful
    BOOL IsGroupViewEnabled() const;

    //! Checks if item is visible
    //! @param[in] itemID
    //!     Item ID
    //! @return
    //!     True when successful
    BOOL IsItemVisible(UINT itemID) const;

    //! Map ID to index
    //! @param[in] itemID
    //!     Item ID
    //! @return
    //!     Item Index
    UINT IDToIndex(UINT itemID) const;

    //! Map index to ID
    //! @param[in] index
    //!     Item index
    //! @return
    //!     Item ID
    UINT IndexToID(UINT index) const;

    //! Redraws items
    //! @param[in] firstIndex
    //!     First index
    //! @param[out] lastIndex
    //!     Last index
    //! @return
    //!     True when successful
    BOOL RedrawItems(INT firstIndex, INT lastIndex);

    //! Removes all groups
    void RemoveAllGroups();

    //! Removes group
    //! @param[in] groupID
    //!     Group ID
    //! @return
    //!     Number of groups after remove
    INT RemoveGroup(INT groupID);

    //! Scrolls view
    //! @param[in] dx
    //!     Delta X
    //! @param[in] dy
    //!     Delta y
    //! @return
    //!     True when successful
    BOOL ScrollView(INT dx, INT dy);

    //! Sets background color
    //! @param[in] color
    //!     Background color
    //! @return
    //!     True when successful
    BOOL SetBackgroundColor(uixColor color);

    //! Sets background image
    //! @param[in] image
    //!     Image data
    //! @return
    //!     True when successful
    BOOL SetBackgroundImage(LVBKIMAGE& image);

    //! Sets callback mask
    //! @param[in] mask
    //!     Mask
    //! @return
    //!     True when successful
    BOOL SetCallbackMask(UINT mask);

    //! Sets check state
    //! @param[in] itemIndex
    //!     Item index
    //! @param[in] check
    //!     Check state
    void SetCheckState(UINT itemIndex, BOOL check);

    //! Sets column
    //! @param[in] columnIndex
    //!     Column index
    //! @param[in] column
    //!     Column data
    //! @return
    //!     True when successful
    BOOL SetColumn(INT columnIndex, LVCOLUMN& column);

    //! Sets column order array
    //! @param[in] order
    //!     Order array
    //! @param[in] count
    //!     Number of elements in order array
    //! @return
    //!     True when successful
    BOOL SetColumnOrderArray(INT order[], INT count);

    //! Sets colummn width
    //! @param[in] columnIndex
    //!     Column index
    //! @param[in] width
    //!     Width
    //! @return
    //!     True when successful
    BOOL SetColumnWidth(INT columnIndex, INT width);

    //! Sets control style
    //! @param[in] style
    //!     Control style
    void SetControlStyle(DWORD style);

    //! Sets control style
    //! @param[in] style
    //!     Control style
    //! @param[in] mask
    //!     Style mask
    void SetControlStyle(DWORD style, DWORD mask);

    //! Sets group header imagelist
    //! @param[in] images
    //!     Handle to image list
    //! @return
    //!     Previous image list handle
    HIMAGELIST SetGroupHeaderImageList(HIMAGELIST images);

    //! Sets group info
    //! @param[in] groupID
    //!     Group ID
    //! @param[in] group
    //!     Group data
    //! @return
    //!     Group index
    INT SetGroupInfo(INT groupID, LVGROUP& group);

    //! Sets group metrics
    //! @param[in] metrics
    //!     Group metrics
    void SetGroupMetrics(LVGROUPMETRICS& metrics);

    //! Sets group state
    //! @param[in] groupID
    //!     Group ID
    //! @param[in] mask
    //!     Mask
    //! @param[in] state
    //!     Group state
    void SetGroupState(UINT groupID, UINT mask, UINT state);

    //! Sets hot cursor
    //! @param[in] cursor
    //!     New hot cursor
    //! @return
    //!     Previuos hot cursor
    HCURSOR SetHotCursor(HCURSOR cursor);

    //! Sets hot item
    //! @param[in] itemIndex
    //!     Index of hot item
    //! @return
    //!     Index of previous hot item
    INT SetHotItem(INT itemIndex);

    //! Sets hover time
    //! @param[in] time
    //!     New hover time
    void SetHoverTime(DWORD time);

    //! Sets icon spacing
    //! @param[in] width
    //!     Width
    //! @param[in] height
    //!     Height
    //! @return
    //!     Previuos icon spacing
    DWORD SetIconSpacing(INT width, INT height);

    //! Sets image list handle
    //! @param[in] handle
    //!     Image list handle
    //! @param[in] type
    //!     Image list type
    //! @return
    //!     Previous image list handle
    HIMAGELIST SetImageList(HIMAGELIST handle, uixListViewImageList type);

    //! Sets info tip
    //! @param[in] info
    //!     Info tip data
    //! @return
    //!     True when successful
    BOOL SetInfoTip(LVSETINFOTIP& info);

    //! Sets insertion mark
    //! @param[in] mark
    //!     Insertion mark
    //! @return
    //!     True when successful
    BOOL SetInsertMark(LVINSERTMARK& mark);

    //! Sets insertion mark color
    //! @param[in] color
    //!     Color
    //! @return
    //!     Previous color
    uixColor SetInsertMarkColor(uixColor color);

    //! Sets item
    //! @param[in] item
    //!     Item
    //! @return
    //!     True when successful
    BOOL SetItem(const LVITEM& item);

    //! Sets item count
    //! @param[in] count
    //!     Item count
    void SetItemCount(INT count);

    //! Sets item count
    //! @param[in] count
    //!     Item count
    //! @param[in] flags
    //!     Flags
    void SetItemCount(INT count, DWORD flags);

    //! Sets item state
    //! @param[in] index
    //!     Item index
    //! @param[in] data
    //!     Data
    //! @param[in] mask
    //!     Mask
    void SetItemIndexState(LVITEMINDEX& index, UINT data, UINT mask);

    //! Sets item position
    //! @param[in] itemIndex
    //!     Item index
    //! @param[in] left
    //!     Left position
    //! @param[in] top
    //!     Top position
    //! @return
    //!     True when successful
    BOOL SetItemPosition(INT itemIndex, INT left, INT top);

    //! Sets item position
    //! @param[in] itemIndex
    //!     Item index
    //! @param[in] left
    //!     Left position
    //! @param[in] top
    //!     Top position
    void SetItemPosition32(INT itemIndex, INT left, INT top);

    //! Sets item state
    //! @param[in] itemIndex
    //!     Item index
    //! @param[in] state
    //!     Item state
    //! @param[in] mask
    //!     Mask
    void SetItemState(INT itemIndex, UINT state, UINT mask);

    //! Sets item text
    //! @param[in] itemIndex
    //!     Item index
    //! @param[in] subItemIndex
    //!     Sub item index
    //! @param[in] text
    //!     Text
    void SetItemText(INT itemIndex, INT subItemIndex, const uixChar* text);

    //! Sets outline color
    //! @param[in] color
    //!     Outline color
    //! @return
    //!     Previous outline color
    uixColor SetOutlineColor(uixColor color);

    //! Sets selected column
    //! @param[in] columnIndex
    //!     Column index
    void SetSelectedColumn(INT columnIndex);

    //! Sets selection mark
    //! @param[in] itemIndex
    //!     Item ID
    //! @return
    //!     Previous selection mark, -1 if there is no previuos selection mark
    INT SetSelectionMark(INT itemIndex);

    //! Sets text background color
    //! @param[in] color
    //!     Background color
    //! @return
    //!     True when successful
    BOOL SetTextBackgroundColor(uixColor color);

    //! Sets text color
    //! @param[in] color
    //!     Color
    //! @return
    //!     True when successful
    BOOL SetTextColor(uixColor color);

    //! Sets tile info
    //! @param[in] info
    //!     Tile info
    //! @return
    //!     True when successful
    BOOL SetTileInfo(LVTILEINFO& info);

    //! Sets tile view info
    //! @param[in] info
    //!     Tile view info
    //! @return
    //!     True when sucessful
    BOOL SetTileViewInfo(LVTILEVIEWINFO& info);

    //! Sets tool tips window handle
    //! @param[in] toolTips
    //!     New tool tip window handle
    //! @return
    //!     Previous tool tips window handle
    HWND SetToolTips(HWND toolTips);

    //! Sets unicode format support
    //! @param[in] unicode
    //!     Unicode format support flag
    //! @return
    //!     Previous unicode format support flag
    BOOL SetUnicodeFormat(BOOL unicode);

    //! Sets view mode
    //! @param[in] view
    //!     View mode
    //! @return
    //!     True when successful
    BOOL SetViewMode(uixListViewViewMode view);

    //! Sets work areas
    //! @param[in] areas
    //!     Work areas
    //! @param[in] count
    //!     Number of elements in areas array
    void SetWorkAreas(RECT areas[], INT count);

    //! Sorts groups
    //! @param[in] compare
    //!     Function to compare groups
    //! @param[in] data
    //!     Data passed to compare function
    //! @return
    //!     True when successful
    BOOL SortGroups(PFNLVGROUPCOMPARE compare, void* data);

    //! Sorts items
    //! @param[in] compare
    //!     Function to compare items
    //! @param[in] data
    //!     Data passed to compare function
    //! @return
    //!     True when successful
    BOOL SortItems(PFNLVCOMPARE compare, LPARAM data);

    //! @param[in] compare
    //!     Function to compare items
    //! @param[in] data
    //!     Data passed to compare function
    //! @return
    //!     True when successful
    BOOL SortItemsEx(PFNLVCOMPARE compare, LPARAM data);

    //! Test hit for sub item
    //! @param[in] info
    //!     Hit test info
    //! @return
    //!     Item ID
    INT SubItemHitTest(LVHITTESTINFO& info);

    //! Update item
    //! @param[in] itemIndex
    //!     Index of item to update
    //! @return
    //!     True when successful
    BOOL UpdateItem(INT itemIndex);
};
}
//----------------------------------------------------------------------------//
#include "uixlistviewctrl.inl"
//----------------------------------------------------------------------------//
#endif /* _UIX_LISTVIEWCTRL_H__ */