#ifndef INTERFACE_H
#define INTERFACE_H

#include <argh.h>

typedef void(*Action)(const argh::parser&);

Action getAction(std::string name);

namespace actions {
    void help(const argh::parser&);
    void init(const argh::parser&);
    void add(const argh::parser&);
    void remove(const argh::parser&);
    void validate(const argh::parser&);
    void build(const argh::parser&);
}

#endif
