#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    // vector<int> vint{1,2,3,4,5};
    // for_each(vint.begin(), vint.end(), [](const int& elem){
    //     cout << elem << " ";
    // });

    // vector<int> vi;
    // auto it = back_inserter(vi);
    // fill_n(it, 10, 1);

    // vector<int> other;
    // copy(vi.begin(), vi.end(), back_inserter(other));
    // for (auto i : other)
    //     cout << i << endl;
    // int size = 2;
    // auto item = find_if(vi.begin(), vi.end(), [size](const int& a){
    //     return a > size;
    // });
    // if (item != vi.end())
    //     cout << *item;

    size_t v1 = 42;
    auto f = [=, &v1]() -> int { return v1; };
    v1 = 0;
    cout << f();
}