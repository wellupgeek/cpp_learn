#include <iostream>

class A{
public:
    A(int b = 0):a(b){}
    int test(const A&) const;
    int test(const A);
private:
    int a;
};

int A::test(const A& at) const {
    return a;
}

int A::test(const A at) {
    return a + at.a;
}

int main()
{
    A a(1);
    A b(2);
    int t1 = a.test(b);
    const A c(1);
    int t2 = c.test(b);
    std::cout << "t1 = " << t1 << std::endl;
    std::cout << "t2 = " << t2 << std::endl; 
}