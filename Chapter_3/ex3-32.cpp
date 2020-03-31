// 练习3.32
/*将上一题刚刚创建的数组拷贝给另一数组。
利用vector重写程序，实现类似的功能。
 */

# include <iostream>
# include <vector>
using namespace std;
int main()
{
    int box[10];
    int box2[10];
    for (int i = 0; i < 10; ++i)
    {
        box[i] = i;
        box2[i] = box[i];
    }
    for (int i = 0; i < 10; ++i)
    {
        cout << box2[i] << " ";
    }
    cout << endl;

    vector<int> ivec, ivec2;
    for (int i = 0; i < 10; ++i)
    {
        ivec.push_back(i);
    }
    for (int i = 0; i < 10; ++i)
    {
        ivec2.push_back(ivec[i]);
    }
    for (auto i : ivec2)
    {
        cout << i << " ";
    }
    return 0;
}