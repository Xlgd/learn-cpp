// 练习3.5
/* 编写一段程序从标准输入中读入多个字符串并将他们连接起来，输出连接成的大字符串。然后修改上述程序，
用空格把输入的多个字符串分割开来。 */

# include <iostream>
# include <string>
/*
// 连接string
int main()
{
    std::string s1;
    std::string s2;
    
    std::cin >> s1 >> s2;
    std::cout << s1 + s2 << std::endl;
    
    return 0;
}
*/

// 用空格分隔开string
int main()
{
    std::string s1;
    std::string s2;
    
    std::cin >> s1 >> s2;
    std::cout << s1 + " " + s2 << std::endl;
    
    return 0;
}
