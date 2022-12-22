#ifndef RETURNS_H
#define RETURNS_H

#include <string>
#include "Stmt.h"

class Returns : public Stmt {
    public:
        int val;
        Returns() : Stmt("Return") { };
        // Returns(int i) : Stmt("Return ") {val = i;};
};
#endif