#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

template <typename T>
void FuncDisplayElement (const T& elem) {
    cout << elem << endl;
}

template <typename T>
struct DisplayElement
{
    int count;
    DisplayElement() {
        count = 0;
    }
    void operator() (const T& elem){
        count++;
        cout << elem << endl;
    }
};

template <typename T>
struct IsMultiple
{
    T divisor;
    IsMultiple(const T& x):divisor(x){}
    bool operator() (const T& other) {
        return (other % divisor == 0);
    }
};

template <typename T>
class Multiple{
public:
    T operator() (const T& a, const T& b) const {
        return a * b;
    }
};

class CompareStringNoCase {
public:
    bool operator() (const string& stra, const string& strb) const {
        string strLowCasea;
        strLowCasea.resize(stra.size());
        string strLowCaseb;
        strLowCaseb.resize(strb.size());

        transform(stra.begin(), stra.end(), strLowCasea.begin(), ::tolower);
        transform(strb.begin(), strb.end(), strLowCaseb.begin(), ::tolower);

        return (strLowCasea < strLowCaseb);
    }
};

int main()
{
    // vector<int> vint{8,1,23,4,2,9,1,3,2,4};
    // // DisplayElement<int> result;
    // // result = for_each(vint.begin(), vint.end(), DisplayElement<int>());
    // // cout << "-------" << endl;
    // // cout << result.count << endl;

    // int divisor = 4;
    // auto elem = find_if(vint.begin(), vint.end(), IsMultiple<int>(divisor));
    // if (elem != vint.end())
    //     cout << *elem;

    // vector<int> vint = {0,1,2,3,4};
    // vector<int> vint2 = {100,200,300,400,500};
    // vector<int> result;
    // result.resize(vint.size());
    // transform(vint.begin(), vint.end(), vint2.begin(), result.begin(), Multiple<int>());
    // for (auto i : result) {
    //     cout << i << endl;
    // }

    vector<string> vs = {"JOIJD", "jldfai", "dfelk", "Akjkjidf"};
    sort(vs.begin(), vs.end(), CompareStringNoCase());
    for (auto i : vs) {
        cout << i << endl;
    }
}