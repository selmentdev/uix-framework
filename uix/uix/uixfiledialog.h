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
#ifndef _UIX_FILEDIALOG_H__
#define _UIX_FILEDIALOG_H__
//----------------------------------------------------------------------------//
#include "uixrequired.h"
#include "uixwindow.h"
//----------------------------------------------------------------------------//
namespace UIX
{
//! FIle dialog filter item
struct uixFileDialogFilter : COMDLG_FILTERSPEC
{
    //! Gets filter name
    //! @return
    //!     Filter name
    const wchar_t* GetName() const
    {
        return pszName;
    }

    //! Sets filter name
    //! @param[in] name
    //!     Filter name
    void SetName(const wchar_t* name)
    {
        pszName = name;
    }

    //! Gets filter
    //! @return
    //!     Filter string
    const wchar_t* GetFilter() const
    {
        return pszSpec;
    }

    //! Sets filter
    //! @param[in] filter
    //!     Filter string
    void SetFilter(const wchar_t* filter)
    {
        pszSpec = filter;
    }
};

//! File Dialog Flag
enum uixFileDialogFlag
{
    //! None
    uixFileDialogFlag_None = 0,
    //! Overwrite Promp
    uixFileDialogFlag_OverwritePrompt = FOS_OVERWRITEPROMPT,
    //! Strict file types
    uixFileDialogFlag_StrictFileTypes = FOS_STRICTFILETYPES,
    //! No change dir
    uixFileDialogFlag_NoChangeDir = FOS_NOCHANGEDIR,
    //! Pick folders
    uixFileDialogFlag_PickFolders = FOS_PICKFOLDERS,
    //! Force file system
    uixFileDialogFlag_ForceFileSystem = FOS_FORCEFILESYSTEM,
    //! All non storage items
    uixFileDialogFlag_AllNonStorageItems = FOS_ALLNONSTORAGEITEMS,
    //! No validate
    uixFileDialogFlag_NoValidate = FOS_NOVALIDATE,
    //! Allow multiselect
    uixFileDialogFlag_AllowMultiSelect = FOS_ALLOWMULTISELECT,
    //! Path must exist
    uixFileDialogFlag_PathMustExist = FOS_PATHMUSTEXIST,
    //! File must exist
    uixFileDialogFlag_FileMustExist = FOS_FILEMUSTEXIST,
    //! Create prompt
    uixFileDialogFlag_CreatePrompt = FOS_CREATEPROMPT,
    //! Share aware
    uixFileDialogFlag_ShareAware = FOS_SHAREAWARE,
    //! No readonly return
    uixFileDialogFlag_NoReadOnlyReturn = FOS_NOREADONLYRETURN,
    //! No test file create
    uixFileDialogFlag_NoTestFileCreate = FOS_NOTESTFILECREATE,
    //! Hide MRU
    uixFileDialogFlag_HideMruPlaces = FOS_HIDEMRUPLACES,
    //! Hide pinned
    uixFileDialogFlag_HidePinnedPlaces = FOS_HIDEPINNEDPLACES,
    //! No deference links
    uixFileDialogFlag_NoDereferenceLinks = FOS_NODEREFERENCELINKS,
    //! Dont add to recent
    uixFileDialogFlag_DontAddToRecent = FOS_DONTADDTORECENT,
    //! Force show hidden
    uixFileDialogFlag_ForceShowHidden = FOS_FORCESHOWHIDDEN,
    //! Default no minimode
    uixFileDialogFlag_DefaultNoMinimode = FOS_DEFAULTNOMINIMODE,
    //! Force preview pane window
    uixFileDialogFlag_ForcePreviewPaneWindow = FOS_FORCEPREVIEWPANEON,
};

//! File Dialog
//! @brief
//!     This class implements file dialog, for opening and saving files. Also
//!     it supports choosing folders by specyfing FOS_PICKFOLDERS flag
class UIXAPI uixFileDialog
{
public:
    //! Constructor
    //! @param[in] openDialog
    //!     When set to true, shows Open File Dialog
    //!     When set to false, Save File Dialog
    uixFileDialog(BOOL openDialog = TRUE);

    //! Destructor
    virtual ~uixFileDialog();
public: // properties
    #pragma region Properties

    //! Gets options
    //! @return
    //!     Option flags
    uixFileDialogFlag GetOptions() const;

    //! Sets options
    //! @param[in] flags
    //!     Option flags
    BOOL SetOptions(uixFileDialogFlag flags);

    //! Gets selection
    //! @param[out] selection
    //!     Selected file name
    void GetFileName(uixWString& selection);

    //! Sets selection
    //! @param[in] fileName
    //!     File name
    //! @return
    //!     True when successful
    BOOL SetFileName(const wchar_t* fileName);

    //! Gets folder
    //! @param[out] folder
    //!     Folder path
    void GetFolder(uixWString& folder);

    //! Sets folder
    //! @param[in] folder
    //!     Folder path
    void SetFolder(const wchar_t* folder);

    //! Adds new place to places in dialog
    //! @param[in] folder
    //!     Path to folder
    //! @param[in] onTop
    //!     When true, place will be added on top of list
    //!     When false, place will be added on bottom of list
    void AddPlace(const wchar_t* folder, BOOL onTop = TRUE);

    //! Sets default folder
    //! @param[in] folder
    //!     Path to folder
    void SetDefaultFolder(const wchar_t* folder);

    //! Sets default extension
    //! @param[in] extension
    //!     Default extension
    void SetDefaultExtension(const wchar_t* extension);

    //! Gets current selection
    //! @param[out] selection
    //!     Current selection
    void GetCurrentSelection(uixWString& selection);

    //! Gets dialog results filename
    //! @param[out] fileName
    //!     Gets selected file
    void GetResult(uixWString& fileName);

    //! Sets name label
    //! @param[in] title
    //!     File name label title
    void SetFileNameLabel(const wchar_t* title);

    //! Sets dialog title
    //! @param[in] title
    //!     Dialog title
    void SetTitle(const wchar_t* title);

    //! Sets text on OK button
    //! @param[in] title
    //!     Ok button title
    void SetOkButtonLabel(const wchar_t* title);

    //! Sets file types
    //! @param[in] filters
    //!     Filters array
    //! @param[in] count
    //!     Number of filters in array
    void SetFileTypes(const uixFileDialogFilter filters[], UINT count);

    //! Sets current file type index
    //! @param[in] index
    //!     Index of selected file type
    void SetFileTypeIndex(UINT index);

    //! Gets current file type index
    //! @return
    //!     Index of selected file type
    UINT GetFileTypeIndex() const;

    //! Shows modal
    //! @param[in] parent
    //!     Parent window
    //! @return
    //!     Result code
    UINT_PTR DoModal(uixWindow* parent);

    //! Close dialog
    void Close();
    #pragma endregion
public:
    #pragma region Message Handlers
    //! Called when OK button was clicked
    //! @return
    //!     True when successful
    virtual BOOL OnFileOk();

    //! Called when folder was changed
    //! @return
    //!     True when successful
    virtual BOOL OnFolderChange();

    //! Called when folder is changing
    //! @return
    //!     True when successful
    virtual BOOL OnFolderChanging();
    #pragma endregion
private:
    DWORD               m_Cookie;       //!< Advise cookie
    IFileDialogEvents*  m_EventHandler; //!< Event handler
    IFileDialog*        m_FileDialog;   //!< File dialog
    HRESULT             m_ShowResult;   //!< Result
};
}
//----------------------------------------------------------------------------//
#endif /* _UIX_FILEDIALOG_H__ */