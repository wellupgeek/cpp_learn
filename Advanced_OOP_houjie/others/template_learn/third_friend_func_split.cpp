#include <iostream>
using namespace std;

/**
 * 在编译器进行编译的时候，编译器会产生类的模板函数的声明，当时实际确认类型后调用的时候，
 * 会根据调用的类型进行再次帮我们生成对应类型的函数声明和定义。我们称之为二次编译。
 * 同样，因为这个机制，会经常报错找不到类的函数的实现。在模板类的友元函数外部定义时，
 * 也会出现这个错误。解决方法是 “ 类的前置声明和函数的前置声明 ”。
 * 
 */

// 类的前置声明
template <typename T>
class Complex;

// 函数的前置声明
template <typename T>
ostream& operator<<(ostream&, const Complex<T>&);

template <typename T>
class Complex{
public:
    Complex(T, T);
    Complex<T> operator+(const Complex<T>&);
    friend ostream& operator<< <T>(ostream&, const Complex<T>&);    // 友元模板函数声明需要增加泛型支持
private:
    T re, im;
};

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
ostream& operator<< (ostream& os, const Complex<T>& comp) {
    os << '(' << comp.re << ',' << comp.im << ')';
    return os;
}

int main()
{
    Complex<int> a(1,3);
    cout << a << '\n';
}