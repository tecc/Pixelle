#include <pixelle-resources/Manifest.h>
#include <pixelle-resources/Interface.h>

#include <argh.h>
#include <iostream>

Action getAction(std::string name) {
    if (name == "help") {
        return actions::help;
    }
    if (name == "init") {
        return actions::init;
    }
    return nullptr;
}

int main(int argc, char** argv) {
    std::cout << "Pixelle Resource Tool (pixelle-resources)" << std::endl;
    auto cmdl = argh::parser(argc, argv);

    std::string action;
    if (!cmdl(1)) {
        std::cout << "No action specified, resorting to help" << std::endl;
        action = "help";
    }
    else cmdl(1) >> action;

    auto actionf = getAction(action);
    if (actionf == nullptr) {
        std::cout << "Invalid action, resorting to help" << std::endl;
        actionf = actions::help;
    } else {
        std::cout << "Running action '" << action << "'" << std::endl;
    }
    std::cout << std::endl;
    actionf(cmdl);
}