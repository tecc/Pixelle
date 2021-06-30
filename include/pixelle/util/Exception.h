#ifndef PIXELLE_EXCEPTION_H
#define PIXELLE_EXCEPTION_H

#include <string>
#include <exception>

namespace pixelle {
    class Exception : std::exception {
    private:
        std::string message;
    public:
        explicit Exception(std::string message = "");

        [[nodiscard]] const char* what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW override;
    };
}

#endif
