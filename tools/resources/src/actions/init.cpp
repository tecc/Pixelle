#include <pixelle-resources/Interface.h>
#include <pixelle-resources/Manifest.h>
#include <pixelle/util/Util.h>
#include <iostream>

void actions::init(const argh::parser& cmdl) {
    std::string fileName;
    if (cmdl(2)) cmdl(2) >> fileName;
    else fileName = "resources.json";

    std::cout << "Writing to file " << fileName << std::endl;

    Manifest manifest{pixelle::util::getWorkingDir().append(fileName)};
    manifest.setVersion(MANIFEST_VERSION);
    manifest.write();

    std::cout << "Written manifest" << std::endl;
}