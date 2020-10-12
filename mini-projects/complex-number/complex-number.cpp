#include "complex-number.h"

ostream& operator<<(ostream& os, const ComplexNumber& rhs) {
    if (rhs._imaginary < 0) {
        os << rhs.real() << rhs.imaginary() << "i" << endl;
    }
    else {
        os << rhs.real() << "+" << rhs.imaginary() << "i" << endl;
    }
    
    return os;
}

void ComplexNumber::copy(ComplexNumber& tar, const ComplexNumber& src) {
    ComplexNumber* temp = new ComplexNumber;
    temp->_real = src.real();
    temp->_imaginary = src.imaginary();
    tar = *temp;
}

ComplexNumber operator+(const ComplexNumber& x, const ComplexNumber& y){
    ComplexNumber* temp = new ComplexNumber();
    temp->_real = x.real() + y.real();
    temp->_imaginary = x.imaginary() + y.imaginary();
    return *temp;
}

ComplexNumber operator-(const ComplexNumber& x, const ComplexNumber& y) {
    ComplexNumber* temp = new ComplexNumber();
    temp->_real = x.real() - y.real();
    temp->_imaginary = x.imaginary() - y.imaginary();
    return *temp;
}

ComplexNumber operator*(const ComplexNumber& x, const ComplexNumber& y) {
    ComplexNumber* temp = new ComplexNumber();
    temp->_real = x.real() * y.real() - x.imaginary() * y.imaginary();
    temp->_imaginary = x.real() * y.imaginary() + x.imaginary() * y.real();
    return *temp;
}

ComplexNumber operator/(const ComplexNumber& x, const ComplexNumber& y) {
    ComplexNumber* temp = new ComplexNumber();
    float y_real = y.real();
    float y_imaginary = y.imaginary();
    float denominator = y_real * y_real + y_imaginary * y_imaginary;
    try {
        if (denominator == 0) {
            throw "denominator is zero";
        }
        temp->_real = ((x.real() * y_real) + (x.imaginary() * y_imaginary)) / denominator;
        temp->_imaginary = ((x.imaginary() * y_real) - (x.real() * y_imaginary)) / denominator;
    }
    catch (...) {
        cout << "Exception occured" << endl;
    }
    return *temp;
}
