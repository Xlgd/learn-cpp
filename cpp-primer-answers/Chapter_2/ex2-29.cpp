// 练习2.29
/* 假设已有上一个练习中定义的那些变量，则下面的哪些语句是合法的？请说明原因。 */

/*
(a) i = ic; 合法，使用const int给int赋值
(b) p1 = p3; 非法，p3是const指针不能赋值给一般指针
(c) p1 = &ic; 非法，p1不是const
(d) p3 = &ic; 合法，常量指针指向常量
(e) p2 = p1; 合法，const指针可以指向int
(f) ic = *p3; 合法，将p3所指的int赋值给ic
*/