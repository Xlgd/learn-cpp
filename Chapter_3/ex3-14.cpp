// 练习3.14
/* 编写一段程序，
用cin读入一组整数并把它们存入一个vector对象。 */

# include <iostream>
# include <string>
# include <vector>
int main()
{
    std::vector<int> box;
    int i;
    while(std::cin >> i)
    {
        box.push_back(i);
    }
    return 0;
}