#include <iostream>
#include <string>
#include <stdlib.h>
#include "DotProduct.h"

std::ostream &operator<<(std::ostream &os, const DotProduct obj)
{
    os << "inner product on arrays of length " << obj.size << ", result is " << obj.val << "\n\n";
    return os;
}

DotProduct::DotProduct( ) {
    DotProduct(0);
}

DotProduct::DotProduct( int l ) : size(l) {
    val = 0;
    a = new int[l];
    b = new int[l];
    int i = 0;
    while (i < size) {
        a[i] = rand( );
        b[i] = rand( );
        i += 1;
    }
}

void DotProduct::execute(){ 
    for(int i = 0; i < size; i++){
        val += a[i] * b[i];
    }
}
void DotProduct::identify(){
    std::cout << *this;
}
