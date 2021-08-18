#include <iostream>

using namespace std;

static int counter = 0;
class numbered {
friend void f1(numbered s);
friend void f2(const numbered& s);
public:
    numbered() : mysn(counter++) { }
    numbered(numbered& rhs) : mysn(counter++) { }
private:
    int mysn;
};

void f1(numbered s) {
    cout << s.mysn << endl;
}

void f2(const numbered& s) {
    cout << s.mysn << endl;
}

int main() {
    numbered a, b = a, c = b;
    f1(a);
    f1(b);
    f1(c);

    f2(a);
    f2(b);
    f2(c);

    return 0;
}