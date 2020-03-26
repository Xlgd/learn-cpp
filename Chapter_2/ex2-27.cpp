// 练习2.27
/* 下面的哪些初始化是合法的？请说明原因。 */

/*
(a) int i = -1, &r = 0; 非法，r必须引用一个对象
(b) int *const p2 = &i2; 合法
(c) const int i = -1, &r = 0; 合法
(d) const int *const p3 = &i2; 合法
(e) const int *p1 = &i2; 合法
(f) const int &const r2; 非法，引用没有顶层const
(g) const int i2 = i, &r = i; 合法
*/