// 练习3.25
/* 3.3.3节划分分数段的程序是使用下标运算符实现的，请利用迭代器改写该程序实现完全相同的功能。
 */

# include <iostream>
# include <vector>
using namespace std;

int main()
{
    vector<unsigned> scores(11, 0);
    unsigned grade;
    auto it = scores.begin();
    while (cin >> grade)
    {
        if (grade <= 100)
        {
            *(it + grade / 10) += 1;
        }
    }

    for (auto s : scores)
    {
        cout << s << " ";
    }
    cout << endl;
    return 0;

}
