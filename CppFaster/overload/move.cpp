#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

class A {
public:
    A() {
        cout << "default constructor" << endl; 
        _ptr = NULL; 
    }
    A(const char* source) {
        if (source != NULL) {
            cout << "have param constructor" << endl;
            _ptr = new char[strlen(source)+1];
            strcpy(_ptr, source);
        } 
        else
            _ptr = NULL;
            
    }
    A(const A& a) {
        _ptr = NULL;
        if (a._ptr != NULL) 
        {
            cout << "copy constructor" << endl;
            _ptr = new char[strlen(a._ptr)+1];
            strcpy(_ptr, a._ptr);
        }
    }
    A(A && a) {
        cout << "Move consturcot moves : " << a._ptr << endl;
        if (a._ptr != NULL) {
            _ptr = a._ptr;
            a._ptr = NULL;
        }
    }
    A& operator= (A && a) {
        cout << "Move assignment op. moves : " << a._ptr << endl;
        if (_ptr != NULL && a._ptr != NULL) {
            delete[] _ptr;
            _ptr = a._ptr;
            a._ptr = NULL;
        }
        return *this;
    }
    A& operator= (const A& a) {
        if (_ptr != NULL && a._ptr != NULL) {
            delete[] _ptr;
            cout << "assign operator copy" << endl;
            _ptr = new char[strlen(a._ptr)+1];
            strcpy(_ptr, a._ptr);
        }
        return *this;
    }
    A operator+ (const A& a) {
        cout << "operator + start: " << _ptr << endl;
        A temp;
        temp._ptr = new char[strlen(_ptr)+strlen(a._ptr)+1];
        strcpy(temp._ptr, _ptr);
        strcat(temp._ptr, a._ptr);
        return temp;
    }

    ~A() {
        cout << "A destructor " << endl;
        if (_ptr != NULL)
            delete[] _ptr;
    }
private:
    char* _ptr;
};

int main()
{
    A a("hello"), b("world"), c("china");
    A t = std::move(a+b+c);
    A l = a;
    A p = b;
}