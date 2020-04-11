// 练习8.13
/* 重写本节的电话号码程序，从一个命名文件而非cin读取数据。*/

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
struct PersonInfo {
    string name;
    vector<string> phones;
};

bool valid(const string& str)
{
    return isdigit(str[0]);
}

string format(const string& str)
{
    return str.substr(0, 3) + "-" + str.substr(3, 3) + "-" + str.substr(6);
}

int main()
{
    string line, word;
    vector<PersonInfo> people;
    ifstream in("test.txt");
    
    while (getline(in, line))
    {
        PersonInfo  info;
        istringstream record(line);
        record >> info.name;
        while (record >> word)
            info.phones.push_back(word);
        people.push_back(info);
    }
    
    for (const auto& entry : people)
    {
        ostringstream formatted, badNums;
        for (const auto& nums : entry.phones)
        {
            if (!valid(nums))
            {
                badNums << " " << nums;
            }
            else
                formatted << " " << format(nums);
        }
        if (badNums.str().empty())
            cout << entry.name << " " << formatted.str() << endl;
        else
            cerr << "input error: " << entry.name
            << " invalid numbers(s) " << badNums.str() << endl;
    }
    return 0;
}