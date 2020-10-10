// 练习9.46
/* 重写上一题的函数，这次使用位置和长度来管理string，并只使用insert。*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;


auto add_pre_and_suffix(string name, string const& pre, string const& su)
{
    name.insert(0, pre);
    name.insert(name.size(), su);
    return name;
}

int main()
{
    string name("Wang");
    cout << add_pre_and_suffix(name, "Mr.", ", Jr.") << endl;
    return 0;
}