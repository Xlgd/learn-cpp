// 练习2.38
/* 说明由decltype 指定类型和由auto指定类型有何区别。
请举一个例子，decltype指定的类型与auto指定的类型一样；
再举一个例子，decltype指定的类型与auto指定的类型不一样。 */

//decltype 会处理顶层const和引用的方式与auto不同

int i = 0, &r = i;
//相同
auto a = i;
decltype(i) b = i;

//不同，d是一个int&
auto c = r;
decltype(r) d = r;