#ifndef PIXELLE_UTIL_H
#define PIXELLE_UTIL_H

#include <string>

namespace pixelle {
    namespace util {
        template<typename I>
        std::string toHexString(I number);
    }

    namespace log {
        enum LogLevel {
            DEBUG,
            INFO,
            WARN,
            ERROR
        };

        void _log(std::ostream& out, LogLevel level, const std::string& message);
        void debug(const std::string& message);
        void info(const std::string& message);
        void warn(const std::string& message);
        void error(const std::string& message);
    }


}

#include <pixelle/util/Util.tcc>

#endif
