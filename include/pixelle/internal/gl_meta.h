#ifndef PIXELLE_GL_META_H
#define PIXELLE_GL_META_H

#include <glad/gl.h>
#include <GLFW/glfw3.h>

#ifdef PIXELLE_TEXTURE_H
#include <cstddef>

struct pixelle::graphics::TextureMeta {
    size_t id;
};
#endif

#ifdef PIXELLE_GRAPHICSAPI_H
struct pixelle::graphics::WindowMeta {
public:
    GLFWwindow* glfw;
};
#endif

#endif
