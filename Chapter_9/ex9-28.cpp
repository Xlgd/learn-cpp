// 练习9.28
/* 编写函数，接受一个forward_list<string>和两个string共三个参数。
函数应在链表中查找第一个string，并将第二个string插入到紧接着第一个string之后的位置。
若第一个string未在链表中，则将第二个string插入到链表末尾。*/

/*
void find_and_insert(forward_list<string>& flst, const string& s1, const string& s2)
{
	auto prev = flst.before_begin();
	auto curr = flst.begin();
	while (curr != flst.end())
	{
		if (*curr == s1)
		{
			flst.insert_after(curr, s2);
			return;
	    }
	    prev = curr;
	    ++curr;
    }
    flst.insert_after(prev, s2);
}
*/