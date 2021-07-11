#ifndef PIXELLE_MATH_TCC
#define PIXELLE_MATH_TCC

#include <pixelle/util/Util.h>

template<pixelle::math::NumberLike Number>
pixelle::math::Vector2<Number> pixelle::math::Vector2<Number>::operator *(Number num) {
    return { this->x * num, this->y * num };
}

template<pixelle::math::NumberLike Number>
pixelle::math::Vector2<Number> pixelle::math::Vector2<Number>::operator /(Number num) {
    return { this->x / num, this->y / num };
}
template<pixelle::math::NumberLike Number>
pixelle::math::Vector2<Number>::operator std::string() {
    return _str("v2{") + std::to_string(this->x) + ", " + std::to_string(this->y) + "}";
}
template<pixelle::math::NumberLike Number>
pixelle::math::Vector2<Number>::operator float*() {
    return { this->x, this-> y};
}


#endif