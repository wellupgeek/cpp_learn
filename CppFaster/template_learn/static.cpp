#include <iostream>
using namespace std;

template <typename T>
class TestStatic {
public:
    static T val;
};

template <typename T> T TestStatic<T>::val;

template <typename Res, typename Val>
void Sum(Res& result, Val& val) {
    result = result + val;
}

template <typename Res, typename Val, typename... Rest>
void Sum(Res& result, Val first, Rest... rest) {
    cout << sizeof...(rest) << endl;
    result = result + first;
    return Sum(result, rest...);
}

int main()
{
    TestStatic<int>::val = 123;
    TestStatic<double>::val = 465.76;

    TestStatic<int> intInstance;
    TestStatic<double> doubleInstance;

    cout << intInstance.val << endl;
    cout << doubleInstance.val << endl;

    int res;
    Sum(res,2,3,4,5,6,7,7);
    cout << res << endl;
}