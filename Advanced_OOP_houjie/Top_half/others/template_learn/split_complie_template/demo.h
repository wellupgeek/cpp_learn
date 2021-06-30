#ifndef __DEMO__
#define __DEMO__

#include <iostream>

// 类的前置声明
template <typename T>
class Complex;

// 函数的前置声明
template <typename T>
std::ostream& operator<<(std::ostream&, const Complex<T>&);

template <typename T>
class Complex{
public:
    Complex(T, T);
    Complex<T> operator+(const Complex<T>&);
    friend std::ostream& operator<< <T>(std::ostream&, const Complex<T>&);    // 友元模板函数声明需要增加泛型支持
private:
    T re, im;
};

#endif