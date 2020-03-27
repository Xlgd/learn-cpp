// 练习3.12
/* 下列vector对象的定义有不正确的吗？如果有，请指出来。对于正确的，描述其执行结果；
对于不正确的，说明其错误的原因。 */

/*
(a) vector<vector<int>> ivec; 正确，创建了一个元素为vector的vector
(b) vector<string> svec = ivec; 不正确，类型不一致
(c) vector<string> svec(10, "null"); 正确，创建了一个包含10个"null"字符串的vector
*/