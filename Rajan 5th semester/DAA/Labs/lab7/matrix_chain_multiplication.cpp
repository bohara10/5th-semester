#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Function to print the optimal parenthesization
void printOptimalParenthesis(vector<vector<int>>& s, int i, int j) {
    if (i == j) {
        cout << "A" << i;
        return;
    }
    cout << "(";
    printOptimalParenthesis(s, i, s[i][j]);
    printOptimalParenthesis(s, s[i][j] + 1, j);
    cout << ")";
}

// Function to find minimum cost of matrix chain multiplication
int matrixChainMultiplication(vector<int>& p, int n) {
    // m[i][j] stores minimum number of scalar multiplications needed
    vector<vector<int>> m(n, vector<int>(n, 0));
    // s[i][j] stores the split point for optimal parenthesization
    vector<vector<int>> s(n, vector<int>(n, 0));
    
    // l is the chain length
    for (int l = 2; l < n; l++) {
        // i is the starting matrix
        for (int i = 1; i < n - l + 1; i++) {
            int j = i + l - 1; // j is the ending matrix
            m[i][j] = INT_MAX;
            
            // Try different positions to split
            for (int k = i; k < j; k++) {
                int cost = m[i][k] + m[k + 1][j] + p[i-1] * p[k] * p[j];
                if (cost < m[i][j]) {
                    m[i][j] = cost;
                    s[i][j] = k;
                }
            }
        }
    }
    
    // Print the multiplication table
    cout << "Minimum Cost Table (m):\n";
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            if (j < i) cout << "0\t";
            else cout << m[i][j] << "\t";
        }
        cout << endl;
    }
    
    cout << "\nOptimal Split Table (s):\n";
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            if (j <= i) cout << "0\t";
            else cout << s[i][j] << "\t";
        }
        cout << endl;
    }
    
    cout << "\nOptimal Parenthesization: ";
    printOptimalParenthesis(s, 1, n-1);
    cout << endl;
    
    return m[1][n-1];
}

int main() {
    int n;
    cout << "Enter the number of matrices: ";
    cin >> n;
    
    if (n <= 1) {
        cout << "At least 2 matrices are required!" << endl;
        return 1;
    }
    
    // p stores dimensions: p[i-1] x p[i] is dimension of matrix Ai
    vector<int> p(n + 1);
    cout << "Enter " << n+1 << " dimensions (e.g., for A1: 10x30 enter 10 30):\n";
    for (int i = 0; i <= n; i++) {
        cin >> p[i];
    }
    
    int minCost = matrixChainMultiplication(p, n + 1);
    cout << "Minimum number of multiplications needed: " << minCost << endl;
    
    return 0;
}