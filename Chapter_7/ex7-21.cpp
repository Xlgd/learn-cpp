// 练习7.21
/*修改你的Sales_data类使其隐藏实现的细节。
你之前编写的关于Sales_data操作的程序应该继续使用，借助类的新定义重新编译该程序，确保其正常工作。*/

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
    Sales_data(istream&);
    double avg_price() const;
    friend istream& read(istream& in, Sales_data& s);
    friend ostream& print(ostream& out, Sales_data& s);
};

Sales_data::Sales_data(istream& in)
{
    in >> bookNo >> units_sold >> revenue;
}

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