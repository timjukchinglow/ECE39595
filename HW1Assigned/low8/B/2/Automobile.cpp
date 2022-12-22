#include <string>
#include <iostream>
#include "Automobile.h"

Automobile::Automobile(int _id, float _miles, int _mm, int _dd, int _yy) {
    id = _id;
    miles = _miles;
    mm = _mm;
    dd = _dd;
    yy = _yy;
}
int Automobile::getID( ) {
    return id;
}

float Automobile::getMiles( ) {
    return miles;
}

std::string Automobile::getDate( ) {
    std::string date = ""+std::to_string(mm)+"/"+std::to_string(dd)+"/"+std::to_string(yy);
    return date;
}

std::string Automobile::toString( ) {
   std::string automobile = std::to_string(id)+"\n";
   automobile += std::to_string(miles)+"\n";
   std::string date = getDate( );
   automobile += date;
   return automobile;
}