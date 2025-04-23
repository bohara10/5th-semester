#include <iostream>

class Node {
public:
    int data;
    Node* left;
    Node* right;
    
    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

class BST {
private:
    Node* root;
    
    Node* insertHelper(Node* current, int value) {
        if (current == nullptr) {
            return new Node(value);
        }
        
        if (value < current->data) {
            current->left = insertHelper(current->left, value);
        }
        else if (value > current->data) {
            current->right = insertHelper(current->right, value);
        }
        
        return current;
    }
    
    Node* searchHelper(Node* current, int value) {
        if (current == nullptr || current->data == value) {
            return current;
        }
        
        if (value < current->data) {
            return searchHelper(current->left, value);
        }
        
        return searchHelper(current->right, value);
    }

public:
    BST() {
        root = nullptr;
    }
    
    void insert(int value) {
        root = insertHelper(root, value);
    }
    
    bool search(int value) {
        Node* result = searchHelper(root, value);
        return result != nullptr;
    }
    
    void printInOrder(Node* current) {
        if (current == nullptr) return;
        
        printInOrder(current->left);
        std::cout << current->data << " ";
        printInOrder(current->right);
    }
    
    void printTree() {
        if (root == nullptr) {
            std::cout << "Tree is empty!" << std::endl;
            return;
        }
        printInOrder(root);
        std::cout << std::endl;
    }
};

int main() {
    BST tree;
    int choice, value;
    
    while (true) {
        std::cout << "\n=== Binary Search Tree Operations ===" << std::endl;
        std::cout << "1. Insert a value" << std::endl;
        std::cout << "2. Search for a value" << std::endl;
        std::cout << "3. Display the tree (In-order)" << std::endl;
        std::cout << "4. Exit" << std::endl;
        std::cout << "Enter your choice (1-4): ";
        std::cin >> choice;
        
        switch (choice) {
            case 1:
                std::cout << "Enter the value to insert: ";
                std::cin >> value;
                tree.insert(value);
                std::cout << value << " has been inserted into the tree." << std::endl;
                break;
                
            case 2:
                std::cout << "Enter the value to search: ";
                std::cin >> value;
                if (tree.search(value)) {
                    std::cout << value << " found in the tree!" << std::endl;
                } else {
                    std::cout << value << " not found in the tree!" << std::endl;
                }
                break;
                
            case 3:
                std::cout << "Tree elements (in-order): ";
                tree.printTree();
                break;
                
            case 4:
                std::cout << "Exiting program..." << std::endl;
                return 0;
                
            default:
                std::cout << "Invalid choice! Please try again." << std::endl;
        }
    }
    
    return 0;
}