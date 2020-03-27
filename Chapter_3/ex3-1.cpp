// 练习3.1
/* 使用恰当的using 声明重做 1.4.1节和2.6.2节的练习。 */

//1.4.1


#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
	int sum = 0;
	for (int val = 1; val <= 10; ++val) sum += val;

	cout << "Sum of 1 to 10 inclusive is " << sum << endl;
	
	return 0;
}
