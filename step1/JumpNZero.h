#ifndef JUMPNZERO_H
#define JUMPNZERO_H

#include <string>
#include "Stmt.h"

class JumpNZero : public Stmt {
    public:
        std::string label;
        JumpNZero(std::string i) : Stmt("JumpNZero, ", i) {label = i;};
};
#endif