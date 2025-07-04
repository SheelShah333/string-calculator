#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include <stdexcept>
using namespace std;

int add(const string& input) {
    if (input.empty()) return 0;

    string numbers = input;
    string delimiter = ",\n";

    // Custom delimiter check
    if (numbers.rfind("//", 0) == 0) {
        delimiter = numbers[2];
        numbers = numbers.substr(4);
    } else {
        replace(numbers.begin(), numbers.end(), '\n', ',');
    }

    // Normalize all delimiters to comma
    for (char& ch : numbers) {
        if (delimiter.find(ch) != string::npos) {
            ch = ',';
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