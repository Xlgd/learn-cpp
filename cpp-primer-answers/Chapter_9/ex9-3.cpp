// 练习9.3
/* 构成迭代器范围的迭代器有何限制？*/

/*
两个迭代器 begin 和 end 需满足以下条件：
它们指向同一个容器中的元素，或者是容器最后一个元素之后的位置。
我们可以通过反复递增begin来到达end。换句话说，end 不在begin之前。
*/