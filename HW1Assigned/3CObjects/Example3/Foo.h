#ifndef B_H_
#define B_H_

#include <iostream>
#include "Foo.h"

class Foo {

private:
   int value;

public:
   Foo(int i);

   virtual int getVal( );

   virtual void stupidPrintMe( );
};

#endif /* FOO_H_ */
