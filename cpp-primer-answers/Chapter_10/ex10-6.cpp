/* 编写程序，使用 fill_n 将一个序列中的 int 值都设置为0。*/

#include <iostream>
#include <vector>
#include <numeric>

int main()
{
    std::vector<int> box = {1, 2, 3, 4, 5, 6};
    std::fill_n(box.begin(), box.size(), 0);

    for (auto i : box) {
        std::cout << i << " ";
    }
    return 0;
}