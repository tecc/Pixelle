#ifndef PIXELLE_GRAPHICSAPI_H
#define PIXELLE_GRAPHICSAPI_H

#include <pixelle/util/Math.h>

namespace pixelle::graphics {
    struct WindowMeta;
    class Window {
    private:
        WindowMeta* meta;
    public:
        Window();

        void update();
        void onClose();
        void onFramebufferSize(int width, int height);
        math::Vector2<int> getFramebufferSize();

        bool shouldClose();
    };

    void initGraphics();
    void updateGraphics();
    Window* getWindow();
}

#endif
