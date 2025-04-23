#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Number of cities
int n;

// Function to solve TSP using DP
int tsp(vector<vector<int>>& graph, vector<vector<int>>& dp, int mask, int pos) {
    // If all cities are visited
    if(mask == (1 << n) - 1) {
        return graph[pos][0]; // Return to starting city
    }
    
    // If this subproblem is already solved
    if(dp[mask][pos] != -1) {
        return dp[mask][pos];
    }
    
    int ans = INT_MAX;
    // Try to visit an unvisited city
    for(int city = 0; city < n; city++) {
        if((mask & (1 << city)) == 0) { // If city is not visited
            int newAns = graph[pos][city] + tsp(graph, dp, mask | (1 << city), city);
            ans = min(ans, newAns);
        }
    }
    
    return dp[mask][pos] = ans;
}

// Function to reconstruct the path
vector<int> getPath(vector<vector<int>>& graph, vector<vector<int>>& dp) {
    vector<int> path;
    int mask = 1; // Start with only city 0 visited
    int pos = 0;  // Start from city 0
    path.push_back(0);
    
    for(int i = 0; i < n-1; i++) {
        int minCost = INT_MAX;
        int nextCity = -1;
        
        for(int city = 0; city < n; city++) {
            if((mask & (1 << city)) == 0) { // If city not visited
                int cost = graph[pos][city] + dp[mask | (1 << city)][city];
                if(cost < minCost) {
                    minCost = cost;
                    nextCity = city;
                }
            }
        }
        
        mask |= (1 << nextCity);
        pos = nextCity;
        path.push_back(nextCity);
    }
    
    path.push_back(0); // Return to start
    return path;
}

int main() {
    cout << "Enter number of cities: ";
    cin >> n;
    
    if(n <= 0) {
        cout << "Number of cities must be positive!" << endl;
        return 1;
    }
    
    // Initialize graph with infinity distances
    vector<vector<int>> graph(n, vector<int>(n));
    
    cout << "\nEnter the distance matrix (" << n << "x" << n << "):\n";
    cout << "Enter 0 for same city distance and INF (99999) for no direct path\n";
    
    // Input distance matrix
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }
    
    // Validate input
    for(int i = 0; i < n; i++) {
        if(graph[i][i] != 0) {
            cout << "Distance from city to itself must be 0!" << endl;
            return 1;
        }
    }
    
    // DP table: dp[mask][pos] represents minimum cost to visit all cities in mask
    // starting from pos
    vector<vector<int>> dp(1 << n, vector<int>(n, -1));
    
    // Solve TSP starting from city 0
    int minCost = tsp(graph, dp, 1, 0); // 1 means only city 0 is visited
    
    // Get the path
    vector<int> path = getPath(graph, dp);
    
    // Output results
    cout << "\nMinimum cost: " << minCost << endl;
    cout << "Path: ";
    for(int i = 0; i < path.size(); i++) {
        cout << path[i];
        if(i < path.size() - 1) cout << " -> ";
    }
    cout << endl;
    
    return 0;
}