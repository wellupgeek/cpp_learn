// template <class T>
// void sort(T arr[], int size) {

// }

// template <>
// void sort<char>(char arr[], int size) {

// }

#include <iostream>
using namespace std;

template <typename T>
void fun(T a) {
    cout << "main template func() : " << a << endl;
}

template <>
void fun<int>(int a) {
    cout << "Specialized for int type: " << a << endl;
}

int main()
{
    fun<char>('a');
    fun<int>(10);
    fun<double>(10.234);
}