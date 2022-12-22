#ifndef DUP_H
#define DUP_H

#include <string>
#include "Stmt.h"

class Dup : public Stmt {
    public:
        Dup() : Stmt("Dup") { };
};
#endif