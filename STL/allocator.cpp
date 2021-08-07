#include <memory>
#include <list>
#include <string>
#include <vector>
#include <algorithm>
#include <ext\pool_allocator.h>

using namespace std;

bool strLonger(const string& a, const string& b) {
    return a.size() < b.size();
}

template <typename T>
inline const T& Max(const T& a, const T& b) {
    return a < b ? a : b;
}

template <typename T, class Compare>
inline const T& Max(const T& a, const T& b, Compare cmp) {
    return cmp(a, b) ? b : a;
}

template<> 
inline const int& Max(const int& a, const int& b) {
    return a < b ? a : b;
}

template <class T>
struct __list_node
{
    typedef void* void_pointer;
    void_pointer pre;
    void_pointer next;
    T data;
};

template <class T, class Ref, class Ptr>
struct __list_iterator {
    typedef __list_iterator self;
    typedef T value_type;
    typedef Ref reference;
    typedef Ptr pointer;
    typedef __list_node<T>* link_type;

    link_type node;

    reference operator*() { return (*node).data; }
    pointer operator->() { return &(operator*()); }
    self& operator++() { node = (link_type)((*node).next); return *this; }
    self operator++(int) { self tmp = *this; ++*this; return tmp; }
};

// iterator traits
template <class I>
struct iterator_traits {    // 如果I是class iterator
    typedef typename I::value_type value_type;
};

template <class T>
struct iterator_traits<T*> {
    typedef T value_type;
};

template <class T>
struct iterator_traits<const T*> {
    typedef T value_type;
};

template <typename T, ...>
void algorithm(...) {
    typename iterator_traits<T>::value_type v1;
}

int main()
{
    list<string, allocator<string>> c1;
    list<string, __gnu_cxx::__pool_alloc<string>> c2;

    string h = "ggg";
    c1.push_back(h);
    c2.push_back(h);

    int *p;
    allocator<int> alloc1;
    p = alloc1.allocate(1);
    alloc1.deallocate(p, 1);

    __gnu_cxx::__pool_alloc<int> alloc2;
    p = alloc2.allocate(1);
    alloc2.deallocate(p,1);

    vector<int> vint = {1,2,3};
    Max(string("hello"), string("bbb"), strLonger);

}