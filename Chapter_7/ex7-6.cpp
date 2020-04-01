// 练习7.6
/*
对于函数`add`、`read`和`print`，定义你自己的版本。*/

#include <string>
#include <iostream>
using namespace std;

struct Sales_data {
    std::string isbn() const { return bookNo; };
    Sales_data& combine(const Sales_data&);
    
    
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

Sales_data& Sales_data::combine(const Sales_data& rhs)
{
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

Sales_data add (const Sales_data &s1, const Sales_data &s2)
{
    Sales_data sum = s1;
    sum.combine(s2);
    return sum;
}

istream& read(istream &in, Sales_data &s)
{
    double price = 0.0;
    in >> s.bookNo >> s.units_sold >> price;
    s.revenue = s.units_sold * price;
    return in;
}

ostream& print(ostream &out, Sales_data &s)
{
    out << s.isbn() << " " << s.units_sold << s.revenue << endl;
    return out;
}