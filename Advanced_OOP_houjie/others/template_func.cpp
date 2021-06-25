#include <iostream>

template <class T>
inline
const T& min(const T& a, const T& b) {
    return a < b ? a : b;
}

template <typename T>
class Stone{
public:
    Stone(T w, T h, T we):_w(w), _h(h), _weight(we){}
    bool operator < (const Stone& s) const;
private:
    T _w, _h, _weight;
};

template <typename T>
inline
bool Stone<T>::operator < (const Stone<T>& s) const {
    return _weight < s._weight;
}

int main()
{
    Stone<int> a(1, 2, 3), b(3, 4, 5);
    Stone<int> c = min(a, b);
}