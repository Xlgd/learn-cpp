#ifndef __MYSTRING__
#define __MYSTRING__

#include <iostream>
#include <cstring>

using namespace std;

class MyString {
    friend ostream& operator<< (ostream& os, const MyString& val);
   
public:
    MyString();
    MyString(const char* val);
    MyString(const MyString& rhs);
    MyString(int n, char c);
    ~MyString();

    int size() const;
    bool empty() { return size() == 0; }
    char* c_str();
    void clear();
    void insert(int index, const char* val);
    void insert(int index, const char c);
    void append(const char* val);
    void append(const char c);

    MyString& operator= (const MyString& src);
    MyString& operator= (const char* src);
    MyString& operator+= (const MyString& rhs);
    MyString operator+ (const MyString& rhs);
    char& operator[] (int index);
    bool operator== (const MyString& rhs);

    class Iterator {
    public:
        Iterator(char* ptr): _ptr(ptr) {};
        Iterator operator++ () {
            Iterator temp = *this;
            _ptr++;
            return temp;
        }
        Iterator operator++ (int) {
            _ptr++;
            return *this;
        }
        char& operator* () { return *_ptr; }
        bool operator== (const Iterator& rhs) { return _ptr == rhs._ptr; }
        bool operator!= (const Iterator& rhs) { return _ptr != rhs._ptr; }

    private:
        char* _ptr;
    };

    Iterator begin() { return Iterator(_str); }
    Iterator end() { return Iterator(_str + size()); }
    
private:
    char* _str;
};

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
MyString::~MyString() {
    delete[] _str;
}


int MyString::size() const {
    return strlen(_str);
}
char* MyString::c_str() {
    char* temp = new char[size() + 1];
    strcpy(temp, _str);
    return temp;
}
void MyString::clear() {
    if (!empty()) {
        delete _str;
        _str = nullptr;
        _str = new char[1];
        _str[0] = '\0';
    }
}
void MyString::insert(int index, const char c) {
    if (index < 0 || index > size()) {
        return ;
    }
    else if (index == size()) {
        append(c);
        return;
    }
    int thisLen =  size();
    char* temp = new char[thisLen + 2];
    strncpy(temp, _str, index);
    temp[index] = c;
    if (index == 0) {
        strncpy(temp + 1, _str, thisLen);
    }
    else {
        strncpy(temp + index + 1, _str + index, thisLen - index);
    }
    temp[thisLen + 1] = '\0';
    delete _str;
    _str = nullptr;
    _str = temp;
}
void MyString::insert(int index, const char* val) {
    if (index < 0 || index > size()) {
        return ;
    }
    else if (index == size()) {
        append(val);
        return;
    }
    int thisLen =  size();
    int valLen = strlen(val);
    char* temp = new char[thisLen + valLen + 1];
    strncpy(temp, _str, index);
    strncpy(temp + index, val, valLen);
    if (index == 0) {
        strncpy(temp + valLen + index, _str, thisLen);
    }
    else {
        strncpy(temp + valLen + index, _str + index, thisLen - index);
    }
    temp[thisLen + valLen] = '\0';
    delete _str;
    _str = nullptr;
    _str = temp;
}
void MyString::append(const char* val) {
    if (val == nullptr) {
        return;
    }
    int thisLen = size();
    int valLen = strlen(val);
    char* temp = new char[thisLen + valLen + 1];
    strncpy(temp, _str, thisLen);
    strncpy(temp + thisLen, val, valLen);
    temp[thisLen + valLen] = '\0';
    delete _str;
    _str = nullptr;
    _str = temp;
}
void MyString::append(const char c) {
    if (c == '\0') {
        return;
    }
    int thisLen = size();
    char* temp = new char[thisLen + 2];
    strncpy(temp, _str, thisLen);
    temp[thisLen] = c;
    temp[thisLen + 1] = '\0';
    delete _str;
    _str = nullptr;
    _str = temp;
}



MyString& MyString::operator= (const MyString& src) {
    if (this != &src) {
        int srcLen = src.size();
        if (size() != srcLen) {
            delete[] _str;
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
MyString& MyString::operator+= (const MyString& rhs) {
    int rhsLen = rhs.size();
    int thisLen = size();
    char* strTemp = new char[rhsLen + thisLen + 1];
    strncpy(strTemp, _str, thisLen);
    strncpy(strTemp + thisLen, rhs._str, rhsLen);
    strTemp[rhsLen + thisLen] = '\0';
    delete _str;
    _str = nullptr;
    _str = strTemp;
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

#endif