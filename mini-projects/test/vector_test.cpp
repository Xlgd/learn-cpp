#include <iostream>
#include <string>
#include "../mini_stl/vector.h"
using namespace std;


int main() {
	Vector<int> testVec;
	Vector<string> testVec2;
	cout << "testVec: " << endl;
	cout << "empty: " << testVec.empty() << endl;
	testVec.push_back(1);
	testVec.push_back(2);
	testVec.push_back(3);
	cout << "empty: " << testVec.empty() << endl;
	cout << "size: " << testVec.size() << endl;
	testVec.pop_back();
	cout << "size: " << testVec.size() << endl;
	cout << "front elem: " << testVec.front() << endl;

	cout << "end elem: " << testVec.back() << endl;

	cout << "print the elems: " << endl;
	for (int i = 0; i < testVec.size(); ++i) {
		cout << testVec[i] << " ";
	}
	cout << endl;

	cout << "print the elems using iterator: " << endl;
	for (auto i = testVec.begin(); i != testVec.end(); ++i) {
		cout << *i << " ";
	}
	cout << endl;

	cout << "testVec2: " << endl;
	cout << "empty: " << testVec2.empty() << endl;
	testVec2.push_back("hello");
	testVec2.push_back("world");
	testVec2.push_back("hi");
	cout << "empty: " << testVec2.empty() << endl;
	cout << "size: " << testVec2.size() << endl;
	testVec2.pop_back();
	cout << "size: " << testVec2.size() << endl;
	cout << "front elem: " << testVec2.front() << endl;

	cout << "end elem: " << testVec2.back() << endl;

	cout << "print the elems: " << endl;
	for (int i = 0; i < testVec2.size(); ++i) {
		cout << testVec2[i] << " ";
	}
	cout << endl;

	

	return 0;
}