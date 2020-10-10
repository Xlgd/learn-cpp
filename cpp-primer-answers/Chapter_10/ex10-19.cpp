/* 用 stable_partition 重写前一题的程序，与 stable_sort 类似，在划分后的序列中维持原有元素的顺序。*/

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

	auto it = stable_partition(words.begin(), words.end(), [sz](const string& s) { return s.size() < sz; });
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