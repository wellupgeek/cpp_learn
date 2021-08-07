#include <functional>
#include <cassert>
#include <iostream>
#include <map>
#include <string>

using namespace std;

int add(int a, int b) {
    return a + b;
}

auto mod = [](int a, int b) { return a % b; };

struct devide
{
    int operator() (int a, int b) {
        assert(b != 0);
        return a / b;
    }
};

int main()
{
    function<int(int, int)> f1 = add;
    function<int(int, int)> f2 = devide();
    function<int(int, int)> f3 = [](int a, int b){ return a * b; };

    cout << f1(1, 2) << endl;
    cout << f2(2, 3) << endl;
    cout << f3(3, 3) << endl;

    map<string, function<int(int, int)>> binops = {
        {"+", add},
        {"-", std::minus<int>()},
        {"/", devide()},
        {"*", [](int a, int b){return a*b;}},
        {"%", mod}
    };

    binops["+"](10, 5);
    binops["-"](10, 5);

    // if (typeid(int) == typeid(double))
    //     cout << "True" << endl;
    // cout << "False" << endl;
    cout << typeid(int).name() << endl;
}