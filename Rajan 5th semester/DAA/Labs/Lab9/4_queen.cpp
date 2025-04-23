#include <iostream>
using namespace std;

const int MAX = 5; // Max board size

bool isSafe(int board[MAX][MAX], int row, int col, int n) {
    for (int i = 0; i < row; i++) if (board[i][col]) return false;
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) if (board[i][j]) return false;
    for (int i = row, j = col; i >= 0 && j < n; i--, j++) if (board[i][j]) return false;
    return true;
}

bool solve(int board[MAX][MAX], int row, int n) {
    if (row >= n) return true;
    for (int col = 0; col < n; col++) {
        if (isSafe(board, row, col, n)) {
            board[row][col] = 1;
            if (solve(board, row + 1, n)) return true;
            board[row][col] = 0;
        }
    }
    return false;
}

void print(int board[MAX][MAX], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cout << (board[i][j] ? "Q " : ". ");
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Enter size (1-5): ";
    cin >> n;
    n = (n < 1 || n > MAX) ? MAX : n;
    
    int board[MAX][MAX] = {0};
    
    if (solve(board, 0, n)) print(board, n);
    else cout << "No solution for " << n << "x" << n << " board\n";
    
    return 0;
}