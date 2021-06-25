#include <iostream>
#include <cmath>
using namespace std;

class Complex{
public:
    Complex(double r, double m):re(r), im(m){}
    double mag() { return getmag(); }
    operator double () { return getmag(); }    // conversion operator
private:
    double re, im;
    double getmag() { return sqrt(re*re + im*im); }
};

int main()
{
    Complex com(3.0, 4.0);

    cout << com.mag() << endl;
    // same can be done like this
    double t = com; // Complex object type convert to double, maybe like (double)com
    cout << com << endl;
}