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
/// \brief Mathematical constants and conversion factors used throughout
/// game engine computations, physics, and graphics.
///
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
/// \brief Single-precision constants.
///////////////////////////////////////////////////////////////////////////////

// Value of Pi, used in trigonometric calculations.
#define PI (3.1415926535897932f)
// Small threshold value to handle numerical precision errors.
#define SMALL_NUMBER (1.e-8f)
// Slightly larger small number, useful for less strict comparisons.
#define KINDA_SMALL_NUMBER (1.e-4f)
// Represents a very large number, near the limit of float precision.
#define BIG_NUMBER (3.4e+38f)
// Euler's number, the base of natural logarithms.
#define EULERS_NUMBER (2.71828182845904523536f)
// Golden ratio constant, often used in design and architecture.
#define GOLDEN_RATIO (1.6180339887498948482045868343656381f)
// The largest float value where adding or subtracting 1 produces a
// non-fractional result.
#define FLOAT_NON_FRACTIONAL (8388608.f)

// Double-precision value of Pi for high accuracy calculations.
#define DOUBLE_PI (3.141592653589793238462643383279502884197169399)
// Small threshold for double-precision calculations.
#define DOUBLE_SMALL_NUMBER (1.e-8)
// Larger threshold for double-precision calculations.
#define DOUBLE_KINDA_SMALL_NUMBER (1.e-4)
// Very large number in double-precision format.
#define DOUBLE_BIG_NUMBER (3.4e+38)
// Double-precision Euler's number.
#define DOUBLE_EULERS_NUMBER (2.7182818284590452353602874713526624977572)
// Double-precision golden ratio constant.
#define DOUBLE_GOLDEN_RATIO (1.6180339887498948482045868343656381)
// Double-precision non-fractional threshold.
#define DOUBLE_NON_FRACTIONAL (4503599627370496.0)

///////////////////////////////////////////////////////////////////////////////
/// \brief Inverses and multiples of Pi.
///////////////////////////////////////////////////////////////////////////////

// 1/Pi, used for scaling or normalization.
#define INV_PI (0.31830988618f)
// Pi/2, useful in angle calculations.
#define HALF_PI (1.57079632679f)
// 2*Pi, commonly used for full rotations or angle wrapping.
#define TWO_PI (6.28318530717f)
// Pi squared, used in various geometric formulas.
#define PI_SQUARED (9.86960440108f)

// Double-precision 1/Pi.
#define DOUBLE_INV_PI (0.31830988618379067154)
// Double-precision Pi/2.
#define DOUBLE_HALF_PI (1.57079632679489661923)
// Double-precision 2*Pi.
#define DOUBLE_TWO_PI (6.28318530717958647692)
// Double-precision Pi squared.
#define DOUBLE_PI_SQUARED (9.86960440108935861883)

///////////////////////////////////////////////////////////////////////////////
/// \brief Square roots and their inverses.
///////////////////////////////////////////////////////////////////////////////

// Square root of 2, often used in vector normalization.
#define SQRT_2 (1.4142135623730950488016887242097f)
// Square root of 3, useful in 3D geometry.
#define SQRT_3 (1.7320508075688772935274463415059f)
// 1/Square root of 2, used in various geometric transformations.
#define INV_SQRT_2 (0.70710678118654752440084436210485f)
// 1/Square root of 3, useful in certain 3D calculations.
#define INV_SQRT_3 (0.57735026918962576450914878050196f)
// Half of the square root of 2.
#define HALF_SQRT_2 (0.70710678118654752440084436210485f)
// Half of the square root of 3.
#define HALF_SQRT_3 (0.86602540378443864676372317075294f)

// Double-precision square root of 2.
#define DOUBLE_SQRT_2 (1.4142135623730950488016887242097)
// Double-precision square root of 3.
#define DOUBLE_SQRT_3 (1.7320508075688772935274463415059)
// Double-precision 1/square root of 2.
#define DOUBLE_INV_SQRT_2 (0.70710678118654752440084436210485)
// Double-precision 1/square root of 3.
#define DOUBLE_INV_SQRT_3 (0.57735026918962576450914878050196)
// Double-precision half of square root of 2.
#define DOUBLE_HALF_SQRT_2 (0.70710678118654752440084436210485)
// Double-precision half of square root of 3.
#define DOUBLE_HALF_SQRT_3 (0.86602540378443864676372317075294)

///////////////////////////////////////////////////////////////////////////////
/// \brief Unit conversion factors.
///////////////////////////////////////////////////////////////////////////////

//  Conversion from kilometers to meters.
#define KM_TO_M (1000.f)
// Conversion from meters to kilometers.
#define M_TO_KM (0.001f)
// Conversion from centimeters to meters.
#define CM_TO_M (0.01f)
// Conversion from meters to centimeters.
#define M_TO_CM (100.f)
// Conversion from square centimeters to square meters.
#define CM2_TO_M2 (0.0001f)
// Conversion from square meters to square centimeters.
#define M2_TO_CM2 (10000.f)

///////////////////////////////////////////////////////////////////////////////
/// \brief Small deltas and precision thresholds.
///////////////////////////////////////////////////////////////////////////////

// A small float delta for precision-based comparisons.
#define DELTA (0.00001f)
// A small double delta for precision-based comparisons.
#define DOUBLE_DELTA (0.00001)

// Threshold used for checking if a float is normalized.
#define FLOAT_NORMAL_THRESH (0.0001f)
// Threshold for checking if a double is normalized.
#define DOUBLE_NORMAL_THRESH (0.0001)

///////////////////////////////////////////////////////////////////////////////
/// \brief Geometric thresholds and tolerances.
///////////////////////////////////////////////////////////////////////////////

// Tolerance for considering a point to lie on a plane.
#define THRESH_POINT_ON_PLANE (0.10f)
// Tolerance for determining if a point is on one side of a plane.
#define THRESH_POINT_ON_SIDE (0.20f)
// Tolerance for determining if two points are considered identical.
#define THRESH_POINTS_ARE_SAME (0.00002f)
// Tolerance for determining if two points are considered near.
#define THRESH_POINTS_ARE_NEAR (0.015f)
// Tolerance for determining if two normals are considered identical.
#define THRESH_NORMALS_ARE_SAME (0.00002f)
// Tolerance for determining if two UV coordinates are considered identical.
#define THRESH_UVS_ARE_SAME (0.0009765625f)

// Tolerance for determining if two vectors are considered near.
#define THRESH_VECTORS_ARE_NEAR (0.0004f)

// Threshold for splitting a polygon with a plane.
#define THRESH_SPLIT_POLY_WITH_PLANE (0.25f)
// Precision threshold for accurate polygon splitting.
#define THRESH_SPLIT_POLY_PRECISELY (0.01f)
// Threshold for detecting near-zero normal vectors.
#define THRESH_ZERO_NORM_SQUARED (0.0001f)
// Tolerance for determining if two normals are parallel.
#define THRESH_NORMALS_ARE_PARALLEL (0.999845f)
// Tolerance for determining if two normals are orthogonal.
#define THRESH_NORMALS_ARE_ORTHOGONAL (0.017455f)

// Threshold for checking if a vector is normalized.
#define THRESH_VECTOR_NORMALIZED (0.01f)
// Threshold for checking if a quaternion is normalized.
#define THRESH_QUAT_NORMALIZED (0.01f)

// Double-precision tolerance for points on planes.
#define DOUBLE_THRESH_POINT_ON_PLANE (0.10)
// Double-precision tolerance for points on sides of planes.
#define DOUBLE_THRESH_POINT_ON_SIDE (0.20)
// Double-precision tolerance for points being the same.
#define DOUBLE_THRESH_POINTS_ARE_SAME (0.00002)
// Double-precision tolerance for points being near.
#define DOUBLE_THRESH_POINTS_ARE_NEAR (0.015)
// Double-precision tolerance for normals being the same.
#define DOUBLE_THRESH_NORMALS_ARE_SAME (0.00002)
// Double-precision tolerance for UVs being the same.
#define DOUBLE_THRESH_UVS_ARE_SAME (0.0009765625)

// Double-precision tolerance for vectors being near.
#define DOUBLE_THRESH_VECTORS_ARE_NEAR (0.0004)

// Double-precision tolerance for polygon splitting.
#define DOUBLE_THRESH_SPLIT_POLY_WITH_PLANE (0.25)
// Double-precision threshold for accurate polygon splitting.
#define DOUBLE_THRESH_SPLIT_POLY_PRECISELY (0.01)
// Double-precision threshold for near-zero normal vectors.
#define DOUBLE_THRESH_ZERO_NORM_SQUARED (0.0001)
// Double-precision tolerance for normals being parallel.
#define DOUBLE_THRESH_NORMALS_ARE_PARALLEL (0.999845)
// Double-precision tolerance for normals being orthogonal.
#define DOUBLE_THRESH_NORMALS_ARE_ORTHOGONAL (0.017455)

// Double-precision threshold for vector normalization.
#define DOUBLE_THRESH_VECTOR_NORMALIZED (0.01)
// Double-precision threshold for quaternion normalization.
#define DOUBLE_THRESH_QUAT_NORMALIZED (0.01)
