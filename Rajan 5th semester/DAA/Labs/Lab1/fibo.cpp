#include <iostream>
using namespace std;

void Fibonacci(int n) {
    int a = 0, b = 1, steps = 0, next;
    
    for (int i = 0; i < n; i++) {
        steps++;
        cout << a << " , ";
        next = a + b;
        a = b;
        b = next;
    }
    cout << "Number of steps required: " << steps << endl;
}

int main() {
    int n;
    cout << "Enter the number of terms for the Fibonacci sequence: ";
    cin >> n;
    Fibonacci(n);
    return 0;
}
