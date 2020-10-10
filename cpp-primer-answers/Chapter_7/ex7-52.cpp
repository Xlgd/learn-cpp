// 练习7.52
/* 使用2.6.1节的 Sales_data类，解释下面的初始化过程。
如果存在问题，尝试修改它。*/

/*
Sales_data item = {"987-0590353403", 25, 15.99};

Sales_data类不是聚合类，应该修改成如下：

struct Sales_data {
    std::string bookNo;
    unsigned units_sold;
    double revenue;
};
*/