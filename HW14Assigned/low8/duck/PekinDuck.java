package low8.duck;
import low8.fly.*;
import low8.quack.*;
import low8.eggs.*;


public class PekinDuck extends Duck {
   public PekinDuck( ) {
      quackBehavior = new Quack( );
      flyBehavior = new FlysPoorly( );
      laysEggsBehavior = new LaysEggsNotBroody( );
   }

   public void display( ) {
      System.out.println("I’m a real pekin duck");
   }
}
