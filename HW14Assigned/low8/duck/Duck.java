package low8.duck;
import low8.fly.*;
import low8.quack.*;
import low8.eggs.*;

public abstract class Duck {

   public Duck( ) { }

   public abstract void display( );
   
   public void swim( ) {
      System.out.println("All ducks float");
   }
   
   public void performQuack ( ) {
      quackBehavior.quack( );
   }
   
   public void performFly( ) {
      flyBehavior.fly( );
   }

   public void performEggLaying( ) {
      laysEggsBehavior.laysEggs( );
   }
   
   public void setFlyBehavior(FlyBehavior fb) {
      flyBehavior = fb;
   }
      
   public void setQuackBehavior(QuackBehavior qb) {
      quackBehavior = qb;
   }

   public void setLaysEggsBehavior(LaysEggsBehavior leb) {
      laysEggsBehavior = leb;
   }

   protected QuackBehavior quackBehavior;
   protected FlyBehavior flyBehavior;
   protected LaysEggsBehavior laysEggsBehavior;
}

