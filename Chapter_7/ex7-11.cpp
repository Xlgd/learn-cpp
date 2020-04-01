// 练习7.11
/*在你的`Sales_data`类中添加构造函数，
然后编写一段程序令其用到每个构造函数。
*/

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


int main()
{
    Sales_data s1;
    print(cout, s1);
    Sales_data s2("0-201-78345-X");
    print(cout, s2);
    Sales_data s3("0-201-78345-X", 3, 20.0);
    print(cout, s3);
    Sales_data s4(cin);
    print(cout, s4);

    return 0;
}