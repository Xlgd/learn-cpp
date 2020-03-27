// 练习3.8
/* 分别用while循环和传统for循环重写第一题的程序，
你觉得哪种形式更好呢？为什么？ */

# include <iostream>
# include <string>

int main()
{
    std::string s;
    std::cin >> s;
    decltype(s.size()) i = 0;
    while (i != s.size())
    {
        s[i] = 'X';
        ++i;
    }
    std::cout << s << std::endl;

    for (decltype(s.size()) i = 0; i != s.size(); ++i)
    {
        s[i] = 'Y';
    }
    std::cout << s << std::endl;
    return 0;
}