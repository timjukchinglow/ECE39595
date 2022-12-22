#ifndef LINE_H_
#define LINE_H_
class Line {
public:
    Line();
    Line(std::string);
    void setLine(std::string);
    std::string getLine();
    void parse(std::string);
    std::string getCommand();
    std::string getSymbol();
    std::string getValue();
    
private:
    std::string wholeLine;
    std::string command;
    std::string symbol;
    std::string value;

};
#endif /* LINE_H_ */
