// 练习2.5
/* 指出下述字面值的数据类型并说明每一组内几种字面值的区别 */

/*
(a) 'a', L'a', "a", L"a"

'a': 字符字面值(char)
L'a': 宽字符字面值(wchar_t)
"a": 字符串字面值
L"a": 宽字符串字面值
区别：前两种描述字符，但是占的位数不一样；
后两种描述字符串，占的位数不一样。

(b) 10, 10u, 10L, 10uL, 012, 0xC

10: 十进制整型字面值(int)
10u: 十进制无符号整型字面值(unsigned int)
10L: 十进制长整型字面值(long)
10uL: 无符号长整型字面值 (unsigned long)
012: 八进制整型字面值
0xC: 十六进制整型字面值
区别：无符号表示数据非负，长整型占的位数更多，
八进制和十六进制是另外的表示整数的方式。

(c) 3.14, 3.14f, 3.14L

3.14: 双精度浮点型字面值(double)
3.14f: 单精度浮点型字面值(float)
3.14L: 扩展精度浮点型字面值(long double)
区别：在于占的位数不同

(d) 10, 10u, 10., 10e-2

10: 十进制整型字面值(int)
10u: 十进制无符号整型字面值(unsigned int)
10.: 双精度浮点型字面值(double)
10e-2: 双精度浮点型字面值(double)
区别：前两种在于是否可以表示负数，后两种都是双精度浮点型(double)
*/