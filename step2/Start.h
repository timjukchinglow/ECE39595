#ifndef START_H
#define START_H

#include <string>
#include "Stmt.h"

class Start : public Stmt {
    public:
        int val;
        Start() : Stmt("Start ") { };
        Start(int i) : Stmt("Start ") {val = i;};
};
#endif