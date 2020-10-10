// 练习8.4
/*  编写函数，以读模式打开一个文件，将其内容读入到一个string的vector中，
将每一行作为一个独立的元素存于vector中。*/

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
        while (getline(ifs, buf))
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