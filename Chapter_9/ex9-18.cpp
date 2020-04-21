// 练习9.18
/* 编写程序，从标准输入读取string序列，存入一个deque中。
编写一个循环，用迭代器打印deque中的元素。*/

#include <iostream>
#include <string>
#include <deque>

using std::string; using std::deque; using std::cout; using std::cin; using std::endl;

int main()
{
    deque<string> input;
    for (string str; cin >> str; input.push_back(str));
    for (auto iter = input.cbegin(); iter != input.cend(); ++iter)
        cout << *iter << endl;

    return 0;
}