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
#ifndef _UIX_BUTTONCTRL_H__
#define _UIX_BUTTONCTRL_H__
//----------------------------------------------------------------------------//
#include "uixwindow.h"
//----------------------------------------------------------------------------//
namespace UIX
{
//! Handles button click event
#define uixEVT_BTN_CLICKED(Identifier, Handler) \
    uixEVT_CONTROL(BN_CLICKED, Identifier, Handler)

//! Handles double button click
#define uixEVT_BTN_DOUBLECLICKED(Identifier, Handler) \
    uixEVT_CONTROL(BN_DBLCLK, Identifier, Handler)

//! Handles set focus
#define uixEVT_BTN_SETFOCUS(Identifier, Handler) \
    uixEVT_CONTROL(BN_SETFOCUS, Identifier, Handler)

//! Handles kill focus
#define uixEVT_BTN_KILLFOCUS(Identifier, Handler) \
    uixEVT_CONTROL(BN_KILLFOCUS, Identifier)

//! Handle drop down
#define uixEVT_BTN_DROPDOWN(Identifier, Handler) \
    uixEVT_NOTIFY(BCN_DROPDOWN, Identifier, Handler)

//! Handle hot item change
#define uixEVT_BTN_HOTITEMCHANGE(Identifier, Handler) \
    uixEVT_NOTIFY(BCN_HOTITEMCHANGE, Identifier, Handler)

//! Button notify messages
//! @note
//!     This codes are used with uixEVT_CONTROL macro, not with uixEVT_NOTIFY
enum uixButtonNotifyMessage
{
    //! Clicked
    uixButtonNotifyMessage_Clicked = BN_CLICKED,
    //! Double clicked
    uixButtonNotifyMessage_DoubleClicked = BN_DBLCLK,
    //! Button has focus
    uixButtonNotifyMessage_SetFocus = BN_SETFOCUS,
    //! Button lost focus
    uixButtonNotifyMessage_KillFocus = BN_KILLFOCUS,
    //! Button drop down list
    uixButtonNotifyMessage_DropDown = BCN_DROPDOWN,
    //! Button drop down list hot item changed
    uixButtonNotifyMessage_HotItemChange = BCN_HOTITEMCHANGE,
};

//! Button Image List Align
enum uixButtonImageListAlign
{
    //! No align specified
    uixButtonImageListAlign_None = 0,
    //! Align left
    uixButtonImageListAlign_Left = BUTTON_IMAGELIST_ALIGN_LEFT,
    //! Align right
    uixButtonImageListAlign_Right = BUTTON_IMAGELIST_ALIGN_RIGHT,
    //! Align top
    uixButtonImageListAlign_Top = BUTTON_IMAGELIST_ALIGN_TOP,
    //! Align bottom
    uixButtonImageListAlign_Bottom = BUTTON_IMAGELIST_ALIGN_BOTTOM,
    //! Align center
    uixButtonImageListAlign_Center = BUTTON_IMAGELIST_ALIGN_CENTER,
};

//! Button Image List
struct uixButtonImageList : BUTTON_IMAGELIST
{
    //! Gets image list
    HIMAGELIST GetImageList() const;

    //! Sets image list
    void SetImageList(HIMAGELIST value);

    //! Gets margin
    const RECT& GetMargin() const;

    //! Sets margin
    void SetMargin(const RECT& rect);

    //! Gets align
    uixButtonImageListAlign GetAlign() const;

    //! Sets align
    void SetAlign(uixButtonImageListAlign value);
};

//! Button split style
enum uixButtonSplitStyle
{
    //! No flag
    uixButtonSplitStyle_None = 0,
    //! Split aligned left
    uixButtonSplitStyle_AlignLeft = BCSS_ALIGNLEFT,
    //! Image
    uixButtonSplitStyle_Image = BCSS_IMAGE,
    //! No split
    uixButtonSplitStyle_NoSplit = BCSS_NOSPLIT,
    //! Stretched
    uixButtonSplitStyle_Stretch = BCSS_STRETCH,
};

//! Button Split Info
struct uixButtonSplitInfo : BUTTON_SPLITINFO
{
    //! Gets used fields mask
    DWORD GetMask() const;

    //! Sets used fields mask
    void SetMask(DWORD value);

    //! Gets image list
    HIMAGELIST GetImageList() const;

    //! Sets image list
    void SetImageList(HIMAGELIST handle);

    //! Gets size
    BOOL GetSize(SIZE& value) const;

    //! Sets size
    void SetSize(const SIZE& value);

    //! Gets split style
    uixButtonSplitStyle GetStyle() const;

    //! Sets split style
    void SetStyle(uixButtonSplitStyle value);
};

//! Button Style
enum uixButtonStyle
{
    //! No button style
    uixButtonStyle_None = 0,
    //! Push Button
    uixButtonStyle_PushButton = BS_PUSHBUTTON,
    //! Default Push button
    uixButtonStyle_DefPushButton = BS_DEFPUSHBUTTON,
    //! Manual Check box
    uixButtonStyle_CheckBox = BS_CHECKBOX,
    //! Auto Check Box
    uixButtonStyle_AutoCheckBox = BS_AUTOCHECKBOX,
    //! Manual Radio Button
    uixButtonStyle_RadioButton = BS_RADIOBUTTON,
    //! Manual 3State check box
    uixButtonStyle_3State = BS_3STATE,
    //! Auto 3State check box
    uixButtonStyle_Auto3State = BS_AUTO3STATE,
    //! Group Box
    uixButtonStyle_GroupBox = BS_GROUPBOX,
    //! User Button
    uixButtonStyle_UserButton = BS_USERBUTTON,
    //! Auto Radio Button
    uixButtonStyle_AutoRadioButton = BS_AUTORADIOBUTTON,
    //! Push Box
    uixButtonStyle_PushBox = BS_PUSHBOX,
    //! Owner Draw
    uixButtonStyle_OwnerDraw = BS_OWNERDRAW,
    //! Text on left
    uixButtonStyle_LeftText = BS_LEFTTEXT,
    //! Text
    uixButtonStyle_Text = BS_TEXT,
    //! Icon
    uixButtonStyle_Icon = BS_ICON,
    //! Bitmap
    uixButtonStyle_Bitmap = BS_BITMAP,
    //! Left text align
    uixButtonStyle_TextAlignLeft = BS_LEFT,
    //! Right text align
    uixButtonStyle_TextAlignRight = BS_RIGHT,
    //! Center text align
    uixButtonStyle_TextAlignCenter = BS_CENTER,
    //! Top text align
    uixButtonStyle_TextAlignTop = BS_TOP,
    //! Bottom text align
    uixButtonStyle_TextAlignBottom = BS_BOTTOM,
    //! Vertical center text align
    uixButtonStyle_TextAlignVCenter = BS_VCENTER,
    //! Push like
    uixButtonStyle_PushLike = BS_PUSHLIKE,
    //! Multiline
    uixButtonStyle_Multiline = BS_MULTILINE,
    //! Notify parent
    uixButtonStyle_Notify = BS_NOTIFY,
    //! Flat button
    uixButtonStyle_Flat = BS_FLAT,
    //! Type mask
    uixButtonStyle_TypeMask = BS_TYPEMASK,
};

//! Button State
enum uixButtonState
{
    //! None
    uixButtonState_None = 0,
    //! Checked
    uixButtonState_Checked = BST_CHECKED,
    //! Unchecked
    uixButtonState_Unchecked = BST_UNCHECKED,
    //! Indeterminate
    uixButtonState_Indeterminate = BST_INDETERMINATE,
    //! Pushed
    uixButtonState_Pushed = BST_PUSHED,
    //! Focus
    uixButtonState_Focus = BST_FOCUS,
    //! Hot
    uixButtonState_Hot = BST_HOT,
    //! Drop Down Pushed
    uixButtonState_DropDownPushed = BST_DROPDOWNPUSHED,
};

//! Button control
//! @brief
//!     This class implements simple button control. Also it's base class
//!     for any other specialized button-derived controls
//! @note
//!     Notify message entries are starting with uixEVT_BTN_
class UIXAPI uixButton : public uixWindow
{
    uixDECLARE_DYNAMIC_CLASS(uixButton);
public:
    //! Constructor
    uixButton();

    //! Destructor
    virtual ~uixButton();

    //! @copydoc uixWindow::BeforeWindowCreate
    virtual BOOL BeforeWindowCreate(CREATESTRUCT& cs) override;

    //! Gets button check state
    //! @return
    //!     Check state
    uixButtonState GetCheck() const;

    //! Gets button ideal size
    //! @param[out] size
    //!     Button's ideal size
    //! @return
    //!     True when successful
    BOOL GetIdealSize(SIZE& size) const;

    //! Gets button image list
    //! @param[in,out] imageList
    //!     Image list description struct
    //! @return
    //!     True when successful
    BOOL GetImageList(BUTTON_IMAGELIST& imageList) const;

    //! Gets note text attached to button
    //! @param[out] text
    //!     Text buffer
    //! @param[in] length
    //!     Buffer length
    //! @return
    //!     True when successful
    BOOL GetNote(uixChar* text, INT length) const;

    //! Gets note text length
    //! @return
    //!     Note text length
    UINT GetNoteLength() const;

    //! Gets split info
    //! @param[in,out] info
    //!     Split info
    //! @return
    //!     True when successful
    BOOL GetSplitInfo(BUTTON_SPLITINFO& info) const;

    //! Gets button state
    //! @return
    //!     Button state flags
    UINT GetState() const;

    //! Sets text margin
    //! @param[out] rect
    //!     Text margin
    //! @return
    //!     True when successful
    BOOL GetTextMargin(RECT& rect) const;

    //! Sets button check state
    //! @param[in] check
    //!     Check state
    void SetCheck(uixButtonState check);

    //! Sets drop down state
    //! @param[in] dropDown
    //!     Drop down state flag
    //! @return
    //!     True when successful
    BOOL SetDropDownState(BOOL dropDown);

    //! Sets "elevation required" state
    //! @param[in] required
    //!     Required flag
    //! @return
    //!     Flags
    UINT SetElevationRequiredState(BOOL required);

    //! Sets image list
    //! @param[in] imageList
    //!     Image list description
    //! @return
    //!     True when successful
    BOOL SetImageList(BUTTON_IMAGELIST& imageList);

    //! Sets note text
    //! @param[in] text
    //!     Note text
    //! @return
    //!     True when successful
    BOOL SetNote(const uixChar* text);

    //! Sets split info
    //! @param[in] info
    //!     Button split info
    //! @return
    //!     True when successful
    BOOL SetSplitInfo(BUTTON_SPLITINFO& info);

    //! Sets button state
    //! @param[in] state
    //!     Button state
    void SetState(BOOL state = TRUE);

    //! Sets button style
    //! @param[in] style
    //!     Button style
    //! @param[in] redraw
    //!     Redraw flag
    void SetStyle(uixButtonStyle style, BOOL redraw);

    //! Sets text margin
    //! @param[in] rect
    //!     Margin values
    //! @return
    //!     True when successful
    BOOL SetTextMargin(const RECT& rect);

    //! Sets image handle
    //! @param[in] handle
    //!     Icon handle
    //! @return
    //!     Previous icon handle
    HICON SetImage(HICON handle)
    {
        return (HICON)SendMessage(BM_SETIMAGE, IMAGE_ICON, (LPARAM)handle);
    }

    //! Gets image icon handle
    //! @return
    //!     Image icon handle
    HICON GetImage() const
    {
        return (HICON)SendMessage(BM_GETIMAGE, IMAGE_ICON, 0);
    }

    //! Sets image bitmap handle
    //! @param[in] handle
    //!     Bitmap handle
    //! @return
    //!     Previous bitmap handle
    HBITMAP SetBitmap(HBITMAP handle)
    {
        return (HBITMAP)SendMessage(BM_SETIMAGE, IMAGE_BITMAP, (LPARAM)handle);
    }

    //! Gets bitmap handle
    //! @return
    //!     Previuos bitmap handle
    HBITMAP GetBitmap() const
    {
        return (HBITMAP)SendMessage(BM_GETIMAGE, IMAGE_BITMAP, 0);
    }
};

//! Group pane class
//! @brief
//!     This class represents single grouping pane control with borders
class UIXAPI uixGroupPane : public uixButton
{
    uixDECLARE_DYNAMIC_CLASS(uixGroupPane);
public:
    //! @copydoc uixButton::BeforeWindowCreate
    virtual BOOL BeforeWindowCreate(CREATESTRUCT& cs) override;
};

//! Check box control
//! @brief
//!     This class represents checkbox control
class UIXAPI uixCheckBox : public uixButton
{
    uixDECLARE_DYNAMIC_CLASS(uixCheckBox);
public:
    //! @copydoc uixButton::BeforeWindowCreate
    virtual BOOL BeforeWindowCreate(CREATESTRUCT& cs) override;
};

//! Radio button
//! @brief
//!     This class represents radio button control
class UIXAPI uixRadioButton : public uixButton
{
    uixDECLARE_DYNAMIC_CLASS(uixRadioButton);
public:
    //! @copydoc uixButton::BeforeWindowCreate
    virtual BOOL BeforeWindowCreate(CREATESTRUCT& cs) override;
};

//! Command link button
//! @brief
//!     This class represents command link button
class UIXAPI uixCommandLink : public uixButton
{
    uixDECLARE_DYNAMIC_CLASS(uixCommandLink);
public:
    //! @copydoc uixButton::BeforeWindowCreate
    virtual BOOL BeforeWindowCreate(CREATESTRUCT& cs) override;
};
}
//----------------------------------------------------------------------------//
#include "uixbuttonctrl.inl"
//----------------------------------------------------------------------------//
#endif /* _UIX_BUTTONCTRL_H__ */