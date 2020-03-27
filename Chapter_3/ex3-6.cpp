// 练习3.6
/* 编写一段程序，使用范围for语句将字符串内所有字符用X代替。 */

# include <iostream>
# include <string>

int main()
{
    std::string s;
    std::cin >> s;

    for (auto &c : s)
    {
        c = 'X';
    }
    std::cout << s << std::endl;
    return 0;
}