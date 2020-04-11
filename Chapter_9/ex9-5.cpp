// 练习9.5
/* 重写上一题的函数，返回一个迭代器指向找到的元素。
注意，程序必须处理未找到给定值的情况。*/

#include <vector>
vector<int>::iterator find(vector<int>::iterator begin, vector<int>::iterator end, int key)
{
    while (begin != end)
    {
        if (*begin == key)
            return begin;
        ++begin;
    }
    return end;
}