// 练习1.20
/* 在网站http://www.informit.com/title/032174113 上，第1章的代码目录包含了头文件 Sales_item.h。
将它拷贝到你自己的工作目录中。
用它编写一个程序，读取一组书籍销售记录，将每条记录打印到标准输出上。 */

#include <iostream>
#include "Sales_item.h"

int main()
{
    Sales_item item;
    
    while (std::cin >> item){
        std::cout << item << std::endl;
    }

    return 0;
}