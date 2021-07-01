#ifndef PIXELLE_UTIL_TCC
#define PIXELLE_UTIL_TCC

#include <pixelle/util/Util.h>

template<typename I>
std::string pixelle::util::toHexString(I number) {
    static const char* ALPHABET = "0123456789ABCDEF";
    std::string result;
    size_t size = sizeof(I);
    for (size_t i = size * 2; i != 0; i--) {
        auto val = PIXELLE_BYTE(number, i * 4) & 0xf;
        result += ALPHABET[val];
    }
    return result;
}

#endif
