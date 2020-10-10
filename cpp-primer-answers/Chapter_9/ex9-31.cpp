// 练习9.31
/* 第316页中删除偶数值元素并复制奇数值元素的程序不能用于list或forward_list。
为什么？修改程序，使之也能用于这些类型。*/

/*
因为复合赋值语句只能用于string、vector、deque、array，所以要改为：

++iter;
++iter;

如果是forward_list的话，要增加一个首先迭代器prev：


auto prev = flst.before_begin();
//...
curr == flst.insert_after(prev, *curr);
++curr; ++curr;
++prev; ++prev;
*/