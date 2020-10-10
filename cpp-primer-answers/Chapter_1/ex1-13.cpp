// 练习1.13
/* 使用for循环重做1.4.1节中的所有练习（练习1.9到1.11）。 */

#include <iostream>

int main()
{
    int sum = 0;

    for (int count = 50; count <= 100; count++)
    {
        sum = sum + count;
    }
    
    std::cout << "The sum is: " << sum << std::endl;

    return 0;
}