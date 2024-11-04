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
#include <axiom/math/vector3.hpp>
#include <axiom/math/utilities.hpp>

///////////////////////////////////////////////////////////////////////////////
// Forward Vector2, Vector3 and Vector4 from ax::math
///////////////////////////////////////////////////////////////////////////////
using ax::math::Vector2;
using ax::math::Vector3;
using ax::math::Vector4;

///////////////////////////////////////////////////////////////////////////////
Vector3::Vector3(void) : x(0.f), y(0.f), z(0.f) {}

///////////////////////////////////////////////////////////////////////////////
Vector3::Vector3(float f) : x(f), y(f), z(f) {}

///////////////////////////////////////////////////////////////////////////////
Vector3::Vector3(float x, float y, float z) : x(x), y(y), z(z) {}

///////////////////////////////////////////////////////////////////////////////
Vector3::Vector3(const Vector2& vector, float z)
    : x(vector.x), y(vector.y), z(z) {}

///////////////////////////////////////////////////////////////////////////////
Vector3::Vector3(const Vector4& vector)
    : x(vector.x), y(vector.y), z(vector.z) {}

///////////////////////////////////////////////////////////////////////////////
float& Vector3::operator[](Int32 index)
{
    CHECK(index >= 0 && index <= 2);
    return (xyz[index]);
}

///////////////////////////////////////////////////////////////////////////////
const float& Vector3::operator[](Int32 index) const
{
    CHECK(index >= 0 && index <= 2);
    return (xyz[index]);
}

///////////////////////////////////////////////////////////////////////////////
AXIOM_NODISCARD Vector3 operator+(const Vector3& lhs)
{
    return (Vector3(+lhs.x, +lhs.y, +lhs.z));
}

///////////////////////////////////////////////////////////////////////////////
AXIOM_NODISCARD Vector3 operator+(const Vector3& lhs, const Vector3& rhs)
{
    return (Vector3(lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z));
}

///////////////////////////////////////////////////////////////////////////////
AXIOM_NODISCARD Vector3 operator+(const Vector3& lhs, float rhs)
{
    return (Vector3(lhs.x + rhs, lhs.y + rhs, lhs.z + rhs));
}

///////////////////////////////////////////////////////////////////////////////
AXIOM_NODISCARD Vector3 operator+(float lhs, const Vector3& rhs)
{
    return (Vector3(lhs + rhs.x, lhs + rhs.y, lhs + rhs.z));
}

///////////////////////////////////////////////////////////////////////////////
AXIOM_NODISCARD Vector3 operator-(const Vector3& lhs)
{
    return (Vector3(-lhs.x, -lhs.y, -lhs.z));
}

///////////////////////////////////////////////////////////////////////////////
AXIOM_NODISCARD Vector3 operator-(const Vector3& lhs, const Vector3& rhs)
{
    return (Vector3(lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z));
}

///////////////////////////////////////////////////////////////////////////////
AXIOM_NODISCARD Vector3 operator-(const Vector3& lhs, float rhs)
{
    return (Vector3(lhs.x - rhs, lhs.y - rhs, lhs.z - rhs));
}

///////////////////////////////////////////////////////////////////////////////
AXIOM_NODISCARD Vector3 operator-(float lhs, const Vector3& rhs)
{
    return (Vector3(lhs - rhs.x, lhs - rhs.y, lhs - rhs.z));
}

///////////////////////////////////////////////////////////////////////////////
AXIOM_NODISCARD Vector3 operator*(const Vector3& lhs, const Vector3& rhs)
{
    return (Vector3(lhs.x * rhs.x, lhs.y * rhs.y, lhs.z * rhs.z));
}

///////////////////////////////////////////////////////////////////////////////
AXIOM_NODISCARD Vector3 operator*(const Vector3& lhs, float rhs)
{
    return (Vector3(lhs.x * rhs, lhs.y * rhs, lhs.z * rhs));
}

///////////////////////////////////////////////////////////////////////////////
AXIOM_NODISCARD Vector3 operator*(float lhs, const Vector3& rhs)
{
    return (Vector3(lhs * rhs.x, lhs * rhs.y, lhs * rhs.z));
}

///////////////////////////////////////////////////////////////////////////////
AXIOM_NODISCARD Vector3 operator/(const Vector3& lhs, const Vector3& rhs)
{
    CHECK(rhs.x != 0.f && rhs.y != 0.f && rhs.z != 0.f);
    return (Vector3(lhs.x / rhs.x, lhs.y / rhs.y, lhs.z / rhs.z));
}

///////////////////////////////////////////////////////////////////////////////
AXIOM_NODISCARD Vector3 operator/(const Vector3& lhs, float rhs)
{
    CHECK(rhs != 0.f);
    return (Vector3(lhs.x / rhs, lhs.y / rhs, lhs.z / rhs));
}

///////////////////////////////////////////////////////////////////////////////
AXIOM_NODISCARD Vector3 operator/(float lhs, const Vector3& rhs)
{
    CHECK(rhs.x != 0.f && rhs.y != 0.f && rhs.z != 0.f);
    return (Vector3(lhs / rhs.x, lhs / rhs.y, lhs / rhs.z));
}

///////////////////////////////////////////////////////////////////////////////
Vector3& operator+=(Vector3& lhs, const Vector3& rhs)
{
    lhs.x += rhs.x;
    lhs.y += rhs.y;
    lhs.z += rhs.z;
    return (lhs);
}

///////////////////////////////////////////////////////////////////////////////
Vector3& operator+=(Vector3& lhs, float rhs)
{
    lhs.x += rhs;
    lhs.y += rhs;
    lhs.z += rhs;
    return (lhs);
}

///////////////////////////////////////////////////////////////////////////////
Vector3& operator-=(Vector3& lhs, const Vector3& rhs)
{
    lhs.x -= rhs.x;
    lhs.y -= rhs.y;
    lhs.z -= rhs.z;
    return (lhs);
}

///////////////////////////////////////////////////////////////////////////////
Vector3& operator-=(Vector3& lhs, float rhs)
{
    lhs.x -= rhs;
    lhs.y -= rhs;
    lhs.z -= rhs;
    return (lhs);
}

///////////////////////////////////////////////////////////////////////////////
Vector3& operator*=(Vector3& lhs, const Vector3& rhs)
{
    lhs.x *= rhs.x;
    lhs.y *= rhs.y;
    lhs.z *= rhs.z;
    return (lhs);
}

///////////////////////////////////////////////////////////////////////////////
Vector3& operator*=(Vector3& lhs, float rhs)
{
    lhs.x *= rhs;
    lhs.y *= rhs;
    lhs.z *= rhs;
    return (lhs);
}

///////////////////////////////////////////////////////////////////////////////
Vector3& operator/=(Vector3& lhs, const Vector3& rhs)
{
    CHECK(rhs.x != 0.f && rhs.y != 0.f && rhs.z != 0.f);
    lhs.x /= rhs.x;
    lhs.y /= rhs.y;
    lhs.z /= rhs.z;
    return (lhs);
}

///////////////////////////////////////////////////////////////////////////////
Vector3& operator/=(Vector3& lhs, float rhs)
{
    CHECK(rhs != 0.f);
    lhs.x /= rhs;
    lhs.y /= rhs;
    lhs.z /= rhs;
    return (lhs);
}

///////////////////////////////////////////////////////////////////////////////
AXIOM_NODISCARD bool operator==(const Vector3& lhs, const Vector3& rhs)
{
    return ((lhs.x == rhs.x) && (lhs.y == rhs.y) && (lhs.z == rhs.z));
}

///////////////////////////////////////////////////////////////////////////////
AXIOM_NODISCARD bool operator==(const Vector3& lhs, float rhs)
{
    return ((lhs.x == rhs) && (lhs.y == rhs) && (lhs.z == rhs));
}

///////////////////////////////////////////////////////////////////////////////
AXIOM_NODISCARD bool operator==(float lhs, const Vector3& rhs)
{
    return ((lhs == rhs.x) && (lhs == rhs.y) && (lhs == rhs.z));
}

///////////////////////////////////////////////////////////////////////////////
AXIOM_NODISCARD bool operator!=(const Vector3& lhs, const Vector3& rhs)
{
    return ((lhs.x != rhs.x) || (lhs.y != rhs.y) || (lhs.z != rhs.z));
}

///////////////////////////////////////////////////////////////////////////////
AXIOM_NODISCARD bool operator!=(const Vector3& lhs, float rhs)
{
    return ((lhs.x != rhs) || (lhs.y != rhs) || (lhs.z != rhs));
}

///////////////////////////////////////////////////////////////////////////////
AXIOM_NODISCARD bool operator!=(float lhs, const Vector3& rhs)
{
    return ((lhs != rhs.x) || (lhs != rhs.y) || (lhs != rhs.z));
}

///////////////////////////////////////////////////////////////////////////////
AXIOM_NODISCARD bool operator<(const Vector3& lhs, const Vector3& rhs)
{
    return ((lhs.x < rhs.x) && (lhs.y < rhs.y) && (lhs.z < rhs.z));
}

///////////////////////////////////////////////////////////////////////////////
AXIOM_NODISCARD bool operator<(const Vector3& lhs, float rhs)
{
    return ((lhs.x < rhs) && (lhs.y < rhs) && (lhs.z < rhs));
}

///////////////////////////////////////////////////////////////////////////////
AXIOM_NODISCARD bool operator<(float lhs, const Vector3& rhs)
{
    return ((lhs < rhs.x) && (lhs < rhs.y) && (lhs < rhs.z));
}

///////////////////////////////////////////////////////////////////////////////
AXIOM_NODISCARD bool operator<=(const Vector3& lhs, const Vector3& rhs)
{
    return ((lhs.x <= rhs.x) && (lhs.y <= rhs.y) && (lhs.z <= rhs.z));
}

///////////////////////////////////////////////////////////////////////////////
AXIOM_NODISCARD bool operator<=(const Vector3& lhs, float rhs)
{
    return ((lhs.x <= rhs) && (lhs.y <= rhs) && (lhs.z <= rhs));
}

///////////////////////////////////////////////////////////////////////////////
AXIOM_NODISCARD bool operator<=(float lhs, const Vector3& rhs)
{
    return ((lhs <= rhs.x) && (lhs <= rhs.y) && (lhs <= rhs.z));
}

///////////////////////////////////////////////////////////////////////////////
AXIOM_NODISCARD bool operator>(const Vector3& lhs, const Vector3& rhs)
{
    return ((lhs.x > rhs.x) && (lhs.y > rhs.y) && (lhs.z > rhs.z));
}

///////////////////////////////////////////////////////////////////////////////
AXIOM_NODISCARD bool operator>(const Vector3& lhs, float rhs)
{
    return ((lhs.x > rhs) && (lhs.y > rhs) && (lhs.z > rhs));
}

///////////////////////////////////////////////////////////////////////////////
AXIOM_NODISCARD bool operator>(float lhs, const Vector3& rhs)
{
    return ((lhs > rhs.x) && (lhs > rhs.y) && (lhs > rhs.z));
}

///////////////////////////////////////////////////////////////////////////////
AXIOM_NODISCARD bool operator>=(const Vector3& lhs, const Vector3& rhs)
{
    return ((lhs.x >= rhs.x) && (lhs.y >= rhs.y) && (lhs.z >= rhs.z));
}

///////////////////////////////////////////////////////////////////////////////
AXIOM_NODISCARD bool operator>=(const Vector3& lhs, float rhs)
{
    return ((lhs.x >= rhs) && (lhs.y >= rhs) && (lhs.z >= rhs));
}

///////////////////////////////////////////////////////////////////////////////
AXIOM_NODISCARD bool operator>=(float lhs, const Vector3& rhs)
{
    return ((lhs >= rhs.x) && (lhs >= rhs.y) && (lhs >= rhs.z));
}

///////////////////////////////////////////////////////////////////////////////
Vector3& operator++(Vector3& lhs)
{
    lhs.x++;
    lhs.y++;
    lhs.z++;
    return (lhs);
}

///////////////////////////////////////////////////////////////////////////////
Vector3& operator++(Vector3& lhs, int)
{
    lhs.x++;
    lhs.y++;
    lhs.z++;
    return (lhs);
}

///////////////////////////////////////////////////////////////////////////////
Vector3& operator--(Vector3& lhs)
{
    lhs.x--;
    lhs.y--;
    lhs.z--;
    return (lhs);
}

///////////////////////////////////////////////////////////////////////////////
Vector3& operator--(Vector3& lhs, int)
{
    lhs.x--;
    lhs.y--;
    lhs.z--;
    return (lhs);
}

///////////////////////////////////////////////////////////////////////////////
AXIOM_NODISCARD Vector3 operator^(const Vector3& lhs, const Vector3& rhs)
{
    return (Vector3(
        (lhs.y * rhs.z) - (lhs.z * rhs.y),
        (lhs.z * rhs.x) - (lhs.x * rhs.z),
        (lhs.x * rhs.y) - (lhs.y * rhs.x)
    ));
}

///////////////////////////////////////////////////////////////////////////////
AXIOM_NODISCARD float operator|(const Vector3& lhs, const Vector3& rhs)
{
    return ((lhs.x * rhs.x) + (lhs.y * rhs.y) + (lhs.z * rhs.z));
}

Vector3& operator^=(Vector3& lhs, const Vector3& rhs)
{
    float oldX = lhs.x;
    float oldY = lhs.y;
    float oldZ = lhs.z;

    lhs.x = (oldY * rhs.z) - (oldZ * rhs.y);
    lhs.y = (oldZ * rhs.x) - (oldX * rhs.z);
    lhs.z = (oldX * rhs.y) - (oldY * rhs.x);
    return (lhs);
}

///////////////////////////////////////////////////////////////////////////////
std::ostream& operator<<(std::ostream& lhs, const Vector3& rhs)
{
    lhs << '(' << rhs.x << ", " << rhs.y << ", " << rhs.z << ')';
    return (lhs);
}
