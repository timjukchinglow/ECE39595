#ifndef PEKINDUCK_H_
#define PEKINDUCK_H_
#include "Duck.h"
#include "FlyBehavior.h"
#include "QuackBehavior.h"
#include "LaysEggsBehavior.h"

class PekinDuck : public Duck { 
public:
   PekinDuck( );
   void display( );
};
#endif /* PEKINDUCK_H_ */
