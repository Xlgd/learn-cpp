#include <iostream>
#include "mystring.h"
using namespace std;

int main()
{
	MyString testS("hello");
	MyString testS2;
	if (testS == testS2) {
		cout << "true";
	}
	else {
		cout << "false";
	}
	cout << endl;

	testS2 = "world";
	testS += testS2;
	cout << testS << endl;
	cout << "testS size: " << testS.size() << endl;
	
	for (auto i = testS.begin(); i != testS.end(); ++i) {
		cout << *i << " ";
	}
	cout << endl;

	for (int i = 0; i < testS.size(); ++i) {
		cout << testS[i] << " ";
	}
	cout << endl;

	testS.insert(5, "world");
	cout << testS << endl;
	return 0;
}