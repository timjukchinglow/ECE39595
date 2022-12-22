#include <string>
#include <iostream>
#include "Automobile.h"

Automobile::Automobile(int _id, float _miles, int _mm, int _dd, int _yy) {
    id = _id;
    miles = _miles;
    date = ""+std::to_string(_mm)+"/"+std::to_string(_dd)+"/"+std::to_string(_yy);
}
int Automobile::getID( ) {
    return id;
}

float Automobile::getMiles( ) {
    return miles;
}

std::string Automobile::getDate( ) {
    return date;
}

std::string Automobile::toString( ) {
   std::string automobile = std::to_string(id)+"\n";
   automobile += std::to_string(miles)+"\n";
   std::string date = getDate( );
   automobile += date;
   return automobile;
}