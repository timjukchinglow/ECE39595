#ifndef ADD_H
#define ADD_H

#include <string>
#include "Stmt.h"

class Add : public Stmt {
    public:
        Add() : Stmt("Add") { };
};
#endif