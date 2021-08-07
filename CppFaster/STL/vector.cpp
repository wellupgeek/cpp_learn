#include <vector>
#include <list>
#include <forward_list>
#include <string>
#include <iostream>

using namespace std;

struct People {
    string name;
    string phone;
    string displayAs;

    People(const string& name, const string& phone) {
        this->name = name;
        this->phone = phone;
        displayAs = (name + " : " + phone);
    }

    bool operator== (const People& pb) const {
        return this->name == pb.name;
    }

    bool operator< (const People& pb) const {
        return this->name < pb.name;
    }

    operator const char* () const {
        return displayAs.c_str();
    }
};

int main()
{
    // vector<int> integers;
    // // integers.insert(integers.begin(), 1);
    // integers.insert(integers.begin(), 2, 1);
    // vector<int> another (6, 30);
    // integers.insert(integers.begin() + 1, another.begin(), another.end());
    // for (auto i : integers)
    //     cout << i << endl;
    // vector<int> ints{50, 1, 987, 1001};
    // auto iter = ints.cbegin();

    // while (iter != ints.end()) {
    //     size_t index = distance(ints.cbegin(), iter);
    //     cout << "index : " << index << " value : " << *iter << '\n';
    //     ++iter;
    // }
    // ints.clear();
    // display(ints);

    // list<int> li{3,1,2,4,6,5};
    // vector<int> vi{6,6,6};
    // li.insert(li.begin(), 1);
    // li.insert(++li.begin(), 2, 3);
    // li.insert(li.end(), vi.begin(), vi.end());

    // for (auto i : li) {
    //     cout << i << endl;
    // }
    // auto iter = li.insert(li.begin(), 1);
    // li.erase(iter);
    // auto iter2 = li.insert(li.begin(), 2, 2);
    // li.erase(iter2, li.end());
    // for (auto i : li) {
    //     cout << i << endl;
    // }
    // li.sort([](const int &a, const int &b){
    //     return a > b;
    // });
    list<People> li = {{"jiji", "bibi"}, {"ahah", "idod"}};
    li.sort();
    for (auto i : li) {
        cout << i << endl;
    }
    forward_list<int> fl{1,2,3,4,5};
    fl.push_front(9);
    // for (auto i : fl) {
    //     cout << i << endl;
    // }
    auto iter = fl.begin();
    fl.erase_after(fl.before_begin());
    for (auto i : fl) {
        cout << i << endl;
    }
    
}