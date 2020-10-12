#include <iostream>
using namespace std;

class ComplexNumber {
    
public:
    ComplexNumber(): _real(0), _imaginary(0) {}
    ComplexNumber(float real, float imaginary): _real(real), _imaginary(imaginary) {}
    ComplexNumber(const ComplexNumber& rhs) : _real(rhs._real), _imaginary(rhs._imaginary) {}
    inline float real() const{ return _real; }
    inline float imaginary() const{ return _imaginary; }
    static void copy(ComplexNumber& tar, const ComplexNumber& src);
    
    friend ostream& operator<<(ostream& os, const ComplexNumber& rhs);
    friend ComplexNumber operator+(const ComplexNumber& x, const ComplexNumber& y);
    friend ComplexNumber operator-(const ComplexNumber& x, const ComplexNumber& y);
    friend ComplexNumber operator*(const ComplexNumber& x, const ComplexNumber& y);
    friend ComplexNumber operator/(const ComplexNumber& x, const ComplexNumber& y);

private:
    float _real;
    float _imaginary;
};

