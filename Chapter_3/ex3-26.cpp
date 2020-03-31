// 练习3.26
/*在100页的二分搜索程序中，为什么用的是 `mid = beg + (end - beg) / 2`, 
而非 `mid = (beg + end) / 2 ;` ?3.3.3节划分分数段的程序是使用下标运算符实现的，请利用迭代器改写该程序实现完全相同的功能。
 */

/*
因为两个迭代器相互之间支持的运算只有 `-` ，而没有 `+` 。
但是迭代器和迭代器差值（整数值）之间支持 `+`。
*/