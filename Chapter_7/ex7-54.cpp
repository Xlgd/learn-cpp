// 练习7.54
/* Debug中以 set_`开头的成员应该被声明成constexpr吗？如果不，为什么？*/

// 不能。constexpr函数必须包含一个返回语句。