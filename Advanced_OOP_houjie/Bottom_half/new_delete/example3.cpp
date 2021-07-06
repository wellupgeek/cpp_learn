#include <string>
#include <iostream>

class Foo{
public:
    Foo(int _a = 0, std::string _str = ""):a(_a), str(_str){}
    void* operator new(std::size_t);
    void* operator new[](std::size_t);
    void* operator new(std::size_t, void*);
    void* operator new(std::size_t, long);
    void* operator new(std::size_t, long, char);

    void operator delete(void*, std::size_t);
    void operator delete[](void*, std::size_t);
private:
    int a;
    std::string str;
};

void* Foo::operator new(std::size_t size) {
    Foo* p = (Foo*)malloc(size);
    std::cout << "operator new call, size = " << size << std::endl;
    return p;
}

void* Foo::operator new[](std::size_t size) {
    Foo* p = (Foo*)malloc(size);
    std::cout << "operator new[] call" << std::endl;
    return p;
}

void* Foo::operator new(std::size_t size, void* start) {
    return start;
}

void* Foo::operator new(std::size_t size, long other) {
    Foo* p = (Foo*)malloc(size + other);
    return p;
}

void* Foo::operator new(std::size_t size, long other, char init) {
    Foo* p = (Foo*)malloc(size + other);
    return p;
}

void Foo::operator delete(void* ptr, std::size_t size) {
    std::cout << "operator delete call, size = " << size << std::endl;
    free(ptr);
}

void Foo::operator delete[](void* ptr, std::size_t size) {
    std::cout << "operator delete[] call" << std::endl;
    free(ptr);
}

int main()
{
    // Foo* p = new Foo;
    // delete p;

    // Foo* pb = ::new Foo;
    // ::delete pb;

    Foo* p = new(100) Foo;
    std::cout << sizeof(*p) << std::endl;
    delete p;
}