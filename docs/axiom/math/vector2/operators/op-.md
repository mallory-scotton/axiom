> _[axiom](../../../../axiom.md)/[math](../../../math.md)/[vector2](../../vector2.md)/[operator-](./op-.md)_

# [Vector2](../../vector2.md).operator-

## Declaration

```cpp
AXIOM_NODISCARD operator-(const Vector2& lhs, const Vector2& rhs);
```

```cpp
AXIOM_NODISCARD operator-(const Vector2& lhs, float rhs);
```

```cpp
AXIOM_NODISCARD operator-(float lhs, const Vector2& rhs);
```

## Description

Subtracts using a vector in the operation.

Subtracts each component of `rhs` from `lhs`.

## Returns

`Vector2` The difference between the two vectors, returned as a Vector2 struct.

## Examples

```cpp
#include <axiom/math.hpp>

int main(void)
{
    // Create the vector.
    axm::Vector2 a(1.f, 2.f);

    // Negate the vector.
    axm::Vector2 b(2.f, 1.f);

    // Calculate the results.
    axm::Vector2 result1 = a - b;       // x:(a.x - b.x) and y:(a.y - b.y)
    axm::Vector2 result2 = a - 1.f;     // x:(a.x - 1.f) and y:(a.y - 1.f)
    axm::Vector2 result3 = 5.f - b;     // x:(5.f - b.x) and y:(5.f - b.y)

    // Print the results
    std::cout << "1: " << result1 << '\n';
    std::cout << "2: " << result2 << '\n';
    std::cout << "3: " << result3 << '\n';
}
```

Will output:

```
1: (-1, 1)
2: (0, 1)
3: (3, 4)
```
