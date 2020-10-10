// 练习3.24
/* 请使用迭代器重做3.3.3节的最后一个练习。 */

# include <iostream>
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
    for (auto it = ivec.begin(); it != ivec.end() - 1; ++it)
    {
        cout << *it + *(it + 1) << " ";
    }
    cout << endl;
    auto it1 = ivec.begin();
    auto it2 = ivec.end() - 1;
    while (it1 < it2)
    {
        cout << *it1 + *it2 << " ";
        ++it1;
        --it2;
    }
    cout << endl;
    return 0;

}
