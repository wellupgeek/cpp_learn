#include <iostream>
using namespace std;

class fish{
    bool isFreshWater;
public:
    fish(bool flag):isFreshWater(flag){ cout << "create fish\n"; }
    void swim() { cout << "swim no param" << endl; }
    void swim(bool flag) { cout << "swim have param" << endl; }
    virtual ~fish(){ cout << "delete fish\n";}
};

class tuna : public fish {
public:
    // using fish::swim;
    tuna(bool flag):fish(flag){ cout << "create tuna\n"; }
    void swim() { cout << "this is tuna swim" << endl; }
    ~tuna(){ cout << "delete tuna\n"; }
};

int main()
{
    tuna* pt = new tuna(true);
    fish* pf = pt;
    tuna* pt2 = dynamic_cast<tuna*>(pf);
    delete pt2;

    return 0;
}