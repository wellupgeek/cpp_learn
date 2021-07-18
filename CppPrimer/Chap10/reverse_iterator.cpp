#include <iostream>
#include <vector>
#include <list>
#include <iterator>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> vi{1,2,3,4,5,6,7};
    // for (auto r_iter = vi.crbegin(); r_iter != vi.crend(); ++r_iter)
    //     cout << *r_iter << endl;
    sort(vi.rbegin(), vi.rend(), [](int a, int b){return a < b;});
    for (auto i : vi)
        cout << i << endl;
    string line = "first, middle, last";
    auto comma = find(line.begin(), line.end(), ',');
    cout << string(line.begin(), comma) << endl;
    auto rcomma = find(line.rbegin(), line.rend(), ',');
    cout << string(line.rbegin(), rcomma) << endl;
    cout << string(rcomma.base(), line.end()) << endl;

    list<int> li = {1,235,5,2,5,0, 2,34,5,0,13};
    vector<int> vii = {1,2,3,4,5,6,7,8,8};
    auto rii = find(li.crbegin(), li.crend(), 0);
    cout << *rii << endl;
    list<int> li2;
    copy(vii.begin()+3, vii.begin()+8, front_inserter(li2));
    for_each(li2.begin(), li2.end(), [](int a){ cout << a << " ";});
}