#include <pixelle/graphics/RenderObject.h>
#include <pixelle/internal/gl_meta.h>
#include <pixelle/util/Exception.h>
#include <utility>

using namespace pixelle;

void pixelle::graphics::RenderObject::renderAtWindow(math::Vector2<int> windowPos) {
    glWindowPos2i(windowPos.x, windowPos.y);
    this->render();
}
void pixelle::graphics::RenderObject::renderAtRaster(math::Vector2<float> rasterPos) {
    glRasterPos2f(rasterPos.x, rasterPos.y);
    this->render();
}

// include implementations
#include "render_object/PixelRenderObject.cpp"
#include "render_object/ShapeRenderObject.cpp"