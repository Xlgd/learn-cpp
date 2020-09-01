#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <iterator>
#include <limits>

using namespace std;


void Pentagonal(vector<int>& vec, int nSize) {
	for (int n = 1; n <= nSize; n++) {
		int Pn = n * (3 * n - 1) / 2;
		if (Pn < numeric_limits<int>::max()) {
			vec.push_back(Pn);
		}
	}
}

void printVec(vector<int>& vec) {
	for (auto n : vec) {
		cout << n << endl;
	}
}

int main()
{	
	vector<int> box;
	Pentagonal(box, 10);
	printVec(box);
	return 0;
}