#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include <stdexcept>
#include <regex>
using namespace std;

int add(const string& input) {
    if (input.empty()) return 0;

    string numbers = input;
    vector<string> delimiters = {",", "\n"}; // default

    // Check for custom delimiters
    if (numbers.rfind("//", 0) == 0) {
        size_t newline_pos = numbers.find('\n');
        string delimiter_section = numbers.substr(2, newline_pos - 2);

        if (delimiter_section[0] == '[') {
            // Support multiple delimiters like //[***][%]
            regex re(R"(\[([^\]]+)\])");
            smatch match;
            string s = delimiter_section;
            while (regex_search(s, match, re)) {
                delimiters.push_back(match[1]);
                s = match.suffix();
            }
        } else {
            delimiters = {delimiter_section}; // single-char delimiter
        }

        numbers = numbers.substr(newline_pos + 1); // strip delimiter section
    }

    // Replace all delimiters with comma
    for (const string& delim : delimiters) {
        size_t pos;
        while ((pos = numbers.find(delim)) != string::npos) {
            numbers.replace(pos, delim.length(), ",");
        }
    }

    int sum = 0;
    vector<int> negatives;
    stringstream ss(numbers);
    string token;

    while (getline(ss, token, ',')) {
        if (!token.empty()) {
            int num = stoi(token);
            if (num < 0) negatives.push_back(num);
            else if (num <= 1000) sum += num;
        }
    }

    if (!negatives.empty()) {
        string msg = "negative numbers not allowed ";
        for (size_t i = 0; i < negatives.size(); ++i) {
            msg += to_string(negatives[i]);
            if (i < negatives.size() - 1) msg += ",";
        }
        throw runtime_error(msg);
    }

    return sum;
}