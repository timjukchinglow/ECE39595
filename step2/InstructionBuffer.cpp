#include <string>
#include <vector>
#include "InstructionBuffer.h"

Instruct_Buff* Instruct_Buff::uniqueInstance = nullptr;

Instruct_Buff::Instruct_Buff( ) { } 

Instruct_Buff* Instruct_Buff::getInstance() {
    if (uniqueInstance == NULL) {
        uniqueInstance = new Instruct_Buff();
    }
    return uniqueInstance;
}


