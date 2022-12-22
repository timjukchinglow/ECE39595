#ifndef ADDRESS_H_
#define ADDRESS_H_

#include <string>

class Address {
private:
   std::string street;
   std::string city;
   std::string state;
   std::string postalCode;
   std::string country = "USA";

public:
   Address(std::string _street, std::string _city, std::string _state, std::string _postalCode);
   Address(std::string _street, std::string _city, std::string _state, std::string _postalCode, std::string _country);
   virtual std::string toString( );

   virtual std::string getStreet( );
   virtual void setStreet(std::string _street);

   virtual std::string getCity( );
   virtual void setCity(std::string _city);

   virtual void setState(std::string _state);
   virtual std::string getState( );

   virtual void setPostalCode(std::string _postalCode);
   virtual std::string getPostalCode( );

   virtual void setCountry(std::string _country);
   virtual std::string getCountry( );
};
#endif /* ADDRESS_H_ */
