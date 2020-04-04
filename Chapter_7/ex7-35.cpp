// 练习7.35
/*解释下面代码的含义，说明其中的Type和initVal分别使用了哪个定义。
如果代码存在错误，尝试修改它。*/

#include<string>
using namespace std;

typedef string Type;
Type initVal(); // Type为string
class Exercise {
public:
    typedef double Type;
    Type setVal(Type); // Type为double
    Type initVal(); // Type为double
private:
    int val;
};
Exercise::Type Exercise::setVal(Type parm) { // 函数类型Type为string，parm参数类型为double
    val = parm + initVal(); // 使用了类中的定义
    return val;
}