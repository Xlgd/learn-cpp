#include <iostream>
#include "../mini_stl/smart_pointers.h"
using namespace std;

int main() {
    // Unique_Ptr testing

    Unique_Ptr<int> test(new int(8));
    cout << *test << endl;

    int * b = test.get();
    cout << *b << endl;

    Unique_Ptr<int> test2(move(test));
    int c = *test2;
    cout << c << endl;
    if (test == nullptr) {
        cout << "test is null" << endl;
    }

    Unique_Ptr<int> test3 = move(test2);
    cout << *test3 << endl;
    if (test2 == nullptr) {
        cout << "test2 is null" << endl;
    }

    int * d = test3.release();
    cout << *d << endl;
    if (test3 == nullptr) {
        cout << "test3 is null" << endl;
    }

    // Shared_Ptr testing
    Shared_Ptr<int> t(new int(12));
    Shared_Ptr<int> t2;
    Shared_Ptr<int> t3(t);
    cout << *t << " " << *(t3.get()) << " " << t3.count() << endl;
    t2 = t;
    cout << *t2 << " " << t2.count() << endl;

    Shared_Ptr<int> t4(new int(13));
    cout << t4.count() << endl;
    t = t4;
    t2 = t4;
    cout << t3.count() << endl;
    t3 = t4;
    cout << t4.count() << endl;
    if (t3 == t4) {
        cout << "t3 is equal to t4" << endl;
    }

    return 0;
}