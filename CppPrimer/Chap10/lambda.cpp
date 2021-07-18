#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

void elimDups(vector<string> &words) 
{
    sort(words.begin(), words.end());
    auto end_unique = unique(words.begin(), words.end());
    words.erase(end_unique, words.end());
}

void biggies(vector<string> &words, vector<string>::size_type sz)
{
    // 去重
    elimDups(words);
    // 按长度排序
    stable_sort(words.begin(), words.end(), 
                [](const string& s1, const string &s2)
                  { return s1.size() < s2.size(); });
    // 找到第一个满足size() >= sz的元素的迭代器
    auto first = find_if(words.begin(), words.end(), 
                         [sz](const string &s)
                            { return s.size() >= sz; });
    // 计算满足size() >= sz的元素个数
    auto num = words.end() - first;
    cout << num << endl;
    // 打印
    for_each(words.begin(), words.end(), 
             [](const string& s)
                { cout << s << " "; });
    cout << endl;
}

int main()
{
    // vector<string> vec = {"hello", "world", "i", "am", "best"};
    // string split = " ";
    // for_each(vec.begin(), vec.end(), 
    //          [split](string& str){ str += split; cout << str; });
    // cout << endl;

    auto sum = [](int a, int b){return a + b;};
    cout << sum(1, 2) << endl;
    int t = 4;
    auto sum2 = [t](int a) { return t + a; };
    cout << sum2(6) << endl;

    size_t v1 = 42;
    // auto f = [v1]() mutable{ return ++v1; };
    auto f = [&v1] {return ++v1;};
    v1 = 1;
    cout << f() << endl;

    vector<int> vec = {1,2,3,4,5,6,7,8,9};
    transform(vec.begin(), vec.end(), vec.begin(), 
              [](int i) -> int
              { if (i > 0) return -i; else return i; });
    for_each(vec.cbegin(), vec.cend(), [](int i) { cout << i << " "; });
    cout << endl;

    int i = 10;
    auto f2 = [&]() -> bool 
    { 
        if (i > 0){
            --i;
            return true;
        } else {
            return false;
        }
    };
    for (int j = 0; j < 11; j++) {
        cout << f2() << " " << i << endl;
    }
}