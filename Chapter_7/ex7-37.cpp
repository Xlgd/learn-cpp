// 练习7.37
/* 使用本节提供的Sales_data类，确定初始化下面的变量时分别使用了哪个构造函数，
然后罗列出每个对象所有的数据成员的值。*/

/*
Sales_data first_item(cin) // 使用Sales_data(std::istream &is)，从输入读入数据
int main(){
    Sales_data next; // 使用默认构造函数，bookNo = "", cnt = 0, revenue = 0.0
    Sales_data last("9-999-99999-9");
    // 使用使用 Sales_data(std::string s = "");   
    //bookNo = "9-999-99999-9", cnt = 0, revenue = 0.0
}
*/