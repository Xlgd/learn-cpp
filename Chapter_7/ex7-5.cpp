// 练习7.5
/*在你的`Person`类中提供一些操作使其能够返回姓名和地址。
这些函数是否应该是`const`的呢？解释原因。*/

# include <string>
using namespace std;

class Person
{
    string name;
    string address;

public:
    string get_name() const { return name; }
    string get_address() const { return address; }
};

// 应该是`const`的。因为常量的`Person`对象也需要使用这些函数操作。