#include <pixelle/graphics/renderObjects/PixelRenderObject.h>


void graphics::PixelRenderObject::setPixels(std::vector<util::Colour> pixels) {
    this->pixels = std::move(pixels);
}
std::vector<util::Colour> graphics::PixelRenderObject::getPixels() const {
    return this->pixels;
}

void graphics::PixelRenderObject::render() {
    size_t total = this->getPixelCount();
    if (this->pixels.size() < total) throw pixelle::Exception("Pixel vector is too small!");
    auto* pixbuf = (uint32_t*) calloc(total, sizeof(uint32_t));
    for (size_t i = 0; i < total; i++) {
        pixbuf[i] = this->pixels[i].getRGBA();
    }
    glDrawPixels(
            this->dimensions.x, this->dimensions.y,
            GL_RGBA, GL_UNSIGNED_INT_8_8_8_8,
            pixbuf
            );
    free(pixbuf);
}

size_t graphics::PixelRenderObject::getPixelCount() const {
    return this->dimensions.x * this->dimensions.y;
}

void graphics::PixelRenderObject::setDimensions(math::Vector2<int> dimensions) {
    this->dimensions = dimensions;
}

math::Vector2<int> graphics::PixelRenderObject::getDimensions() const {
    return this->dimensions;
}
