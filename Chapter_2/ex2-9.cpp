// 练习2.9
/* 解释下列定义的含义，对于非法的定义，请说明错在何处并将其改正。 */

/*
(a) std::cin >> int input_value;
错误，应该先定义再使用

int input_value;
std::cin >> input_value;

从输入中获得一个数，存入input_value中

(b) int i = { 3.14 };
错误，使用列表初始化且初始值存在丢失信息的风险，编译器会报错

double i = { 3.14 };
定义i并将其初始化为3.14

(c) double salary = wage = 9999.99;
错误，不能给没定义的wage赋值

double wage;
double salary = wage = 9999.99;

定义wage和salary并将它们初始化为9999.99

(d) int i = 3.14;
小数部分会被截断，i的值为3
*/