#ifndef SWAP_H
#define SWAP_H

#include <string>
#include "Stmt.h"

class Swap : public Stmt {
    public:
        Swap() : Stmt("Swap") { };
};
#endif