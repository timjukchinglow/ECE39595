#include <string>
#include "Stmt.h"

class End : public Stmt {
    public:
        End() : Stmt(op_code) {
            op_code = "End";
        };
};