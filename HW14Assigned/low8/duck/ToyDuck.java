package low8.duck;
import low8.fly.*;
import low8.quack.*;
import low8.eggs.*;

public class ToyDuck extends Duck {
   public ToyDuck( ) {
      quackBehavior = new Quack( );
      flyBehavior = new FlyNoWay( );
      laysEggsBehavior = new LaysToyEggs( );
   }

   public void display( ) {
      System.out.println("I’m a toy duck");
   }
}
