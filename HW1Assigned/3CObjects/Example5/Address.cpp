#include <string>
#include "Address.h"

Address::Address(std::string _street, std::string _city, std::string _state, std::string _postalCode) {
   street = _street;
   city = _city;
   state = _state;
   postalCode = _postalCode;
}

Address::Address(std::string _street, std::string _city, std::string _state, std::string _postalCode, std::string _country) {
   street = _street;
   city = _city;
   state = _state;
   postalCode = _postalCode;
   country = _country;
}

std::string Address::getStreet( ) {
   return street;
}

void Address::setStreet(std::string _street) {
   street = _street;
}

std::string Address::getCity( ) {
   return city;
}

void Address::setCity(std::string _city) {
   city = _city;
}

void Address::setState(std::string _state) {
   state = _state;
}

std::string Address::getState( ) {
   return state;
}

void Address::setPostalCode(std::string _postalCode) {
   postalCode = _postalCode;
}

std::string Address::getPostalCode( ) {
   return postalCode;
}

void Address::setCountry(std::string _country) {
   country = _country;
}

std::string Address::getCountry( ) {
   return country;
}

std::string Address::toString( ) {
   std::string address = street+"\n";
   address += city+"\n";
   address += state+"\n";
   address += country+"\n";
   address += postalCode+"\n";
   return address;
}
