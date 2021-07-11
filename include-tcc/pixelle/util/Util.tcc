#ifndef PIXELLE_UTIL_TCC
#define PIXELLE_UTIL_TCC

#include <pixelle/util/Util.h>

template<typename I>
std::string pixelle::util::toHexString(I number) {
    static const char* ALPHABET = "0123456789ABCDEF";
    std::string result;
    size_t size = sizeof(I);
    for (size_t i = size; i != 0; i--) {
        auto base = i * 8 - 8;
        auto v1 = PIXELLE_BYTE(number, base) & 0xf;
        auto v2 = PIXELLE_BYTE(number, base + 4) & 0xf;
        result = result + ALPHABET[v2] + ALPHABET[v1];
    }
    return result;
}

template<typename TDuration>
size_t pixelle::util::getTime() {
    auto point = std::chrono::system_clock::now().time_since_epoch();
    return duration_cast<TDuration>(point).count();
}

#endif
