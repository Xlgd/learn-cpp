#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <set>

using namespace std;


int main()
{	
	string word;
	map<string, int> words;
	set<string> exclusive{ "a", "an", "or", "the", "and", "but" };
	while (cin >> word) {
		if (exclusive.count(word)) {
			continue;
		}
		words[word]++;
	}

	map<string, int>::iterator it = words.begin();
	for (; it != words.end(); it++) {
		cout << "key: " << it->first << " "
			<< "value: " << it->second << endl;
	}

	return 0;
}