#include <iostream>
#include "complex-number.h"
using namespace std;

int main()
{
	ComplexNumber<int> testN1(3, 2);
	ComplexNumber<int> testN2;
	ComplexNumber<int> testN3(5);
	cout << testN1;
	cout << testN2;
	cout << testN3;

	testN2 = testN1 + 5;
	testN2 = 7 + testN1;
	testN2 = testN2 - 7;
	testN2 = 10 - testN2;
	testN2 = testN1 + testN2;
	testN2 += testN1;
	testN2 = testN2 * 2;
	testN2 = 1 * testN2;
	cout << testN2;
	cout << ComplexNumber<int>(4, 5);
	testN2 += 3;
	testN2 *= 2;
	testN2 /= 2;
	testN2 -= 3;
	cout << testN2;
	testN2 = -testN1;
	cout << testN2;

	cout << (testN2 == testN1) << endl;
	cout << (testN2 != testN1) << endl;
	cout << conj(testN2);

	testN3 = 10;
	cout << testN3;

	testN3 = testN2;
	cout << testN3;
	testN3.real(1);
	testN3.imaginary(1);
	cout << testN3;
	cout << 2.0f / ComplexNumber<float>(2, 1);
	cout << ComplexNumber<float>(2, 1) / 2.0f;
	return 0;
}