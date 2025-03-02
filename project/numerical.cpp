#include <iostream>
#include <sstream>
#include <unordered_map>

using namespace std;

long long wordsToNumber(const string &words) {
    unordered_map<string, int> wordMap = {
        {"zero", 0}, {"one", 1}, {"two", 2}, {"three", 3}, {"four", 4},
        {"five", 5}, {"six", 6}, {"seven", 7}, {"eight", 8}, {"nine", 9},
        {"ten", 10}, {"eleven", 11}, {"twelve", 12}, {"thirteen", 13},
        {"fourteen", 14}, {"fifteen", 15}, {"sixteen", 16}, {"seventeen", 17},
        {"eighteen", 18}, {"nineteen", 19}, {"twenty", 20}, {"thirty", 30},
        {"forty", 40}, {"fifty", 50}, {"sixty", 60}, {"seventy", 70},
        {"eighty", 80}, {"ninety", 90}, {"hundred", 100}, {"thousand", 1000},
        {"million", 1000000}, {"billion", 1000000000}
    };

    istringstream iss(words);
    string word;
    long long number = 0, current = 0;

    while (iss >> word) {
        if (wordMap.find(word) != wordMap.end()) {
            int value = wordMap[word];

            if (value == 100) {
                current *= 100;  // "one hundred" -> 100
            } else if (value == 1000 || value == 1000000 || value == 1000000000) {
                current *= value;  // Handle "thousand", "million", "billion"
                number += current;
                current = 0;
            } else {
                current += value;
            }
        }
    }

    number += current;
    return number;
}

int main() {
    string input;
    cout << "Enter a number in words (e.g., 'two million five hundred thousand sixty three'): ";
    getline(cin, input);  // Get full-line input

    long long result = wordsToNumber(input);
    cout << "Numeric Value: " << result << endl;

    return 0;
}
