#include <iostream>

template <class T1, class T2>
struct pair{
    typedef T1 first_type;
    typedef T2 second_type;
    T1 first;
    T2 second;
    pair() : first{T1()}, second{T2()} {}
    pair(const T1& a, const T2& b) : first(a), second(b) {}
    template <typename U1, typename U2>
    pair(const pair<U1, U2>& p) : first(p.first), second(p.second) {}
};

template <typename T>
struct Identify{
    const T& operator() (const T& x) const { return x; }
};

template <class Pair>
struct SelectFirst{
    const typename Pair::first_type &
    operator() (const Pair& p) const { return p.first; }
};

template <class Pair>
struct SelectSecond{
    const typename Pair::second_type &
    operator() (const Pair& p) const { return p.second; }
};

int main()
{
    pair<int, double> a(1, 3.14);
    // std::cout << a.first << ' ' << a.second;

    std::cout << SelectFirst<pair<int, double>>()(a) << std::endl;
    std::cout << SelectSecond<pair<int, double>>()(a) << std::endl; 

    // pair<Base1, Base2> p(pair<Derived1, Derived2>());
}