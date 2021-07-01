#include <pixelle/Engine.h>
#include <pixelle/graphics/GraphicsAPI.h>
#include <pixelle/util/Util.h>

pixelle::Settings* settings;

void pixelle::start(pixelle::scenes::Scene* scene, pixelle::Settings* gameSettings) {
    pixelle::log::info("PIXELLE - 2D PIXEL GAME ENGINE - BY CAE'S LAB");
    pixelle::log::debug("Printing debug information");
    pixelle::log::debug("Executable location: " + util::getExecutablePath().string());
    pixelle::log::debug(" - Parent directory: " + util::getExecutableDir().string());
    // pixelle::log::debug("");
    pixelle::log::info("=====================================");

    settings = gameSettings;
    pixelle::log::info("Starting game");
    pixelle::graphics::initGraphics();

    while (true) {
        pixelle::graphics::updateGraphics();
        util::wait(1);
    }
}

pixelle::Settings pixelle::getSettings() {
    return *settings;
}
