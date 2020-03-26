// 练习1.9
/* 编写程序，使用`while`循环将50到100整数相加。 */

#include <iostream>

int main()
{
    int sum = 0;
    int count = 50;
    
    while (count <= 100)
    {
        sum = sum + count;
        count = count + 1;
    }

    std::cout << "The sum is: " << sum << std::endl;

    return 0;
}