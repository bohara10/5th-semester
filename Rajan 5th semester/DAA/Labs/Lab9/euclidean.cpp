#include <iostream>
using namespace std;

int euclid(int a, int b) {
    // Base case: if b is 0, GCD is a
    if (b == 0) {
        return a;
    }
    // Recursive case: GCD(a, b) = GCD(b, a mod b)
    return euclid(b, a % b);
}

int main() {
    int a, b;
    
    // Get input from user
    cout << "Enter first number (a): ";
    cin >> a;
    cout << "Enter second number (b): ";
    cin >> b;
    
    // Validate input for non-negative numbers
    if (a < 0 || b < 0) {
        cout << "Error: Numbers must be non-negative." << endl;
        return 1;
    }
    
    // Compute and display GCD
    int result = euclid(a, b);
    cout << "GCD of " << a << " and " << b << " is: " << result << endl;
    
    return 0;
}