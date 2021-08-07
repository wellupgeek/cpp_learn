#include <string.h>
#include <iostream>
#include <cassert>

using namespace std;

template <typename T>
class Complex {
public:
    Complex(T r, T i):real(r), imag(i){}
    Complex(const Complex& other):real(other.real), imag(other.imag){}
    Complex& operator= (const Complex& other) {
        if (&other == this)
            return *this;
        real = other.real;
        imag = other.imag;
        return *this;
    }
    friend Complex operator+ (const Complex&, const Complex&);
    friend Complex operator- (const Complex&, const Complex&);
    friend Complex operator* (const Complex&, const Complex&);
    friend Complex operator/ (const Complex&, const Complex&);
    friend ostream& operator<< (ostream&, const Complex&);
private:
    T real;
    T imag;
};

int main()
{

}