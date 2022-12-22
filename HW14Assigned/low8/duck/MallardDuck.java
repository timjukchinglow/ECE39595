package low8.duck;
import low8.fly.*;
import low8.quack.*;
import low8.eggs.*;

public class MallardDuck extends Duck {
   public MallardDuck( ) {
      quackBehavior = new Quack( );
      flyBehavior = new FlyWithWings( );
      laysEggsBehavior = new LaysEggsBroody( );
   }
   
   public void display( ) {
      System.out.println("I’m a real mallard duck");
   }
}
