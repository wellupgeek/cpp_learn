#include <sstream>
#include <iostream>

using namespace std;

int main()
{
    int input = 100;
    stringstream convert;
    convert << input;
    string transform;
    convert >> transform;
    cout << transform << endl;

    stringstream other;
    other << transform;
    int t;
    other >> t;
    cout << t << endl;
}