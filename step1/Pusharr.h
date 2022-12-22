#ifndef PUSHARR_H
#define PUSHARR_H

#include <string>
#include "Stmt.h"

class Pusharr : public Stmt {
    public:
        std::string label;
        Pusharr(std::string i, int val) : Stmt("PushArray ", i, val) {label = i;};

};
#endif