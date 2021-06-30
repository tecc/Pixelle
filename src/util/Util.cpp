#include <pixelle/util/Util.h>
#include <sstream>
#include <iostream>
#include <pixelle/util/Math.h>

using namespace pixelle;

void log::_log(std::ostream& out, log::LogLevel level, const std::string& message) {
    std::string prefix = "[Pixelle ";
    switch (level) {
        #define llx(X, y) case X: prefix += y #X; break
        #define ll(X) llx(X,)
        ll(DEBUG);
        llx(INFO, " ");
        llx(WARN, " ");
        ll(ERROR);
        #undef ll
    }
    prefix += "]: ";
    std::stringstream compiled;
    compiled << prefix;
    for (char c : message) {
        compiled << c;
        if (c == '\n') compiled << prefix;
    }
    out << compiled.str() << std::endl;
}

#define ll(o, x, Y) void log::x(const std::string& message) { log::_log(o, log::LogLevel::Y, std::move(message)); }

ll(std::cout, debug, DEBUG)
ll(std::cout, info, INFO)
ll(std::cerr, warn, WARN)
ll(std::cerr, error, ERROR)

#undef ll