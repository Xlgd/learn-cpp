// 练习3.15
/* 改写上题程序，不过这次读入的是字符串。 */

# include <iostream>
# include <string>
# include <vector>
int main()
{
    std::vector<std::string> box;
    std::string s;
    while(std::cin >> s)
    {
        box.push_back(s);
    }
    return 0;
}