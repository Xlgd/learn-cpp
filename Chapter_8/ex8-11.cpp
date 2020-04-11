// 练习8.11
/* 本节的程序在外层while循环中定义了istringstream对象。
如果record对象定义在循环之外，你需要对程序进行怎样的修改？重写程序，
将record的定义移到while循环之外，验证你设想的修改方法是否正确。*/

// 如果定义在循环外，则每次处理一个人的信息的时候，需要解除之前的绑定，重新绑定到新的信息

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
struct PersonInfo {
    string name;
    vector<string> phones;
};

int main()
{
    string line, word;
    vector<PersonInfo> people;
    istringstream record; // 定义在循环外
    while (getline(cin, line))
    {
        PersonInfo info;
        record.clear(); // 清除绑定
        record.str(line); // 重新绑定
        record >> info.name;
        while (record >> word)
            info.phones.push_back(word);
        people.push_back(info);
    }
    
    for (auto &p : people)
    {
        std::cout << p.name << " ";
        for (auto &s : p.phones)
            std::cout << s << " ";
        std::cout << std::endl;
    }
    
    return 0;
}