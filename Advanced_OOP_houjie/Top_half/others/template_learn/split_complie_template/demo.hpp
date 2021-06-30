#include "demo.h"

template <typename T>
Complex<T>::Complex(T a, T b) {
    re = a;
    im = b;
}

template <typename T>
Complex<T> Complex<T>::operator+ (const Complex<T>& comp) {
    return Complex(this->re+comp.re, this->im+comp.im);
}

template <typename T>
std::ostream& operator<< (std::ostream& os, const Complex<T>& comp) {
    os << '(' << comp.re << ',' << comp.im << ')';
    return os;
}