#ifndef DATA_H
#define DATA_H

#include <string>
#include <vector>

class Data {
    
    public:
        std::string index;
        std::vector<std::string> vars;
        virtual std::string getIndex() {
            return index;
        };

        Data() {
            index = 'A';
        };
        friend std::ostream& operator<<(std::ostream& os, const Data& data) {
            os << data.index;
            return os;
        }
        // virtual ~Stmt();
};
#endif