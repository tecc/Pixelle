#ifndef PIXELLE_SPRITERENDEROBJECT_H
#define PIXELLE_SPRITERENDEROBJECT_H

#include <filesystem>
#include <pixelle/graphics/RenderObject.h>

namespace pixelle::graphics {
    class SpriteRenderObject : RenderObject {
    private:
    public:
        SpriteRenderObject(std::filesystem::path path);
    };
}

#endif
