#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
using namespace std;

void elimDups(vector<string> &str){
    sort(str.begin(), str.end());
    auto end_unique = unique(str.begin(), str.end());
    str.erase(end_unique, str.end());
}

bool isBigerThanFive(const string& s1) {
    return s1.size() >= 5 ? true : false;
}

int main()
{
    vector<string> str = {"abc", "defgh", "hahaha", "wo"};
    auto end_true = partition(str.begin(), str.end(), isBigerThanFive);
    str.erase(end_true, str.end());
    for (const auto &i : str)
        cout << i << endl;
}