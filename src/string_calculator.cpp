#include <string>
#include <sstream>
using namespace std;

int add(const string& input) {
    if (input.empty()) return 0;

    int sum = 0;
    stringstream ss(input);
    string token;

    while (getline(ss, token, ',')) {
        sum += stoi(token);
    }

    return sum;
}