// 练习1.10
/* 除了`++`运算符将运算对象的值增加1之外，还有一个递减运算符`--`实现将值减少1.
编写程序与，使用递减运算符在循环中按递减顺序打印出10到0之间的整数。 */

#include <iostream>

int main()
{
    int count = 10;

    while (count >= 0)
    {
        std::cout << count << " ";
        --count;
    }

    return 0;
}