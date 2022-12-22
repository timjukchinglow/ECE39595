#include "Duck.h"
#include "RedHeadDuck.h"
#include "MallardDuck.h"
#include "DecoyDuck.h"
#include "FlyNoWay.h"
#include <memory>
#include <iostream>

int main(int argc, char *argv[]) {
   // Duck* red = new RedHeadDuck( );
   std::shared_ptr<Duck> red( new RedHeadDuck( ) );
   std::shared_ptr<Duck> mallard( new MallardDuck( ) );
   std::shared_ptr<Duck> decoy( new DecoyDuck( ) );

   red->performQuack( );
   red->performFly( );
   red->swim( );
   red->setFlyBehavior(new FlyNoWay( ));
   red->performFly( );

   std::cout << "\n";

   mallard->performQuack( );
   mallard->performFly( );
   mallard->swim( );
   mallard->setFlyBehavior(new FlyNoWay( ));
   mallard->performFly( );

   std::cout << "\n";

   decoy->performQuack( );
   decoy->performFly( );
   decoy->swim( );
   decoy->setFlyBehavior(new FlyNoWay( ));
   decoy->performFly( );
}
