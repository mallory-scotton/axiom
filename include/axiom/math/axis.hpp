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
// Namespace ax::math
///////////////////////////////////////////////////////////////////////////////
namespace ax::math
{

///////////////////////////////////////////////////////////////////////////////
// Namespace ax::math::Axis
///////////////////////////////////////////////////////////////////////////////
namespace Axis
{

///////////////////////////////////////////////////////////////////////////////
/// \brief Generic axis enum.
///
///////////////////////////////////////////////////////////////////////////////
enum Type
{
    None,       //<!
    X,          //<!
    Y,          //<!
    Z           //<!
};

} // namespace ax::math::Axis

///////////////////////////////////////////////////////////////////////////////
// Namespace ax::math::AxisList
///////////////////////////////////////////////////////////////////////////////
namespace AxisList
{

///////////////////////////////////////////////////////////////////////////////
/// \brief Extended axis enum for more specialized usage.
///
///////////////////////////////////////////////////////////////////////////////
enum Type
{
    None        = 0,                //<!
    X           = 1,                //<!
    Y           = 2,                //<!
    Z           = 4,                //<!
    Screen      = 8,                //<!
    XY          = X | Y,            //<!
    XZ          = X | Z,            //<!
    YZ          = Y | Z,            //<!
    XYZ         = X | Y | Z,        //<!
    All         = XYZ | Screen,     //<!
    ZRotation   = YZ,               //<! Alias over Axis YZ.
    Rotate2D    = Screen            //<! Alias oer Screen.
};

} // namespace ax::math::AxisList

} // namespace ax::math
