#ifndef GOSUBLABEL_H
#define GOSUBLABEL_H

#include <string>
#include "Stmt.h"

class Gosublabel : public Stmt {
    public:
        Gosublabel(std::string i) : Stmt("GoSubLabel " + i) {};
};
#endif