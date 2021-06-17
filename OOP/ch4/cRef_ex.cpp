#include <string>
#include <iostream>
using std::string;
using std::cout;

class CRef{
public:
    CRef(){count++;}
    static void print(const string &str = "") {
        cout << str << " Object Count is ";
        cout << count << "\n";
    }
    ~CRef() {
        count--;
        print("~CRef");
    }
private:
    static int count;
};

int CRef::count = 0;
CRef cp(CRef X) {
    X.print("X arguments in cp");
    return X;
}

int main()
{
    CRef r;
    CRef::print("constructor r");
    CRef r2 = cp(r);
    CRef::print("after calling cp");

// output:
    // constructor r Object Count is 1
    // X arguments in cp Object Count is 1
    // ~CRef Object Count is 0
    // after calling cp Object Count is 0
    // ~CRef Object Count is -1
    // ~CRef Object Count is -2
}