#include <string>
using namespace std;

template <typename T>
const T& GetMax(const T& obj1, const T& obj2) {
    return obj1 > obj2 ? obj1 : obj2;
}

template <typename T1, typename T2>
class HoldsPair {
    T1 val1;
    T2 val2;
public:
    HoldsPair(T1 a, T2 b):val1(a), val2(b){}
};

template<>
class HoldsPair<int, int> {
    int val1;
    int val2;
    string name;
public:
    HoldsPair(int a, int b):val1(a), val2(b){}
};

int main()
{
    int a, b;
    GetMax(a, b);

    HoldsPair<int, int> pair(1, 5);
}