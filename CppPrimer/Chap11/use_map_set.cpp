#include <map>
#include <set>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void test()
{
    map<string, size_t> words;
    string name;
    while (cin >> name) {
        for (auto &c : name)
            c = tolower(c);
        name.erase(remove_if(name.begin(), name.end(), [](char c){ return ispunct(c); }), name.end());
        ++words[name];
    }
    for (auto &w : words) {
        cout << w.first << " occurs " << w.second << (w.second > 1 ? "times" : "time") << endl;
    }
}

// bool compareIsbn(const Sales_data& lhs, const Sales_data& rhs) {
//     return lhs.isbn() < rhs.isbn();
// }

// void test1111() {
//     using compare = bool(*)(const Sales_data&, const Sales_data&);
//     multimap<Sales_data, compare> bookstore(compare);
// }

int main()
{
    // map<string, size_t> word_count;
    // set<string> exclude = {"The", "But", "And", "Or", "An", "A",
    //                        "the", "but", "and", "or", "an", "a"};
    // string word;
    // while (cin >> word) {
    //     if (exclude.find(word) == exclude.end())
    //         ++word_count[word];
    // }
    // for (const auto &w : word_count) {
    //     cout << w.first << " occurs: " << 
    //     w.second << (w.second > 1 ? "times" : "time") << endl;
    // }

    // map<string, vector<string>> family;
    // string first, second;
    // int is_continue = 1;
    // while (is_continue){
    //     cout << "input firstname: " << endl;
    //     cin >> first;
    //     cout << "input lastname: " << endl;
    //     cin >> second;
    //     family[first].push_back(second);
    //     cout << "is continue ? 1 yes : 0 no" << endl;
    //     cin >> is_continue;
    // }
    // for (const auto &f : family) {
    //     cout << "firstname : " << f.first << "\n" <<endl;
    //     for (const auto &s : f.second)
    //         cout << "secondname : " << s << " ";
    //     cout << endl;
    // }

    // test();
    // vector<pair<string, int>> vp;
    // int count = 0;
    // string name;
    // while (cin >> name) {
    //     vp.push_back(make_pair(name, count++));
    // }

    // multiset<string> c = {"hello", "world"};
    // vector<string> v = {"hello1", "world1"};
    // copy(v.begin(), v.end(), inserter(c, c.end()));
    // // copy(v.begin(), v.end(), back_inserter(c));
    // copy(c.begin(), c.end(), inserter(v, v.end()));
    // copy(c.begin(), c.end(), back_inserter(v));

    // map<string, int> word_count;
    // string word2;
    // // word_count.insert({word2, 1});
    // // word_count.insert(make_pair(word2, 1));
    // // word_count.insert(pair<string, int>(word2, 1));
    // // word_count.insert(map<string, int>::value_type(word2, 1));

    // while (cin >> word2) {
    //     auto ret = word_count.insert({word2, 1});
    //     // pair<map<string, int>::iterator, bool> temp = word_count.insert(make_pair(word2, 1));
    //     if (!ret.second) {
    //         ++ret.first->second;
    //     }
    // }

    // map<string, vector<int>> msvi;
    // string name;
    // int t;
    // while (cin >> name) {
    //     vector<int> te;
    //     while (cin >> t) {
    //         te.push_back(t);
    //     }
    //     map<string, vector<int>>::value_type mvt = make_pair(name, te);
    //     pair<map<string, vector<int>>::iterator, bool> ret = msvi.insert(mvt);
    // }

    // auto entries = word_count.count("well");
    // auto iter = word_count.find("well");
    // while (entries) {
    //     cout << iter->second << endl;
    //     ++iter;
    //     --entries;
    // }

    // for (auto beg = word_count.lower_bound("well"), end = word_count.upper_bound("well");
    //      beg != end; ++beg) 
    //      cout << beg->second << endl;
    
    // for (auto beg = word_count.equal_range("well"); beg.first != beg.second; ++beg.first)
    //     cout << beg.first->second << endl;

    multimap<string, vector<string>> msvs = {{"wili", {"jojo", "bikili", "the world"}},
                                             {"plimo", {"are you ok", "some of lili"}}};
    auto iter = msvs.find("wili");
    msvs.erase(iter);
    for (auto &m : msvs) {
        cout << m.first << endl;
        for (auto &v : m.second)
            cout << v << endl;
    }
}