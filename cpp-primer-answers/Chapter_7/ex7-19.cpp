// 练习7.19
/*在你的Person类中，你将把哪些成员声明成public的？
哪些声明成private的？
解释你这样做的原因。
*/

/*
构造函数、getName()、getAddress()函数将设为public。
name和 address 将设为private。
函数是暴露给外部的接口，因此要设为public；
而数据则应该隐藏让外部不可见。
*/