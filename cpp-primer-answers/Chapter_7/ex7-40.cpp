// 练习7.40
/* 从下面的抽象概念中选择一个（或者你自己指定一个），思考这样的类需要哪些数据成员，
提供一组合理的构造函数并阐明这样做的原因。*/

#include <iostream>
class Date 
{
    unsigned year;
    unsigned month;
    unsigned day;
public:
    Date(std::istream &in) { in >> year >> month >> day;}
    Date(unsigned y, unsigned m, unsigned d) : year(y), month(m), day(d) { }
}