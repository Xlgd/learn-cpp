#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;


bool isShorter(string& s1, string& s2) {
	return s1.size() < s2.size();
}

int main()
{	
	string word;
	vector<string> words;
	while (cin >> word) {
		words.push_back(word);
	}
	sort(words.begin(), words.end(), isShorter);
	for (auto w : words) {
		cout << w << " ";
	}

	return 0;
}