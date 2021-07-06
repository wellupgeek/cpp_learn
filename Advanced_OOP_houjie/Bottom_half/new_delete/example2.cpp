#include <string>
#include <iostream>

class Foo{
public:
    Foo(int _a = 0, std::string _str = ""):a(_a), str(_str){}
    static void* operator new(std::size_t);
    static void* operator new[](std::size_t);
    static void operator delete(void*, std::size_t);
    static void operator delete[](void*, std::size_t);
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
    // std::cout << sizeof(Foo) << std::endl;
    // std::cout << sizeof(std::string) << std::endl;
    Foo* p = new Foo;
    delete p;

    Foo* pb = ::new Foo;
    ::delete pb;
}