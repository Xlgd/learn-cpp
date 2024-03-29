#ifndef __COMPLEX_NUMBER__
#define __COMPLEX_NUMBER__

#include <iostream>
#include <cmath>
using namespace std;

template<typename T>
class ComplexNumber { 
public:
    ComplexNumber(): _real(0), _imaginary(0) {}
    ComplexNumber(const T& real, const T& imaginary = 0): _real(real), _imaginary(imaginary) {}
    ComplexNumber(const ComplexNumber<T>& other) : _real(other.real()), _imaginary(other.imaginary()) {}
    ComplexNumber<T>& operator=(const T& x);
    ComplexNumber<T>& operator=(const ComplexNumber<T>& cx);
    T real() const { return _real; }
    void real(T value) { this->_real = value; }
    T imaginary() const{ return _imaginary; }
    void imaginary(T value) { this->_imaginary = value; }
    ComplexNumber<T>& operator+=(const ComplexNumber<T>& other);
    ComplexNumber<T>& operator+=(const T& other);
    ComplexNumber<T>& operator-=(const ComplexNumber<T>& other);
    ComplexNumber<T>& operator-=(const T& other);
    ComplexNumber<T>& operator*=(const ComplexNumber<T>& other);
    ComplexNumber<T>& operator*=(const T& other);
    ComplexNumber<T>& operator/=(const ComplexNumber<T>& other);
    ComplexNumber<T>& operator/=(const T& other);

private:
    T _real;
    T _imaginary;
};

// Member functions
template<typename T>
ComplexNumber<T>& ComplexNumber<T>::operator=(const T& x) {
    this->_real = x;
    this->_imaginary = 0;
    return *this;
}
template<typename T>
ComplexNumber<T>& ComplexNumber<T>::operator=(const ComplexNumber<T>& cx) {
    this->_real  = cx.real();
    this->_imaginary = cx.imaginary();
    return *this;
}


template<typename T>
ComplexNumber<T>& ComplexNumber<T>::operator+= (const ComplexNumber<T>& other) {
    this->_real += other.real();
    this->_imaginary += other.imaginary();
    return *this;
}
template<typename T>
ComplexNumber<T>& ComplexNumber<T>::operator+= (const T& other) {
    this->_real += other;
    return *this;
}

template<typename T>
ComplexNumber<T>& ComplexNumber<T>::operator-= (const ComplexNumber<T>& other) {
    this->_real -= other.real();
    this->_imaginary -= other.imaginary();
    return *this;
}
template<typename T>
ComplexNumber<T>& ComplexNumber<T>::operator-= (const T& other) {
    this->_real -= other;
    return *this;
}

template<typename T>
ComplexNumber<T>& ComplexNumber<T>::operator*= (const ComplexNumber<T>& other) {
    this->_real = this->real() * other.real() - this->imaginary() * other.imaginary();
    this->_imaginary = this->real() * other.imaginary() + this->imaginary() * other.real();
    return *this;
}
template<typename T>
ComplexNumber<T>& ComplexNumber<T>::operator*= (const T& other) {
    this->_real = this->real() * other;
    this->_imaginary = this->imaginary() * other;
    return *this;
}

template<typename T>
ComplexNumber<T>& ComplexNumber<T>::operator/= (const ComplexNumber<T>& other) {
    T denominator = other.real() * other.real() + other.imaginary() * other.imaginary();
    if (denominator == 0) {
        throw "denominator is zero";
    }
    this->_real = ((this->_real * other.real()) + (this->_imaginary * other.imaginary())) / denominator;
    this->_imaginary = ((this->_imaginary * other.real()) - (this->_real * other.imaginary())) / denominator;
    return *this;
}
template<typename T>
ComplexNumber<T>& ComplexNumber<T>::operator/= (const T& other) {
    this->_real = this->real() / other;
    this->_imaginary = this->imaginary() / other;
    return *this;
}

// Non-member functions
template<typename T>
ComplexNumber<T> operator+ (const ComplexNumber<T> & x) {
    return x;
}
template<typename T>
ComplexNumber<T> operator- (const ComplexNumber<T> & x) {
    return ComplexNumber<T>(-x.real(), -x.imaginary());
}

template<typename T>
ComplexNumber<T> operator+ (const ComplexNumber<T>& x, const ComplexNumber<T>& y){
    return ComplexNumber<T>(x.real() + y.real(), x.imaginary() + y.imaginary());
}
template<typename T>
ComplexNumber<T> operator+ (const ComplexNumber<T>& x, const T& y) {
    return ComplexNumber<T>(x.real() + y, x.imaginary());
}
template<typename T>
ComplexNumber<T> operator+ (const T& x, const ComplexNumber<T> & y) {
    return ComplexNumber<T>(y.real() + x, y.imaginary());
}

 

template<typename T>
ComplexNumber<T> operator- (const ComplexNumber<T>& x, const ComplexNumber<T>& y) {
    return ComplexNumber<T>(x.real() - y.real(), x.imaginary() - y.imaginary());
}
template<typename T>
ComplexNumber<T> operator- (const ComplexNumber<T>& x, const T& y) {
    return ComplexNumber<T>(x.real() - y, x.imaginary());
}
template<typename T>
ComplexNumber<T> operator- (const T& x, const ComplexNumber<T> & y) {
    return ComplexNumber<T>(x - y.real(), 0 - y.imaginary());
}

template<typename T>
ComplexNumber<T> operator* (const ComplexNumber<T>& x, const ComplexNumber<T>& y) { 
    return ComplexNumber<T>(x.real() * y.real() - x.imaginary() * y.imaginary(),
                        x.real() * y.imaginary() + x.imaginary() * y.real());
}
template<typename T>
ComplexNumber<T> operator* (const ComplexNumber<T>& x, const T& y) {
    return ComplexNumber<T>(x.real() * y, x.imaginary() * y);
}
template<typename T>
ComplexNumber<T> operator* (const T& x, const ComplexNumber<T> & y) {
    return ComplexNumber<T>(x * y.real(), x * y.imaginary());
}

template<typename T>
ComplexNumber<T> operator/ (const ComplexNumber<T>& x, const ComplexNumber<T>& y) {
    T y_real = y.real();
    T y_imaginary = y.imaginary();
    T denominator = y_real * y_real + y_imaginary * y_imaginary;
    if (denominator == 0) {
        throw "denominator is zero";
    }
    return ComplexNumber<T>(((x.real() * y_real) + (x.imaginary() * y_imaginary)) / denominator, 
                         ((x.imaginary() * y_real) - (x.real() * y_imaginary)) / denominator);
}
template<typename T>
ComplexNumber<T> operator/ (const ComplexNumber<T>& x, const T& y) {
    return ComplexNumber<T>(x.real() / y, x.imaginary() / y);
}
template<typename T>
ComplexNumber<T> operator/ (const T& x, const ComplexNumber<T> & y) {
    T y_real = y.real();
    T y_imaginary = y.imaginary();
    T denominator = y_real * y_real + y_imaginary * y_imaginary;
    if (denominator == 0) {
        throw "denominator is zero";
    }
    return ComplexNumber<T>(((x * y_real) + (0 * y_imaginary)) / denominator, 
                         ((0 * y_real) - (x * y_imaginary)) / denominator);
}

template<typename T>
bool operator== (const ComplexNumber<T>& x, const ComplexNumber<T>& y) {
    return (x.real() == y.real()) && (x.imaginary() == y.imaginary());
}
template<typename T>
bool operator== (const ComplexNumber<T>& x, const T& y) {
    return (x.real() == y) && (x.imaginary() == 0);
}
template<typename T>
bool operator== (const T& x, const ComplexNumber<T>& y) {
    return (x == y.real()) && (y.imaginary() == 0);
}

template<typename T>
bool operator!= (const ComplexNumber<T>& x, const ComplexNumber<T>& y) {
    return !(x == y);
}
template<typename T>
bool operator!= (const ComplexNumber<T>& x, const T& y) {
    return !(x == y);
}
template<typename T>
bool operator!= (const T& x, const ComplexNumber<T>& y) {
    return !(x == y);
}

template<typename T>
ostream& operator<< (ostream& os, const ComplexNumber<T>& rhs) {
    os << "(" << rhs.real() << "," << rhs.imaginary() << ")";
    return os;
}

template<typename T>
T real(const ComplexNumber<T>& z) {
    return z.real();
}

template<typename T>
T imaginary(const ComplexNumber<T>& z) {
    return z.imaginary();
}

template<typename T>
T abs(const ComplexNumber<T>& z) {
    return sqrt(z.real() * z.real() + z.imaginary() * z.imaginary());
}

template<typename T>
T arg(const ComplexNumber<T>& z) {
    return atan(z.imaginary() / z.real());
}

template<typename T>
T norm(const ComplexNumber<T>& z) {
    return z.real() * z.real() + z.imaginary() * z.imaginary();
}

template<typename T>
ComplexNumber<T> conj(const ComplexNumber<T>& z) {
    return ComplexNumber<T>(z.real(), -z.imaginary());
}

#endif