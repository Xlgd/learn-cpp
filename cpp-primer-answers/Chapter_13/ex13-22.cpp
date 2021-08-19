#include <string>
using namespace std;

class HasPtr {
public:
    HasPtr(const HasPtr& rhs) : ps(new string(*rhs.ps)), i(rhs.i) { }
    HasPtr& operator=(const HasPtr& rhs) {
        string *temp =  new string(*rhs.ps);
        delete ps;
        ps = temp;
        i = rhs.i;
        return *this;
    }
private:
    string *ps;
    int i;    
};