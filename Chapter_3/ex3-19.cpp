// 练习3.19
/* 如果想定义一个含有10个元素的vector对象，所有元素的值都是42，
请例举三种不同的实现方法，哪种方式更好呢？ */

# include <iostream>
# include <string>
# include <vector>
using namespace std;
int main()
{
    vector<int> ivec1(10, 42);
    vector<int> ivec2{42, 42, 42, 42, 42, 42, 42, 42, 42, 42};
    vector<int> ivec3;
    
    for (int i = 0; i < 10; ++i)
	    ivec3.push_back(42);

    return 0;
}