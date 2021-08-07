#include <iostream>
#include <exception>
using namespace std;

double divide(double a, double b) {
    if (b == 0)
        throw "Divided by 0 is a crime";
    return (a/b);
}

int main()
{
    // cout << " input a number you wish to reserve: " << endl;
    // try 
    // {
    //     int input = 0;
    //     cin >> input;

    //     int* numArray = new int[input];
    //     delete[] numArray;
    // }
    // catch (std::bad_alloc& exp) {
    //     cout << "Exception encountered: " << exp.what() << endl;
    //     cout << "Go to end, sorry!" << endl;
    // }
    // catch (...) {
    //     cout << "Exception encountered, sorry!" << endl;
    // }

    try {
        cout << "Result is : " << divide(5, 0);
    } catch (const char* exp) {
        cout << "Excepton: " << exp << endl;
    }
    return 0;
}