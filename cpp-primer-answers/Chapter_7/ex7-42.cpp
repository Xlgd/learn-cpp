// 练习7.42
/* 对于你在练习7.40中编写的类，确定哪些构造函数可以使用委托。
如果可以的话，编写委托构造函数。
如果不可以，从抽象概念列表中重新选择一个你认为可以使用委托构造函数的，为挑选出的这个概念编写类定义。*/

#include <iostream>
class Date 
{
    unsigned year;
    unsigned month;
    unsigned day;
public:
    Date() : Date(0, 0, 0) { }
    Date(std::istream &in) { in >> year >> month >> day;}
    Date(unsigned y, unsigned m, unsigned d) : year(y), month(m), day(d) { }
}