#ifndef PIXELLE_RESOURCE_H
#define PIXELLE_RESOURCE_H

#include <string>

namespace pixelle::resources {
    class Resource {
    private:
        void** resource;
    };

    class ResourceManifest {
    private:
    public:
        bool resourceExists(std::string name);
        Resource getResource(std::string name);
        Resource operator [](std::string key) {
            return getResource(key);
        }
    };

    ResourceManifest getManifest();
    void loadManifest(std::string fileName = "resources.json");
    void getResource(std::string name);
}

#endif
