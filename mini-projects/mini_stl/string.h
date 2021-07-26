#ifndef __MINI_STRING__
#define __MINI_STRING__

#include <iostream>
#include <cstring>
#include "allocator.h"

namespace ministl {

#define STRING_INIT_SIZE 32

class string {

public:
    typedef ministl::allocator<char>            allocator;
    typedef typename allocator::value_type      value_type;
    typedef typename allocator::size_type       size_type;
    typedef typename allocator::pointer         pointer;
    typedef typename allocator::const_pointer   const_pointer;
    typedef typename allocator::reference       reference;
    typedef typename allocator::const_reference const_reference;
    typedef value_type*                         iterator;

    static const size_type npos = -1;

    string();
    string(const string& val, size_type pos, size_type count = npos);
    string(const_pointer val);
    string(const string& val);
    string(string&& val);
    string(size_type n, value_type ch);
    ~string();

    size_type size() const;
    size_type length() const;
    bool empty() const { return size() == 0; }
    const_pointer c_str() const;
    void clear();
    string& insert(size_type index, const_pointer s);
    void insert(int index, const char c);
    void append(const char* val);
    void append(const char c);

    string& operator=(const string& rhs);
    string& operator=(const_pointer s);
    string& operator=(string&& rhs);
    string& operator=(std::nullptr_t) = delete;
    string& operator+= (const string& rhs);
    string operator+ (const string& rhs);
    char& operator[] (int index);
    bool operator== (const string& rhs);
 
private:
    iterator _str;
    size_type _size;
    size_type _capacity;
};

// constructor, destructor
string::string() {
    _str = allocator::allocate(static_cast<size_type>(STRING_INIT_SIZE));
    std::cout << "allocate " << STRING_INIT_SIZE << std::endl; 
    _size = 0;
    _capacity = STRING_INIT_SIZE;
}

string::string(const string& val, size_type pos, size_type count)
    : _str(nullptr), _size(0), _capacity(0) {
    size_type length = val.size();
    if (count == npos || pos + count >= length) {
        _str = allocator::allocate(length - pos + 1);
        std::cout << "allocate " << length - pos + 1 << std::endl;
        _size = length - pos;
        _capacity = length - pos + 1;
        strcpy(_str, val._str + pos);
    }
    else {
        _str = allocator::allocate(count + 1);
        std::cout << "allocate " << count + 1 << std::endl;
        _size = count;
        _capacity = count + 1;
        strncpy(_str, val._str + pos, count);
        _str[count] = '\0';
    }
}


string::string(const_pointer val): _str(nullptr), _size(0), _capacity(0) {
    size_type length = strlen(val);
    _str = allocator::allocate(length + 1);
    std::cout << "allocate " << length + 1 << std::endl;
    strcpy(_str, val);
    _size = length;
    _capacity = length + 1;
}

string::string(const string& val): _str(nullptr), _size(0), _capacity(0) {
    _str = allocator::allocate(val.size() + 1);
    std::cout << "allocate " << val.size() + 1 << std::endl;
    strcpy(_str, val._str);
    _size = val.size();
    _capacity = val.size() + 1;
}

string::string(string&& val): _str(val._str), _size(val._size), _capacity(val._capacity) {
    val._str = nullptr;
    val._size = 0;
    val._capacity = 0;
}

string::string(size_type count, value_type ch): _str(nullptr), _size(0), _capacity(0){
    _str = allocator::allocate(count + 1);
    std::cout << "allocate " << count + 1 << std::endl;
    int i = 0;
    for (; i < count; ++i) {
        _str[i] = ch;
    }
    _str[i] = '\0';
    _size = count;
    _capacity = count + 1;
}

string::~string() {
    if (_str != nullptr) {
        allocator::deallocate(_str, _capacity);
        std::cout << "deallocate " << _capacity << std::endl;
        _str = nullptr;
        _size = 0;
        _capacity = 0;
    }
}


string::size_type string::size() const {
    return _size;
}
string::size_type string::length() const {
    return this->size();
}

string::const_pointer string::c_str() const {
    return _str;
}
void string::clear() {
    if (!this->empty()) {
        _str[0] = '\0';
        _size = 0;
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
string& string::insert(size_type index, const_pointer s) {
    return *this; 
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



string& string::operator=(const string& rhs) {
    if (this != &rhs) {
        allocator::deallocate(_str, _capacity);
        std::cout << "deallocate " << _capacity << std::endl;
        _str = allocator::allocate(rhs._capacity);
        std::cout << "allocate " << rhs._capacity << std::endl;
        strcpy(_str, rhs._str);
        _size = rhs._size;
        _capacity = rhs._capacity;
    }
    return *this;
}

string& string::operator=(string&& rhs) {
    allocator::deallocate(_str, _capacity);
    std::cout << "deallocate " << _capacity << std::endl;
    _str = rhs._str;
    _size = rhs._size;
    _capacity = rhs._capacity;
    rhs._str = nullptr;
    rhs._size = 0;
    rhs._capacity = 0;
    return *this;
}

string& string::operator=(const_pointer s) {
    allocator::deallocate(_str, _capacity);
    std::cout << "deallocate " << _capacity << std::endl;
    size_type length = strlen(s);
    _str = allocator::allocate(length + 1);
    std::cout << "allocate " << length + 1 << std::endl;
    strcpy(_str, s);
    _size = length;
    _capacity = length + 1;
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