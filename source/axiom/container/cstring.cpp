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
#include <axiom/container/cstring.hpp>

///////////////////////////////////////////////////////////////////////////////
// Forward CString from ax::container
///////////////////////////////////////////////////////////////////////////////
using ax::container::CString;

///////////////////////////////////////////////////////////////////////////////
int CString::_strlenCompare(Uint64 longword, const char* cp)
{
    int max = 4;

    if (sizeof(longword) > 4)
    {
        max = 8;
    }
    for (int i = 0; i < max; i++)
    {
        if (cp[i] == 0)
        {
            return (i);
        }
    }
    return (-1);
}

///////////////////////////////////////////////////////////////////////////////
Uint64 CString::strlen(const char* str)
{
    const char* ptr;
    const Uint64* longwordPtr;
    Uint64 longword, himagic, lomagic;

    for (ptr = str; ((Uint64)ptr & (sizeof(longword) - 1)) != 0; ++ptr)
    {
        if (*ptr == '\0')
        {
            return (ptr - str);
        }
    }

    longwordPtr = (Uint64*)ptr;
    himagic = 0x80808080L;
    lomagic = 0x01010101L;

    if (sizeof(longword) > 4)
    {
        himagic = ((himagic << 16) << 16) | himagic;
        lomagic = ((lomagic << 16) << 16) | lomagic;
    }
    for (;;)
    {
        longword = *longwordPtr++;
        if (((longword - lomagic) & ~longword & himagic) == 0)
        {
            continue;
        }
        const char* cp = (const char*)(longwordPtr - 1);
        int result = _strlenCompare(longword, cp);
        if (result != -1)
        {
            return (cp - str + result);
        }
    }
}
