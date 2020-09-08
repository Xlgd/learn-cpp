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