// 练习3.21
/* 请使用迭代器重做3.3.3节的第一个练习。 */

# include <iostream>
# include <vector>
# include <string>
using namespace std;

void print(vector<int> v)
{
    for (auto it = v.begin(); it != v.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;
}

void print(vector<string> v)
{
    for (auto it = v.begin(); it != v.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> v1;
    vector<int> v2(10);
    vector<int> v3(10, 42);
    vector<int> v4{ 10 };    
    vector<int> v5{ 10, 42 }; 
    vector<string> v6{ 10 };  
    vector<string> v7{ 10, "hi" };

    print(v1);
    print(v2);
    print(v3);
    print(v4);
    print(v5);
    print(v6);
    print(v7);

    return 0;
    
}
