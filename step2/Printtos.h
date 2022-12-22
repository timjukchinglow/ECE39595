#ifndef PRINTTOS_H
#define PRINTTOS_H

#include <string>
#include "Stmt.h"

class Printtos : public Stmt {
    public:
        Printtos() : Stmt("PrintTOS") { };
};
#endif