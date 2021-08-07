#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

int main()
{
    vector<int> vit = {1,2,3,4,5,6,7,8,9};
    vector<int>::iterator vfind = find(vit.begin(), vit.end(), 4);
    if (vfind != vit.end()) {
        int n = vfind - vit.begin();
        cout << n << endl;
    }
}