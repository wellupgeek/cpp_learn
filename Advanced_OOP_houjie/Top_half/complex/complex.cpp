#include "complex.h"

template <typename T>
complex<T>& complex<T>::operator += (const complex<T>& rhs) {
    // this->im += rhs.im;
    // this->re += rhs.re;
    // return *this;
    return __doapl(this, rhs);
}

template <typename T>
complex<T>& __doapl (complex<T>* ths, const complex<T>& rhs) {
    ths->im += rhs.im;
    ths->re += rhs.re;
    return *ths;
}

template <typename T>
T real(const complex<T>& t) {
    return t.real();
}

template <typename T>
T image(const complex<T>& t) {
    return t.imag();
}

template <typename T>
complex<T> operator + (const complex<T>& lhs, const complex<T>& rhs) {
    return complex<T> (real(lhs) + real(rhs), 
                       image(lhs) + image(rhs));
}

template <typename T>
complex<T> operator + (const complex<T>& lhs, T rhs) {
    return complex<T> (real(lhs) + rhs, image(lhs));
}

template <typename T>
complex<T> operator + (T lhs, const complex<T>& rhs) {
    return complex<T> (lhs + real(rhs), image(rhs));
}

template <typename T>
std::ostream& operator<< (std::ostream& os, const complex<T>& t) {
    os << '(' << real(t) << ',' << image(t) << ')';
    return os;
}