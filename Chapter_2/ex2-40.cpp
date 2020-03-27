// 练习2.40
/* 根据自己的理解写出 Sales_data 类，
最好与书中的例子有所区别。 */

struct Sales_data {
    std::string bookNo;
    std::string bookName;
    unsigned units_sold = 0;
    double revenue = 0.0;
    double price = 0.0;
}