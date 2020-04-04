// 练习7.31
/*定义一对类`X`和`Y`，其中`X`包含一个指向`Y`的指针，
而`Y`包含一个类型为`X`的对象。
*/

class Y;

class X{
    Y* y = nullptr;	
};

class Y{
    X x;
};