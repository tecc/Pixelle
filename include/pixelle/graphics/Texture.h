#ifndef PIXELLE_TEXTURE_H
#define PIXELLE_TEXTURE_H

#include <cstdint>
#include <pixelle/util/Math.h>
#include <filesystem>

namespace pixelle::graphics {
    struct TextureMeta;
    class Texture {
    private:
        TextureMeta* meta;
        uint8_t* data;

    public:
        Texture(math::Vector2<uint32_t> size, uint32_t components, uint8_t* data);
        ~Texture();

        static Texture loadFromFile(std::filesystem::path path);
    };
}

#endif
