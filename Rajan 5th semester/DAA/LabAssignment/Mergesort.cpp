#include <iostream>
#include <vector>

class MergeSort {
private:
    // Merge two sorted subarrays into one sorted array
    void merge(std::vector<int>& arr, int left, int mid, int right) {
        int n1 = mid - left + 1;
        int n2 = right - mid;
        
        // Create temporary arrays
        std::vector<int> L(n1), R(n2);
        
        // Copy data to temporary arrays
        for(int i = 0; i < n1; i++)
            L[i] = arr[left + i];
        for(int j = 0; j < n2; j++)
            R[j] = arr[mid + 1 + j];
        
        // Merge the temporary arrays back into arr
        int i = 0;    // Initial index of first subarray
        int j = 0;    // Initial index of second subarray
        int k = left; // Initial index of merged subarray
        
        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) {
                arr[k] = L[i];
                i++;
            }
            else {
                arr[k] = R[j];
                j++;
            }
            k++;
        }
        
        // Copy the remaining elements of L[], if any
        while (i < n1) {
            arr[k] = L[i];
            i++;
            k++;
        }
        
        // Copy the remaining elements of R[], if any
        while (j < n2) {
            arr[k] = R[j];
            j++;
            k++;
        }
    }
    
    // Main mergeSort function
    void mergeSortHelper(std::vector<int>& arr, int left, int right) {
        if (left < right) {
            int mid = left + (right - left) / 2;
            
            // Sort first and second halves
            mergeSortHelper(arr, left, mid);
            mergeSortHelper(arr, mid + 1, right);
            
            // Merge the sorted halves
            merge(arr, left, mid, right);
        }
    }

public:
    void sort(std::vector<int>& arr) {
        if (arr.empty()) return;
        mergeSortHelper(arr, 0, arr.size() - 1);
    }
    
    // Utility function to print array
    void printArray(const std::vector<int>& arr) {
        for(int num : arr) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    MergeSort sorter;
    std::vector<int> arr;
    int n, value;
    
    // Get array size from user
    std::cout << "Enter the number of elements: ";
    std::cin >> n;
    
    // Get array elements from user
    std::cout << "Enter " << n << " elements:\n";
    for(int i = 0; i < n; i++) {
        std::cin >> value;
        arr.push_back(value);
    }
    
    // Print original array
    std::cout << "\nOriginal array: ";
    sorter.printArray(arr);
    
    // Sort the array
    sorter.sort(arr);
    
    // Print sorted array
    std::cout << "Sorted array: ";
    sorter.printArray(arr);
    
    return 0;
}