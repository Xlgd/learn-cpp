// 练习7.49
/* 对于combine函数的三种不同声明，当我们调用i.combine(s)时分别发生什么情况？
其中i是一个Sales_data，而s是一个string对象。*/

/*
(a) Sales_data &combine(Sales_data); 正确
(b) Sales_data &combine(Sales_data&); 错误，隐式转换只能一次
(c) Sales_data &combine(const Sales_data&) const; 错误，函数是const的，与combine的功能冲突
*/