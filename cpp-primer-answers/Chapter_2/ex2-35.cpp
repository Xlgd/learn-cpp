// 练习2.35
/* 判断下列定义推断出的类型是什么，然后编写程序进行验证。 */

const int i = 42;
auto j = i; // int
const auto &k = i; // const int&
auto *p = &i; // const int*
const auto j2 = i, &k2 = i; // j2: const int | k2: const int&