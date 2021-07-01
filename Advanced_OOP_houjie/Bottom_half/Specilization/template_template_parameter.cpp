#include <list>
#include <memory>
#include <string>
#include <deque>

template <typename T, 
          template <typename T> 
          class Container>
class Xls{
private:
    Container<T> c;
public:
    ...
};

template <typename T>
using Lst = std::list<T, std::allocator<T>>;

// Xls<std::string, std::list> mylst1;  // wrong because std::list have 2 template parameter, this forgot allocator
Xls<std::string, Lst> mylst2;   // this have the allocator, so it is suitable

// second example for template template type only have one template parameter
template <typename T, 
          template <typename T>
          class SmartPtr>
class Xlsp{
private:
    SmartPtr<T> sp;
public:
    Xlsp() : sp(new T) {}
};

Xlsp<std::string, std::shared_ptr> obj1;
Xlsp<double, std::unique_ptr> obj2; // wrong
Xlsp<int, std::weak_ptr> obj3;      // wrong
Xlsp<long, std::auto_ptr> obj4;

// third example, attention this is not template template parameter
template <typename T, typename E = std::deque<T>>
class stack{
private:
    E st;
public:
    friend bool operator == <> (const stack& a, const stack& b);
    friend bool operator < <> (const stack& a, const stack& b);
};

stack<int> a1;
stack<int, std::list<int>> a2;
