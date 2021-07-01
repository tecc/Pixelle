#include <pixelle/Engine.h>

int main() {
    pixelle::Settings settings;
    settings.vsync = false;
    pixelle::start(new pixelle::scenes::Scene(), &settings);
}