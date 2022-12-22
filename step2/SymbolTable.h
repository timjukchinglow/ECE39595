#ifndef SYMBOLTABLE_H_
#define SYMBOLTABLE_H_
class SymbolTable {
private:
    static SymbolTable* uniqueInstance;
    double location;
    //std::map<std::string, std::pair<double,double>> symbolMap;

    SymbolTable();
    

public:
    static SymbolTable* getInstance();

    std::pair<double,double> getData(std::string);
    std::pair<double,double> getData2(std::string);
    std::map<std::string, std::pair<double,double>> getSym();
    std::map<std::string, std::pair<double,double>> getSym2();
    bool addSymbol(std::string, double);
    bool addLabel(std::string, double, double);
    bool addLabel2(std::string, double, double);
    bool deleteLabel(std::string);
    bool deleteSymbol(std::string);




};
#endif /* SYMBOLTABLE_H_ */