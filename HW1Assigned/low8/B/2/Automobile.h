#include <string>

class Automobile {
private:
    int id;
    float miles;
    int mm;
    int dd;
    int yy;

public:
    Automobile(int _id, float _miles, int _mm, int _dd, int _yy);
    virtual int getID( );
    virtual float getMiles( );
    virtual std::string getDate( );
    virtual std::string toString( );
};