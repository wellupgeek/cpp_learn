#include <string>
#include <iostream>

using std::string;
using std::cout;

enum Type{ptr, num};

struct Entry{
    string name;
    Type ty;
    value v;
    
};

union value{
    int* p;
    int i;
};

void f(Entry *pe) {
    if (pe->ty == num)
        cout << pe->v.i;
    // ...
}