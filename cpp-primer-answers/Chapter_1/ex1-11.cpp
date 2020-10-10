// 练习1.11
/* 编写程序，提示用户输入两个整数，打印出这两个整数所指定的范围内的所有整数。*/

#include <iostream>

int main()
{
    int low = 0, high = 0;
    int temp1 = 0, temp2 = 0;
    std::cout << "Please input two integers: ";
    std::cin >> temp1 >> temp2;

    if(temp1 > temp2)
    {
        high = temp1;
        low = temp2;
    }
    else
    {
        high = temp2;
        low = temp1;
    }

    for(int i = low; i <= high; i++)
    {
        std::cout << i << " ";
    }

    return 0;
}