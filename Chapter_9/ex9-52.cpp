// 练习9.52
/* 使用stack处理括号化的表达式。
当你看到一个左括号，将其记录下来。
当你在一个左括号之后看到一个右括号，从stack中pop对象，直至遇到左括号，
将左括号也一起弹出栈。然后将一个值（括号内的运算结果）push到栈中，
表示一个括号化的（子）表达式已经处理完毕，被其运算结果所替代。*/

#include <stack>
#include <string>
#include <iostream>

using std::string; using std::cout; using std::endl; using std::stack;

int main()
{
    string expression{ "This is (pezy)." };
    bool bSeen = false;
    stack<char> stk;
    for (const auto &s : expression)
    {
        if (s == '(') { bSeen = true; continue; }
        else if (s == ')') bSeen = false;
        
        if (bSeen) stk.push(s);
    }
    
    string repstr;
    while (!stk.empty())
    {
        repstr += stk.top();
        stk.pop();
    }
    
    expression.replace(expression.find("(")+1, repstr.size(), repstr);
    
    cout << expression << endl;
    
    return 0;
}