// 练习10.1
/* 头文件algorithm中定义了一个名为count的函数，它类似find， 接受一对迭代器和一个值作为参数。
count返回给定值在序列中出现的次数。编写程序，读取int序列存入vector中，打印有多少个元素的值等于给定值。*/

#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::vector<int> box = { 1, 2, 1, 2, 3, 4 };

    std::cout << "There are " << std::count(box.cbegin(), box.cend(), 1) << " 1 in the box";
    return 0;
}