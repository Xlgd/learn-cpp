/*
以下标记*处会调用析构函数
bool fcn(const Sales_data *trans, Sales_data accum) {
    Sales_data item1(*trans), item2(accum);
    return item1.isbn() != item2.isbn(); * item1, item2, accum
}
会发生三次析构函数调用。
*/