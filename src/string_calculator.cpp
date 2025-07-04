#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

int add(const string& input) {
    if (input.empty()) return 0;

    string numbers = input;
    string delimiter = ",\n";  // default delimiters

    // Check for custom delimiter
    if (numbers.rfind("//", 0) == 0) {
        // e.g., "//;\n1;2"
        delimiter = numbers[2];
        numbers = numbers.substr(4); // skip "//<delimiter>\n"
    } else {
        // Replace \n with ,
        replace(numbers.begin(), numbers.end(), '\n', ',');
    }

    // Normalize delimiters
    for (char& ch : numbers) {
        if (delimiter.find(ch) != string::npos) {
            ch = ','; // standardize all delimiters to comma
        }
    }

    int sum = 0;
    stringstream ss(numbers);
    string token;

    while (getline(ss, token, ',')) {
        if (!token.empty()) {
            sum += stoi(token);
        }
    }

    return sum;
}