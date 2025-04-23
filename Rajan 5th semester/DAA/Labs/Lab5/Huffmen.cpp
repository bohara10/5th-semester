#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// Huffman tree node
struct Node {
    char ch;
    int frequency;
    Node *left, *right;

    Node(char c, int f) {
        ch = c;
        frequency = f;
        left = right = nullptr;
    }
};

// Comparator for priority queue
struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->frequency > b->frequency; // Min-heap based on frequency
    }
};

// Huffman Coding Algorithm
Node* Huffman(vector<pair<char, int>> C) {
    priority_queue<Node*, vector<Node*>, Compare> Q;

    // Step 1: Insert all characters into priority queue
    for (auto &p : C) {
        Q.push(new Node(p.first, p.second));
    }

    // Step 2: Build Huffman Tree
    while (Q.size() > 1) {
        Node* x = Q.top(); Q.pop();
        Node* y = Q.top(); Q.pop();

        Node* z = new Node('\0', x->frequency + y->frequency);
        z->left = x;
        z->right = y;

        Q.push(z);
    }
    
    // Step 3: Return root of the Huffman tree
    return Q.top();
}

// Function to print Huffman codes
void printCodes(Node* root, string code) {
    if (!root) return;
    if (root->ch != '\0') {
        cout << root->ch << ": " << code << endl;
    }
    printCodes(root->left, code + "0");
    printCodes(root->right, code + "1");
}

int main() {
    int n;
    cout << "Enter the number of characters: ";
    cin >> n;

    vector<pair<char, int>> C;
    cout << "Enter the characters and their frequencies:\n";
    for (int i = 0; i < n; i++) {
        char ch;
        int freq;
        cin >> ch >> freq;
        C.push_back({ch, freq});
    }
    
    Node* root = Huffman(C);
    
    cout << "Huffman Codes:\n";
    printCodes(root, "");
    
    return 0;
}
