#ifndef EXIT_H
#define EXIT_H

#include <string>
#include "Stmt.h"

class Exit : public Stmt {
    public:
        Exit() : Stmt("Exit") { };
};
#endif