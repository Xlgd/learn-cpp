// 练习2.10
/* 下列变量的初值分别是什么？ */

#include <string>

std::string global_str;
int global_int;
int main()
{
    int local_int;
    std::string local_str;
}

/*
global_str和local_str都是空字符串；
global_int为0；
local_int初值未定义。
*/