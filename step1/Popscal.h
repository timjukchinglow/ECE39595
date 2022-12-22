#ifndef POPSCAL_H
#define POPSCAL_H

#include <string>
#include "Stmt.h"

class Popscal : public Stmt {
    public:
        std::string label;
        int val;
        Popscal(std::string i, int val) : Stmt("PopScalar ", i, val) {label = i;};
};
#endif