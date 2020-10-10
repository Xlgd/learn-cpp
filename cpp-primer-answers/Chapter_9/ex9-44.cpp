// 练习9.44
/* 重写上一题的函数，这次使用一个下标和replace。*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;


void replaceString(string& s, const string& oldVal, const string& newVal)
{
	for (size_t i = 0; i <= s.size() - oldVal.size(); )
	{
		if (s[i] == oldVal[0] && s.substr(i, oldVal.size()) == oldVal)
		{
			s.replace(i, oldVal.size(), newVal);
			i += newVal.size();
		}
		else
			++i;
	}
	return;
}
int main()
{
	string s{ "To drive straight thru is a foolish, tho courageous act." };
	replaceString(s, "tho", "though");
	replaceString(s, "thru", "through");
	cout << s << endl;
	return 0;
}