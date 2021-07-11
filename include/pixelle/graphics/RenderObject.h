#ifndef PIXELLE_RENDEROBJECT_H
#define PIXELLE_RENDEROBJECT_H

#include <utility>
#include <vector>
#include <pixelle/util/Math.h>
#include <pixelle/util/Colour.h>

namespace pixelle::graphics {
    struct RenderObjectMeta;

    class RenderObject {
    protected:
        RenderObjectMeta* meta;
    public:
        virtual void setup() {};
        virtual void render() = 0;
        void renderAtWindow(math::Vector2<int> windowPos);
        void renderAtRaster(math::Vector2<float> rasterPos);
    };
}

#endif
