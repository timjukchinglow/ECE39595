#ifndef POP_H
#define POP_H

#include <string>
#include "Stmt.h"

class Pop : public Stmt {
    public:
        Pop() : Stmt("Pop") { };
};
#endif