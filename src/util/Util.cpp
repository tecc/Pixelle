#include <pixelle/util/Util.h>
#include <sstream>
#include <iostream>
#include <pixelle/util/Math.h>
#include <bsd/stdlib.h>

using namespace pixelle;

std::string util::getFormattedTime(size_t timestampSeconds) {
    // YYYY-mm-dd HH:MM:SS
    char* out = (char*) calloc(20, sizeof(char)); // the format requires 19 characters, add 1 for NULL ending
    strftime(out, 20, "%Y-%m-%d %H:%M:%S", gmtime((time_t*) &timestampSeconds));
    return std::string(out);
}

void log::_log(std::ostream& out, log::LogLevel level, const std::string& message) {
    std::string prefix = "[Pixelle ";
    switch (level) {
        #define llx(X, y) case X: prefix += y #X " "; break
        #define ll(X) llx(X,)
        ll(DEBUG);
        llx(INFO, " ");
        llx(WARN, " ");
        ll(ERROR);
        #undef ll
    }
    prefix += util::getFormattedTime();
    prefix += "]: ";
    std::stringstream compiled;
    compiled << prefix;
    for (char c : message) {
        compiled << c;
        if (c == '\n') compiled << prefix;
    }
    out << compiled.str() << std::endl;
}

uint32_t pixelle::util::random() {
    return arc4random();
}

#define ll(o, x, Y) void log::x(const std::string& message) { log::_log(o, log::LogLevel::Y, std::move(message)); }

ll(std::cout, debug, DEBUG)
ll(std::cout, info, INFO)
ll(std::cerr, warn, WARN)
ll(std::cerr, error, ERROR)

#undef ll

std::filesystem::path util::getExecutableDir() {
    return getExecutablePath().parent_path();
}

std::filesystem::path util::getWorkingDir() {
    return std::filesystem::path();
}

#define c(i, o) ((uint64_t) arr[i] << (o))
inline uint64_t util::uint64(const uint8_t* arr) {
    return c(7, 56) | c(6, 48) | c(5, 40) | c(4, 32) | c(3, 24) | c(2, 16) | c(1, 8) | c(0, 0);
}
inline int64_t util::int64(const uint8_t* arr) {
    return c(7, 56) | c(6, 48) | c(5, 40) | c(4, 32) | c(3, 24) | c(2, 16) | c(1, 8) | c(0, 0);
}
#undef c
#define c(i, o) ((uint32_t) arr[i] << (o))
inline uint32_t util::uint32(const uint8_t* arr) {
    return c(3, 24) | c(2, 16) | c(1, 8) | c(0, 0);
}
inline int32_t util::int32(const uint8_t* arr) {
    return c(3, 24) | c(2, 16) | c(1, 8) | c(0, 0);
}
#undef c
#define c(i, o) ((uint32_t) arr[i] << (o))
inline uint16_t util::uint16(const uint8_t* arr) {
    return c(1, 8) | c(0, 0);
}
inline int16_t util::int16(const uint8_t* arr) {
    return c(1, 8) | c(0, 0);
}
#undef c