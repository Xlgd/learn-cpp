// 练习9.34
/* 假定vi是一个保存int的容器，其中有偶数值也有奇数值，
分析下面循环的行为，然后编写程序验证你的分析是否正确。*/

/*
iter = vi.begin();
while (iter != vi.end())
	if (*iter % 2)
		iter = vi.insert(iter, *iter);
	++iter;
*/

// 循环永远不会结束。因为每次只将iter向前进一步，没有跳过已经判断过的元素，导致if判断都为真