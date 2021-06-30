#ifndef __COMPLEX__
#define __COMPLEX__

#include <iostream>

template <typename T>
class complex;

template <typename T>
complex<T>& __doapl (complex<T>*, const complex<T>&);

template <typename T>
class complex{
public:
    complex(T r = 0, T i = 0) : re(r), im(i){}
    complex& operator += (const complex&);
    T real() const { return re; }
    T imag() const { return im; }
    friend complex<T>& __doapl <T> (complex<T>*, const complex<T>&);
private:
    T re, im;
};

template <typename T>
T real(const complex<T>&);

template <typename T>
T image(const complex<T>&);

template <typename T>
complex<T> operator + (const complex<T>&, const complex<T>&);

template <typename T>
complex<T> operator + (const complex<T>&, T);

template <typename T>
complex<T> operator + (T, const complex<T>&);

template <typename T>
std::ostream& operator<< (std::ostream&, const complex<T>&);

#endif