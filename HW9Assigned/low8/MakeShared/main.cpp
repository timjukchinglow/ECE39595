#include "Duck.h"
#include "RedHeadDuck.h"
#include "MallardDuck.h"
#include "DecoyDuck.h"
#include "FlyNoWay.h"
#include <memory>
#include <iostream>

int main(int argc, char *argv[]) {
   // Duck* red = new RedHeadDuck( );
   auto red = std::make_shared<RedHeadDuck>( );
   auto mallard = std::make_shared<MallardDuck>( );
   auto decoy = std::make_shared<DecoyDuck>( );

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

   decoy->performFly( );
}
