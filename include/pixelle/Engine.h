#ifndef PIXELLE_ENGINE_H
#define PIXELLE_ENGINE_H

#include <pixelle/scenes/Scene.h>
#include <string>
#include <pixelle/util/Colour.h>

namespace pixelle {
    struct Settings {
        std::string name = "Pixelle Game";
        bool vsync = true;
        util::Colour defaultColour = .5f;
        /**
         * The window dimensions.
         * X functions as width and Y functions as height.
         */
        math::Vector2<int> dimensions = { 640, 480 };
        uint64_t minIntermission = 1;
    };
    Settings getSettings();

    void start(pixelle::scenes::Scene* scene, Settings* settings = {});
}

#endif
