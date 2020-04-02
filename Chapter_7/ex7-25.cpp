// 练习7.25
/*Screen能安全地依赖于拷贝和赋值操作的默认版本吗？
如果能，为什么？如果不能？为什么？*/

/*
能。 Screen的成员只有内置类型和string，因此能安全地依赖于拷贝和赋值操作的默认版本。

管理动态内存的类则不能依赖于拷贝和赋值操作的默认版本，而且也应该尽量使用string和vector来避免动态管理内存的复杂性。
*/