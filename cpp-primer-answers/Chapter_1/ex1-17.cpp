// 练习1.17
/* 如果输入的所有值都是相等的，本节的程序会输出什么？如果没有重复值，输出又会是怎样的？ */

#include <iostream>

int main()
{
    int currVal = 0, val = 0;

    if (std::cin >> currVal){
        int count = 1;
        while (std::cin >> val){
            if (currVal == val){
                count++;
            }
            else{
                std::cout << "The number: " << currVal;
                std::cout << " occurs " << count << " times.";
                std::cout << std::endl;

                currVal = val;
                count = 1;
            }
        }
        std::cout << "The number: " << currVal;
        std::cout << " occurs " << count << " times.";
        std::cout << std::endl;

    }

    return 0;
}