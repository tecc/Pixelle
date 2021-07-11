#ifndef PIXELLE_PIXELRENDEROBJECT_H
#define PIXELLE_PIXELRENDEROBJECT_H

#include <pixelle/graphics/RenderObject.h>

namespace pixelle::graphics {
    /**
     * A render object for raw pixels.
     *
     * @warning This is not recommended for general application, as it is inefficient.
     */
    class PixelRenderObject : public RenderObject {
    protected:
        std::vector<util::Colour> pixels;
        math::Vector2<int> dimensions;
    public:
        PixelRenderObject(math::Vector2<int> dimensions) :
                PixelRenderObject(dimensions, {}) { };

        PixelRenderObject(math::Vector2<int> dimensions, std::vector<util::Colour> pixels) : pixels(std::move(pixels)),
                                                                                             dimensions(dimensions) { };

        void setPixels(std::vector<util::Colour> pixels);

        [[nodiscard]] std::vector<util::Colour> getPixels() const;

        size_t getPixelCount() const;

        void setDimensions(math::Vector2<int> dimensions);

        math::Vector2<int> getDimensions() const;

        void render() override;
    };
}

#endif
