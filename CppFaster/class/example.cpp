#include <iostream>
using namespace std;

class base {
protected:
    int x;
public:
    base(int x1) {
        x = x1;
        cout << "base constructor " << x << endl;
    }
};

class base2 : virtual public base{
    int y;
public:
    base2(int y1, int x1) : y(y1), base(x1) {
        cout << "base2 constructor " << y << endl;
    }
};

class base3 : virtual public base{
    int z;
public:
    base3(int z1, int x1) : z(z1), base(x1) {
        cout << "base3 constructor " << z << endl;
    }
};

class derived : public base2, public base3{
    int xyz;
public:
    derived(int xyz1, int x1, int y1, int z1) : xyz(xyz1), base(x1), base2(y1, x1), base3(z1, x1) {
        cout << "derived constructor " << xyz << endl;
    }
};

int main()
{
    derived obj(1,2,3,4);
}