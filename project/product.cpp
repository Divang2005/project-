// Here two non-negative integers are given num1 and num2 represented as a strings, return the product of num1 and num2, also as string.   

#include <iostream>
#include <vector>

using namespace std;

string multiplyStrings(string num1, string num2) {
    if (num1 == "0" || num2 == "0") return "0";

    int len1 = num1.size(), len2 = num2.size();
    vector<int> result(len1 + len2, 0);

    for (int i = len1 - 1; i >= 0; i--) {
        for (int j = len2 - 1; j >= 0; j--) {
            int mul = (num1[i] - '0') * (num2[j] - '0');
            int sum = mul + result[i + j + 1];

            result[i + j + 1] = sum % 10;
            result[i + j] += sum / 10;
        }
    }

    string product;
    for (int num : result) {
        if (!(product.empty() && num == 0)) {
            product.push_back(num + '0');
        }
    }

    return product.empty() ? "0" : product;
}

int main() {
    string num1, num2;
    cout << "Enter two numbers: ";
    cin >> num1 >> num2;

    cout << "Product: " << multiplyStrings(num1, num2) << endl;
    return 0;
}
