/* 本节提到过，标准库算法不会改变它们所操作的容器的大小。为什么使用 back_inserter 不会使这一断言失效？*/

// back_inserter 是插入迭代器，在 iterator.h 头文件中，不是标准库的算法。