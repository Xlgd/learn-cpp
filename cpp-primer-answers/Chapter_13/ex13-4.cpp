/*
以下标*的地方使用了拷贝构造函数：

Point global;
Point foo_bar(Point arg) * 
{
    Point local = arg *, *heap = new Point(global) *;
    *heap = local;
    Point pa[4] = { local, *heap }; *
    return *heap; *
}
共六处
*/