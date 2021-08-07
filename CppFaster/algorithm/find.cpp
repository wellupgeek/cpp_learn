#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;

int main()
{
    vector<int> vint{8,2,3,3,3,4,5,1,2};
    // auto elem = find(vint.begin(), vint.end(), 4);
    // auto elem2 = find_if(vint.begin(), vint.end(), [](const int& a){
    //     return a % 2 == 0;
    // });
    // if (elem != vint.end())
    //     cout << *elem << endl;   
    // if (elem2 != vint.end()) {
    //     cout << *elem2 << endl;
    //     cout << distance(vint.begin(), elem2) << endl;
    // }
    // size_t elem = count(vint.begin(), vint.end(), 5);
    // size_t elem2 = count_if(vint.begin(), vint.end(), [](const int& x){
    //     return x % 2 == 0;
    // });
    // cout << elem2;

    // vector<int> other{3,4,1};
    // auto first = search(vint.begin(), vint.end(), other.begin(), other.end());
    // if (first != vint.end())
    //     cout << *first << endl;

    // auto second = search_n(vint.begin(), vint.end(), 3, 3);
    // if (second != vint.end())
    //     cout << distance(vint.begin(), second) << endl;

    vector<int> numsInVec(5,1);
    // fill(numsInVec.begin(), numsInVec.end(), 9);
    // fill_n(numsInVec.begin(), 2, 1);
    // for_each(numsInVec.begin(), numsInVec.end(), [](const int& a){
    //     cout << a << ' ';
    // });
    // cout << endl;

    // vector<int> temp(5, 1);
    // vector<int> result;
    // result.resize(temp.size());
    // transform(numsInVec.begin(), numsInVec.end(), temp.begin(), result.begin(), [](int a, int b){
    //     return a+b;
    // });
    // for (auto i : result) {
    //     cout << i << endl;
    // }

    // vector<int> other(5,2);
    // other.resize(numsInVec.size());
    // copy(numsInVec.begin(), numsInVec.end(), inserter(other, other.begin()));
    // copy_if(numsInVec.begin(), numsInVec.end(), back_inserter(other), [](const int& a){
    //     return a % 2 == 0;
    // });
    // copy_backward(numsInVec.begin(), numsInVec.end(), other.end());
    // auto elem = remove(other.begin(), other.end(), 1);
    // auto elem = remove_if(other.begin(), other.end(), [](const int& a){
    //     return a % 2 == 0;
    // });
    // sort(other.begin(), other.end(), less<int>());
    // auto iter = unique(other.begin(), other.end());
    // other.erase(iter, other.end());
    // // other.erase(elem, other.end());
    // for (auto i : other) {
    //     cout << i << endl;
    // }

    vector<int> other = {8,12,4,1,6,2,9,10,7,91};
    // sort(other.begin(), other.end(), less<int>());
    // auto item = binary_search(other.begin(), other.end(), 6);
    // cout << item << endl;
    // auto item = stable_partition(other.begin(), other.end(), [](const int& a){
    //     return a % 2 == 0;
    // });
    // if (item != other.end())
    //     cout << *item << endl;

    sort(other.begin(), other.end(), less<int>());
    for (auto i : other) {
        cout << i << " ";
    }
    cout << endl;
    auto minPos = lower_bound(other.begin(), other.end(), 6);
    auto maxPos = upper_bound(other.begin(), other.end(), 6);

    cout << *minPos << endl;
    cout << *maxPos << endl;
    // for (auto i : other) {
    //     cout << i << ' ';
    // }
    cout << endl;
}