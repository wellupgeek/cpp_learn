#include <iostream>
#include <numeric>
#include <algorithm>
#include <vector>
#include <string>
#include <list>
#include <iterator>
using namespace std;

int main()
{
    vector<int> a = {1,2,3,4,5};
    auto result = find(a.cbegin(), a.cend(), 3);
    cout << "The value " << (result == a.cend() ? "is not present " : "is present" ) << '\n';

    int ia[] = {1,2,3,3,3,3,4,5,6};
    int val = 4;
    int *result2 = find(begin(ia), end(ia), val);
    cout << *result2 << endl;
    cout << count(ia+1, ia+5, 3) << endl;
    cout << accumulate(begin(ia), end(ia), 0) << endl;

    string str("hello world!!!");
    string temp = accumulate(str.cbegin(), str.cend(), string(""));
    cout << temp << endl;

    vector<double> v = {2.1, 3.1, 4.0};
    cout << accumulate(v.cbegin(), v.cend(), 0) << endl;

    vector<const char*> cc(12, "hello");
    vector<const char*> dd(12, "world");
    cout << equal(cc.cbegin(), cc.cend(), dd.cbegin()) << endl;

    fill(begin(ia), end(ia), 0);

    vector<int> vec;
    // auto it = back_inserter(vec);
    fill_n(back_inserter(vec), 10, 1);

    int ia2[] = {1,2,3,4,5,6,7,8,9};
    int ia3[sizeof(ia2) / sizeof(*ia2)];
    copy(begin(ia2), end(ia2), ia3);
    
    replace(vec.begin(), vec.end(), 1, 32);
    // replace_copy(vec.cbegin(), vec.cend(), back_inserter(ivec), 0, 32);

    vector<int> vit;
    vit.resize(10);
    fill_n(vit.begin(), 10, 1);
    cout << vit.size();
}