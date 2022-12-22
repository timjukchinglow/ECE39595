#ifndef LABEL_H
#define LABEL_H

#include <string>
#include "Stmt.h"

class Label : public Stmt {
    public:
        Label() : Stmt("Label") { };
        std::string getLabel();
        void setLocation(double);
        double getLocation();
        void setLabel(std::string);
    private:
        std::string label;
        double location;
        

};
#endif