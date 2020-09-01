#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int max(int x, int y) {
	return x > y ? x : y;
}

float max(float x, float y) {
	return x > y ? x : y;
}

string max(string x, string y) {
	return x > y ? x : y;
}

int max(vector<int>& vec) {
	if (!vec.empty()) {
		vector<int> temp{ vec };
		sort(temp.begin(), temp.end());
		return temp[temp.size() - 1];
	}
}

float max(vector<float>& vec) {
	if (!vec.empty()) {
		vector<float> temp{ vec };
		sort(temp.begin(), temp.end());
		return temp[temp.size() - 1];
	}
}

string max(vector<string>& vec) {
	if (!vec.empty()) {
		vector<string> temp{ vec };
		sort(temp.begin(), temp.end());
		return temp[temp.size() - 1];
	}
}

int max(int vec[], int size) {
	int maxValue = 0;
	for (int i = 0; i < size; i++) {
		if (vec[i] > maxValue) {
			maxValue = vec[i];
		}
	}
	return maxValue;
}

float max(float vec[], int size) {
	float maxValue = 0;
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
	cout << "max(2, 3): " << max(2, 3) << endl;
	cout << "max(2.0, 3.0): " << max(2.0, 3.0) << endl;
	cout << "max(abc, ade): " << max("abc", "ade") << endl;

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