//////////////////////////////////////////////////////////////////////////////
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
#include <axiom/math/utilities.hpp>
#include <axiom/math/defines.hpp>
#include <math.h>

///////////////////////////////////////////////////////////////////////////////
// Forward the ax::math namespace to axm
///////////////////////////////////////////////////////////////////////////////
namespace axm = ax::math;

///////////////////////////////////////////////////////////////////////////////
AXIOM_NODISCARD float axm::sqrt(float x)
{
    return (sqrtf(x));
}

///////////////////////////////////////////////////////////////////////////////
AXIOM_NODISCARD double axm::sqrt(double x)
{
    return (sqrt(x));
}

///////////////////////////////////////////////////////////////////////////////
AXIOM_NODISCARD float axm::invSqrt(float x)
{
    return (1.f / axm::sqrt(x));
}

///////////////////////////////////////////////////////////////////////////////
AXIOM_NODISCARD double axm::invSqrt(double x)
{
    return (1.0 / axm::sqrt(x));
}

///////////////////////////////////////////////////////////////////////////////
AXIOM_NODISCARD float axm::round(float x)
{
    return (roundf(x));
}

///////////////////////////////////////////////////////////////////////////////
AXIOM_NODISCARD double axm::round(double x)
{
    return (round(x));
}

///////////////////////////////////////////////////////////////////////////////
AXIOM_NODISCARD float axm::radiansToDegrees(float radians)
{
    return (radians * (180.f / PI));
}

///////////////////////////////////////////////////////////////////////////////
AXIOM_NODISCARD double axm::radiansToDegrees(double radians)
{
    return (radians * (180.0 / DOUBLE_PI));
}

///////////////////////////////////////////////////////////////////////////////
AXIOM_NODISCARD float axm::degreesToRadians(float degrees)
{
    return (degrees * (PI / 180.f));
}

///////////////////////////////////////////////////////////////////////////////
AXIOM_NODISCARD double axm::degreesToRadians(double degrees)
{
    return (degrees * (DOUBLE_PI / 180.0));
}

///////////////////////////////////////////////////////////////////////////////
AXIOM_NODISCARD float axm::unwindRadians(float angle)
{
    while (angle > PI)
    {
        angle -= TWO_PI;
    }
    while (angle < -PI)
    {
        angle += TWO_PI;
    }
    return (angle);
}

///////////////////////////////////////////////////////////////////////////////
AXIOM_NODISCARD double axm::unwindRadians(double angle)
{
    while (angle > PI)
    {
        angle -= TWO_PI;
    }
    while (angle < -PI)
    {
        angle += TWO_PI;
    }
    return (angle);
}

///////////////////////////////////////////////////////////////////////////////
AXIOM_NODISCARD float axm::unwindDegrees(float angle)
{
    while (angle > 180.f)
    {
        angle -= 360.f;
    }
    while (angle < -180.f)
    {
        angle += 360.f;
    }
    return (angle);
}

///////////////////////////////////////////////////////////////////////////////
AXIOM_NODISCARD double axm::unwindDegrees(double angle)
{
    while (angle > 180.0)
    {
        angle -= 360.0;
    }
    while (angle < -180.0)
    {
        angle += 360.0;
    }
    return (angle);
}

///////////////////////////////////////////////////////////////////////////////
AXIOM_NODISCARD float lerp(float a, float b, float alpha)
{
    return (a + alpha * (b - a));
}

///////////////////////////////////////////////////////////////////////////////
AXIOM_NODISCARD double lerp(double a, double b, double alpha)
{
    return (a + alpha * (b - a));
}
