// 练习3.31
/*编写一段程序，定义一个含有10个int的数组，令每个元素的值就是其下标值。
 */

# include <iostream>
using namespace std;
int main()
{
    int box[10];
    for (int i = 0; i < 10; ++i)
    {
        box[i] = i;
    }
    for (int i = 0; i < 10; ++i)
    {
        cout << box[i] << " ";
    }
    return 0;
}


