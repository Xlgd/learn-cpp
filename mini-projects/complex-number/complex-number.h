#include <iostream>
using namespace std;

class ComplexNumber {
    friend ostream& operator<<(ostream& os, const ComplexNumber& rhs);
public:
    ComplexNumber(): _real(0), _imaginary(0) {}
    ComplexNumber(float real, float imaginary): _real(real), _imaginary(imaginary) {}
    ComplexNumber(const ComplexNumber& rhs) : _real(rhs._real), _imaginary(rhs._imaginary) {}
    int real() { return _real; }
    int imaginary() { return _imaginary; }
    ComplexNumber& add(const ComplexNumber& rhs);
    ComplexNumber& subtract(const ComplexNumber& rhs);
    ComplexNumber& multiply(const ComplexNumber& rhs);
    ComplexNumber& divide(const ComplexNumber& rhs);
    static void copy(ComplexNumber& tar, const ComplexNumber& src);
    
private:
    float _real;
    float _imaginary;
};
