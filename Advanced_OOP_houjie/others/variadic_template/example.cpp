#include <iostream>
using namespace std;

void print()
{
    cout << "empty function, called last\n";
}

template <typename T, typename ... Types>
void print(T var1, Types ... var2)
{
    cout << var1 << endl;

    print(var2 ...);
}

int main()
{
    print(1, 2, 3.14, "Pass me any"
                      "number of argements",
                      "I will print\n");
    return 0;
}