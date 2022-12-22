#include <map>
#include <string>
#include <utility>
#include <iostream>
#include "SymbolTable.h"

//Private
    SymbolTable* SymbolTable::uniqueInstance = nullptr;
    int location = 0;
    std::map<std::string, std::pair<double,double>> symbolMap;
    std::map<std::string, std::pair<double,double>> symbolMap2;

    SymbolTable::SymbolTable(){
        if(uniqueInstance != nullptr){
            std::cout << "Error: SymbolTable already initialized\n";
        }
    }
    

//Public

    SymbolTable* SymbolTable::getInstance(){
        if (uniqueInstance == nullptr) {
            uniqueInstance = new SymbolTable( );
        }
        return uniqueInstance;
    }

    //Returns a pair of doubles <location, length> from the key.
    //To access location it is pair.first, length is pair.second, where pair is the return value
    std::pair<double,double> SymbolTable::getData(std::string key){
        return symbolMap[key];
    }

    std::pair<double,double> SymbolTable::getData2(std::string key){
        return symbolMap2[key];
    }

    std::map<std::string, std::pair<double,double>> SymbolTable::getSym(){
        return symbolMap;
    }
    std::map<std::string, std::pair<double,double>> SymbolTable::getSym2(){
        return symbolMap2;
    }

    //Adds a new symbol to the symbol table. Returns true if successful, false otherwise
    //key is the identifier, location is the location in the InstructionBuffer, length is the length of the data (ie 1 for scalar, 0 for labels, length of array for arrays)
    bool SymbolTable::addSymbol(std::string key, double length){
        if(symbolMap.find(key) == symbolMap.end()){
            std::pair<double,double> data;
            data.first = location;
            data.second = length;
            symbolMap[key] = data;
            location++;
        }
        else{
            
            return false;
        }
        return true;
        
    }
    bool SymbolTable::addLabel(std::string key, double loc, double length){
        if(symbolMap.find(key) == symbolMap.end()){
            std::pair<double,double> data;
            data.first = loc;
            data.second = length;
            symbolMap[key] = data;
        }
        else{
            return false;
        }
        return true;
        
    }

    bool SymbolTable::addLabel2(std::string key, double loc, double length){
        if(symbolMap2.find(key) == symbolMap2.end()){
            std::pair<double,double> data;
            data.first = loc;
            data.second = length;
            symbolMap2[key] = data;
        }
        else{
            return false;
        }
        return true;
        
    }

    //Deletes a symbol based on the key. Returns true if successful, false otherwise
    bool SymbolTable::deleteSymbol(std::string key){
        if(symbolMap.find(key) != symbolMap.end()){
            symbolMap.erase(key);
        }
        else{
            std::cout << "ERROR: Cannot delete symbol. key [" << key << "] not found.\n";
            return false;
        }
        return true;
    }

    bool SymbolTable::deleteLabel(std::string key){
        if(symbolMap.find(key) != symbolMap.end()){
            symbolMap.erase(key);
        }
        else{
            std::cout << "ERROR: Cannot delete symbol. key [" << key << "] not found.\n";
            return false;
        }
        return true;
    }