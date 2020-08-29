/* 下面程序是否有错误？如果有，请改正：*/

/*
(a) vector<int> vec; list<int> lst; int i;
	while (cin >> i)
		lst.push_back(i);
	copy(lst.cbegin(), lst.cend(), vec.begin());

(b) vector<int> vec;
	vec.reserve(10);
	fill_n(vec.begin(), 10, 0);
*/

// a，会出现错误，copy时必须保证vec的大小至少和lst一样大，可以加上一句 vec.resize(lst.size())。

// b，会出现错误，将 vec.reserve(10) 改为 vec.resize(10)。