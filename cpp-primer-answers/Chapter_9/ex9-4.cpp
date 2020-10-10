// 练习9.4
/* 编写函数，接受一对指向vector<int>的迭代器和一个int值。
在两个迭代器指定的范围中查找给定的值，返回一个布尔值来指出是否找到。*/

#include <vector>
bool find(vector<int>::iterator begin, vector<int>::iterator end, int key)
{
    while (begin != end)
    {
        if (*begin == key)
            return true;
        begin++;
    }
    return false;
}