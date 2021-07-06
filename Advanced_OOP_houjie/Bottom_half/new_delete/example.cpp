#include <string>
#include <iostream>

class Foo{
public:
    Foo(int _a = 0, std::string t = ""):a(_a), str(t){}
    void* operator new(std::size_t);
    void* operator new[](std::size_t);
    void operator delete(void*, std::size_t);
    void operator delete[](void*, std::size_t);
private:
    int a;
    std::string str;
};

void* Foo::operator new(std::size_t size) {
    std::cout << "operator new call" << std::endl;
    return std::malloc(size);
}

void* Foo::operator new[](std::size_t size) {
    std::cout << "operator new[] call" << std::endl;
    return std::malloc(size);
}

void Foo::operator delete(void* ptr, std::size_t) {
    std::cout << "operator delete call" << std::endl;
    std::free(ptr);
}

void Foo::operator delete[](void* ptr, std::size_t) {
    std::cout << "operator delete[] call" << std::endl;
    std::free(ptr);
}

int main()
{
    Foo* p = new Foo;
    delete p;

    Foo* pa = new Foo[3];
    delete[] pa;

}