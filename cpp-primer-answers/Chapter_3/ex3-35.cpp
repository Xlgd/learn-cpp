// 练习3.35
/*编写一段程序，利用指针将数组中的元素置为0。
 */

# include <iostream>
using namespace std;
int main()
{
    int box[10];
    int* p = box;
    for (int i = 0; i < 10; ++i)
    {
        *p = 0;
        ++p;
    }
    for (int i = 0; i < 10; ++i)
    {
        cout << box[i] << " ";
    }
    return 0;
}