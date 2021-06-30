#include <pixelle/Engine.h>

int main() {
    pixelle::Settings settings;

    pixelle::start(new pixelle::scenes::Scene(), &settings);
}