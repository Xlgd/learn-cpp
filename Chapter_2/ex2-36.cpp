// 练习2.36
/* 关于下面的代码，请指出每一个变量的类型以及程序结束时它们各自的值。 */

int a = 3, b = 4;
decltype(a) c = a;
decltype((b)) d = a;
++c;
++d;

/*
a是int，最终值为4
b是int，最终值为4
c是int，最终值为4
d是int&，最终值为4
*/