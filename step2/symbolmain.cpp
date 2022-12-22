#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include "SymbolTable.h"
using namespace std;

int main(int argc, char** args) {

    SymbolTable* symTable = SymbolTable::getInstance();

    symTable->addSymbol("A", 0);
    double location = symTable->getData("A").first;
    double length = symTable->getData("A").second;
    cout << "A: <" << location << ", " << length << ">" << "\n";

   
    symTable->addSymbol("B", 12);
    location = symTable->getData("B").first;
    length = symTable->getData("B").second;
    cout << "B: <" << location << ", " << length << ">" << "\n";

    symTable->addSymbol("C1", 1);
    location = symTable->getData("C1").first;
    length = symTable->getData("C1").second;
    cout << "C1: <" << location << ", " << length << ">" << "\n";

    symTable->addSymbol("C2", 2);
    location = symTable->getData("C2").first;
    length = symTable->getData("C2").second;
    cout << "C2: <" << location << ", " << length << ">" << "\n";

    symTable->addSymbol("C3", 3);
    location = symTable->getData("C3").first;
    length = symTable->getData("C3").second;
    cout << "C3: <" << location << ", " << length << ">" << "\n";

    symTable->addSymbol("D", 40000000);
    location = symTable->getData("D").first;
    length = symTable->getData("D").second;
    cout << "D: <" << location << ", " << length << ">" << "\n";

 
    
    
}
