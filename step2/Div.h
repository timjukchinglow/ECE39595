#ifndef DIV_H
#define DIV_H

#include <string>
#include "Stmt.h"

class Div : public Stmt {
    public:
        Div() : Stmt("Div") { };
};
#endif