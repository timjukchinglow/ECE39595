#ifndef GOSUB_H
#define GOSUB_H

#include <string>
#include "Stmt.h"

class Gosub : public Stmt {
    public:
        Gosub(std::string i) : Stmt("GoSub ") {label = i;};
};
#endif