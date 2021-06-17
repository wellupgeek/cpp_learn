#include <cstring>
#include <iostream>
using std::cout;

class string{
public:
    string(const char* str);
    ~string();
    string& operator=(const string &rhs);
    void print();
private:
    char *data;
};

string::string(const char* str) {
    data = new char[strlen(str) + 1];
    strcpy(data, str);
}

string::~string() {
    delete []data;
}

string& string::operator=(const string &rhs) {
    char* temp = new char[strlen(rhs.data) + 1];
    strcpy(temp, rhs.data);
    delete []data;
    data = new char[strlen(temp) + 1];
    strcpy(data, temp);
    delete []temp;
    return *this;
}

void string::print() {
    cout << data << '\n';
}

int main()
{
    const char* str = "hello world";
    string a(str);
    a = a;
    a.print();
}