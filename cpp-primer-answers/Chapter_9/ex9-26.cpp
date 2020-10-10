// 练习9.26
/* 使用下面代码定义的ia，将ia拷贝到一个vector和一个list中。
是用单迭代器版本的erase从list中删除奇数元素，从vector中删除偶数元素。*/

/*
int ia[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89 };

vector<int> vec(ia, end(ia));
list<int> lst(vec.begin(), vec.end());

for (auto it = lst.begin(); it != lst.end(); )
	if (*it & 0x1)
		it = lst.erase(it);
	else 
		++it;

for (auto it = vec.begin(); it != vec.end(); )
	if (!(*it & 0x1))
		it = vec.erase(it);
	else
		++it;	
*/