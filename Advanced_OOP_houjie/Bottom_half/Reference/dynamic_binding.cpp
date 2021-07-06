#include <iostream>

class A{
public:
    A(int b = 0):a(b){}
    virtual void vfunc() {
        std::cout << "A vfunc()" << std::endl;
    }
private:
    int a;
};

class B : public A{
public:
    B(int c = 1):A(c){}
    virtual void vfunc() {
        std::cout << "B vfunc()" << std::endl;
    }
};


int main()
{
    B b;
    A a = (A)b;
    a.vfunc();

    A* pa = new B;
    pa->vfunc();

    A* pb = &b;
    pb->vfunc();    // 相当于C语言写法  (* (pb->vptr)[n])(pb)    意思是通过指针pb找到他的虚指针，再找到虚表的第n个当成函数指针去调用pb
}