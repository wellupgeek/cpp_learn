#include "complex.h"
#include <iostream>

inline complex& complex::operator += (const complex& rhs) {
    return __doapl (this, rhs);
}

inline complex& __doapl (complex* ths, const complex& rhs) {
    ths->im += rhs.im;
    ths->re += rhs.re;
    return *ths;
}

inline double real(const complex& t) {
    return t.real();
}

inline double image(const complex& t) {
    return t.imag();
}

inline complex
operator + (const complex& lhs, const complex& rhs) {
    return complex (real(lhs) + real(rhs), 
                    image(lhs) + image(rhs));
}

inline complex
operator + (const complex& lhs, double rhs) {
    return complex (real(lhs) + rhs, image(lhs));
}

inline complex
operator + (double lhs, const complex& rhs) {
    return complex (lhs + real(rhs), image(rhs));
}

std::ostream&
operator << (std::ostream& os, const complex& t) {
    os << '(' << real(t) << ',' << image(t) << ')\n';
}