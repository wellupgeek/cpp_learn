#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    ifstream myfile;
    myfile.open("hello.txt", ios_base::in);
    if (myfile.is_open()) {
        string fileContents;

        while (myfile.good()) {
            getline(myfile, fileContents);
            cout << fileContents << endl;
        }
        myfile.close();
    } else {
        cout << "open file error" << endl;
    }
    return 0;
}