#include <pixelle/Engine.h>
#include <pixelle/graphics/GraphicsAPI.h>
#include <pixelle/util/Util.h>

pixelle::Settings* settings;

void pixelle::start(pixelle::scenes::Scene* scene, pixelle::Settings* gameSettings) {
    settings = gameSettings;
    pixelle::log::info("Starting game");
    pixelle::graphics::initGraphics();

    while (true) {
        pixelle::graphics::updateGraphics();
    }
}

pixelle::Settings pixelle::getSettings() {
    return *settings;
}
