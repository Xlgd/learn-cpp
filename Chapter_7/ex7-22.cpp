// 练习7.22
/*修改你的`Person`类使其隐藏实现的细节。*/

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
