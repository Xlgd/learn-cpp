#ifndef __STRING__
#define __STRING__

#include <iostream>
#include <cstring>

namespace ministl {
class string {
 
public:
    string(): _str(nullptr), _size(0) {}
    string(const char* val);
    string(const string& rhs);
    string(int n, char c);
    ~string();

    int size() const;
    bool empty() { return size() == 0; }
    const char* c_str() const;
    void clear();
    void insert(int index, const char* val);
    void insert(int index, const char c);
    void append(const char* val);
    void append(const char c);

    string& operator= (const string& src);
    string& operator= (const char* src);
    string& operator+= (const string& rhs);
    string operator+ (const string& rhs);
    char& operator[] (int index);
    bool operator== (const string& rhs);


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
    int _size;
    int _capacity;
};


string::string(const char* val) {
    if (val == nullptr) {
        _str = new char[1];
        _str[0] = '\0';
    }
    int len = strlen(val);
    _str = new char[len + 1];
    strcpy(_str, val);
}

string::string(const string& rhs) {
    int len = rhs.size();
    _str = new char[len + 1];
    strcpy(_str, rhs._str);
}

string::string(int count, char ch) {
    _str = new char[2 * count];
    for (int i = 0; i < count; ++i) {
        _str[i] = ch;
    }
    _size = count;
    _capacity = 2 * count;
}
string::~string() {
    delete[] _str;
}


int string::size() const {
    return strlen(_str);
}
const char* string::c_str() const {
    return _str;
}
void string::clear() {
    if (!empty()) {
        delete _str;
        _str = nullptr;
        _str = new char[1];
        _str[0] = '\0';
    }
}
void string::insert(int index, const char c) {
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
void string::insert(int index, const char* val) {
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
void string::append(const char* val) {
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
void string::append(const char c) {
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



string& string::operator= (const string& src) {
    if (this != &src) {
        int srcLen = src.size();
        if (size() != srcLen) {
            delete[] _str;
            _str = new char[srcLen + 1];
        }
        std::copy(src._str, src._str + srcLen, _str);
    }
    return *this;
}
string& string::operator= (const char* src) {
    int srcLen = strlen(src);
    if (size() != srcLen) {
        delete _str;
        _str = nullptr;
        _str = new char[srcLen + 1];
    }
    strcpy(_str, src);
    return *this;
}
string& string::operator+= (const string& rhs) {
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
string string::operator+ (const string& rhs) {
    int rhsLen = rhs.size();
    int thisLen = size();
    char* strTemp = new char[rhsLen + thisLen + 1];
    strncpy(strTemp, _str, thisLen);
    strncpy(strTemp + thisLen, rhs._str, rhsLen);
    strTemp[rhsLen + thisLen] = '\0';
    string Temp(strTemp);
    return Temp;
}
bool string::operator== (const string& rhs) {
    return (strcmp(_str, rhs._str) == 0);
}
char& string::operator[] (int index) {
    try {
        if (index > size() - 1 || index < 0) {
            throw "index is out of range";
        }  
    }
    catch(...) {
        std::cout << "Exception occured" << std::endl;
    }
    return _str[index];
}
std::ostream& operator<< (std::ostream& os, const string& val) {
    os << val.c_str();
    return os;
}

} // namespace ministl
#endif