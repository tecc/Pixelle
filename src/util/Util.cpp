#include <pixelle/util/Util.h>
#include <sstream>
#include <iostream>

using namespace pixelle;

void log::_log(log::LogLevel level, const std::string& message) {
    std::string prefix = "[Pixelle ";
    switch (level) {
        #define llx(X, y) case X: prefix += y #X; break
        #define ll(X) llx(X, "")
        ll(DEBUG);
        llx(INFO, " ");
        llx(WARN, " ");
        ll(ERROR);
        #undef ll
    }
    prefix += "]: ";
    std::stringstream out;
    out << prefix;
    for (char c : message) {
        out << c;
        if (c == '\n') out << prefix;
    }
    std::cout << out.str() << std::endl;
}

#define ll(x, Y) void log::x(const std::string& message) { log::_log(log::LogLevel::Y, std::move(message)); }
ll(debug, DEBUG)
ll(info, INFO)
ll(warn, WARN)
ll(error, ERROR)
#undef ll