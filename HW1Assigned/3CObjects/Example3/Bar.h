#ifndef Bar_H_
#define Bar_H_

#include <iostream>
#include "Foo.h"

class Bar {
public:
   virtual void printAFoo(Foo* f);
};
#endif /* BAR_H_ */
