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
AXIOM_NODISCARD float operator^(const Vector2& lhs, const Vector2& rhs)
{
    return ((lhs.x * rhs.y) - (lhs.y * rhs.x));
}

///////////////////////////////////////////////////////////////////////////////
AXIOM_NODISCARD float operator|(const Vector2& lhs, const Vector2& rhs)
{
    return ((lhs.x * rhs.x) + (lhs.y * rhs.y));
}

///////////////////////////////////////////////////////////////////////////////
std::ostream& operator<<(std::ostream& lhs, const Vector2& rhs)
{
    lhs << '(' << rhs.x << ", " << rhs.y << ')';
    return (lhs);
}

///////////////////////////////////////////////////////////////////////////////
float& Vector2::component(Int32 index)
{
    CHECK(index >= 0 && index <= 1);
    return (xy[index]);
}

///////////////////////////////////////////////////////////////////////////////
const float& Vector2::component(Int32 index) const
{
    CHECK(index >= 0 && index <= 1);
    return (xy[index]);
}

///////////////////////////////////////////////////////////////////////////////
AXIOM_NODISCARD bool Vector2::componentWiseAllLessThan(const Vector2& other)
    const
{
    return ((x < other.x) && (y < other.y));
}

///////////////////////////////////////////////////////////////////////////////
AXIOM_NODISCARD bool Vector2::componentWiseAllGreaterThan(const Vector2& other)
    const
{
    return ((x > other.x) && (y > other.y));
}

///////////////////////////////////////////////////////////////////////////////
AXIOM_NODISCARD bool Vector2::componentWiseAllLessOrEqual(const Vector2& other)
    const
{
    return ((x <= other.x) && (y <= other.y));
}

///////////////////////////////////////////////////////////////////////////////
AXIOM_NODISCARD bool Vector2::componentWiseAllGreaterOrEqual(
    const Vector2& other) const
{
    return ((x >= other.x) && (y >= other.y));
}

///////////////////////////////////////////////////////////////////////////////
AXIOM_NODISCARD bool Vector2::equals(const Vector2& other, float tolerance)
    const
{
    return (
        (axm::abs(x - other.x) <= tolerance) &&
        (axm::abs(y - other.y) <= tolerance)
    );
}

///////////////////////////////////////////////////////////////////////////////
void Vector2::set(float x, float y)
{
    this->x = x;
    this->y = y;
}

///////////////////////////////////////////////////////////////////////////////
AXIOM_NODISCARD float Vector2::getMax(void) const
{
    return (axm::max(x, y));
}

///////////////////////////////////////////////////////////////////////////////
AXIOM_NODISCARD float Vector2::getAbsMax(void) const
{
    return (axm::max(axm::abs(x), axm::abs(y)));
}

///////////////////////////////////////////////////////////////////////////////
AXIOM_NODISCARD float Vector2::getMin(void) const
{
    return (axm::min(x, y));
}

///////////////////////////////////////////////////////////////////////////////
AXIOM_NODISCARD float Vector2::getAbsMin(void) const
{
    return (axm::min(axm::abs(x), axm::abs(y)));
}

///////////////////////////////////////////////////////////////////////////////
AXIOM_NODISCARD float Vector2::size(void) const
{
    return (axm::sqrt((x * x) + (y * y)));
}

///////////////////////////////////////////////////////////////////////////////
AXIOM_NODISCARD float Vector2::length(void) const
{
    return (size());
}

///////////////////////////////////////////////////////////////////////////////
AXIOM_NODISCARD float Vector2::sizeSquared(void) const
{
    return ((x * x) + (y * y));
}

///////////////////////////////////////////////////////////////////////////////
AXIOM_NODISCARD float Vector2::squaredLength(void) const
{
    return (sizeSquared());
}

///////////////////////////////////////////////////////////////////////////////
AXIOM_NODISCARD float Vector2::dot(const Vector2& other) const
{
    return ((x * other.x) + (y * other.y));
}

///////////////////////////////////////////////////////////////////////////////
AXIOM_NODISCARD Vector2 Vector2::getRotated(float angleDeg) const
{
    float sinus = 0.f;
    float cosine = 0.f;
    // TODO: Add sinus/cosine values
    return (Vector2(
        (cosine * x) - (sinus * y),
        (sinus * x) - (cosine * y)
    ));
}

///////////////////////////////////////////////////////////////////////////////
AXIOM_NODISCARD Vector2 Vector2::getSafeNormal(float tolerance)
    const
{
    const float squareSum = sizeSquared();

    if (squareSum > tolerance)
    {
        const float scale = axm::invSqrt(squareSum);
        return (Vector2(x * scale, y * scale));
    }
    return (Vector2::zeroVector);
}

///////////////////////////////////////////////////////////////////////////////
bool Vector2::normalize(float tolerance)
{
    const float squareSum = sizeSquared();

    if (squareSum > tolerance)
    {
        const float scale = axm::invSqrt(squareSum);
        x *= scale;
        y *= scale;
        return (true);
    }
    x = 0.f;
    y = 0.f;
    return (false);
}

///////////////////////////////////////////////////////////////////////////////
AXIOM_NODISCARD bool Vector2::isNearlyZero(float tolerance) const
{
    return (
        (axm::abs(x) <= tolerance) &&
        (axm::abs(y) <= tolerance)
    );
}

///////////////////////////////////////////////////////////////////////////////
void Vector2::toDirectionAndLength(Vector2& outDir, float& outLength) const
{
    outLength = size();
    if (outLength > SMALL_NUMBER)
    {
        float oneOverLength = 1.f / outLength;
        outDir = Vector2(x * oneOverLength, y * oneOverLength);
    }
    else
    {
        outDir = Vector2::zeroVector;
    }
}

///////////////////////////////////////////////////////////////////////////////
void Vector2::toDirectionAndLength(Vector2& outDir, double& outLength) const
{
    outLength = size();
    if (outLength > SMALL_NUMBER)
    {
        float oneOverLength = 1.f / outLength;
        outDir = Vector2(x * oneOverLength, y * oneOverLength);
    }
    else
    {
        outDir = Vector2::zeroVector;
    }
}

///////////////////////////////////////////////////////////////////////////////
AXIOM_NODISCARD bool Vector2::isZero(void) const
{
    return ((x == 0.f) && (y == 0.f));
}

///////////////////////////////////////////////////////////////////////////////
AXIOM_NODISCARD Vector2 Vector2::roundToVector(void) const
{
    return (Vector2(axm::round(x), axm::round(y)));
}

///////////////////////////////////////////////////////////////////////////////
AXIOM_NODISCARD Vector2 Vector2::clampAxes(float minAxisValue,
    float maxAxisValue) const
{
    return (Vector2(
        (axm::clamp(x, minAxisValue, maxAxisValue)),
        (axm::clamp(y, minAxisValue, maxAxisValue))
    ));
}

///////////////////////////////////////////////////////////////////////////////
AXIOM_NODISCARD Vector2 Vector2::getSignVector(void) const
{
    return (Vector2(axm::sign(x), axm::sign(y)));
}

///////////////////////////////////////////////////////////////////////////////
AXIOM_NODISCARD Vector2 Vector2::getAbs(void) const
{
    return (Vector2(axm::abs(x), axm::abs(y)));
}

///////////////////////////////////////////////////////////////////////////////
AXIOM_NODISCARD Vector2 Vector2::min(const Vector2& a, const Vector2& b)
{
    return (Vector2(
        axm::min(a.x, b.x),
        axm::min(a.y, b.y)
    ));
}

///////////////////////////////////////////////////////////////////////////////
AXIOM_NODISCARD Vector2 Vector2::min(const Vector2& a, const Vector2& b,
    const Vector2& c)
{
    return (Vector2(
        axm::min(a.x, b.x, c.x),
        axm::min(a.y, b.y, c.y)
    ));
}

///////////////////////////////////////////////////////////////////////////////
AXIOM_NODISCARD Vector2 Vector2::max(const Vector2& a, const Vector2& b)
{
    return (Vector2(
        axm::max(a.x, b.x),
        axm::max(a.y, b.y)
    ));
}

///////////////////////////////////////////////////////////////////////////////
AXIOM_NODISCARD Vector2 Vector2::max(const Vector2& a, const Vector2& b,
    const Vector2& c)
{
    return (Vector2(
        axm::max(a.x, b.x, c.x),
        axm::max(a.y, b.y, c.y)
    ));
}

///////////////////////////////////////////////////////////////////////////////
AXIOM_NODISCARD Vector2 Vector2::clamp(const Vector2& value,
    const Vector2& minValue, const Vector2& maxValue)
{
    return (Vector2(
        axm::clamp(value.x, minValue.x, maxValue.x),
        axm::clamp(value.y, minValue.y, maxValue.y)
    ));
}

///////////////////////////////////////////////////////////////////////////////
AXIOM_NODISCARD float Vector2::dotProduct(const Vector2& a, const Vector2& b)
{
    return (a | b);
}

///////////////////////////////////////////////////////////////////////////////
AXIOM_NODISCARD float Vector2::crossProduct(const Vector2& a, const Vector2& b)
{
    return (a ^ b);
}

///////////////////////////////////////////////////////////////////////////////
AXIOM_NODISCARD float Vector2::distSquared(const Vector2& a, const Vector2& b)
{
    return ((axm::square(b.x - a.x) + axm::square(b.y - a.y)));
}

///////////////////////////////////////////////////////////////////////////////
AXIOM_NODISCARD float Vector2::distance(const Vector2& a, const Vector2& b)
{
    return (axm::sqrt(Vector2::distSquared(a, b)));
}
