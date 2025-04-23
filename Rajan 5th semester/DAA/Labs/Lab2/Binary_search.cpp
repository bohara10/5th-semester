#include <iostream>
using namespace std;

void binarySearch(int A[], int x, int low, int high, int &steps) {
    while (low <= high) {
        steps++;
        int mid = low + (high - low) / 2;

        if (A[mid] == x) {
            cout << x << " found at index " << mid << endl;
            return;
        }
        if (A[mid] < x) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    cout << x << " not found" << endl;
}

int main() {
    int n, steps = 0;
    cout << "Enter the size of the array: ";
    cin >> n;

    int A[n];
    cout << "Enter " << n << " elements in sorted order: ";
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    int x;
    cout << "Enter the element to search: ";
    cin >> x;

    binarySearch(A, x, 0, n - 1, steps);
    cout << "No of steps required: " << steps << endl;

    return 0;
}
