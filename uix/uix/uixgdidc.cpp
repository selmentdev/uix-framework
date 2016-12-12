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
#include "uixgdidc.h"
//----------------------------------------------------------------------------//
namespace UIX
{
//----------------------------------------------------------------------------//
uixBufferDC::uixBufferDC(HWND handle)
    : uixPaintDC(handle)
    , m_BoundsUpdated(FALSE)
{
    if (m_Handle != 0)
    {
        m_OutputDC = uixPaintDC::m_Handle;

        ::GetClientRect(m_Window, &m_ClientRect);

        m_MemoryDC = ::CreateCompatibleDC(m_OutputDC);

        m_PaintBitmap = ::CreateCompatibleBitmap(
                            m_OutputDC,
                            m_ClientRect.Width(),
                            m_ClientRect.Height());

        m_PreviousBitmap = (HBITMAP)::SelectObject(m_MemoryDC, m_PaintBitmap);

        uixPaintDC::m_Handle = m_MemoryDC;
    }
}
//----------------------------------------------------------------------------//
uixBufferDC::~uixBufferDC()
{
    Flush();

    ::SelectObject(m_MemoryDC, m_PreviousBitmap);
    ::DeleteObject(m_PaintBitmap);

    uixPaintDC::m_Handle = m_OutputDC;

    ::DeleteDC(m_MemoryDC);
}
//----------------------------------------------------------------------------//
void uixBufferDC::Flush()
{
    ::BitBlt(m_OutputDC,
             m_ClientRect.Left(),
             m_ClientRect.Top(),
             m_ClientRect.Width(),
             m_ClientRect.Height(),
             m_MemoryDC,
             0, 0,
             SRCCOPY);
}
//----------------------------------------------------------------------------//
uixDCBounds uixBufferDC::SetBoundsRect(const uixRect* rect, uixDCBounds flags)
{
    if (rect != NULLPTR)
    {
        if ((m_ClientRect.Width() > rect->Width()) ||
            (m_ClientRect.Height() > rect->Height()))
        {
            rect = &m_ClientRect;
        }

        HBITMAP bitmap = ::CreateCompatibleBitmap(
                             m_OutputDC,
                             rect->Width(),
                             rect->Height());

        HDC tempDC = ::CreateCompatibleDC(m_OutputDC);

        HBITMAP prevBitmap = (HBITMAP)::SelectObject(tempDC, bitmap);

        ::BitBlt(
            tempDC,
            m_ClientRect.Left(),
            m_ClientRect.Top(),
            m_ClientRect.Width(),
            m_ClientRect.Height(),
            m_MemoryDC,
            0, 0,
            SRCCOPY);

        ::SelectObject(tempDC, prevBitmap);
        ::DeleteDC(tempDC);

        HBITMAP prev = (HBITMAP)::SelectObject(m_MemoryDC, bitmap);

        if ((prev != 0) &&
            (prev != m_PaintBitmap))
        {
            ::DeleteObject(prev);
        }

        if (m_PaintBitmap != 0)
        {
            ::DeleteObject(m_PaintBitmap);
        }

        m_PaintBitmap = bitmap;

        m_ClientRect = *rect;

        m_BoundsUpdated = TRUE;
    }

    return uixPaintDC::SetBoundsRect(rect, flags);
}
//----------------------------------------------------------------------------//
BOOL uixBufferDC::Restore(INT saved)
{
    BOOL result = uixPaintDC::Restore(saved);

    if (m_BoundsUpdated)
    {
        Select(m_PaintBitmap);
    }

    return result;
}
//----------------------------------------------------------------------------//
}
//----------------------------------------------------------------------------//