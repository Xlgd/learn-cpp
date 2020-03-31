// 练习3.27
/*假设`txt_size`是一个无参函数，它的返回值是`int`。请回答下列哪个定义是非法的，为什么？
 */

/*
unsigned buf_size = 1024;
(a) int ia[buf_size]; 非法，维度必须是常量
(b) int ia[4 * 7 - 14]; 合法
(c) int ia[txt_size()]; 非法，函数的值只能在运行的时候得到
(d) char st[11] = "fundamental"; 非法，没有给'\0'留空间
*/
