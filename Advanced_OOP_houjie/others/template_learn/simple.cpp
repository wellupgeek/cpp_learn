#include <iostream>

template <typename T>
class Complex{
public:
    Complex(T a, T b):re(a), im(b){}
    // Complex operator + (const Complex& rhs) {
    //     return Complex(this->re+rhs.re, this->im+rhs.im); 
    // }
    // Complex operator + () {
    //     return Complex(this->re, this->im); 
    // }
    friend std::ostream& operator << (std::ostream& os, const Complex& comp) {
        os << '(' << comp.re << ',' << comp.im << ')';
        return os;
    }
    friend Complex operator + (const Complex& lhs, const Complex& comp) {
        return Complex(lhs.re+comp.re, lhs.im+comp.im);
    }

private:
    T re, im;
};

int main()
{
    Complex<int> a(1, 3);
    // Complex<double> c(2.1, 3.8);
    Complex<int> b(2, 4);
    Complex<int> c = a + b;
    std::cout << c << '\n';
    std::cout << a << '\n';
    // std::cout << c << '\n';

    return 0;
}