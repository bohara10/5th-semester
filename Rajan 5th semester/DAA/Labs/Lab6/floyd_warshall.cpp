#include <iostream>
#include <vector>
using namespace std;

// Define infinity as a large number
#define INF 99999

// Function to implement Floyd-Warshall algorithm
void floydWarshall(vector<vector<int>>& graph, int V) {
    vector<vector<int>> dist(V, vector<int>(V));
     
    // Initialize distance matrix
    for(int i = 0; i < V; i++) {
        for(int j = 0; j < V; j++) {
            dist[i][j] = graph[i][j];
        }
    }
    
    // Update distances
    for(int k = 0; k < V; k++) {
        for(int i = 0; i < V; i++) {
            for(int j = 0; j < V; j++) {
                if(dist[i][k] != INF && dist[k][j] != INF && 
                   dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    
    // Print result
    cout << "\nShortest distances between every pair of vertices:\n";
    for(int i = 0; i < V; i++) {
        for(int j = 0; j < V; j++) {
            if(dist[i][j] == INF)
                cout << "INF" << "\t";
            else
                cout << dist[i][j] << "\t";
        }
        cout << endl;
    }
}

// Function to print the graph
void printGraph(vector<vector<int>>& graph, int V) {
    cout << "\nInput Graph (adjacency matrix):\n";
    for(int i = 0; i < V; i++) {
        for(int j = 0; j < V; j++) {
            if(graph[i][j] == INF)
                cout << "INF" << "\t";
            else
                cout << graph[i][j] << "\t";
        }
        cout << endl;
    }
}

int main() {
    int V;
    
    // Get number of vertices
    cout << "Enter the number of vertices: ";
    cin >> V;
    
    // Input validation
    if(V <= 0) {
        cout << "Number of vertices must be positive!" << endl;
        return 1;
    }
    
    // Create adjacency matrix with initial values as INF
    vector<vector<int>> graph(V, vector<int>(V, INF));
    
    // Set diagonal elements to 0
    for(int i = 0; i < V; i++) {
        graph[i][i] = 0;
    }
    
    // Get edges from user
    cout << "\nEnter edges (format: source destination weight)\n";
    cout << "Enter -1 -1 -1 to finish\n";
    
    while(true) {
        int src, dest, weight;
        cout << "Edge: ";
        cin >> src >> dest >> weight;
        
        // Check for termination condition
        if(src == -1 && dest == -1 && weight == -1) {
            break;
        }
        
        // Validate input
        if(src < 0 || src >= V || dest < 0 || dest >= V) {
            cout << "Invalid vertex! Vertices should be between 0 and " << V-1 << endl;
            continue;
        }
        if(weight < 0) {
            cout << "Negative weights are allowed but be careful of negative cycles\n";
        }
        
        // Update graph
        graph[src][dest] = weight;
    }
    
    // Print input graph
    printGraph(graph, V);
    
    // Run Floyd-Warshall algorithm
    floydWarshall(graph, V);
    
    return 0;
}