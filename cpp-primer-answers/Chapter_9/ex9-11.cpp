// 练习9.11
/* 对6种创建和初始化vector对象的方法，每一种都给出一个实例。
解释每个vector包含什么值。*/

/*
vector<int> vec;    // 0
vector<int> vec(10);    // 10个0
vector<int> vec(10, 1);  // 10个1
vector<int> vec{ 1, 2, 3, 4, 5 }; // 1, 2, 3, 4, 5
vector<int> vec(other_vec); // 拷贝 other_vec 的元素
vector<int> vec(other_vec.begin(), other_vec.end()); // 拷贝 other_vec 的元素
*/