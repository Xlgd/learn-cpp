#include <iostream>
using namespace std;

template <typename T>
class Vector {
public:
    Vector();
    Vector(const Vector<T>& v);
    ~Vector();

    void push_back(const T elem);
    void pop_back();
    unsigned int size() const;
    unsigned int capacity() const;
    bool empty() const;
    void reserve(unsigned int capacity);
    T& front();
    T& back();

    T& operator[] (int index);

    class Iterator {
    public:
        Iterator(Vector<T>* v, int index);
        Iterator& operator++ ();
        T& operator* ();
        bool operator== (const Iterator& rhs) const;
        bool operator!= (const Iterator& rhs) const;

    private:
        Vector<T>* _pVector;
        int _index = -1;
    };
    Iterator begin();
    Iterator end();

private:
    T* _data;
    unsigned int _size;
    unsigned int _capacity;
};

template <typename T>
Vector<T>::Vector() {
    _data = nullptr;
    _size = 0;
    _capacity = 0;
}

template <typename T>
Vector<T>::Vector(const Vector<T>& v) {
    _size = v._size;
    _capacity = v._capacity;
    _data = new T[v._size];
    for (int i = 0; i < v._size; ++i) {
        _data[i] = v._data[i];
    }
}

template <typename T>
Vector<T>::~Vector() {
    _size = 0;
    _capacity = 0;
    delete[] _data;
}

template <typename T>
void Vector<T>::push_back(const T elem) {
    if (_size + 1 == _capacity) {
        reserve(_capacity * 2);
    }
    else if (_capacity == 0) {
        reserve(10);
    }
    _data[_size++] = elem;
}

template <typename T>
void Vector<T>::pop_back() {
    _size--;
}

template <typename T>
unsigned int Vector<T>::size() const{
    return _size;
}

template <typename T>
unsigned int Vector<T>::capacity() const{
    return _capacity;
}

template <typename T>
bool Vector<T>::empty() const {
    return size() == 0;
}

template <typename T>
void Vector<T>::reserve(unsigned int capacity) {
    if (_capacity >= capacity) {
        return;
    }
    T* newBuffer = new T[capacity];
    for (int i = 0; i < _size; i++) {
        newBuffer[i] = _data[i];
    }
    _capacity = capacity;
    delete[] _data;
    _data = nullptr;
    _data = newBuffer;
}

template <typename T>
T& Vector<T>::front() {
    try {
        if (empty()) {
            throw "Vector is empty";
        }  
    }
    catch(...) {
        cout << "Exception occured" << endl;
    }
    return _data[0];
}

template <typename T>
T& Vector<T>::back() {
    try {
        if (empty()) {
            throw "Vector is empty";
        }  
    }
    catch(...) {
        cout << "Exception occured" << endl;
    }
    return _data[_size - 1];
}

template <typename T>
T& Vector<T>::operator[] (int index) {
    try {
        if (index >= _size || index < 0) {
            throw "index is out of range";
        }  
    }
    catch(...) {
        cout << "Exception occured" << endl;
    }
    return _data[index];
}

template <typename T>
Vector<T>::Iterator::Iterator(Vector<T>* v, int index) : _pVector(v), _index(index) {}

template <typename T>
T& Vector<T>::Iterator::operator* () {
    return (*_pVector)[_index];
    // return _pVector->operator[](_index);
}

template <typename T>
typename Vector<T>::Iterator& Vector<T>::Iterator::operator++() {
    ++_index;
    return *this;
}

template <typename T>
bool Vector<T>::Iterator::operator!= (const Vector<T>::Iterator& rhs) const{
    return _index != rhs._index;
}

template <typename T>
bool Vector<T>::Iterator::operator== (const Vector<T>::Iterator& rhs) const{
    return _index == rhs._index;
}

template <typename T>
typename Vector<T>::Iterator Vector<T>::begin()
{
    return Vector<T>::Iterator(this, 0);
}

template <typename T>
typename Vector<T>::Iterator Vector<T>::end()
{
    return Vector<T>::Iterator(this, _size);
}