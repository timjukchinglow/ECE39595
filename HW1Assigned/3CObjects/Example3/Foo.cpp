#include "Foo.h"
#include "Bar.h"

Foo::Foo(int i) {
    value = i;
}

int Foo::getVal( ) {
   return value;
}

void Foo::stupidPrintMe( ) {
   Bar* b = new Bar( );
   b->printAFoo(this); // S2
}
