#include <iostream>
#include <memory>
#include <string.h>
#include <string>

using namespace std;

class Date {
private:
    int year, month, day;
public:
    Date(int y, int m, int d):year(y), month(m), day(d){}
    void display() {
        cout << year << "/" << month << "/" << day << endl;
    }
};

class Display {
public:
    void operator() (string input) const{
        cout << input << endl;
    }
};

int main()
{
    unique_ptr<int> smartIntPtr(new int);
    *smartIntPtr = 42;
    cout << *smartIntPtr << endl;

    unique_ptr<Date> pDate(new Date(2021,8,5));
    pDate->display();

    const char* q = "hello";
    const char* l = "world";
    char* p = new char[strlen(q)+strlen(l)+1];
    strcpy(p, q);
    strcat(p, l);
    cout << p << endl;

    Display dp;
    dp("you are beautiful");
}