#include <set>
#include <iostream>
using namespace std;

template <typename T>
struct SortDescending{
    bool operator() (const T& a, const T& b){
        return a < b;
    }
};

int main()
{
    set<int, SortDescending<int>> sint{6,3,2,5,1,9};
    multiset<int> mset(sint.begin(), sint.end());
    set<int> ss{100,200};
    mset.insert(-1);
    mset.insert(ss.begin(), ss.end());
    for (auto i : mset) {
        cout << i << endl;
    }
    cout << mset.count(100) << endl;
    auto elem = mset.find(100);
    if (elem != mset.end())
        cout << *elem << endl;
    // int a = 2, b = 5;
    // SortDescending<int> s;
    // bool flag = s(a, b);
    // cout << flag << endl;
}