// 练习3.4
/* 编写一段程序读取两个字符串，比较其是否相等并输出结果。如果不相等，输出比较大的那个字符串。改写上述程序，比较输入的两个字符串是否等长，
如果不等长，输出长度较大的那个字符串。 */

# include <iostream>
# include <string>
/*
// 输出较大的string
int main()
{
    std::string s1;
    std::string s2;
    
    std::cin >> s1 >> s2;
    if (s1 == s2)
    {
        std::cout << s1 << std::endl;
    }
    else if (s1 > s2)
    {
        std::cout << s1 << std::endl;
    }
    else
    {
        std::cout << s2 << std::endl;
    }
    return 0;
}
*/
// 输出较长的string
int main()
{
    std::string s1;
    std::string s2;
    
    std::cin >> s1 >> s2;
    if (s1.size() == s2.size())
    {
        std::cout << s1 << std::endl;
    }
    else if (s1.size() > s2.size())
    {
        std::cout << s1 << std::endl;
    }
    else
    {
        std::cout << s2 << std::endl;
    }
    return 0;
}