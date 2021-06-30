#include <pixelle/util/Exception.h>

#include <utility>

pixelle::Exception::Exception(std::string message) {
    this->message = std::move(message);
}

const char* pixelle::Exception::what() const noexcept {
    return this->message.c_str();
}
