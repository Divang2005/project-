// this pattern is known as Look-and-Say sequence

// Start with "1" as the first term.
// Read "1" as "one 1" → "11" (2nd term).
// Read "11" as "two 1s" → "21" (3rd term).
// Read "21" as "one 2, one 1" → "1211" (4th term).
// Read "1211" as "one 1, one 2, two 1s" → "111221" (5th term).

// like this pattern works.

#include <iostream>
#include <string>

using namespace std;

void lookAndSay(int n) {
    if (n <= 0) return;

    string result = "1";  // First term of the sequence
    cout << result << endl;

    for (int i = 1; i < n; i++) {
        string next_term = "";
        int count = 1;

        for (size_t j = 0; j < result.length(); j++) {
            if (j + 1 < result.length() && result[j] == result[j + 1]) {
                count++;
            } else {
                next_term += to_string(count) + result[j];
                count = 1;
            }
        }

        result = next_term;
        cout << result << endl;
    }
}

int main() {
    int n;
    cout << "Enter the number of rows: ";
    cin >> n;
    lookAndSay(n);
    return 0;
}
