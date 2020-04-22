// 练习9.50
/* 编写程序处理一个vector<string>，其元素都表示整型值。
计算vector中所有元素之和。修改程序，使之计算表示浮点值的string之和。*/

#include <iostream>
#include <string>
#include <vector>

auto sum_for_int(std::vector<std::string> const& v)
{
    int sum = 0;
    for (auto const& s : v)
        sum += std::stoi(s);
    return sum;
}

auto sum_for_float(std::vector<std::string> const& v)
{
    float sum = 0.0;
    for (auto const& s : v)
        sum += std::stof(s);
    return sum;
}

int main()
{
    std::vector<std::string> v = { "1", "2", "3", "4.5" };
    std::cout << sum_for_int(v) << std::endl;
    std::cout << sum_for_float(v) << std::endl;

    return 0;
}