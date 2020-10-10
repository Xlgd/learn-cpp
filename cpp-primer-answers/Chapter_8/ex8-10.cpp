// 练习8.10
/* 编写程序，将来自一个文件中的行保存在一个vector中。
然后使用一个istringstream从vector读取数据元素，每次读取一个单词。*/

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
void ReadFileToVec(const string& fileName, vector<string>& vec)
{
    ifstream ifs(fileName);
    if (ifs)
    {
        string buf;
        while (getline(ifs, buf))
            vec.push_back(buf);
    }
}
int main()
{
    vector<string> box;
    string word;
    const string file("test.txt");
    ReadFileToVec(file, box);
    for (string line : box)
    {
        istringstream in(line);
        while(in >> word)
            cout << word << endl;
    }
        
    return 0;
}