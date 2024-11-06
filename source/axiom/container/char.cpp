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
#include <axiom/container/char.hpp>

///////////////////////////////////////////////////////////////////////////////
// Forward Char from ax::container
///////////////////////////////////////////////////////////////////////////////
using ax::container::Char;

///////////////////////////////////////////////////////////////////////////////
AXIOM_NODISCARD bool Char::isAlNum(char ch)
{
    return (isAlpha(ch) || isDigit(ch));
}

///////////////////////////////////////////////////////////////////////////////
AXIOM_NODISCARD bool Char::isAlpha(char ch)
{
    return (
        (ch >= 'a' && ch <= 'z') ||
        (ch >= 'A' && ch <= 'Z')
    );
}

///////////////////////////////////////////////////////////////////////////////
AXIOM_NODISCARD bool Char::isCntrl(char ch)
{
    return (
        (ch >= 0 && ch <= 31) ||
        ch == 127
    );
}

///////////////////////////////////////////////////////////////////////////////
AXIOM_NODISCARD bool Char::isDigit(char ch)
{
    return (ch >= '0' && ch <= '9');
}

///////////////////////////////////////////////////////////////////////////////
AXIOM_NODISCARD bool Char::isGraph(char ch)
{
    return (isPrint(ch) && !isSpace(ch));
}

///////////////////////////////////////////////////////////////////////////////
AXIOM_NODISCARD bool Char::isLower(char ch)
{
    return (ch >= 'a' && ch <= 'z');
}

///////////////////////////////////////////////////////////////////////////////
AXIOM_NODISCARD bool Char::isPrint(char ch)
{
    return (ch >= 32 && ch <= 126);
}

///////////////////////////////////////////////////////////////////////////////
AXIOM_NODISCARD bool Char::isPunct(char ch)
{
    return (
        ch == '!' ||
        (ch >= '"' && ch <= '&') ||
        (ch >= '(' && ch <= '/') ||
        (ch >= ':' && ch <= '?') ||
        (ch >= '[' && ch <= '`') ||
        (ch >= '{' && ch <= '~')
    );
}

///////////////////////////////////////////////////////////////////////////////
AXIOM_NODISCARD bool Char::isSpace(char ch)
{
    return (
        ch == '\t' ||
        ch == '\n' ||
        ch == '\v' ||
        ch == '\f' ||
        ch == '\r' ||
        ch == ' '
    );
}

///////////////////////////////////////////////////////////////////////////////
AXIOM_NODISCARD bool Char::isUpper(char ch)
{
    return (ch >= 'A' && ch <= 'Z');
}

///////////////////////////////////////////////////////////////////////////////
AXIOM_NODISCARD bool Char::isXDigit(char ch)
{
    return (
        (ch >= '0' && ch <= '9') ||
        (ch >= 'a' && ch <= 'f') ||
        (ch >= 'A' && ch <= 'F')
    );
}

///////////////////////////////////////////////////////////////////////////////
AXIOM_NODISCARD char Char::toLower(char ch)
{
    return (isLower(ch) ? (ch + 32) : ch);
}

///////////////////////////////////////////////////////////////////////////////
AXIOM_NODISCARD char Char::toUpper(char ch)
{
    return (isUpper(ch) ? (ch - 32) : ch);
}
