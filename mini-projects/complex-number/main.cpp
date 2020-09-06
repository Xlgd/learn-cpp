#include <iostream>
#include "complex-number.h"
using namespace std;

int main()
{
	ComplexNumber testN1(3, 2);
	ComplexNumber testN2(4, -5);
	cout << testN1;
	cout << testN2;

	cout << testN1.add(testN2);
	cout << testN1.subtract(testN2);
	cout << testN1.multiply(testN2);
	cout << testN1.divide(testN2);


	return 0;
}