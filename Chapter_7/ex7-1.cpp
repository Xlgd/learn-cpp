// 练习7.1
/*使用2.6.1节定义的`Sales_data`类为1.6节的交易处理程序编写一个新版本。
 */

 # include <iostream>
# include <string>
using namespace std;

struct Sales_data
{
    string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

int main()
{
    Sales_data total;
    if (cin >> total.bookNo >> total.units_sold >> total.revenue)
    {
        Sales_data trans;
        while (cin >> trans.bookNo >> trans.units_sold >> trans.revenue)
        {
            if (total.bookNo == trans.bookNo)
            {
                total.units_sold += trans.units_sold;
                total.revenue += trans.revenue;
            }
            else
            {
                cout << total.bookNo << " " << total.units_sold << " ";
                cout << total.revenue << endl;
                total = trans;
            }
        }
        cout << total.bookNo << " " << total.units_sold << " ";
        cout << total.revenue << endl;
    }
    else
    {
        cerr << "no data" << endl;
        return -1;
    }
    return 0;
}