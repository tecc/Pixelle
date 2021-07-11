#ifndef PIXELLE_MATH_H
#define PIXELLE_MATH_H

#include <concepts>
#include <string>

#define PIXELLE_BYTE(x, off) ((uint8_t) (((x) >> (off)) & 0xff))

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

        Vector2(Number x = 0, Number y = 0) : x(x), y(y) {};

        Vector2<Number> operator *(Number num);
        Vector2<Number> operator /(Number num);

        operator std::string();
        inline operator float*();
    };

    template<NumberLike Number>
    struct Vector3 {
        Number x;
        Number y;
        Number z;

        Vector3(Number x = 0, Number y = 0, Number z = 0) : x(x), y(y), z(z) {};
    };
}

#include <pixelle/util/Math.tcc>

#endif
