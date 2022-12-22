#ifndef DUCK_H_
#define DUCK_H_
#include "QuackBehavior.h"
#include "FlyBehavior.h"
#include <memory>

class Duck {
public:
   Duck( );
   virtual void setFlyBehavior(FlyBehavior*);
   virtual void setQuackBehavior(QuackBehavior*);
   virtual void performQuack ( );
   virtual void performFly ( );
   virtual void swim( );
   virtual void display( )=0;
   // typedef std::shared_ptr<Duck> Ptr( );
protected:
   QuackBehavior* quackBehavior;
   FlyBehavior* flyBehavior;
};
#endif /* DUCK_H_ */
