#include <iostream>
#include "complex-number.h"
using namespace std;

int main()
{
	ComplexNumber<int> testN1(3, 2);
	ComplexNumber<int> testN2;
	cout << testN1;
	cout << testN2;

	testN2 = testN1 + 5;
	testN2 = 7 + testN1;
	testN2 = testN1 + testN2;
	testN2 += testN1;
	cout << testN2;
	cout << ComplexNumber<int>(4, 5);
	testN2 += 3;
	cout << testN2;
	testN2 = -testN1;
	cout << testN2;

	cout << (testN2 == testN1) << endl;
	cout << (testN2 != testN1) << endl;
	cout << conj(testN2);

	return 0;
}