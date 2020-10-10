// 练习7.58
/* 下面的静态数据成员的声明和定义有错误吗？请解释原因。*/

//example.h

#include <vector>

class Example {
public:
	static double rate = 6.5;
	static const int vecSize = 20;
	static vector<double> vec(vecSize);
};

//example.c
#include "example.h"
double Example::rate;
vector<double> Example::vec;

/*
rate应该是一个常量表达式。
而类内只能初始化整型类型的静态常量，所以不能在类内初始化vec。
*/

