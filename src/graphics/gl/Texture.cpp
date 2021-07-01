#include <pixelle/graphics/Texture.h>
#include <pixelle/internal/gl_meta.h>
#include <pixelle/internal/stb_image.h>

using namespace pixelle;

graphics::Texture graphics::Texture::loadFromFile(std::filesystem::path path) {
    int x, y, components;
    uint8_t* data = stbi_load(path.c_str(), &x, &y, &components, 0);

    return {math::Vector2{(uint32_t) x, (uint32_t) y}, (uint32_t) components, data};
}
