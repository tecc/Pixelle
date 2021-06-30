#ifndef PIXELLE_MATH_H
#define PIXELLE_MATH_H

#include <concepts>

#define PIXELLE_BYTE(x, off) ((uint8_t) ((x >> off) & 0xff))

namespace pixelle::math {
    template<typename T>
    concept NumberLike = requires(T a, T b) {
        { a + b } -> std::convertible_to<T>;
        { 0 } -> std::convertible_to<T>;
    };

    template<NumberLike Number>
    struct Vector2 {
        Number x;
        Number y;

        inline Vector2() : Vector2(0) {};
        inline Vector2(Number x) : Vector2(x, 0) {};
        Vector2(Number x, Number y) : x(x), y(y) {};
    };
}

#endif
