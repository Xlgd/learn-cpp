// 练习3.7
/* 就上一题完成的程序而言，如果将循环控制的变量设置为char将发生什么？
先估计一下结果，然后实际编程进行验证。 */

# include <iostream>
# include <string>

int main()
{
    std::string s;
    std::cin >> s;

    for (char &c : s)
    {
        c = 'X';
    }
    std::cout << s << std::endl;
    return 0;
    return 0;
}
// 没有改变