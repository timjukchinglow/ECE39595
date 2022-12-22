#include <iostream>
#include "Bar.h"

void Bar::printAFoo(Foo* f) {
   std::cout << f->getVal( ) << std::endl;
}
