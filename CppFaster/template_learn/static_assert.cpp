#include <iostream>

using namespace std;

template <typename T>
class Test{
public:
    Test() {
        static_assert(sizeof(T) != sizeof(int), "Not int please");
    }
};

int main()
{
    Test<int> d;
    return 0;
}