#include "mystring.h"

MyString::MyString() {
    _str = new char[1];
    _str[0] = '\0';
}

MyString::MyString(const char* val) {
    if (val == nullptr) {
        _str = new char[1];
        _str[0] = '\0';
    }
    int len = strlen(val);
    _str = new char[len + 1];
    strcpy(_str, val);
}

MyString::MyString(const MyString& rhs) {
    int len = rhs.size();
    _str = new char[len + 1];
    strcpy(_str, rhs._str);
}

MyString::MyString(int n, char c) {
    _str = new char[n + 1];
    int i = 0;
    for (;i < n; ++i) {
        _str[i] = c;
    }
    _str[i] = '\0';
}

int MyString::size() const {
    return strlen(_str);
}

MyString::~MyString() {
    delete _str;
}

MyString& MyString::operator= (const MyString& src) {
    if (this != &src) {
        int srcLen = src.size();
        if (size() != srcLen) {
            delete _str;
            _str = nullptr;
            _str = new char[srcLen + 1];
        }
        copy(src._str, src._str + srcLen, _str);
    }
    return *this;
}
MyString& MyString::operator= (const char* src) {
    int srcLen = strlen(src);
    if (size() != srcLen) {
        delete _str;
        _str = nullptr;
        _str = new char[srcLen + 1];
    }
    strcpy(_str, src);
    return *this;
}
MyString MyString::operator+ (const MyString& rhs) {
    int rhsLen = rhs.size();
    int thisLen = size();
    char* strTemp = new char[rhsLen + thisLen + 1];
    strncpy(strTemp, _str, thisLen);
    strncpy(strTemp + thisLen, rhs._str, rhsLen);
    strTemp[rhsLen + thisLen] = '\0';
    MyString Temp(strTemp);
    return Temp;
}
bool MyString::operator== (const MyString& rhs) {
    return (strcmp(_str, rhs._str) == 0);
}

char* MyString::c_str() {
    char* temp = new char[size() + 1];
    strcpy(temp, _str);
    return temp;
}

char& MyString::operator[] (int index) {
    try {
        if (index > size() - 1 || index < 0) {
            throw "index is out of range";
        }  
    }
    catch(...) {
        cout << "Exception occured" << endl;
    }
    return _str[index];
}
ostream& operator<< (ostream& os, const MyString& val) {
    os << val._str;
    return os;
}

void MyString::clear() {
    if (!empty()) {
        delete _str;
        _str = nullptr;
        _str = new char[1];
        _str[0] = '\0';
    }
}