/* 在本节对名册（roster）调用equal的例子中，
如果两个名册中保存的都是C风格字符串而不是string，会发生什么？*/

/*
因为C风格字符串的值为存储字符串的地址，所以在比较的时候其实是在比较两个字符串的地址是否相等，和我们的想法有区别。
*/