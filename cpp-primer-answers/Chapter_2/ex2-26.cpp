// 练习2.26
/* 下面哪些语句是合法的？如果不合法，请说明为什么？ */

/*
(a) const int buff; 非法，const对象必须初始化
(b) int cnt = 0; 合法
(c) const int sz = cnt; 合法
(d) ++cnt; ++sz; 非法，不能改变const对象的值
*/