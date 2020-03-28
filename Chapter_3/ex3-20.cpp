// 练习3.20
/* 读入一组整数并把他们存入一个vector对象，将每对相邻整数的和输出出来。改写你的程序，这次要求先输出第一个和最后一个元素的和，
接着输出第二个和倒数第二个元素的和，以此类推。 */

# include <iostream>
# include <string>
# include <vector>
using namespace std;
int main()
{
    vector<int> ivec;
    int i;
    while (cin >> i)
    {
        ivec.push_back(i);
    }
    for (vector<int>::size_type i = 0; i != ivec.size() - 1; ++i)
    {
        int sum = ivec[i] + ivec[i + 1];
        cout << sum << " ";
    }
    cout << endl;
    for (vector<int>::size_type i = 0; i != ivec.size() / 2; ++i)
    {
        int j = ivec.size() - 1 - i;
        int sum = ivec[i] + ivec[j];
        cout << sum << " ";
    }
    return 0;
}