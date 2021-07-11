#include <pixelle/Engine.h>

int main() {
    pixelle::Settings settings;
    settings.defaultColour = { 0, 0, 1 };
    settings.vsync = false;
    settings.minIntermission = 5;
    pixelle::start(new pixelle::scenes::Scene(), &settings);
}