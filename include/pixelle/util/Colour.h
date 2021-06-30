#ifndef PIXELLE_COLOUR_H
#define PIXELLE_COLOUR_H

#include <concepts>
#include <cstdint>
#include <string>

#include <pixelle/util/Math.h>

namespace pixelle::util {

    struct Colour {
    private:
        float red, green, blue, alpha;
    protected:
        Colour() = default;

    public:
        Colour(float r) : Colour(r, r, r, 1.f) {};
        Colour(float r, float g, float b, float a);

        uint32_t getRGBA() const;
        float getRed();
        uint8_t getRedByte();
        float getGreen();
        uint8_t getGreenByte();
        float getBlue();
        uint8_t getBlueByte();
        float getAlpha();
        uint8_t getAlphaByte();

        std::string toHexString() const;
        operator std::string() const { return toHexString(); };

        static Colour fromHSV(float hue, float saturation, float value, float alpha = 1.f);
        static Colour fromARGB(uint32_t argb);
    };
}

#endif
