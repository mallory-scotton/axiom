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
// Pragma once
///////////////////////////////////////////////////////////////////////////////
#pragma once

///////////////////////////////////////////////////////////////////////////////
// Headers
///////////////////////////////////////////////////////////////////////////////
#include <axiom/config.hpp>

///////////////////////////////////////////////////////////////////////////////
// Namespace ax::container
///////////////////////////////////////////////////////////////////////////////
namespace ax::container
{

///////////////////////////////////////////////////////////////////////////////
/// \brief
///
///////////////////////////////////////////////////////////////////////////////
struct Char
{
public:
    ///////////////////////////////////////////////////////////////////////////
    /// \brief
    ///
    /// \param ch
    ///
    /// \return
    ///
    ///////////////////////////////////////////////////////////////////////////
    AXIOM_NODISCARD static bool isAlNum(char ch);

    ///////////////////////////////////////////////////////////////////////////
    /// \brief
    ///
    /// \param ch
    ///
    /// \return
    ///
    ///////////////////////////////////////////////////////////////////////////
    AXIOM_NODISCARD static bool isAlpha(char ch);

    ///////////////////////////////////////////////////////////////////////////
    /// \brief
    ///
    /// \param ch
    ///
    /// \return
    ///
    ///////////////////////////////////////////////////////////////////////////
    AXIOM_NODISCARD static bool isCntrl(char ch);

    ///////////////////////////////////////////////////////////////////////////
    /// \brief
    ///
    /// \param ch
    ///
    /// \return
    ///
    ///////////////////////////////////////////////////////////////////////////
    AXIOM_NODISCARD static bool isDigit(char ch);

    ///////////////////////////////////////////////////////////////////////////
    /// \brief
    ///
    /// \param ch
    ///
    /// \return
    ///
    ///////////////////////////////////////////////////////////////////////////
    AXIOM_NODISCARD static bool isGraph(char ch);

    ///////////////////////////////////////////////////////////////////////////
    /// \brief
    ///
    /// \param ch
    ///
    /// \return
    ///
    ///////////////////////////////////////////////////////////////////////////
    AXIOM_NODISCARD static bool isLower(char ch);

    ///////////////////////////////////////////////////////////////////////////
    /// \brief
    ///
    /// \param ch
    ///
    /// \return
    ///
    ///////////////////////////////////////////////////////////////////////////
    AXIOM_NODISCARD static bool isPrint(char ch);

    ///////////////////////////////////////////////////////////////////////////
    /// \brief
    ///
    /// \param ch
    ///
    /// \return
    ///
    ///////////////////////////////////////////////////////////////////////////
    AXIOM_NODISCARD static bool isPunct(char ch);

    ///////////////////////////////////////////////////////////////////////////
    /// \brief
    ///
    /// \param ch
    ///
    /// \return
    ///
    ///////////////////////////////////////////////////////////////////////////
    AXIOM_NODISCARD static bool isSpace(char ch);

    ///////////////////////////////////////////////////////////////////////////
    /// \brief
    ///
    /// \param ch
    ///
    /// \return
    ///
    ///////////////////////////////////////////////////////////////////////////
    AXIOM_NODISCARD static bool isUpper(char ch);

    ///////////////////////////////////////////////////////////////////////////
    /// \brief
    ///
    /// \param ch
    ///
    /// \return
    ///
    ///////////////////////////////////////////////////////////////////////////
    AXIOM_NODISCARD static bool isXDigit(char ch);

    ///////////////////////////////////////////////////////////////////////////
    /// \brief
    ///
    /// \param ch
    ///
    /// \return
    ///
    ///////////////////////////////////////////////////////////////////////////
    AXIOM_NODISCARD static char toLower(char ch);

    ///////////////////////////////////////////////////////////////////////////
    /// \brief
    ///
    /// \param ch
    ///
    /// \return
    ///
    ///////////////////////////////////////////////////////////////////////////
    AXIOM_NODISCARD static char toUpper(char ch);
};

} // namespace ax::container