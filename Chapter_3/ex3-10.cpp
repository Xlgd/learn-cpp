// 练习3.10
/* 编写一段程序，读入一个包含标点符号的字符串，
将标点符号去除后输出字符串剩余的部分。 */

# include <iostream>
# include <string>

int main()
{
    std::string s;
    std::string result;
    std::cin >> s;
    for (auto &c : s)
    {
        if (!ispunct(c))
        {
            result += c;
        }
    }
    std::cout << result << std::endl;
    return 0;
}