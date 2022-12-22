#include <iostream>
#include <string>
#include <sstream>
#include "Line.h"

    std::string wholeLine;
    std::string command = "";
    std::string symbol = "";
    std::string value = "";

Line::Line(){
    std::cout << "Created an object\n";
}
Line::Line(std::string whole){
    wholeLine = whole;
    parse(whole);
}

void Line::parse(std::string str){
    std::string token;
    std::stringstream S(str);
    int numParam = 1;
    while(getline(S, token, ' ')){
        if(numParam == 1){
            command = token;
        }
        else if(numParam == 2){
            symbol = token;
        }
        else if(numParam == 3){
            value = token;
        }
        numParam++;
    }

}

void Line::setLine(std::string thisLine){
    wholeLine = thisLine;
}
std::string Line::getLine(){
    std::cout << wholeLine << "\n";
    return wholeLine;
}

std::string Line::getCommand(){
    return command;
}
std::string Line::getSymbol(){
    return symbol;
}
std::string Line::getValue(){
    return value;
}


