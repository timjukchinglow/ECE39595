#ifndef JUMPZERO_H
#define JUMPZERO_H

#include <string>
#include "Stmt.h"

class JumpZero : public Stmt {
    public:
        std::string label;
        JumpZero(std::string i) : Stmt("JumpZero, ", i) {label = i;};
};
#endif