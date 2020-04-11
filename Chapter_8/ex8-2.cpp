// 练习8.2
/* 测试函数，调用参数为cin。*/

#include <iostream>
#include <string>
std::istream& output(std::istream &in)
{
    std::string buf;
    while(in >> buf)
    {
        std::cout << buf << std::endl;
    }
    in.clear();
    return in;
}

int main()
{
    std::istream& in;
    in = output(std::cin);
    std::cout << in.rdstate() << std::endl;
    return 0;
}