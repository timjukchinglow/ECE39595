#include <iostream>
#include "Automobile.h"

int main(int argc, char* argv[ ]) {
   Automobile* automobile1 = new Automobile(123, 100232, 1, 20, 2000);
   std::cout << automobile1->toString( ) << std::endl;    

   Automobile* automobile2 = new Automobile(456, 64634, 7, 5, 2010);
   std::cout << automobile2->toString( ) << std::endl; 
}
