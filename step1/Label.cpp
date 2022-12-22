#include <string>
#include "Label.h"

// std::string label;
// double location;

void Label::setLabel(std::string lab){
    label = lab;
}
std::string Label::getLabel() {
    return label;
}
void Label::setLocation(double loc) {
    location = loc;
}
double Label::getLocation() {
    return location;
}