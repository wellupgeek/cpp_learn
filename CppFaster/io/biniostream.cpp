#include <fstream>
#include <iostream>
#include <string.h>

using namespace std;

struct Human
{
    Human(){}
    Human(const char* Name, int a, const char* dob):age(a) {
        strcpy(name, Name);
        strcpy(DOB, dob);
    }
    char name[30];
    int age;
    char DOB[20];
};


int main()
{
    Human Input("alibaba", 101, "May 1916");
    ofstream fsOut("Human.bin", ios_base::out | ios_base::binary);
    if (fsOut.is_open()) {
        fsOut.write(reinterpret_cast<const char*>(&Input), sizeof(Input));
        fsOut.close();
    }

    ifstream fsIn("Human.bin", ios_base::in | ios_base::binary);
    if (fsIn.is_open()) {
        Human somePerson;
        fsIn.read((char *)(&somePerson), sizeof(somePerson));
        cout << "name : " << somePerson.name << endl;
        cout << "age : " << somePerson.age << endl;
        cout << "DOB : " << somePerson.DOB << endl;
        fsIn.close();
    }
    return 0;
}