// pascal's triangle (enter number of rows for pascal's triangle)


#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

void printPascalsTriangle(int n) {
    vector<vector<int>> triangle(n);
    
    for (int i = 0; i < n; i++) {
        triangle[i].resize(i + 1);
        triangle[i][0] = triangle[i][i] = 1;
        
        for (int j = 1; j < i; j++) {
            triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
        }
    }
    
    for (int i = 0; i < n; i++) {
        cout << setw(n - i) << ""; 
        for (int j = 0; j <= i; j++) {
            cout << triangle[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int rows;
    cout << "Enter the number of rows: ";
    cin >> rows;
    printPascalsTriangle(rows);
    return 0;
}
