#include <string>
#include "Label.h"

std::string label;
double location;

std::string setLabel(std::string lab){
    label = lab;
}
std::string getLabel() {
    return label;
}
void setLocation(double loc) {
    location = loc;
}
double getLocation() {
    return location;
}