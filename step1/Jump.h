#ifndef JUMP_H
#define JUMP_H

#include <string>
#include "Stmt.h"

class Jump : public Stmt {
    public:
        std::string label;
        Jump(std::string i) : Stmt("Jump, ", i) {label = i;};
};
#endif