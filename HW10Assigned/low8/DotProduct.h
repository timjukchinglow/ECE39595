#include <iostream>
#include <string>
#include <stdlib.h>
#include "Command.h"
using namespace std;

class DotProduct : public Command {
    private:
        int *a;
        int *b;
        int size;
        float val;
    public:
        friend std::ostream &operator<<(std::ostream &os, const DotProduct obj);
        DotProduct( );
        DotProduct(int l);
        virtual void execute( );
        virtual void identify( );
};