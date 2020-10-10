// 练习9.22
/* 假定iv是一个int的vector，下面的程序存在什么错误？你将如何修改？*/

/*
循环不会结束
迭代器可能会失效

要改为下面这样：

while (iter != mid)
{
	if (*iter == some_val)
	{
		iter = v.insert(iter, 2 * some_val);
		++iter;
    }
	++iter;
}
*/