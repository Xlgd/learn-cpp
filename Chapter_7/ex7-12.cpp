// 练习7.12
/*把只接受一个`istream`作为参数的构造函数移到类的内部。*/

#include <string>
#include <iostream>
using namespace std;

class Sales_data {
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;

public:
    std::string isbn() const { return bookNo; };
    Sales_data& combine(const Sales_data&);
    Sales_data() = default;
    Sales_data(const string &s) : bookNo(s) { }
    Sales_data(const string& s, unsigned n, double p) :
        bookNo(s), units_sold(n), revenue(p * n) { }
    Sales_data(istream& in) { read(in, *this); }
    double avg_price() const;
    friend istream& read(istream& in, Sales_data& s);
    friend ostream& print(ostream& out, Sales_data& s);
};

Sales_data& Sales_data::combine(const Sales_data& rhs)
{
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

double Sales_data::avg_price() const
{
    return revenue / units_sold;
}

Sales_data add(const Sales_data& s1, const Sales_data& s2)
{
    Sales_data sum = s1;
    sum.combine(s2);
    return sum;
}

istream& read(istream& in, Sales_data& s)
{
    double price = 0.0;
    in >> s.bookNo >> s.units_sold >> price;
    s.revenue = s.units_sold * price;
    return in;
}

ostream& print(ostream& out, Sales_data& s)
{
    out << s.isbn() << " " << s.units_sold << " " << s.revenue << endl;
    return out;
}