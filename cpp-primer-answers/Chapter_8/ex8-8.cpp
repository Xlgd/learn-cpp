// 练习8.8
/* 修改上一题的程序，将结果追加到给定的文件末尾。
对同一个输出文件，运行程序至少两次，检验数据是否得以保留。*/

#include <fstream>
#include <iostream>

using std::ifstream; 
using std::ofstream;
using std::cout; 
using std::endl; 
using std::cerr;

int main(int argc, char **argv)
{
    ifstream input(argv[1]);
    ofstream output(argv[2], ofstream::app);
    
    Sales_data total;
    if (read(input, total))
    {
        Sales_data trans;
        while (read(input, trans))
        {
            if (total.isbn() == trans.isbn())
                total.combine(trans);
            else
            {
                print(output, total) << endl;
                total = trans;
            }
        }
        print(output, total) << endl;
    }
    else
    {
        cerr << "No data?!" << endl;
    }
    
    return 0;
}