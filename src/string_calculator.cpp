#include <string>
using namespace std;

int add(const string& input) {
    return input.empty() ? 0 : stoi(input);
}