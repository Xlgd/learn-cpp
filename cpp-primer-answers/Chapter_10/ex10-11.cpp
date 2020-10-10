/* 编写程序，使用 stable_sort 和 isShorter 将传递给你的 elimDups 版本的 vector 排序。
打印 vector的内容，验证你的程序的正确性。*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

void elimDups(vector<string>& words) {
	sort(words.begin(), words.end());
	auto end_unique = unique(words.begin(), words.end());
	cout << "words data after unique" << endl;
	for (auto i : words) {
		cout << i << " ";
	}
	words.erase(end_unique, words.end());
}

bool isShorter(const string& s1, const string& s2) {
	return s1.size() < s2.size();
}

int main()
{	
	vector<string> box;
	string item;
	while (getline(cin, item)) {
		box.push_back(item);
	}
	elimDups(box);
	stable_sort(box.begin(), box.end(), isShorter);
	for (auto i : box) {
		cout << i << " ";
	}
    return 0;
}