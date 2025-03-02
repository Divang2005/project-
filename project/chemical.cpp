#include <iostream>
#include <map>
#include <stack>
#include <cctype>
#include <vector>
#include <algorithm>

using namespace std;

map<string, int> countAtoms(string formula) {
    stack<map<string, int>> stack;
    map<string, int> current;
    int i = 0, n = formula.length();
    
    while (i < n) {
        if (isupper(formula[i])) {
            string atom(1, formula[i++]);
            while (i < n && islower(formula[i])) {
                atom += formula[i++];
            }
            
            int count = 0;
            while (i < n && isdigit(formula[i])) {
                count = count * 10 + (formula[i++] - '0');
            }
            if (count == 0) count = 1;
            current[atom] += count;
        } else if (formula[i] == '(') {
            stack.push(current);
            current.clear();
            i++;
        } else if (formula[i] == ')') {
            i++;
            int count = 0;
            while (i < n && isdigit(formula[i])) {
                count = count * 10 + (formula[i++] - '0');
            }
            if (count == 0) count = 1;
            
            for (auto &pair : current) {
                pair.second *= count;
            }
            if (!stack.empty()) {
                map<string, int> top = stack.top();
                stack.pop();
                for (auto &pair : current) {
                    top[pair.first] += pair.second;
                }
                current = top;
            }
        }
    }
    
    return current;
}

int main() {
    string formula;
    cout << "Enter the chemical formula: ";
    cin >> formula;
    
    map<string, int> result = countAtoms(formula);
    
    vector<pair<string, int>> sortedResult(result.begin(), result.end());
    sort(sortedResult.begin(), sortedResult.end());
    
    for (const auto &pair : sortedResult) {
        cout << pair.first << pair.second;
    }
    cout << endl;
    
    return 0;
}
