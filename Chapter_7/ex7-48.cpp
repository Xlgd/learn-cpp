// 练习7.48
/* 假定Sales_data的构造函数不是explicit的，
则下述定义将执行什么样的操作？*/

/*
string null_isbn("9-999-99999-9"); 定义一个string
Sales_data item1(null_isbn); 定义Sales_data对象item1
Sales_data item2("9-999-99999-9"); 定义Sales_data对象item2

如果构造函数是explicit，不会对上面的定义产生影响
*/