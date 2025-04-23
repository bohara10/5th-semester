#include<iostream>
using namespace std;

void search(int A[], int n, int x) {
    int steps = 0;
    for (int i = 0; i < n; i++) {
        steps++;
        if (A[i] == x) {
            cout << "Found at " << i + 1 << " position." << endl;
            cout << "Number of steps required: " << steps << endl;
            return;
        }
    }
    cout << "Element not found!" << endl;
    cout << "Number of steps required: " << steps << endl;
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    int A[n];
    cout << "Enter elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    int x;
    cout << "Enter an element to search: ";
    cin >> x;

    search(A, n, x);

    return 0;
}
 