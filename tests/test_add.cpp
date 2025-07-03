#include <cassert>
#include <iostream>
using namespace std;

extern int add(const string&);

int main() {
    assert(add("") == 0);  // Test empty string returns 0
    cout << "Test passed" << endl;
    assert(add("1") == 1);
    assert(add("42") == 42);

    assert(add("1,2") == 3);
    assert(add("4,5") == 9);


    return 0;
}