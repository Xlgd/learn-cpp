/* 假定 v 是一个vector<double>，
那么调用 accumulate(v.cbegin(),v.cend(),0) 有何错误（如果存在的话）？*/

/*
因为accumulate第三个参数是0，所以会导致在计算的时候将v中的double类型的数据转化为int类型，最后结果也会是int
*/