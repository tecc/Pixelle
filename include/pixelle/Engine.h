#ifndef PIXELLE_ENGINE_H
#define PIXELLE_ENGINE_H

#include <pixelle/scenes/Scene.h>
#include <string>

namespace pixelle {
    struct Settings {
        std::string name = "Pixelle Game";
        bool vsync = true;
    };
    Settings getSettings();

    void start(pixelle::scenes::Scene* scene, Settings* settings = {});
}

#endif
