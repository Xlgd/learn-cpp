// 练习7.38
/* 有些情况下我们希望提供cin作为接受istream&参数的构造函数的默认实参，
请声明这样的构造函数。
*/

// Sales_data(std::istream &is = std::cin) { read(is, *this); }