// 练习3.11
/* 下面的范围for语句合法吗？如果合法，c的类型是什么？ */

/*
const string s = "Keep out!";
for (auto &c : s) { ...  }

auto会忽略顶层const，如果代码会给c赋值就不合法

*/
