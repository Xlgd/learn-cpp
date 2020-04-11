// 练习8.7
/*修改上一节的书店程序，将结果保存到一个文件中。
将输出文件名作为第二个参数传递给main函数。*/

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
    ofstream output(argv[2]);
    
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