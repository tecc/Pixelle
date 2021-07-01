#ifndef MANIFEST_H
#define MANIFEST_H

#include <pixelle/resources/Resource.h>
#include <nlohmann/json.hpp>
#include <filesystem>

#define MANIFEST_VERSION 1
class Manifest {
private:
    nlohmann::json object;
    std::string error = "";
    std::filesystem::path file;
public:
    explicit Manifest(std::filesystem::path file);
    nlohmann::json getObject();

    int getVersion();
    void setVersion(int version);

    void setResource(const std::string& name, const std::string& path);
    void removeResource(const std::string& name);
    std::string getResource(const std::string& name);

    void write();
};

#endif
