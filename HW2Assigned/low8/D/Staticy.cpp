#include "Staticy.h"
#include <iostream>

int Staticy::EvenCount = 0;

int Staticy::getEvenCount() {
    return EvenCount;
}

Staticy* Staticy::makeStaticy(int i) {
    Staticy * newStaticy = new Staticy(i);
    return newStaticy;
}

Staticy::Staticy(int _i) {
    int i = _i;
    if (i%2 == 0) {
        EvenCount++;
    }
}
