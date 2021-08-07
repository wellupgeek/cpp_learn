#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>
#include <string>
// #include <stdlib.h>

using namespace std;
using namespace std::placeholders;

bool check_size(const int elem, string::size_type sz) {
    return elem >= sz;
}

bool isShorter(const string&a ,const string& b) {
    return a.size() < b.size();
}

ostream& print(ostream& os, const string& str, char c) {
    os << str << c;
    return os;
}

int main()
{
    // string::size_type sz = 6;
    // vector<int> vint{1,9,2,4,0,12};
    // auto item = find_if(vint.begin(), vint.end(), bind(check_size, _1, sz));
    // if (item != vint.end())
    //     cout << *item;
    vector<string> hello{"z", "yc", "ghf", "ahij"};
    sort(hello.begin(), hello.end(), bind(isShorter, _2, _1));
    for_each(hello.begin(), hello.end(), bind(print, ref(cout), _1, ' '));
    for (auto i : hello) {
    //     cout << i << endl;
    // }
}