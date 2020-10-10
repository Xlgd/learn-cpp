/* 使用 lambda 编写你自己版本的 biggies。*/

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

	auto it = find_if(words.begin(), words.end(), [sz](const string& s) { return s.size() >= sz; });

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