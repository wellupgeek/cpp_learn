#ifndef __MYSTRING__
#define __MYSTRING__

#include <iostream>
#include <string.h>

class String;

class String{
public:
    String(const char* t = 0);
    String(const String&);
    String& operator=(const char*);
    String& operator=(const String&);
    char* getData() const { return m_data; }
    void setData(const char*);
    ~String() { delete[] m_data; }
private:
    char* m_data;
    friend String& assign(String&, const String&);
    friend String& __doapls(String&, const String&);
};

String& operator+=(String&, const String&);
std::ostream& operator << (std::ostream&, const String&);

#endif