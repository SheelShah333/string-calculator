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

    assert(add("1,2,3") == 6);
    assert(add("10,20,30,40") == 100);

    assert(add("1\n2,3") == 6);
    assert(add("4\n5\n6") == 15);

    assert(add("//;\n1;2") == 3);
    assert(add("//#\n4#5#6") == 15);

    try {
    add("1,-2,3");
    assert(false); // Should not reach here
} catch (const exception& e) {
    assert(string(e.what()) == "negative numbers not allowed -2");
}

try {
    add("2,-4,-6");
    assert(false); // Should not reach here
} catch (const exception& e) {
    assert(string(e.what()) == "negative numbers not allowed -4,-6");
}

    return 0;
}