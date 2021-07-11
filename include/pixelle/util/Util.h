#ifndef PIXELLE_UTIL_H
#define PIXELLE_UTIL_H

#include <string>
#include <cstdint>
#include <filesystem>

#define _str(...) std::string(__VA_ARGS__)

namespace pixelle {
    namespace util {
        template<typename I>
        std::string toHexString(I number);

        void wait(uint64_t ms);
        std::filesystem::path getExecutablePath();
        std::filesystem::path getExecutableDir();
        std::filesystem::path getWorkingDir();
        std::filesystem::path getRootDir();

        uint64_t uint64(const uint8_t arr[8]);
        int64_t int64(const uint8_t arr[8]);
        uint32_t uint32(const uint8_t arr[4]);
        int32_t int32(const uint8_t arr[4]);
        uint16_t uint16(const uint8_t arr[2]);
        int16_t int16(const uint8_t arr[2]);

        uint32_t random();

        template<typename TDuration = std::chrono::seconds>
        size_t getTime();
        std::string getFormattedTime(size_t timestampSeconds = getTime());
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
