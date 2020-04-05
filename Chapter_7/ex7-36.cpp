// 练习7.36
/* 下面的初始值是错误的，请找出问题所在并尝试修改它。*/

/*
struct X {
    X (int i, int j) : base(i), rem(base % j) { }
    int rem, base;
}

rem比base先定义，所以X构造函数中我们用了一个未定义的base来初始化rem，应该改为：

struct X {
	X (int i, int j): base(i), rem(base % j) {}
	int base, rem;
};
*/