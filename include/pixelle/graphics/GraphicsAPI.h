#ifndef PIXELLE_GRAPHICSAPI_H
#define PIXELLE_GRAPHICSAPI_H

namespace pixelle::graphics {
    struct WindowMeta;
    class Window {
    private:
        WindowMeta* meta;
    public:
        Window();

        void update();
        void onClose();
    };

    void initGraphics();
    void updateGraphics();
    Window* getWindow();
}

#endif
