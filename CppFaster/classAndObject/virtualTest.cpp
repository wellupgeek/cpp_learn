#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Date {
private:
    int year, month, day;
    string dateInString;
public:
    Date(int y, int m, int d):year(y),month(m),day(d){}
    explicit operator const char*() {
        ostringstream formatedDate;
        formatedDate << year << " / " << month << " / " << day;
        dateInString = formatedDate.str();
        return dateInString.c_str();
    }
    explicit operator int() {
        return year + month + day;
    }
};

int main()
{
    int* p = new int;
    *p = 123;
    cout << *p << endl;
    delete p;
}