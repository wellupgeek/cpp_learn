#include <iostream>
using namespace std;

class A{
public:
    A(int _a = 1, int _b = 2):a(_a), b(_b) {}
private:
    int a, b;
};

class B : public A{
public:
    B(int _a=1, int _b=2, int _c=3):A(_a, _b), c(_c){}
    void show(){ std::cout << c << std::endl; }
private:
    int c;
};

int main()
{
    // B b(3, 2, 1);
    // A a(b);
    // B *p = static_cast<B*>(&a);
    // p->show();
    
    // B *pb = new B();
    // A *pa = dynamic_cast<A*>(pb);
    // B *ans = dynamic_cast<B*>(pa);
    // ans->show();
    // return 0;
}