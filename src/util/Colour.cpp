#include <pixelle/util/Colour.h>
#include <cmath>
#include <algorithm>
#include <pixelle/util/Util.h>

using namespace pixelle;

util::Colour::Colour(float r, float g, float b, float a) : red(r), green(g), blue(b), alpha(a) { }

uint32_t util::Colour::getRGBA() const {
    auto r = (uint8_t) (red * 255), g = (uint8_t) (green * 255), b = (uint8_t) (blue * 255), a = (uint8_t) (alpha *
                                                                                                            255);
    return r << 24 | g << 16 | b << 8 | a;
}

#define getcol(funcName, prop) float util::Colour::funcName() { return this->prop; } \
uint8_t util::Colour::funcName##Byte() { return (uint8_t) (this->prop * 255.f); }

getcol(getRed, red)

getcol(getGreen, green)

getcol(getBlue, blue)

getcol(getAlpha, alpha)

#undef getcol

util::Colour util::Colour::fromHSV(float hue, float saturation, float value, float alpha) {
    if (hue < 0.f) hue = -hue;
    hue = std::fmod(hue, 360.f); // max hue
    saturation = std::clamp(saturation, 0.f, 1.f);
    value = std::clamp(value, 0.f, 1.f);
    float c = value * saturation;
    float x = c * (1 - std::abs(std::fmod(hue / 60, 2.f) - 1));
    float m = value - c;
    float rf = 0.f, gf = 0.f, bf = 0.f;

    // TODO: replace this mess with something more efficient
    if (0.f <= hue && hue < 60.f) { // C X 0
        rf = c;
        gf = x;
    } else if (60.f <= hue && hue < 120.f) { // X C 0
        rf = x;
        gf = c;
    } else if (120.f <= hue && hue < 180.f) { // 0 C X
        gf = c;
        bf = x;
    } else if (180.f <= hue && hue < 240.f) { // 0 X C
        gf = x;
        bf = c;
    } else if (240.f <= hue && hue < 300.f) { // X 0 C
        rf = x;
        bf = c;
    } else if (300.f <= hue && hue < 360.f) { // C 0 X
        rf = c;
        bf = x;
    }

    return { rf, gf, bf, alpha };
}

util::Colour util::Colour::fromARGB(uint32_t argb) {
    return {
            PIXELLE_BYTE(argb, 16) / 255.f,
            PIXELLE_BYTE(argb, 8) / 255.f,
            PIXELLE_BYTE(argb, 0) / 255.f,
            PIXELLE_BYTE(argb, 24) / 255.f
    };
}

std::string util::Colour::toHexString() const {
    return util::toHexString(getRGBA());
}

