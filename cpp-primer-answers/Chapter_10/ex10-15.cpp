/* 编写一个 lambda ，捕获它所在函数的 int，并接受一个 int参数。lambda 应该返回捕获的 int 和 int 参数的和。*/

void testLambda() {
    int a = 0;
    auto f = [a](int b) { return a + b; };
}