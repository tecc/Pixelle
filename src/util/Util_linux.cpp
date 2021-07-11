#include <pixelle/util/Util.h>
#include <unistd.h>

#define PATH_MAX 65535

void pixelle::util::wait(uint64_t ms) {
    usleep(ms * 1000);
}

std::filesystem::path pixelle::util::getExecutablePath() {
    char result[PATH_MAX];
    ssize_t count = readlink("/proc/self/exe", result, PATH_MAX);
    return std::filesystem::path(std::string(result, (count > 0) ? count : 0));
}

std::filesystem::path pixelle::util::getRootDir() {
    return std::filesystem::path("/");
}