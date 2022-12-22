#ifndef PUSHSCAL_H
#define PUSHSCAL_H

#include <string>
#include "Stmt.h"

class Pushscal : public Stmt {
    public:
        std::string label;
        Pushscal(std::string i, int val) : Stmt("PushScalar ", i, val) {label = i;};

};
#endif