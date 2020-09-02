#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

int main()
{	
	string last;
	string first;
	map<string, set<string> > words;
	
	while (cin >> last) {
		if (last == "Q") {
			break;
		}
		while (cin >> first) {
			if (first == "q") {
				break;
			}
			words[last].insert(first);
		}
	}

	set<string> lastName;
	for (auto it = words.begin(); it != words.end(); it++) {
		lastName.insert(it->first);
		
	}

	string search;
	cout << "input the LastName to search: ";
	while (cin >> search) {
		if (search == "q") {
			break;
		}
		if (lastName.count(search)) {
			auto itset = words[search].begin();
			for (; itset != words[search].end(); itset++) {
				cout << *itset << " ";
			}
			cout << endl;
		}
	}
	return 0;
}