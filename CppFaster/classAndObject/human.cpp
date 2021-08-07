#include <iostream>
using namespace std;

union Simple{
    int num;
    char alphabet;
};

struct ComplexType{
    enum DataType
    {
        Int,
        Char
    }Type;
    union Value
    {
        int num;
        char alphabet;
        Value(){}
        ~Value(){}
    }value;
};

void DisplayComplexType(const ComplexType& obj) {
    switch (obj.Type)
    {
    case ComplexType::Int:
        cout << "Union contain number : " << obj.value.num << endl;
        break;

    case ComplexType::Char:
        cout << "Union contain character : " << obj.value.alphabet;
        break;
    }
}

int main()
{
    Simple u1, u2;
    u1.num = 1232;
    u2.alphabet = 'D';
    cout << sizeof(u1) << endl;
    cout << sizeof(u2) << endl;

    ComplexType myData1, myData2;
    myData1.Type = ComplexType::Int;
    myData1.value.num = 123;

    myData2.Type = ComplexType::Char;
    myData2.value.alphabet = 'D';

    DisplayComplexType(myData1);
    DisplayComplexType(myData2);
}