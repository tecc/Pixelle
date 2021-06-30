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
    };
    Settings getSettings();

    void start(pixelle::scenes::Scene* scene, Settings* settings = {});
}

#endif
