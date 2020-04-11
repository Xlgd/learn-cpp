// 练习8.5
/* 重写上面的程序，将每个单词作为一个独立的元素进行存储。*/

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
void ReadFileToVec(const string& fileName, vector<string>& vec)
{
    ifstream ifs(fileName);
    if (ifs)
    {
        string buf;
        while (ifs >> buf)
            vec.push_back(buf);
    }
}
int main()
{
    vector<string> box;
    const string file("test.txt");
    ReadFileToVec(file, box);
    for (string line : box)
    {
        cout << line << endl;
    }
        
    return 0;
}