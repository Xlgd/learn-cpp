// 练习9.45
/* 编写一个函数，接受一个表示名字的string参数和两个分别表示前缀（如"Mr."或"Mrs."）和后缀（如"Jr."或"III"）的字符串。
使用迭代器及insert和append函数将前缀和后缀添加到给定的名字中，将生成的新string返回。*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;


auto add_pre_and_suffix(string name, string const& pre, string const& su)
{
    name.insert(name.begin(), pre.cbegin(), pre.cend());
    return name.append(su);
}

int main()
{
    string name("Wang");
    cout << add_pre_and_suffix(name, "Mr.", ", Jr.") << endl;
    return 0;
}