#include <iostream>

template <class Key>
struct Hash{ };

template <>
struct Hash<char>{
    const char& operator() (const char& x) const { return x; }
};

template <>
struct Hash<int>{
    const int& operator() (const int& x) const { return x; }
};

template <>
struct Hash<long>{
    const long& operator() (const long& x) const { return x; }
};

int main()
{
    std::cout << Hash<long>()(5000) << std::endl;
}