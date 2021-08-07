#include <iostream>

using namespace std;

class animal;
class fish;

class animal {
private:
    virtual void test();
public:
    virtual void breathe() { cout << "animal breathe" << endl; }
};

class fish : public animal {
public:
    void breathe() { cout << "fish breathe" << endl; }
};

int main() {
    animal* pAn = new fish();
    pAn->breathe();
}