// 练习7.41
/* 使用委托构造函数重新编写你的Sales_data类，给每个构造函数体添加一条语句，令其一旦执行就打印一条信息。用各种可能的方式分别创建`Sales_data`对象，
认真研究每次输出的信息直到你确实理解了委托构造函数的执行顺序。*/

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
    Sales_data() : Sales_data("", 0, 0) { cout << "Sales_data()" << endl; }
    Sales_data(const string& s) : Sales_data(s, 0, 0){ cout << "Sales_data(const string& s)" << endl; }
    Sales_data(const string& s, unsigned n, double p) :
        bookNo(s), units_sold(n), revenue(p* n) {
        cout << "Sales_data(const string& s, unsigned n, double p)" << endl;
    }
    Sales_data(istream&);
    double avg_price() const;
    friend istream& read(istream& in, Sales_data& s);
    friend ostream& print(ostream& out, Sales_data& s);
};

Sales_data::Sales_data(istream& in) : Sales_data()
{
    cout << "Sales_data(istream& in)" << endl;
    read(in, *this);
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
    Sales_data book1;
    Sales_data book2("001");
    Sales_data book3("002", 4, 5);
    Sales_data book4(cin);
    return 0;
}
/*
输出：
Sales_data(const string& s, unsigned n, double p)
Sales_data()
Sales_data(const string& s, unsigned n, double p)
Sales_data(const string& s)
Sales_data(const string& s, unsigned n, double p)
Sales_data(const string& s, unsigned n, double p)
Sales_data()
Sales_data(istream& in)
*/