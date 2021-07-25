#include <iostream>
#include "../mini_stl/string.h"
using namespace std;

int main()
{
	ministl::string s1("hello");
	ministl::string s2;		
	ministl::string s3(3, 'a');
	cout << s1 << endl;
	cout << s3 << endl;
	s1 = s3;
	cout << s1 << endl;
	s2 = move(s1);
	cout << s3 << endl;
	return 0;
}