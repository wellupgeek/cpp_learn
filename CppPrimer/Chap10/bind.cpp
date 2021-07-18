#include <functional>
#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <list>

using namespace std;
using namespace std::placeholders;

bool check_size(const string& s, string::size_type sz) {
    return s.size() > sz ? true : false;
}

ostream& print(ostream &os, const string& s, char c) {
    os << s << c;
    return os;
}

bool check_size2(int a, const string& s) {
    return a > s.size();
}

int main()
{
    string t = "hello";
    string::size_type sz = 4;
    auto check_sz = bind(check_size, _1, sz);
    cout << check_sz(t);

    vector<string> words = {"hello", "world", "hahaha", "best"};
    auto first = find_if(words.cbegin(), words.cend(), 
                        [=](const string& s){ return s.size() > sz; });
    auto first2 = find_if(words.cbegin(), words.cend(), 
                         bind(check_size, _1, sz));
    char c = ' ';
    for_each(words.cbegin(), words.cend(), 
             [=](const string& s){ cout << s << c; });
    ostream &os = cout;
    for_each(words.cbegin(), words.cend(),
             bind(print, ref(os), _1, c));
    
    vector<int> vec = {1,2,3,4,5,6,7,8,9};
    find_if(vec.cbegin(), vec.cend(), 
            [=](int i){
                return i > t.size();
            });
    find_if(vec.cbegin(), vec.cend(), 
            bind(check_size2, _1, t));
    
    vector<int> dup = {1,1,2,3,4,4,0,0,0,7,3,1};
    list<int> uniq;
    sort(dup.begin(), dup.end());
    unique_copy(dup.cbegin(), dup.cend(), back_inserter(uniq));
    for_each(uniq.cbegin(), uniq.cend(), [](int a){cout << a << ' ';});
    cout << endl;

    vector<int> temp = {1,2,3,4,5,6,7,8,9};
    list<int> lia, lib, lic;
    copy(temp.cbegin(), temp.cend(), back_inserter(lia));
    copy(temp.cbegin(), temp.cend(), inserter(lib, lib.end()));
    copy(temp.cbegin(), temp.cend(), front_inserter(lic));

    for_each(lia.cbegin(), lia.cend(), [](int a){cout << a << ' ';});
    cout << endl;
    for_each(lib.cbegin(), lib.cend(), [](int b){cout << b << ' ';});
    cout << endl;
    for_each(lic.cbegin(), lic.cend(), [](int c){cout << c << ' ';});
}