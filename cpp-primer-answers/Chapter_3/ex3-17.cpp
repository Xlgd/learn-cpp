// 练习3.17
/* 从cin读入一组词并把它们存入一个vector对象，然后设法把所有词都改为大写形式。
输出改变后的结果，每个词占一行。 */

# include <iostream>
# include <string>
# include <vector>
using namespace std;
int main()
{
    vector<string> box;
    string word;
    while (cin >> word)
    {
        for (auto &c : word)
        {
            c = toupper(c);
        }
        box.push_back(word);
    }

    for (auto word : box)
    {
        cout << word << " ";
    }
    return 0;
}