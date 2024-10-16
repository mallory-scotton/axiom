> _[axiom](../../../../axiom.md)/[math](../../../math.md)/[vector2](../../vector2.md)/[operator-](./-op.md)_

# [Vector2](../../vector2.md).operator-

## Declaration

```cpp
AXIOM_NODISCARD operator-(const Vector2& lhs);
```

## Description

Negates a vector.

Each component in the vector is negated, to obtain its negative value. The negative of a vector has the same magnitude but opposite direction.

## Returns

`Vector2` The negative of the vector, returned as a Vector2 struct.

## Examples

```cpp
#include <axiom/math.hpp>

int main(void)
{
    // Create the vector.
    axm::Vector2 a(1.f, 2.f);

    // Negate the vector.
    axm::Vector2 b = -a;

    // Print the result.
    std::cout << b << '\n';
}
```

Will output:

```
(-1, -2)
```
