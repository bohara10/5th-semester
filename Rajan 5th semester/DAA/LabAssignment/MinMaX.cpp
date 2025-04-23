#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>

class Node {
public:
    std::vector<Node*> children;
    int value;
    bool isTerminal;
    
    Node(int val = 0, bool terminal = false) : value(val), isTerminal(terminal) {}
    
    void addChild(Node* child) {
        children.push_back(child);
    }
};

class MinMax {
private:
    int maxDepth;
    
    int minValue(Node* node, int depth, int alpha, int beta) {
        if (depth == maxDepth || node->isTerminal) {
            return node->value;
        }
        
        int minVal = INT_MAX;
        
        for (Node* child : node->children) {
            int value = maxValue(child, depth + 1, alpha, beta);
            minVal = std::min(minVal, value);
            beta = std::min(beta, minVal);
            
            if (beta <= alpha) {
                break; // Alpha-beta pruning
            }
        }
        
        return minVal;
    }
    
    int maxValue(Node* node, int depth, int alpha, int beta) {
        if (depth == maxDepth || node->isTerminal) {
            return node->value;
        }
        
        int maxVal = INT_MIN;
        
        for (Node* child : node->children) {
            int value = minValue(child, depth + 1, alpha, beta);
            maxVal = std::max(maxVal, value);
            alpha = std::max(alpha, maxVal);
            
            if (beta <= alpha) {
                break; // Alpha-beta pruning
            }
        }
        
        return maxVal;
    }

public:
    MinMax(int depth = 3) : maxDepth(depth) {}
    
    std::pair<int, int> findMinMax(Node* root) {
        int maxVal = maxValue(root, 0, INT_MIN, INT_MAX);
        int minVal = minValue(root, 0, INT_MIN, INT_MAX);
        return std::make_pair(minVal, maxVal);
    }
};

// Example usage and test
int main() {
    // Create a sample game tree
    Node* root = new Node();
    
    // Level 1
    Node* node1 = new Node();
    Node* node2 = new Node();
    Node* node3 = new Node();
    
    // Level 2 (terminal nodes with values)
    Node* leaf1 = new Node(3, true);
    Node* leaf2 = new Node(5, true);
    Node* leaf3 = new Node(2, true);
    Node* leaf4 = new Node(9, true);
    Node* leaf5 = new Node(12, true);
    Node* leaf6 = new Node(8, true);
    
    // Build the tree
    root->addChild(node1);
    root->addChild(node2);
    root->addChild(node3);
    
    node1->addChild(leaf1);
    node1->addChild(leaf2);
    node2->addChild(leaf3);
    node2->addChild(leaf4);
    node3->addChild(leaf5);
    node3->addChild(leaf6);
    
    // Create MinMax instance and find min-max values
    MinMax minmax(3); // depth = 3
    auto result = minmax.findMinMax(root);
    
    std::cout << "Minimum value: " << result.first << std::endl;
    std::cout << "Maximum value: " << result.second << std::endl;
    
    return 0;
}