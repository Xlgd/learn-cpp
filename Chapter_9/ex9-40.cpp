// 练习9.40
/* 如果上一题的程序读入了256个词，在resize之后容器的capacity可能是多少？
如果读入了512个、1000个、或1048个呢？*/

/*

如果读入了256个词，capacity 仍然是 1024
如果读入了512个词，capacity 仍然是 1024
如果读入了1000或1048个词，capacity 取决于具体实现。
*/