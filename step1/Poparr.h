#ifndef POPARR_H
#define POPARR_H

#include <string>
#include "Stmt.h"

class Poparr : public Stmt {
    public:
        std::string label;
        int val;
        Poparr(std::string i, int val) : Stmt("PopArray ", i, val) {label = i;};
};
#endif