#ifndef PRINTS_H
#define PRINTS_H

#include <string>
#include "Stmt.h"

class Prints : public Stmt {
    public:
        Prints(std::string i) : Stmt("Prints " + i) {};
};
#endif