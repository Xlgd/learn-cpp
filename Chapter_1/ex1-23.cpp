// 练习1.23
/* 编写程序，读取多条销售记录，并统计每个 ISBN（每本书）有几条销售记录。 */

#include <iostream>
#include "Sales_item.h"

int main()
{
    Sales_item currItem, valItem;
    if (std::cin >> currItem){
        int cnt = 1;
        while (std::cin >> valItem){
            if (valItem.isbn() == currItem.isbn()){
                ++cnt;
            }
            else{
                std::cout << currItem << " occurs " << cnt << " times " << std::endl;
                currItem = valItem;
                cnt = 1;
            }
        }
        std::cout << currItem << " occurs "<< cnt << " times " << std::endl;
    }
    return 0;
}