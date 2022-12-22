#ifndef PUSHI_H
#define PUSHI_H

#include <string>
#include "Stmt.h"

class Pushi : public Stmt {
    public:
        Pushi(std::string i) : Stmt("PushI  (" + i + ")") {};
};
#endif