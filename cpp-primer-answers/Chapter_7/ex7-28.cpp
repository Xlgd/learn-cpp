// 练习7.28
/*如果move、set和display函数的返回类型不是Screen& 而是Screen，
则在上一个练习中将会发生什么？*/

/*
如果返回类型是Screen，那么move返回的是*this的一个副本，
因此set函数只能改变临时副本而不能改变myScreen的值。
*/
