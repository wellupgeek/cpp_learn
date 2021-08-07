#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    const char* a = "hello String!";
    // string f(a);
    string f;
    // cout << f.c_str() << endl;

    // f += "hello";
    // cout << f << endl;

    f.append("world");
    cout << f << endl;

    size_t pos = f.find("world", 0);
    if (pos != string::npos) {
        cout << pos << endl;
    }

    // std::reverse(f.begin(), f.end());
    transform(f.begin(), f.end(), f.begin(), ::toupper);
    cout << f << endl;
}