// 练习9.20
/* 编写程序，从一个list<int>拷贝元素到两个deque中。
值为偶数的所有元素都拷贝到一个deque中，
而奇数值元素都拷贝到另一个deque中。*/

#include <iostream>
#include <deque>
#include <list>
using std::deque; using std::list; using std::cout; using std::cin; using std::endl;

int main()
{
    list<int> l{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    deque<int> odd, even;
    for (auto i : l)
        (i & 0x1 ? odd : even).push_back(i);

    for (auto i : odd) cout << i << " ";
    cout << endl;
    for (auto i : even)cout << i << " ";
    cout << endl;

    return 0;
}