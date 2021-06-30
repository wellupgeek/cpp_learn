#include <iostream>
using namespace std;

class Complex{
public:
    // explicit keyword means such function must explicit conversion if must be.
    explicit Complex(double r=0.0, double i=0.0):re(r), im(i){}
    bool operator == (const Complex& comp) const {
        return (re == comp.re && im == comp.im) ? true : false;
    }
private:
    double re, im;
};

int main()
{
    Complex com1(3.0, 0.0);

    if (com1 == (Complex)3.0)    // the output is "Same", if there is not explicit keyword
        cout << "Same"; // implicit conversion
    else
        cout << "Not Same";
    return 0;
}