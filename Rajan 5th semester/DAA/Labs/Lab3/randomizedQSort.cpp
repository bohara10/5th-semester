#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int steps = 0;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
    steps++; // Count each swap operation
}

int partition(int arr[], int low, int high) {
    int pivotIndex = low + rand() % (high - low + 1);
    swap(arr[pivotIndex], arr[high]);
    int pivot = arr[high];
    int i = low - 1;
    
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void randomizedQuickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        randomizedQuickSort(arr, low, pi - 1);
        randomizedQuickSort(arr, pi + 1, high);
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    srand(time(0)); // Seed random number generator
    
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    
    
    int arr[n];
    cout<<"Enter the of element:";
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }


    randomizedQuickSort(arr, 0, n - 1);

    cout << "\nSorted array: ";
    printArray(arr, n);

    cout << "Total number of steps: " << steps << endl;
    
    
    return 0;
}