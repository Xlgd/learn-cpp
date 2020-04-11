// 练习9.6
/* 下面的程序有何错误？你应该如何修改它？*/

/*
list<int> lst1;
list<int>::iterator iter1 = lst1.begin(), iter2 = lst1.end();
while (iter1 < iter2) ...

while的判断条件不正确，改为： while (iter1 != iter2)
*/