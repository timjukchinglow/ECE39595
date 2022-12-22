#ifndef MUL_H
#define MUL_H

#include <string>
#include "Stmt.h"

class Mul : public Stmt {
    public:
        Mul() : Stmt("Mul") { };
};
#endif