#ifndef NEGATE_H
#define NEGATE_H

#include <string>
#include "Stmt.h"

class Pop : public Stmt {
    public:
        Pop() : Stmt("Pop") { };
};
#endif