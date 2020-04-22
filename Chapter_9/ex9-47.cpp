// 练习9.47
/* 编写程序，首先查找string"ab2c3d7R4E6"中每个数字字符，
然后查找其中每个字母字符。编写两个版本的程序，
第一个要使用find_first_of，第二个要使用find_first_not_of。*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;


int main()
{
    string number("0123456789");
    string s("ab2c3d7R4E6");
    
    for (auto i = 0; (i = s.find_first_of(number, i)) != string::npos; ++i)
    {
        cout << s[i] << " ";
    }

    cout << endl;

    for (auto i = 0; (i = s.find_first_not_of(number, i)) != string::npos; ++i)
    {
        cout << s[i] << " ";
    }
    return 0;
}