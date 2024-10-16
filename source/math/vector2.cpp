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
#include <axiom/math/vector2.hpp>
#include <axiom/math/utilities.hpp>

///////////////////////////////////////////////////////////////////////////////
// Forward Vector2 from ax::math
///////////////////////////////////////////////////////////////////////////////
using ax::math::Vector2;

///////////////////////////////////////////////////////////////////////////////
Vector2::Vector2(void) : x(0.f), y(0.f) {}

///////////////////////////////////////////////////////////////////////////////
Vector2::Vector2(float f) : x(f), y(f) {}

///////////////////////////////////////////////////////////////////////////////
Vector2::Vector2(float x, float y) : x(x), y(y) {}

///////////////////////////////////////////////////////////////////////////////
float& Vector2::operator[](Int32 index)
{
    CHECK(index >= 0 && index <= 1);
    return (xy[index]);
}

///////////////////////////////////////////////////////////////////////////////
const float& Vector2::operator[](Int32 index) const
{
    CHECK(index >= 0 && index <= 1);
    return (xy[index]);
}

///////////////////////////////////////////////////////////////////////////////
AXIOM_NODISCARD Vector2 operator+(const Vector2& lhs)
{
    return (Vector2(+lhs.x, +lhs.y));
}

///////////////////////////////////////////////////////////////////////////////
AXIOM_NODISCARD Vector2 operator+(const Vector2& lhs, const Vector2& rhs)
{
    return (Vector2(lhs.x + rhs.x, lhs.y + rhs.y));
}

///////////////////////////////////////////////////////////////////////////////
AXIOM_NODISCARD Vector2 operator+(const Vector2& lhs, float rhs)
{
    return (Vector2(lhs.x + rhs, lhs.y + rhs));
}

///////////////////////////////////////////////////////////////////////////////
AXIOM_NODISCARD Vector2 operator+(float lhs, const Vector2& rhs)
{
    return (Vector2(lhs + rhs.x, lhs + rhs.y));
}

///////////////////////////////////////////////////////////////////////////////
AXIOM_NODISCARD Vector2 operator-(const Vector2& lhs)
{
    return (Vector2(-lhs.x, -lhs.y));
}

///////////////////////////////////////////////////////////////////////////////
AXIOM_NODISCARD Vector2 operator-(const Vector2& lhs, const Vector2& rhs)
{
    return (Vector2(lhs.x - rhs.x, lhs.y - rhs.y));
}

///////////////////////////////////////////////////////////////////////////////
AXIOM_NODISCARD Vector2 operator-(const Vector2& lhs, float rhs)
{
    return (Vector2(lhs.x - rhs, lhs.y - rhs));
}

///////////////////////////////////////////////////////////////////////////////
AXIOM_NODISCARD Vector2 operator-(float lhs, const Vector2& rhs)
{
    return (Vector2(lhs - rhs.x, lhs - rhs.y));
}

///////////////////////////////////////////////////////////////////////////////
AXIOM_NODISCARD Vector2 operator*(const Vector2& lhs, const Vector2& rhs)
{
    return (Vector2(lhs.x * rhs.x, lhs.y * rhs.y));
}

///////////////////////////////////////////////////////////////////////////////
AXIOM_NODISCARD Vector2 operator*(const Vector2& lhs, float rhs)
{
    return (Vector2(lhs.x * rhs, lhs.y * rhs));
}

///////////////////////////////////////////////////////////////////////////////
AXIOM_NODISCARD Vector2 operator*(float lhs, const Vector2& rhs)
{
    return (Vector2(lhs * rhs.x, lhs * rhs.y));
}

///////////////////////////////////////////////////////////////////////////////
AXIOM_NODISCARD Vector2 operator/(const Vector2& lhs, const Vector2& rhs)
{
    CHECK(rhs.x != 0.f && rhs.y != 0.f);
    return (Vector2(lhs.x / rhs.x, lhs.y / rhs.y));
}

///////////////////////////////////////////////////////////////////////////////
AXIOM_NODISCARD Vector2 operator/(const Vector2& lhs, float rhs)
{
    CHECK(rhs != 0.f);
    return (Vector2(lhs.x / rhs, lhs.y / rhs));
}

///////////////////////////////////////////////////////////////////////////////
AXIOM_NODISCARD Vector2 operator/(float lhs, const Vector2& rhs)
{
    CHECK(rhs.x != 0.f && rhs.y != 0.f);
    return (Vector2(lhs / rhs.x, lhs / rhs.y));
}

///////////////////////////////////////////////////////////////////////////////
Vector2& operator+=(Vector2& lhs, const Vector2& rhs)
{
    lhs.x += rhs.x;
    lhs.y += rhs.y;
    return (lhs);
}

///////////////////////////////////////////////////////////////////////////////
Vector2& operator+=(Vector2& lhs, float rhs)
{
    lhs.x += rhs;
    lhs.y += rhs;
    return (lhs);
}

///////////////////////////////////////////////////////////////////////////////
Vector2& operator-=(Vector2& lhs, const Vector2& rhs)
{
    lhs.x -= rhs.x;
    lhs.y -= rhs.y;
    return (lhs);
}

///////////////////////////////////////////////////////////////////////////////
Vector2& operator-=(Vector2& lhs, float rhs)
{
    lhs.x -= rhs;
    lhs.y -= rhs;
    return (lhs);
}

///////////////////////////////////////////////////////////////////////////////
Vector2& operator*=(Vector2& lhs, const Vector2& rhs)
{
    lhs.x *= rhs.x;
    lhs.y *= rhs.y;
    return (lhs);
}

///////////////////////////////////////////////////////////////////////////////
Vector2& operator*=(Vector2& lhs, float rhs)
{
    lhs.x *= rhs;
    lhs.y *= rhs;
    return (lhs);
}

///////////////////////////////////////////////////////////////////////////////
Vector2& operator/=(Vector2& lhs, const Vector2& rhs)
{
    CHECK(rhs.x != 0.f && rhs.y != 0.f);
    lhs.x /= rhs.x;
    lhs.y /= rhs.y;
    return (lhs);
}

///////////////////////////////////////////////////////////////////////////////
Vector2& operator/=(Vector2& lhs, float rhs)
{
    CHECK(rhs != 0.f);
    lhs.x /= rhs;
    lhs.y /= rhs;
    return (lhs);
}

///////////////////////////////////////////////////////////////////////////////
AXIOM_NODISCARD bool operator==(const Vector2& lhs, const Vector2& rhs)
{
    return ((lhs.x == rhs.x) && (lhs.y == rhs.y));
}

///////////////////////////////////////////////////////////////////////////////
AXIOM_NODISCARD bool operator==(const Vector2& lhs, float rhs)
{
    return ((lhs.x == rhs) && (lhs.y == rhs));
}

///////////////////////////////////////////////////////////////////////////////
AXIOM_NODISCARD bool operator==(float lhs, const Vector2& rhs)
{
    return ((lhs == rhs.x) && (lhs == rhs.y));
}

///////////////////////////////////////////////////////////////////////////////
AXIOM_NODISCARD bool operator!=(const Vector2& lhs, const Vector2& rhs)
{
    return ((lhs.x != rhs.x) || (lhs.y != rhs.y));
}

///////////////////////////////////////////////////////////////////////////////
AXIOM_NODISCARD bool operator!=(const Vector2& lhs, float rhs)
{
    return ((lhs.x != rhs) || (lhs.y != rhs));
}

///////////////////////////////////////////////////////////////////////////////
AXIOM_NODISCARD bool operator!=(float lhs, const Vector2& rhs)
{
    return ((lhs != rhs.x) || (lhs != rhs.y));
}

///////////////////////////////////////////////////////////////////////////////
AXIOM_NODISCARD bool operator<(const Vector2& lhs, const Vector2& rhs)
{
    return ((lhs.x < rhs.x) && (lhs.y < rhs.y));
}

///////////////////////////////////////////////////////////////////////////////
AXIOM_NODISCARD bool operator<(const Vector2& lhs, float rhs)
{
    return ((lhs.x < rhs) && (lhs.y < rhs));
}

///////////////////////////////////////////////////////////////////////////////
AXIOM_NODISCARD bool operator<(float lhs, const Vector2& rhs)
{
    return ((lhs < rhs.x) && (lhs < rhs.y));
}

///////////////////////////////////////////////////////////////////////////////
AXIOM_NODISCARD bool operator<=(const Vector2& lhs, const Vector2& rhs)
{
    return ((lhs.x <= rhs.x) && (lhs.y <= rhs.y));
}

///////////////////////////////////////////////////////////////////////////////
AXIOM_NODISCARD bool operator<=(const Vector2& lhs, float rhs)
{
    return ((lhs.x <= rhs) && (lhs.y <= rhs));
}

///////////////////////////////////////////////////////////////////////////////
AXIOM_NODISCARD bool operator<=(float lhs, const Vector2& rhs)
{
    return ((lhs <= rhs.x) && (lhs <= rhs.y));
}

///////////////////////////////////////////////////////////////////////////////
AXIOM_NODISCARD bool operator>(const Vector2& lhs, const Vector2& rhs)
{
    return ((lhs.x > rhs.x) && (lhs.y > rhs.y));
}

///////////////////////////////////////////////////////////////////////////////
AXIOM_NODISCARD bool operator>(const Vector2& lhs, float rhs)
{
    return ((lhs.x > rhs) && (lhs.y > rhs));
}

///////////////////////////////////////////////////////////////////////////////
AXIOM_NODISCARD bool operator>(float lhs, const Vector2& rhs)
{
    return ((lhs > rhs.x) && (lhs > rhs.y));
}

///////////////////////////////////////////////////////////////////////////////
AXIOM_NODISCARD bool operator>=(const Vector2& lhs, const Vector2& rhs)
{
    return ((lhs.x >= rhs.x) && (lhs.y >= rhs.y));
}

///////////////////////////////////////////////////////////////////////////////
AXIOM_NODISCARD bool operator>=(const Vector2& lhs, float rhs)
{
    return ((lhs.x >= rhs) && (lhs.y >= rhs));
}

///////////////////////////////////////////////////////////////////////////////
AXIOM_NODISCARD bool operator>=(float lhs, const Vector2& rhs)
{
    return ((lhs >= rhs.x) && (lhs >= rhs.y));
}

///////////////////////////////////////////////////////////////////////////////
Vector2& operator++(Vector2& lhs)
{
    lhs.x++;
    lhs.y++;
    return (lhs);
}

///////////////////////////////////////////////////////////////////////////////
Vector2& operator++(Vector2& lhs, int)
{
    lhs.x++;
    lhs.y++;
    return (lhs);
}

///////////////////////////////////////////////////////////////////////////////
Vector2& operator--(Vector2& lhs)
{
    lhs.x--;
    lhs.y--;
    return (lhs);
}

///////////////////////////////////////////////////////////////////////////////
Vector2& operator--(Vector2& lhs, int)
{
    lhs.x--;
    lhs.y--;
    return (lhs);
}

///////////////////////////////////////////////////////////////////////////////
std::ostream& operator<<(std::ostream& lhs, const Vector2& rhs)
{
    lhs << '(' << rhs.x << ", " << rhs.y << ')';
    return (lhs);
}
