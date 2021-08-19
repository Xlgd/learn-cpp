#include <string>
using namespace std;

class Employee {
public:
    Employee() : number(counter++), name(string()) { }
    Employee(string n) : number(counter++), name(n) { }
private:
    static int counter;
    int number;
    string name;
};