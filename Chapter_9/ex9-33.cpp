// 练习9.33
/* 在本节最后一个例子中，如果不将insert的结果赋予`begin`，将会发生什么？
编写程序，去掉此赋值语句，验证你的答案。*/

// begin将会失效。

```cpp
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int main()
{
    vector<int> data { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    for(auto cur = data.begin(); cur != data.end(); ++cur)
        if(*cur & 0x1)
            cur = data.insert(cur, *cur), ++cur;
    
    for (auto i : data)
        cout << i << " ";

    return 0;
}