#include <pixelle-resources/Manifest.h>
#include <fstream>

Manifest::Manifest(std::filesystem::path filePath) {
    this->file = filePath;
    std::ifstream input = filePath;
    if (input.good()) {
        this->object = nlohmann::json::parse(input);
        input.close();
    }
    else this->object = nullptr;
    if (!this->object.is_object()) {
        this->object = nlohmann::json::object();
        this->setVersion(MANIFEST_VERSION);
    }
    if (!this->object["resources"].is_object()) {
        this->object["resources"] = nlohmann::json::object();
    }
    if (this->getVersion() != MANIFEST_VERSION) {
        this->error = "Invalid manifest";
    }
}

nlohmann::json Manifest::getObject() {
    return this->object;
}

void Manifest::setVersion(int version) {
    this->object["version"] = version;
}

int Manifest::getVersion() {
    return this->object["version"];
}

void Manifest::setResource(const std::string& name, const std::string& path) {
    auto res = this->object["resources"];
    if (!res.is_object()) {
        res = nlohmann::json::object();
    }
    res[name] = path;
    this->object["resources"] = res;
}

std::string Manifest::getResource(const std::string& name) {
    nlohmann::json res = this->object["resources"];
    if (!res.is_object()) {
        this->object["resources"] = nlohmann::json::object();
        return res;
    }
    if (!res[name].is_string()) return "";
    return res[name];
}

void Manifest::removeResource(const std::string& name) {
    auto res = this->object["resources"];
    res.erase(name);
    this->object["resources"] = res;
}

void Manifest::write() {
    std::ofstream out;
    out.open(this->file, std::ios::trunc | std::ios::out);
    out << this->object.dump(4, ' ');
    out.close();
}
