#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

int add(const string& input) {
    if (input.empty()) return 0;

    string normalized = input;
    replace(normalized.begin(), normalized.end(), '\n', ',');  // Replace \n with ,

    int sum = 0;
    stringstream ss(normalized);
    string token;

    while (getline(ss, token, ',')) {
        if (!token.empty()) {
            sum += stoi(token);
        }
    }

    return sum;
}