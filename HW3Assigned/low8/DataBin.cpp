#include <iostream>

#include "DataBin.h"

DataBin::DataBin(int _datum) {
   datum = new int(_datum);
}

DataBin::~DataBin( ) {
   std::cout << "deleting DataBin " << *datum << std::endl;
}

int DataBin::getDatum( ) {
   return *datum;
}
