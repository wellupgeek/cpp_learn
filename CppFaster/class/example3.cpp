#include <iostream>
using namespace std;

class A{
public:
    A(){ num = 0; }
    A(int val):num(val){}
    int getVal() const { return num; }
    A operator+ (int num) {
        return A(this->num + num);
    }
    A operator- () {
        return A(-num);
    }
    // A& operator++ () {
    //     num++;
    //     return *this;
    // }
    // A operator++ (int) {
    //     A t = *this;
    //     num++;
    //     return t;
    // }
    friend A operator+ (const A& a, const A& b) {
        return A(a.num + b.num);
    }
    friend A& operator++ (A& a) {
        ++a.num;
        return a;
    }
    friend A operator++ (A& a, int) {
        A b = a;
        a.num++;
        return b;
    }
private:
    int num;
};


// a = 1 + 2;

int main()
{
    A a(2), b(3);
    A c = a++;
    A d = ++b;
    cout << c.getVal() << endl;
    cout << a.getVal() << endl;
    cout << d.getVal() << endl;
}