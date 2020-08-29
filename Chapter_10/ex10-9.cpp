/* 实现你自己的elimDups。分别在读取输入后、调用unique后以及调用erase后打印vector的内容。*/

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
int main()
{	
	vector<string> box;
	string item;
	while (getline(cin, item)) {
		box.push_back(item);
	}
	elimDups(box);
	for (auto i : box) {
		cout << i << " ";
	}
}