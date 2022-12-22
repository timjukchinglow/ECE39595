#include <iostream>
#include <string>
#include <stdlib.h>
#include <vector>
#include <memory>
#include "Command.h"
using namespace std;

class WorkQueue { 
    private:
        vector<shared_ptr<Command>> queue;
    public:
        WorkQueue( ) {
            vector<shared_ptr<Command>> queue = { };
        };
        shared_ptr<Command> get( );
        void put(shared_ptr<Command>);
};