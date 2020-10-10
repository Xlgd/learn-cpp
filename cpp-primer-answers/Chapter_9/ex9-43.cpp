// 练习9.43
/* 编写一个函数，接受三个string参数是s、oldVal 和newVal。
使用迭代器及insert和erase函数将s中所有oldVal替换为newVal。
测试你的程序，用它替换通用的简写形式，
如，将"tho"替换为"though",将"thru"替换为"through"。*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;


void replaceString(string& s, const string& oldVal, const string& newVal)
{
	for (auto c = s.begin(); c <= s.end() - oldVal.size(); )
	{
		if (oldVal == string{ c, c + oldVal.size() })
		{
			c = s.erase(c, c + oldVal.size());
			c = s.insert(c, newVal.begin(), newVal.end());
			c += newVal.size();
		}
		else
			++c;
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