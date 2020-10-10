// 练习7.15
/*为你的`Person`类添加正确的构造函数。*/

#include <string>
#include <iostream>
using namespace std;

class Person
{
    string name;
    string address;

public:
    Person() = default;
    Person(const string &nam, const string &add) : name(nam), address(add) { }
    Person(istream& in) { read(in, *this); }
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
    Person P1;
    print(cout, P1);
    Person P2("lgd", "China");
    print(cout, P2);
    Person P3(cin);
    print(cout, P3);
    return 0;
}