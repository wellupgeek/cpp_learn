#include <list>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

int main()
{
    vector<string> str;
    list<const char *> word{"hello", "world"};
    str.assign(word.begin(), word.end());

    for (auto &i : str) {
        cout << i << endl;
    }
}