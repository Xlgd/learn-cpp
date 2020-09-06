#include "complex-number.h"

ComplexNumber& ComplexNumber::
add(const ComplexNumber& rhs) {
    ComplexNumber* temp = new ComplexNumber(0, 0);
    temp->_real = _real + rhs._real;
    temp->_imaginary = _imaginary + rhs._imaginary;
    return *temp;
}

ComplexNumber& ComplexNumber::
subtract(const ComplexNumber& rhs) {
    ComplexNumber* temp = new ComplexNumber(0, 0);
    temp->_real = _real - rhs._real;
    temp->_imaginary = _imaginary - rhs._imaginary;
    return *temp;
}

ComplexNumber& ComplexNumber::
multiply(const ComplexNumber& rhs) {
    ComplexNumber* temp = new ComplexNumber(0, 0);
    temp->_real = _real * rhs._real - _imaginary * rhs._imaginary;
    temp->_imaginary = _real * rhs._imaginary + _imaginary * rhs._real;
    return *temp;
}

ComplexNumber& ComplexNumber::
divide(const ComplexNumber& rhs) {
    ComplexNumber* temp = new ComplexNumber(0, 0);
    int denominator = rhs._real * rhs._real + rhs._imaginary * rhs._imaginary;
    try {
        if (denominator == 0) {
            throw "denominator is zero";
        }
        temp->_real = ((_real * rhs._real) + (_imaginary * rhs._imaginary)) / denominator;
        temp->_imaginary = ((_imaginary * rhs._real) - (_real * rhs._imaginary)) / denominator;
    }
    catch (...) {
        cout << "Exception occured" << endl;
    }
    return *temp;   
}

ostream& operator<<(ostream& os, const ComplexNumber& rhs) {
    if (rhs._imaginary < 0) {
        os << rhs._real << rhs._imaginary << "i" << endl;
    }
    else {
        os << rhs._real << "+" << rhs._imaginary << "i" << endl;
    }
    
    return os;
}