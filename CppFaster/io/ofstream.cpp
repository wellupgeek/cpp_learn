#include <fstream>
#include <iostream>

using namespace std;

int main()
{
    ofstream myfile;
    myfile.open("hello.txt", ios_base::out);

    if (myfile.is_open()) {
        myfile << "my first text file!" << endl;
        myfile << "hello file!" << endl;
        myfile.close();
    }

    return 0;
}