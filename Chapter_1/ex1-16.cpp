// 练习1.16
/* 编写程序，从cin读取一组数，输出其和。 */

#include <iostream>

int main()
{
    int sum = 0;
    int input = 0;
    
    std::cout << "Enter a set of numbers: " << std::endl;
    while (std::cin >> input)
    {
        sum += input;
    }

    std::cout << "The sum of there integers is: " << sum <<std::endl;

    return 0;
}