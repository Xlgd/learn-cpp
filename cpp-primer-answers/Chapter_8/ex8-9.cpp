// 练习8.9
/* 使用你为8.1.2节第一个练习所编写的函数打印一个istringstream对象的内容。*/

#include <iostream>
#include <sstream>
using std::istream;

istream& func(istream &is)
{
    std::string buf;
    while (is >> buf)
        std::cout << buf << std::endl;
    is.clear();
    return is;
}

int main()
{
    std::istringstream iss("hello");
    func(iss);
    return 0;
}