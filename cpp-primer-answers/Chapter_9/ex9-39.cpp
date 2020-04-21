// 练习9.39
/* 解释下面程序片段做了什么：*/

/*
vector<string> svec;
svec.reserve(1024);
string word;
while (cin >> word)
	svec.push_back(word);
svec.resize(svec.size() + svec.size() / 2);


定义一个vector，为它分配1024个元素的空间。
然后通过一个循环从标准输入中读取字符串并添加到vector当中。
循环结束后，改变vector的容器大小（元素数量）为原来的1.5倍，使用元素的默认初始化值填充。
如果容器的大小超过1024，vector也会重新分配空间以容纳新增的元素。
*/