// 练习7.9
/*对于7.1.2节练习中代码，添加读取和打印`Person`对象的操作。*/

#include <string>
#include <iostream>
using namespace std;

class Person
{
    string name;
    string address;

public:
    string get_name() const { return name; }
    string get_address() const { return address; }
    friend istream& read(istream&, Person&);
    friend ostream& print(ostream&, Person&);
};

istream& read(istream& in, Person& p)
{
    in >> p.name >> p.address;
    return in;
}

ostream& print(ostream& out, Person& p)
{
    out << p.get_name() << " " << p.get_address() << endl;
    return out;
}

int main()
{
    Person P;
    read(cin, P);
    print(cout, P);
    return 0;
}