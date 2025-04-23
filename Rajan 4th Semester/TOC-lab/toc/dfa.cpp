#include <iostream>
#include <string>
using namespace std;

struct Node {
    string name;
    bool fnl = false;
    Node* aip = nullptr;
    Node* bip = nullptr;
};

class odd_a {
    Node q0, q1;
    Node* present;

public:
    odd_a() {
        q0.name = "q0";
        q0.aip = &q1;
        q0.bip = &q0;
        q1.name = "q1";
        q1.aip = &q0;
        q1.bip = &q1;
        q1.fnl = true;
        present = &q0;
    }

    bool test(const string& inp) {
        cout << "Input: " << inp << endl;
        cout << "Transitions:" << endl;
        present = &q0; // Reset to initial state
        for (char c : inp) {
            string currentState = present->name;
            switch (c) {
                case 'a':
                    present = present->aip;
                    break;
                case 'b':
                    present = present->bip;
                    break;
                default:
                    cout << "Error: Invalid input character '" << c << "'" << endl;
                    return false;
            }
            cout << currentState << " --(" << c << ")--> " << present->name << endl;
        }
        return present->fnl;
    }
};

int main() {
    odd_a a1;
    string input = "abaa";
    bool result = a1.test(input);
    cout << "Result: " << (result ? "Accept" : "Reject") << endl;
    return 0;
}