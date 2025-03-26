// sum of numbers in the given range 

#include <iostream>
using namespace std;

int sumInRange(int start, int end) {
    int sum = 0;
    for (int i = start; i <= end; i++) {
        sum += i;
    }
    return sum;
}

int main() {
    int l, r;
    
    cout << "Enter the start of the range: ";
    cin >> l;
    cout << "Enter the end of the range: ";
    cin >> r;
    
    int result = sumInRange(l, r);
    cout << "The sum of numbers from " << l << " to " << r << " is: " << result << endl;
    
    return 0;
}
