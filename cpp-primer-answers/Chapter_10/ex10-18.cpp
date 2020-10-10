/* 重写 biggies，用 partition 代替 find_if。我们在10.3.1节练习10.13中介绍了 partition 算法。*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include "util.h" // elimDups


using namespace std;


void biggies(vector<string>& words, vector<string>::size_type sz) {
	elimDups(words);

	stable_sort(words.begin(), words.end(), [](const string& a, const string& b)
		{ return a.size() < b.size(); });

	auto it = partition(words.begin(), words.end(), [sz](const string& s) { return s.size() < sz; });
	for_each(it, words.end(), [](const string& s) { cout << s << " "; });
}

int main()
{	
	vector<string> box;
	string item;
	while (getline(cin, item)) {
		box.push_back(item);
	}
	biggies(box, 5);

	return 0;
}