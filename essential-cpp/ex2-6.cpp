#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

template <typename T>
T max(T x, T y) {
	return x > y ? x : y;
}

template <typename T>
T max(vector<T>& vec) {
	if (!vec.empty()) {
		vector<T> temp{ vec };
		sort(temp.begin(), temp.end());
		return temp[temp.size() - 1];
	}
}

template <typename T>
T max(T vec[], int size) {
	T maxValue = 0;
	for (int i = 0; i < size; i++) {
		if (vec[i] > maxValue) {
			maxValue = vec[i];
		}
	}
	return maxValue;
}

string max(string vec[], int size) {
	string maxValue = "";
	for (int i = 0; i < size; i++) {
		if (vec[i] > maxValue) {
			maxValue = vec[i];
		}
	}
	return maxValue;
}

int main()
{	

	vector<int> intVec{ 1, 2, 3, 4, 5, 6 };
	vector<float> floatVec{ 1.0, 2.0, 3.0, 4.0, 5.0, 6.0 };
	vector<string> stringVec{ "abc", "ade", "edf", "tyy" };

	cout << "vector<int> max: " << max(intVec) << endl;
	cout << "vector<float> max: " << max(floatVec) << endl;
	cout << "vector<string> max: " << max(stringVec) << endl;

	int intArray[5] = { 1, 2, 3, 4, 5 };
	float floatArray[5] = { 1.0, 2.0, 3.0, 4.0, 5.0 };
	string stringArray[5] = { "abc", "ade", "edf", "tyy", "dfg" };

	cout << "array int max: " << max(intArray, 5) << endl;
	cout << "array float max: " << max(floatArray, 5) << endl;
	cout << "array string max: " << max(stringArray, 5) << endl;

	return 0;
}