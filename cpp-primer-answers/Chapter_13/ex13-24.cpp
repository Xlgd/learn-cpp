/*
若未定义析构函数，则会导致ps指向的内存泄漏。
若未定义拷贝构造函数，则拷贝一个对象时导致新的对象和原对象共享ps所指的字符串。
*/