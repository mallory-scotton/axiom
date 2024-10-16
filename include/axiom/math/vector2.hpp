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
#include <axiom/math/types.hpp>
#include <axiom/math/defines.hpp>
#include <iostream>

///////////////////////////////////////////////////////////////////////////////
// Namespace ax::math
///////////////////////////////////////////////////////////////////////////////
namespace ax::math
{

///////////////////////////////////////////////////////////////////////////////
/// \brief
///
///////////////////////////////////////////////////////////////////////////////
struct Vector2
{
public:
    ///////////////////////////////////////////////////////////////////////////
    /// \brief
    ///
    ///////////////////////////////////////////////////////////////////////////
    union
    {
        struct
        {
            float x;        //<!
            float y;        //<!
        };
        float xy[2];        //<!
    };

public:
    ///////////////////////////////////////////////////////////////////////////
    /// \brief
    ///
    ///////////////////////////////////////////////////////////////////////////
    static const Vector2 zeroVector;    //<!
    static const Vector2 oneVector;     //<!
    static const Vector2 upVector;      //<!
    static const Vector2 downVector;    //<!
    static const Vector2 leftVector;    //<!
    static const Vector2 rightVector;   //<!
    static const Vector2 xAxisVector;   //<!
    static const Vector2 yAxisVector;   //<!

public:
    ///////////////////////////////////////////////////////////////////////////
    /// \brief
    ///
    ///////////////////////////////////////////////////////////////////////////
    Vector2(void);

    ///////////////////////////////////////////////////////////////////////////
    /// \brief
    ///
    /// \param f
    ///
    ///////////////////////////////////////////////////////////////////////////
    Vector2(float f);

    ///////////////////////////////////////////////////////////////////////////
    /// \brief
    ///
    /// \param x
    /// \param y
    ///
    ///////////////////////////////////////////////////////////////////////////
    Vector2(float x, float y);

public:
    ///////////////////////////////////////////////////////////////////////////
    /// \brief
    ///
    /// \param index
    ///
    /// \return
    ///
    ///////////////////////////////////////////////////////////////////////////
    AXIOM_NODISCARD float& operator[](Int32 index);

    ///////////////////////////////////////////////////////////////////////////
    /// \brief
    ///
    /// \param index
    ///
    /// \return
    ///
    ///////////////////////////////////////////////////////////////////////////
    AXIOM_NODISCARD const float& operator[](Int32 index) const;

public:
    ///////////////////////////////////////////////////////////////////////////
    /// \brief
    ///
    /// \param index
    ///
    /// \return
    ///
    ///////////////////////////////////////////////////////////////////////////
    float& component(Int32 index);

    ///////////////////////////////////////////////////////////////////////////
    /// \brief
    ///
    /// \param index
    ///
    /// \return
    ///
    ///////////////////////////////////////////////////////////////////////////
    const float& component(Int32 index) const;

    ///////////////////////////////////////////////////////////////////////////
    /// \brief
    ///
    /// \param other
    ///
    /// \return
    ///
    ///////////////////////////////////////////////////////////////////////////
    AXIOM_NODISCARD bool componentWiseAllLessThan(const Vector2& other) const;

    ///////////////////////////////////////////////////////////////////////////
    /// \brief
    ///
    /// \param other
    ///
    /// \return
    ///
    ///////////////////////////////////////////////////////////////////////////
    AXIOM_NODISCARD bool componentWiseAllGreaterThan(const Vector2& other)
        const;

    ///////////////////////////////////////////////////////////////////////////
    /// \brief
    ///
    /// \param other
    ///
    /// \return
    ///
    ///////////////////////////////////////////////////////////////////////////
    AXIOM_NODISCARD bool componentWiseAllLessOrEqual(const Vector2& other)
        const;

    ///////////////////////////////////////////////////////////////////////////
    /// \brief
    ///
    /// \param other
    ///
    /// \return
    ///
    ///////////////////////////////////////////////////////////////////////////
    AXIOM_NODISCARD bool componentWiseAllGreaterOrEqual(const Vector2& other)
        const;

    ///////////////////////////////////////////////////////////////////////////
    /// \brief
    ///
    /// \param other
    /// \param tolerance
    ///
    /// \return
    ///
    ///////////////////////////////////////////////////////////////////////////
    AXIOM_NODISCARD bool equals(const Vector2& other,
        float tolerance = KINDA_SMALL_NUMBER) const;

    ///////////////////////////////////////////////////////////////////////////
    /// \brief
    ///
    /// \param x
    /// \param y
    ///
    ///////////////////////////////////////////////////////////////////////////
    void set(float x, float y);

    ///////////////////////////////////////////////////////////////////////////
    /// \brief
    ///
    /// \return
    ///
    ///////////////////////////////////////////////////////////////////////////
    AXIOM_NODISCARD float getMax(void) const;

    ///////////////////////////////////////////////////////////////////////////
    /// \brief
    ///
    /// \return
    ///
    ///////////////////////////////////////////////////////////////////////////
    AXIOM_NODISCARD float getAbsMax(void) const;

    ///////////////////////////////////////////////////////////////////////////
    /// \brief
    ///
    /// \return
    ///
    ///////////////////////////////////////////////////////////////////////////
    AXIOM_NODISCARD float getMin(void) const;

    ///////////////////////////////////////////////////////////////////////////
    /// \brief
    ///
    /// \return
    ///
    ///////////////////////////////////////////////////////////////////////////
    AXIOM_NODISCARD float getAbsMin(void) const;

    ///////////////////////////////////////////////////////////////////////////
    /// \brief
    ///
    /// \return
    ///
    ///////////////////////////////////////////////////////////////////////////
    AXIOM_NODISCARD float size(void) const;

    ///////////////////////////////////////////////////////////////////////////
    /// \brief
    ///
    /// \return
    ///
    ///////////////////////////////////////////////////////////////////////////
    AXIOM_NODISCARD float length(void) const;

    ///////////////////////////////////////////////////////////////////////////
    /// \brief
    ///
    /// \return
    ///
    ///////////////////////////////////////////////////////////////////////////
    AXIOM_NODISCARD float sizeSquared(void) const;

    ///////////////////////////////////////////////////////////////////////////
    /// \brief
    ///
    /// \return
    ///
    ///////////////////////////////////////////////////////////////////////////
    AXIOM_NODISCARD float squaredLength(void) const;

    ///////////////////////////////////////////////////////////////////////////
    /// \brief
    ///
    /// \param other
    ///
    /// \return
    ///
    ///////////////////////////////////////////////////////////////////////////
    AXIOM_NODISCARD float dot(const Vector2& other) const;

    ///////////////////////////////////////////////////////////////////////////
    /// \brief
    ///
    /// \param angleDeg
    ///
    /// \return
    ///
    ///////////////////////////////////////////////////////////////////////////
    AXIOM_NODISCARD Vector2 getRotated(float angleDeg) const;

    ///////////////////////////////////////////////////////////////////////////
    /// \brief
    ///
    /// \param tolerance
    ///
    /// \return
    ///
    ///////////////////////////////////////////////////////////////////////////
    AXIOM_NODISCARD Vector2 getSafeNormal(float tolerance = SMALL_NUMBER)
        const;

    ///////////////////////////////////////////////////////////////////////////
    /// \brief
    ///
    /// \param tolerance
    ///
    /// \return
    ///
    ///////////////////////////////////////////////////////////////////////////
    bool normalize(float tolerance = SMALL_NUMBER);

    ///////////////////////////////////////////////////////////////////////////
    /// \brief
    ///
    /// \param tolerance
    ///
    /// \return
    ///
    ///////////////////////////////////////////////////////////////////////////
    AXIOM_NODISCARD bool isNearlyZero(float tolerance = KINDA_SMALL_NUMBER)
        const;

    ///////////////////////////////////////////////////////////////////////////
    /// \brief
    ///
    /// \param outDir
    /// \param outLength
    ///
    ///////////////////////////////////////////////////////////////////////////
    void toDirectionAndLength(Vector2& outDir, float& outLength) const;

    ///////////////////////////////////////////////////////////////////////////
    /// \brief
    ///
    /// \param outDir
    /// \param outLength
    ///
    ///////////////////////////////////////////////////////////////////////////
    void toDirectionAndLength(Vector2& outDir, double& outLength) const;

    ///////////////////////////////////////////////////////////////////////////
    /// \brief
    ///
    /// \return
    ///
    ///////////////////////////////////////////////////////////////////////////
    AXIOM_NODISCARD bool isZero(void) const;

    ///////////////////////////////////////////////////////////////////////////
    /// \brief
    ///
    /// \return
    ///
    ///////////////////////////////////////////////////////////////////////////
    AXIOM_NODISCARD Vector2 roundToVector(void) const;

    ///////////////////////////////////////////////////////////////////////////
    /// \brief
    ///
    /// \param minAxisValue
    /// \param maxAxisValue
    ///
    /// \return
    ///
    ///////////////////////////////////////////////////////////////////////////
    AXIOM_NODISCARD Vector2 clampAxes(float minAxisValue, float maxAxisValue)
        const;

    ///////////////////////////////////////////////////////////////////////////
    /// \brief
    ///
    /// \return
    ///
    ///////////////////////////////////////////////////////////////////////////
    AXIOM_NODISCARD Vector2 getSignVector(void) const;

    ///////////////////////////////////////////////////////////////////////////
    /// \brief
    ///
    /// \return
    ///
    ///////////////////////////////////////////////////////////////////////////
    AXIOM_NODISCARD Vector2 getAbs(void) const;

public:
    ///////////////////////////////////////////////////////////////////////////
    /// \brief
    ///
    /// \param a
    /// \param b
    ///
    /// \return
    ///
    ///////////////////////////////////////////////////////////////////////////
    AXIOM_NODISCARD static Vector2 min(const Vector2& a, const Vector2& b);

    ///////////////////////////////////////////////////////////////////////////
    /// \brief
    ///
    /// \param a
    /// \param b
    /// \param c
    ///
    /// \return
    ///
    ///////////////////////////////////////////////////////////////////////////
    AXIOM_NODISCARD static Vector2 min(const Vector2& a, const Vector2& b,
        const Vector2& c);

    ///////////////////////////////////////////////////////////////////////////
    /// \brief
    ///
    /// \param a
    /// \param b
    ///
    /// \return
    ///
    ///////////////////////////////////////////////////////////////////////////
    AXIOM_NODISCARD static Vector2 max(const Vector2& a, const Vector2& b);

    ///////////////////////////////////////////////////////////////////////////
    /// \brief
    ///
    /// \param a
    /// \param b
    /// \param c
    ///
    /// \return
    ///
    ///////////////////////////////////////////////////////////////////////////
    AXIOM_NODISCARD static Vector2 max(const Vector2& a, const Vector2& b,
        const Vector2& c);

    ///////////////////////////////////////////////////////////////////////////
    /// \brief
    ///
    /// \param value
    /// \param minValue
    /// \param maxValue
    ///
    /// \return
    ///
    ///////////////////////////////////////////////////////////////////////////
    AXIOM_NODISCARD static Vector2 clamp(const Vector2& value,
        const Vector2& minValue, const Vector2& maxValue);

    ///////////////////////////////////////////////////////////////////////////
    /// \brief
    ///
    /// \param a
    /// \param b
    ///
    /// \return
    ///
    ///////////////////////////////////////////////////////////////////////////
    AXIOM_NODISCARD static float dotProduct(const Vector2& a,
        const Vector2& b);

    ///////////////////////////////////////////////////////////////////////////
    /// \brief
    ///
    /// \param a
    /// \param b
    ///
    /// \return
    ///
    ///////////////////////////////////////////////////////////////////////////
    AXIOM_NODISCARD static float crossProduct(const Vector2& a,
        const Vector2& b);

    ///////////////////////////////////////////////////////////////////////////
    /// \brief
    ///
    /// \param a
    /// \param b
    ///
    /// \return
    ///
    ///////////////////////////////////////////////////////////////////////////
    AXIOM_NODISCARD static float distSquared(const Vector2& a,
        const Vector2& b);

    ///////////////////////////////////////////////////////////////////////////
    /// \brief
    ///
    /// \param a
    /// \param b
    ///
    /// \return
    ///
    ///////////////////////////////////////////////////////////////////////////
    AXIOM_NODISCARD static float distance(const Vector2& a, const Vector2& b);
};

} // namespace ax::math

///////////////////////////////////////////////////////////////////////////////
// Forward ax::math namespace
///////////////////////////////////////////////////////////////////////////////
namespace axm = ax::math;

///////////////////////////////////////////////////////////////////////////////
/// \brief
///
/// \param lhs
///
/// \return
///
///////////////////////////////////////////////////////////////////////////////
AXIOM_NODISCARD axm::Vector2 operator+(const axm::Vector2& lhs);

///////////////////////////////////////////////////////////////////////////////
/// \brief
///
/// \param lhs
/// \param rhs
///
/// \return
///
///////////////////////////////////////////////////////////////////////////////
AXIOM_NODISCARD axm::Vector2 operator+(const axm::Vector2& lhs,
    const axm::Vector2& rhs);

///////////////////////////////////////////////////////////////////////////////
/// \brief
///
/// \param lhs
/// \param rhs
///
/// \return
///
///////////////////////////////////////////////////////////////////////////////
AXIOM_NODISCARD axm::Vector2 operator+(const axm::Vector2& lhs, float rhs);

///////////////////////////////////////////////////////////////////////////////
/// \brief
///
/// \param lhs
/// \param rhs
///
/// \return
///
///////////////////////////////////////////////////////////////////////////////
AXIOM_NODISCARD axm::Vector2 operator+(float lhs, const axm::Vector2& rhs);

///////////////////////////////////////////////////////////////////////////////
/// \brief
///
/// \param lhs
///
/// \return
///
///////////////////////////////////////////////////////////////////////////////
AXIOM_NODISCARD axm::Vector2 operator-(const axm::Vector2& lhs);

///////////////////////////////////////////////////////////////////////////////
/// \brief
///
/// \param lhs
/// \param rhs
///
/// \return
///
///////////////////////////////////////////////////////////////////////////////
AXIOM_NODISCARD axm::Vector2 operator-(const axm::Vector2& lhs,
    const axm::Vector2& rhs);

///////////////////////////////////////////////////////////////////////////////
/// \brief
///
/// \param lhs
/// \param rhs
///
/// \return
///
///////////////////////////////////////////////////////////////////////////////
AXIOM_NODISCARD axm::Vector2 operator-(const axm::Vector2& lhs, float rhs);

///////////////////////////////////////////////////////////////////////////////
/// \brief
///
/// \param lhs
/// \param rhs
///
/// \return
///
///////////////////////////////////////////////////////////////////////////////
AXIOM_NODISCARD axm::Vector2 operator-(float lhs, const axm::Vector2& rhs);

///////////////////////////////////////////////////////////////////////////////
/// \brief
///
/// \param lhs
/// \param rhs
///
/// \return
///
///////////////////////////////////////////////////////////////////////////////
AXIOM_NODISCARD axm::Vector2 operator*(const axm::Vector2& lhs,
    const axm::Vector2& rhs);

///////////////////////////////////////////////////////////////////////////////
/// \brief
///
/// \param lhs
/// \param rhs
///
/// \return
///
///////////////////////////////////////////////////////////////////////////////
AXIOM_NODISCARD axm::Vector2 operator*(const axm::Vector2& lhs, float rhs);

///////////////////////////////////////////////////////////////////////////////
/// \brief
///
/// \param lhs
/// \param rhs
///
/// \return
///
///////////////////////////////////////////////////////////////////////////////
AXIOM_NODISCARD axm::Vector2 operator*(float lhs, const axm::Vector2& rhs);

///////////////////////////////////////////////////////////////////////////////
/// \brief
///
/// \param lhs
/// \param rhs
///
/// \return
///
///////////////////////////////////////////////////////////////////////////////
AXIOM_NODISCARD axm::Vector2 operator/(const axm::Vector2& lhs,
    const axm::Vector2& rhs);

///////////////////////////////////////////////////////////////////////////////
/// \brief
///
/// \param lhs
/// \param rhs
///
/// \return
///
///////////////////////////////////////////////////////////////////////////////
AXIOM_NODISCARD axm::Vector2 operator/(const axm::Vector2& lhs, float rhs);

///////////////////////////////////////////////////////////////////////////////
/// \brief
///
/// \param lhs
/// \param rhs
///
/// \return
///
///////////////////////////////////////////////////////////////////////////////
AXIOM_NODISCARD axm::Vector2 operator/(float lhs, const axm::Vector2& rhs);

///////////////////////////////////////////////////////////////////////////////
/// \brief
///
/// \param lhs
/// \param rhs
///
/// \return
///
///////////////////////////////////////////////////////////////////////////////
axm::Vector2& operator+=(axm::Vector2& lhs, const axm::Vector2& rhs);

///////////////////////////////////////////////////////////////////////////////
/// \brief
///
/// \param lhs
/// \param rhs
///
/// \return
///
///////////////////////////////////////////////////////////////////////////////
axm::Vector2& operator+=(axm::Vector2& lhs, float rhs);

///////////////////////////////////////////////////////////////////////////////
/// \brief
///
/// \param lhs
/// \param rhs
///
/// \return
///
///////////////////////////////////////////////////////////////////////////////
axm::Vector2& operator-=(axm::Vector2& lhs, const axm::Vector2& rhs);

///////////////////////////////////////////////////////////////////////////////
/// \brief
///
/// \param lhs
/// \param rhs
///
/// \return
///
///////////////////////////////////////////////////////////////////////////////
axm::Vector2& operator-=(axm::Vector2& lhs, float rhs);

///////////////////////////////////////////////////////////////////////////////
/// \brief
///
/// \param lhs
/// \param rhs
///
/// \return
///
///////////////////////////////////////////////////////////////////////////////
axm::Vector2& operator*=(axm::Vector2& lhs, const axm::Vector2& rhs);

///////////////////////////////////////////////////////////////////////////////
/// \brief
///
/// \param lhs
/// \param rhs
///
/// \return
///
///////////////////////////////////////////////////////////////////////////////
axm::Vector2& operator*=(axm::Vector2& lhs, float rhs);

///////////////////////////////////////////////////////////////////////////////
/// \brief
///
/// \param lhs
/// \param rhs
///
/// \return
///
///////////////////////////////////////////////////////////////////////////////
axm::Vector2& operator/=(axm::Vector2& lhs, const axm::Vector2& rhs);

///////////////////////////////////////////////////////////////////////////////
/// \brief
///
/// \param lhs
/// \param rhs
///
/// \return
///
///////////////////////////////////////////////////////////////////////////////
axm::Vector2& operator/=(axm::Vector2& lhs, float rhs);

///////////////////////////////////////////////////////////////////////////////
/// \brief
///
/// \param lhs
/// \param rhs
///
/// \return
///
///////////////////////////////////////////////////////////////////////////////
AXIOM_NODISCARD bool operator==(const axm::Vector2& lhs,
    const axm::Vector2& rhs);

///////////////////////////////////////////////////////////////////////////////
/// \brief
///
/// \param lhs
/// \param rhs
///
/// \return
///
///////////////////////////////////////////////////////////////////////////////
AXIOM_NODISCARD bool operator==(const axm::Vector2& lhs, float rhs);

///////////////////////////////////////////////////////////////////////////////
/// \brief
///
/// \param lhs
/// \param rhs
///
/// \return
///
///////////////////////////////////////////////////////////////////////////////
AXIOM_NODISCARD bool operator==(float lhs, const axm::Vector2& rhs);

///////////////////////////////////////////////////////////////////////////////
/// \brief
///
/// \param lhs
/// \param rhs
///
/// \return
///
///////////////////////////////////////////////////////////////////////////////
AXIOM_NODISCARD bool operator!=(const axm::Vector2& lhs,
    const axm::Vector2& rhs);

///////////////////////////////////////////////////////////////////////////////
/// \brief
///
/// \param lhs
/// \param rhs
///
/// \return
///
///////////////////////////////////////////////////////////////////////////////
AXIOM_NODISCARD bool operator!=(const axm::Vector2& lhs, float rhs);

///////////////////////////////////////////////////////////////////////////////
/// \brief
///
/// \param lhs
/// \param rhs
///
/// \return
///
///////////////////////////////////////////////////////////////////////////////
AXIOM_NODISCARD bool operator!=(float lhs, const axm::Vector2& rhs);

///////////////////////////////////////////////////////////////////////////////
/// \brief
///
/// \param lhs
/// \param rhs
///
/// \return
///
///////////////////////////////////////////////////////////////////////////////
AXIOM_NODISCARD bool operator<(const axm::Vector2& lhs,
    const axm::Vector2& rhs);

///////////////////////////////////////////////////////////////////////////////
/// \brief
///
/// \param lhs
/// \param rhs
///
/// \return
///
///////////////////////////////////////////////////////////////////////////////
AXIOM_NODISCARD bool operator<(const axm::Vector2& lhs, float rhs);

///////////////////////////////////////////////////////////////////////////////
/// \brief
///
/// \param lhs
/// \param rhs
///
/// \return
///
///////////////////////////////////////////////////////////////////////////////
AXIOM_NODISCARD bool operator<(float lhs, const axm::Vector2& rhs);

///////////////////////////////////////////////////////////////////////////////
/// \brief
///
/// \param lhs
/// \param rhs
///
/// \return
///
///////////////////////////////////////////////////////////////////////////////
AXIOM_NODISCARD bool operator<=(const axm::Vector2& lhs,
    const axm::Vector2& rhs);

///////////////////////////////////////////////////////////////////////////////
/// \brief
///
/// \param lhs
/// \param rhs
///
/// \return
///
///////////////////////////////////////////////////////////////////////////////
AXIOM_NODISCARD bool operator<=(const axm::Vector2& lhs, float rhs);

///////////////////////////////////////////////////////////////////////////////
/// \brief
///
/// \param lhs
/// \param rhs
///
/// \return
///
///////////////////////////////////////////////////////////////////////////////
AXIOM_NODISCARD bool operator<=(float lhs, const axm::Vector2& rhs);

///////////////////////////////////////////////////////////////////////////////
/// \brief
///
/// \param lhs
/// \param rhs
///
/// \return
///
///////////////////////////////////////////////////////////////////////////////
AXIOM_NODISCARD bool operator>(const axm::Vector2& lhs,
    const axm::Vector2& rhs);

///////////////////////////////////////////////////////////////////////////////
/// \brief
///
/// \param lhs
/// \param rhs
///
/// \return
///
///////////////////////////////////////////////////////////////////////////////
AXIOM_NODISCARD bool operator>(const axm::Vector2& lhs, float rhs);

///////////////////////////////////////////////////////////////////////////////
/// \brief
///
/// \param lhs
/// \param rhs
///
/// \return
///
///////////////////////////////////////////////////////////////////////////////
AXIOM_NODISCARD bool operator>(float lhs, const axm::Vector2& rhs);

///////////////////////////////////////////////////////////////////////////////
/// \brief
///
/// \param lhs
/// \param rhs
///
/// \return
///
///////////////////////////////////////////////////////////////////////////////
AXIOM_NODISCARD bool operator>=(const axm::Vector2& lhs,
    const axm::Vector2& rhs);

///////////////////////////////////////////////////////////////////////////////
/// \brief
///
/// \param lhs
/// \param rhs
///
/// \return
///
///////////////////////////////////////////////////////////////////////////////
AXIOM_NODISCARD bool operator>=(const axm::Vector2& lhs, float rhs);

///////////////////////////////////////////////////////////////////////////////
/// \brief
///
/// \param lhs
/// \param rhs
///
/// \return
///
///////////////////////////////////////////////////////////////////////////////
AXIOM_NODISCARD bool operator>=(float lhs, const axm::Vector2& rhs);

///////////////////////////////////////////////////////////////////////////////
/// \brief
///
/// \param lhs
///
/// \return
///
///////////////////////////////////////////////////////////////////////////////
axm::Vector2& operator++(axm::Vector2& lhs);

///////////////////////////////////////////////////////////////////////////////
/// \brief
///
/// \param lhs
///
/// \return
///
///////////////////////////////////////////////////////////////////////////////
axm::Vector2& operator++(axm::Vector2& lhs, int);

///////////////////////////////////////////////////////////////////////////////
/// \brief
///
/// \param lhs
///
/// \return
///
///////////////////////////////////////////////////////////////////////////////
axm::Vector2& operator--(axm::Vector2& lhs);

///////////////////////////////////////////////////////////////////////////////
/// \brief
///
/// \param lhs
///
/// \return
///
///////////////////////////////////////////////////////////////////////////////
axm::Vector2& operator--(axm::Vector2& lhs, int);

///////////////////////////////////////////////////////////////////////////////
/// \brief
///
/// \param lhs
/// \param rhs
///
/// \return
///
///////////////////////////////////////////////////////////////////////////////
std::ostream& operator<<(std::ostream& lhs, const axm::Vector2& rhs);
