#include <iostream>
#include "complex-number.h"
using namespace std;

int main()
{
	ComplexNumber testN1(3, 2);
	ComplexNumber testN2(4, -5);
	cout << testN1;
	cout << testN2;

	cout << testN1 + testN2;
	cout << testN1 - testN2;
	cout << testN1 * testN2;
	cout << testN1 / testN2;

	return 0;
}