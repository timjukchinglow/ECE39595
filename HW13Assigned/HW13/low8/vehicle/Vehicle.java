package low8.vehicle;

public class Vehicle {

   String model;

   Vehicle(String _model) {
      model = _model;
      System.out.print(model);
   }

   public String getModel( ) { 
      return null;
   }

   public String getVehicleModel( ) {
      return getModel( );
   }

   public String getColor( ) { 
      return null;
   }

   public String getEngine( ) {
      return null;
   }

   public String getTransmission( ) {
      return null;
   }

   public int getNumPassengers( ) {
      return 0;
   }

   public String getWarranty( ) {
      return null;
   }
}
