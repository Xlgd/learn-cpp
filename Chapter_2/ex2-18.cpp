// 练习2.18
/* 编写代码分别改变指针的值以及指针所指对象的值。 */

#include <iostream>

int main()
{
    int i = 0, *p = &i;
    int j = 1, *t = &j;

    std::cout << "i: " << i << std::endl;
    std::cout << "*p: " << *p << std::endl;
    
    *p = j;
    p = t;
    std::cout << "i: " << i << std::endl;
    std::cout << "*p: " << *p << std::endl;
}