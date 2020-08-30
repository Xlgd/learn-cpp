/* 编写名为 compareIsbn 的函数，比较两个 Sales_data 对象的isbn() 成员。
使用这个函数排序一个保存 xSales_data 对象的 vector。*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

inline bool compareIsbn(const Sales_data &sd1, const Sales_data &sd2)
{
    return sd1.isbn().size() < sd2.isbn().size();
}

int main()
{
    Sales_data d1("aa"), d2("aaaa"), d3("aaa"), d4("z"), d5("aaaaz");
    std::vector<Sales_data> v{ d1, d2, d3, d4, d5 };

    // @note   the elements the iterators pointing to
    //         must match the parameters of the predicate.
    std::sort(v.begin(), v.end(), compareIsbn);

    for(const auto &element : v)
        std::cout << element.isbn() << " ";
    std::cout << std::endl;

    return 0;
}