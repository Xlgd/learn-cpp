/* 用 accumulate求一个 vector<int> 中元素之和。*/

#include <iostream>
#include <vector>
#include <numeric>

int main()
{
    std::vector<int> box = {1, 2, 3, 4, 5, 6};

    std::cout << "The sum is " << std::accumulate(box.cbegin(), box.cend(), 0);
    return 0;
}