// 练习10.2
/* 重做上一题，但读取 string 序列存入 list */

#include <iostream>
#include <list>
#include <algorithm>
#include <string>


int main()
{
    std::list<std::string> box = {"abc", "abcd", "abc", "aaa"};

    std::cout << "There are " << std::count(box.cbegin(), box.cend(), "abc") << " abc in the box";
    return 0;
}
