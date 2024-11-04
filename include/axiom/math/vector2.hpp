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
#include <axiom/math/vector3.hpp>
#include <axiom/math/vector4.hpp>
#include <iostream>

///////////////////////////////////////////////////////////////////////////////
// Namespace ax::math
///////////////////////////////////////////////////////////////////////////////
namespace ax::math
{

///////////////////////////////////////////////////////////////////////////////
/// \brief Structure predefinition
///
///////////////////////////////////////////////////////////////////////////////
struct Vector3;
struct Vector4;

///////////////////////////////////////////////////////////////////////////////
/// \brief A vector in 2D space composed of components (x, y) with floating
///        point precision.
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
            float x;        //<! X coordinate of the vector.
            float y;        //<! Y coordinate of the vector.
        };
        float xy[2];        //<! Coordinates array of the vector.
    };

public:
    ///////////////////////////////////////////////////////////////////////////
    /// \brief
    ///
    ///////////////////////////////////////////////////////////////////////////
    static const Vector2 zeroVector;    //<! Vector2( 0,  0).
    static const Vector2 oneVector;     //<! Vector2( 1,  1).
    static const Vector2 upVector;      //<! Vector2( 0,  1).
    static const Vector2 downVector;    //<! Vector2( 0, -1).
    static const Vector2 leftVector;    //<! Vector2( 1,  0).
    static const Vector2 rightVector;   //<! Vector2(-1,  0).
    static const Vector2 xAxisVector;   //<! Vector2( 1,  0).
    static const Vector2 yAxisVector;   //<! Vector2( 0,  1).

public:
    ///////////////////////////////////////////////////////////////////////////
    /// \brief Constructor which iniializes all components to zero.
    ///
    ///////////////////////////////////////////////////////////////////////////
    Vector2(void);

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Constructor initializing both components to a single float
    /// value.
    ///
    /// \param f Value to set both components to.
    ///
    ///////////////////////////////////////////////////////////////////////////
    Vector2(float f);

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Constructor using initial values for each component.
    ///
    /// \param x X coordinate.
    /// \param y Y coordinate.
    ///
    ///////////////////////////////////////////////////////////////////////////
    Vector2(float x, float y);

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Constructs a vector from an Vector3.
    ///
    /// Copies the `x` and `y` components from the Vector3.
    ///
    /// \param vector Vector to copy from.
    ///
    ///////////////////////////////////////////////////////////////////////////
    Vector2(const Vector3& vector);

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Constructs a vector from an Vector4.
    ///
    /// Copies the `x` and `y` components from the Vector4.
    ///
    /// \param vector Vector to copy from.
    ///
    ///////////////////////////////////////////////////////////////////////////
    Vector2(const Vector4& vector);

public:
    ///////////////////////////////////////////////////////////////////////////
    /// \brief Gets specific component of the vector.
    ///
    /// \param index The index of vector component.
    ///
    /// \return Reference to the component.
    ///
    ///////////////////////////////////////////////////////////////////////////
    AXIOM_NODISCARD float& operator[](Int32 index);

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Gets specific component of the vector.
    ///
    /// \param index The index of vector component.
    ///
    /// \return Copy of the component.
    ///
    ///////////////////////////////////////////////////////////////////////////
    AXIOM_NODISCARD const float& operator[](Int32 index) const;

public:
    ///////////////////////////////////////////////////////////////////////////
    /// \brief Gets specific component of the vector.
    ///
    /// \param index The index of vector component.
    ///
    /// \return Reference to the component.
    ///
    ///////////////////////////////////////////////////////////////////////////
    float& component(Int32 index);

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Gets specific component of the vector.
    ///
    /// \param index The index of vector component.
    ///
    /// \return Copy of the component.
    ///
    ///////////////////////////////////////////////////////////////////////////
    const float& component(Int32 index) const;

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Checks whether both components of this vector are less than
    /// another.
    ///
    /// \param other The vector to compare against.
    ///
    /// \return `true` if both components of this are less than `other`,
    /// otherwise `false`.
    ///
    ///////////////////////////////////////////////////////////////////////////
    AXIOM_NODISCARD bool componentWiseAllLessThan(const Vector2& other) const;

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Checks whether both components of this vector are greater
    /// than another.
    ///
    /// \param other The vector to compare against.
    ///
    /// \return `true` if both components of this are greater than `other`,
    /// otherwise `false`.
    ///
    ///////////////////////////////////////////////////////////////////////////
    AXIOM_NODISCARD bool componentWiseAllGreaterThan(const Vector2& other)
        const;

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Checks whether both components of this vector are less than or
    /// equal to another.
    ///
    /// \param other The vector to compare against.
    ///
    /// \return `true` if both components of this are less than or equal to
    /// `other`, otherwise `false`.
    ///
    ///////////////////////////////////////////////////////////////////////////
    AXIOM_NODISCARD bool componentWiseAllLessOrEqual(const Vector2& other)
        const;

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Checks whether both components of this vector are greater than
    /// or equal to another.
    ///
    /// \param other The vector to compare against.
    ///
    /// \return `true` if both components of this are greater than or equal to
    /// `other`, otherwise `false`.
    ///
    ///////////////////////////////////////////////////////////////////////////
    AXIOM_NODISCARD bool componentWiseAllGreaterOrEqual(const Vector2& other)
        const;

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Checks for equality with error-tolerant comparison.
    ///
    /// \param other The vector to compare.
    /// \param tolerance Error tolerance.
    ///
    /// \return `true` if the vectors are equal within specified tolerance,
    /// otherwise `false`.
    ///
    ///////////////////////////////////////////////////////////////////////////
    AXIOM_NODISCARD bool equals(const Vector2& other,
        float tolerance = KINDA_SMALL_NUMBER) const;

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Set the values of the vector directly.
    ///
    /// \param x New X coordinate.
    /// \param y New Y coordinate.
    ///
    ///////////////////////////////////////////////////////////////////////////
    void set(float x, float y);

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Get the maximum value of the vector's components.
    ///
    /// \return The maximum value of the vector's components.
    ///
    ///////////////////////////////////////////////////////////////////////////
    AXIOM_NODISCARD float getMax(void) const;

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Get the maximum absolute value of the vector's components.
    ///
    /// \return The maximum absolute value of the vector's components.
    ///
    ///////////////////////////////////////////////////////////////////////////
    AXIOM_NODISCARD float getAbsMax(void) const;

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Get the minimum value of the vector's components.
    ///
    /// \return The minimum value of the vector's components.
    ///
    ///////////////////////////////////////////////////////////////////////////
    AXIOM_NODISCARD float getMin(void) const;

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Get the absolute minimum value of the vector's components.
    ///
    /// \return The absolute minimum value of the vector's components.
    ///
    ///////////////////////////////////////////////////////////////////////////
    AXIOM_NODISCARD float getAbsMin(void) const;

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Get the length (magnitude) of this vector.
    ///
    /// \return The length of this vector.
    ///
    /// \see length - This function is a sononym for length().
    ///
    ///////////////////////////////////////////////////////////////////////////
    AXIOM_NODISCARD float size(void) const;

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Get the length (magnitude) of this vector.
    ///
    /// \return The length of this vector.
    ///
    /// \see size - This function is a sononym for size().
    ///
    ///////////////////////////////////////////////////////////////////////////
    AXIOM_NODISCARD float length(void) const;

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Get the squared length of this vector.
    ///
    /// \return The squared length of this vector.
    ///
    /// \see squaredLength - This function is a sononym for squaredLength().
    ///
    ///////////////////////////////////////////////////////////////////////////
    AXIOM_NODISCARD float sizeSquared(void) const;

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Get the squared length of this vector.
    ///
    /// \return The squared length of this vector.
    ///
    /// \see sizeSquared - This function is a sononym for sizeSquared().
    ///
    ///////////////////////////////////////////////////////////////////////////
    AXIOM_NODISCARD float squaredLength(void) const;

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Get the dot product of this vector against another.
    ///
    /// \param other The vector to measure dot product against.
    ///
    /// \return The dot product.
    ///
    ///////////////////////////////////////////////////////////////////////////
    AXIOM_NODISCARD float dot(const Vector2& other) const;

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Rotates around axis (0,0,1).
    ///
    /// \param angleDeg Angle to rotate (in degrees).
    ///
    /// \return Rotated Vector.
    ///
    ///////////////////////////////////////////////////////////////////////////
    AXIOM_NODISCARD Vector2 getRotated(float angleDeg) const;

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Gets a normalized copy of the vector, checking it is safe to do
    /// so based on the length.
    ///
    /// Returns zero vector if vector length is too small to safely normalize.
    ///
    /// \param tolerance Minimum squared length of vector for normalization.
    ///
    /// \return A normalized copy of the vector if safe, (0,0) otherwise.
    ///
    ///////////////////////////////////////////////////////////////////////////
    AXIOM_NODISCARD Vector2 getSafeNormal(float tolerance = SMALL_NUMBER)
        const;

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Normalize this vector in-place if it is large enough, set it to
    /// (0,0) otherwise.
    ///
    /// \note This is different from Vector3::normalize, which leaves the
    /// vector unchanged if it is too small to normalize.
    ///
    /// \param tolerance Minimum squared length of vector for normalization.
    ///
    /// \return `true` if the vector was normalized correctly, `false` if it
    /// was too small and set to zero.
    ///
    ///////////////////////////////////////////////////////////////////////////
    bool normalize(float tolerance = SMALL_NUMBER);

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Checks whether vector is near to zero within a specified
    /// tolerance.
    ///
    /// \param tolerance Error tolerance.
    ///
    /// \return `true` if vector is in tolerance to zero, otherwise `false`.
    ///
    ///////////////////////////////////////////////////////////////////////////
    AXIOM_NODISCARD bool isNearlyZero(float tolerance = KINDA_SMALL_NUMBER)
        const;

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Util to convert this vector into a unit direction vector and
    /// its original length.
    ///
    /// \param outDir Reference passed in to store unit direction vector.
    /// \param outLength Reference passed in to store length of the vector.
    ///
    ///////////////////////////////////////////////////////////////////////////
    void toDirectionAndLength(Vector2& outDir, float& outLength) const;

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Util to convert this vector into a unit direction vector and
    /// its original length.
    ///
    /// \param outDir Reference passed in to store unit direction vector.
    /// \param outLength Reference passed in to store length of the vector.
    ///
    ///////////////////////////////////////////////////////////////////////////
    void toDirectionAndLength(Vector2& outDir, double& outLength) const;

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Checks whether all components of the vector are exactly zero.
    ///
    /// \return `true` if vector is exactly zero, otherwise `false`.
    ///
    ///////////////////////////////////////////////////////////////////////////
    AXIOM_NODISCARD bool isZero(void) const;

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Get this vector as a vector where each component has been
    /// rounded to the nearest int.
    ///
    /// \return New vector from this vector that is rounded.
    ///
    ///////////////////////////////////////////////////////////////////////////
    AXIOM_NODISCARD Vector2 roundToVector(void) const;

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Creates a copy of this vector with both axes clamped to the
    /// given range.
    ///
    /// \param minAxisValue Minimum axis value.
    /// \param maxAxisValue Maximum axis value.
    ///
    /// \return New vector with clamped axes.
    ///
    ///////////////////////////////////////////////////////////////////////////
    AXIOM_NODISCARD Vector2 clampAxes(float minAxisValue, float maxAxisValue)
        const;

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Get a copy of the vector as sign only.
    ///
    /// Each component is set to +1 or -1, with the sign of zero treated as +1.
    ///
    /// \return A copy of the vector with each component set to +1 or -1.
    ///
    ///////////////////////////////////////////////////////////////////////////
    AXIOM_NODISCARD Vector2 getSignVector(void) const;

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Get a copy of this vector with absolute value of each component.
    ///
    /// \return A copy of this vector with absolute value of each component.
    ///
    ///////////////////////////////////////////////////////////////////////////
    AXIOM_NODISCARD Vector2 getAbs(void) const;

public:
    ///////////////////////////////////////////////////////////////////////////
    /// \brief Returns a vector with the minimum component for each dimension
    /// from the pair of vectors.
    ///
    /// \param a The first vector.
    /// \param b The second vector.
    ///
    /// \return The min vector.
    ///
    ///////////////////////////////////////////////////////////////////////////
    AXIOM_NODISCARD static Vector2 min(const Vector2& a, const Vector2& b);

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Returns a vector with the minimum component for each dimension
    /// from the trio of vectors.
    ///
    /// \param a The first vector.
    /// \param b The second vector.
    /// \param c The third vector.
    ///
    /// \return The min vector.
    ///
    ///////////////////////////////////////////////////////////////////////////
    AXIOM_NODISCARD static Vector2 min(const Vector2& a, const Vector2& b,
        const Vector2& c);

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Returns a vector with the maximum component for each dimension
    /// from the pair of vectors.
    ///
    /// \param a The first vector.
    /// \param b The second vector.
    ///
    /// \return The max vector.
    ///
    ///////////////////////////////////////////////////////////////////////////
    AXIOM_NODISCARD static Vector2 max(const Vector2& a, const Vector2& b);

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Returns a vector with the maximum component for each dimension
    /// from the trio of vectors.
    ///
    /// \param a The first vector.
    /// \param b The second vector.
    /// \param c The third vector.
    ///
    /// \return The max vector.
    ///
    ///////////////////////////////////////////////////////////////////////////
    AXIOM_NODISCARD static Vector2 max(const Vector2& a, const Vector2& b,
        const Vector2& c);

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Returns a vector with each component clamped between a
    /// minimum and a maximum.
    ///
    /// \param value The vector to clamp.
    /// \param minValue The minimum vector.
    /// \param maxValue The maximum vector.
    ///
    /// \return The clamped vector.
    ///
    ///////////////////////////////////////////////////////////////////////////
    AXIOM_NODISCARD static Vector2 clamp(const Vector2& value,
        const Vector2& minValue, const Vector2& maxValue);

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Calculates the dot product of two vectors.
    ///
    /// \param a The first vector.
    /// \param b The second vector.
    ///
    /// \return The dot product.
    ///
    ///////////////////////////////////////////////////////////////////////////
    AXIOM_NODISCARD static float dotProduct(const Vector2& a,
        const Vector2& b);

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Calculate the cross product of two vectors.
    ///
    /// \param a The first vector.
    /// \param b The second vector.
    ///
    /// \return The cross product.
    ///
    ///////////////////////////////////////////////////////////////////////////
    AXIOM_NODISCARD static float crossProduct(const Vector2& a,
        const Vector2& b);

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Squared distance between two 2D points.
    ///
    /// \param a The first point.
    /// \param b The second point.
    ///
    /// \return The squared distance between two 2D points.
    ///
    ///////////////////////////////////////////////////////////////////////////
    AXIOM_NODISCARD static float distSquared(const Vector2& a,
        const Vector2& b);

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Distance between two 2D points.
    ///
    /// \param a The first point.
    /// \param b The second point.
    ///
    /// \return The distance between two 2D points.
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
AXIOM_NODISCARD float operator^(const axm::Vector2& lhs,
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
AXIOM_NODISCARD float operator|(const axm::Vector2& lhs,
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
std::ostream& operator<<(std::ostream& lhs, const axm::Vector2& rhs);
