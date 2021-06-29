#include <iostream>

class Base{
public:
    Base() {
        std::cout << "Base ctor\n";
    }
    virtual ~Base() {
        std::cout << "Base dtor\n";
    }
    virtual void foo() {}
};

class Component{
public:
    Component() {
        std::cout << "Component ctor" << '\n';
    }
    ~Component() {
        std::cout << "Component dtor" << '\n';
    }
    void foo() {
        std::cout << "Component virtual foo()" << '\n';
    }
};

class Derived : public Base{
public:
    Derived() { std::cout << "Derived ctor\n"; }
    ~Derived() { std::cout << "Derived dtor\n"; }
    virtual void foo() {
        std::cout << "Derived virtual foo()";
        c.foo();
    }
private:
    Component c;
};

int main()
{
    Derived d;
    d.foo();
}