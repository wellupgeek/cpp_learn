#include "myString.h"

String::String(const char* t) {
    if (t) {
        m_data = new char[strlen(t)+1];
        strcpy(m_data, t);
    }
    else {
        m_data = new char[1];
        *m_data = '\0';
    }
}

String::String(const String& s) {
    if (s.m_data) {
        m_data = new char[strlen(s.m_data)+1];
        strcpy(m_data, s.m_data);
    }
    else {
        m_data = new char[1];
        *m_data = '\0';
    }
}

String& String::operator=(const String& rhs) {
    return assign(*this, rhs);
}

String& String::operator=(const char* s) {
    delete m_data;
    m_data = new char[strlen(s)+1];
    strcpy(m_data, s);
    return *this;
}

void String::setData(const char* t) {
    delete[] m_data;
    m_data = new char[strlen(t)+1];
    strcpy(m_data, t);
}

String& assign(String& lhs, const String& rhs) {
    if (rhs.m_data && &lhs != &rhs) {
        lhs.m_data = new char[strlen(rhs.m_data)+1];
        strcpy(lhs.m_data, rhs.m_data);
    }
    return lhs;
}

String& __doapls(String& lhs, const String& rhs) {
    if (rhs.m_data) {
        if (lhs.m_data) {
            char* temp = new char[strlen(lhs.m_data)];
            strcpy(temp, lhs.m_data);
            delete[] lhs.m_data;
            lhs.m_data = new char[strlen(lhs.m_data)+strlen(rhs.m_data)+1];
            strcpy(lhs.m_data, temp);
            strcat(lhs.m_data, rhs.m_data);
        }
        else {
            lhs.m_data = new char[strlen(rhs.m_data)+1];
            strcpy(lhs.m_data, rhs.m_data);
        }
    }
    return lhs;
}

String& operator+=(String& lhs, const String& rhs) {
    return __doapls(lhs, rhs);
}

std::ostream&
operator << (std::ostream& os, const String& str) {
    os << str.getData();
    return os;
}