package low8;
import low8.duck.*;
import low8.fly.*;
import low8.quack.*;
import low8.eggs.*;

public class Main {

   public static void main(String[ ] args) {
      int maxDucks = 3;
   
      Duck ducks[ ] = new Duck[maxDucks];

      ducks[0] = new MallardDuck( );
      ducks[1] = new RedHeadDuck( );
      ducks[2] = new DecoyDuck( );
   
      for (int i=0; i<maxDucks; i++) {
         ducks[i].display( );
         ducks[i].performQuack( );
         ducks[i].performFly( );
         ducks[i].swim( );
         System.out.println(" "); 
      }
   }
}
