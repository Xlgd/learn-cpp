# include <vector>
# include <iostream>
# include <string>
# include <algorithm>
# include <iterator>
# include "line-iterator.h"

using namespace std;

int main() {
    vector<char> strtab;
    char c;
    while (cin.get(c)) {
        strtab.push_back(c);
    }

    typedef vector<char>::iterator strtab_iterator;
    vector<pair<strtab_iterator, strtab_iterator> > lines;
    strtab_iterator start = strtab.begin();
    while (start != strtab.end()) {
        strtab_iterator next = find(start, strtab.end(), '\n');
        if (next != strtab.end()) {
            ++next;
        }
        lines.push_back(make_pair(start, next));
        start = next;
    }

    sort(lines.begin(), lines.end(), strtab_cmp());
    for_each(lines.begin(), lines.end(), strtab_print(cout));
    return 0;
}