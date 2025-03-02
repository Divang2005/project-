// convert encoding string to decoding string 


#include <iostream>
#include <stack>
#include <string>

using namespace std;

string decodeString(string s) {
    stack<int> countStack;
    stack<string> resultStack;
    string result = "";
    int i = 0;
    
    while (i < s.length()) {
        if (isdigit(s[i])) {
            int count = 0;
            while (isdigit(s[i])) {
                count = count * 10 + (s[i] - '0');
                i++;
            }
            countStack.push(count);
        } else if (s[i] == '[') {
            resultStack.push(result);
            result = "";
            i++;
        } else if (s[i] == ']') {
            string temp = resultStack.top();
            resultStack.pop();
            int repeatTimes = countStack.top();
            countStack.pop();
            
            for (int j = 0; j < repeatTimes; j++) {
                temp += result;
            }
            result = temp;
            i++;
        } else {
            result += s[i];
            i++;
        }
    }
    return result;
}

int main() {
    string input;
    cout << "Enter the encoded string: ";
    cin >> input;
    cout << "Decoded string: " << decodeString(input) << endl;
    return 0;
}
