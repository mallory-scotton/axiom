///////////////////////////////////////////////////////////////////////////////
///
/// MIT License
///
/// Copyright(c) 2024 Mallory SCOTTON
///
/// Permission is hereby granted, free of charge, to any person obtaining a
/// copy of this software and associated documentation files (the "Software"),
/// to deal in the Software without restriction, including without limitation
/// the rights to use, copy, modify, merge, publish, distribute, sublicense,
/// and/or sell copies of the Software, and to permit persons to whom the
/// Software is furnished to do so, subject to the following coditions:
///
/// The above copyright notice and this permission notice shall be included
/// in all copies or substantial portions of the Software?
///
/// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
/// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
/// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
/// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
/// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
/// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
/// DEALINGS IN THE SOFTWARE.
///
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// Headers
///////////////////////////////////////////////////////////////////////////////
#include <axiom/graphics/videoMode.hpp>

///////////////////////////////////////////////////////////////////////////////
axg::VideoMode::VideoMode(void) : width(800), height(600), bitsPerPixel(32) {}

///////////////////////////////////////////////////////////////////////////////
axg::VideoMode::VideoMode(Uint32 width, Uint32 height, Uint32 modeBitsPerPixel)
    : width(width), height(height), bitsPerPixel(modeBitsPerPixel) {}

///////////////////////////////////////////////////////////////////////////////
AXIOM_NODISCARD bool operator==(axg::VideoMode& lhs, axg::VideoMode& rhs)
{
    return (
        (lhs.width == rhs.width) &&
        (lhs.height == rhs.height) &&
        (lhs.bitsPerPixel == rhs.bitsPerPixel)
    );
}

///////////////////////////////////////////////////////////////////////////////
AXIOM_NODISCARD bool operator!=(axg::VideoMode& lhs, axg::VideoMode& rhs)
{
    return (
        (lhs.width != rhs.width) ||
        (lhs.height != rhs.height) ||
        (lhs.bitsPerPixel != rhs.bitsPerPixel)
    );
}

///////////////////////////////////////////////////////////////////////////////
AXIOM_NODISCARD bool operator>(axg::VideoMode& lhs, axg::VideoMode& rhs)
{
    return (rhs < lhs);
}

///////////////////////////////////////////////////////////////////////////////
AXIOM_NODISCARD bool operator>=(axg::VideoMode& lhs, axg::VideoMode& rhs)
{
    return (!(lhs < rhs));
}

///////////////////////////////////////////////////////////////////////////////
AXIOM_NODISCARD bool operator<(axg::VideoMode& lhs, axg::VideoMode& rhs)
{
    if (lhs.bitsPerPixel == rhs.bitsPerPixel)
    {
        if (lhs.width == rhs.width)
        {
            return (lhs.height < rhs.height);
        }
        return (lhs.width < rhs.width);
    }
    return (lhs.bitsPerPixel < rhs.bitsPerPixel);
}

///////////////////////////////////////////////////////////////////////////////
AXIOM_NODISCARD bool operator<=(axg::VideoMode& lhs, axg::VideoMode& rhs)
{
    return (!(rhs < lhs));
}
