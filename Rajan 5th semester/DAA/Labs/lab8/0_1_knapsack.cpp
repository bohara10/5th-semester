#include <iostream>
#include <vector>
using namespace std;

// Function to solve 0/1 Knapsack using DP
int knapsack(vector<int>& weights, vector<int>& values, int capacity, int n) {
    // Create DP table
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));
    
    // Fill DP table
    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= capacity; w++) {
            if (weights[i-1] <= w) {
                // Max of including or excluding current item
                dp[i][w] = max(values[i-1] + dp[i-1][w - weights[i-1]], dp[i-1][w]);
            } else {
                // Can't include current item
                dp[i][w] = dp[i-1][w];
            }
        }
    }
    
    return dp[n][capacity];
}

// Function to find selected items
vector<int> getSelectedItems(vector<int>& weights, vector<int>& values, int capacity, int n) {
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));
    // Fill DP table (same as above)
    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= capacity; w++) {
            if (weights[i-1] <= w) {
                dp[i][w] = max(values[i-1] + dp[i-1][w - weights[i-1]], dp[i-1][w]);
            } else {
                dp[i][w] = dp[i-1][w];
            }
        }
    }
    
    // Backtrack to find selected items
    vector<int> selected;
    int w = capacity;
    for (int i = n; i > 0 && w > 0; i--) {
        if (dp[i][w] != dp[i-1][w]) {
            selected.push_back(i-1);  // Item i-1 was included
            w -= weights[i-1];
        }
    }
    
    return selected;
}

int main() {
    int n, capacity;
    
    // Input number of items
    cout << "Enter number of items: ";
    cin >> n;
    if (n <= 0) {
        cout << "Number of items must be positive!\n";
        return 1;
    }
    
    // Input capacity
    cout << "Enter knapsack capacity: ";
    cin >> capacity;
    if (capacity < 0) {
        cout << "Capacity cannot be negative!\n";
        return 1;
    }
    
    vector<int> weights(n), values(n);
    
    // Input weights
    cout << "Enter weights of " << n << " items:\n";
    for (int i = 0; i < n; i++) {
        cout << "Item " << i + 1 << ": ";
        cin >> weights[i];
        if (weights[i] < 0) {
            cout << "Weight cannot be negative!\n";
            return 1;
        }
    }
    
    // Input values
    cout << "Enter values of " << n << " items:\n";
    for (int i = 0; i < n; i++) {
        cout << "Item " << i + 1 << ": ";
        cin >> values[i];
        if (values[i] < 0) {
            cout << "Value cannot be negative!\n";
            return 1;
        }
    }
    
    // Calculate maximum value
    int maxValue = knapsack(weights, values, capacity, n);
    
    // Get selected items
    vector<int> selected = getSelectedItems(weights, values, capacity, n);
    
    // Output results
    cout << "\nMaximum value: " << maxValue << endl;
    cout << "Selected items (indices): ";
    for (int i = selected.size() - 1; i >= 0; i--) {
        cout << selected[i];
        if (i > 0) cout << ", ";
    }
    cout << endl;
    
    return 0;
}