#include <iostream>
using namespace std;

class Base {
public:
    virtual void print() { cout << "hello world!" << endl; }
};

class Derived : public Base {
public:
    void print() { cout << "derived class" << endl; }
    void print2() { cout << "are you ok!" << endl; }
};

void display(const Base* base) {
    Base* pCastData = const_cast<Base*>(base);
    const Base* other = const_cast<const Base*>(pCastData);
    pCastData->print();
}

int main()
{
    Base* p;
    Derived* q = dynamic_cast<Derived*>(p);
}