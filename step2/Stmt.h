#ifndef STMT_H
#define STMT_H

#include <string> 

class Stmt {
    
    protected:
        std::string op_code;
    public:
        int val;
        std::string label;
        virtual std::string getOpCode() {
            return op_code;
        };
        virtual int getVal() {
            return val;
        };
        Stmt(std::string s) {
            op_code = s;
        };
        Stmt(std::string s, std::string l) {
            op_code = s;
            label = l;
        };
        Stmt(std::string s, std::string l, int v) {
            op_code = s;
            label = l;
            val = v;
        };
        Stmt(std::string s, int v) {
            op_code = s;
            val = v;
        };
        friend std::ostream& operator<<(std::ostream& os, const Stmt& stmt) {
            os << stmt.op_code;
            return os;
        }
        // virtual ~Stmt();
};
#endif