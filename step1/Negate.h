#ifndef NEGATE_H
#define NEGATE_H

#include <string>
#include "Stmt.h"

class Negate : public Stmt {
    public:
        Negate() : Stmt("Negate") { };
};
#endif