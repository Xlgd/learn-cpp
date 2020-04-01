// 练习7.3
/*修改7.1.1节的交易处理程序，令其使用这些成员。*/

# include <iostream>
# include <string>
using namespace std;

struct Sales_data {
    std::string isbn() const { return bookNo; };
    Sales_data& combine(const Sales_data&);

    string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

Sales_data& Sales_data::combine(const Sales_data& rhs)
{
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

int main()
{
    Sales_data total;
    if (cin >> total.bookNo >> total.units_sold >> total.revenue)
    {
        Sales_data trans;
        while (cin >> trans.bookNo >> trans.units_sold >> trans.revenue)
        {
            if (total.isbn() == trans.isbn())
            {
                total.combine(trans);
            }
            else
            {
                cout << total.isbn() << " " << total.units_sold << " ";
                cout << total.revenue << endl;
                total = trans;
            }
        }
        cout << total.isbn() << " " << total.units_sold << " ";
        cout << total.revenue << endl;
    }
    else
    {
        cerr << "no data" << endl;
        return -1;
    }
    return 0;
}