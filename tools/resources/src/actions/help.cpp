#include <pixelle-resources/Interface.h>
#include <iostream>

void printCommand(std::string cmdName, std::string desc) {
    std::cout << "    " << cmdName << std::endl
              << "     .. " << desc << std::endl;
}

void actions::help(const argh::parser& cmdl) {
    std::string exeName;
    cmdl(0) >> exeName;
    std::cout << "Usage: " << exeName << " <action> [args...]" << std::endl;
    std::cout << "Actions" << std::endl;
    printCommand("help",
                 "Displays help for the Pixelle Resource Tool");

    printCommand("init [manifestFile = 'resources.json']",
                 "Initialises a resource manifest.");

    printCommand("add [--manifestFile -m = 'resources.json'] <resourceFile> [resourceName]",
                 "Adds a resource to a resource manifest. Default name is the basename of the file.");

    printCommand("remove [--manifestFile -m = 'resources.json'] <resourceName>",
                 "Removes a resource.");

    printCommand("validate [manifestFile = 'resources.json']",
                 "Validates a manifest file.");

    printCommand("build [--manifestFile -m = 'resources.json'] [outputFile = 'resources.pxll']",
                 "Builds a manifest and compresses all the resources into a file Pixelle can use.");
}