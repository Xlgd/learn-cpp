// 练习9.24
/* 编写程序，分别使用at、下标运算符、front 和 begin 提取一个vector中的第一个元素。
在一个空vector上测试你的程序。*/

#include <iostream>
#include <vector>

int main()
{
    std::vector<int> v;
    std::cout << v.at(0);       // terminating with uncaught exception of type std::out_of_range
    std::cout << v[0];          // Segmentation fault: 11
    std::cout << v.front();     // Segmentation fault: 11
    std::cout << *v.begin();    // Segmentation fault: 11
    return 0;
}