#include <iostream>
#include "../mini_stl/string.h"
using namespace std;

int main()
{
	ministl::string s1("hello");
	ministl::string s2;		
	cout << s2.empty() << endl;
	ministl::string s3(3, 'a');
	cout << s1 << endl;
	cout << s3 << endl;
	s1 = s3;
	cout << s1 << endl;
	s2 = move(s1);
	cout << s2 << endl;
	ministl::string s4(s2, 1, 2);
	ministl::string s5(s2, 1, 1);
	cout << s4 << " " << s5 << endl;

	s4 = "hello";
	cout << s4 << endl;
	cout << s4.size() << " " << s4.length() << " " << s4.empty() <<endl;

	s4.clear();
	cout << s4 << " " << s4.size() << " " << s4.empty() << endl;
	return 0;
}