// 练习7.43
/* 假定有一个名为NoDefault的类，它有一个接受int的构造函数，但是没有默认构造函数。
定义类C，C有一个 NoDefault类型的成员，定义C的默认构造函数。*/

class NoDefault {
public:
    NoDefault(int i) { }
};

class C {
public:
    C() : def(0) { }
private:
    NoDefault def;
};