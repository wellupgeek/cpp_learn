#include <iostream>

class A{
public:
    static A& getInstance();
    void show() {std::cout << "A is constructor" << '\n';}
private:
    A(){};
    A(const A&);
};

A& A::getInstance() {
    static A a;
    return a;
}

int main()
{
    A::getInstance().show();
}