#ifndef JUMP_H
#define JUMP_H

#include <string>
#include "Stmt.h"

class Jump : public Stmt {
    public:
        Jump(std::string lab) : Stmt("Jump") { 
            label = lab;
        };
        std::string getLabel() {};
        void setLocation(double) {};
        double getLocation() {};
    private:
        std::string label;
        double location;
        

};
#endif