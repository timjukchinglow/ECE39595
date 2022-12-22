package low8.duck;
import low8.fly.*;
import low8.quack.*;
import low8.eggs.*;

public class DecoyDuck extends Duck {

   public DecoyDuck( ) {
      flyBehavior = new FlyNoWay( );
      quackBehavior = new MuteQuack( );
      laysEggsBehavior = new DoesNotLayEggs( );
   }

   public void display( ) {
      System.out.println("I’m a decoy duck");
   }
}
