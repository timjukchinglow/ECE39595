#ifndef INSTRUCTIONBUFFER_H
#define INSTRUCTIONBUFFER_H

#include <string> 
#include <vector>
#include "Stmt.h"

class Instruct_Buff {
    private:
        Instruct_Buff();
        static Instruct_Buff* uniqueInstance;
    public:
        static Instruct_Buff* getInstance();
        std::vector<Stmt> buff;
};
#endif